/**
 * @file spaces.h
 * @author elizabeth hooton
 * @brief 
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SPACES_H
#define SPACES_H
#include <string>
#include <iostream>

namespace main_savitch_14{

    class Spaces{
        public:
            /**
             * @brief Construct a new Spaces object
             * 
             */
            Spaces();

            /**
             * @brief Set the Space object
             * 
             * @param r1 row 1
             * @param r2 row 2
             * @param r3 row 3
             */
            void setSpace(std::string r1, std::string r2, std::string r3);

            /**
             * @brief Set the Taken object
             * 
             * @param t 
             */
            void setTaken(int t) {taken = t;}
            
            /**
             * @brief Get the Row1 object
             * 
             * @return std::string 
             */
            std::string getRow1() const {return row1;}

            /**
             * @brief Get the Row2 object
             * 
             * @return std::string 
             */
            std::string getRow2() const {return row2;}

            /**
             * @brief Get the Row3 object
             * 
             * @return std::string 
             */
            std::string getRow3() const {return row3;}

            /**
             * @brief Get the Taken object
             * 
             * @return int 
             */
            int getTaken() const {return taken;}

        private:
            std::string row1; // first row of space
            std::string row2; // second row of space
            std::string row3; // third row of space
            int taken; // 0 for empty, 1 for p1 kitten, 2 for p1 cat, 3 for p2 kitten, 4 for 2 cat
    };

}

#endif