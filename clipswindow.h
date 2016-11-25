#ifndef _CLIPSWINDOW_H
#define _CLIPSWINDOW_H 
#include <gtkmm.h>


class ClipsWindow : public Gtk::Window
{
public:
	ClipsWindow(BaseObjectType * cobject, const Glib::RefPtr<Gtk::Builder> &refGlade);
	~ClipsWindow();


protected:
	Glib::RefPtr<Gtk::Builder> builder;
	//MainWindow
    Gtk::Window *main_window;
	// Control buttons.
    Gtk::Button *agenda_btn; // buttons to contain the control buttons in the GUI.
    Gtk::Button *fact_btn;
    Gtk::Button *run_btn;
    Gtk::Button *reset_btn;
    // Menu options.
    //Gtk::MenuButton *options; // Get the options menu
    Gtk::MenuItem *load_item; // Menu items for the "Options menu"
    Gtk::MenuItem *save_item;
    Gtk::MenuItem *change_strategy_item;
    //Gtk::MenuButton *help;
    Gtk::MenuItem *about_item; // Menu item for the "Help Menu"

    // signal handlers for buttons. 
	void on_agendabtn_clicked();
	void on_factbtn_clicked();
	void on_runbtn_clicked();
	void on_resetbtn_clicked();

	// signal handlers for menu items.
	void on_load_activate();
	void on_StrategyOption_activate();
	void on_SaveOption_activate();
	void AboutItem_activate_cb(); 
};







#endif