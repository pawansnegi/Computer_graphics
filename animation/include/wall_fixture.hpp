/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wall_fixture.hpp
 * Author: pawannegi
 *
 * Created on November 4, 2018, 7:40 PM
 */

#ifndef WALL_FIXTURE_HPP
#define WALL_FIXTURE_HPP

#include "human.hpp"

namespace csX75{
    
    class wall_fixture_t:public object_t{
    private:
        glm::vec4 fixture_col ;
        
        shape *struc1_data ;
        shape *top_data ;
        shape *light_data ;
        
        HNode *struc1 ;
        HNode *top ;
        HNode *light ;
        
        void make_wallfixture() ;
        
    public:
        wall_fixture_t() {} ;
        ~wall_fixture_t() {};
        
        void init() ;
        
        void hrender() {struc1->render_tree(this);};
    };
}

#endif /* WALL_FIXTURE_HPP */

