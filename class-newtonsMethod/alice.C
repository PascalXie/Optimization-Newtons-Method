#include <iostream>
#include <vector>
#include <string>

//#include "Optimization.hh"
#include "UserCostFunction.hh"
#include "SteepestCostFunction.hh"
#include "NewtonsCostFunction.hh"

#include "UserResidualBlockFunction.hh"
#include "PolyResidualBlockFunction.hh"

#include "UserOptimizationManager.hh"
#include "SteepestOptimizationManager.hh"
#include "NewtonsOptimizationManager.hh"


using namespace std;

void test3();
void test4();
void test7();
void test8();
double observation1(double ob1);
double observation2(double ob1);

int main()
{
	cout<<"Hello "<<endl;

	test4();
	//test8();

	return 1;
}

void test3()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 4;
	UserOptimizationManager * sd = new SteepestOptimizationManager("SteepestDecentMethod",observationsSize,varialbeSize,residualSize);

	// set variables
	vector<double> variables;
	variables.push_back(1.1);
	variables.push_back(2.1);
	variables.push_back(3.1);
	variables.push_back(4.1);
	sd->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new SteepestCostFunction("costFunction",observationsSize,varialbeSize,residualSize);

	// get observations
	int LengthObservations = 5;
	double observation_xs[5];
	double observation_ys[5];
	for(int i=0;i<LengthObservations;i++)
	{
		double x = double(i)-2;
		double y = observation2(x);
		observation_xs[i] = x;
		observation_ys[i] = y;
		cout<<"Observation ID "<<i<<", x "<<observation_xs[i]<<", y "<<observation_ys[i]<<endl;
	}

	for(int i=0;i<LengthObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	//
	cout<<" "<<endl;
	cout<<"alice SetUserInitialization"<<endl;
	sd->SetUserInitialization(costFunction);


	// initialize
	cout<<" "<<endl;
	cout<<"Initialize "<<endl;
	sd->Initialize();
}

void test4()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 4;
	UserOptimizationManager * manager = new NewtonsOptimizationManager("NewtonsMethod",observationsSize,varialbeSize,residualSize);

	// set variables
	vector<double> variables;
	variables.push_back(1.+0.2);
	variables.push_back(2.+0.2);
	variables.push_back(3.-0.2);
	variables.push_back(4.-0.2);
	manager->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new NewtonsCostFunction("costFunction",observationsSize,varialbeSize,residualSize);

	// get observations
	int LengthObservations = 5;
	double observation_xs[5];
	double observation_ys[5];
	for(int i=0;i<LengthObservations;i++)
	{
		double x = double(i)-2;
		double y = observation2(x);
		observation_xs[i] = x;
		observation_ys[i] = y;
		cout<<"Observation ID "<<i<<", x "<<observation_xs[i]<<", y "<<observation_ys[i]<<endl;
	}

	for(int i=0;i<LengthObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	//
	cout<<" "<<endl;
	cout<<"alice SetUserInitialization"<<endl;
	manager->SetUserInitialization(costFunction);


	// initialize
	cout<<" "<<endl;
	cout<<"Initialize "<<endl;
	manager->Initialize();
}

void test7()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 4;
	UserOptimizationManager * sp = new SteepestOptimizationManager("NewtonsMethod",observationsSize,varialbeSize,residualSize);
	sp->SetAlphaStepLength(1e-6);

	// set variables
	vector<double> variables;
	variables.push_back(1.9);
	variables.push_back(2.9);
	variables.push_back(3.9);
	variables.push_back(4.9);
	sp->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new SteepestCostFunction("costFunction",observationsSize,varialbeSize,residualSize);
	costFunction->SetStepLength(1e-3);

	int LengthObservations = 6;
	for(int i=0;i<LengthObservations;i++)
	{
		double ob1 = double(i);
		double ob2 = observation2(ob1);

		vector<double> observation_current;
		observation_current.push_back(ob1);
		observation_current.push_back(ob2);
		costFunction->AddResidualBlock(observation_current);
	}

	sp->SetUserInitialization(costFunction);

	//// iteration
	//newton->Iteration(variables);

	// initialize
	sp->Initialize();
}

void test8()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 4;
	UserOptimizationManager * newton = new NewtonsOptimizationManager("NewtonsMethod",observationsSize,varialbeSize,residualSize);
	newton->SetAlphaStepLength(1e-2);

	// set variables
	vector<double> variables;
	variables.push_back(1.1);
	variables.push_back(2.1);
	variables.push_back(3.1);
	variables.push_back(4.1);
	newton->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new NewtonsCostFunction("costFunction",observationsSize,varialbeSize,residualSize);
	costFunction->SetStepLength(1e-2);

	int LengthObservations = 16;
	for(int i=0;i<LengthObservations;i++)
	{
		double ob1 = double(i);
		double ob2 = observation2(ob1);

		vector<double> observation_current;
		observation_current.push_back(ob1);
		observation_current.push_back(ob2);
		costFunction->AddResidualBlock(observation_current);
	}

	newton->SetUserInitialization(costFunction);

	//// iteration
	//newton->Iteration(variables);

	// initialize
	newton->Initialize();
}

double observation1(double ob1)
{
	double as[3] = {1,2,3};
	double x = ob1;
	double y = (as[0] + as[1]*x + as[2]*x*x);

	return y;
}

double observation2(double ob1)
{
	double as[4] = {1,2,3,4};
	double x = ob1;
	double y = (as[0] + as[1]*x + as[2]*x*x + as[3]*x*x*x);

	return y;
}
