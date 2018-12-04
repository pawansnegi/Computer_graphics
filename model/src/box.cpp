/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "box.hpp"

namespace csX75{
    
    void box_t::init(){
        bottom_color = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        lid_color = glm::vec4(0.3 , 0.1 , 0.4 , 1.0) ;
        
        bottom_data = new square_wo_topface(bottom_color) ;
        lid_data = new square(lid_color) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        bottom = new HNode(NULL , bottom_data , temp , this) ;
        lid = new HNode(bottom , lid_data , temp , this) ;
        
        make_box() ;
        set_constraints() ;
    }
    
    void box_t::make_box(){
        
        bottom->change_parameters(0.0 ,0.0 , 0.0 , 
                               0.0, 0.0 ,0.0 ,
                               8.0 , 4 , 8.0) ;
        
        lid->change_parameters(0.0 ,5.0 , 0.0 , 
                               0.0, 0.0 ,0.0 ,
                               8.0 , 1 , 8) ;
        lid->set_por(glm::vec3(0.0 , 4.0 , -8)) ;
        
    }
    
    void box_t::set_constraints(){
        bottom->set_limits(0 , 0, -180,180 , 0, 0,0 , 0, 0,0 , 0, 0) ;
        lid->set_limits(-180, 0, 0 , 0, 0,0 , 0, 0,0 , 0,0,0) ;
        
    }
    
    void box_t::open_box(){
        lid->dec_rx() ;
    }
    
    void box_t::close_box(){
        lid->inc_rx() ;
    }
}