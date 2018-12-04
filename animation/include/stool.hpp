/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stool.hpp
 * Author: pawannegi
 *
 * Created on November 1, 2018, 2:03 AM
 */

#ifndef STOOL_HPP
#define STOOL_HPP

#include "human.hpp"

namespace csX75{
    
    class stool_t:public object_t {
    private:
        glm::vec4 table_col ;
        
        shape *table_top_d ;
        shape *leg1_d ;
        shape *leg2_d ;
        shape *leg3_d ;
        shape *leg4_d ;
        
        HNode *table_top ;
        HNode *leg1 ;
        HNode *leg2 ;
        HNode *leg3 ;
        HNode *leg4 ;
        
        void make_stool() ;
        
    public:
        stool_t() {} ;
        ~stool_t() {} ;
        
        void init() ;
        
        void hrender() {table_top->render_tree(this);} ;
    };
    
}

#endif /* STOOL_HPP */

