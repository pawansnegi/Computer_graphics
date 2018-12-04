/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"table.hpp"

namespace csX75{
    
    void table_t::init(){
        table_col = glm::vec4(0.2,0.1,0.4,1.0) ;
        
        table_top_d = new square(table_col);
        leg1_d = new square(table_col);
        leg2_d = new square(table_col);
        leg3_d = new square(table_col);
        leg4_d = new square(table_col);
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        table_top = new HNode(NULL , table_top_d , temp , this , "render_maps/wood.bmp" , 1400, 980 );
        leg1 = new HNode(table_top , leg1_d , temp , this , "render_maps/wood.bmp", 1400, 980);
        leg2 = new HNode(table_top , leg2_d , temp , this , "render_maps/wood.bmp", 1400, 980);
        leg3 = new HNode(table_top , leg3_d , temp , this , "render_maps/wood.bmp", 1400, 980);
        leg4 = new HNode(table_top , leg4_d , temp , this , "render_maps/wood.bmp", 1400, 980);
        
        make_table() ;
        
    }
    
    
    void table_t::make_table(){
        
        table_top->change_parameters(0.0 ,-5.5 ,0.0,
                                0.0 ,0.0 , 0.0,
                                5.0 , 0.5 , 5.0) ;
        
        leg1->change_parameters(4.5 ,-5.5 ,4.5,
                                0.0 ,0.0 , 0.0,
                                0.5 , 5 , 0.5);
        
        leg2->change_parameters(-4.5 ,-5.5 ,4.5,
                                0.0 ,0.0 , 0.0,
                                0.5 , 5 , 0.5);
        
        leg3->change_parameters(-4.5 ,-5.5 ,-4.5,
                                0.0 ,0.0 , 0.0,
                                0.5 , 5 , 0.5);
        
        leg4->change_parameters(4.5 ,-5.5 ,-4.5,
                                0.0 ,0.0 , 0.0,
                                0.5 , 5 , 0.5);
        
    }
    
}