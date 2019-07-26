#include "PolyResidualBlockFunction.hh"

//-------------------------
// Constructor
//-------------------------
PolyResidualBlockFunction::PolyResidualBlockFunction(string name, vector<double> observations, int SizeObservations, int SizeVariables, int SizeResiduals)
:	UserResidualBlockFunction(name+"_User"),
	name_(name),
	SizeObservations_(SizeObservations),
	SizeVariables_(SizeVariables),
    SizeResiduals_(SizeResiduals)
{
	observations_.clear();
	observations_ = observations;
}

//-------------------------
// Destructor
//-------------------------
PolyResidualBlockFunction::~PolyResidualBlockFunction()
{}

//-------------------------
// Public
//-------------------------
bool PolyResidualBlockFunction::ResidualFunction(vector<double> variables, vector<double> &residuals)
{
	//
	// step 0
	//
	if(variables.size()!=SizeVariables_) return false;

	// observations_[0] : x
	// observations_[1] : y
	// varialbles[0] : a[0]
	// varialbles[1] : a[1]
	// varialbles[2] : a[2]

	// residual = ( y - (a[0] + a[1]*x + a[2]*x^2) )^2

	double x = observations_[0];
	double y = observations_[1];
	double a[4];
	a[0] = variables[0];
	a[1] = variables[1];
	a[2] = variables[2];
	a[3] = variables[3];

	double residual_0 = (a[0] + a[1]*x + a[2]*x*x + a[3]*x*x*x) - y;

	residuals.clear();
	residuals.push_back(residual_0);


	/*
	// debug
	cout<<"Debug class PolyResidualBlockFunction::ResidualFunction"<<endl;
	cout<<"Debug Residual : Observation "<<x<<" "<<y<<endl;
	cout<<"Debug Residual : varialbles "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<", residual "<<residual_0<<endl;
	*/

	return true;
}

int PolyResidualBlockFunction::GetObervationsSize()
{
	return SizeObservations_;
}

void PolyResidualBlockFunction::ShowResidualFunction()
{
	// debug
	cout<<"debug Class PolyResidualBlockFunction : "<<name_<<endl;
	cout<<"Observations : "<<endl;
	for(int i=0; i<observations_.size(); i++)
	{
		cout<<"    ID "<<i<<"; Observation "<<observations_[i]<<endl;
	}
}
