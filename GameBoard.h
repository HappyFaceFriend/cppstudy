#include <iostream>

class GamePiece {
	public:
		char c = '_';
};

class GameBoard
{
	public:
		static const size_t kDefaultWidth = 100;
		static const size_t kDefaultHeight = 100;
		
		explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
		GameBoard(const GameBoard& src);
		virtual ~GameBoard();
		GameBoard& operator=(const GameBoard& rhs);
		
		GamePiece& at(size_t x, size_t y) noexcept;
		const GamePiece& at(size_t x, size_t y) const noexcept;
		
		size_t getHeight() const noexcept { return mHeight; }
		size_t getWidth() const noexcept { return mWidth; }
		
		friend void swap(GameBoard& first, GameBoard& second) noexcept;
	
	private:
		GamePiece** mCells = nullptr;
		size_t mWidth = 0, mHeight = 0;
		void cleanup();
		void verifyCoord(size_t x, size_t y) const;

};
