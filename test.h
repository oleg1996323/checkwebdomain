#pragma once
#include <iostream>
#include <cassert>
#include <fstream>
#include "domain.h"
#include "reading.h"
#include "log_duration.h"

void TestCompareResults(){
    {
        LOG_DURATION("Test");
        ifstream input("bin/in_test_10.txt",ios::in);
        ifstream output("bin/out_test_10.txt",ios::in);
        //ifstream input("bin/input_hard.txt",ios::in);
        //ifstream output("bin/output_hard.txt",ios::in);

        if(!input.is_open() || !output.is_open())
            throw std::runtime_error("Not open files");
        
        const std::vector<Domain> forbidden_domains = ReadDomains(input, ReadNumberOnLine<size_t>(input));
        DomainChecker checker(forbidden_domains.begin(), forbidden_domains.end());
        const std::vector<Domain> test_domains = ReadDomains(input, ReadNumberOnLine<size_t>(input));

        string etalon;
        int count_line=0;

        for (const Domain& domain : test_domains) {
            ostringstream output_test;
            if(count_line==0){
                int num=count_line;
                num=num;
            }
            output_test << (checker.IsForbidden(domain) ? "Bad"sv : "Good"sv);
            output>>etalon;
            ++count_line;
            
            //std::cout<<"Line "<<count_line<<". "<<output_test.str()<<" / "<<etalon<<endl;
            if(output_test.str()!=etalon){
                throw std::invalid_argument(output_test.str()+"!="s+etalon);
            }
            getline(output,etalon);  
        }
    }
    
}