#version 400

in vec3 normal;
in vec4 eye;
in vec4 COLOR;
in vec2 tex;

in vec4 v;

uniform sampler2D texture1;
uniform mat4 viewMatrix;

out vec4 frag_color;

void main () 
{
  // Defining Materials
  float shininess = 100.0;
  float spec = 0.0; 
  float diffuse = 0.0 ;

  // Defining Light 
  vec4 lightPos = vec4(-11.0, 4.0, 0.0, 1.0) ;
  vec4 lightPos2 = vec4(15.0 ,-4 ,-15.0, 1.0);

  vec3 lightDir = vec3(viewMatrix * lightPos - v);  // Transforms with camera
  lightDir = normalize( vec3(lightDir)); 

  vec3 lightDir2 = vec3(viewMatrix * lightPos2 - v);  // Transforms with camera
  lightDir2 = normalize( vec3(lightDir2)); 

  //Diffuse
  vec3 n = normalize(vec3(normal));	     
  float dotProduct = dot(n, lightDir);
  diffuse =  max( dotProduct, 0);

  float dotProduct2 = dot(n, lightDir2);
  diffuse =  diffuse + max( dotProduct2, 0.0);


  // Compute specular component only if light falls on vertex
  if(diffuse > 0.0)
  {
	vec3 e = normalize(vec3(eye));
	vec3 h = normalize(lightDir + e );
   	float intSpec = max(dot(h,n), 0.0);	
        spec = pow(intSpec, 7);

        h = normalize(lightDir2 + e );
   	float intSpec2 = max(dot(h,n), 0.0);	
        spec = spec + pow(intSpec2, 3);
  }  
  
  
  vec4 color1 = texture(texture1, tex);
  vec4 color = max((diffuse + spec), 0) * color1; // All
  frag_color = color;

}
