#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    cv::Mat img = cv::imread("/Users/klevcsoo/Developer/deik-kepfeldolgozas/week7/sajt.png");

    cv::Mat gray, mask;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::threshold(gray, mask, 248, 255, cv::THRESH_BINARY_INV);
    cv::medianBlur(mask, mask, 5);

    std::vector<std::vector<cv::Point>> cont;
    std::vector<cv::Vec4i> hier;
    cv::findContours(mask, cont, hier, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    cv::Mat dest = img.clone();
    double cheese_area = 0, holes_area = 0;
    for (int i = 0; i < cont.size(); i++) {
        if (hier[i][3] == -1) {
            cheese_area += cv::contourArea(cont[i]);
            cv::drawContours(dest, cont, i, cv::Scalar(0, 255, 0), 2);
        } else {
            holes_area += cv::contourArea(cont[i]);
            cv::drawContours(dest, cont, i, cv::Scalar(255, 0, 0), 2);
        }
    }
    cv::putText(
            dest, "cheese: " + std::to_string(cheese_area), cv::Point(20, 20),
            cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1
    );
    cv::putText(
            dest, "holes " + std::to_string(holes_area), cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1
    );

    cv::imshow("cheese", dest);

    cv::waitKey();
    return 0;
}

#pragma clang diagnostic pop
