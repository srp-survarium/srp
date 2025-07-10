__int16 __cdecl png_gamma_correct(int a1, unsigned int a2, int a3)
{
  if ( *(_BYTE *)(a1 + 316) == 8 )
    return (unsigned __int8)png_gamma_8bit_correct(a2, a3);
  else
    return png_gamma_16bit_correct(a2, a3);
}
