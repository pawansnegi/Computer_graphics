#version 400  // for mac
//#version 440  // for ubuntu

in vec4 vPosition;
in vec4 vColor;
in vec3 vNormal;
in vec2 texCoord;

out vec3 normal;
out vec4 eye;
out vec4 COLOR;
out vec2 tex;

out vec4 v;

uniform mat4 uModelViewMatrix;
uniform mat3 normalMatrix;
uniform mat4 viewMatrix;
void main (void) 
{
  v = uModelViewMatrix * vPosition; 
  gl_Position = uModelViewMatrix * vPosition;
  normal = (normalMatrix * normalize(vNormal)); 
  eye = - gl_Position; 
  COLOR = vColor; 
  tex = texCoord;
 }
