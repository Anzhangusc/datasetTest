//=======================================================================
// Copyright (c) 2017 Adrian Schneider
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "mnist_reader.hpp"

int main(int argc, char* argv[]) {
    // MNIST_DATA_LOCATION set by MNIST cmake config
    std::string MNIST_DATA_LOCATION = "/Users/anzhang/xcodeProject/datasetTest";
    std::cout << "MNIST data directory: " << MNIST_DATA_LOCATION << std::endl;
    //std::ofstream out("/Users/anzhang/xcodeProject/datasetTest/out.txt");
    //std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    //std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
    // Load MNIST data
    mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t> dataset =
    mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);
    
    std::cout << "Nbr of training images = " << dataset.training_images.size() << std::endl;
    std::cout << "Nbr of training labels = " << dataset.training_labels.size() << std::endl;
    std::cout << "Nbr of test images = " << dataset.test_images.size() << std::endl;
    std::cout << "Nbr of test labels = " << dataset.test_labels.size() << std::endl;
    for(int i = 0 ; i <dataset.training_images[0].size();i++){
        //std::cout << std::fixed << std::setprecision(4);
        std::cout << std::left << std::setw(4)<< std::to_string(dataset.training_images[0][i]);
        if(i%28 == 27){
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout <<"The result for sample [0] : " << std::to_string(dataset.training_labels[0]) << std::endl;
    //std::cout.rdbuf(coutbuf);
    return 0;
}

