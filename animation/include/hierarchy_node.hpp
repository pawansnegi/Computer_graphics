#ifndef _HNODE_HPP_
#define _HNODE_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "texture.hpp"
#include "gl_framework.hpp"
#include"primitive.hpp"

namespace csX75 {

    class object_t ;
    // A simple class that represents a node in the hierarchy tree
    class HNode {
        GLfloat tx, ty, tz, rx, ry, rz , sx , sy ,sz;
        GLfloat lrx , lry , lrz ;

        std::size_t vertex_buffer_size;
        std::size_t color_buffer_size;
        std::size_t normal_buffer_size ;
        std::size_t tex_buffer_size ;

        GLuint num_vertices;
        GLuint vao, vbo, tex;

        glm::vec3 point_of_rot ;
        glm::mat4 rotation , rot1;
        glm::mat4 local_rotation ;
        
        glm::mat4 translation , trans1 , trans2;
        glm::mat4 scale;

        std::vector<HNode*> children;
        HNode* parent;

        void update_matrices();

    public:
        HNode(HNode*, GLuint, glm::vec4*, glm::vec4*, std::size_t,
              std::size_t , glm::vec3, object_t *obj);
        HNode(HNode*, shape* , glm::vec3, object_t *obj,
            std::string texfile = "render_maps/all1.bmp", int h=256, int w=256);

        void add_child(HNode*);
        void render(object_t *obj);
        void change_parameters(GLfloat, GLfloat, GLfloat, 
                               GLfloat, GLfloat, GLfloat,
                               GLfloat, GLfloat, GLfloat);
        
        void set_por(glm::vec3 pnt) {point_of_rot = pnt ;} ;
        glm::vec3 get_por() {return point_of_rot ;} ;
        
        void render_tree(object_t *obj);
        void set_pose(GLfloat, GLfloat, GLfloat);
        void translate(GLfloat atx, GLfloat aty, GLfloat atz) ;
        
        void inc_rx();
        void inc_ry();
        void inc_rz();
        void dec_rx();
        void dec_ry();
        void dec_rz();
        
        void inc_tx();
        void dec_tx();
        void inc_ty();
        void dec_ty();
        void inc_tz();
        void dec_tz();
        
        glm::vec4 get_coordinates(){return glm::vec4(tx , ty , tz , 1);} ;
        void get_orientation(std::vector<float> &data);
        void set_orientation(std::vector<float> &data);
    };

    glm::mat4* multiply_stack(std::vector <glm::mat4>);
};

#endif