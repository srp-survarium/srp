int __cdecl png_handle_bKGD(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-1Ch]
  unsigned __int8 buf; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 v6; // [esp+5h] [ebp-17h]
  unsigned __int8 v7; // [esp+6h] [ebp-16h]
  unsigned __int8 v8; // [esp+7h] [ebp-15h]
  unsigned __int8 v9; // [esp+8h] [ebp-14h]
  unsigned __int8 v10; // [esp+9h] [ebp-13h]
  unsigned __int8 src[2]; // [esp+10h] [ebp-Ch] BYREF
  __int16 v12; // [esp+12h] [ebp-Ah]
  __int16 v13; // [esp+14h] [ebp-8h]
  __int16 v14; // [esp+16h] [ebp-6h]
  __int16 v15; // [esp+18h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before bKGD");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid bKGD after IDAT");
    return png_crc_finish(a1, a3);
  }
  if ( *(_BYTE *)(a1 + 315) == 3 && (*(_DWORD *)(a1 + 108) & 2) == 0 )
  {
    png_warning(a1, "Missing PLTE before bKGD");
    return png_crc_finish(a1, a3);
  }
  if ( a2 && (*(_DWORD *)(a2 + 8) & 0x20) != 0 )
  {
    png_warning(a1, "Duplicate bKGD chunk");
    return png_crc_finish(a1, a3);
  }
  if ( *(_BYTE *)(a1 + 315) == 3 )
  {
    v4 = 1;
  }
  else if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
  {
    v4 = 6;
  }
  else
  {
    v4 = 2;
  }
  if ( a3 != v4 )
  {
    png_warning(a1, "Incorrect bKGD chunk length");
    return png_crc_finish(a1, a3);
  }
  png_crc_read((_DWORD *)a1, &buf, v4);
  result = png_crc_finish(a1, 0);
  if ( !result )
  {
    if ( *(_BYTE *)(a1 + 315) == 3 )
    {
      src[0] = buf;
      if ( a2 && *(_WORD *)(a2 + 20) )
      {
        if ( buf >= (int)*(unsigned __int16 *)(a2 + 20) )
          return png_warning(a1, "Incorrect bKGD chunk index value");
        v12 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * buf);
        v13 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * buf + 1);
        v14 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * buf + 2);
      }
      else
      {
        v14 = 0;
        v13 = 0;
        v12 = 0;
      }
      v15 = 0;
    }
    else if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
    {
      src[0] = 0;
      v12 = v6 + (buf << 8);
      v13 = v8 + (v7 << 8);
      v14 = v10 + (v9 << 8);
      v15 = 0;
    }
    else
    {
      src[0] = 0;
      v15 = v6 + (buf << 8);
      v14 = v15;
      v13 = v15;
      v12 = v15;
    }
    return png_set_bKGD(a1, a2, src);
  }
  return result;
}
