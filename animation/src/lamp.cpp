/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "lamp.hpp"

namespace csX75{
    
    void lamp_t::init(){
        lamp_col = glm::vec4(0.2,0.1,0.4,1.0) ;
        
        frus_data = new cone_frustum(lamp_col) ;
        frustop_data = new cylinder(lamp_col) ;
        stand_data = new cylinder(lamp_col) ;
        base_data = new cylinder(lamp_col) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        frustum = new HNode(NULL, frus_data, temp, this, "render_maps/lamp.bmp" , 640, 480);
        frustop = new HNode(frustum , frustop_data, temp, this, "render_maps/stand.bmp" , 284, 177 );
        stand = new HNode(frustum, stand_data, temp, this, "render_maps/stand.bmp" , 284, 177);
        base = new HNode(frustum, base_data, temp, this, "render_maps/stand.bmp" , 284, 177);
        
        make_lamp();
    }
    
    void lamp_t::make_lamp() {
        
        frustum->change_parameters(15.0 ,-5.2 ,-15.0,
                                -90.0 ,0.0 , 0.0,
                                2.0 , 2.0 , 2.0) ;
        
        
        frustop->change_parameters(0.0 ,2.0 ,0.0,
                                90.0 ,0.0 , 0.0,
                                1.0 , 0.05 , 1.0) ;
        
        stand->change_parameters(0.0 ,-2.0 ,0.0,
                                90.0 ,0.0 , 0.0,
                                0.2 , 2.5 , 0.2) ;
        
        base->change_parameters(0.0 ,-4.5 ,0.0,
                                90.0 ,0.0 , 0.0,
                                1.0 , 0.1 , 1.0) ;
    }
    
}