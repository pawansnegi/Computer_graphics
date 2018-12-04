/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lamp.hpp
 * Author: pawannegi
 *
 * Created on November 1, 2018, 1:37 AM
 */

#ifndef LAMP_HPP
#define LAMP_HPP

#include "human.hpp"

namespace csX75{
    class lamp_t:public object_t{
    private:
        glm::vec4 lamp_col ;
        
        shape* frus_data ;
        shape* frustop_data ;
        shape* stand_data ;
        shape* base_data ;
        
        HNode* frustum ;
        HNode* frustop ;
        HNode* stand ;
        HNode* base ;
        
        void make_lamp() ;
        
    public:
        lamp_t() {};
        ~lamp_t() {} ;
        
        void init() ;
        
        void hrender(){frustum->render_tree(this);} ;
    };
    
}


#endif /* LAMP_HPP */

