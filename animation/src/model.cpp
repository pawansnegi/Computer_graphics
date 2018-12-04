/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "model.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "stb_image_write.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_TGA
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.hpp"

namespace csX75 {

    model_t::model_t() {

        shaderprogram1 = 0 ;
        shaderprogram2 = 0 ;
        
        newhuman = new human_t();
        newalien = new alien_t();
        newbox = new box_t();
        newroom = new room_t();
        newtable = new table_t() ;
        bezier_curve = new curve_t();
        newchair = new chair_t() ;
        newlamp = new lamp_t() ;
        newstool = new stool_t();
        newsofa = new sofa_t() ;
        newcupboard = new cupboard_t();
        newwallfixture = new wall_fixture_t();
        
        objtype = obj_type::human;
        curr_mode = animate_mode::none ;
        curr_eye_pos = 0 ;
        last_eyeframe = 99 ;
        start_eye = false ;
        curr_keyframe = 0;
        numofinbetweens = 10;
        delta_k = 1.0 / (numofinbetweens + 1) ;
        curr_k = 0.0 ;
        framenum = 0 ;
        fps = 5 ;
                
    }

    void model_t::init() {

        // getting the attributes from the shader program
        GLuint vpos = glGetAttribLocation(shaderprogram1, "vPosition");
        GLuint vcol = glGetAttribLocation(shaderprogram1, "vColor");
        GLuint vnorm = glGetAttribLocation(shaderprogram1, "vNormal");
        GLuint tc = glGetAttribLocation(shaderprogram1, "texCoord");
        GLuint viewmat = glGetUniformLocation(shaderprogram1, "viewMatrix");
        GLuint normat = glGetUniformLocation(shaderprogram1, "normalMatrix");
        GLuint umodel = glGetUniformLocation(shaderprogram1, "uModelViewMatrix");

        
        newhuman->set_vposition(vpos);
        newhuman->set_vcolor(vcol);
        newhuman->set_vnormal(vnorm);
        newhuman->set_vModelviewmatrix(umodel);
        newhuman->set_viewMatrix(viewmat);
        newhuman->set_normalMatrix(normat);
        newhuman->set_texCoord(tc);
        newhuman->init();

        newalien->set_vposition(vpos);
        newalien->set_vcolor(vcol);
        newalien->set_vnormal(vnorm);
        newalien->set_vModelviewmatrix(umodel);
        newalien->set_viewMatrix(viewmat);
        newalien->set_normalMatrix(normat);
        newalien->set_texCoord(tc);
        newalien->init();

        newbox->set_vposition(vpos);
        newbox->set_vcolor(vcol);
        newbox->set_vnormal(vnorm);
        newbox->set_vModelviewmatrix(umodel);
        newbox->set_viewMatrix(viewmat);
        newbox->set_normalMatrix(normat);
        newbox->set_texCoord(tc);
        newbox->init();

        newroom->set_vposition(vpos);
        newroom->set_vcolor(vcol);
        newroom->set_vnormal(vnorm);
        newroom->set_vModelviewmatrix(umodel);
        newroom->set_viewMatrix(viewmat);
        newroom->set_normalMatrix(normat);
        newroom->set_texCoord(tc);
        newroom->init();
        
        newtable->set_vposition(vpos);
        newtable->set_vcolor(vcol);
        newtable->set_vnormal(vnorm);
        newtable->set_vModelviewmatrix(umodel);
        newtable->set_viewMatrix(viewmat);
        newtable->set_normalMatrix(normat);
        newtable->set_texCoord(tc);
        newtable->init();
        
        bezier_curve->set_vposition(vpos);
        bezier_curve->set_vcolor(vcol);
        bezier_curve->set_vnormal(vnorm);
        bezier_curve->set_vModelviewmatrix(umodel);
        bezier_curve->set_viewMatrix(viewmat);
        bezier_curve->set_normalMatrix(normat);
        bezier_curve->set_texCoord(tc);
        bezier_curve->init();
        
        newchair->set_vposition(vpos);
        newchair->set_vcolor(vcol);
        newchair->set_vnormal(vnorm);
        newchair->set_vModelviewmatrix(umodel);
        newchair->set_viewMatrix(viewmat);
        newchair->set_normalMatrix(normat);
        newchair->set_texCoord(tc);
        newchair->init();
        
        newlamp->set_vposition(vpos);
        newlamp->set_vcolor(vcol);
        newlamp->set_vnormal(vnorm);
        newlamp->set_vModelviewmatrix(umodel);
        newlamp->set_viewMatrix(viewmat);
        newlamp->set_normalMatrix(normat);
        newlamp->set_texCoord(tc);
        newlamp->init();
        
        newstool->set_vposition(vpos);
        newstool->set_vcolor(vcol);
        newstool->set_vnormal(vnorm);
        newstool->set_vModelviewmatrix(umodel);
        newstool->set_viewMatrix(viewmat);
        newstool->set_normalMatrix(normat);
        newstool->set_texCoord(tc);
        newstool->init();
        
        newsofa->set_vposition(vpos);
        newsofa->set_vcolor(vcol);
        newsofa->set_vnormal(vnorm);
        newsofa->set_vModelviewmatrix(umodel);
        newsofa->set_viewMatrix(viewmat);
        newsofa->set_normalMatrix(normat);
        newsofa->set_texCoord(tc);
        newsofa->init();
        
        newcupboard->set_vposition(vpos);
        newcupboard->set_vcolor(vcol);
        newcupboard->set_vnormal(vnorm);
        newcupboard->set_vModelviewmatrix(umodel);
        newcupboard->set_viewMatrix(viewmat);
        newcupboard->set_normalMatrix(normat);
        newcupboard->set_texCoord(tc);
        newcupboard->init();
        
        newwallfixture->set_vposition(vpos);
        newwallfixture->set_vcolor(vcol);
        newwallfixture->set_vnormal(vnorm);
        newwallfixture->set_vModelviewmatrix(umodel);
        newwallfixture->set_viewMatrix(viewmat);
        newwallfixture->set_normalMatrix(normat);
        newwallfixture->set_texCoord(tc);
        newwallfixture->init();
    }

    void model_t::clear_stack() {

        newhuman->matrixStack.clear();
        newalien->matrixStack.clear();
        newbox->matrixStack.clear();
        newroom->matrixStack.clear();
        newtable->matrixStack.clear();
        bezier_curve->matrixStack.clear();
        newchair->matrixStack.clear();
        newlamp->matrixStack.clear();
        newstool->matrixStack.clear();
        newsofa->matrixStack.clear();
        newcupboard->matrixStack.clear();
        newwallfixture->matrixStack.clear();

    }

    void model_t::set_view_mat(glm::mat4 viewmat) {

        newhuman->viewmatrix = viewmat;
        newalien->viewmatrix = viewmat;
        newbox->viewmatrix = viewmat;
        newroom->viewmatrix = viewmat;
        newtable->viewmatrix = viewmat;
        bezier_curve->viewmatrix = viewmat;
        newchair->viewmatrix = viewmat;
        newlamp->viewmatrix = viewmat;
        newstool->viewmatrix = viewmat;
        newsofa->viewmatrix = viewmat;
        newcupboard->viewmatrix = viewmat;
        newwallfixture->viewmatrix = viewmat;

        newhuman->matrixStack.push_back(viewmat);
        newalien->matrixStack.push_back(viewmat);
        newbox->matrixStack.push_back(viewmat);
        newroom->matrixStack.push_back(viewmat);
        newtable->matrixStack.push_back(viewmat);
        bezier_curve->matrixStack.push_back(viewmat);
        newchair->matrixStack.push_back(viewmat);
        newlamp->matrixStack.push_back(viewmat);
        newstool->matrixStack.push_back(viewmat);
        newsofa->matrixStack.push_back(viewmat);
        newcupboard->matrixStack.push_back(viewmat);
        newwallfixture->matrixStack.push_back(viewmat);
        
        view_matrix = viewmat ;
    }

    void model_t::render() {
                
        if (curr_mode == animate_mode::play && curr_eye_pos == last_eyeframe ){
            set_pose() ;
        }
        glUseProgram(shaderprogram1);
        newhuman->hrender();
        newalien->hrender();
        newbox->hrender();
        newroom->hrender();
        newtable->hrender();
        newchair->hrender() ;
        newlamp->hrender() ;
        newstool->hrender() ;
        newsofa->hrender() ;
        newcupboard->hrender() ;
        newwallfixture->hrender() ;
        
        if (!start_eye){
            bezier_curve->render_cursor();
            glUseProgram(shaderprogram2) ;
            bezier_curve->render_curve(shaderprogram2 , view_matrix ) ;
        }else{
            if (curr_eye_pos < last_eyeframe -  1) {
                save() ;
                framenum++ ;
            }
                    
            else if (curr_eye_pos == last_eyeframe){
                double time = glfwGetTime();
                if (std::abs(time - 1.0 / fps) > 0.000001){
                    save() ;
                    framenum++ ;
                    glfwSetTime(0.0) ;
                }
                
            }
                
            
        }
    }
    
    void model_t::add_point(){
        
        bezier_curve->add_point();
        
    }
    
    void model_t::remove_point(){
        
        bezier_curve->remove_point() ;
        
    }
    
    glm::vec4 model_t::get_camera_pos() {
//        std::cout << curr_eye_pos << std::endl ;
        if ((!start_eye) || (bezier_curve->get_points() == NULL))
            //start_eye = false ;
            return glm::vec4(100, 10 , 100 , 1) ;
            //return glm::vec4(15,15 , 15 , 1) ;
        double time = glfwGetTime();
        if (std::abs(time - 1.0 / fps) > 0.000001){
            curr_eye_pos++ ;
            if (curr_eye_pos > last_eyeframe) curr_eye_pos = last_eyeframe ;
            glfwSetTime(0.0) ;
        }
        return bezier_curve->get_points()[curr_eye_pos] ;
    }

    void model_t::get_keyframe(){
        
        std::vector<float> orientations ;
        newhuman->get_position(orientations) ;
        newhuman->get_all_poses(orientations) ;
        newalien->get_position(orientations) ;
        newalien->get_all_poses(orientations) ;
        newbox->get_position(orientations) ;
        newbox->get_all_poses(orientations) ;
        
        std::ofstream myfile;
        myfile.open ("keyframe.txt" ,std::fstream::app);
        for (int i = 0 ; i < orientations.size() ; i++)
            myfile << orientations[i] << " " ;
        myfile << "\n" ;
        myfile.close();
        
    }
    
    void model_t::read_keyframes() {
        
        std::ifstream myfile;
        myfile.open ("keyframe.txt");
        std::vector<float> orientations ;
        std::string line;
        float a ;
        while(std::getline(myfile , line)){
            std::istringstream iss(line);
            while (!iss.eof()){
                iss >> a;
                orientations.push_back(a);
            }
            orientations.pop_back() ;
            keyframes.push_back(orientations) ;
            orientations.clear() ;
        }
        
        
    }
    
    void model_t::set_pose(){
        if (std::abs(curr_k - 1.0) < 0.000001){
            curr_k = 0.0 ;
            curr_keyframe++ ;
        }
        std::vector<float> outframe ;
        if (curr_keyframe >= keyframes.size()) return ;
        if (curr_keyframe >= keyframes.size() - 1) {
            outframe = keyframes[keyframes.size() - 1] ;
        }else{
            interpolate_keyframes(keyframes[curr_keyframe] , keyframes[curr_keyframe + 1]
                , curr_k , outframe) ;
        }
        curr_k = curr_k + delta_k ;
        
        std::reverse(outframe.begin() , outframe.end()) ;
        
        newhuman->set_position(outframe) ;
        newhuman->set_all_poses(outframe) ;
        newalien->set_position(outframe) ;
        newalien->set_all_poses(outframe) ;
        newbox->set_position(outframe) ;
        newbox->set_all_poses(outframe) ;
        
        outframe.clear() ;
        
    }
    
    void model_t::interpolate_keyframes(std::vector<float> &key1 
        , std::vector<float> &key2 , float k , std::vector<float> &outframe){
        
        float key = 0.0 ;
        for (int i = 0 ; i < key1.size() ; i++){
            key = (1 - k) * key1[i] + k * key2[i] ;
            if (std::abs( key1[i] -  key2[i]) < 0.00001)
                key = key1[i] ;
            outframe.push_back(key) ;
        }
        
    }

    int model_t::save() {
        int num_bytes_written = 0;
        char drwfilename [100];
        std::snprintf (drwfilename, sizeof drwfilename, "data/default_%05d.tga", framenum);

        unsigned int totalN = 3 * 1024 * 750 ;
        unsigned char* ustore = new unsigned char[3 * 1024 * 750];
        unsigned char* ustore2 = new unsigned char[3 * 1024 * 750];
        glReadPixels(0, 0, 1024, 750, GL_RGB, GL_UNSIGNED_BYTE, ustore);
        
        unsigned int uind = 0 ;
        for (int i =0 ; i < 1024 * 750 ; i++){
                ustore2[uind++] = ustore[totalN - 3 * i - 3] ;
                ustore2[uind++] = ustore[totalN - 3 * i - 2] ;
                ustore2[uind++] = ustore[totalN - 3 * i - 1] ;
            }
        
        num_bytes_written = stbi_write_tga(drwfilename, 1024, 750, 3, (void*) ustore2);

        
        if (ustore != NULL)
            delete[] ustore;
        if (ustore2 != NULL)
            delete[] ustore2;

        return num_bytes_written;
    }
    
            
}