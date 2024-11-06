#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "iostream"

void plot_graph() {
    //
   std::ifstream file("graphdata.txt");
    TGraph *plot = new TGraph();
    TCanvas *c1 = new TCanvas("c1","data",1920,1080);
    //
    double x,y;
    while (1) {
        file >> x >> y;
        plot->SetPoint(plot->GetN(),x,y);
        if (file.eof()){break;}
}
    //
    plot->SetMarkerStyle(20);
    plot->SetMarkerSize(3);
    plot->SetMarkerColor(kRed);
    //
    plot->Draw("APL");
    c1->SaveAs("ex_2.png");
}
