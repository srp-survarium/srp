long double __cdecl _frnd(long double x)
{
  long double result; // st7

  _ST7 = x;
  __asm { frndint }
  return result;
}
