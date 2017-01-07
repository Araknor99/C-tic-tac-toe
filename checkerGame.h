#ifndef CHECKERGAME_H
#define CHECKRGAME_H

class checkerGame
{
	public:
		checkerGame();
		void initBoard();
		void printBoard();
		void loopGame();
		void writeBoard(int x,int y);
		int checkWin();
	protected:
		char board[3][3] ;
		char turn;
		int trues = 1;
	private:

};

#endif // !CHECKERGAME_H

