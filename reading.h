#pragma once
#include <vector>
#include <string>
#include "domain.h"

template<typename Number>
std::vector<Domain> ReadDomains(std::istream& input,Number number_domains){
    string line;
    
    std::vector<Domain> domains;
    std::string buffer;
    domains.reserve(number_domains);
    for(Number count=0;count!=number_domains && getline(input, line);++count){
        std::istringstream (line)>>buffer;
        std::reverse(buffer.begin(),buffer.end());
        domains.push_back(std::move(buffer));
    }
    
    return domains;
}

template <typename Number>
Number ReadNumberOnLine(istream& input) {
    string line;
    getline(input, line);

    Number num;
    std::istringstream(line) >> num;

    return num;
}