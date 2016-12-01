#include "GtkClips.h"
#include <iostream>
#include <string>
#include <vector>


GtkClips::GtkClips() 
{
  
   theEnv = CreateEnvironment();
   SetMaxActivations();
   SetEnvSalienceEval("when-defined");
   SetStrategy("depth");
}


GtkClips::~GtkClips() 
{
  /* Remove periodic function via EnvRemovePeriodicFunction */
   DestroyEnvironment(theEnv);

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
	switch(EnvGetSalienceEvaluation(theEnv)) {
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


void GtkClips::GtkLoad(void *theEnv,const char *filename) {
	EnvLoad(theEnv, filename);
}

void GtkClips::GetAgenda(void *theEnv, char *name, void *moduleName) {
 EnvAgenda(theEnv, name, moduleName);
}

void GtkClips::GtkSave(void *theEnv, const char *filename) {
	EnvSave(theEnv, filename);
}
 
void GtkClips::Run() {
  int ruleFired, max_act;
  max_act = -1; //fire till agenda is empty.
	ruleFired = EnvRun(theEnv, max_act);
  std::cout<<"max rules fired" <<ruleFired<<std::endl;
}

void GtkClips::SetStrategy(std::string strategy) {
     int value;
     if(strategy == "depth")
       value = DEPTH_STRATEGY;
     if(strategy == "breadth")
        value = BREADTH_STRATEGY;
      if(strategy == "lex")
        value = LEX_STRATEGY;
      if(strategy == "mea")
        value = MEA_STRATEGY;
      if(strategy == "random")
        value = RANDOM_STRATEGY;
      if(strategy == "simplicity")
        value = SIMPLICITY_STRATEGY;
      if(strategy == "complexity")
        value = COMPLEXITY_STRATEGY;

    EnvSetStrategy(theEnv,value);


}

std::string GtkClips::GetStrategy() {
	std::string strategy;
	switch(EnvGetStrategy(theEnv)) {
		case DEPTH_STRATEGY:
		   strategy = "depth";
		   break;
		case BREADTH_STRATEGY:
		     strategy = "breadth";
		     break;
		case LEX_STRATEGY:
		     strategy = "lex";
		     break;
		case MEA_STRATEGY:
		     strategy = "mea";
		     break;
   case COMPLEXITY_STRATEGY:
          strategy = "complexity";
          break;
    case SIMPLICITY_STRATEGY:
          strategy = "simplicity";
          break;
    case RANDOM_STRATEGY:
          strategy = "random";
          break;
    default: 
          strategy = "depth";
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
	   list.push_back(ptr);
	}
  return list;
}

std::string GtkClips::returnPPString(void * ptr, void(*getPPFunc)(void*, char*, size_t, void *)) {
  size_t buf_size = 200;
  char buffer[buf_size];
  getPPFunc(theEnv, buffer,buf_size-1,ptr);
  return buffer;
}


