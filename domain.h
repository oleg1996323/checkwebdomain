#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <string_view>
#include <vector>
#include <cassert>


using namespace std;

using namespace std::literals;


class Domain {

    public:
    Domain(std::string&& str):domain(std::move(str)){
    }

    Domain()=default;

    bool operator==(const Domain& other) const {
        return domain==other.domain;
    }

    bool operator<(const Domain& other) const {
        return domain<other.domain;
    }

    bool operator>(const Domain& other) const {
        return !(this->domain<other.domain);
    }

    bool IsSubDomain(const Domain& other_domain) const;

    const std::string& GetDomain() const {
        return domain;
    }

    private:
    std::string domain;
};

class DomainChecker {
public:
    
    template<typename It>
    DomainChecker(It first,It last);
    // разработайте метод IsForbidden, возвращающий true, если домен запрещён

    bool IsForbidden(const Domain& domain) const;

    std::vector<Domain> domains_;
};

template<typename It>
DomainChecker::DomainChecker(It first,It last){
    domains_=std::vector(first,last);
    sort(domains_.begin(),domains_.end());
    auto last_value = std::unique(domains_.begin(),domains_.end());
    domains_.erase(last_value,domains_.end());
    assert(std::is_sorted(domains_.begin(),domains_.end()));
}