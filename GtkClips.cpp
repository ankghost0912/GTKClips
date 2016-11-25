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

void GtkClips::GetAgenda(void *theEnv, void *Printout, void *moduleName) {



}

void GtkClips::Save(const char *filename) {
	EnvSave(theEnv, filename);
}

void GtkClips::Run() {
	EnvRun(theEnv);
}