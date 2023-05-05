/**
 * @file spaces.cc
 * @author elizabeth hooton
 * @brief 
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "spaces.h"

namespace main_savitch_14{

    Spaces::Spaces(){ // sets all rows to empty, no spaces are taken
        row1 = "       ";
        row2 = "       ";
        row3 = "       ";
        taken = 0;
    }

    void Spaces::setSpace(std::string r1, std::string r2, std::string r3){ // sets all the rows to whatever is passed in
        row1 = r1;
        row2 = r2;
        row3 = r3;
    }
    
}