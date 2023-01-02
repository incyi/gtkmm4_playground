/**
 * Main.cpp
 * 
 * https://github.com/incyi/gtkmm4_playground
 */

#include <iostream>
#include <gtkmm/application.h>

#include "MainWindow.h"
#include "Version.h"

int main(int argc, char** argv)
{
  int status;
  Glib::RefPtr<Gtk::Application> app;

  if(argc>=2) {
    printf("Gtkmm4 playground app in C++.\n");
    printf("Version %d.%d.%d\n", MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION);
    printf("\n");
    for(int counter=0;counter<argc;counter++){
      printf("argv[%d]: %s\n",counter,argv[counter]);
    }
  }

  app = Gtk::Application::create("io.github.incyi.gtkmm4_playground");
  MainWindow mainwindow;
  
  //Shows the window and returns when it is closed.
  status = app->run(mainwindow);
  return status;
}
