#ifndef RTLABELPIK_H
#define RTLABELPIK_H
#include "RtLabel.h"
class RtLabelPiK:public RtLabel{
    public:
	RtLabelPiK(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "#pi^{+}K^{-}(#pi^{-}K^{+}) - #pi^{-}K^{-}(#pi^{+}K^{+})";
	}
	string getKKPairLegendText() const {
	    return "#pi K";
	}
    ClassDef(RtLabelPiK, 1)
};
#endif
