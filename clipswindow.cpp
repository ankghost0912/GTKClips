#include "clipswindow.h"
//#include "GtkClips.h"
#include <iostream>
#include <fstream>


ClipsWindow::ClipsWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade) :
Gtk::Window(cobject), builder(refGlade){

	    agenda_btn = NULL;
		fact_btn = NULL;
		reset_btn = NULL;
		run_btn = NULL;
		//display = NULL;
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
    builder->get_widget("display_area",display);
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

     //GtkClips clipsobj;


}


ClipsWindow:: ~ClipsWindow() {
  
	delete main_window;
	// delete strategy_btn;
}


void ClipsWindow:: on_agendabtn_clicked() {
	Gtk::MessageDialog dialog(*this, "This box displays agenda");

	dialog.run();  
}

void ClipsWindow::on_factbtn_clicked() {
	Gtk::MessageDialog dialog(*this, "This box displays facts");
	dialog.run();  
	//std::cout << "Fact Button clicked" << std::endl;
}

void ClipsWindow::on_resetbtn_clicked(){
	Gtk::MessageDialog dialog(*this, "Running the code now");
	dialog.run();
	//clipsobj.Run();
	//std::cout << "Reset Button clicked" << std::endl;
}

void ClipsWindow::on_runbtn_clicked(){

	std::cout << "Run button clicked" << std::endl;
}


void ClipsWindow::on_LoadFileBtn_clicked() {
	 std::string filename;
	 
     Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
     dialog.set_transient_for(*this);

     // response buttons
     dialog.add_button("_Open", Gtk::RESPONSE_OK);
     dialog.add_button("_Cancel",Gtk::RESPONSE_CANCEL);

    Glib::RefPtr<Gtk::FileFilter> filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    int result = dialog.run();

    switch(result) {
    	case (Gtk::RESPONSE_OK): {
    		std::string line;
    		std::cout << "File opened"<<std::endl;
    		
    		filename = dialog.get_filename();
    		std::cout <<"Loading file into CLIPS\n";
    		//clipsobj.Load(filename); // load the file into CLIPS.
    		std::ifstream fs(filename);
    		auto buffer = display->get_buffer();
    		buffer->set_text("");
    		auto insert_at = buffer->begin();

            while(std::getline(fs, line)) {
            	 insert_at = buffer->insert(insert_at, line+"\n");    
            }

           break;

    	}

        case(Gtk::RESPONSE_CANCEL): {
        	std::cout << "cancelled" << std::endl;
        	//dialog.destroy();
        	break;
        }

        default: {
        	std::cout << "Invalid" << std::endl;
        	break;
        }
    }

}

void ClipsWindow::on_StrategyBtn_clicked() {
    // std::string strat;
    // strat = clipsobj.GetStrategy();
    // Gtk::MessageDialog dialog(*this, strat);
    // dialog.run();
	std::cout << "Change Strategy Button clicked" << std::endl;
}
       

