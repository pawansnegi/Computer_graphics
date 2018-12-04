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

#include <iostream>
#include "fill.hpp"
#include "canvas.hpp"
#include"color.hpp"

namespace mydraw {

    void floodfill_t::stroke(const point_t& pt, const color_t& brush_color
            , canvas_t& canvas) {

        color_t target_color = canvas.get_pixel(pt.x, pt.y);
        if (target_color == brush_color) return;

        set_target_color(target_color);
        set_brush_color(brush_color);

        std::deque<point_t> Q;
        canvas.set_pixel(pt);
        Q.push_back(pt);

        int x, y;

        x = Q[0].x;

        while (!Q.empty()) {
            x = Q[0].x;
            y = Q[0].y;

            color_and_add(x + 1, y, canvas, Q);
            color_and_add(x - 1, y, canvas, Q);
            color_and_add(x, y + 1, canvas, Q);
            color_and_add(x, y - 1, canvas, Q);

            Q.pop_front();
        }

    }

    void floodfill_t::color_and_add(unsigned int xpos, unsigned int ypos
            , canvas_t& canvas, std::deque<point_t> &Q) {

        if (xpos > canvas.get_width()) return;
        if (xpos < 0) return;
        if (ypos > canvas.get_height()) return;
        if (ypos < 0) return;

        color_t colorhere = canvas.get_pixel(xpos, ypos);
        if (colorhere == get_brush_color()) return;

        if (colorhere == get_target_color()) {
            canvas.set_pixel(xpos, ypos);
            point_t newpnt(xpos, ypos);
            Q.push_back(newpnt);
        }

    }

}