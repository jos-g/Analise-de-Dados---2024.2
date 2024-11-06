#include "TH1F.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TStyle.h"
#include "TPaveStats.h"

void plot_gaussian_histogram() {
    //
    TCanvas *c1 = new TCanvas("c1", "Gaussian Histogram", 1920, 1080);
    //
    TH1F *h1 = new TH1F("h1", "Gaussian Distribution;X;Frequency", 50, 0, 10);
    for (int i = 0; i < 10000; ++i) {
        double random_value = gRandom->Gaus(5, 2);
        h1->Fill(random_value);
    }
    //
    gStyle->SetOptStat(1111111);  // Default stats box settings
    h1->Draw();
    // 
    double skewness = h1->GetSkewness();
    double kurtosis = h1->GetKurtosis();
    TPaveStats *stats = (TPaveStats*)h1->FindObject("stats");
    if (stats) {
        stats->SetTextColor(kBlack);
    // 
double skewness = h1->GetSkewness();
double kurtosis = h1->GetKurtosis();

    // R
TPaveStats *stats = (TPaveStats*)h1->FindObject("stats");
if (stats) {
    //
    stats->AddText(Form("Skewness = %.5f", skewness));
    stats->AddText(Form("Kurtosis = %.5f", kurtosis));
}
    stats->SetY1NDC(0.6);
    }
    c1->Modified();
    c1->Update();
    c1->SaveAs("gaussian_histogram.png");
}
