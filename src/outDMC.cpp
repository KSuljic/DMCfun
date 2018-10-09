#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include "inDMC.h"
#include "outDMC.h"
#include <Rcpp.h>

// find . -name "*.cpp" -exec sed -i 's/Rcpp::Rcout/Rcpp::Rcout/g' {} \;

void printResults(Prms &p,
                  std::map<std::string, std::vector<double> > &resSum,
                  std::map<std::string, std::vector<double> > &resDelta,
                  std::map<std::string, std::vector<double> > &resCAF) {

    Rcpp::Rcout << "Results Summary:" << std::endl;
    Rcpp::Rcout << "\trtCor\tsdRtCor\tperErr\trtErr\tsdRtErr" << std::endl;
    Rcpp::Rcout << "comp\t"
                << round(resSum["resSum_comp"][0]) << "\t"
                << round(resSum["resSum_comp"][1]) << "\t"
                << resSum["resSum_comp"][2] << "\t"
                << round(resSum["resSum_comp"][3]) << "\t"
                << round(resSum["resSum_comp"][4]) << std::endl;
    Rcpp::Rcout << "incomp\t"
                << round(resSum["resSum_incomp"][0]) << "\t"
                << round(resSum["resSum_incomp"][1]) << "\t"
                << resSum["resSum_incomp"][2] << "\t"
                << round(resSum["resSum_incomp"][3]) << "\t"
                << round(resSum["resSum_incomp"][4]);
    Rcpp::Rcout << std::endl;
    Rcpp::Rcout << std::endl;

    // results delta distribution
    Rcpp::Rcout << "Delta Values:\n" << "\t";
    for (auto step = p.stepDelta; step < 100; step+= p.stepDelta){
        Rcpp::Rcout << std::setw(4) << step << "%\t";
    }
    Rcpp::Rcout << std::endl;

    Rcpp::Rcout << "comp" << "\t";
    for (unsigned int i = 0; i < resDelta["delta_pct_comp"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(1) << resDelta["delta_pct_comp"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;

    Rcpp::Rcout << "incomp" << "\t";
    for (unsigned int i = 0; i < resDelta["delta_pct_incomp"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(1) << resDelta["delta_pct_incomp"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;

    Rcpp::Rcout << "mean" << "\t";
    for (unsigned int i = 0; i < resDelta["delta_pct_mean"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(1) << resDelta["delta_pct_mean"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;

    Rcpp::Rcout << "effect" << "\t";
    for (unsigned int i = 0; i < resDelta["delta_pct_delta"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(1) << std::right << std::setw(5)
                  << resDelta["delta_pct_delta"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;
    Rcpp::Rcout << std::endl;

    // results caf
    Rcpp::Rcout << "CAF Values:\n" << "\t";
    for (auto step = 0; step < 100; step+= p.stepCAF) {
        Rcpp::Rcout << std::right << std::setw(3) << step << "-" << (step+p.stepCAF) <<"%\t";
    }
    Rcpp::Rcout << std::endl;

    Rcpp::Rcout << "comp" << "\t";
    for (unsigned int i = 0; i < resCAF["caf_comp"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(3) << std::right << std::setw(7)
                  << resCAF["caf_comp"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;
    Rcpp::Rcout << "incomp" << "\t";
    for (unsigned int i = 0; i < resCAF["caf_incomp"].size(); i++){
        Rcpp::Rcout << std::fixed << std::setprecision(3) << std::right << std::setw(7)
                  << resCAF["caf_incomp"][i] << "\t";
    }
    Rcpp::Rcout << std::endl;

}
