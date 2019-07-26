#ifndef USEROPTIMIZATIONMANAGER_HH
#define USEROPTIMIZATIONMANAGER_HH

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "UserCostFunction.hh"

using namespace std;

class UserOptimizationManager
{
    public:
		UserOptimizationManager(string name, int SizeObservations, int SizeVariables, int SizeResiduals);
		~UserOptimizationManager();

    public:
		virtual void SetUserInitialization(UserCostFunction* costFunction) = 0;
		virtual void SetUserInitialization(vector<double> variables) = 0;
		virtual void Iteration(vector<double> VariablesPrevious) = 0;

    public:
		void Initialize();
		void SetAlphaStepLength(double alpha_stepLength);

	protected:
		// line search methods
		double GetAlphaStepLength_LineSearch_0816Method(vector<double> Variables, vector<double> DescentDirection);

	protected:
		int SizeObservations_;
		int SizeVariables_;
		int SizeResiduals_;

		bool IsInitializationCostFunctionSet_;
		bool IsInitializationVariablesSet_;

		UserCostFunction* costFunction_;

		vector<double> initializationVariables_;
		vector<double> VariablesPrevious_;
		vector<double> VariablesCurrent_;

		double alpha_stepLength_;
		vector<double> stepLengths_;

		int TotalNumberIterations_;
		int MaximumNumberIterations_;


    private:
		string name_;
};
#endif
