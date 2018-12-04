/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alien.hpp
 * Author: pawannegi
 *
 * Created on September 30, 2018, 11:25 AM
 */

#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "glm/vec4.hpp"
#include"hierarchy_node.hpp"
#include "primitive.hpp"
#include "glm/vec3.hpp"
#include "human.hpp"

namespace csX75{
    
    
    enum class part_t {
        mainbody=1 , larm , rarm , llarm , rlarm , lleg , rleg
        ,llleg , rlleg
    };
    
    class alien_t:public object_t {
    private:
        glm::vec4 mainbody_color;
        glm::vec4 larm_color ;
        glm::vec4 rarm_color ;
        glm::vec4 lleg_color ;
        glm::vec4 rleg_color ;
        glm::vec4 llarm_color ;
        glm::vec4 rlarm_color ;
        glm::vec4 llleg_color ;
        glm::vec4 rlleg_color ;
        glm::vec4 hat_color ;
        glm::vec4 hatrim_color ;
        
        shape *mainbody_data ;
        shape *larm_data ;
        shape *rarm_data ;
        shape *lleg_data ;
        shape *rleg_data ;
        shape *llarm_data ;
        shape *rlarm_data ;
        shape *llleg_data ;
        shape *rlleg_data ;
        shape *hat_data ;
        shape *hatrim_data ;
        
        HNode *mainbody ;
        HNode *larm ;
        HNode *rarm ;
        HNode *lleg ;
        HNode *rleg ;
        HNode *llarm ;
        HNode *rlarm ;
        HNode *llleg ;
        HNode *rlleg ;
        HNode *hat ;
        HNode *hatrim ;
        
        part_t current_limb ;
        
        void make_alien() ;
        void set_constraints() ;
        void make_pose() ;
        
    public:
        alien_t() {} ;
        ~alien_t() {};
        
        void init() ;
        
        void set_curr_limb(part_t a) {current_limb = a;} ;
        part_t get_curr_limb() {return current_limb;};
        
        void rotate_x_cc() ;
        void rotate_y_cc() ;
        void rotate_z_cc() ;
        
        void rotate_x_ccw() ;
        void rotate_y_ccw() ;
        void rotate_z_ccw() ;
        
        void trans_y_inc() ;
        void trans_y_dec() ;
        
        void hrender() {mainbody->render_tree(this) ;} ;
    };
        
}

#endif /* ALIEN_HPP */

