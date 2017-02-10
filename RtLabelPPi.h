#ifndef RTLABELPPI_H
#define RTLABELPPI_H
#include "RtLabel.h"
class RtLabelPPi:public RtLabel{
    public:
	RtLabelPPi(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "p#pi^{-}(#bar{p}#pi^{+}) - #bar{p}#pi^{-}(p#pi^{+})";
	}
	string getKKPairLegendText() const {
	    return "p#pi";
	}
    ClassDef(RtLabelPPi, 1)
};
#endif
