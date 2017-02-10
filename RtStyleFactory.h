#ifndef RTSTYLEFACTORY_H
#define RTSTYLEFACTORY_H
#include "RtStyle.h"
#include <string>
using namespace std;
namespace rtplot{
    class RtStyleFactory{
	private:
	    RtStyleFactory(){}
	    static RtStyleFactory* s_instance;
	public:
	    RtStyle* createStyle(string name = ""){
		/*
		 * The name parameter can be specified for use scenario, like kkiller, gamma...
		 */
		if(name == "gamma"){
		    RtStyle* style = new RtStyle();
		    style->setLegendTextSize(.075);
		    style->setXLabelSize(0);
		    style->setXTitle("% Most Central");
		    style->setXTitleOffset(.9);
		    style->setXTitleSize(.055);
		    style->setYTitle("#gamma_{OS} - #gamma_{SS}");
		    style->setYTitleOffset(.65);
		    style->setYTitleSize(.065);
		    style->setXMin(0);
		    style->setXMax(80);
		    style->setMarkerSize(2);
		    style->setLegendHeight(.065);
		    style->setLegendWidth(.10);
		    style->setAxisDigits(2);
		    style->setPadTopMargin(.06);
		    style->setPadBottomMargin(0.12);
		    style->setLineWidth(2.0);
		    style->setPadRightMargin(.01);
		    style->setYDivision(503);
		    style->setXDivision(505);
		    style->setXLabelFont(42);
		    style->setYLabelFont(42);
		    return style;
		}
		else if(name == "kappa"){
		    RtStyle* style = new RtStyle();
		    style->setXMin(0);
		    style->setXMax(60);
		    style->setLegendTextSize(.075);
		    style->setXTitle("% Most Central");
		    style->setXTitleOffset(.8);
		    style->setXTitleSize(.055);
		    style->setXLabelSize(.045);
		    style->setYTitle("#kappa_{K} = #Delta#gamma / v_{2}#Delta#delta");
		    style->setYTitleOffset(.55);
		    style->setYTitleSize(.065);
		    style->setYLabelSize(.045);
		    style->setXLabelSize(0);
		    style->setMarkerSize(2);
		    style->setAxisDigits(2);
		    style->setLegendHeight(.065);
		    style->setLegendWidth(.10);
		    style->setLineWidth(2.0);
		    style->setPadTopMargin(.06);
		    style->setPadBottomMargin(.12);
		    style->setPadLeftMargin(.12);
		    style->setPadRightMargin(.01);
		    style->setYDivision(503);
		    style->setXDivision(505);
		    return style;
		}
		else
		    return new RtStyle();

	    }
	    static RtStyleFactory* instance(){
		if(!s_instance)
		    s_instance = new RtStyleFactory();
		return s_instance;
	    }
	    ClassDef(RtStyleFactory, 1)
    };
    RtStyleFactory* RtStyleFactory::s_instance = 0;
}
#endif
