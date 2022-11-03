#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void fv(const cv::Mat uzenet, const cv::Mat eredeti, cv::Mat& result) {
    cv::Mat channels_u[3];
    cv::split(uzenet, channels_u);
    cv::Mat channels_e[3];
    cv::split(eredeti, channels_e);

    cv::Mat piros_kivonas = channels_u[2] - channels_e[2];
    cv::threshold(piros_kivonas, result, 0, 255, cv::THRESH_BINARY);
}

int main() {
    int ROWS = 9;
    int COLS = 4;
    uchar data[] = {
            240, 66, 196, 218, 104, 150, 238, 156, 20, 176, 198, 236,
            200, 33, 212, 108, 5, 189, 54, 205, 87, 244, 26, 166,
            58, 11, 27, 164, 88, 172, 202, 60, 40, 144, 47, 245,
            174, 29, 157, 160, 180, 128, 74, 42, 143, 228, 49, 233,
            246, 101, 171, 48, 11, 50, 14, 139, 185, 56, 134, 123,
            78, 111, 126, 0, 96, 116, 106, 30, 69, 112, 41, 149,
            162, 127, 101, 124, 152, 132, 24, 16, 14, 52, 253, 229,
            190, 205, 250, 192, 83, 234, 102, 75, 38, 4, 232, 62,
            170, 30, 188, 158, 84, 200, 136, 224, 194, 210, 2, 64
    };
    cv::Mat uzi(ROWS, COLS, CV_8UC3, data);
    uchar data2[] = {
            240, 66, 196, 218, 104, 150, 238, 156, 20, 176, 198, 236,
            200, 33, 212, 108, 5, 188, 54, 205, 86, 244, 26, 166,
            58, 11, 25, 164, 88, 172, 202, 60, 40, 144, 47, 243,
            174, 29, 155, 160, 180, 128, 74, 42, 143, 228, 49, 231,
            246, 101, 170, 48, 11, 50, 14, 139, 185, 56, 134, 122,
            78, 111, 125, 0, 96, 116, 106, 30, 69, 112, 41, 148,
            162, 127, 100, 124, 152, 132, 24, 16, 14, 52, 253, 228,
            190, 205, 250, 192, 83, 233, 102, 75, 37, 4, 232, 62,
            170, 30, 188, 158, 84, 200, 136, 224, 194, 210, 2, 64
    };
    cv::Mat eredeti(ROWS, COLS, CV_8UC3, data2);
    cv::Mat my_dest;
    fv(uzi, eredeti, my_dest);
    std::cout << my_dest << std::endl;
    return 0;
}
