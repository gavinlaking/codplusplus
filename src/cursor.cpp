#include <iostream>
#include "cursor.h"

 // TODO: get height from Terminal
int Cursor::bottom()
{
  return cy = 25;
}

int Cursor::leftmost()
{
  return cx = 1;
}

// TODO: get width from Terminal
int Cursor::rightmost()
{
  return cx = 80;
}

// TODO: get bottom from Terminal
int Cursor::down()
{
  return cy++;
}

void Cursor::inspect()
{
  std::cout << "\e[s"; // store cursor
  std::cout << "\e[25;80H"; // position cursor
  std::cout << " cx: " << std::to_string(cx);
  std::cout << " cy: " << std::to_string(cy);
  std::cout << "\e[u"; // restore cursor
}

unsigned Cursor::ix()
{
  // if (cx - 1 <= 0)
  // {
  //   return 1;
  // }
  // else
  // {
  //   return cx - 1;
  // }
  return (unsigned)cx - 1;
}

unsigned Cursor::iy()
{
  return (unsigned)cy - 1;
}

int Cursor::left()
{
  if (cx - 1 < 1)
  {
    return cx = 1;
  }
  else
  {
    return cx--;
  }
}

void Cursor::position(int n, int m)
{
  store();
  cy = (n < 1) ? 1 : n;
  cx = (m < 1) ? 1 : m;
  render();
}

void Cursor::restore()
{
  std::cout << "\e[u";
}

void Cursor::render()
{
  std::cout << "\e[";
  std::cout << std::to_string(cy);
  std::cout << ";";
  std::cout << std::to_string(cx);
  std::cout << "f"; // can be either 'f' or 'H'
}

// TODO: get width from Terminal
int Cursor::right()
{
  return cx++;
}

void Cursor::store()
{
  std::cout << "\e[s";
}

int Cursor::top()
{
  return cy = 1;
}

int Cursor::up()
{
  if (cy - 1 < 1)
  {
    return cy = 1;
  }
  else
  {
    return cy--;
  }
}
