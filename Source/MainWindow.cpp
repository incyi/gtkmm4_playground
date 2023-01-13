/**
 * MainWindow.cpp
 * 
 */

#include <iostream>

#include "MainWindow.h"
#include "Version.h"

MainWindow::MainWindow()
:
 m_about_button("About"),
 m_exit_button("Exit")
{
  set_title("Gtkmm Playground ! Made with gtkmm3 and C++");
  set_default_size(480, 360);
  // sets the border width of the window.
  set_border_width(10);

  m_grid.add(m_about_button);
  m_grid.add(m_exit_button);
  add(m_grid);

  // Show the widgets.
  show_all_children();

  // Now when the button is clicked, we call the "on_exit_button_clicked" function.
  m_exit_button.signal_clicked().connect(sigc::mem_fun(*this,
    &MainWindow::on_exit_button_clicked) );

  // Now when the button is clicked, we call the "on_about_button_clicked" function.
  m_about_button.signal_clicked().connect(sigc::mem_fun(*this,
    &MainWindow::on_about_button_clicked) );

  /** About dialog */
  m_Dialog.set_transient_for(*this);
  m_Dialog.set_program_name("Gtkmm4 Playground");
  m_Dialog.set_version(VERSION_STRING);
  m_Dialog.set_copyright("Inanc Yigit");
  m_Dialog.set_comments("Made with C++ and gtkmm3.");
  m_Dialog.set_license("LGPL");
  m_Dialog.set_website("https://github.com/incyi/gtkmm4_playground");
  m_Dialog.set_website_label("Github Repository");

  std::vector<Glib::ustring> list_authors;
  list_authors.push_back("Inanc Yigit");
  m_Dialog.set_authors(list_authors);

  m_Dialog.signal_response().connect(
  sigc::mem_fun(*this, &MainWindow::on_about_dialog_response) );
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_about_dialog_response(int response_id)
{
  switch (response_id)
  {
  case Gtk::RESPONSE_CLOSE:
  case Gtk::RESPONSE_CANCEL:
  case Gtk::RESPONSE_DELETE_EVENT:
    m_Dialog.hide();
    break;
  default:
    break;
  }
}

void MainWindow::on_about_button_clicked()
{
  m_Dialog.show();

  //Bring it to the front, in case it was already shown:
  m_Dialog.present();
}

void MainWindow::on_exit_button_clicked()
{
  hide(); //to close the application.
}