#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "../lib/histo.hpp"

int main() {
    std::string p = "/Users/klevcsoo/Developer/deik-kepfeldolgozas/"
                    "week4/debrecen_deep.png";
    cv::Mat img = cv::imread(p, cv::IMREAD_GRAYSCALE);
    cv::imshow("img", img);
    Histo::showHisto(img, "eredeti histo");

    double ah, fh;
    cv::minMaxLoc(img, &ah, &fh);
    cv::Mat dest = (img - ah) * 255 / (fh - ah);
    cv::imshow("dest", dest);
    Histo::showHisto(dest, "dest histo", 1);

    cv::waitKey();
    return 0;
}
