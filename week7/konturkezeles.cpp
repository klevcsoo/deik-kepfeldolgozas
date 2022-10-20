#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    cv::Mat img = cv::imread("/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/dog.jpg");
    cv::imshow("img", img);

    cv::Mat gray, bin_img;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::threshold(gray, bin_img, 120, 255, cv::THRESH_BINARY);
    cv::medianBlur(bin_img, bin_img, 5);

    std::vector<std::vector<cv::Point>> cont;
    cv::findContours(bin_img, cont, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    std::cout << "Kontúrok száma: " << cont.size() << std::endl;
    cv::Mat dest = img.clone();
    for (int i = 0; i < cont.size(); i++) {
        cv::drawContours(dest, cont, i, cv::Scalar(rand() & 255, rand() & 255, rand() & 255), 2);
    }

    cv::imshow("mask", bin_img);
    cv::imshow("dest", dest);

    cv::waitKey();
    return 0;
}

#pragma clang diagnostic pop
