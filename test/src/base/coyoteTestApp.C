//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "coyoteTestApp.h"
#include "coyoteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
coyoteTestApp::validParams()
{
  InputParameters params = coyoteApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

coyoteTestApp::coyoteTestApp(InputParameters parameters) : MooseApp(parameters)
{
  coyoteTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

coyoteTestApp::~coyoteTestApp() {}

void
coyoteTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  coyoteApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"coyoteTestApp"});
    Registry::registerActionsTo(af, {"coyoteTestApp"});
  }
}

void
coyoteTestApp::registerApps()
{
  registerApp(coyoteApp);
  registerApp(coyoteTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
coyoteTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  coyoteTestApp::registerAll(f, af, s);
}
extern "C" void
coyoteTestApp__registerApps()
{
  coyoteTestApp::registerApps();
}
