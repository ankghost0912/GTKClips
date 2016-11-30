#include "clipswindow.h"
#include <iostream>



int main(int argc, char *argv[])
{
	Gtk::Main kit(argc,argv);
	//auto app = Gtk::Application::create(argc, argv, "clipsgui.clemson.edu");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("clipswindow.glade");


	
	ClipsWindow *cw = 0;
	builder->get_widget_derived("main_window", cw);
    kit.run(*cw);

	// Gtk::Window *window = nullptr;
	// Gtk::Button *activation_btn = nullptr;
	// AgendaController acntrl;
	// builder ->get_widget("main_window", window);
	// builder ->get_widget("agendabtn", activation_btn);
  //
  //   if (activation_btn)
  //   {
  //   	activation_btn->signal_clicked().connect(sigc::ptr_fun(acntrl.on_agendabtn_clicked));
  //   }

	// return app->run(*window);
	return 0;
}
