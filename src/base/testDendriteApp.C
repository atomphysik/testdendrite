#include "testDendriteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
testDendriteApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

testDendriteApp::testDendriteApp(InputParameters parameters) : MooseApp(parameters)
{
  testDendriteApp::registerAll(_factory, _action_factory, _syntax);
}

testDendriteApp::~testDendriteApp() {}

void
testDendriteApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<testDendriteApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"testDendriteApp"});
  Registry::registerActionsTo(af, {"testDendriteApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testDendriteApp::registerApps()
{
  registerApp(testDendriteApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testDendriteApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testDendriteApp::registerAll(f, af, s);
}
extern "C" void
testDendriteApp__registerApps()
{
  testDendriteApp::registerApps();
}
