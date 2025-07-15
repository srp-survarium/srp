long double __cdecl _float32_unpack(int val)
{
  double x; // [esp+Ch] [ebp-Ch]

  x = (double)(val & 0x1FFFFF);
  if ( val < 0 )
    x = -(double)(val & 0x1FFFFF);
  return ldexp(x, ((val >> 21) & 0x3FFu) - 788);
}
