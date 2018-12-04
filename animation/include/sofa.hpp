/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sofa.hpp
 * Author: pawannegi
 *
 * Created on November 4, 2018, 4:01 PM
 */

#ifndef SOFA_HPP
#define SOFA_HPP

#include"human.hpp"

namespace csX75{
    
    class sofa_t:public object_t{
    private:
        glm::vec4 sofa_color ;
        
        shape* base_data ;
        shape* back_data ;
        shape* h1_data ;
        shape* h2_data ;
        shape* h3_data ;
        shape* h4_data ;
        shape* h5_data ;
        shape* h6_data ;
        
        HNode *base ;
        HNode *back ;
        HNode *h1 ;
        HNode *h2 ;
        HNode *h3 ;
        HNode *h4 ;
        HNode *h5 ;
        HNode *h6 ;
        
        void make_sofa() ;
        
    public:
        
        sofa_t() {} ;
        ~sofa_t() {} ;
        
        void init() ;
        
        void hrender() {base->render_tree(this);} ;
    };
    
}

#endif /* SOFA_HPP */

