#include "GameBoard.h"

#include <utility>
#include <cstdlib>
#include <stdexcept>

GameBoard::GameBoard(size_t width, size_t height)
	:mWidth(width), mHeight(height)
{ 
	try{
		mCells = new GamePiece*[mWidth];
		for(size_t i=0; i<mWidth; i++)
		{
			mCells[i] = new GamePiece[mHeight];
			std::cout << i << " ";
		}
	}	catch (...)	{
		cleanup();
		std::throw_with_nested(std::bad_alloc());
	}
}
GameBoard::GameBoard(const GameBoard& src)
	:GameBoard(src.mWidth, src.mHeight)
{
	for(size_t i=0; i<mWidth; i++)
	{
		for(size_t j=0; j<mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}
GameBoard::~GameBoard()
{
	cleanup();
}
GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	if(this == &rhs)
		return *this;
	GameBoard temp(rhs);
	swap(*this,temp);
	return *this;
}
		
GamePiece& GameBoard::at(size_t x, size_t y) noexcept
{
	return const_cast<GamePiece&>(((const GameBoard&)(*this)).at(x,y));
}
const GamePiece& GameBoard::at(size_t x, size_t y) const noexcept
{
	try{
		verifyCoord(x,y);
	} catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		return mCells[0][0];		
	}
	return mCells[x][y];
}
		
void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap;
	
	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

void GameBoard::cleanup()
{
	for(size_t i=0; i<mWidth; i++)
		delete[] mCells[i];
	delete[] mCells;
	mCells = nullptr;
	mWidth = 0;
	mHeight = 0;
}

void GameBoard::verifyCoord(size_t x, size_t y) const
{
	if(x >= mWidth)
		throw std::out_of_range("x coord over width");
	if(y >= mHeight)
		throw std::out_of_range("y coord over height");
}
