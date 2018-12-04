#version 400  // for mac
//#version 440  // for ubuntu

in vec4 vPosition;
in vec4 vColor;
out vec4 color;
uniform mat4 uModelViewMatrix;

void main (void) 
{
  gl_Position = uModelViewMatrix * vPosition;
  color = vColor;
}
