/**
 * @file boop.h
 * @author elizabeth hooton
 * @brief 
 * @version 0.2
 * @date 2023-05-05
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
                 * @brief sends the move to the correct sub is_legal function
                 * 
                 * @param move string for move
                 * @return true if the move is legal
                 * @return false if the move is illegal
                 */
                bool is_legal(const std::string& move) const;

                /**
                 * @brief sub is_legal function for putting a new piece on the board
                 * 
                 * @param move the move that is being attempted
                 * @return true if the move is legal
                 * @return false if the move is illegal
                 */
                bool is_legal_new_piece(const std::string& move) const;

                /**
                 * @brief sub is_legal function for removing three pieces off of the board
                 * 
                 * @param move 
                 * @return true 
                 * @return false 
                 */
                bool is_legal_remove_three(const std::string& move) const;

                /**
                 * @brief sub is_legal function for removing one piece off of the board
                 * 
                 * @param move the move that is being attempted
                 * @return true if the move is legal
                 * @return false if the move is illegal
                 */
                bool is_legal_remove_one(const std::string& move) const;

                /**
                 * @brief sends the move to the correct make_move sub function
                 * 
                 * @param move the move that is being attempted
                 */
                void make_move(const std::string& move);

                /**
                 * @brief sub make_move function that puts a new piece on the board
                 * 
                 * @param move the move that is being attempted
                 */
                void make_move_new_piece(const std::string& move);

                /**
                 * @brief sub make_move function that removes three pieces from the board
                 * 
                 * @param move the move that is being attempted
                 */
                void make_move_remove_three(const std::string& move);

                /**
                 * @brief sub make_move function that removes one piece from the board
                 * 
                 * @param move the move that is being attempted
                 */
                void make_move_remove_one(const std::string& move);

                /**
                 * @brief resets everything to restart the game, called at the start of the game
                 * 
                 */
                void restart( );
                
                /**
                 * @brief checks if the game is over by checking if there is three in a row
                 * 
                 * @return true if the game is over
                 * @return false if the game is not over
                 */
                bool is_game_over( ) const;

                /**
                 * @brief checks if the player needs to remove one kitten from the board
                 * 
                 * @return true if the player needs to remove one kitten from the board
                 * @return false if the player does not need to remove one kitten from the board
                 */
                bool isKitten() const;

                /**
                 * @brief checks if there are three in a row
                 * 
                 * @return true if there are three in a row, and those three are from the correct player
                 * @return false if there are not three in a row, or if those three are not from the correct player
                 */
                bool check();

                /**
                 * @brief computes all possible moves for the computer to play
                 * 
                 * @param moves queue to put the legal moves in
                 */
                void compute_moves(std::queue<std::string>& moves) const;
                
                /**
                 * @brief boops all needed pieces
                 * 
                 * @param row the row the piece placed is in
                 * @param column the column the piece placed is in
                 */
                void boopThePieces(int row, int column);
                
                /**
                 * @brief returns who is winning
                 * 
                 * @return game::who who is winning
                 */
                game::who winning( ) const;
                
                /**
                 * @brief evaluates a move so the computer can decide what move to make
                 * 
                 * @return int the value assigned to the move
                 */
                int evaluate( ) const;

                /**
                 * @brief checks for three in a row
                 * 
                 * @return int based on how beneficial having three in a row is to the computer
                 */
                int checkForComp() const;

                /**
                 * @brief checks for two in a row
                 * 
                 * @return int based on how beneficial having two in a row is to the computer
                 */
                int checkForComp2() const;

                /**
                 * @brief Get the user move object
                 * 
                 * @return std::string the user move
                 */
                std::string get_user_move( ) const;

                /**
                 * @brief returns a clone of the game
                 * 
                 * @return game* clone
                 */
                game* clone( ) const {return new Boop(*this);}    

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