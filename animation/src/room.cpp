/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "room.hpp"

namespace csX75 {
    
    void room_t::init(){
        room_col = glm::vec4(0.5 ,0.6,0.3,1.0);
        
        wall1 = new sheet_p(room_col) ;
        wall2 = new sheet_p(room_col) ;
        wall3 = new sheet_p(room_col) ;
        wall4 = new sheet_p(room_col) ;
        
        for (int i = 0 ; i < 6; i++){
            wall3->v_normals[i] = GLfloat(-1.0) * wall3->v_normals[i] ;
        }
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        w1 = new HNode(NULL , wall1 , temp , this, "render_maps/window.bmp" , 795, 531 );
        w2 = new HNode(w1 , wall2 , temp , this, "render_maps/door.bmp" , 1088, 696 );
        w3 = new HNode(w1 , wall3 , temp , this, "render_maps/floor.bmp" , 1280, 1280 );

//        w2 = new HNode(w1 , wall2 , temp , this, "render_maps/window.bmp" , 795, 531 );
//        w3 = new HNode(w1 , wall3 , temp , this, "render_maps/window.bmp" , 795, 531  );
        w4 = new HNode(w1 , wall4 , temp , this, "render_maps/ceiling.bmp" , 900, 600 );
        
        make_room() ;
        
    }
    
    void room_t::make_room(){
        
        w1->change_parameters(0.0 ,0.0 ,-20.0,
                                0.0 ,0.0 , 0.0,
                                20.0 ,15.0 , 1.0);
        
        w2->change_parameters(-20.0 ,0.0 ,20.0,
                                0.0 ,90.0 , 0.0,
                                1.0 ,15.0 , 20.0);
        
        w3->change_parameters(0.0 ,-15.0 ,20.0,
                                90.0 ,0.0 , 0.0,
                                20.0 ,1.0 , 20.0);
        
        w4->change_parameters(0.0 ,15.0 ,20.0,
                                90.0 ,0.0 , 0.0,
                                20.0 ,1.0 , 20.0);
        
    }
}