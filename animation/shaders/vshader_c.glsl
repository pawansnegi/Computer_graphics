#version 400  // for mac
//#version 440  // for ubuntu

in vec4 vPosition;

out vec4 COLOR ;

uniform mat4 uModelViewMatrix;

void main (void) 
{
  gl_Position = uModelViewMatrix * vPosition;
  COLOR = vec4(1.0,1.0,1.0,1.0) ;
 }
