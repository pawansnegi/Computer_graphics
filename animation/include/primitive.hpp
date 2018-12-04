#ifndef _PRIMITIVE_HPP_
#define _PRIMITIVE_HPP_

#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include<math.h>
#define PI 3.1419
namespace csX75{
    
    
    class shape {
        
    public:
        glm::vec4 *v_positions;
        glm::vec4 *v_colors;
        glm::vec4 *v_normals ;
        glm::vec2 *v_texcoord ;
        std::size_t size ;
        std::size_t size_tex ;
        int numofvert ;
        
    };
    
    class square:public shape{    
    private:
        glm::vec4 positions[8];
        glm::vec4 colors[8] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
    public:
        square() {} ;
        square(glm::vec4 col);
        ~square() {} ;
        
    };
    
    class square_wo_topface:public shape{    
    private:
        glm::vec4 positions[8];
        glm::vec4 colors[8] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
    public:
        square_wo_topface() {} ;
        square_wo_topface(glm::vec4 col) ;
        ~square_wo_topface() {} ;
        
    };
    
    class cylinder:public shape{    
    private:
        glm::vec4 positions[22];
        glm::vec4 colors[22] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        void settexture(shape* sh) ;
        
    public:
        cylinder() {} ;
        cylinder(glm::vec4 col) ;
        ~cylinder() {} ;
        
    };
    
    class sphere:public shape{    
    private:
        glm::vec4 positions[70];
        glm::vec4 colors[70] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        void settexture(shape* sh) ;
        
    public:
        sphere() {} ;
        sphere(glm::vec4 col) ;
        ~sphere() {} ;
        
    };
    
    class cone:public shape{    
    private:
        glm::vec4 positions[11];
        glm::vec4 colors[11] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
    public:
        cone() {} ;
        cone(glm::vec4 col) ;
        ~cone() {} ;
        
    };
    
    class cone_frustum:public shape{    
    private:
        glm::vec4 positions[20];
        glm::vec4 colors[20] ;
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
    public:
        cone_frustum() {} ;
        cone_frustum(glm::vec4 col) ;
        ~cone_frustum() {} ;
        
    };
    
    class room_p:public shape{
    private:
        glm::vec4 positions[16];
        glm::vec4 colors[16];
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
        
    public:
        room_p() {} ;
        room_p(glm::vec4 col) ;
        ~room_p() {} ;
    };
    
    class sheet_p:public shape{
    private:
        glm::vec4 positions[4];
        glm::vec4 colors[4];
        glm::vec2 t_coord[4];
        void maketriangles(void);
        
        
    public:
        sheet_p() {} ;
        sheet_p(glm::vec4 col) ;
        ~sheet_p() {} ;
    };
    
    void quad(int a, int b, int c, int d , int index 
               , shape* , glm::vec4* , glm::vec4* , glm::vec2*) ;
    
    glm::vec4 calculate_normal(glm::vec4, glm::vec4, glm::vec4) ;
    
}

#endif