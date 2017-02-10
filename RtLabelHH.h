#ifndef RTLABELHH_H
#define RTLABELHH_H
#include "RtLabel.h"
class RtLabelHH:public RtLabel{
    public:
	RtLabelHH(string correlation, 
		string pair, 
		string run, 
		string collision_sys):RtLabel(correlation, pair, run, collision_sys){}
    private:
	string getPairLegendText() const {
	    return "h^{+}h^{-} - h^{-}h^{-}(h^{+}h^{+})";
	}

	string getKKPairLegendText() const {
	    return "hh";
	}
    ClassDef(RtLabelHH, 1)
};
#endif
