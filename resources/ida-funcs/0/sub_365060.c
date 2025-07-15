int __cdecl sub_365060(int a1, unsigned __int8 *a2)
{
  if ( a2[3] + (a2[2] << 8) + (a2[1] << 16) + (*a2 << 24) <= 0x7FFFFFFFu )
    return a2[3] + (a2[2] << 8) + (a2[1] << 16) + (*a2 << 24);
  if ( a1 )
    png_warning(a1, "PNG fixed point integer out of range");
  return -1;
}
