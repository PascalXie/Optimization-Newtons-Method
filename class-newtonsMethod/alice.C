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

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();

int main()
{
	cout<<"Hello "<<endl;

	test8();

	return 1;
}

void test1()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new SteepestCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	// derivative
	vector<double> variables;
	variables.push_back(0);
	variables.push_back(2);
	variables.push_back(3);

	double derivative0;
	bool isDerivativeGood = costFunction->GetOneDerivative(0,variables,derivative0);

	if(isDerivativeGood)
	{
		cout<<"derivative0 "<<derivative0<<endl;
	}
	else
	{
		cout<<"Error happend in Derivative "<<endl;
	}

}

void test2()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new SteepestCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	for(int i=0;i<10;i++)
	{
		cout<<"Variables(Plan) ID "<<i<<endl;
		double a0 = -4+i;
		double a1 = 2;
		double a2 = 3;

		// derivative
		vector<double> variables;
		variables.push_back(a0);
		variables.push_back(a1);
		variables.push_back(a2);

		vector<double> derivatives;
		bool isDerivativeGood = costFunction->GradientFunction(variables,derivatives);

		if(isDerivativeGood)
		{
			cout<<"derivative : "<<derivatives[0]<<", "<<derivatives[1]<<", "<<derivatives[2]<<endl;
		}
		else
		{
			cout<<"Error happend in Derivative "<<endl;
		}
		cout<<""<<endl;
	}

}

void test3()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 3;
	UserOptimizationManager * sd = new SteepestOptimizationManager("SteepestDecentMethod",observationsSize,varialbeSize,residualSize);

	// set variables
	vector<double> variables;
	variables.push_back(5);
	variables.push_back(6);
	variables.push_back(4);
	sd->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new SteepestCostFunction("costFunction",observationsSize,varialbeSize,residualSize);

	int LengthObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<LengthObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	sd->SetUserInitialization(costFunction);


	// initialize
	sd->Initialize();
}

void test4()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new NewtonsCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	// derivative
	vector<double> variables;
	variables.push_back(0);
	variables.push_back(2);
	variables.push_back(3);

	double derivative0;
	bool isDerivativeGood = costFunction->GetOneDerivative(0,variables,derivative0);

	if(isDerivativeGood)
	{
		cout<<"derivative0 "<<derivative0<<endl;
	}
	else
	{
		cout<<"Error happend in Derivative "<<endl;
	}

}

void test5()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new NewtonsCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	for(int i=0;i<10;i++)
	{
		cout<<"Variables(Plan) ID "<<i<<endl;
		double a0 = -4+i;
		double a1 = 2;
		double a2 = 3;

		// derivative
		vector<double> variables;
		variables.push_back(a0);
		variables.push_back(a1);
		variables.push_back(a2);

		vector<double> derivatives;
		bool isDerivativeGood = costFunction->GradientFunction(variables,derivatives);

		if(isDerivativeGood)
		{
			cout<<"derivative : "<<derivatives[0]<<", "<<derivatives[1]<<", "<<derivatives[2]<<endl;
		}
		else
		{
			cout<<"Error happend in Derivative "<<endl;
		}
		cout<<""<<endl;
	}

}

void test6()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new NewtonsCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	for(int i=0;i<10;i++)
	{
		cout<<"Variables(Plan) ID "<<i<<endl;
		double a0 = -4+i;
		double a1 = 2;
		double a2 = 3;

		// derivative
		vector<double> variables;
		variables.push_back(a0);
		variables.push_back(a1);
		variables.push_back(a2);

		cout<<"Variables : "<<a0<<", "<<a1<<", "<<a2<<endl;

		double oneSecondDerivative = 666;
		bool isDerivativeGood = costFunction->GetOneSecondOrderDerivative(1,2,variables,oneSecondDerivative);

		if(isDerivativeGood)
		{
			cout<<"oneSecondDerivative : "<<oneSecondDerivative<<endl;
		}
		else
		{
			cout<<"Error happend in Derivative "<<endl;
		}
		cout<<""<<endl;
	}

}

void test7()
{
	int residualSize = 1;
	int varialbeSize = 3;
	UserCostFunction* costFunction = new NewtonsCostFunction("test", 2, varialbeSize, residualSize);

	// observations
	int sizeObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<sizeObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	costFunction->Show();

	for(int i=0;i<10;i++)
	{
		cout<<"Variables(Plan) ID "<<i<<endl;
		double a0 = -4+i;
		double a1 = 2;
		double a2 = 3;

		// derivative
		vector<double> variables;
		variables.push_back(a0);
		variables.push_back(a1);
		variables.push_back(a2);

		cout<<"Variables : "<<a0<<", "<<a1<<", "<<a2<<endl;

		vector<double> HessianMatrix;
		bool isDerivativeGood = costFunction->HessianMatrixFunction(variables,HessianMatrix);

		if(isDerivativeGood)
		{
			cout<<"HessianMatrix : "<<endl;
			for(int i=0;i<3;i++)
			{
				int rowID = i;
				for(int j=0;j<3;j++)
				{
					int columnID = j;
					int ID = rowID*3+columnID;
					cout<<HessianMatrix[ID]<<", ";
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"Error happend in Derivative "<<endl;
		}
		cout<<""<<endl;
	}

}

void test8()
{
	int observationsSize = 2;
	int residualSize = 1;
	int varialbeSize = 3;
	UserOptimizationManager * newton = new NewtonsOptimizationManager("NewtonsMethod",observationsSize,varialbeSize,residualSize);

	// set variables
	vector<double> variables;
	variables.push_back(5);
	variables.push_back(6);
	variables.push_back(4);
	newton->SetUserInitialization(variables);

	// set cost function
	UserCostFunction* costFunction = new NewtonsCostFunction("costFunction",observationsSize,varialbeSize,residualSize);

	int LengthObservations = 5;
	double observation_xs[5] = {0,1,2,-1,-2};
	double observation_ys[5] = {1,6,17,2,9};

	for(int i=0;i<LengthObservations;i++)
	{
		vector<double> observation_current;
		observation_current.push_back(observation_xs[i]);
		observation_current.push_back(observation_ys[i]);
		costFunction->AddResidualBlock(observation_current);
	}

	newton->SetUserInitialization(costFunction);

	//// iteration
	//newton->Iteration(variables);

	// initialize
	newton->Initialize();
}
