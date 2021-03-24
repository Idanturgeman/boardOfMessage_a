#pragma once

#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel {
    class Board{
    	unsigned int height = 10;	
        unsigned int length = 10;	

    	std::vector<std::vector<char>> board;   
    	void resize(unsigned int row, unsigned col);	
        public:
            Board(){
            	board = std::vector<std::vector<char>>(length+1, std::vector<char>(height+1, '_'));
            }
            void post(unsigned int row, unsigned int col, Direction dirc, std::string msg);
            std::string read(unsigned int row, unsigned int col, Direction dirc, unsigned int len);
            void show(); 
    };
}
