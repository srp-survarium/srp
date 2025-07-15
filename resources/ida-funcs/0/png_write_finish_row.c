void __cdecl png_write_finish_row(int a1)
{
  unsigned int v1; // [esp+0h] [ebp-8h]
  int v2; // [esp+4h] [ebp-4h]

  if ( ++*(_DWORD *)(a1 + 252) >= *(_DWORD *)(a1 + 236) )
  {
    if ( !*(_BYTE *)(a1 + 312) )
      goto LABEL_24;
    *(_DWORD *)(a1 + 252) = 0;
    if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
    {
      ++*(_BYTE *)(a1 + 313);
    }
    else
    {
      do
      {
        if ( (unsigned __int8)++*(_BYTE *)(a1 + 313) >= 7u )
          break;
        *(_DWORD *)(a1 + 240) = (*(_DWORD *)(a1 + 228)
                               + (unsigned __int8)byte_6F4210[*(unsigned __int8 *)(a1 + 313)]
                               - 1
                               - (unsigned int)(unsigned __int8)byte_6F4208[*(unsigned __int8 *)(a1 + 313)])
                              / (unsigned __int8)byte_6F4210[*(unsigned __int8 *)(a1 + 313)];
        *(_DWORD *)(a1 + 236) = (*(_DWORD *)(a1 + 232)
                               + (unsigned __int8)byte_6F4220[*(unsigned __int8 *)(a1 + 313)]
                               - 1
                               - (unsigned int)(unsigned __int8)byte_6F4218[*(unsigned __int8 *)(a1 + 313)])
                              / (unsigned __int8)byte_6F4220[*(unsigned __int8 *)(a1 + 313)];
        if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
          break;
      }
      while ( !*(_DWORD *)(a1 + 240) || !*(_DWORD *)(a1 + 236) );
    }
    if ( *(unsigned __int8 *)(a1 + 313) < 7u )
    {
      if ( *(_DWORD *)(a1 + 260) )
      {
        if ( *(unsigned __int8 *)(a1 + 317) * *(unsigned __int8 *)(a1 + 320) < 8 )
          v1 = (*(_DWORD *)(a1 + 228) * *(unsigned __int8 *)(a1 + 317) * (unsigned int)*(unsigned __int8 *)(a1 + 320) + 7) >> 3;
        else
          v1 = *(_DWORD *)(a1 + 228)
             * ((*(unsigned __int8 *)(a1 + 317) * (unsigned int)*(unsigned __int8 *)(a1 + 320)) >> 3);
        memset(*(_DWORD *)(a1 + 260), 0, v1 + 1);
      }
    }
    else
    {
LABEL_24:
      do
      {
        v2 = deflate((z_stream_s *)(a1 + 120), 4);
        if ( v2 )
        {
          if ( v2 != 1 )
          {
            if ( *(_DWORD *)(a1 + 144) )
              png_error(a1, *(_DWORD *)(a1 + 144));
            png_error(a1, (int)"zlib error");
          }
        }
        else if ( !*(_DWORD *)(a1 + 136) )
        {
          png_write_IDAT(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180));
          *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
          *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
        }
      }
      while ( v2 != 1 );
      if ( *(_DWORD *)(a1 + 136) < *(_DWORD *)(a1 + 180) )
        png_write_IDAT(a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136));
      sub_478FC0(a1);
      *(_DWORD *)(a1 + 164) = 0;
    }
  }
}
