#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
    cv::Mat m(2, 3, CV_8UC3);

    m.at<cv::Vec3b>(0, 0) = cv::Vec3b(0, 0, 255);
    m.at<cv::Vec3b>(0, 1) = cv::Vec3b(0, 255, 0);
    m.at<cv::Vec3b>(0, 2) = cv::Vec3b(255, 0, 0);

    m.at<cv::Vec3b>(1, 0) = cv::Vec3b(0, 0, 255);
    m.at<cv::Vec3b>(1, 1) = cv::Vec3b(39, 127, 255);
    m.at<cv::Vec3b>(1, 2) = cv::Vec3b(0, 255, 255);

    cv::namedWindow("sample", cv::WINDOW_NORMAL);
    cv::resizeWindow("sample", 1200, 800);
    cv::imshow("sample", m);
    cv::waitKey(10000);

    return 0;
}
