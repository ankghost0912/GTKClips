#include "clipswindow.h"
#include "GtkClips.h"
#include <iostream>


ClipsWindow::ClipsWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade) :
Gtk::Window(cobject), builder(refGlade){

	    agenda_btn = NULL;
		fact_btn = NULL;
		reset_btn = NULL;
		run_btn = NULL;
	    //load_file_btn = NULL;
	    // strategy_btn = NULL;
		

		//about_item = NULL;
    // main window.
	builder->get_widget("main_window", main_window);
	// Control window btn
	builder->get_widget("agendabtn", agenda_btn);
	builder->get_widget("Factbtn", fact_btn);
	builder->get_widget("Resetbtn", reset_btn);
	builder->get_widget("Runbtn", run_btn);
    builder->get_widget("LoadFileBtn",load_file_btn);
    builder->get_widget("StrategyBtn", strategy_btn);
	//MenuButtons
	// builder->get_widget("OptionItem", options);
	// builder->get_widget("HelpItem", help);

	//MenuItems
	
	main_window->set_title("CLIPSWinv1.0.0");
	//main_window->set_size(400,400);


   // signal connections.
	agenda_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_agendabtn_clicked));
	// using "this" pointer indicates the use of own class object.
	fact_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_factbtn_clicked));
	reset_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_resetbtn_clicked));
    run_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_runbtn_clicked));
    //about_item->signal_activate().connect(sigc::mem_fun(*this, &ClipsWindow::AboutItem_activate_cb));
     load_file_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_LoadFileBtn_clicked));
     strategy_btn->signal_clicked().connect(sigc::mem_fun(*this, &ClipsWindow::on_StrategyBtn_clicked));




}


ClipsWindow:: ~ClipsWindow() {
  /* TODO */
	delete main_window;
	// delete strategy_btn;
}


void ClipsWindow:: on_agendabtn_clicked() {
   std::cout << "Agenda Button clicked" << std::endl;
}

void ClipsWindow::on_factbtn_clicked() {
	std::cout << "Fact Button clicked" << std::endl;
}

void ClipsWindow::on_resetbtn_clicked(){
	std::cout << "Reset Button clicked" << std::endl;
}

void ClipsWindow::on_runbtn_clicked(){
	std::cout << "Run button clicked" << std::endl;
}


void ClipsWindow::on_LoadFileBtn_clicked() {
	std::cout << "Load Button clicked" << std::endl;
}

void ClipsWindow::on_StrategyBtn_clicked() {
	std::cout << "Change Strategy Button clicked" << std::endl;
}
       

