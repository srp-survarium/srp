double __fastcall _float32_unpack(int val)
{
  long double x; // st7

  x = (double)(int)(((unsigned int)&loc_1FFFFE + 1) & val);
  if ( val < 0 )
    x = -x;
  return (float)ldexp(x, ((val >> 21) & 0x3FFu) - 788);
}
