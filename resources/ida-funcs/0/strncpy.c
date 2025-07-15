void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( !count )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( !v8 )
        break;
      if ( !--v4 )
        return;
    }
    while ( --v4 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( !--v3 )
      return;
    if ( !v8 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( !--v3 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( !v9 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( !v7 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) == 0 )
      goto main_loop_2;
    if ( !(_BYTE)v11 )
      break;
    if ( !BYTE1(v11) )
    {
      *(_DWORD *)dest = (unsigned __int8)v11;
      goto fill_with_EOS_dwords;
    }
    if ( (v11 & 0xFF0000) == 0 )
    {
      *(_DWORD *)dest = (unsigned __int16)v11;
      goto fill_with_EOS_dwords;
    }
    if ( (v11 & 0xFF000000) == 0 )
    {
      *(_DWORD *)dest = v11;
      goto fill_with_EOS_dwords;
    }
main_loop_2:
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( !--v7 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 );
  }
  v4 &= 3u;
  if ( v4 )
    goto finish_loop;
}
