__int16 __cdecl png_gamma_16bit_correct(unsigned int a1, int a2)
{
  double v2; // st7

  if ( !a1 || a1 >= 0xFFFF )
    return a1;
  v2 = pow((double)a1 / 65535.0, (double)a2 * 0.00001);
  return (int)floor(v2 * 65535.0 + 0.5);
}
