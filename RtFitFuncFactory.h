#ifndef RTFITFUNCFACTORY_H
#define RTFITFUNCFACTORY_H
#include "TF1.h"
#include "TMath.h"
#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;
namespace rtfitfunc{
    class RtFitFuncFactory{
	private:
	    static RtFitFuncFactory* ptr_instance;
	    static int count; // used for function naming
	    RtFitFuncFactory(){}
	public:
            static RtFitFuncFactory* instance(){
		if(!ptr_instance)
		    ptr_instance = new RtFitFuncFactory();
		return ptr_instance;
	    } 

	    static TF1* GetErf(double x_min, double x_max){
		++count;
		char func_name[100];
		sprintf(func_name, "erf_%d", count);
		TF1* f1 = new TF1(func_name, "[0] * TMath::Erf(x - [1]) + [2]", x_min, x_max);
		return f1; 
	    }

	    static TF1* GetExpEffFunc(double x_min, double x_max){
		++count;
		char func_name[100];
		sprintf(func_name, "expeff_%d", count);
		TF1* f1 = new TF1(func_name, "[0] * exp(-pow([1] / x, [2]))", x_min, x_max);
		return f1;
	    }
    };
    RtFitFuncFactory* RtFitFuncFactory::ptr_instance = 0;
    int RtFitFuncFactory::count = 0;
}
#endif
