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

#include"primitive.hpp"
#include "canvas.hpp"
#include<iostream>

namespace mydraw
{

    void point_primitive::stroke(const point_t& pt, canvas_t& canvas) {
        
        thickline(pt , canvas) ;
                
    }
    
    void line_primitive::stroke(const point_t& pt, canvas_t& canvas) {
        
        add_to_Q(pt);
        
        if((int)sizeofQ() > 2){
            remove_frm_Q() ;
        }
        
        if((int)sizeofQ() < 2){
            return ;
        }
        else if ((int)sizeofQ() == 2){
            drawline(canvas , 0 , 1) ;
        }
    }
    
    void triangle_primitive::stroke(const point_t& pt, canvas_t& canvas) {
        
        add_to_Q(pt);
        
        if((int)sizeofQ() > 3){
            remove_frm_Q() ;
        }
        
        if((int)sizeofQ() < 3){
            return ;
        }
        else if ((int)sizeofQ() == 3){
            drawtriangle(canvas) ;
        }
    }

    void primitive_t::drawline(canvas_t &canvas , int a , int b )
    {
        
        int x0 = Q[a].x ;
        int y0 = Q[a].y ;
        int x1 = Q[b].x ;
        int y1 = Q[b].y ;
            
        bool steep = abs(y1 - y0) > abs(x1 - x0);
        if (steep)
        {
          swap(x0, y0);
          swap(x1, y1);
        }
        if (x0 > x1)
        {
          swap(x0, x1);
          swap(y0, y1);
        }
        int deltax = x1 - x0;
        int deltay = abs(y1 - y0);

        float error = 0.0;
        float deltaerr = (float)deltay / (float)deltax;

        int ystep;
        int y = y0;

        if (y0 < y1) ystep = 1; else ystep = -1;

        point_t newpnt ;
        for (int x=x0; x < x1; x++)
        {
          if (steep){
              newpnt.x = y ;
              newpnt.y = x ;
              thickline(newpnt , canvas);
          }
          else{
              newpnt.x = x ;
              newpnt.y = y ;
              thickline(newpnt , canvas);
          } 

          error = error + deltaerr;
          if (error >= 0.5) 
            {
              y = y + ystep;
              error = error - 1.0;
            }
        }
        
    }
    
    void primitive_t::swap(int &a, int &b){
        
        int c = a ;
        a = b ;
        b = c ;
    }
    

    void primitive_t::thickline(const point_t &pt, canvas_t &canvas) {

        int x, y, newx, newy;
        x = pt.x;
        y = pt.y;
        int curr_size = get_size();
        if (curr_size == 1) {
            canvas.set_pixel(pt);
        }
        else if (get_size() > 1) {
            for (int i = 0; i < curr_size; i++) {
                for (int j = 0; j < get_size(); j++) {
                    newx = x - curr_size / 2 + i;
                    newy = y - curr_size / 2 + j;
                    if ((newx < (int) canvas.get_width()) &&
                            (newy < (int) canvas.get_height()) &&
                            (newx > 0) &&
                            (newy > 0)) {
                        canvas.set_pixel(newx, newy);
                    }

                }
            }
        }
    }
    

    void primitive_t::drawtriangle(canvas_t& canvas){
        
        drawline(canvas ,0 , 1) ;
        drawline(canvas , 1 , 2) ;
        drawline(canvas ,2 , 0);
                
    }
}