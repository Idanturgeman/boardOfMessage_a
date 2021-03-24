#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
using namespace ariel;

void Board::resize(unsigned int row, unsigned col){
    board.resize(col, vector<char>(row, '_'));    
    for(int i = 0; i <= length; i++)
    {
    	board.at(i).resize(row, '_');
    }
    length = col-1;
    height = row-1;
}


void Board::show(){
    for(int i = 0; i <= length; i++)
    {
        for(int j = 0; j <= height; j++)
        {
             cout << board.at(i).at(j);
        }
        cout << "\n";
    }    
}


string Board::read(unsigned int row, unsigned int col, Direction dirc, unsigned int len){
    if(len == 0)
    {
    	throw invalid_argument("message length must be greater than 0");
    }
    string msg;
    
    if(col <= length && row <= height)
    {
        msg = board.at(col).at(row);
    }
   
    else
    {
        msg = "_";
        for(int i = 1; i < len; i++)
        {
            msg += "_";
        }
        return msg;
    }
    
    if(dirc == Direction::Vertical)
    {
        for(unsigned int r = row+1; r < row+len && r <= height; r++)
        {
            msg += board.at(col).at(r);
        }
    }
    else if(dirc == Direction::Horizontal)
    {
        for(unsigned int c = col+1; c < col+len && c <= length; c++)
        {
            msg += board.at(c).at(row);
        }
    }
    else
    {
            throw invalid_argument("Invalid direction");	
    }
    int msg_len = msg.size();
    if(msg_len < len)
    {
        for(int i = msg_len; i < len; i++)
        {
            msg += "_";
     	}  
    }
    return msg;
}



void Board::post(unsigned int row, unsigned int col, Direction dirc, string msg){
    int size = msg.size();
    if(size == 0)
    {
    	throw invalid_argument("empty message");
    }
    if(dirc == Direction::Horizontal)
    {
        if(col+size-1 > length)
        {
            resize(max(row,height)+1, col+size);
        }
        for(int i = 0; i < size; i++)
        {
            board.at(col+i).at(row) = msg.at(i);
        }
    }
    else if(dirc == Direction::Vertical)
    {
        if(row+size-1 > height)
        {
            resize(row+size, max(col,length)+1);
        }
        for(int i = 0; i < size; i++)
        {
            board.at(col).at(row+i) = msg.at(i);
        }
    }
    else
    {
    	    throw invalid_argument("Invalid direction");
    }
}




            

