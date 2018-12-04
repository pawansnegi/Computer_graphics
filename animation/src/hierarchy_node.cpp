#include "hierarchy_node.hpp"
#include "human.hpp"
#include <iostream>

//extern GLuint vPosition, vColor, uModelViewMatrix;
//extern std::vector<glm::mat4> matrixStack;

namespace csX75 {

    HNode::HNode(HNode* a_parent, GLuint num_v, glm::vec4* a_vertices
               , glm::vec4* a_colours, std::size_t v_size, std::size_t c_size
               , glm::vec3 mypor , object_t *obj) {

        num_vertices = num_v;
        vertex_buffer_size = v_size;
        color_buffer_size = c_size;
        // initialize vao and vbo of the object;


        //Ask GL for a Vertex Attribute Objects (vao)
        glGenVertexArrays(1, &vao);
        //Ask GL for aVertex Buffer Object (vbo)
        glGenBuffers(1, &vbo);

        //bind them
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);


        glBufferData(GL_ARRAY_BUFFER, vertex_buffer_size + color_buffer_size, NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_buffer_size, a_vertices);
        glBufferSubData(GL_ARRAY_BUFFER, vertex_buffer_size, color_buffer_size, a_colours);

        //setup the vertex array as per the shader
        glEnableVertexAttribArray(obj->get_vposition());
        glVertexAttribPointer(obj->get_vposition(), 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

        glEnableVertexAttribArray(obj->get_vcolor());
        glVertexAttribPointer(obj->get_vcolor(), 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(vertex_buffer_size));


        // set parent

        if (a_parent == NULL) {
            parent = NULL;
        } else {
            parent = a_parent;
            parent->add_child(this);
        }

        //initial parameters are set to 0;

        tx = ty = tz = rx = ry = rz = 0;
        sx = sy = sz = 1 ;
        
        lrx = lry = lrz ;
        
        
        set_por(mypor) ;
        update_matrices();
    }
    
    HNode::HNode(HNode* a_parent, shape* Shape , glm::vec3 mypor , object_t *obj , std::string texfile , int h , int w) {

        num_vertices = Shape->numofvert;
        vertex_buffer_size = Shape->size;
        color_buffer_size = Shape->size;
        normal_buffer_size = Shape->size;
        tex_buffer_size = Shape->size_tex ;
        // initialize vao and vbo of the object;
        
        tex = LoadTexture(texfile.c_str(),h,w);

        //Ask GL for a Vertex Attribute Objects (vao)
        glGenVertexArrays(1, &vao);
        //Ask GL for aVertex Buffer Object (vbo)
        glGenBuffers(1, &vbo);

        //bind them
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);


        glBufferData(GL_ARRAY_BUFFER, vertex_buffer_size + color_buffer_size 
                + normal_buffer_size + tex_buffer_size, NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_buffer_size, Shape->v_positions);
        glBufferSubData(GL_ARRAY_BUFFER, vertex_buffer_size, color_buffer_size, Shape->v_colors);
        glBufferSubData(GL_ARRAY_BUFFER, vertex_buffer_size + color_buffer_size, 
                normal_buffer_size, Shape->v_normals);
        glBufferSubData(GL_ARRAY_BUFFER, vertex_buffer_size + color_buffer_size  
               + normal_buffer_size , tex_buffer_size, Shape->v_texcoord);

        //setup the vertex array as per the shader
        glEnableVertexAttribArray(obj->get_vposition());
        glVertexAttribPointer(obj->get_vposition(), 4, GL_FLOAT, GL_FALSE,
                0, BUFFER_OFFSET(0));

        glEnableVertexAttribArray(obj->get_vcolor());
        glVertexAttribPointer(obj->get_vcolor(), 4, GL_FLOAT, GL_FALSE,
                0, BUFFER_OFFSET(vertex_buffer_size));

        glEnableVertexAttribArray(obj->get_vnormal());
        glVertexAttribPointer(obj->get_vnormal(), 4, GL_FLOAT, GL_FALSE,
                0, BUFFER_OFFSET(vertex_buffer_size + color_buffer_size));
        
        glEnableVertexAttribArray(obj->get_texCoord());
        glVertexAttribPointer(obj->get_texCoord(), 2, GL_FLOAT, GL_FALSE,
                0, BUFFER_OFFSET(vertex_buffer_size + color_buffer_size + normal_buffer_size));

        // set parent

        if (a_parent == NULL) {
            parent = NULL;
        } else {
            parent = a_parent;
            parent->add_child(this);
        }

        //initial parameters are set to 0;

        tx = ty = tz = rx = ry = rz = 0;
        sx = sy = sz = 1 ;
        
        set_por(mypor) ;
        update_matrices();
    }
    

    void HNode::update_matrices() {

        trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(point_of_rot.x, point_of_rot.y, point_of_rot.z));
        trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(-point_of_rot.x, -point_of_rot.y, -point_of_rot.z));
        
        rot1 = glm::rotate(glm::mat4(1.0f), glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
        rot1 = glm::rotate(rot1, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
        rot1 = glm::rotate(rot1, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
        
        rotation = trans1 * rot1 * trans2 ;
        
        translation = glm::translate(glm::mat4(1.0f), glm::vec3(tx, ty, tz));
        
        scale = glm::scale(glm::mat4(1.0f), glm::vec3(sx, sy, sz)) ;

        local_rotation = glm::rotate(glm::mat4(1.0f), glm::radians(lrx), glm::vec3(1.0f, 0.0f, 0.0f));
        local_rotation = glm::rotate(local_rotation, glm::radians(lry), glm::vec3(0.0f, 1.0f, 0.0f));
        local_rotation = glm::rotate(local_rotation, glm::radians(lrz), glm::vec3(0.0f, 0.0f, 1.0f));
        

    }

    void HNode::add_child(HNode* a_child) {
        children.push_back(a_child);

    }

    void HNode::change_parameters(GLfloat atx, GLfloat aty, GLfloat atz, 
            GLfloat arx, GLfloat ary, GLfloat arz , GLfloat asx, GLfloat asy, GLfloat asz) {
        tx = atx;
        ty = aty;
        tz = atz;
        lrx = arx;
        lry = ary;
        lrz = arz;
        sx = asx;
        sy = asy;
        sz = asz;

        update_matrices();
    }

    void HNode::set_pose(GLfloat arx, GLfloat ary, GLfloat arz) {
        rx = arx;
        ry = ary;
        rz = arz;
        update_matrices();
    }
    
    void HNode::translate(GLfloat atx, GLfloat aty, GLfloat atz) {
        tx = atx ;
        ty = aty ;
        tz = atz ;
        
        point_of_rot[0] = atx ;
        point_of_rot[1] = aty ;
        point_of_rot[2] = atz ;
        update_matrices();
    }
    
    void HNode::render(object_t *obj) {

        glBindTexture(GL_TEXTURE_2D, tex);
        obj->matrixStack.push_back(scale);
        obj->matrixStack.push_back(local_rotation) ;
        glm::mat4* ms_mult = multiply_stack(obj->matrixStack);
        glm::mat3 normal_matrix = glm::transpose (glm::inverse(glm::mat3(*ms_mult)));
        
        glUniformMatrix4fv(obj->get_viewMatrix(), 1, GL_FALSE, glm::value_ptr(obj->viewmatrix));
        glUniformMatrix4fv(obj->get_vModelviewmatrix(), 1, GL_FALSE, glm::value_ptr(*ms_mult));
        glUniformMatrix3fv(obj->get_normalMatrix(), 1, GL_FALSE, glm::value_ptr(normal_matrix));
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, num_vertices);

        obj->matrixStack.pop_back();
        obj->matrixStack.pop_back();
        
        delete ms_mult;

    }

    void HNode::render_tree(object_t *obj) {
        obj->matrixStack.push_back(rotation);
        obj->matrixStack.push_back(translation);
        

        render(obj);
        for (int i = 0; i < children.size(); i++) {
            children[i]->render_tree(obj);
        }
        obj->matrixStack.pop_back();
        obj->matrixStack.pop_back();

    }
    
    void HNode::get_orientation(std::vector<float> &data){
        
        data.push_back(rx) ;
        data.push_back(ry) ;
        data.push_back(rz) ;
        for (int i = 0; i < children.size(); i++) {
            children[i]->get_orientation(data) ;
        }
    }
    
    void HNode::set_orientation(std::vector<float> &data){
        int n = data.size() - 1 ;
        set_pose(data[n] , data[n-1] , data[n-2]) ;
        data.pop_back() ;
        data.pop_back() ;
        data.pop_back() ;
        
        for (int i = 0; i < children.size(); i++) {
            children[i]->set_orientation(data) ;
        }
        
        
    }

    void HNode::inc_rx() {
        rx += 0.5 ;
        update_matrices();
    }

    void HNode::inc_ry() {
        ry += 0.5;
        update_matrices();
    }

    void HNode::inc_rz() {
        rz += 0.5;
        update_matrices();
    }

    void HNode::dec_rx() {
        rx -= 0.5;
        update_matrices();
    }

    void HNode::dec_ry() {
        ry -= 0.5;
        update_matrices();
    }

    void HNode::dec_rz() {
        rz -= 0.5;
        update_matrices();
    }
    
    void HNode::inc_tx() {
        point_of_rot[0] +=  0.2 ;
        tx +=  0.2;
        update_matrices();
    }

    void HNode::dec_tx() {
        point_of_rot[0] -=  0.2 ;
        tx -=  0.2;
        update_matrices();
    }
    
    void HNode::inc_ty() {
        point_of_rot[1] +=  0.2 ;
        ty +=  0.2;
        update_matrices();
    }

    void HNode::dec_ty() {
        point_of_rot[1] -=  0.2 ;
        ty -=  0.2;
        update_matrices();
    }
    
    void HNode::inc_tz() {
        point_of_rot[2] +=  0.2 ;
        tz +=  0.2;
        update_matrices();
    }

    void HNode::dec_tz() {
        point_of_rot[2] -=  0.2 ;
        tz -=  0.2;
        update_matrices();
    }
    
    
    glm::mat4* multiply_stack(std::vector<glm::mat4> matStack) {
        glm::mat4* mult;
        mult = new glm::mat4(1.0f);

        for (int i = 0; i < matStack.size(); i++) {
            *mult = (*mult) * matStack[i];
        }

        return mult;
    }

}