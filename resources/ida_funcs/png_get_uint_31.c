int __cdecl png_get_uint_31(int a1, unsigned __int8 *a2)
{
  if ( a2[3] + (a2[2] << 8) + (a2[1] << 16) + (*a2 << 24) > 0x7FFFFFFFu )
    png_error(a1, (int)"PNG unsigned integer out of range");
  return a2[3] + (a2[2] << 8) + (a2[1] << 16) + (*a2 << 24);
}
