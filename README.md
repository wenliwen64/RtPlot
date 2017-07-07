# Manual

## RtPlotTempFacotry

## RtStyleFactory

### Working Example

```c++
#include "../../CVE_Project/util/RtPlotTempFactory.h"
#include "../../CVE_Project/util/RtStyleFactory.h"
using namespace rtplot;
void plot_mean_std(){
    RtPlotTempFactory* fty = RtPlotTempFactory::instance();

    RtStyle* style = RtStyleFactory::instance()->createStyle("vanilla");
    double xmin = -1;
    double xmax = 14;
    style->setXMin(xmin);
    style->setXMax(xmax);
    style->setYMin(0.0);
    style->setYMax(70.);
    style->setXTitle("Month");
    style->setYTitle("Rainfall(af^{1/2})");
    fty->setGStyle(style);

    TCanvas* can = fty->getCanvas("c1", style);
    TH2F* bg = fty->getBgPad(style);
    bg->Draw();
      
    double x[12] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12};
    double monthly_mean[12] = {25.7405,31.9291,31.5462,24.0107,17.4235,12.1752,8.56591,6.22578,5.95911,7.07194,10.8237,17.8213};
    double monthly_std[12] = {22.8104,24.5223,24.0415,15.2376,10.8551,7.04415,5.8209,4.76374,4.84335,5.19993,9.8928,14.6695};
    TGraphErrors* ger = new TGraphErrors(12, x, monthly_mean, 0, monthly_std);
    ger->SetMarkerStyle(8);
    ger->SetMarkerSize(style->getMarkerSize());
    ger->SetMarkerColorAlpha(kBlue, .65);
    ger->SetFillColorAlpha(kRed, .45);
    ger->Draw("3 p");
    gPad->SaveAs("time_dependence.pdf");
}
```




