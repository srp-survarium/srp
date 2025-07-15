int __cdecl png_crc_finish(int a1, unsigned int a2)
{
  int v3; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  for ( i = *(_DWORD *)(a1 + 180); a2 > i; a2 -= i )
    png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180));
  if ( a2 )
    png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 176), a2);
  if ( !png_crc_error(a1) )
    return 0;
  if ( ((*(_DWORD *)(a1 + 256) >> 29) & 1) != 0 )
    v3 = (*(_DWORD *)(a1 + 112) & 0x200) == 0;
  else
    v3 = *(_DWORD *)(a1 + 112) & 0x400;
  if ( v3 )
  {
    png_chunk_warning(a1, "CRC error");
    return 1;
  }
  else
  {
    png_chunk_benign_error(a1, "CRC error");
    return 0;
  }
}
