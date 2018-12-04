/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chair.hpp
 * Author: pawannegi
 *
 * Created on November 1, 2018, 12:46 AM
 */

#ifndef CHAIR_HPP
#define CHAIR_HPP

#include"human.hpp"

namespace csX75{
    class chair_t:public object_t{
    private:
        glm::vec4 seat_col ;
        glm::vec4 leg1_col ;
        glm::vec4 leg2_col ;
        glm::vec4 leg3_col ;
        glm::vec4 leg4_col ;
        glm::vec4 back1_col ;
        glm::vec4 back2_col ;
        glm::vec4 back3_col;
        glm::vec4 back4_col ;
        
        shape *seat_data ;
        shape *leg1_data ;
        shape *leg2_data ;
        shape *leg3_data ;
        shape *leg4_data ;
        shape *back1_data ;
        shape *back2_data ;
        shape *back3_data ;
        shape *back4_data ;
        
        HNode *seat ;
        HNode *leg1 ;
        HNode *leg2 ;
        HNode *leg3 ;
        HNode *leg4 ;
        HNode *back1 ;
        HNode *back2 ;
        HNode *back3 ;
        HNode *back4 ;
        
        void make_chair() ;
        
    public:
        chair_t() {} ;
        ~chair_t() {} ;
        
        void init() ;
        void hrender() {seat->render_tree(this) ;} ; 
    };
    
}


#endif /* CHAIR_HPP */

