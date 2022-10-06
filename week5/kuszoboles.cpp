#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../lib/histo.hpp"

int main() {

    cv::Mat img = cv::imread(
            "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/dog.jpg",
            cv::IMREAD_GRAYSCALE
    );
    Histo::showHisto(img, "eredeti histo", 1);

    cv::Mat dest;
    std::cout << cv::threshold(img, dest, 100, 255, THRESH_BINARY);
    cv::medianBlur(dest, dest, 5);
    cv::imshow("kuszobolt", dest);

    cv::Mat dest2;
    cv::threshold(img, dest2, 100, 255, THRESH_TOZERO);

    cv::imshow("eredeti", img);
    cv::imshow("vagott", dest2);

    cv::waitKey();
    return 0;
}
