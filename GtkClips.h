#include "clips.h"
#include <string>




class GtkClips
{
  public:
	GtkClips();
	~GtkClips();

  //Environment functions 
  void ClearEnv() {return EnvClear(theEnv);} // clear the environment.
  bool CheckDynamicConstraintchecking() {return EnvGetDynamicConstraintChecking(theEnv);}
  bool CheckStaticConstraintchecking() {return EnvGetDynamicConstraintChecking(theEnv);}


  // load function
  void Load(const char *); // pass the environment and the filename to be loaded.
  
  // reset function
  void Reset() {return EnvReset(theEnv);}

  // save function
  void Save(const char *);


// debugging functions 
  bool CheckDribbleActive() {return EnvDribbleActive(theEnv);}
  bool CheckWatchitem(const char *item) {return EnvGetWatchItem(theEnv, item);} 


 // TODO: add fact functions
  void GetFactList(void *, void *); // Get fact list.

  // TODO: add rule functions
  std::string GetRuleModule(void *);
  std::string GetRulePPForm(void *rulePtr) {return returnPPString(ptr, EnvGetRulePPForm);}


  //agenda
  void getActivationName(void *ptr) { return EnvGetActivationName(theEnv, ptr);}
  std::string activationPPForm(void *ptr) {return returnPPString(ptr, EnvGetActivationPPForm);}
  std::vector<void *> getActivationList() {return returnList(EnvGetNextActivation);}
  void GetAgenda(void*, void *, void *); // Get the agenda of the current module.
  std::string GetActivationName(void *actPtr) {return EnvGetActivationName(theEnv, actPtr);}
  bool CheckAgendaChanged() {return EnvGetAgendaChanged(theEnv);}
  void SetEnvSalienceEval(std::string);
  std::string GetEnvSalienceEval();

  void SetStrategy(Glib::ustring);
  Glib::ustring GetStrategy();

  void ReorderAgenda(void *); // reorder agenda based on CR strategy. TBD where to fit.

  void Run(); // run function. 


  private: 
   void *theEnv; 
   int maxActivations;
   std::string returnPPString(void *, void (*)(void *, char*, unsigned, void*)); 
   std::string returnPPString(void*, void(*)(void *, void *));
   std::vector<void *> returnList(void* (*)(void *, void *));
   void ActivationCallback(void *); // callback to the function which will be run on each rule fire.




	
};