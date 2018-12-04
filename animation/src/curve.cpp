/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <GL/glew.h>
#include <vector>

#include "curve.hpp"

namespace csX75{
    
    void curve_t::init() {
        numofpoints = 101 ;
        
        cursor_col = glm::vec4(1.0 ,1.0,1.0,1.0);
        cursor_shape = new sphere(cursor_col) ;
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        cursor = new HNode(NULL , cursor_shape , temp , this, "render_maps/stand.bmp" , 284, 177 ) ;
        
        cursor->change_parameters(15.0 ,15.0 ,0.0,
                                0.0 ,0.0 , 0.0,
                                0.2 ,0.2 , 0.2) ;
        
        control_points.clear() ;
        
        control_points.push_back(glm::vec4(80, 10 , 80 , 1)) ;
        t = new float[numofpoints] ;
        t[0] = 0.0 ;
        for (int i = 1 ; i< numofpoints ; i++){
            t[i] = t[i-1] + 1.0/100 ;
        }
        t[100] = 1.0 ;
        
        out_points = new glm::vec4[numofpoints] ;
        point_buffer_size = sizeof(*out_points) * numofpoints ;
        
        
    }
    
    void curve_t::calculate_points_on_curve(){
        
        std::vector<glm::vec4> newval ;
       
        for (int i = 0 ; i < numofpoints ; i++){
            newval = control_points ;
            while (newval.size() > 1){
                for (unsigned int j = 0 ; j < newval.size() - 1; j++){
                    newval[j] = glm::float32(1.0 - t[i]) * newval[j] + t[i] * newval[j+1] ;
                }
                newval.pop_back() ;
            }
            out_points[i] = newval[0] ;
        }
    }
    
    void curve_t::move_x_dec(){
        cursor->dec_tx() ;
    }
    
    void curve_t::move_x_inc(){
        cursor->inc_tx() ;
    }
    
    void curve_t::move_y_dec(){
        cursor->dec_ty() ;
    }
    
    void curve_t::move_y_inc(){
        cursor->inc_ty() ;
    }
    
    void curve_t::move_z_dec(){
        cursor->dec_tz() ;
    }
    
    void curve_t::move_z_inc(){
        cursor->inc_tz() ;
    }
    
    void curve_t::render_curve(GLuint sp , glm::mat4 viewmat){
        
        if (control_points.size() < 2) return ;
        
        GLuint vpos = glGetAttribLocation(sp, "vPosition");
        GLuint umodel = glGetUniformLocation(sp, "uModelViewMatrix");
        
        GLuint vao , vbo ;

        calculate_points_on_curve() ;
        
        //Ask GL for a Vertex Attribute Objects (vao)
        glGenVertexArrays(1, &vao);
        //Ask GL for aVertex Buffer Object (vbo)
        glGenBuffers(1, &vbo);

        //bind them
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        
        glBufferData(GL_ARRAY_BUFFER, point_buffer_size , NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, point_buffer_size, out_points);
        
        glEnableVertexAttribArray(vpos);
        glVertexAttribPointer(vpos, 4, GL_FLOAT, GL_FALSE,
                0, BUFFER_OFFSET(0));
        
        
        glUniformMatrix4fv(umodel, 1, GL_FALSE, glm::value_ptr(viewmat));
        
        glDrawArrays(GL_LINE_STRIP , 0 , numofpoints);
           
    }
    
    void curve_t::render_cursor(){
        cursor->render_tree(this) ;
    }
}