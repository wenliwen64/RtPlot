#ifndef RTLABELPK_H
#define RTLABELPK_H
#include "RtLabel.h"
class RtLabelPK:public RtLabel{
    public:
	RtLabelPK(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "pK^{-}(#bar{p}K^{+}) - pK^{+}(#bar{p}K^{-})";
	}
	string getKKPairLegendText() const {
	    return "pK";
	}
    ClassDef(RtLabelPK, 1)
};
#endif
