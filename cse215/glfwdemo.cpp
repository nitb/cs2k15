#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

int main(){
  if ( !glfwInit() )
  {
    fprintf(stderr, "Failed to initialize GLFW \n");
    return -1;
  }
  glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Use OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //For MAC
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Dont use old OpenGL

  // Open a window and create its OpenGL context
  GLFWwindow* window;
  window = glfwCreateWindow (1024, 768, "Hey", NULL, NULL);
  if ( window==NULL )
  {
    fprintf(stderr, "Failed to open GLFW window. You might have INTEL GPU. The version 3.3 of OpenGL is not compatible. Use OpenGL 2.0 instead.");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window); //Initialize GLEW
  glewExperimental = true;
  if ( glewInit() != GLEW_OK ){
    fprintf(stderr, "Failed to initialize GLEW \n");
    return -1;
  }
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

do{
    // Draw nothing, see you in tutorial 2 !

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

} // Check if the ESC key was pressed or the window was closed
while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
glfwWindowShouldClose(window) == 0 );
}
