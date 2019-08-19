#include "easybmp.hpp"

class Box {
private:
  size_t width{};
  EasyBMP::RGBColor color{0,0,0};

public:
  Box(const size_t x) : width(x) {}
  Box(const size_t x, EasyBMP::RGBColor c):width(x), color(c){}
  void paint(EasyBMP::Image &im, const size_t dx, const size_t dy){
    for (int y = 0; y < width; ++y) {
        for (int x = 0; x < width; ++x) {
          im.SetPixel(dx * width + x, y + dy * width, color);
        }
      }
  }
  const size_t getWidth() { return width;}
  void setColor(EasyBMP::RGBColor x){color = x;}
};

int main() {
  
  //size_t box = 1;
  size_t howManyBoxes = 10;
  
  EasyBMP::RGBColor black(0, 0, 0);
  EasyBMP::RGBColor white(255, 255, 255);
  EasyBMP::RGBColor final_color;


  Box myBox(50, white);
  size_t width = myBox.getWidth() * howManyBoxes;
  // sizeX, sizeY, FileName, BackgroundColor
  EasyBMP::Image img(width, width, "sample.bmp", black);

  bool reverse = false;
  size_t offset = 0;
  for (size_t j = 0; j < howManyBoxes; j++) {
    for (size_t i = 0; i < howManyBoxes; i++) {
      if (reverse){
        //myBox.setColor(white);
        myBox.paint(img,i,j);
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