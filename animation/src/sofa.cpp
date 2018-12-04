/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"sofa.hpp"

namespace csX75{
    
    void sofa_t::init(){
        
        sofa_color = glm::vec4(0.0, 0.0, 0.0, 0.0) ;
        
        base_data = new cylinder(sofa_color) ;
        back_data = new cylinder(sofa_color) ;
        h1_data = new square(sofa_color) ;
        h2_data = new square(sofa_color) ;
        h3_data = new square(sofa_color) ;
        h4_data = new square(sofa_color) ;
        h5_data = new square(sofa_color) ;
        h6_data = new square(sofa_color) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        base = new HNode(NULL, base_data, temp, this, "render_maps/sofa.bmp" , 2272, 1704 );
        back = new HNode(base, back_data, temp, this, "render_maps/sofa.bmp" , 2272, 1704 );
        h1 = new HNode(base, h1_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        h2 = new HNode(base, h2_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        h3 = new HNode(base, h3_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        h4 = new HNode(base, h4_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        h5 = new HNode(base, h5_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        h6 = new HNode(base, h6_data, temp, this, "render_maps/shelf.bmp" , 512, 512 );
        
        make_sofa() ;
        
    }
    
    void sofa_t::make_sofa(){
        
        base->change_parameters(-12.0 ,-11.0 ,0.0,
                                0.0 ,0.0 , 0.0,
                                2.5 , 1.0 , 10.0) ;
        
        back->change_parameters(-2.5 ,2.5 ,0.0,
                                0.0 ,0.0 , 0.0,
                                0.5 , 2.5 , 10.0) ;
        
        h1->change_parameters(0.0 ,1.75 ,10.0,
                                0.0 ,0.0 , 0.0,
                                2.5 , 0.25 , 0.25) ;
        h2->change_parameters(0.0 ,1.75 ,-10.0,
                                0.0 ,0.0 , 0.0,
                                2.5 , 0.25 , 0.25) ;
        h3->change_parameters(2.5 ,-1.0 ,10.0,
                                0.0 ,0.0 , 0.0,
                                0.25 , 3 , 0.25) ;
        h4->change_parameters(-2.5 ,-1.0 ,10.0,
                                0.0 ,0.0 , 0.0,
                                0.25 , 3 , 0.25) ;
        h5->change_parameters(-2.5 ,-1.0 ,-10.0,
                                0.0 ,0.0 , 0.0,
                                0.25 , 3 , 0.25) ;
        h6->change_parameters(2.5 ,-1.0 ,-10.0,
                                0.0 ,0.0 , 0.0,
                                0.25 , 3 , 0.25) ;
        
    }
    
}