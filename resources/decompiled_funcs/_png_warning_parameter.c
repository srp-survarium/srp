unsigned int __cdecl png_warning_parameter(int a1, int a2, _BYTE *a3)
{
  unsigned int result; // eax

  if ( a2 > 0 && a2 <= 8 )
    return png_safecat(a1 + 32 * (a2 - 1), 0x20u, 0, a3);
  return result;
}
