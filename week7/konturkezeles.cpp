#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    cv::Mat img = cv::imread("/Users/klevcsoo/Developer/deik-kepfeldolgozas/week7/sajt.png");
    cv::imshow("img", img);

    cv::Mat gray, bin_img;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::threshold(gray, bin_img, 248, 255, cv::THRESH_BINARY_INV);
    cv::medianBlur(bin_img, bin_img, 5);

    std::vector<std::vector<cv::Point>> cont;
    cv::findContours(bin_img, cont, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat dest = img.clone();
    cv::drawContours(dest, cont, -1, cv::Scalar(0, 255, 0), 2);

    cv::imshow("mask", bin_img);
    cv::imshow("dest", dest);

    cv::waitKey();
    return 0;
}
