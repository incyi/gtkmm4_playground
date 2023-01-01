/**
 * Main.cpp
 * 
 * https://github.com/incyi/gtkmm4_playground
 */

#include <gtkmm.h>

int main(int argc, char** argv)
{
  auto app = Gtk::Application::create(argc, argv);
  Gtk::Window window;
  window.set_default_size(400, 300);
  
  return app->run(window);
}