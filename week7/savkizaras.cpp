#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

    cv::VideoCapture cap;
    cap.open("/Users/klevcsoo/Developer/deik-kepfeldolgozas/week5/sas.avi");

    if (!cap.isOpened()) {
        std::cout << "error" << std::endl;
        return -1;
    }

    cv::Mat img, gray, mask;
    int idx = 0;
    while (true) {
        cap >> img;
        if (img.empty())
            break;

        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        cv::inRange(gray, 100, 155, mask);

        cv::medianBlur(mask, mask, 5);

        mask = 255 - mask;
        cv::dilate(
                mask, mask,
                cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(13, 13))
        );

        std::vector<std::vector<cv::Point>> cont;
        cv::findContours(mask, cont, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
        cv::Mat small = img(cv::boundingRect(cont[0]));

        cv::imwrite(
                "/Users/klevcsoo/Developer/deik-kepfeldolgozas/week7/sas_output/"
                + std::to_string(idx) + ".png", small
        );
        idx++;

        cv::imshow("output_small", small);

        cv::waitKey(33);
    }
    cv::waitKey(0);

    return 0;
}
