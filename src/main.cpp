#include "easybmp.hpp"

class Box {
private:
  size_t width{};
  EasyBMP::RGBColor color{0, 0, 0};
  size_t offset =0;

public:
  Box(const size_t x) : width(x) {}
  Box(const size_t x, EasyBMP::RGBColor c) : width(x), color(c) {}
  void paint(EasyBMP::Image &im, const size_t dx, const size_t dy) {
    for (int y = 0; y < width; ++y) {
      for (int x = 0; x < width; ++x) {
        im.SetPixel(offset + dx * width + x, offset+ y + dy * width, color);
      }
    }
  }
  const size_t getWidth() { return width; }
  void setColor(EasyBMP::RGBColor x) { color = x; }
  void setOffset(size_t val){ offset = val;}
};

int main() {

  // size_t box = 1;
  size_t howManyBoxes = 10;

  EasyBMP::RGBColor black(0, 0, 0);
  EasyBMP::RGBColor white(255, 255, 255);
  EasyBMP::RGBColor final_color;

  Box myBox(50, white);
  size_t width = myBox.getWidth() * howManyBoxes;
  size_t offset = 30;
  
  
  // sizeX, sizeY, FileName, BackgroundColor
  EasyBMP::Image img(width + 2*offset, width + 2*offset, "sample.bmp", black);

  bool reverse = false;
  myBox.setOffset(offset);
  for (size_t j = 0; j < howManyBoxes; j++) {
    for (size_t i = 0; i < howManyBoxes; i++) {
      if (reverse) {
        // myBox.setColor(white);
        myBox.paint(img, i, j);
      }

      //   else
      //     myBox.setColor(black);

      reverse = not reverse;
    }
    reverse = not reverse;
  }
  img.Write();
  return 0;
}