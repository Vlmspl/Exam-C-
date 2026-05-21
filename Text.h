#pragma once

struct Text {
  char* text;
  size_t length;
};

Text create(const char* text);
void print(Text& text);
void append(Text& text, const char* a);
void remove(Text& text);