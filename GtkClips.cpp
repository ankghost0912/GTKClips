#include "GtkClips.h"
#include <iostream>
#include <string>


GtkClips::GtkClips() 
{
  /* Add Periodicfunction which will be checked via EnvAddPeriodicFunction */
  /* Add function which will be checked after each rule firing via EnvAddRunFunction */
   theEnv = CreateEnvironment();
}


GtkClips::~GtkClips() 
{
  /* Remove periodic function via EnvRemovePeriodicFunction */


}


void GtkClips::SetEnvSalienceEval(std::string type) {
	 int value;
	 if(type == "when-defined")
	 	value = WHEN_DEFINED;
	 if(type == "when-activated")
	 	value = WHEN_ACTIVATED;
	 if(type == "every-cycle")
	 	value = EVERY_CYCLE;
	 EnvSetSalienceEvaluation(theEnv, value);
}

std::string GtkClips::GetEnvSalienceEval() {
	switch(EnvGetSalienceEvaluation) {
		case WHEN_DEFINED:
		 return  "when-defined";
		 break;

	    case WHEN_ACTIVATED:
	      return "when-activated";
	      break;

	    case EVERY_CYCLE:
	       return "every-cycle";
	       break;

	    default:
	      return "undefined";
	}

}


GtkClips::Load(const char *filename) {
	EnvLoad(theEnv, filename);
}

void GtkClips::GetAgenda(void *moduleName) {
  EnvAgenda(theEnv, WDIALOG, moduleName);
}

void GtkClips::Save(const char *filename) {
	EnvSave(theEnv, filename);
}

void GtkClips::Run() {
	EnvRun(theEnv);
}

void GtkClips::SetStrategy(Glib::ustring strategy) {
   
   switch(strategy) {
   	    case "depth":
   	       EnvSetStrategy(theEnv, DEPTH_STRATEGY);
   	       break;
   	    case "breadth":
   	        EnvSetStrategy(theEnv,BREADTH_STRATEGY);
   	        break;
   	    case "lex":
   	         EnvSetStrategy(theEnv, LEX_STRATEGY);
   	         break;
   	    case "mea":
   	         EnvSetStrategy(theEnv, MEA_STRATEGY);
   	         break;
   	    case "complexity":
   	          EnvSetStrategy(theEnv, COMPLEXITY_STRATEGY);
   	          break;
   	    case "simplicity":
   	          EnvSetStrategy(theEnv, SIMPLICITY_STRATEGY);
   	          break;
   	    case "random":
   	          EnvSetStrategy(theEnv, RANDOM_STRATEGY);
   	          break;
   	    default:
   	          EnvSetStrategy(theEnv, DEPTH_STRATEGY);
   	          break;

   }

}

Glib::ustring GtkClips::GetStrategy() {
	Glib::ustring strategy;
	switch(EnvGetStrategy(theEnv)) {
		case DEPTH_STRATEGY:
		   strategy = "depth";
		   break;
		case BREADTH_STRATEGY:
		     strategy = "breadth";
		     break;
		case LEX_STRATEGY:
		     strategy = "lex"
		     break;
		case MEA_STRATEGY:
		     strategy = "mea"
		     break;
   case COMPLEXITY_STRATEGY:
          strategy = "complexity"
          break;
    case SIMPLICITY_STRATEGY:
          strategy = "simplicity"
          break;
    case RANDOM_STRATEGY:
          strategy = "random"
          break;
    default: 
          strategy = "depth"
          break;


	}

return strategy;
}

void GtkClips::ReorderAgenda(void *moduleName) {
	EnvReorderAgenda(theEnv,moduleName);
}


std::vector<void *> GtkClips::returnList(void * (*getNextFunction)(void *, void *)) {
    void *ptr = NULL;
	std::vector<void *> list;

	while(ptr = getNextFunction(theEnv, ptr)) {
	   list.append(ptr);
	}
  return list;
}