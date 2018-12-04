#include "human.hpp"

namespace csX75 {
    
    void human_t::init(){
        hip_color = glm::vec4(0.813 , 0.705 , 0.549 , 1.0) ;
        torso_color = glm::vec4(0.82 , 0.71 , 0.549 , 1.0) ;
        larm_color = glm::vec4(0.833 , 0.725 , 0.549 , 1.0) ;
        rarm_color = glm::vec4(0.843 , 0.735 , 0.549 , 1.0) ;
        lleg_color = glm::vec4(0.853 , 0.755 , 0.549 , 1.0) ;
        rleg_color = glm::vec4(0.863 , 0.755 , 0.549 , 1.0) ;
        head_color = glm::vec4(0.873 , 0.765 , 0.549 , 1.0) ;
        llarm_color = glm::vec4(0.883 , 0.775 , 0.549 , 1.0) ;
        rlarm_color = glm::vec4(0.893 , 0.785 , 0.549 , 1.0) ;
        llleg_color = glm::vec4(0.803 , 0.795 , 0.549 , 1.0) ;
        rlleg_color = glm::vec4(0.813 , 0.705 , 0.519 , 1.0) ;
        rfeet_color = glm::vec4(0.823 , 0.705 , 0.529 , 1.0) ;
        lfeet_color = glm::vec4(0.833 , 0.705 , 0.539 , 1.0) ;
        rhand_color = glm::vec4(0.843 , 0.705 , 0.569 , 1.0) ;
        lhand_color = glm::vec4(0.853 , 0.705 , 0.579 , 1.0) ;
        neck_color = glm::vec4(0.863 , 0.705 , 0.589 , 1.0) ;
        rstick_color = glm::vec4(1.0 , 0.0 , 0.0 , 1.0) ;
        lstick_color = glm::vec4(1.0 , 0.0 , 0.0 , 1.0) ;
        
                
        hip_data = new cylinder(hip_color) ;
        torso_data = new cylinder(torso_color) ;
        larm_data = new cylinder(larm_color) ;
        rarm_data = new cylinder(rarm_color) ;
        lleg_data = new cylinder(lleg_color) ;
        rleg_data = new cylinder(rleg_color) ;
        head_data = new sphere(head_color) ;
        torso_data = new cylinder(torso_color) ;
        llarm_data = new cylinder(llarm_color) ;
        rlarm_data = new cylinder(rlarm_color) ;
        rhand_data = new square(rhand_color) ;
        lhand_data = new square(lhand_color) ;
        llleg_data = new cylinder(llleg_color) ;
        rlleg_data = new cylinder(rlleg_color) ;
        lfeet_data = new square(lfeet_color) ;
        rfeet_data = new square(rfeet_color) ;
        neck_data = new cylinder(neck_color) ;
        rstick_data = new cylinder(rstick_color) ;
        lstick_data = new cylinder(lstick_color) ;
        
        
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        hip = new HNode(NULL , hip_data , temp , this) ;
        torso = new HNode(hip , torso_data , temp , this) ;
        larm = new HNode(torso , larm_data , temp , this) ;
        rarm = new HNode(torso , rarm_data , temp, this) ;
        lleg = new HNode(hip , lleg_data , temp, this) ;
        rleg = new HNode(hip , rleg_data , temp, this) ;
        llarm = new HNode(larm , llarm_data , temp, this) ; 
        rlarm = new HNode(rarm , rlarm_data , temp, this) ; 
        lhand = new HNode(llarm , lhand_data , temp, this) ; 
        rhand = new HNode(rlarm , rhand_data , temp, this) ; 
        llleg = new HNode(lleg , llleg_data , temp, this) ; 
        rlleg = new HNode(rleg , rlleg_data , temp, this) ; 
        rfeet = new HNode(rlleg , rfeet_data , temp, this) ; 
        lfeet = new HNode(llleg , lfeet_data , temp, this) ; 
        neck = new HNode (torso , neck_data , temp , this) ;
        head = new HNode(neck , head_data , temp, this) ; 
        rstick = new HNode (rhand , rstick_data , temp , this) ;
        lstick = new HNode (lhand , lstick_data , temp , this) ;
        
        make_human() ;
        set_constraints() ;
        make_pose() ;
        current_limb = limb_t::hip ;
    }
    
    void human_t::make_human(){
        
        hip->change_parameters(15.0 ,0.0 , 0.0 , 
                               90.0, 0.0 ,0.0 ,
                               1.0 , 0.5 , 0.5) ;
        hip->set_por(glm::vec3(15.0 , 0.0 , 0.0)) ;
        
        torso->change_parameters(0.0 ,2.5 , 0.0 , 
                                 90.0, 0.0 ,0.0 ,
                                 1.0 , 2.0 , 0.5) ;
        torso->set_por(glm::vec3(0.0 , 0.5 , 0.0)) ;
        
        larm->change_parameters(2.0 ,1.75 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.25 , 0.25) ;
        larm->set_por(glm::vec3(1.0 , 1.75 , 0.0)) ;
        
        rarm->change_parameters(-2.0 ,1.75 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.25 , 0.25) ;
        rarm->set_por(glm::vec3(-1.0 , 1.75 , 0.0)) ;
        
        lleg->change_parameters(0.75 , -1.5 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.25 , 1.0 , 0.25) ;
        lleg->set_por(glm::vec3(0.875 , -0.5 , 0.0)) ;
        
        rleg->change_parameters(-0.75 , -1.5 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.25 , 1.0 , 0.25) ;
        rleg->set_por(glm::vec3(-0.875 , -0.5 , 0.0)) ;
        
        head->change_parameters( 0.0, 1.25 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.8 , 1.0 , 0.8) ;
        head->set_por(glm::vec3(0.0 , 0.25 , 0.0)) ;
        
        rlarm->change_parameters( -2, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.25 , 0.25) ;
        rlarm->set_por(glm::vec3(-1.0 , 0.0 , 0.0)) ;
        
        rhand->change_parameters( -1.125, 0.0 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.4 , 0.2 , 0.2) ;
        rhand->set_por(glm::vec3(-1 , 0.0 , 0.0)) ;
        
        llarm->change_parameters( 2, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                1.0 , 0.25 , 0.25) ;
        llarm->set_por(glm::vec3(1.0 , 0.0 , 0.0)) ;
        
        lhand->change_parameters( 1.125, 0.0 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.4 , 0.2 , 0.2) ;
        lhand->set_por(glm::vec3(1.0 , 0.0 , 0.0)) ;
        
        llleg->change_parameters( 0.0, -2.0 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.25 , 1.0 , 0.25) ;
        llleg->set_por(glm::vec3(0.0 , -1.0 , 0.0)) ;
        
        lfeet->change_parameters( 0.0, -1.1 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.25 , 0.2 , 0.5) ;
        lfeet->set_por(glm::vec3(0.0 , -1 , 0.0)) ;
        
        rlleg->change_parameters( 0.0, -2.0 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.25 , 1.0 , 0.25) ;
        rlleg->set_por(glm::vec3(0.0 , -1.0 , 0.0)) ;
        
        rfeet->change_parameters( 0.0, -1.1 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.25 , 0.2 , 0.5) ;
        rfeet->set_por(glm::vec3(0.0 , -1.0 , 0.0)) ;
        
        neck->change_parameters( 0.0, 2.25 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.25 , 0.25 , 0.25) ;
        
        rstick->change_parameters( 0.0, 1.25 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.1 , 1.25 , 0.1) ;
        
        lstick->change_parameters( 0.0, 1.25 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.1 , 1.25 , 0.1) ;
        
         
    }
     
    void human_t::set_constraints(){
        
        hip->set_limits(-180 ,180 , -180 , 180 , -180 , 180 ,0,0,-10,10,0.0 ,0.0) ; ;
        torso->set_limits(-60 , 90 , -10 , 10 , -30 , 30 , 0 , 0 , -10,10 ,0 ,0) ;
        larm->set_limits(-90 , 90 , -90 , 90 , -90 , 90, 0 , 0 , 0,0 ,0 ,0) ;
        rarm->set_limits(-90 , 90 , -90 , 90 , -90 , 90, 0 , 0 , 0,0 ,0 ,0) ;
        rleg->set_limits(-90 , 20 , -30 , 30 , -30 , 30, 0 , 0 , 0,0 ,0 ,0) ;
        lleg->set_limits(-90 , 20 , -30 , 30 , -30 , 30, 0 , 0 , 0,0 ,0 ,0) ;
        head->set_limits(-90 , 90 , -90 , 90 , -90 , 90, 0 , 0 , 0,0 ,0 ,0 ) ;
        llarm->set_limits(0 , 0 , -160 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        rlarm->set_limits(0 , 0 , 0 , 160 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        rlleg->set_limits(0 , 160 , 0 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        llleg->set_limits(0 , 160 , 0 , 0 , 0 , 0, 0 , 0 , 0,0 ,0 ,0) ;
        
    }
    
    void human_t::make_pose(){
        torso->set_pose(10 , 10 , 10) ;
        larm->set_pose(20 , -60 , 10) ;
        rarm->set_pose(-60 ,30 , 10) ;
        rlarm->set_pose(0 , 100 , 0) ;
        llarm->set_pose(0 , -100 , 0) ;
        lleg->set_pose(-20 , 50 , -20) ;
        llleg->set_pose(40 , 0 , 0) ;
        rlleg->set_pose(20 , 0 , 0) ;
        head->set_pose(30 , 0 , 30) ;
    }
    
    
    void human_t::rotate_x_cc(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->dec_rx() ;
                break;
            case limb_t::torso:
                torso->dec_rx() ;
                break;
            case limb_t::larm:
                larm->dec_rx() ;
                break;
            case limb_t::rarm:
                rarm->dec_rx() ;
                break;
            case limb_t::lleg:
                lleg->dec_rx() ;
                break;
            case limb_t::rleg:
                rleg->dec_rx() ;
                break;
            case limb_t::head:
                head->dec_rx() ;
                break;
            case limb_t::llarm:
                break;
            case limb_t::rlarm:
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                llleg->dec_rx() ;
                break;
            case limb_t::rlleg:
                rlleg->dec_rx() ;
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;    
            default:
                break ;
                
        }
        
    }
    
    void human_t::rotate_y_cc(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->inc_ry();
                break;
            case limb_t::torso:
                torso->inc_ry() ;
                break;
            case limb_t::larm:
                larm->inc_ry() ;
                break;
            case limb_t::rarm:
                rarm->inc_ry() ;
                break;
            case limb_t::lleg:
                lleg->inc_ry();
                break;
            case limb_t::rleg:
                rleg->inc_ry() ;
                break;
            case limb_t::head:
                head->inc_ry() ;
                break;
            case limb_t::llarm:
                llarm->inc_ry() ;
                break;
            case limb_t::rlarm:
                rlarm->inc_ry() ;
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                break;
            case limb_t::rlleg:
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::rotate_z_cc(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->dec_rz() ;
                break;
            case limb_t::torso:
                torso->dec_rz() ;
                break;
            case limb_t::larm:
                larm->dec_rz() ;
                break;
            case limb_t::rarm:
                rarm->dec_rz() ;
                break;
            case limb_t::lleg:
                lleg->dec_rz() ;
                break;
            case limb_t::rleg:
                rleg->dec_rz() ;
                break;
            case limb_t::head:
                head->dec_rz() ;
                break;
            case limb_t::llarm:
                break;
            case limb_t::rlarm:
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                break;
            case limb_t::rlleg:
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::rotate_x_ccw(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->inc_rx() ;
                break;
            case limb_t::torso:
                torso->inc_rx() ;
                break;
            case limb_t::larm:
                larm->inc_rx() ;
                break;
            case limb_t::rarm:
                rarm->inc_rx() ;
                break;
            case limb_t::lleg:
                lleg->inc_rx() ;
                break;
            case limb_t::rleg:
                rleg->inc_rx() ;
                break;
            case limb_t::head:
                head->inc_rx() ;
                break;
            case limb_t::llarm:
                break;
            case limb_t::rlarm:
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                llleg->inc_rx() ;
                break;
            case limb_t::rlleg:
                rlleg->inc_rx() ;
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::rotate_y_ccw(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->dec_ry();
                break;
            case limb_t::torso:
                torso->dec_ry() ;
                break;
            case limb_t::larm:
                larm->dec_ry() ;
                break;
            case limb_t::rarm:
                rarm->dec_ry() ;
                break;
            case limb_t::lleg:
                lleg->dec_ry() ;
                break;
            case limb_t::rleg:
                rleg->dec_ry() ;
                break;
            case limb_t::head:
                head->dec_ry() ;
                break;
            case limb_t::llarm:
                llarm->dec_ry();
                break;
            case limb_t::rlarm:
                rlarm->dec_ry() ;
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                break;
            case limb_t::rlleg:
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::rotate_z_ccw(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->inc_rz() ;
                break;
            case limb_t::torso:
                torso->inc_rz() ;
                break;
            case limb_t::larm:
                larm->inc_rz() ;
                break;
            case limb_t::rarm:
                rarm->inc_rz() ;
                break;
            case limb_t::lleg:
                lleg->inc_rz() ;
                break;
            case limb_t::rleg:
                rleg->inc_rz() ;
                break;
            case limb_t::head:
                head->inc_rz() ;
                break;
            case limb_t::llarm:
                break;
            case limb_t::rlarm:
                break;
            case limb_t::rhand:
                break;
            case limb_t::lhand:
                break;
            case limb_t::llleg:
                break;
            case limb_t::rlleg:
                break;
            case limb_t::rfeet:
                break;
            case limb_t::lfeet:
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::trans_y_inc(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->inc_ty() ;
                break;
            default:
                break ;
                
        }
    }
    
    void human_t::trans_y_dec(){
        limb_t s = get_curr_limb() ;
        switch(s) {
            case limb_t::hip:
                hip->dec_ty() ;
                break;
            default:
                break ;
                
        }
    }
    
}



