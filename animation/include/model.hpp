/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   model.hpp
 * Author: pawannegi
 *
 * Created on September 30, 2018, 2:12 PM
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include "human.hpp"
#include "alien.hpp"
#include "box.hpp"
#include "room.hpp"
#include "table.hpp"
#include "curve.hpp"
#include "chair.hpp"
#include "lamp.hpp"
#include "stool.hpp"
#include "sofa.hpp"
#include "cupboard.hpp"
#include "wall_fixture.hpp"

namespace csX75{
    
    enum class animate_mode{
        none , select_point , record , play
    };
    
    class model_t{
    public:
        
        model_t(); 
        ~model_t() {} ;
        
        GLuint shaderprogram1 ;
        GLuint shaderprogram2 ;
        human_t *newhuman ;
        alien_t *newalien ;
        box_t *newbox ;
        room_t *newroom ;
        table_t *newtable ;
        curve_t *bezier_curve ;
        chair_t *newchair ;
        lamp_t *newlamp ;
        stool_t *newstool ;
        sofa_t *newsofa ;
        cupboard_t *newcupboard ;
        wall_fixture_t *newwallfixture ;
        
        float* keyframe ;
        
        obj_type objtype ;
        
        animate_mode curr_mode ;
        
        glm::mat4 view_matrix ;
        int curr_eye_pos ;
        int curr_keyframe ;
        int last_eyeframe ;
        int numofinbetweens ;
        float delta_k;
        float curr_k;
        bool start_eye ;
        int framenum ;
        int fps ;
        
        std::vector< std::vector<float> > keyframes ;
        
        void init() ;
        void clear_stack() ;
        void set_view_mat(glm::mat4 viewmat) ;
        void render() ;
        
        void change_mode(animate_mode a) {curr_mode = a ;} ;
        void add_point() ;
        void remove_point() ;
        
        glm::vec4 get_camera_pos();
        glm::vec4 get_up_vector() {return glm::vec4(0.0,1.0,0.0,1.0) ;};
        glm::vec4 get_box_postion() {return newbox->position() ;};
        //glm::vec4 get_box_postion() {return glm::vec4(0.0,0.0,0.0,1.0) ;;};
        
        void get_keyframe() ;
        void read_keyframes() ;
        void set_pose() ;
        void interpolate_keyframes(std::vector<float> &key1 
                , std::vector<float> &key2 , float k , std::vector<float> &outframe) ;
        
        int save(void) ;
        
    };
    
}

#endif /* MODEL_HPP */

