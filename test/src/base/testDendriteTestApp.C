//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "testDendriteTestApp.h"
#include "testDendriteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
testDendriteTestApp::validParams()
{
  InputParameters params = testDendriteApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

testDendriteTestApp::testDendriteTestApp(InputParameters parameters) : MooseApp(parameters)
{
  testDendriteTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

testDendriteTestApp::~testDendriteTestApp() {}

void
testDendriteTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  testDendriteApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"testDendriteTestApp"});
    Registry::registerActionsTo(af, {"testDendriteTestApp"});
  }
}

void
testDendriteTestApp::registerApps()
{
  registerApp(testDendriteApp);
  registerApp(testDendriteTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
testDendriteTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testDendriteTestApp::registerAll(f, af, s);
}
extern "C" void
testDendriteTestApp__registerApps()
{
  testDendriteTestApp::registerApps();
}
