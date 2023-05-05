/**
 * @file boop.h
 * @author elizabeth hooton
 * @brief 
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BOOP_H
#define BOOP_H

#include "game.h"
#include "spaces.h"

#include <iostream>
#include <queue>

namespace main_savitch_14{

    class Boop:public game{

            public:
                static const int SIZE = 6; // size of board

                /**
                 * @brief displays the board
                 * 
                 */
                void display_status( ) const;

                /**
                 * @brief returns if a move is legal based on the move type
                 * 
                 * @param move 
                 * @return true 
                 * @return false 
                 */
                bool is_legal(const std::string& move) const;

                bool is_legal_new_piece(const std::string& move) const;

                bool is_legal_remove_three(const std::string& move) const;

                bool is_legal_remove_one(const std::string& move) const;

                /**
                 * @brief makes the player's move
                 * 
                 * @param move 
                 */
                void make_move(const std::string& move);

                void make_move_new_piece(const std::string& move);
                void make_move_remove_three(const std::string& move);
                void make_move_remove_one(const std::string& move);

                /**
                 * @brief (re)starts the game
                 * 
                 */
                void restart( );
                
                /**
                 * @brief Checks to see if anyone has three cats in a row
                 * 
                 * @return true 
                 * @return false 
                 */
                bool is_game_over( ) const;

                bool isKitten() const;

                bool check();

                void compute_moves(std::queue<std::string>& moves) const;

                /**
                 * @brief Checks all the spaces directly next to the places piece to see where they should be booped.
                 * 
                 * @param row row of the array
                 * @param column column of the array
                 */
                void boopThePieces(int row, int column);

                /**
                 * @brief Uses almost the same code from is_game_over, but it keeps track of who's cats are 3 in a row.
                 * It returns HUMAN, NEUTRAL, or COMPUTER, depending on who is winning
                 * 
                 * @return game::who 
                 */
                game::who winning( ) const;

                // STUB FUNCTIONS
                game* clone( ) const {return new Boop(*this);}
                int evaluate( ) const;

                

            protected:
                Spaces board[SIZE][SIZE]; // [row][column]

                int turnType; // keeps track of what kind of turn it is, 0 = new piece, 1 = removing 1, 3 = remove 3

                int p1Kittens; // player 1's kittens
                int p1Cats; // player 1's cats

                int p2Kittens; // player 2's kittens
                int p2Cats; // player 2's cats

                who columnPerson; // these are all for the winning function when keeping track of
                who rowPerson; // who's cats are 3 in a row
                who diagonalPerson;
                who diagonalPerson2;
                who diagonalPerson3;
                who diagonalPerson4;
                who complete;

                bool isColumn; // if the column is 3 in a row
                bool isRow; // if the row is 3 in a row
                bool isDiagonal; // if one of the diagonals is 3 in a row
                bool isDiagonal2; // if one of the diagonals is 3 in a row
                bool isDiagonal3; // if one of the diagonals is 3 in a row
                bool isDiagonal4; // if one of the diagonals is 3 in a row
                
    };
    
}
#endif