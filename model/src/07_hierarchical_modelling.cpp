/*
  CSX75 Tutorial 3

  Use the arrow keys and PgUp,PgDn, 
  keys to make the arms move.

  Use the keys 1,2 and 3 to switch between arms.

  Modified from An Introduction to OpenGL Programming, 
  Ed Angel and Dave Shreiner, SIGGRAPH 2013

  Written by - 
               Harshavardhan Kode
 */


#include "07_hierarchical_modelling.hpp"

GLuint shaderProgram;

glm::mat4 projection_matrix;
glm::mat4 c_rotation_matrix;
glm::mat4 lookat_matrix;

glm::mat4 view_matrix;


void initBuffersGL(csX75::model_t *mymodel) {

    // Load shaders and use the resulting shader program
    std::string vertex_shader_file("shaders/vshader.glsl");
    std::string fragment_shader_file("shaders/fshader.glsl");

    std::vector<GLuint> shaderList;
    shaderList.push_back(csX75::LoadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
    shaderList.push_back(csX75::LoadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

    shaderProgram = csX75::CreateProgramGL(shaderList);
    glUseProgram(shaderProgram);

    // getting the attributes from the shader program
    GLuint vPosition = glGetAttribLocation(shaderProgram, "vPosition");
    GLuint vColor = glGetAttribLocation(shaderProgram, "vColor");
    GLuint uModelViewMatrix = glGetUniformLocation(shaderProgram, "uModelViewMatrix");

    mymodel->newhuman->set_vposition(vPosition) ;
    mymodel->newhuman->set_vcolor(vColor) ;
    mymodel->newhuman->set_vModelviewmatrix(uModelViewMatrix) ;
    mymodel->newhuman->init() ;
    
    mymodel->newalien->set_vposition(vPosition) ;
    mymodel->newalien->set_vcolor(vColor) ;
    mymodel->newalien->set_vModelviewmatrix(uModelViewMatrix) ;
    mymodel->newalien->init() ;
    
    mymodel->newbox->set_vposition(vPosition) ;
    mymodel->newbox->set_vcolor(vColor) ;
    mymodel->newbox->set_vModelviewmatrix(uModelViewMatrix) ;
    mymodel->newbox->init() ;
}

void renderGL(csX75::model_t *mymodel) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mymodel->newhuman->matrixStack.clear();
    mymodel->newalien->matrixStack.clear();
    mymodel->newbox->matrixStack.clear();
    
    //Creating the lookat and the up vectors for the camera
    c_rotation_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(c_xrot), glm::vec3(1.0f, 0.0f, 0.0f));
    c_rotation_matrix = glm::rotate(c_rotation_matrix, glm::radians(c_yrot), glm::vec3(0.0f, 1.0f, 0.0f));
    c_rotation_matrix = glm::rotate(c_rotation_matrix, glm::radians(c_zrot), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::vec4 c_pos = glm::vec4(c_xpos, c_ypos, c_zpos, 1.0) * c_rotation_matrix;
    glm::vec4 c_up = glm::vec4(c_up_x, c_up_y, c_up_z, 1.0) * c_rotation_matrix;
    //Creating the lookat matrix
    lookat_matrix = glm::lookAt(glm::vec3(c_pos), glm::vec3(0.0), glm::vec3(c_up));

    //creating the projection matrix
    if (enable_perspective)
        projection_matrix = glm::frustum(-20.0, 20.0, -20.0, 20.0, 1.0, 2.0);
    else
        projection_matrix = glm::ortho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);

    view_matrix = projection_matrix*lookat_matrix;

    mymodel->newhuman->matrixStack.push_back(view_matrix);
    mymodel->newalien->matrixStack.push_back(view_matrix);
    mymodel->newbox->matrixStack.push_back(view_matrix);
    
    mymodel->newhuman->hrender() ;
    mymodel->newalien->hrender() ;
    mymodel->newbox->hrender() ;

}

int main(int argc, char** argv) {
    //! The pointer to the GLFW window
    GLFWwindow* window;

    //! Setting up the GLFW Error callback
    glfwSetErrorCallback(csX75::error_callback);

    //! Initialize GLFW
    if (!glfwInit())
        return -1;

    //We want OpenGL 4.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    //This is for MacOSX - can be omitted otherwise
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //We don't want the old OpenGL 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //! Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1024, 1024, "Hierarchical Modelling", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //! Make the window's context current 
    glfwMakeContextCurrent(window);

    //Initialize GLEW
    //Turn this on to get Shader based OpenGL
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        //Problem: glewInit failed, something is seriously wrong.
        std::cerr << "GLEW Init Failed : %s" << std::endl;
    }

    //Print and see what context got enabled
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    //Keyboard Callback
    glfwSetKeyCallback(window, csX75::key_callback);
    //Framebuffer resize callback
    glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    csX75::model_t *mymodel = new csX75::model_t() ;
    mymodel->newhuman = new csX75::human_t() ;
    mymodel->newalien = new csX75::alien_t() ;
    mymodel->newbox = new csX75::box_t() ;
    
    //Initialize GL state
    csX75::initGL();
    initBuffersGL(mymodel);

    mymodel->objtype = csX75::obj_type::human ;
    glfwSetWindowUserPointer(window, (void *)mymodel);
    // Loop until the user closes the window
    while (glfwWindowShouldClose(window) == 0) {

        // Render here
        renderGL(mymodel);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

//-------------------------------------------------------------------------

