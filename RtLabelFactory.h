#ifndef RTLABELFACTORY_H
#define RTLABELFACTORY_H
#include "RtLabelPiPi.h"
#include "RtLabelHH.h"
#include "RtLabelPiK.h"
#include "RtLabelPP.h"
#include "RtLabelPK.h"
#include "RtLabelPPi.h"
class RtLabelFactory{
    public:
	static RtLabelFactory* instance(){
	    if(!s_instance)
		s_instance = new RtLabelFactory();
	    return s_instance;
	}

        RtLabel* getRtLabel(string correlation, 
		string pair,
		string run,
		string collision_sys){
	    if(pair == "pipi")
		return new RtLabelPiPi(correlation, pair, run, collision_sys);
	    else if(pair == "hh")
		return new RtLabelHH(correlation, pair, run, collision_sys);
	    else if(pair == "pik")
		return new RtLabelPiK(correlation, pair, run, collision_sys);
	    else if(pair == "pp")
		return new RtLabelPP(correlation, pair, run, collision_sys);
	    else if(pair == "pk")
		return new RtLabelPK(correlation, pair, run, collision_sys);
	    else if(pair == "ppi")
		return new RtLabelPPi(correlation, pair, run, collision_sys);
	    else 
		return 0;
	}
    private:
        RtLabelFactory(){}
        static RtLabelFactory* s_instance;
    ClassDef(RtLabelFactory, 1)
};
RtLabelFactory* RtLabelFactory::s_instance = 0; 
#endif
