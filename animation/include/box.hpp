/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   box.hpp
 * Author: pawannegi
 *
 * Created on September 30, 2018, 6:14 PM
 */

#ifndef BOX_HPP
#define BOX_HPP

#include "human.hpp"

namespace csX75{
    
    class box_t:public object_t {
    private:
        glm::vec4 bottom_color ;
        glm::vec4 lid_color ;
        
        shape *bottom_data ;
        shape *lid_data ;
        
        HNode *bottom ;
        HNode *lid ;

        void make_box() ;
        
    public:
        box_t() {} ;
        ~box_t() {} ;
        
        void init() ;
        
        void open_box() ;
        void close_box() ;
        
        void rotate_x_cc() {bottom->inc_rx();};
        void rotate_x_ccw() {bottom->dec_rx();} ;
        void rotate_y_cc() {bottom->inc_ry();};
        void rotate_y_ccw() {bottom->dec_ry();} ;
        void rotate_z_cc() {bottom->inc_rz();};
        void rotate_z_ccw() {bottom->dec_rz();} ;
        
        void trans_x_inc() {bottom->inc_tx();};
        void trans_y_inc() {bottom->inc_ty();};
        void trans_z_inc() {bottom->inc_tz();};
        void trans_x_dec() {bottom->dec_tx();};
        void trans_y_dec() {bottom->dec_ty();};
        void trans_z_dec() {bottom->dec_tz();};
        
        void hrender() {bottom->render_tree(this) ;} ; 
        glm::vec4 position() {return bottom->get_coordinates() ; };
        void get_all_poses(std::vector<float>&data) {bottom->get_orientation(data);} ;
        void set_all_poses(std::vector<float>&data) {bottom->set_orientation(data);} ;
        void get_position(std::vector<float>&data);
        void set_position(std::vector<float>&data);
        
    };
}


#endif /* BOX_HPP */

