#include <array>
#include <iostream>
#include <ranges>
#include <string_view>

namespace Utils {
  using std::array;

  template <size_t N> consteval array<char, N> multiplicate_char(const char letter) {
    array<char, N> arr{};
    arr.fill(letter);
    return arr;
  }

}  //  namespace Utils

int main() {
  using std::cout, std::endl, std::array, std::string_view;
  using std::views::iota;

  constexpr char block = '\xDB';  //  Full block character

  //  Draw a triangle
  []() {
    constexpr auto screen_buffer = []() consteval {
      constexpr uint_fast8_t width = 40;
      constexpr uint_fast8_t height = 20;

      constexpr array<char, width> row = Utils::multiplicate_char<width>(' ');
      array<array<char, width>, height> screen_buffer{};
      screen_buffer.fill(row);

      //  Calculate the triangle
      for (auto y_coord : iota(0U, height)) {
        for (auto x_coord = width / 2 - y_coord + 1; x_coord < width / 2 + y_coord; ++x_coord) {
          screen_buffer.at(y_coord).at(x_coord) = block;
        }
      }

      return screen_buffer;
    }();

    for (const auto& line : screen_buffer) {
      cout << string_view(line.data(), line.size()) << endl;
    }
  }();

  cout << endl << endl << endl;

  //  Draw a square
  []() {
    constexpr uint_fast8_t size = 20;
    constexpr auto square_line = Utils::multiplicate_char<size>(block);
    for ([[maybe_unused]] auto iterator : iota(0U, size)) {
      auto line = string_view(square_line.data(), square_line.size());
      cout << line << endl;
    }
  }();

  cout << endl << endl << endl;

  return EXIT_SUCCESS;
}