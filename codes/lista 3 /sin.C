#include "TCanvas.h"
#include "TF1.h"
#include "TMath.h"
#include <iostream>

double f(double *x, double *c_i) {
    return (c_i[0] * TMath::Sin(c_i[1] * x[0])) / x[0];
}

void plotFunction(double p0, double p1) {
    TF1 *func = new TF1("p0*sin(p1*x)/x", f, -10, 10, 5);
    func->SetParameters(p0, p1);
    
    TCanvas *c1 = new TCanvas("c1", "Function Plot", 1920, 1080);
    func->SetLineColor(kBlue);
    func->Draw();
    // valor para x=1
    double x0 = 1.0;
    double funcValue = func->Eval(x0);
    std::cout << "f(x) = 1: " << funcValue << std::endl;
    // derivada em x = 1 
    double funcDerivative = func->Derivative(x0);
    std::cout << "f'(1) = : " << funcDerivative << std::endl;
    // integral de 0 a 3 
    double integralValue = func->Integral(0, 3);
    std::cout << "Integral de 0 a 3: " << integralValue << std::endl;
    // Legenda 
    TPaveText *pt = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);    
    pt->AddText(Form("f(1) = %.2f", funcValue));
    pt->AddText(Form("f' (1) = %.2f", funcDerivative));
    pt->AddText(Form("Integral = %.2f", integralValue));
    pt->AddText("p0 = 1, p1=2");
    pt->Draw();
    c1->SaveAs("plots/function_plot.png");
}

int main() {
    double p0 = 1.0;
    double p1 = 2.0;
    plotFunction(p0, p1);
}
