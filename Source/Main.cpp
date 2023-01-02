/**
 * Main.cpp
 * 
 * https://github.com/incyi/gtkmm4_playground
 */

#include <gtkmm.h>

#include "MainWindow.h"

int main(int argc, char** argv)
{
  int status;
  auto app = Gtk::Application::create("io.github.incyi.gtkmm4_playground");
  MainWindow mainwindow;
  
  //Shows the window and returns when it is closed.
  status = app->run(mainwindow);
  return status;
}
