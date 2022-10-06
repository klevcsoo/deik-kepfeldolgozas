#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../lib/histo.hpp"

int calc_th_value(const cv::Mat& src, float ratio = 0.1f) {
    int n_fg = (int)((float)src.rows * (float)src.cols * ratio);
    cv::Mat hist;
    Histo::calcHistoC1(src, hist);

    int s = 0;
    for (int th = 0; th < 256; th++) {
        s += hist.at<int>(th);
        if (s >= n_fg) return th;
    }

    return 255; // hiba
}


int main() {
    cv::Mat img = cv::imread(
            "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/scanned3.png",
            CV_8UC1
    );
    cv::Mat dest;

    int th = calc_th_value(img, 0.1f);
    cv::threshold(img, dest, th, 255, cv::THRESH_BINARY);
    cv::imshow("szoveg", dest);

    cv::waitKey();
    return 0;
}
