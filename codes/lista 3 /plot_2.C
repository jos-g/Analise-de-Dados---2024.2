void plot_err() {
    TCanvas *c1 = new TCanvas ("c1","Plot com erros", 1920,1080);
    TGraphErrors *plot_errors = new TGraphErrors();
    //
    std::ifstream file("graphdata_error.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }
    //
    double x,y, e_x, e_y;
    while (1) {
        file >> x >> y >> e_x >> e_y;
        plot_errors->SetPoint(plot_errors->GetN(),x,y);
        plot_errors->SetPointError(plot_errors->GetN()-1,e_x,e_y);
        if (file.eof()){break;}
    }
    //
    plot_errors->SetMarkerStyle(20);
    plot_errors->SetMarkerSize(3);
    plot_errors->SetMarkerColor(kRed);
    //
    plot_errors->Draw("APL");
    c1->SaveAs("ex_2b.png");
}
