#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>


#include "gen.h"
#include "Person.h"

class Person;

class PassTable{
public:
    PassTable():hash(nullptr){};

    PassTable(std::vector<std::shared_ptr<Person>> p_arr){
         hash = std::make_shared<Hash_table<int>>();
        for(size_t i = 0;i<p_arr.size();++i){
            hash->put(p_arr[i]->getId(), p_arr[i]->getPass());
        }
    }
    ~PassTable(){
        hash->clear();
    }

    std::string displayPasses(){
    return hash->disp();
    }

    bool check(std::string& id, unsigned int pass) {
            auto entry = hash->get(id);
            if (entry != nullptr) {
                if (entry->data == pass) {
                    return true;
                }
            }
            return false;
    }

    std::shared_ptr<Hash_table<int>> getHash(){
        return hash;
    }
private:
    std::shared_ptr<Hash_table<int>> hash;
};