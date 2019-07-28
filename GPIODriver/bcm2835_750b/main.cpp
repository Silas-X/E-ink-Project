#include <bcm2835.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "epd7in5b.h"
#include "epd7in5bpaint.h"
#include "imagedata.h"
using std::cin;
using std::cout;
using std::endl;

void showStart(Epd& epd) {
  unsigned char* frame_buffer =
      (unsigned char*)malloc(epd.width / 2 * epd.height);
  Paint paint(frame_buffer, epd.width, epd.height);
  paint.Clear(EPDPAINT_WHITE);
  paint.DrawFilledRectangle(0, 0, 640, 384, EPDPAINT_RED);
  paint.DrawStringAt(40, 0, "Welcome To The Supermarket Label System", &Font20,
                     EPDPAINT_WHITE);
  paint.DrawStringAt(14, 192, "Press Any Key To Show The Demo Part", &Font24,
                     EPDPAINT_WHITE);
  epd.DisplayFrame1(frame_buffer);
  sleep(1);
  char ctl;
cin>>ctl;
std::cout<<"Process Continue"<<std::endl;
  free(frame_buffer);
}

int main(void) {
  Epd epd;
  if (epd.Init() != 0) {
    printf("e-Paper init failed\n");
    return -1;
  }
  showStart(epd);
  unsigned char* frame_buffer =
      (unsigned char*)malloc(epd.width / 2 * epd.height);
  Paint paint(frame_buffer, epd.width, epd.height);
  paint.Clear(EPDPAINT_WHITE);
  epd.DisplayFrame(IMAGE_DATA);
  free(frame_buffer);
  return 0;
}
