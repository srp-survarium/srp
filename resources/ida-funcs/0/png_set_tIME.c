int __cdecl png_set_tIME(int a1, int a2, const __m128i *src)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      result = a1;
      if ( (*(_DWORD *)(a1 + 108) & 0x200) == 0 )
      {
        if ( src->m128i_i8[2]
          && src->m128i_u8[2] <= 0xCu
          && src->m128i_i8[3]
          && src->m128i_u8[3] <= 0x1Fu
          && src->m128i_u8[4] <= 0x17u
          && src->m128i_u8[5] <= 0x3Bu
          && src->m128i_u8[6] <= 0x3Cu )
        {
          memcpy(a2 + 60, src, 8u);
          result = a2;
          *(_DWORD *)(a2 + 8) |= 0x200u;
        }
        else
        {
          return png_warning(a1, "Ignoring invalid time value");
        }
      }
    }
  }
  return result;
}
