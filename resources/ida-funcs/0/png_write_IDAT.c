int __cdecl png_write_IDAT(int a1, unsigned __int8 *buf, unsigned int a3)
{
  int result; // eax
  unsigned int i; // [esp+4h] [ebp-10h]
  unsigned int v5; // [esp+8h] [ebp-Ch]
  unsigned int v6; // [esp+Ch] [ebp-8h]
  unsigned int v7; // [esp+10h] [ebp-4h]
  int v8; // [esp+10h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 4) == 0 && !*(_BYTE *)(a1 + 636) )
  {
    v7 = *buf;
    if ( (v7 & 0xF) != 8 || (v7 & 0xF0) > 0x70 )
      png_error(a1, (int)"Invalid zlib compression method or flags in IDAT");
    if ( a3 >= 2 && *(_DWORD *)(a1 + 232) < 0x4000u && *(_DWORD *)(a1 + 228) < 0x4000u )
    {
      v6 = *(_DWORD *)(a1 + 232)
         * ((*(unsigned __int8 *)(a1 + 316) * *(_DWORD *)(a1 + 228) * (unsigned int)*(unsigned __int8 *)(a1 + 319) + 15) >> 3);
      if ( *(_BYTE *)(a1 + 312) )
        v6 += (*(unsigned __int8 *)(a1 + 316) >= 8u ? 6 : 12) * ((unsigned int)(*(_DWORD *)(a1 + 232) + 7) >> 3);
      v5 = v7 >> 4;
      for ( i = 1 << ((*buf >> 4) + 7); v6 <= i && i >= 0x100; i >>= 1 )
        --v5;
      v8 = (16 * v5) | v7 & 0xF;
      if ( *buf != v8 )
      {
        *buf = v8;
        buf[1] = (buf[1] & 0xE0) + 31 - ((buf[1] & 0xE0u) + (v8 << 8)) % 0x1F;
      }
    }
  }
  sub_36AEC0((_DWORD *)a1, 1229209940, buf, a3);
  *(_DWORD *)(a1 + 108) |= 4u;
  *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 176);
  result = *(_DWORD *)(a1 + 180);
  *(_DWORD *)(a1 + 136) = result;
  return result;
}
