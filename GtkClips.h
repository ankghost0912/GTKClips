#include "clips.h"
#include <string>
#include <vector>




class GtkClips
{
  public:
	GtkClips();
	~GtkClips();

  void SetMaxActivations() {maxActivations = 1000;}
  int GetMaxActications() {return maxActivations;}

  //Environment functions 
  void ClearEnv() {return EnvClear(theEnv);} // clear the environment.
  bool CheckDynamicConstraintchecking() {return EnvGetDynamicConstraintChecking(theEnv);}
  bool CheckStaticConstraintchecking() {return EnvGetDynamicConstraintChecking(theEnv);}


  // load function
  void GtkLoad(void*, const char *); // pass the environment and the filename to be loaded.
  
  // reset function
  void GtkReset() {return EnvReset(theEnv);}

  // save function
  void GtkSave(void *, const char *);


// debugging functions 
  bool CheckDribbleActive() {return EnvDribbleActive(theEnv);}
  bool CheckWatchitem(const char *item) {return EnvGetWatchItem(theEnv, item);} 


 // TODO: add fact functions
  void GetFactList(void *, void *); // Get fact list.

  // // TODO: add rule functions
  // std::string GetRuleModule(void *);
  // std::string GetRulePPForm(void *rulePtr) {return returnPPString(rulePtr, EnvGetRulePPForm);}


  //agenda
  std::string getActivationName(void *ptr) { return EnvGetActivationName(theEnv, ptr);}
  std::string activationPPForm(void *ptr) {return returnPPString(ptr, EnvGetActivationPPForm);}
  std::vector<void *> getActivationList() {return returnList(EnvGetNextActivation);}
  void GetAgenda(void*, char *, void *); // Get the agenda of the current module.
  std::string GetActivationName(void *actPtr) {return EnvGetActivationName(theEnv, actPtr);}
  bool CheckAgendaChanged() {return EnvGetAgendaChanged(theEnv);}
  void SetEnvSalienceEval(std::string);
  std::string GetEnvSalienceEval();

  void SetStrategy(std::string);
  std::string GetStrategy();

  void ReorderAgenda(void *); // reorder agenda based on CR strategy. TBD where to fit.

  void Run(); // run function. 


  private: 
   void *theEnv; 
   int maxActivations;
   std::string returnPPString(void *, void (*)(void *, char*, size_t, void*)); 
   
   std::vector<void *> returnList(void* (*)(void *, void *));
   //void ActivationCallback(void *); // callback to the function which will be run on each rule fire.
	
};