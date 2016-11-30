#ifndef _CLIPSWINDOW_H
#define _CLIPSWINDOW_H 
#include <gtkmm.h>


class ClipsWindow : public Gtk::Window
{
public:
	ClipsWindow(BaseObjectType * cobject, const Glib::RefPtr<Gtk::Builder> &refGlade);
	virtual ~ClipsWindow();


protected:
	Glib::RefPtr<Gtk::Builder> builder;
	//MainWindow
    Gtk::Window *main_window;
	// Control buttons.
    Gtk::Button *agenda_btn; // buttons to contain the control buttons in the GUI.
    Gtk::Button *fact_btn;
    Gtk::Button *run_btn;
    Gtk::Button *reset_btn;
    Gtk::Button *load_file_btn;
    Gtk::Button *strategy_btn;
   

    // signal handlers for buttons. 
	void on_agendabtn_clicked();
	void on_factbtn_clicked();
	void on_runbtn_clicked();
	void on_resetbtn_clicked();
    void on_LoadFileBtn_clicked();
    void on_StrategyBtn_clicked();
};







#endif