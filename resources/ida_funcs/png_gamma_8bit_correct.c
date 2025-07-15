char __cdecl png_gamma_8bit_correct(unsigned int a1, int a2)
{
  double v2; // st7

  if ( !a1 || a1 >= 0xFF )
    return a1;
  v2 = pow((double)a1 / 255.0, (double)a2 * 0.00001);
  return (int)floor(v2 * 255.0 + 0.5);
}
