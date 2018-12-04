/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   curve.hpp
 * Author: pawannegi
 *
 * Created on October 25, 2018, 10:15 AM
 */

#ifndef CURVE_HPP
#define CURVE_HPP

#include <vector>
#include "human.hpp"

namespace csX75{
    
    class curve_t:public object_t{
    private:
        std::vector<glm::vec4> control_points ;
        int numofpoints ;
        
        glm::vec4 *out_points ;
        std::size_t point_buffer_size ;
        float *t ;
        glm::vec4 cursor_col;
        shape *cursor_shape ;
        HNode *cursor ;
        
    public:
        curve_t() {};
        ~curve_t() {} ;
        
        void init() ;
        void add_point() {control_points.push_back(cursor->get_coordinates()) ;} ;
        void remove_point() {if (!control_points.empty()) control_points.pop_back() ;};
        glm::vec4* get_points() {if (control_points.size() > 2) return out_points; else return NULL ; } ; 
        void calculate_points_on_curve() ;
        
        
        void move_x_inc() ;
        void move_y_inc() ;
        void move_z_inc() ;
        
        void move_x_dec() ;
        void move_y_dec() ;
        void move_z_dec() ;
        
        void render_curve(GLuint sp , glm::mat4 viewmat) ;
        void render_cursor() ;
    };
    
}


#endif /* CURVE_HPP */

