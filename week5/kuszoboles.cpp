#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    cv::VideoCapture capture;
    capture.open("/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/sas.avi");
    if (!capture.isOpened()) {
        std::cout << "Nem nyitható" << std::endl;
        return -1;
    }

    cv::Mat img, gray, mask, dest;
    const int target_fps = 1000 / 30;
    while (true) {
        capture >> img;
        if (img.empty()) {
            break;
        }

        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        cv::inRange(gray, 100, 155, mask);
        cv::medianBlur(mask, mask, 9);
        dest = img.clone();
        dest.setTo(0, mask);

        cv::imshow("sas", dest);
        cv::waitKey(target_fps);
    }

    return 0;
}
