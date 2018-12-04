/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   table.hpp
 * Author: pawannegi
 *
 * Created on October 17, 2018, 10:05 PM
 */

#ifndef TABLE_HPP
#define TABLE_HPP

#include "human.hpp"

namespace csX75{
    
    class table_t:public object_t {
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
        
        void make_table() ;
        
    public:
        table_t() {} ;
        ~table_t() {} ;
        
        void init() ;
        
        void hrender() {table_top->render_tree(this);} ;
    };
    
}

#endif /* TABLE_HPP */

