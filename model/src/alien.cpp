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
        
        mainbody = new HNode(NULL , mainbody_data , temp , this) ;
        larm = new HNode(mainbody , larm_data , temp , this) ;
        rarm = new HNode(mainbody , rarm_data , temp, this) ;
        lleg = new HNode(mainbody , lleg_data , temp, this) ;
        rleg = new HNode(mainbody , rleg_data , temp, this) ;
        llarm = new HNode(larm , llarm_data , temp, this) ; 
        rlarm = new HNode(rarm , rlarm_data , temp, this) ; 
        llleg = new HNode(lleg , llleg_data , temp, this) ; 
        rlleg = new HNode(rleg , rlleg_data , temp, this) ; 
        hatrim = new HNode(mainbody , hatrim_data , temp , this) ;
        hat = new HNode(hatrim , hat_data , temp , this) ;
        
        make_alien() ;
        set_constraints() ;
        make_pose() ;
        current_limb = part_t::mainbody ;
    }
    
    void alien_t::make_alien(){
        
        mainbody->change_parameters(0.0 , 5.0, 15.0 , 
                               0.0, 0.0 ,0.0 ,
                               2.0 , 5.0 , 2.0) ;
        mainbody->set_por(glm::vec3(0.0 , -4.0 , 15.0)) ;
        
        larm->change_parameters(2.0 ,1.75 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.2 , 0.2) ;
        larm->set_por(glm::vec3(1.0 , 1.75 , 0.0)) ;
        
        rarm->change_parameters(-2.0 ,1.75 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.2 , 0.2) ;
        rarm->set_por(glm::vec3(-1.0 , 1.75 , 0.0)) ;
        
        lleg->change_parameters(0.75 , -4.5 , 0.0 , 
                                90.0, 0.0 ,10.0 ,
                                0.2 , 1.0 , 0.2) ;
        lleg->set_por(glm::vec3(0.875 , -4.0 , 0.0)) ;
        
        rleg->change_parameters(-0.75 , -4.5 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.2 , 1.0 , 0.2) ;
        rleg->set_por(glm::vec3(-0.875 , -4.0 , 0.0)) ;
        
        //###############################
        rlarm->change_parameters( -2, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.2 , 0.2) ;
        rlarm->set_por(glm::vec3(-1.0 , 0.0 , 0.0)) ;
        
        llarm->change_parameters( 2, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.2 , 0.2) ;
        llarm->set_por(glm::vec3(1.0 , 0.0 , 0.0)) ;
        
        llleg->change_parameters( 0.0, -2.0 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.2 , 1.0 , 0.2) ;
        llleg->set_por(glm::vec3(0.0 , -1.0 , 0.0)) ;
        
        rlleg->change_parameters( 0.0, -2.0 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.2 , 1.0 , 0.2) ;
        rlleg->set_por(glm::vec3(0.0 , -1.0 , 0.0)) ;
        
        hatrim->change_parameters(0.0, 4.9 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                2.0 , 0.25 , 2.0) ;
        
        hat->change_parameters(0.0, 0.25 , 0.0 , 
                                -90.0, 0.0 ,0.0 ,
                                0.8 , 3.0 , 0.8) ;
        
        
        
    }
     
    void alien_t::make_pose(){
        lleg->set_pose(60 ,-30 , 0 ) ;
        llleg->set_pose(80 , 0 , 0) ;
        
        rleg->set_pose(-60 , 30 , 0) ;
        
        rarm->set_pose(0 , 60 , -30  ) ;
        larm->set_pose(0 , 60 , 30) ;
    }
    
    void alien_t::set_constraints(){
        
        mainbody->set_limits(-180 ,180 , -180 , 180 , -180 , 180 ,0,0,-10,10,0.0 ,0.0) ; ;
        larm->set_limits(-90 , 90 , -90 , 90 , -90 , 90, 0 , 0 , 0,0 ,0 ,0) ;
        rarm->set_limits(-90 , 90 , -90 , 90 , -90 , 90, 0 , 0 , 0,0 ,0 ,0) ;
        rleg->set_limits(-90 , 20 , -30 , 30 , -30 , 30, 0 , 0 , 0,0 ,0 ,0) ;
        lleg->set_limits(-90 , 20 , -30 , 30 , -30 , 30, 0 , 0 , 0,0 ,0 ,0) ;
        llarm->set_limits(0 , 0 , -160 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        rlarm->set_limits(0 , 0 , 0 , 160 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;        
        rlleg->set_limits(0 , 160 , 0 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        llleg->set_limits(0 , 160 , 0 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        
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
    
    void alien_t::trans_y_inc(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->inc_ty() ;
                break;
            default:
                break ;
                
        }
    }
    
    void alien_t::trans_y_dec(){
        part_t s = get_curr_limb() ;
        switch(s) {
            case part_t::mainbody:
                mainbody->dec_ty() ;
                break;
            default:
                break ;
                
        }
    }
    
}
