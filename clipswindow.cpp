#include "clipswindow.h"
//#include "GtkClips.h"
#include <iostream>


ClipsWindow::ClipsWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade) :
Gtk::Window(cobject), builder(refGlade){

	    agenda_btn = NULL;
		fact_btn = NULL;
		reset_btn = NULL;
		run_btn = NULL;
		load_item = NULL;
		change_strategy_item = NULL;
		save_item = NULL;
    // main window.
	builder->get_widget("main_window", main_window);
	// Control window btn
	builder->get_widget("agendabtn", agenda_btn);
	builder->get_widget("FactBtn", fact_btn);
	builder->get_widget("ResetBtn", reset_btn);
	builder->get_widget("RunBtn", run_btn);

	//MenuButtons
	// builder->get_widget("OptionItem", options);
	// builder->get_widget("HelpItem", help);

	//MenuItems
	builder->get_widget("LoadOption", load_item);
	builder->get_widget("StrategyOption", change_strategy_item);
	builder->get_widget("SaveOption", save_item);



	main_window->set_title("CLIPSWinv1.0.0");
	//main_window->set_size(400,400);


   // signal connections.
	agenda_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_agendabtn_clicked));
	// using "this" pointer indicates the use of own class object.
	fact_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_factbtn_clicked));
	reset_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_resetbtn_clicked));
    run_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_runbtn_clicked));






}


ClipsWindow:: ~ClipsWindow() {
  /* TODO */
}


void ClipsWindow:: on_agendabtn_clicked() {
   std::cout << "Agenda Button clicked" << std::endl;
}

void ClipsWindow::on_factbtn_clicked() {
	std::cout << "Fact Button clicked" << std::endl;
}

void ClipsWindow::on_resetbtn_clicked(){
	std::cout << "Fact Button clicked" << std::endl;
}

void ClipsWindow::on_runbtn_clicked(){
	std::cout << "Run button clicked" << std::endl;
}
