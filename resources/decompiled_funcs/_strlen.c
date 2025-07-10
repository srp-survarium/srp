void __cdecl strlen(unsigned __int8 *buf)
{
  unsigned __int8 *v1; // ecx
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( *v1++ )
    {
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_1;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_1:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4
         && BYTE1(v4)
         && ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & v4) != 0
         && (v4 & 0xFF000000) != 0 );
  }
}
