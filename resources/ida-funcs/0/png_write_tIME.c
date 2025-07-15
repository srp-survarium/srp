int __cdecl png_write_tIME(_DWORD *a1, int a2)
{
  unsigned __int8 buf[8]; // [esp+0h] [ebp-Ch] BYREF

  if ( *(unsigned __int8 *)(a2 + 2) > 0xCu
    || !*(_BYTE *)(a2 + 2)
    || *(unsigned __int8 *)(a2 + 3) > 0x1Fu
    || !*(_BYTE *)(a2 + 3)
    || *(unsigned __int8 *)(a2 + 4) > 0x17u
    || *(unsigned __int8 *)(a2 + 6) > 0x3Cu )
  {
    return png_warning((int)a1, "Invalid time specified for tIME chunk");
  }
  png_save_uint_16(buf, *(_WORD *)a2);
  buf[2] = *(_BYTE *)(a2 + 2);
  buf[3] = *(_BYTE *)(a2 + 3);
  buf[4] = *(_BYTE *)(a2 + 4);
  buf[5] = *(_BYTE *)(a2 + 5);
  buf[6] = *(_BYTE *)(a2 + 6);
  return sub_477B80(a1, 1950960965, buf, 7);
}
