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
        
        if (!hip_data){
            std::cout << "not here" << std::endl ;
        }
        glm::vec3 temp = glm::vec3(0 , 0 , 0) ; 
        
        hip = new HNode(NULL , hip_data , temp , this, "render_maps/skin.bmp" , 100, 100) ;
        torso = new HNode(hip , torso_data , temp , this, "render_maps/skin.bmp" , 100, 100) ;
        larm = new HNode(torso , larm_data , temp , this, "render_maps/skin.bmp" , 100, 100) ;
        rarm = new HNode(torso , rarm_data , temp, this, "render_maps/skin.bmp" , 100, 100) ;
        lleg = new HNode(hip , lleg_data , temp, this, "render_maps/skin.bmp" , 100, 100) ;
        rleg = new HNode(hip , rleg_data , temp, this, "render_maps/skin.bmp" , 100, 100) ;
        llarm = new HNode(larm , llarm_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        rlarm = new HNode(rarm , rlarm_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        lhand = new HNode(llarm , lhand_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        rhand = new HNode(rlarm , rhand_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        llleg = new HNode(lleg , llleg_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        rlleg = new HNode(rleg , rlleg_data , temp, this, "render_maps/skin.bmp" , 100, 100) ; 
        rfeet = new HNode(rlleg , rfeet_data , temp, this,"render_maps/stand.bmp" , 284, 177) ; 
        lfeet = new HNode(llleg , lfeet_data , temp, this, "render_maps/stand.bmp" , 284, 177) ; 
        neck = new HNode (torso , neck_data , temp , this, "render_maps/skin.bmp" , 100, 100) ;
        head = new HNode(neck , head_data , temp, this, "render_maps/human.bmp" , 720, 405) ; 
        rstick = new HNode (rhand , rstick_data , temp , this, "render_maps/stand.bmp" , 284, 177) ;
        lstick = new HNode (lhand , lstick_data , temp , this, "render_maps/stand.bmp" , 284, 177) ;
        
        if (!hip){
            std::cout << "not here" << std::endl ;
        }
        
        make_human() ;
        make_pose() ;
        current_limb = limb_t::hip ;
    }
    
    void human_t::make_human(){
        
        hip->change_parameters(0.0 ,-0.0 , 0.0 , 
                               90.0, 0.0 ,0.0 ,
                               0.2 , 0.04 , 0.12) ;
        hip->set_por(glm::vec3(1.0 , -4.0 , 0.0)) ;
        
        torso->change_parameters(0.0 ,0.2 , 0.0 , 
                                 90.0, 0.0 ,0.0 ,
                                 0.2 , 0.16 , 0.12) ;
        torso->set_por(glm::vec3(0.0 , 0.04 , 0.0)) ;
        
        larm->change_parameters(0.28 ,0.14 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.08 , 0.04 , 0.04) ;
        larm->set_por(glm::vec3(0.2 , 0.14 , 0.0)) ;
        
        rarm->change_parameters(-0.28 ,0.14 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.08 , 0.04 , 0.04) ;
        rarm->set_por(glm::vec3(-0.2 , 0.14 , 0.0)) ;
        
        lleg->change_parameters(0.16 , -0.12 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.08 , 0.04) ;
        lleg->set_por(glm::vec3(0.16 , -0.04 , 0.0)) ;
        
        rleg->change_parameters(-0.16 , -0.12 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.08 , 0.04) ;
        rleg->set_por(glm::vec3(-0.16 , -0.04 , 0.0)) ;
        
        head->change_parameters( 0.0, 0.16 , 0.0 , 
                                -90.0, 0.0 ,0.0 ,
                                0.1 , 0.12 , 0.1) ;
        head->set_por(glm::vec3(0.0 , 0.04 , 0.0)) ;
        
        rlarm->change_parameters( -0.16, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.08 , 0.04 , 0.04) ;
        rlarm->set_por(glm::vec3(-0.08 , 0.0 , 0.0)) ;
        
        rhand->change_parameters( -0.12, 0.0 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.08 , 0.02 , 0.01) ;
        
        llarm->change_parameters( 0.16, 0.0 , 0.0 , 
                                0.0, 90.0 ,0.0 ,
                                0.08 , 0.04 , 0.04) ;
        llarm->set_por(glm::vec3(0.08 , 0.0 , 0.0)) ;
        
        lhand->change_parameters( 0.12, 0.0 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.04 , 0.02 , 0.01) ;
        
        llleg->change_parameters( 0.0, -0.16 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.08 , 0.04) ;
        llleg->set_por(glm::vec3(0.0 , -0.08 , 0.0)) ;
        
        lfeet->change_parameters( 0.0, -0.1 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.02 , 0.02 , 0.04) ;
        
        rlleg->change_parameters( 0.0, -0.16 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.08 , 0.04) ;
        rlleg->set_por(glm::vec3(0.0 , -0.08 , 0.0)) ;
        
        rfeet->change_parameters( 0.0, -0.1 , 0.0 , 
                                0.0, 0.0 ,0.0 ,
                                0.02 , 0.02 , 0.04) ;
        
        neck->change_parameters( 0.0, 0.2 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.04 , 0.04 , 0.04) ;
        
        rstick->change_parameters( 0.0, 0.05 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.01 , 0.1 , 0.01) ;
        
        lstick->change_parameters( 0.0, 0.05 , 0.0 , 
                                90.0, 0.0 ,0.0 ,
                                0.01 , 0.1 , 0.01) ;
        
         
    }
    
    void human_t::make_pose(){
        hip->translate(1, -4 , 0) ;
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
    
    void human_t::get_position(std::vector<float>& data){
        
        data.push_back(hip->get_coordinates()[0]);
        data.push_back(hip->get_coordinates()[1]);
        data.push_back(hip->get_coordinates()[2]);
    }
    
    void human_t::set_position(std::vector<float>& data){
        
        int n = data.size() - 1 ;
        hip->translate(data[n] , data[n-1] , data[n-2]) ;
        data.pop_back() ;
        data.pop_back() ;
        data.pop_back() ;
    }
    
}



