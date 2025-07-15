int __cdecl png_set_tIME(int a1, int a2, unsigned __int8 *src)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      result = a1;
      if ( (*(_DWORD *)(a1 + 108) & 0x200) == 0 )
      {
        if ( src[2]
          && src[2] <= 0xCu
          && src[3]
          && src[3] <= 0x1Fu
          && src[4] <= 0x17u
          && src[5] <= 0x3Bu
          && src[6] <= 0x3Cu )
        {
          memcpy((unsigned __int8 *)(a2 + 60), src, 8u);
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
