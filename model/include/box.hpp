/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   box.hpp
 * Author: pawannegi
 *
 * Created on September 30, 2018, 6:14 PM
 */

#ifndef BOX_HPP
#define BOX_HPP

#include "human.hpp"

namespace csX75{
    
    class box_t:public object_t {
    private:
        glm::vec4 bottom_color ;
        glm::vec4 lid_color ;
        
        shape *bottom_data ;
        shape *lid_data ;
        
        HNode *bottom ;
        HNode *lid ;

        void make_box() ;
        void set_constraints() ;
        
    public:
        box_t() {} ;
        ~box_t() {} ;
        
        void init() ;
        
        void open_box() ;
        void close_box() ;
        
        void rotate_cw() {bottom->inc_ry();};
        void rotate_ccw() {bottom->dec_ry();} ;
        void hrender() {bottom->render_tree(this) ;} ;     
    };
}


#endif /* BOX_HPP */

