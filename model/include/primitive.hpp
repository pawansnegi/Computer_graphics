#ifndef _PRIMITIVE_HPP_
#define _PRIMITIVE_HPP_

#include "glm/vec4.hpp"
#include<math.h>
#define PI 3.1419
namespace csX75{
    
    
    class shape {
        
    public:
        glm::vec4 *v_positions;
        glm::vec4 *v_colors;
        std::size_t size ;
        int numofvert ;
        
    };
    
    class square:public shape{    
    private:
        glm::vec4 positions[8];
        glm::vec4 colors[8] ;
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
        void maketriangles(void);
        
    public:
        cylinder() {} ;
        cylinder(glm::vec4 col) ;
        ~cylinder() {} ;
        
    };
    
    class sphere:public shape{    
    private:
        glm::vec4 positions[70];
        glm::vec4 colors[70] ;
        void maketriangles(void);
        
    public:
        sphere() {} ;
        sphere(glm::vec4 col) ;
        ~sphere() {} ;
        
    };
    
    class cone:public shape{    
    private:
        glm::vec4 positions[11];
        glm::vec4 colors[11] ;
        void maketriangles(void);
        
    public:
        cone() {} ;
        cone(glm::vec4 col) ;
        ~cone() {} ;
        
    };
    
    void quad(int a, int b, int c, int d , int index 
               , shape* , glm::vec4* , glm::vec4*) ;
    
}

#endif
