#ifndef RTLABELPIPI_H
#define RTLABELPIPI_H
#include "RtLabel.h"
class RtLabelPiPi:public RtLabel{
    public:
	RtLabelPiPi(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "#pi^{+}#pi^{-} - #pi^{-}#pi^{-}(#pi^{+}#pi^{+})";
	}

	string getKKPairLegendText() const {
	    return "#pi#pi";
	}
    ClassDef(RtLabelPiPi, 1)
};
#endif
