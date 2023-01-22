/**
 * MainWindow.cpp
 *
 */

#include <iostream>
#include <string>

#include "MainWindow.h"
#include "Version.h"

MainWindow::MainWindow() {
    set_title("Gtkmm Playground ! Made with gtkmm3 and C++");
    set_default_size(480, 360);
    // Sets the border width of the window.
    set_border_width(10);

    // Create the menu bar and its items
    m_menu_file.set_label("File");
    m_menu_file_new.set_label("Status");
    m_menu_file_quit.set_label("Quit");
    m_menu_help.set_label("Help");
    m_menu_help_about.set_label("About");

    // Add the items to the "File" and "Help" menu
    m_menu_file_items.append(m_menu_file_new);
    m_menu_file_items.append(m_menu_file_quit);
    m_menu_help_items.append(m_menu_help_about);

    // Add the "File" and "Help" menu to the menu bar
    m_menu_file.set_submenu(m_menu_file_items);
    m_menu_help.set_submenu(m_menu_help_items);
    m_menubar.append(m_menu_file);
    m_menubar.append(m_menu_help);

    // Connect the menu items' signals to their corresponding slots
    m_menu_file_new.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_status_clicked));
    m_menu_file_quit.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_exit_clicked));
    m_menu_help_about.signal_activate().connect(sigc::mem_fun(*this, &MainWindow::on_about_clicked) );

    // Create the labels
    m_label1.set_text("Label 1");
    m_label2.set_text("Label 2");
    m_label3.set_text("Label 3");
    m_label4.set_text("Label 4");
    m_label5.set_text("Label 5");

    // Add the labels to the label box
    m_label_box.pack_start(m_label1, true, true, 5);
    m_label_box.pack_start(m_label2, true, true, 5);
    m_label_box.pack_start(m_label3, true, true, 5);
    m_label_box.pack_start(m_label4, true, true, 5);
    m_label_box.pack_start(m_label5, true, true, 5);

    // Add the menu bar, label box to the main grid and show everything
    m_grid.attach(m_menubar, 0, 0, 1, 1);
    m_grid.attach(m_label_box, 0, 1, 1, 1);
    add(m_grid);
    show_all();
}

MainWindow::~MainWindow() {
}

void MainWindow::on_about_dialog_response(int response_id) {
    switch (response_id) {
    case Gtk::RESPONSE_CLOSE:
    case Gtk::RESPONSE_CANCEL:
    case Gtk::RESPONSE_DELETE_EVENT:
        m_Dialog.hide();
        break;
    default:
        break;
    }
}

void MainWindow::on_about_clicked() {
    char comment[80];

    m_Dialog.set_transient_for(*this);
    m_Dialog.set_program_name("Gtkmm4 Playground");
    m_Dialog.set_version(VERSION_STRING);
    m_Dialog.set_copyright("Inanc Yigit");
    sprintf(comment, "Written in C++ and uses gtkmm3.\nBuild by: %s, on: %s, with G++: %s.", BUILD_USER, BUILD_MACHINE, BUILD_GCC_VERSION);
    m_Dialog.set_comments(comment);
    m_Dialog.set_license("LGPL");
    m_Dialog.set_website("https://github.com/incyi/gtkmm4_playground");
    m_Dialog.set_website_label("Github Repository");

    /**
    * Alternative for compiler version:
    * std::string(__VERSION__)
    */

    std::vector<Glib::ustring> list_authors;
    list_authors.push_back("Inanc Yigit");
    m_Dialog.set_authors(list_authors);
    m_Dialog.signal_response().connect(sigc::mem_fun(*this, &MainWindow::on_about_dialog_response) );
    m_Dialog.show();

    //Bring it to the front, in case it was already shown:
    m_Dialog.present();
}

void MainWindow::on_exit_clicked() {
    hide(); //to close the application.
}

void MainWindow::on_status_clicked() {
    std::string os_version = "Undefined";

#ifdef _WIN32
    // std::system("ver");
#else
    // std::system("uname -a");
#endif

    Gtk::MessageDialog dialog(*this, "...text will be shown here... ", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);

    // Gtk::MessageDialog dialog(*this, "OS version: " + os_version + "\n", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);

    dialog.run();
}
