/**
 * MainWindow.h
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/grid.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menu.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/aboutdialog.h>

class MainWindow : public Gtk::Window {
  public:
    MainWindow();
    virtual ~MainWindow();

  protected:
    //Signal handlers:
    void on_about_clicked();
    void on_exit_clicked();
    void on_about_dialog_response(int response_id);
    void on_menu_file_new();
    void on_status_clicked();

    //Child widgets:
    Gtk::Grid m_grid;
    Gtk::MenuBar m_menubar;
    Gtk::MenuItem m_menu_file;
    Gtk::MenuItem m_menu_help;
    Gtk::Menu m_menu_file_items;
    Gtk::Menu m_menu_help_items;
    Gtk::MenuItem m_menu_file_new;
    Gtk::MenuItem m_menu_file_quit;
    Gtk::MenuItem m_menu_help_about;
    Gtk::AboutDialog m_Dialog;
    Gtk::Box m_label_box;
    Gtk::Label m_label1;
    Gtk::Label m_label2;
    Gtk::Label m_label3;
    Gtk::Label m_label4;
    Gtk::Label m_label5;

};

#endif //MAINWINDOW_H
