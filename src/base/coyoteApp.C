#include "coyoteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
coyoteApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

coyoteApp::coyoteApp(InputParameters parameters) : MooseApp(parameters)
{
  coyoteApp::registerAll(_factory, _action_factory, _syntax);
}

coyoteApp::~coyoteApp() {}

void
coyoteApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<coyoteApp>(f, af, s);
  Registry::registerObjectsTo(f, {"coyoteApp"});
  Registry::registerActionsTo(af, {"coyoteApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
coyoteApp::registerApps()
{
  registerApp(coyoteApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
coyoteApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  coyoteApp::registerAll(f, af, s);
}
extern "C" void
coyoteApp__registerApps()
{
  coyoteApp::registerApps();
}
