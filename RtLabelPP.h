#ifndef RTLABELPP_H
#define RTLABELPP_H
#include "RtLabel.h"
class RtLabelPP:public RtLabel{
    public:
	RtLabelPP(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "p#bar{p} - pp(#bar{p}#bar{p})";
	}
	string getKKPairLegendText() const {
	    return "pp";
	}
    ClassDef(RtLabelPP, 1)
};
#endif
