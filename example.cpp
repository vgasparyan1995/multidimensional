#include "md_array.h"

int main()
{
    using ChessBoard = vg::md_array<int, 2, 8, 8>;
    using ChessBoards = vg::md_array<int, 3, 100, 8, 8>;

    constexpr ChessBoard chess_board = {
        std::array{ 5, 3, 3, 9, 10, 3, 3, 5 },
        std::array{ 1, 1, 1, 1,  1, 1, 1, 1 },
        std::array{ 0, 0, 0, 0,  0, 0, 0, 0 },
        std::array{ 0, 0, 0, 0,  0, 0, 0, 0 },
        std::array{ 0, 0, 0, 0,  0, 0, 0, 0 },
        std::array{ 0, 0, 0, 0,  0, 0, 0, 0 },
        std::array{ 1, 1, 1, 1,  1, 1, 1, 1 },
        std::array{ 5, 3, 3, 9, 10, 3, 3, 5 }
    };
    ChessBoards chess_boards;
    for (int i = 0; i < 100; ++i) {
        chess_boards[i] = chess_board;
    }
}
