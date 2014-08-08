/**
 *  Michael Dorst
 *  Assignment 3
 *  Used Car Dealership
 *
 *  car.h
 */

#ifndef Used_Car_Dealership__car_h
#define Used_Car_Dealership__car_h

#include "date.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <random>
#include <ciso646>

class random_generator {
    std::mt19937 generator;
    std::uniform_int_distribution<uint32_t> distribution;
public:
    random_generator();
    uint32_t operator()();
};

class car_t {
public:
    typedef uint32_t inv_num_t;
    
private:
    static random_generator rand;
    inv_num_t inv_num;
    date_t _date;
    std::string plate_number;
    std::string description;
    
    void capitolize_plate_number();
    
public:
    
    car_t(const std::string& pn, const std::string& dscptn, const date_t& date);
    car_t(std::string&& pn, std::string&& dscptn, const date_t& date);
    
    inv_num_t inventory_number()const;
    date_t date()const;
    
    friend std::ostream& operator << (std::ostream&, const car_t&);
    
};

#endif
