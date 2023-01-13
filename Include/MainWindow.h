/**
 * MainWindow.h
 * 
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/aboutdialog.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_about_button_clicked();
  void on_exit_button_clicked();
  void on_about_dialog_response(int response_id);

  //Child widgets:
  Gtk::Grid m_grid;
  Gtk::Button m_about_button;
  Gtk::Button m_exit_button;
  Gtk::AboutDialog m_Dialog;
};

#endif //MAINWINDOW_H
