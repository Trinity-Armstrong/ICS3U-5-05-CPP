// Copyright (c) 2019 Trinity Armstrong All rights reserved.
//
// Created by: Trinity Armstrong
// Created on: December 2019
// This program formats Canadian mailing addresses

#include <iostream>
#include <string>

std::string MailingAddress(std::string name,
                      std::string address,
                      std::string municipality,
                      std::string province,
                      std::string postalCode,
                      std::string apartmentNumber = "") {
    // This function formats the mailing address

    // Variables
    std::string postAddress;

    // Process
    if (apartmentNumber.size() != 0) {
        postAddress = name + "\n" + apartmentNumber + \
                      + "-" + address + "\n" + municipality \
                      + " " + province + "  " + postalCode;
    } else {
        postAddress = name + "\n" + address + "\n" + \
                      municipality + " " + province + \
                      "  " + postalCode;
    }
    return postAddress;
}

int main() {
    // This function gets information, calls other functions and prints address

    // Variables
    std::string userName;
    std::string userAddress;
    std::string question;
    std::string userMunicipality;
    std::string userProvince;
    std::string userPostalCode;
    std::string post;
    std::string userApartmentNumber = "";

    // Input
    std::cout << "This program formats Canadian mailing addresses." \
    << std::endl;
    std::cout << "Please enter the following information: " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Full name: " << std::endl;
    std::getline(std::cin, userName);
    std::cout << "Address (Street number & road): "<< std::endl;
    std::getline(std::cin, userAddress);
    std::cout << "Do you live in an apartment? (y/n): " << std::endl;
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Apartment number: " << std::endl;
        std::getline(std::cin, userApartmentNumber);
    }
    std::cout << "Municipality: " << std::endl;
    std::getline(std::cin, userMunicipality);
    std::cout << "Province/Territory (abbreviate): "
              << std::endl;
    std::getline(std::cin, userProvince);
    std::cout << "Postal code: " << std::endl;
    std::getline(std::cin, userPostalCode);;

    // Process
    if (userApartmentNumber != "") {
        post = MailingAddress(userName, userAddress, userMunicipality,
                              userProvince, userPostalCode,
                              userApartmentNumber);
    } else {
        post = MailingAddress(userName, userAddress, userMunicipality,
                              userProvince, userPostalCode);
    }

    // Output
    std::cout << "" << std::endl;
    std::cout << post << std::endl;
}
