/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stool.hpp"

namespace csX75{
    
    void stool_t::init(){
        table_col = glm::vec4(0.2,0.1,0.4,1.0) ;
        
        table_top_d = new cylinder(table_col);
        leg1_d = new square(table_col);
        leg2_d = new square(table_col);
        leg3_d = new square(table_col);
        leg4_d = new square(table_col);
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        table_top = new HNode(NULL , table_top_d , temp , this, "render_maps/shelf.bmp" , 512, 512  );
        leg1 = new HNode(table_top , leg1_d , temp , this , "render_maps/shelf.bmp" , 512, 512 );
        leg2 = new HNode(table_top , leg2_d , temp , this, "render_maps/shelf.bmp" , 512, 512  );
        leg3 = new HNode(table_top , leg3_d , temp , this, "render_maps/shelf.bmp" , 512, 512  );
        leg4 = new HNode(table_top , leg4_d , temp , this , "render_maps/shelf.bmp" , 512, 512 );
        
        make_stool() ;
        
    }
    
    
    void stool_t::make_stool(){
        
        table_top->change_parameters(15.0 ,-10.0 ,-15.0,
                                90.0 ,0.0 , 0.0,
                                2.5 , 0.25 , 2.5) ;
        
        leg1->change_parameters(1.5 ,-2.75 ,1.5,
                                0.0 ,0.0 , 0.0,
                                0.2 , 2.5 , 0.2);
        
        leg2->change_parameters(-1.5 ,-2.75 ,1.5,
                                0.0 ,0.0 , 0.0,
                                0.2 , 2.5 , 0.2);
        
        leg3->change_parameters(-1.5 ,-2.75 ,-1.5,
                                0.0 ,0.0 , 0.0,
                                0.2 , 2.5 , 0.2);
        
        leg4->change_parameters(1.5 ,-2.75 ,-1.5,
                                0.0 ,0.0 , 0.0,
                                0.2 , 2.5 , 0.2);
        
    }
    
}