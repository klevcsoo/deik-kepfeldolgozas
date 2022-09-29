//
// Created by Keve Lajsz on 2022. 09. 29..
//

#ifndef DEIK_KEPFELDOLGOZAS_A_GYAKORLATBAN_2022_OSZ_HISTO_HPP
#define DEIK_KEPFELDOLGOZAS_A_GYAKORLATBAN_2022_OSZ_HISTO_HPP

#include <vector>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

namespace Histo {
    void calcHistoC1(const cv::Mat img, cv::Mat& histo);
    void calcHistoC3(const cv::Mat img, vector<cv::Mat>& histo);

    void drawHistoC1(const cv::Mat histo, cv::Mat& canvas, int channel = -1);
    void drawHistoC3(const vector<cv::Mat> histos, vector<cv::Mat>& canvases);

    /// <summary>
    /// Egy kep hisztogramjanak megjelenitese.
    /// </summary>
    /// <param name="img">1 vagy 3 csatornas input kep</param>
    /// <param name="title">ablaknev</param>
    /// <param name="wait">varakoztatas</param>
    void showHisto(Mat img, string title = "histo", int wait = 0);
};


#endif //DEIK_KEPFELDOLGOZAS_A_GYAKORLATBAN_2022_OSZ_HISTO_HPP
