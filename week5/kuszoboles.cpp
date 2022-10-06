#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../lib/histo.hpp"

int main() {

    cv::Mat img = cv::imread(
            "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/madar.jpg",
            cv::IMREAD_COLOR
    );
    std::vector<cv::Mat> chs;
    cv::split(img, chs);

    cv::Mat mask, dest;
    cv::threshold(chs[0], mask, 120, 255, THRESH_BINARY);

    img.copyTo(dest, mask);
    cv::imshow("dest", dest);

    cv::waitKey();
    return 0;
}
