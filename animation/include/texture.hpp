#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

namespace csX75 {
    GLuint LoadTexture(const char * filename, int width, int height);
    void FreeTexture(GLuint texture);
}
#endif 
