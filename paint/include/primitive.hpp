/*
    This file is part of the mydraw.

    mydraw is a simple, interactive drawing program written using OpenGL. 
    
    This code base is meant to serve as a starter code for an assignment in a 
    Computer Graphics course.

    Copyright (c) 2018 by Parag Chaudhuri

    mydraw is free software; you can redistribute it and/or modify it under the 
    terms of the MIT License.

    Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#pragma once

#include <glm/vec2.hpp>
#include"color.hpp"
#include <queue>
#include<iostream>

namespace mydraw
{
        
        class canvas_t ;
        
	enum class primitive_mode_t
	{
		point = 1,
		line,
		triangle
	};

	//2D point
	typedef glm::vec2 point_t;
        
        class primitive_t
	{
        private:
            int size ;
            color_t _brush_color ;
            primitive_mode_t _primitive_mode;
            std::deque<point_t> Q ; 
        
        public:
            std::deque<point_t> get_Q() {return Q ;} ;
            void reset_Q() {Q.clear() ;} ;
            void add_to_Q(point_t newpt) {Q.push_back(newpt) ;} ;
            void remove_frm_Q() {Q.pop_front() ;} ;
            unsigned int sizeofQ() {return Q.size() ;} ;
            
            void set_brush_color(const color_t _color) {_brush_color = _color;};
            color_t get_brush_color() {return _brush_color;} ;
            
            int get_size() {return size ;} ;
            void set_size(int _size) {size = _size;} ; 
            
            void set_primitive(int mode) {_primitive_mode = (primitive_mode_t)mode ;} ;
           
            void swap(int &a , int &b) ;
            void thickline(const point_t &pt, canvas_t &canvas) ;
            void drawline(canvas_t &canvas, int a , int b) ;
            void drawtriangle(canvas_t &canvas) ;
            virtual void stroke(const point_t &pt, canvas_t &canvas)= 0 ;
            
	};
        
        
        class point_primitive:public primitive_t 
        {
        public:
            point_primitive() {
                set_size(1) ;
                set_primitive(1) ;
                set_brush_color(color_t(1.0f,1.0f,1.0f,1.0f)) ;
                        
            };
            ~point_primitive() {} ;
            
            void stroke(const point_t &pt, canvas_t &canvas) ;
        };
        
        
        class line_primitive:public primitive_t 
        {
        public:
            line_primitive(){
                set_size(1) ;
                set_primitive(1) ;
                set_brush_color(color_t(1.0f,1.0f,1.0f,1.0f)) ;
                        
            };
            
            ~line_primitive() {} ;
            
            void stroke(const point_t &pt, canvas_t &canvas) ;
        };
        
        
        class triangle_primitive:public primitive_t 
        {
        public:
            triangle_primitive(){
                set_size(1) ;
                set_primitive(1) ;
                set_brush_color(color_t(1.0f,1.0f,1.0f,1.0f)) ;
                        
            };
            
            ~triangle_primitive() {} ;
            
            void stroke(const point_t &pt, canvas_t &canvas) ;
        };
        
	
}