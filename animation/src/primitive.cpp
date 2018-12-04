
#include<iostream>
#include <math.h>
#include"primitive.hpp"

namespace csX75 {
    
    void quad(int a, int b, int c, int d, int index 
    , shape* sh ,glm::vec4 *pos , glm::vec4 *col, glm::vec2 *tex  ) {
        sh->v_colors[index] = col[a];
        sh->v_positions[index] = pos[a];
        sh->v_texcoord[index] = tex[1] ;
        index++;
        sh->v_colors[index] = col[b];
        sh->v_positions[index] = pos[b];
        sh->v_texcoord[index] = tex[0] ;
        index++;
        sh->v_colors[index] = col[c];
        sh->v_positions[index] = pos[c];
        sh->v_texcoord[index] = tex[2] ;
        
        glm::vec4 normal = calculate_normal(sh->v_positions[index -1 ]
                ,sh->v_positions[index - 2] ,
                sh->v_positions[index] ) ;
        
        sh->v_normals[index] = normal ;
        sh->v_normals[index - 1] = normal ;
        sh->v_normals[index - 2] = normal ;
    
        index++;
        sh->v_colors[index] = col[a];
        sh->v_positions[index] = pos[a];
        sh->v_texcoord[index] = tex[1] ;
        index++;
        sh->v_colors[index] = col[c];
        sh->v_positions[index] = pos[c];
        sh->v_texcoord[index] = tex[2] ;
        index++;
        sh->v_colors[index] = col[d];
        sh->v_positions[index] = pos[d];
        sh->v_texcoord[index] = tex[3] ;
        
        normal = calculate_normal(sh->v_positions[index -1 ]
                ,sh->v_positions[index - 2] ,
                sh->v_positions[index] ) ;
        
        sh->v_normals[index] = normal ;
        sh->v_normals[index - 1] = normal ;
        sh->v_normals[index - 2] = normal ;
    }
    
    glm::vec4 calculate_normal(glm::vec4 a, glm::vec4 b, glm::vec4 c){
        glm::vec4 vec1 = b - a;
        glm::vec4 vec2 = c - a ;
        
        // convert to vec3
        glm::vec3 v1 = glm::vec3(vec1[0] , vec1[1] , vec1[2]) ;
        glm::vec3 v2 = glm::vec3(vec2[0] , vec2[1] , vec2[2]);
        
        glm::vec3 cross1 = glm::cross(v2 , v1) ;
        cross1 = glm::normalize(cross1) ;
        
        return glm::vec4(cross1, 1.0) ;
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

        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);        
         
        for (int i = 0; i < 8; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[36]  ;
        v_colors = new glm::vec4[36] ;
        v_normals = new glm::vec4[36] ;
        v_texcoord = new glm::vec2[36] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 36;
        size_tex = sizeof(*v_texcoord) * 36 ;
        numofvert = 36 ;
    }

    void square::maketriangles(void) {
        quad(1, 0, 3, 2, 0 , this , positions , colors ,t_coord );
        quad(2, 3, 7, 6, 6, this , positions , colors, t_coord);
        quad(3, 0, 4, 7, 12, this , positions , colors, t_coord);
        quad(6, 5, 1, 2, 18, this , positions , colors, t_coord);
        quad(4, 5, 6, 7, 24, this , positions , colors, t_coord);
        quad(5, 4, 0, 1, 30, this , positions , colors, t_coord);
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

        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 8; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[30]  ;
        v_colors = new glm::vec4[30] ;
        v_normals = new glm::vec4[30] ;
        v_texcoord = new glm::vec2[30] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 30;
        size_tex = sizeof(*v_texcoord) * 30 ;
        numofvert = 30 ;
    }

    void square_wo_topface::maketriangles(void) {
        quad(1, 0, 3, 2, 0, this , positions , colors, t_coord);
        quad(2, 3, 7, 6, 6, this , positions , colors, t_coord);
        quad(3, 0, 4, 7, 12, this , positions , colors, t_coord);
        quad(4, 5, 6, 7, 18, this , positions , colors, t_coord);
        quad(5, 4, 0, 1, 24, this , positions , colors, t_coord);
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
        
            
        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 22; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[120]  ;
        v_colors = new glm::vec4[120] ;
        v_normals = new glm::vec4[120] ;
        v_texcoord = new glm::vec2[120] ;
        
        size = sizeof(*v_positions) * 120;
        size_tex = sizeof(*v_texcoord) * 120 ;
        numofvert = 120 ;
        
        maketriangles() ;
        settexture(this) ;
        
        
    }

    void cylinder::maketriangles(){
        quad(0 , 1 , 11 , 10 ,0, this , positions , colors, t_coord) ;
        quad(1 , 2 , 12 , 11 ,6, this , positions , colors, t_coord) ;
        quad(2 , 3 , 13 , 12 ,12, this , positions , colors, t_coord) ;
        quad(3 , 4 , 14 , 13 ,18, this , positions , colors, t_coord) ;
        quad(4 , 5 , 15 , 14 ,24, this , positions , colors, t_coord) ;
        quad(5 , 6 , 16 , 15 ,30, this , positions , colors, t_coord) ;
        quad(6 , 7 , 17 , 16 ,36, this , positions , colors, t_coord) ;
        quad(7 , 8 , 18 , 17 ,42, this , positions , colors, t_coord) ;
        quad(8 , 9 , 19 , 18 ,48, this , positions , colors, t_coord) ;
        quad(9 , 0 , 10 , 19 ,54, this , positions , colors, t_coord) ;
        
        quad(1 , 0 , 20 , 2 ,60, this , positions , colors , t_coord);
        quad(3 , 2 , 20 , 4 ,66, this , positions , colors , t_coord );
        quad(5 , 4 , 20 , 6 ,72, this , positions , colors , t_coord );
        quad(7 , 6 , 20 , 8 ,78, this , positions , colors , t_coord );
        quad(9 , 8 , 20 , 0 ,84, this , positions , colors , t_coord );
        
        quad(11 , 10 , 21 , 12 ,90 , this , positions , colors, t_coord );
        quad(13 , 12 , 21 , 14 ,96, this , positions , colors  , t_coord);
        quad(15 , 14 , 21 , 16, 102, this , positions , colors , t_coord );
        quad(17 , 16 , 21 , 18, 108, this , positions , colors  , t_coord);
        quad(19 , 18 , 21 , 10 , 114, this , positions , colors , t_coord );
    }
    
    void cylinder::settexture(shape* sh){
        float x=0.0, y=0.0, z=0.0 ;
        float angle = 0 , dist = 0;
        float u=0, v=0 ;
        float totaldist = 1.0 + 1.0 + 2.0 ; // total half perimeter
        for (int i = 0 ; i < sh->numofvert ; i++){
            x = sh->v_positions[i][0] ;
            y = sh->v_positions[i][1] ;
            z = sh->v_positions[i][2] ;
            
            if ((abs(x) < 0.000001) && (abs(y) < 0.000001) &&
                    (abs(z + 1) < 0.000001)){
                sh->v_texcoord[i] = glm::vec2(0.0,1.0) ;
            }
            
            else if ((abs(x) < 0.000001) && (abs(y) < 0.000001) &&
                    (abs(z - 1) < 0.000001)){
                sh->v_texcoord[i] = glm::vec2(0.0,0.0) ;
            }
            
            else{
                angle = std::atan2(y, x) + PI ;
                dist = z + 1.0 + 1.0 ;
                u = angle / 2.0 / PI ;
                v = dist / totaldist ;
                sh->v_texcoord[i] = glm::vec2(u, v) ;
            }
        }
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
        
        phi = PI * 0.3 ;
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
        
        phi = PI * 0.7 ;
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
        
        phi = PI *1.0;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(sin(phi) * cos(2 * PI/10 * i)
                    , sin(phi) * sin(2 * PI/10 * i), cos(phi), 1.0);
            index++ ;
        }
     
        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 70; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[360]  ;
        v_colors = new glm::vec4[360] ;
        v_normals = new glm::vec4[360] ;
        v_texcoord = new glm::vec2[360] ;
        
                
        size = sizeof(*v_positions) * 360;
        size_tex = sizeof(*v_texcoord) * 360 ;
        numofvert = 360 ;
        
        maketriangles() ;
        settexture(this) ;
        
    }
    
    void sphere::maketriangles(){
        int trias = -6 ;
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(i, 1 + i, 11 + i , 10 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(9, 0, 10 , 19 , trias , this , positions , colors, t_coord);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(10 + i, 11 + i, 21 + i , 20 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(19, 10, 20 , 29 , trias , this , positions , colors, t_coord);
        
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6;
            quad(20 + i, 21 + i, 31 + i , 30 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(29, 20, 30 , 39 , trias , this , positions , colors, t_coord);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(30 + i, 31 + i, 41 + i , 40 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(39, 30, 40 , 49 , trias , this , positions , colors, t_coord);
        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(40 + i, 41 + i, 51 + i , 50 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(49, 40, 50 , 59 , trias , this , positions , colors, t_coord);

        
        for (int i = 0 ; i < 9 ; i++){
            trias += 6 ;
            quad(50 + i, 51 + i, 61 + i , 60 + i , trias , this , positions , colors, t_coord);
        }
        trias += 6 ;
        quad(59, 50, 60 , 69 , trias , this , positions , colors, t_coord);
        
    }
    
    void sphere::settexture(shape* sh){
        float x1=0.0, y1=0.0, z1=0.0 ;
        float x2=0.0, y2=0.0, z2=0.0 ;
        float x3=0.0, y3=0.0, z3=0.0 ;
        float angle1 = 0, angle2 = 0, angle3 = 0 ;
        float dist1 = 0, dist2 = 0, dist3 = 0;
        float u1=0, v1=0 ;
        float u2=0, v2=0 ;
        float u3=0, v3=0 ;
        float totaldist = 2.0 ; // total half perimeter
        for (int i = 0 ; i < sh->numofvert; i=i+3) {
            x1 = sh->v_positions[i][0];
            y1 = sh->v_positions[i][1];
            z1 = sh->v_positions[i][2];
            
            x2 = sh->v_positions[i+1][0];
            y2 = sh->v_positions[i+1][1];
            z2 = sh->v_positions[i+1][2];
            
            x3 = sh->v_positions[i+2][0];
            y3 = sh->v_positions[i+2][1];
            z3 = sh->v_positions[i+2][2];
            
            angle1 = std::atan2(y1, x1) + PI;
            angle2 = std::atan2(y2, x2) + PI;
            angle3 = std::atan2(y3, x3) + PI;
            
            if (angle1 > PI || angle2 > PI || angle3 > PI){
                if (angle1 < PI){
                    angle1 = 2.0 * PI ;
                }
                if (angle2 < PI){
                    angle2 = 2.0 * PI ;
                }
                if (angle3 < PI){
                    angle3 = 2.0 * PI ;
                }
                //std::cout << "hree 1" << std::endl ;
            }
            
            else if (angle1 < PI || angle2 < PI || angle3 < PI){
                if (angle1 > PI){
                    angle1 = 0.0 ;
                }
                if (angle2 > PI){
                    angle2 = 0.0 ;
                }
                if (angle3 > PI){
                    angle3 = 0.0 ;
                }
                //std::cout << "hree 3" << std::endl ;
            }
            
            dist1 = z1 + 1.0;
            u1 = angle1 / 2.0 / PI;
            v1 = dist1 / totaldist;
            sh->v_texcoord[i] = glm::vec2(u1, v1);
            
            dist2 = z2 + 1.0;
            u2 = angle2 / 2.0 / PI;
            v2 = dist2 / totaldist;
            sh->v_texcoord[i+1] = glm::vec2(u2, v2);
            
            dist3 = z3 + 1.0;
            u3 = angle3 / 2.0 / PI;
            v3 = dist3 / totaldist;
            sh->v_texcoord[i+2] = glm::vec2(u3, v3);
        }
        
    }
    
    cone::cone(glm::vec4 col){
        int index = 0 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(cos(PI/5 * i), sin(PI/5 * i), 0.0, 1.0);
            index++ ;
        }
        positions[index] = glm::vec4(0.0, 0.0, 1.0, 1.0);
        index++;
        
          
        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 11; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[30]  ;
        v_colors = new glm::vec4[30] ;
        v_normals = new glm::vec4[30] ;
        v_texcoord = new glm::vec2[30] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 30;
        size_tex = sizeof(*v_texcoord) * 30 ;
        numofvert = 30 ;
    }
    
    void cone::maketriangles(){
        int trias = 0 ;
        for (int i = 0 ; i < 4 ; i++){
            quad(1+2 *i, 2 * i , 10 , 2 + 2 * i , trias , this , positions , colors, t_coord) ;
            trias += 6 ;
        }
        
        quad(9, 8 , 10 , 0 , trias , this , positions , colors, t_coord) ;
        
    }
    
    cone_frustum::cone_frustum(glm::vec4 col){
        int index = 0 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(cos(PI/5 * i), sin(PI/5 * i), 0.0, 1.0);
            index++ ;
        }
        
        float r2 = 0.5 ;
        for (int i = 0; i< 10 ; i++){
            positions[index] = glm::vec4(r2 * cos(PI/5 * i),r2* sin(PI/5 * i), 1.0, 1.0);
            index++ ;
        }
        
          
        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 11; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[60]  ;
        v_colors = new glm::vec4[60] ;
        v_normals = new glm::vec4[60] ;
        v_texcoord = new glm::vec2[60] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 60;
        size_tex = sizeof(*v_texcoord) * 60 ;
        numofvert = 60 ;
    }
    
    void cone_frustum::maketriangles(){
        int trias = 0 ;
        for (int i = 0 ; i < 9 ; i++){
            
            quad(i, 1 + i, 11 + i , 10 + i , trias , this , positions , colors, t_coord);
            trias += 6 ;
        }
        quad(9, 0, 10 , 19 , trias , this , positions , colors, t_coord);
    }
    
    room_p::room_p(glm::vec4 col){
        positions[0] = glm::vec4(-1.0, -1.0, 1.0, 1.0);
        positions[1] = glm::vec4(-1.0, 1.0, 1.0, 1.0);
        positions[2] = glm::vec4(1.0, 1.0, 1.0, 1.0);
        positions[3] = glm::vec4(1.0, -1.0, 1.0, 1.0);
        positions[4] = glm::vec4(-1.0, -1.0, -1.0, 1.0);
        positions[5] = glm::vec4(-1.0, 1.0, -1.0, 1.0);
        positions[6] = glm::vec4(1.0, 1.0, -1.0, 1.0);
        positions[7] = glm::vec4(1.0, -1.0, -1.0, 1.0);

        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 8; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[24]  ;
        v_colors = new glm::vec4[24] ;
        v_normals = new glm::vec4[24] ;
        v_texcoord = new glm::vec2[24] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 24;
        size_tex = sizeof(*v_texcoord) * 24 ;
        numofvert = 24 ;
        
    }
    
    void room_p::maketriangles(){
        quad(3, 0, 4, 7, 0, this , positions , colors, t_coord);
        quad(6, 5, 1, 2, 6, this , positions , colors, t_coord);
        quad(4, 5, 6, 7, 12, this , positions , colors, t_coord);
        quad(5, 4, 0, 1, 18, this , positions , colors, t_coord);
    }
    
    sheet_p::sheet_p(glm::vec4 col){
        positions[0] = glm::vec4(-1.0, -1.0, 0.0, 1.0);
        positions[1] = glm::vec4(-1.0, 1.0, 0.0, 1.0);
        positions[2] = glm::vec4(1.0, 1.0, 0.0, 1.0);
        positions[3] = glm::vec4(1.0, -1.0, 0.0, 1.0);

        t_coord[0] = glm::vec2( 0.0, 0.0);
        t_coord[1] = glm::vec2( 0.0, 1.0);
        t_coord[2] = glm::vec2( 1.0, 0.0);
        t_coord[3] = glm::vec2( 1.0, 1.0);
        
        for (int i = 0; i < 4; i++)
            colors[i] = col;
        
        v_positions = new glm::vec4[6]  ;
        v_colors = new glm::vec4[6] ;
        v_normals = new glm::vec4[6] ;
        v_texcoord = new glm::vec2[6] ;
        
        maketriangles() ;
        
        size = sizeof(*v_positions) * 6;
        size_tex = sizeof(*v_texcoord) * 6 ;
        numofvert = 6 ;
        
    }
    
    void sheet_p::maketriangles(){
        quad(1, 0, 3, 2, 0 , this , positions , colors ,t_coord );
    }
    
    
}
