/**
 * MainWindow.cpp
 * 
 */

#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow()
: m_exit_button("Exit")
{
  set_title("Hello World ! Made with gtkmm3 and C++");
  set_default_size(400, 300);
  // sets the border width of the window.
  set_border_width(10);
  // put the box into the main window.
  add(m_box1);

  // Now when the button is clicked, we call the "on_exit_button_clicked" function.
  m_exit_button.signal_clicked().connect(sigc::mem_fun(*this,
    &MainWindow::on_exit_button_clicked) );

  // instead of gtk_container_add, we pack this button into the invisible
  // box, which has been packed into the window.
  // note that the pack_start default arguments are Gtk::EXPAND | Gtk::FILL, 0
  m_box1.pack_start(m_exit_button);
  // Show the widgets.
  // They will not really be shown until this Window is shown.
  m_exit_button.show();
  m_box1.show();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_exit_button_clicked()
{
  hide(); //to close the application.
}