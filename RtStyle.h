/*
 * This class is used to make ROOT plots style consistent 
 */
#ifndef RTSTYLE_H
#define RTSTYLE_H
#include "TString.h"
#include "TAttMarker.h"
class RtStyle{
    public:
	RtStyle():m_AxisTitleSize(0.045),
	          m_AxisDigits(2),
		  m_ErrorBarEndTickLength(2),
                  m_XTitleOffset(.7),
		  m_XTitleSize(.055),
		  m_XLabelSize(.055),
                  m_YTitleOffset(.7),
		  m_YTitleSize(.055),
		  m_YLabelSize(.055),
                  m_MarkerSize(1.5),
		  m_MarkerStyle(kOpenCircle),
		  m_MarkerColor(kBlue),
		  m_LegendTextSize(0.055),
                  m_LegendWidth(.35),
                  m_LegendHeight(.35),
		  m_XDivision(510),
                  m_YDivision(510),
		  m_YMax(1.0),
		  m_YMin(-1.0),
		  m_XMax(100.0),
		  m_XMin(0.0),
		  m_PadLeftMargin(1.0),
		  m_PadRightMargin(1.0),
		  m_PadTopMargin(1.0),
		  m_PadBottomMargin(1.0),
                  m_XTitle("Y"),
                  m_YTitle("X"),
		  m_XLabelFont(42),
		  m_YLabelFont(42)
    {}


	double getAxisTitleSize() const { return m_AxisTitleSize; }
	double getErrorBarEndTickLength() const { return m_ErrorBarEndTickLength; }
	double getXTitleOffset() const { return m_XTitleOffset; }
	double getXTitleSize() const { return m_XTitleSize; }
	double getXLabelSize() const { return m_XLabelSize; }
	double getYTitleOffset() const { return m_YTitleOffset; }
	double getYTitleSize() const { return m_YTitleSize; }
	double getYLabelSize() const { return m_YLabelSize; }
	double getMarkerSize() const { return m_MarkerSize; }
	int getMarkerStyle() const { return m_MarkerStyle; }
	int getMarkerColor() const { return m_MarkerColor; }
	int getLineWidth() const { return m_LineWidth; }
	double getLegendTextSize() const { return m_LegendTextSize; }
	double getLegendWidth() const { return m_LegendWidth; }
	double getLegendHeight() const { return m_LegendHeight; }
	int getYDivision() const { return m_YDivision; }
	int getXDivision() const { return m_XDivision; }
	double getYMax() const { return m_YMax; }
	double getYMin() const { return m_YMin; }
	double getXMax() const { return m_XMax; }
	double getXMin() const { return m_XMin; }
	int getAxisDigits() const { return m_AxisDigits; }
        double getPadLeftMargin() const { return m_PadLeftMargin; }
        double getPadRightMargin() const { return m_PadRightMargin; }
        double getPadTopMargin() const { return m_PadTopMargin; }
	double getPadBottomMargin() const { return m_PadBottomMargin; }
	double getXLabelFont() const { return m_XLabelFont; }
	double getYLabelFont() const { return m_YLabelFont; }
    
	TString getYTitle() const { return m_YTitle; }
	TString getXTitle() const { return m_XTitle; }

	void setAxisTitleSize(double size) { m_AxisTitleSize = size; }
	void setErrorBarEndTickLength(double size) { m_ErrorBarEndTickLength = size; }
	void setXTitleOffset(double v) { m_XTitleOffset = v; }
	void setXTitleSize(double size) { m_XTitleSize = size; } 
	void setXLabelSize(double size) { m_XLabelSize = size; }
	void setYTitleOffset(double v) { m_YTitleOffset = v; }
	void setYTitleSize(double size) { m_YTitleSize = size; }
	void setYLabelSize(double size) { m_YLabelSize = size; }
	void setMarkerStyle(int style) { m_MarkerStyle = style; }
	void setMarkerSize(double size) { m_MarkerSize = size; }
	void setMarkerColor(int cl) { m_MarkerColor = cl; }
	void setLineWidth(int v) { m_LineWidth = v; }
	void setLegendTextSize(double size) { m_LegendTextSize = size; }
	void setLegendWidth(double size) { m_LegendWidth = size; }
	void setLegendHeight(double size) { m_LegendHeight = size; }
	void setYDivision(int d) { m_YDivision = d; }
	void setXDivision(int d) { m_XDivision = d; }
	void setYMax(double v) { m_YMax = v; }
	void setYMin(double v) { m_YMin = v; }
	void setXMax(double v) { m_XMax = v; }
	void setXMin(double v) { m_XMin = v; }
	void setAxisDigits(int v) { m_AxisDigits = v; }
        void setPadLeftMargin(double v) { m_PadLeftMargin = v; }
        void setPadRightMargin(double v) { m_PadRightMargin = v; }
        void setPadTopMargin(double v) { m_PadTopMargin = v; }
        void setPadBottomMargin(double v) { m_PadBottomMargin = v; }
	void setXLabelFont(int v) { m_XLabelFont = v; }
	void setYLabelFont(int v) { m_YLabelFont = v; }

	void setXTitle(const TString& tt) { m_XTitle = tt; }
	void setYTitle(const TString& tt) { m_YTitle = tt; }
    private:
	double m_AxisTitleSize;
	double m_ErrorBarEndTickLength;
	double m_XTitleOffset;
	double m_XTitleSize;
	double m_XLabelSize;
	double m_YTitleOffset;
	double m_YTitleSize;
	double m_YLabelSize;
	double m_MarkerSize;
	int m_MarkerStyle;
	int m_MarkerColor;
	int m_LineWidth;
	double m_LegendTextSize;
	double m_LegendWidth;
	double m_LegendHeight;
	int m_YDivision;
	int m_XDivision;
	int m_AxisDigits; 
	double m_YMax;
	double m_YMin;
	double m_XMax;
	double m_XMin;
	double m_PadLeftMargin;
	double m_PadRightMargin;
	double m_PadTopMargin;
	double m_PadBottomMargin;
	int m_XLabelFont;
	int m_YLabelFont;

	TString m_YTitle;
	TString m_XTitle;

    ClassDef(RtStyle, 1)
};
#endif
