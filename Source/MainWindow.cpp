/**
 * MainWindow.cpp
 * 
 */

#include "MainWindow.h"

MainWindow::MainWindow()
{
  set_title("Hello World ! Made with gtkmm3 and C++");
  set_default_size(400, 300);

/** Exit button */
  m_exit_button.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_exit_button_clicked) );
  m_exit_button.set_margin(10);
  m_exit_button.set_label("Exit");

  set_child(m_exit_button);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_exit_button_clicked()
{
  hide(); //to close the application.
}
