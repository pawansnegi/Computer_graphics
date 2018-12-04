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

namespace csX75{
    
    class model_t{
    public:
        
        model_t() {} ;
        ~model_t() {} ;
        human_t *newhuman ;
        alien_t *newalien ;
        box_t *newbox ;
        obj_type objtype ;
    };
    
}

#endif /* MODEL_HPP */

