/**
 * MainWindow.h
 * 
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_exit_button_clicked();

  //Child widgets:
  Gtk::Button m_exit_button;

private:

};

#endif //MAINWINDOW_H
