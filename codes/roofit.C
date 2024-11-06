#include "TH1.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooPlot.h"
#include "RooFit.h"
#include "TCanvas.h"
#include <iostream>
using namespace RooFit ;

void roofit(){
    RooRealVar mass("mass","mass",5.20,5.30) ;
    RooRealVar mean("mean","mean",5.28,5.20,5.30) ;
    RooRealVar sigma("sigma","sigma",0.005,0.001,0.005);
    RooGaussian model("model","model",mass,mean,sigma);
    // Importar a pdf 
    RooWorkspace w("w");
    w.import(model) ;

    //Gerar dados
    RooDataSet* dado = w.pdf("model")->generate(*w.var("mass"),1000) ; 
    //Executar o ajuste
    w.pdf("model")->fitTo(*dado) ;
    RooPlot* frame = w.var("mass")->frame();

    TCanvas *c = new TCanvas("c","c",1368,768);
    dado->plotOn(frame);
    w.pdf("model")->plotOn(frame);
    frame->Draw();
    c->Draw();
    c->SaveAs("w.png");
    w.writeToFile("wspacecpp.root");

}
