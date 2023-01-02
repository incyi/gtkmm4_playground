/**
 * MainWindow.cpp
 * 
 */

#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow()
: m_exit_button("exit")
{
  set_title("Hello World ! Made with gtkmm3 and C++");
  set_default_size(400, 300);
  set_border_width(10);

  m_exit_button.signal_clicked().connect(sigc::mem_fun(*this,
    &MainWindow::on_exit_button_clicked) );

  add(m_exit_button);

  show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_exit_button_clicked()
{
  hide(); //to close the application.
}