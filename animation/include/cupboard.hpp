/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cupboard.hpp
 * Author: pawannegi
 *
 * Created on November 4, 2018, 6:48 PM
 */

#ifndef CUPBOARD_HPP
#define CUPBOARD_HPP

#include "human.hpp"

namespace csX75{
    class cupboard_t:public object_t{
    private:
        glm::vec4 cupboard_col ;
        
        shape *cupboard_data ;
        shape *front_d ;
        
        HNode *cupboard ;
        HNode *front ;
        
        void make_cupboard() ;
        
    public:
        cupboard_t() {} ;
        ~cupboard_t() {} ;
        
        void init() ;
        
        void hrender() {cupboard->render_tree(this);};
    };
}

#endif /* CUPBOARD_HPP */

