#ifndef _HUMAN_HPP_
#define _HUMAN_HPP_

#include "glm/vec4.hpp"
#include"hierarchy_node.hpp"
#include "primitive.hpp"
#include "glm/vec3.hpp"

namespace csX75{
    
    enum class obj_type{
        human=1 , alien , box
    };
    
    enum class limb_t {
        hip=1 , torso , larm , rarm , lleg , rleg , head
        ,llarm , rlarm , llleg , rlleg , rhand , lhand
        , rfeet , lfeet
    };
    
    class object_t{
    private:
        GLuint vPosition, vColor, uModelViewMatrix;
        
    public:
        std::vector<glm::mat4> matrixStack;
        
        void set_vposition(GLuint vpos ) {vPosition = vpos;} ;
        void set_vcolor(GLuint vcolor ) {vColor = vcolor;} ;
        void set_vModelviewmatrix(GLuint mvmat ) {uModelViewMatrix = mvmat;} ;
        
        GLuint get_vposition() {return vPosition;} ;
        GLuint get_vcolor() {return vColor;} ;
        GLuint get_vModelviewmatrix() {return uModelViewMatrix;} ;
    };
    
    class human_t:public object_t{
    private:
        glm::vec4 hip_color;
        glm::vec4 torso_color ;
        glm::vec4 larm_color ;
        glm::vec4 rarm_color ;
        glm::vec4 lleg_color ;
        glm::vec4 rleg_color ;
        glm::vec4 head_color ;
        glm::vec4 llarm_color ;
        glm::vec4 rlarm_color ;
        glm::vec4 llleg_color ;
        glm::vec4 rlleg_color ;
        glm::vec4 lfeet_color ;
        glm::vec4 rfeet_color ;
        glm::vec4 lhand_color ;
        glm::vec4 rhand_color ;
        glm::vec4 neck_color ;
        glm::vec4 rstick_color;
        glm::vec4 lstick_color;
        
        shape *hip_data ;
        shape *torso_data ;
        shape *larm_data ;
        shape *rarm_data ;
        shape *lleg_data ;
        shape *rleg_data ;
        shape *head_data ;
        shape *llarm_data ;
        shape *rlarm_data ;
        shape *llleg_data ;
        shape *rlleg_data ;
        shape *lfeet_data ;
        shape *rfeet_data ;
        shape *lhand_data ;
        shape *rhand_data ;
        shape *neck_data ;
        shape *rstick_data ;
        shape *lstick_data ;
        
        HNode *hip ;
        HNode *torso ;
        HNode *larm ;
        HNode *rarm ;
        HNode *lleg ;
        HNode *rleg ;
        HNode *head ;
        HNode *llarm ;
        HNode *rlarm ;
        HNode *llleg ;
        HNode *rlleg ;
        HNode *lfeet ;
        HNode *rfeet ;
        HNode *lhand ;
        HNode *rhand ;
        HNode *neck ;
        HNode *rstick ;
        HNode *lstick ;
        
        limb_t current_limb ;
        
        void make_human() ;
        void set_constraints() ;
        void make_pose() ;
        
    public:
        human_t() {} ;
        ~human_t() {};
        
        void init() ;
        
        void set_curr_limb(limb_t a) {current_limb = a;} ;
        limb_t get_curr_limb() {return current_limb;};
        
        void rotate_x_cc() ;
        void rotate_y_cc() ;
        void rotate_z_cc() ;
        
        void rotate_x_ccw() ;
        void rotate_y_ccw() ;
        void rotate_z_ccw() ;
        
        void trans_y_inc() ;
        void trans_y_dec() ;
        
        void hrender() {hip->render_tree(this) ;}
    };
        
}

#endif