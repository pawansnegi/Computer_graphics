/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "chair.hpp"

namespace csX75{
    
    void chair_t::init(){
        seat_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        leg1_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        leg2_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        leg3_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        leg4_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        back1_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        back2_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        back3_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        back4_col = glm::vec4(0.6 , 0.5 , 0.6 , 1.0) ;
        
        seat_data = new square(seat_col) ;
        leg1_data = new square(seat_col) ;
        leg2_data = new square(seat_col) ;
        leg3_data = new square(seat_col) ;
        leg4_data = new square(seat_col) ;
        back1_data = new square(seat_col) ;
        back2_data = new square(seat_col) ;
        back3_data = new square(seat_col) ;
        back4_data = new square(seat_col) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ;
        
        seat = new HNode(NULL , seat_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        leg1 = new HNode(seat , leg1_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        leg2 = new HNode(seat , leg2_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        leg3 = new HNode(seat , leg3_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        leg4 = new HNode(seat , leg4_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        back1 = new HNode(seat , back1_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        back2 = new HNode(seat , back2_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        back3 = new HNode(seat , back3_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        back4 = new HNode(seat , back4_data , temp , this, "render_maps/chair.bmp" , 480, 480);
        
        make_chair() ;
    }
    
    void chair_t::make_chair(){
        
        seat->change_parameters(0.0 , -9.0, -6.0 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 0.25 , 2.0) ;
        
        leg1->change_parameters(1.75 , -3.25, 1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        leg2->change_parameters(1.75 , -3.25, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        leg3->change_parameters(-1.75 , -3.25, 1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        leg4->change_parameters(-1.75 , -3.25, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        back1->change_parameters(1.75 , 3.25, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        back2->change_parameters(-1.75 , 3.25, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               0.25 , 3.0 , 0.25) ;
        
        back3->change_parameters(0.0 , 3.0, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 0.25 , 0.25) ;
        
        back4->change_parameters(0.0 , 6.0, -1.75 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 0.25 , 0.25) ;
    }
}