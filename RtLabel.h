#ifndef RTLABEL_H
#define RTLABEL_H
#include <string>
#include "TString.h"
using namespace std;
/*
 * This class is to be used in creation of the zoo of PID plots without unnecessary troubles (which I had enough!).
 */
class RtLabel{
    /* Example of input label for further parse: ppi`*/
    public:
	RtLabel(string correlation, // gamma_separate, gamma_diff, kkiller 
		string pair,  // pipi
		string run,  // run11
		string collision_sys):// auau200GeV
	    m_DataDir("../data_points/"),
	    m_PlotsDir("../../plots/"),
	    m_Corr(correlation),
	    m_Pair(pair), 
	    m_Run(run), 
	    m_Coll(collision_sys){
                m_Label = m_Corr + "_" + m_Pair + "_" + m_Coll + m_Run; // sth like "gamma_diff_ppi_auau200GeVrun11"
	}

	/* To create something like "../../plots/gamma_diff_ppi_auau200GeVrun11.pdf" */
        //TString getDataFilePath() const {
	    //return m_DataDir + m_Label + ".txt"; 
	//}

        TString getDataFilePath() const {
	    return m_DataDir + m_Label + ".txt"; 
	}

        TString getGammaDataFilePath() const {
	    return m_DataDir + "gamma_" + m_Pair + "_" + m_Coll + m_Run + ".txt"; 
	}
	/* To create something like "../../plots/gamma_diff_ppi_auau200GeVrun11.pdf" */
        TString getPlotFilePath(string postfix) const {
	    return m_PlotsDir + m_Label + postfix; 
	}

	/* To create something like "pK, Au+Au 200 GeV" */
	TString getKKLegendText() const {
	    return getKKPairLegendText() + ", " + getCollisionSystem(); 
	}

	TString getKKLegendTextNoColl() const {
	    return getKKPairLegendText(); 
	}
	/* To create something like "pK^{-}(#bar{p}K^{+}) - pK^{+}(#bar{p}K^{-}), Au+Au 200 GeV" */
	TString getGammaLegendText() const {
	    return getPairLegendText() + ", " + getCollisionSystem();  // TODO: to add separate case
	}

	TString getGammaLegendTextNoColl() const {
	    return getPairLegendText();  
	}
	/* To get something like "#gamma_{os} - #gamma_{ss}"*/
	TString getYTitle() const {
	    if(m_Corr == "gamma_diff")
		return "#gamma_{os} - #gamma_{ss}";
	    else if(m_Corr == "gamma_separate")
		return "#gamma = #LT cos(#phi_{1} + #phi_{2} - 2 #psi_{full}) #GT";
	    else if(m_Corr == "kkiller")
		return "#kappa_{K} = #frac{#Delta#gamma}{v_{2}#Delta#delta}";
	    else
		return "";
	}
    private:
	string m_DataDir;
	string m_PlotsDir;
	string m_Label;
	string m_Corr;
	string m_Pair;
	string m_Run;
	string m_Coll;

	string getCollisionSystem() const{
	    if(m_Coll == "auau200GeV")
		return "Au+Au 200 GeV";
	    else if(m_Coll == "auau39GeV")
		return "Au+Au 39 GeV";
	    else if(m_Coll == "dau200GeV")
		return "d+Au 200 GeV";
	    else if(m_Coll == "pau200GeV")
		return "p+Au 200 GeV";
	    else
		return "";
	}

	TString getPair() const {
	    TString tmp(m_Pair);
	    return tmp;
	}
        /* To create something like "pK^{-}(#bar{p}K^{+}) - pK^{+}(#bar{p}K^{-})" */
	virtual string getPairLegendText() const = 0;
	virtual string getKKPairLegendText() const = 0;
	ClassDef(RtLabel, 1)
};
#endif
