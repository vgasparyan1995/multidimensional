#include "md_array.h"
#include "md_vector.h"

int main()
{
    // md_array
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

    // md_vector
    using Pixel = vg::md_array<unsigned char, 1, 3>;
    using Images = vg::md_vector<Pixel, 3>;

    size_t width = 1024;
    size_t height = 720;
    size_t num_wallpapers = 100;
    Images wallpapers{ num_wallpapers, { height, { width, Pixel{} } } };
    for (size_t i = 0; i < num_wallpapers; ++i) {
        for (size_t r = 0; r < height; ++r) {
            for (size_t c = 0; c < width; ++c) {
                wallpapers[i][r][c][0] = 255;
                wallpapers[i][r][c][1] = 0;
                wallpapers[i][r][c][2] = 0;
            }
        }
    }
}
