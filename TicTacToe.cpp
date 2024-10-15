class TicTacToe
{
public:
    TicTacToe();
    void playGame();
private:
    vector<vector<char>> board;
    void printBoard();
    char checkWinner();
    void makeMove(int row, int col);
    int minimax(bool isMaximizing);
    findBestMove();
};
