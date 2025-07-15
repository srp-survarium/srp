_DWORD *__cdecl sub_478D30(int a1, int a2, unsigned int a3)
{
  int v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  unsigned int i; // [esp+8h] [ebp-14h]
  unsigned int v7; // [esp+Ch] [ebp-10h]
  unsigned int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  if ( *(_DWORD *)a2 )
    return png_write_chunk_data((_DWORD *)a1, *(unsigned __int8 **)a2, a3);
  if ( a3 >= 2 && *(_DWORD *)(a2 + 4) < 0x4000u && *(_DWORD *)(a1 + 180) > 1u )
  {
    if ( *(_DWORD *)(a2 + 8) )
      v8 = ***(unsigned __int8 ***)(a2 + 16);
    else
      v8 = **(unsigned __int8 **)(a1 + 176);
    if ( (v8 & 0xF) != 8 || (v8 & 0xF0) > 0x70 )
      png_error(a1, (int)"Invalid zlib compression method or flags in non-IDAT chunk");
    v7 = v8 >> 4;
    for ( i = 1 << ((v8 >> 4) + 7); *(_DWORD *)(a2 + 4) <= i && i >= 0x100; i >>= 1 )
      --v7;
    v9 = (16 * v7) | v8 & 0xF;
    if ( *(_DWORD *)(a2 + 8) )
    {
      if ( ***(unsigned __int8 ***)(a2 + 16) != v9 )
      {
        ***(_BYTE ***)(a2 + 16) = v9;
        v5 = *(_BYTE *)(**(_DWORD **)(a2 + 16) + 1) & 0xE0;
        *(_BYTE *)(**(_DWORD **)(a2 + 16) + 1) = v5 + 31 - (v5 + (v9 << 8)) % 0x1Fu;
      }
    }
    else
    {
      **(_BYTE **)(a1 + 176) = v9;
      v4 = *(_BYTE *)(*(_DWORD *)(a1 + 176) + 1) & 0xE0;
      *(_BYTE *)(*(_DWORD *)(a1 + 176) + 1) = v4 + 31 - (v4 + (v9 << 8)) % 0x1Fu;
    }
  }
  for ( j = 0; j < *(_DWORD *)(a2 + 8); ++j )
  {
    png_write_chunk_data((_DWORD *)a1, *(unsigned __int8 **)(*(_DWORD *)(a2 + 16) + 4 * j), *(_DWORD *)(a1 + 180));
    png_free(a1, *(void **)(*(_DWORD *)(a2 + 16) + 4 * j));
  }
  if ( *(_DWORD *)(a2 + 12) )
    png_free(a1, *(void **)(a2 + 16));
  if ( *(_DWORD *)(a1 + 136) < *(_DWORD *)(a1 + 180) )
    png_write_chunk_data((_DWORD *)a1, *(unsigned __int8 **)(a1 + 176), *(_DWORD *)(a1 + 180) - *(_DWORD *)(a1 + 136));
  return (_DWORD *)sub_478FC0(a1);
}
