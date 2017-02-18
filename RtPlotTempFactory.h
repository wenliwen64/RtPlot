#ifndef RTPLOTTEMPFACTORY_H
#define RTPLOTTEMPFACTORY_H
#include "RtStyle.h"
#include "TGaxis.h"
#include <sstream>
#include <memory>
using namespace std;
namespace rtplot{
    class RtPlotTempFactory{
	private:
	    static RtPlotTempFactory* ptr_instance;
	    RtPlotTempFactory(){} // To prevent compile from generating the default constructor
	public:
	    static void setGStyle(RtStyle* style){
		gStyle->SetOptStat(0); 

		// Legend
		gStyle->SetLegendFont(42);
		gStyle->SetLegendBorderSize(0);

		// Line
		gStyle->SetLineWidth(style->getLineWidth());

		// Marker
		gStyle->SetMarkerSize(style->getMarkerSize());

		// Text
		gStyle->SetTextFont(42);

		gStyle->SetEndErrorSize(style->getErrorBarEndTickLength());
		TGaxis::SetMaxDigits(style->getAxisDigits());
	    }

	    static RtPlotTempFactory* instance(){
		if(ptr_instance == 0)
		    ptr_instance = new RtPlotTempFactory();
		return ptr_instance;
	    }

	    static TCanvas* getDivCan(TCanvas* can, int nRows, int nCols, const RtStyle* style){
		can->Divide(nCols, nRows, 0, 0);
		for(int i = 0; i != nCols * nRows; ++i){
		    can->cd(i + 1);
		    gPad->SetTicks(1, 1);
		    gPad->SetMargin(style->getPadLeftMargin(), style->getPadRightMargin(), style->getPadBottomMargin(), style->getPadTopMargin());
		}
		return can;
	    }

	    static TLine* getZeroLine(const RtStyle* style){
		TLine* line = new TLine(style->getXMin(), 0, style->getXMax(), 0);
		line->SetLineColor(1);
		line->SetLineStyle(3);
		return line;
	    }

	    static TLatex* getDescText(double x, double y, RtStyle* style, const char* text){
		TLatex* tex = new TLatex(x, y, text);
		tex->SetNDC();
		tex->SetTextColor(1);
		tex->SetTextSize(style->getLegendTextSize());
		tex->SetTextFont(42);
		return tex;
	    }

	    static TLatex* getSTARPreText(double x, double y, RtStyle* style){
		TLatex* tex = new TLatex(x, y, "STAR Preliminary");
		tex->SetNDC();
		tex->SetTextColor(15);
		tex->SetTextSize(.8 * style->getLegendTextSize());
		tex->SetTextFont(62);
		return tex;
	    }

	    static TGaxis* getReverseAxis(const RtStyle* style){
		stringstream ss(stringstream::in | stringstream::out);
		ss << style->getXMax();
		string exp_f = ss.str();
		exp_f += "- x";
		TF1* f1 = new TF1("f", exp_f.c_str(), style->getXMin(), style->getXMax());
		TGaxis* A1 = new TGaxis(style->getXMin(), style->getYMin(), style->getXMax(), style->getYMin(), "f", style->getXDivision(), "+");
		A1->SetLabelSize(style->getYLabelSize());
		A1->SetLabelFont(style->getYLabelFont());
		return A1;
	    }

	    static TCanvas* getCanvas(const char* cName, const RtStyle* style){
		TCanvas* c = new TCanvas(cName);
		c->SetTicks(1, 1);
		c->SetMargin(style->getPadLeftMargin(), style->getPadRightMargin(), style->getPadBottomMargin(), style->getPadTopMargin());
		return c;
	    }

	    static TGraph* getShellG(TGraph* g, int markerStyle){
		TGraph* gg = (TGraph*)g->Clone();
		gg->SetMarkerStyle(markerStyle);
		gg->SetMarkerSize(g->GetMarkerSize() * 1.05);
		gg->SetMarkerColor(1);
		return gg;
	    }

	    static TCanvas* getRatioCanvas(const char* cName){
		TCanvas* can = new TCanvas(cName, cName, 600, 700);
		TPad* pad1 = new TPad("p1", "p1", 0, .3, 1., 1.);
		pad1->SetTopMargin(0.02);
		pad1->SetBottomMargin(0);
		pad1->SetTicks(1, 1);
		pad1->Draw();

		TPad* pad2 = new TPad("p2", "p2", 0, 0, 1., .3);
		pad2->SetTopMargin(0);
		pad2->SetBottomMargin(.2);
		pad2->SetTicks(1, 1);
		pad2->Draw();
		return can;
	    }

	    static TH2F* getBgPad(const RtStyle* style){
		//shared_ptr<TH2F> histGraph(new TH2F("h_diff", "", 10, style->getXMin(), style->getXMax(), 10, style->getYMin(), style->getYMax()));
		TH2F* histGraph = new TH2F("h_diff", "", 10, style->getXMin(), style->getXMax(), 10, style->getYMin(), style->getYMax());

		//histGraph->SetMaximum(style->getYMax());
		//histGraph->SetMinimum(style->getYMin());
		histGraph->SetLineColor(kBlack);
		histGraph->SetLineWidth(style->getLineWidth());
		histGraph->SetXTitle(style->getXTitle());
		histGraph->SetYTitle(style->getYTitle());
		histGraph->GetYaxis()->SetTitleOffset(style->getYTitleOffset());
		histGraph->GetYaxis()->SetTitleSize(style->getYTitleSize());
		histGraph->GetYaxis()->SetLabelSize(style->getYLabelSize());
		histGraph->GetYaxis()->SetNdivisions(style->getYDivision());
		histGraph->GetYaxis()->CenterTitle();
		histGraph->GetXaxis()->CenterTitle();
		histGraph->GetXaxis()->SetTitleSize(style->getXTitleSize());
		histGraph->GetXaxis()->SetTitleOffset(style->getXTitleOffset());
		histGraph->GetXaxis()->SetLabelSize(style->getXLabelSize());
		histGraph->GetXaxis()->SetNdivisions(style->getXDivision());

		return histGraph;
	    }

	    static TH1F* getBgPad1D(const RtStyle* style){
		//shared_ptr<TH2F> histGraph(new TH2F("h_diff", "", 10, style->getXMin(), style->getXMax(), 10, style->getYMin(), style->getYMax()));
		TH1F* histGraph = new TH1F("h_diff", "", 10, style->getXMin(), style->getXMax());

		histGraph->SetMaximum(style->getYMax());
		histGraph->SetMinimum(style->getYMin());
		histGraph->SetLineColor(kBlack);
		histGraph->SetLineWidth(style->getLineWidth());
		histGraph->SetXTitle(style->getXTitle());
		histGraph->SetYTitle(style->getYTitle());
		histGraph->GetYaxis()->SetTitleOffset(style->getYTitleOffset());
		histGraph->GetYaxis()->SetTitleSize(style->getYTitleSize());
		histGraph->GetYaxis()->SetLabelSize(style->getYLabelSize());
		histGraph->GetYaxis()->SetNdivisions(style->getYDivision());
		histGraph->GetYaxis()->CenterTitle();
		histGraph->GetXaxis()->SetTitleSize(style->getXTitleSize());
		histGraph->GetXaxis()->SetTitleOffset(style->getXTitleOffset());
		histGraph->GetXaxis()->SetLabelSize(style->getXLabelSize());
		histGraph->GetXaxis()->SetNdivisions(style->getXDivision());

		return histGraph;
	    }
	    /*
	    static shared_ptr<TH2F> getBgPad(const RtStyle* style){
		//shared_ptr<TH2F> histGraph(new TH2F("h_diff", "", 10, style->getXMin(), style->getXMax(), 10, style->getYMin(), style->getYMax()));
		shared_ptr<TH2F> histGraph(new TH2F("h_diff", "", 10, style->getXMin(), style->getXMax(), 10, style->getYMin(), style->getYMax()));

		//histGraph->SetMaximum(style->getYMax());
		//histGraph->SetMinimum(style->getYMin());
		histGraph->SetLineColor(kBlack);
		histGraph->SetLineWidth(style->getLineWidth());
		histGraph->SetXTitle(style->getXTitle());
		histGraph->SetYTitle(style->getYTitle());
		histGraph->GetYaxis()->SetTitleOffset(style->getYTitleOffset());
		histGraph->GetYaxis()->SetTitleSize(style->getYTitleSize());
		histGraph->GetYaxis()->SetLabelSize(style->getYLabelSize());
		histGraph->GetYaxis()->SetNdivisions(style->getYDivision());
		histGraph->GetYaxis()->CenterTitle();
		histGraph->GetXaxis()->SetTitleSize(style->getXTitleSize());
		histGraph->GetXaxis()->SetTitleOffset(style->getXTitleOffset());
		histGraph->GetXaxis()->SetLabelSize(style->getXLabelSize());
		histGraph->GetXaxis()->SetNdivisions(style->getXDivision());

		return histGraph;
	    }
	    */

	    static float* getShiftedCent(int n_cent, float* cent, float shift){
		float* result = new float[n_cent];
		for(int i = 0; i != n_cent; ++i)
		    result[i] = cent[i] + shift;
		return result;
	    }
    };
    RtPlotTempFactory* RtPlotTempFactory::ptr_instance = 0;
}
#endif
