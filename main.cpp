#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int countNumberOfObjects(cv::Mat src){
    cv::Mat dst;
    // Convert to binary image
    threshold(src, dst, 128, 255, cv::THRESH_BINARY);

    // Remove any random white pixels - noise
    erode(dst, dst, cv::Mat(), cv::Point(-1, -1), 3);

    imshow("Binary image", dst);
    cv::waitKey(0);
    cv::Mat labels, stats, centroids;
    int nLabels = connectedComponentsWithStats(dst, labels, stats, centroids);

    // Color the objects - with random colors
    cv::Mat output = cv::Mat::zeros(src.size(), CV_8UC3);
    for(int i = 1; i < nLabels; i++){
        cv::Mat mask = labels == i;
        cv::Vec3b color(rand() & 255, rand() & 255, rand() & 255);
        output.setTo(color, mask);
    }
    imshow("Output image", output);
    cv::waitKey(0);
    return nLabels - 1;
}

int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cout << "Usage: ./main <imageFile>" << std::endl;
        return -1;
    }
    cv::Mat src = imread(argv[1], cv::IMREAD_GRAYSCALE);
    imshow("Input image", src);
    cv::waitKey(0);
    std::cout << "Number of objects: ";
    std::cout << countNumberOfObjects(src);
    std::cout << std::endl;
}
