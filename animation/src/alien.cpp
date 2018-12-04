/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "alien.hpp"

namespace csX75 {
    
    void alien_t::init(){
        mainbody_color = glm::vec4(0.0 , 0.39 , 0.0 , 1.0) ;
        larm_color = glm::vec4(1.0 , 0.84 , 0.0 , 1.0) ;
        rarm_color = glm::vec4(1.0 , 0.84 , 0.0 , 1.0) ;
        lleg_color = glm::vec4(1.0 , 0.84 , 0.0 , 1.0) ;
        rleg_color = glm::vec4(1.0 , 0.84 , 0.0, 1.0) ;
        llarm_color = glm::vec4(1.0 , 0.84 , 0.0, 1.0) ;
        rlarm_color = glm::vec4(1.0 , 0.84 , 0.0 , 1.0) ;
        llleg_color = glm::vec4(1.0 , 0.84 , 0.0, 1.0) ;
        rlleg_color = glm::vec4(1.0 , 0.84 , 0.0, 1.0) ;
        hatrim_color = glm::vec4(0.1 , 0.8 , 1.0 , 1.0) ;
        hat_color = glm::vec4(0.1 , 0.8 , 1.0 , 1.0) ;
        
                
        mainbody_data = new sphere(mainbody_color) ;
        larm_data = new cylinder(larm_color) ;
        rarm_data = new cylinder(rarm_color) ;
        lleg_data = new cylinder(lleg_color) ;
        rleg_data = new cylinder(rleg_color) ;
        llarm_data = new cylinder(llarm_color) ;
        rlarm_data = new cylinder(rlarm_color) ;
        llleg_data = new cylinder(llleg_color) ;
        rlleg_data = new cylinder(rlleg_color) ;
        hatrim_data = new cylinder(hatrim_color) ;
        hat_data = new cone(hat_color) ;
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        mainbody = new HNode(NULL , mainbody_data , temp , this, "render_maps/alien.bmp" , 484, 484) ;
        larm = new HNode(mainbody , larm_data , temp , this, "render_maps/stand.bmp" , 284, 177) ;
        rarm = new HNode(mainbody , rarm_data , temp, this, "render_maps/stand.bmp" , 284, 177) ;
        lleg = new HNode(mainbody , lleg_data , temp, this, "render_maps/stand.bmp" , 284, 177) ;
        rleg = new HNode(mainbody , rleg_data , temp, this, "render_maps/stand.bmp" , 284, 177) ;
        llarm = new HNode(larm , llarm_data , temp, this, "render_maps/stand.bmp" , 284, 177) ; 
        rlarm = new HNode(rarm , rlarm_data , temp, this, "render_maps/stand.bmp" , 284, 177) ; 
        llleg = new HNode(lleg , llleg_data , temp, this, "render_maps/stand.bmp" , 284, 177) ; 
        rlleg = new HNode(rleg , rlleg_data , temp, this, "render_maps/stand.bmp" , 284, 177) ; 
        hatrim = new HNode(mainbody , hatrim_data , temp , this, "render_maps/hat.bmp" , 100, 100) ;
        hat = new HNode(hatrim , hat_data , temp , this, "render_maps/hat.bmp" , 100, 100) ;
        
        make_alien() ;
        make_pose() ;
        current_limb = part_t::mainbody ;
    }
    
    void alien_t::make_alien(){
        
        mainbody->change_parameters(0.0 , 0.0, 0.0 , 
                               -90.0, 0.0 ,0.0 ,
                               0.3 , 0.5 , 0.3) ;
        mainbody->set_por(glm::vec3(0.0 , 0.0 , 0.0)) ;
        
        larm->change_parameters(0.3 ,0.2 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.2 , 0.04 , 0.04) ;
        larm->set_por(glm::vec3(0.1 , 0.2 , 0.0)) ;
        
        rarm->change_parameters(-0.3 ,0.2 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.2 , 0.04 , 0.04) ;
        rarm->set_por(glm::vec3(-0.1 , 0.2 , 0.0)) ;
        
        lleg->change_parameters(0.2 , -0.3 , 0.0 , 
                                90.0, 0.0 ,10.0 ,
                                0.04 , 0.2 , 0.04) ;
        lleg->set_por(glm::vec3(0.2 , -0.2 , 0.0)) ;
        
        rleg->change_parameters(-0.2 , -0.3 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.2 , 0.04) ;
        rleg->set_por(glm::vec3(-0.2 , -0.1 , 0.0)) ;
        
        //###############################
        rlarm->change_parameters( -0.4, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.2 , 0.04 , 0.04) ;
        rlarm->set_por(glm::vec3(-0.2 , 0.0 , 0.0)) ;
        
        llarm->change_parameters( 0.4, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.2 , 0.04 , 0.04) ;
        llarm->set_por(glm::vec3(0.2 , 0.0 , 0.0)) ;
        
        llleg->change_parameters( 0.0, -0.4 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.2 , 0.04) ;
        llleg->set_por(glm::vec3(0.0 , -0.2 , 0.0)) ;
        
        rlleg->change_parameters( 0.0, -0.4 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.2 , 0.04) ;
        rlleg->set_por(glm::vec3(0.0 , -0.2 , 0.0)) ;
        
        hatrim->change_parameters(0.0, 0.5 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.3 , 0.01 , 0.3) ;
        
        hat->change_parameters(0.0, 0.01 , 0.0 , 
                                -90.0, 0.0 ,0.0 ,
                                0.08 , 0.3 , 0.08) ;
        
        
        
    }
     
    void alien_t::make_pose(){
        mainbody->translate(-1, -4 , 0) ;
        lleg->set_pose(60 ,-30 , 0 ) ;
        llleg->set_pose(80 , 0 , 0) ;
        
        rleg->set_pose(-60 , 30 , 0) ;
        
        rarm->set_pose(0 , 60 , -30  ) ;
        larm->set_pose(0 , 60 , 30) ;
    }
    
    void alien_t::rotate_x_cc(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->dec_rx() ;
                break;
            case part_t::larm:
                larm->dec_rx() ;
                break;
            case part_t::rarm:
                rarm->dec_rx() ;
                break;
            case part_t::lleg:
                lleg->dec_rx() ;
                break;
            case part_t::rleg:
                rleg->dec_rx() ;
                break;
            case part_t::llarm:
                break;
            case part_t::rlarm:
                break;
            case part_t::llleg:
                llleg->dec_rx() ;
                break;
            case part_t::rlleg:
                rlleg->dec_rx() ;
                break;
            default:
                break ;
                
        }
        
    }
    
    void alien_t::rotate_y_cc(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->inc_ry();
                break;
            case part_t::larm:
                larm->inc_ry() ;
                break;
            case part_t::rarm:
                rarm->inc_ry() ;
                break;
            case part_t::lleg:
                lleg->inc_ry();
                break;
            case part_t::rleg:
                rleg->inc_ry() ;
                break;
            case part_t::llarm:
                llarm->inc_ry() ;
                break;
            case part_t::rlarm:
                rlarm->inc_ry() ;
                break;
            case part_t::llleg:
                break;
            case part_t::rlleg:
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::rotate_z_cc(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->dec_rz() ;
                break;
            case part_t::larm:
                larm->dec_rz() ;
                break;
            case part_t::rarm:
                rarm->dec_rz() ;
                break;
            case part_t::lleg:
                lleg->dec_rz() ;
                break;
            case part_t::rleg:
                rleg->dec_rz() ;
                break;
            case part_t::llarm:
                break;
            case part_t::rlarm:
                break;
            case part_t::llleg:
                break;
            case part_t::rlleg:
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::rotate_x_ccw(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->inc_rx() ;
                break;
            case part_t::larm:
                larm->inc_rx() ;
                break;
            case part_t::rarm:
                rarm->inc_rx() ;
                break;
            case part_t::lleg:
                lleg->inc_rx() ;
                break;
            case part_t::rleg:
                rleg->inc_rx() ;
                break;
            case part_t::llarm:
                break;
            case part_t::rlarm:
                break;
            case part_t::llleg:
                llleg->inc_rx() ;
                break;
            case part_t::rlleg:
                rlleg->inc_rx() ;
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::rotate_y_ccw(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->dec_ry();
                break;
            case part_t::larm:
                larm->dec_ry() ;
                break;
            case part_t::rarm:
                rarm->dec_ry() ;
                break;
            case part_t::lleg:
                lleg->dec_ry() ;
                break;
            case part_t::rleg:
                rleg->dec_ry() ;
                break;
            case part_t::llarm:
                llarm->dec_ry();
                break;
            case part_t::rlarm:
                rlarm->dec_ry() ;
                break;
            case part_t::llleg:
                break;
            case part_t::rlleg:
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::rotate_z_ccw(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->inc_rz() ;
                break;
            case part_t::larm:
                larm->inc_rz() ;
                break;
            case part_t::rarm:
                rarm->inc_rz() ;
                break;
            case part_t::lleg:
                lleg->inc_rz() ;
                break;
            case part_t::rleg:
                rleg->inc_rz() ;
                break;
            case part_t::llarm:
                break;
            case part_t::rlarm:
                break;
            case part_t::llleg:
                break;
            case part_t::rlleg:
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::get_position(std::vector<float>& data){
        
        data.push_back(mainbody->get_coordinates()[0]);
        data.push_back(mainbody->get_coordinates()[1]);
        data.push_back(mainbody->get_coordinates()[2]);
    }
    
    void alien_t::set_position(std::vector<float>& data){
        
        int n = data.size() - 1 ;
        mainbody->translate(data[n] , data[n-1] , data[n-2]) ;
        data.pop_back() ;
        data.pop_back() ;
        data.pop_back() ;
    }
    
}