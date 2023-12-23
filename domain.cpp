#include "domain.h"
#include "log_duration.h"

using namespace std;

using namespace std::literals;


bool Domain::IsSubDomain(const Domain& other_domain) const{
    if(other_domain.domain.size()<domain.size()){
        auto pos = domain.find(other_domain.domain);
        if(pos!=domain.npos && pos==0){
            if(domain.at(other_domain.domain.size())=='.')
                return true;
            else return false;
        }
        else
            return false;
    }
    else if(domain == other_domain.domain)
        return true;
    else
        return false;
}


bool DomainChecker::IsForbidden(const Domain& domain) const{
    auto first_pos=std::lower_bound(domains_.begin(),domains_.end(),Domain(std::move(domain.GetDomain().substr(0,1))));
    if(first_pos!=domains_.end())
        for(auto super_domain=first_pos;
                    super_domain!=domains_.end() && super_domain->GetDomain().at(0)==domain.GetDomain().at(0);
                    ++super_domain){
            if(domain.IsSubDomain(*super_domain))
                return true;
        }
    return false;
}
