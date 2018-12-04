/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "wall_fixture.hpp"

namespace csX75{
    
    void wall_fixture_t::init(){
    
        fixture_col = glm::vec4(0.0,0.0,0.0,1.0) ;
        
        struc1_data = new square(fixture_col);
        top_data = new cylinder(fixture_col);
        light_data = new cone_frustum(fixture_col);
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        struc1 = new HNode(NULL, struc1_data, temp, this, "render_maps/stand.bmp" , 284, 177 );
        top = new HNode(struc1, top_data, temp, this, "render_maps/stand.bmp" , 284, 177 );
        light = new HNode(struc1, light_data, temp, this, "render_maps/ceiling.bmp" , 900, 600 );
        
        make_wallfixture() ;
    }
    
    
    void wall_fixture_t::make_wallfixture(){
        
        struc1->change_parameters(-13.0 ,5.0 ,0.0,
                                0.0 ,0.0 , 0.0,
                                2 , 0.1 , 0.1) ;
        
        top->change_parameters(2.0 ,-0.2 ,0.0,
                                90.0 ,0.0 , 0.0,
                                0.5 , 0.05 , 0.5) ;
        
        light->change_parameters(2.0 ,-1.6 ,0.0,
                                -90.0 ,0.0 , 0.0,
                                1.0 , 1.5 , 1.0) ;
        
    }
    
}