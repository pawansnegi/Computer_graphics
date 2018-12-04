/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   room.hpp
 * Author: pawannegi
 *
 * Created on October 14, 2018, 11:54 AM
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include "human.hpp"

namespace csX75{
    
    class room_t:public object_t {
    private:
        glm::vec4 room_col ;
        
        shape *wall1 ;
        shape *wall2 ;
        shape *wall3 ;
        shape *wall4 ;
        
        HNode *w1 ;
        HNode *w2 ;
        HNode *w3 ;
        HNode *w4 ;
        
        void make_room() ;
        
    public:
        room_t() {} ;
        ~room_t() {} ;
        
        void init() ;
        
        void hrender() {w1->render_tree(this);} ;
    };
}


#endif /* ROOM_HPP */

