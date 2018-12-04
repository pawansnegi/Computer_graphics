/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "cupboard.hpp"

namespace csX75{
    
    void cupboard_t::init(){
        cupboard_col = glm::vec4(0.0,0.0,0.0,0.0) ;
        
        cupboard_data = new square(cupboard_col) ;
        front_d = new sheet_p(cupboard_col) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        cupboard = new HNode(NULL, cupboard_data , temp, this, "render_maps/shelf.bmp" , 512, 512 );
        front = new HNode(cupboard, front_d , temp, this, "render_maps/books.bmp" , 1500, 953 );
        
        make_cupboard() ;
        
    }
    
    void cupboard_t::make_cupboard(){
        
        cupboard->change_parameters(-10.0,3.0,-19.0,
                                    0.0,0.0,0.0,
                                    5.0,5.0,1.0) ;
        
        front->change_parameters(0.0,0.0,1.1,
                                    0.0,0.0,0.0,
                                    5.0,5.0,1.0) ;
        
    }
}