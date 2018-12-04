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
        
        bottom = new HNode(NULL , bottom_data , temp , this, "render_maps/box.bmp" , 250, 167) ;
        lid = new HNode(bottom , lid_data , temp , this, "render_maps/box.bmp" , 250, 167) ;
        
        make_box() ;
    }
    
    void box_t::make_box(){
        
        bottom->change_parameters(0.0 ,-4.0 , 0.0 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 1 , 2.0) ;
        bottom->set_por(glm::vec3(0.0, -4.0, 0.0));
        
        lid->change_parameters(0.0 ,1.1 , 0.0 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 0.2 , 2) ;
        lid->set_por(glm::vec3(0.0 , 1.0 , -2)) ;
        
    }
    
    void box_t::open_box(){
        lid->dec_rx() ;
    }
    
    void box_t::close_box(){
        lid->inc_rx() ;
    }
    
    void box_t::get_position(std::vector<float>& data){
        
        data.push_back(bottom->get_coordinates()[0]);
        data.push_back(bottom->get_coordinates()[1]);
        data.push_back(bottom->get_coordinates()[2]);
    }
    
    void box_t::set_position(std::vector<float>& data){
        
        int n = data.size() - 1 ;
        bottom->translate(data[n] , data[n-1] , data[n-2]) ;
        data.pop_back() ;
        data.pop_back() ;
        data.pop_back() ;
    }
    
}