#include "../RtFitFuncFactory.h"
using namespace rtfitfunc;
void test_erf(){
    TF1* f1 = RtFitFuncFactory::GetErf(0.0, 3.0);
    f1->SetParameter(0, 1.0);
    f1->SetParameter(1, 1.0);
    f1->SetParameter(2, 1.0);
    f1->Draw();
}

void test_expeff(){
    TF1* f1 = RtFitFuncFactory::GetExpEffFunc(0.0, 3.0);
    f1->SetParameter(0, 1.0);
    f1->SetParameter(1, 1.0);
    f1->SetParameter(2, 1.0);
    f1->Draw();
}

void test_fitfunc(){
    test_erf();
    test_expeff();
}
