
#include<iostream>
#include"primitive.hpp"

namespace csX75 {
    
    void quad(int a, int b, int c, int d, int index 
    , shape* sh ,glm::vec4 *pos , glm::vec4 *col  ) {
        sh->v_colors[index] = col[a];
        sh->v_positions[index] = pos[a];
        index++;
        sh->v_colors[index] = col[b];
        sh->v_positions[index] = pos[b];
        index++;
        sh->v_colors[index] = col[c];
        sh->v_positions[index] = pos[c];
        index++;
        sh->v_colors[index] = col[a];
        sh->v_positions[index] = pos[a];
        index++;
        sh->v_colors[index] = col[c];
        sh->v_positions[index] = pos[c];
        index++;
        sh->v_colors[index] = col[d];
        sh->v_positions[index] = pos[d];
        index++;
    }
    
    square::square(glm::vec4 col) {
        
        positions[0] = glm::vec4(-1.0, -1.0, 1.0, 1.0);
        positions[1] = glm::vec4(-1.0, 1.0, 1.0, 1.0);
        positions[2] = glm::vec4(1.0, 1.0, 1.0, 1.0);
        positions[3] = glm::vec4(1.0, -1.0, 1.0, 1.0);
        positions[4] = glm::vec4(-1.0, -1.0, -1.0, 1.0);
        positions[5] = glm::vec4(-1.0, 1.0, -1.0, 1.0);
        positions[6] = glm::vec4(1.0, 1.0, -1.0, 1.0);
        positions[7] = glm::vec4(1.0, -1.0, -1.0, 1.0);

        for (int i = 0; i < 8; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[36]  ;
        v_colors = new glm::vec4[36] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 36;
        numofvert = 36 ;
    }

    void square::maketriangles(void) {
        quad(1, 0, 3, 2, 0 , this , positions , colors);
        quad(2, 3, 7, 6, 6, this , positions , colors);
        quad(3, 0, 4, 7, 12, this , positions , colors);
        quad(6, 5, 1, 2, 18, this , positions , colors);
        quad(4, 5, 6, 7, 24, this , positions , colors);
        quad(5, 4, 0, 1, 30, this , positions , colors);
    }

    square_wo_topface::square_wo_topface(glm::vec4 col) {
        
        positions[0] = glm::vec4(-1.0, -1.0, 1.0, 1.0);
        positions[1] = glm::vec4(-1.0, 1.0, 1.0, 1.0);
        positions[2] = glm::vec4(1.0, 1.0, 1.0, 1.0);
        positions[3] = glm::vec4(1.0, -1.0, 1.0, 1.0);
        positions[4] = glm::vec4(-1.0, -1.0, -1.0, 1.0);
        positions[5] = glm::vec4(-1.0, 1.0, -1.0, 1.0);
        positions[6] = glm::vec4(1.0, 1.0, -1.0, 1.0);
        positions[7] = glm::vec4(1.0, -1.0, -1.0, 1.0);

        for (int i = 0; i < 8; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[30]  ;
        v_colors = new glm::vec4[30] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 30;
        numofvert = 30 ;
    }

    void square_wo_topface::maketriangles(void) {
        quad(1, 0, 3, 2, 0, this , positions , colors);
        quad(2, 3, 7, 6, 6, this , positions , colors);
        quad(3, 0, 4, 7, 12, this , positions , colors);
        quad(4, 5, 6, 7, 18, this , positions , colors);
        quad(5, 4, 0, 1, 24, this , positions , colors);
    }


    
    cylinder::cylinder(glm::vec4 col) {

        int index = 0 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(cos(2 * PI/10 * i), sin(2 * PI/10 * i), -1.0, 1.0);
            index++ ;
        }
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(cos(2 * PI/10 * i), sin(2 * PI/10 * i), 1.0, 1.0);
            index++ ;
        }
        positions[index] = glm::vec4(0.0, 0.0, -1.0, 1.0);
        index++;
        positions[index] = glm::vec4(0.0, 0.0, 1.0, 1.0);
        index++;
        
                
        for (int i = 0; i < 22; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[120]  ;
        v_colors = new glm::vec4[120] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 120;
        numofvert = 120 ;
        
    }

    void cylinder::maketriangles(){
        quad(0 , 1 , 11 , 10 ,0, this , positions , colors) ;
        quad(1 , 2 , 12 , 11 ,6, this , positions , colors) ;
        quad(2 , 3 , 13 , 12 ,12, this , positions , colors) ;
        quad(3 , 4 , 14 , 13 ,18, this , positions , colors) ;
        quad(4 , 5 , 15 , 14 ,24, this , positions , colors) ;
        quad(5 , 6 , 16 , 15 ,30, this , positions , colors) ;
        quad(6 , 7 , 17 , 16 ,36, this , positions , colors) ;
        quad(7 , 8 , 18 , 17 ,42, this , positions , colors) ;
        quad(8 , 9 , 19 , 18 ,48, this , positions , colors) ;
        quad(9 , 0 , 10 , 19 ,54, this , positions , colors) ;
        
        quad(1 , 0 , 20 , 2 ,60, this , positions , colors );
        quad(3 , 2 , 20 , 4 ,66, this , positions , colors  );
        quad(5 , 4 , 20 , 6 ,72, this , positions , colors  );
        quad(7 , 6 , 20 , 8 ,78, this , positions , colors  );
        quad(9 , 8 , 20 , 0 ,84, this , positions , colors  );
        
        quad(11 , 10 , 21 , 12 ,90 , this , positions , colors );
        quad(13 , 12 , 21 , 14 ,96, this , positions , colors  );
        quad(15 , 14 , 21 , 16, 102, this , positions , colors  );
        quad(17 , 16 , 21 , 18, 108, this , positions , colors  );
        quad(19 , 18 , 21 , 10 , 114, this , positions , colors  );
    }
    
    sphere::sphere(glm::vec4 col){
        int index = 0 ;
        float phi = 0.0 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI * 0.1 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI * 0.25 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI * 0.5 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI * 0.75 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI*0.9 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
        
        phi = PI ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
     
        for (int i = 0; i < 70; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[360]  ;
        v_colors = new glm::vec4[360] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 360;
        numofvert = 360 ;
        
    }
    
    void sphere::maketriangles(){
        
        int trias = -6 ;
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(i, 1 + i, 11 + i , 10 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(9, 0, 10 , 19 , trias , this , positions , colors);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(10 + i, 11 + i, 21 + i , 20 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(19, 10, 20 , 29 , trias , this , positions , colors);
        
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6;
            quad(20 + i, 21 + i, 31 + i , 30 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(29, 20, 30 , 39 , trias , this , positions , colors);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(30 + i, 31 + i, 41 + i , 40 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(39, 30, 40 , 49 , trias , this , positions , colors);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(40 + i, 41 + i, 51 + i , 50 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(49, 40, 50 , 59 , trias , this , positions , colors);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(50 + i, 51 + i, 61 + i , 60 + i , trias , this , positions , colors);
        }
        trias += 6 ;
        quad(59, 50, 60 , 69 , trias , this , positions , colors);
        
    }
    
    cone::cone(glm::vec4 col){
        int index = 0 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(cos(PI/5 * i), sin(PI/5 * i), 0.0, 1.0);
            index++ ;
        }
        positions[index] = glm::vec4(0.0, 0.0, 1.0, 1.0);
        index++;
        
                
        for (int i = 0; i < 11; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[30]  ;
        v_colors = new glm::vec4[30] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 30;
        numofvert = 30 ;
    }
    
    void cone::maketriangles(){
        int trias = 0 ;
        for (int i = 0 ; i < 4 ; i++){
            quad(1+2 *i, 2 * i , 10 , 2 + 2 * i , trias , this , positions , colors) ;
            trias += 6 ;
        }
        
        quad(9, 8 , 10 , 0 , trias , this , positions , colors) ;
        
    }
}
