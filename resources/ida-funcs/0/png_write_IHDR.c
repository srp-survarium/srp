int __cdecl png_write_IHDR(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8)
{
  int result; // eax
  unsigned int v9; // [esp+0h] [ebp-24h]
  unsigned __int8 buf[4]; // [esp+10h] [ebp-14h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-10h] BYREF

  switch ( a5 )
  {
    case 0:
      switch ( a4 )
      {
        case 1:
        case 2:
        case 4:
        case 8:
        case 16:
          *(_BYTE *)(a1 + 319) = 1;
          break;
        default:
          png_error(a1, (int)"Invalid bit depth for grayscale image");
      }
      return result;
    case 2:
      if ( a4 != 8 && a4 != 16 )
        png_error(a1, (int)"Invalid bit depth for RGB image");
      *(_BYTE *)(a1 + 319) = 3;
      break;
    case 3:
      switch ( a4 )
      {
        case 1:
        case 2:
        case 4:
        case 8:
          *(_BYTE *)(a1 + 319) = 1;
          break;
        default:
          png_error(a1, (int)"Invalid bit depth for paletted image");
      }
      return result;
    case 4:
      if ( a4 != 8 && a4 != 16 )
        png_error(a1, (int)"Invalid bit depth for grayscale+alpha image");
      *(_BYTE *)(a1 + 319) = 2;
      break;
    case 6:
      if ( a4 != 8 && a4 != 16 )
        png_error(a1, (int)"Invalid bit depth for RGBA image");
      *(_BYTE *)(a1 + 319) = 4;
      break;
    default:
      png_error(a1, (int)"Invalid image color type specified");
  }
  if ( a6 )
  {
    png_warning(a1, "Invalid compression type specified");
    LOBYTE(a6) = 0;
  }
  if ( ((*(_DWORD *)(a1 + 600) & 4) == 0 || (*(_DWORD *)(a1 + 108) & 0x1000) != 0 || a5 != 2 && a5 != 6 || a7 != 64)
    && a7 )
  {
    png_warning(a1, "Invalid filter type specified");
    LOBYTE(a7) = 0;
  }
  if ( a8 >= 2 )
  {
    png_warning(a1, "Invalid interlace type specified");
    LOBYTE(a8) = 1;
  }
  *(_BYTE *)(a1 + 316) = a4;
  *(_BYTE *)(a1 + 315) = a5;
  *(_BYTE *)(a1 + 312) = a8;
  *(_BYTE *)(a1 + 604) = a7;
  *(_BYTE *)(a1 + 636) = a6;
  *(_DWORD *)(a1 + 228) = a2;
  *(_DWORD *)(a1 + 232) = a3;
  *(_BYTE *)(a1 + 318) = a4 * *(_BYTE *)(a1 + 319);
  if ( *(unsigned __int8 *)(a1 + 318) < 8u )
    v9 = (a2 * (unsigned int)*(unsigned __int8 *)(a1 + 318) + 7) >> 3;
  else
    v9 = a2 * (*(unsigned __int8 *)(a1 + 318) >> 3);
  *(_DWORD *)(a1 + 244) = v9;
  *(_DWORD *)(a1 + 240) = *(_DWORD *)(a1 + 228);
  *(_BYTE *)(a1 + 317) = *(_BYTE *)(a1 + 316);
  *(_BYTE *)(a1 + 320) = *(_BYTE *)(a1 + 319);
  png_save_uint_32(buf, a2);
  png_save_uint_32(v11, a3);
  v11[4] = a4;
  v11[5] = a5;
  v11[6] = a6;
  v11[7] = a7;
  v11[8] = a8;
  sub_477B80((_DWORD *)a1, 1229472850, buf, 13);
  *(_DWORD *)(a1 + 152) = png_zalloc;
  *(_DWORD *)(a1 + 156) = png_zfree;
  *(_DWORD *)(a1 + 160) = a1;
  if ( !*(_BYTE *)(a1 + 314) )
  {
    if ( *(_BYTE *)(a1 + 315) == 3 || *(unsigned __int8 *)(a1 + 316) < 8u )
      *(_BYTE *)(a1 + 314) = 8;
    else
      *(_BYTE *)(a1 + 314) = -8;
  }
  if ( (*(_DWORD *)(a1 + 112) & 1) == 0 )
    *(_DWORD *)(a1 + 204) = *(unsigned __int8 *)(a1 + 314) != 8;
  if ( (*(_DWORD *)(a1 + 112) & 2) == 0 )
    *(_DWORD *)(a1 + 188) = -1;
  if ( (*(_DWORD *)(a1 + 112) & 4) == 0 )
    *(_DWORD *)(a1 + 200) = 8;
  if ( (*(_DWORD *)(a1 + 112) & 8) == 0 )
    *(_DWORD *)(a1 + 196) = 15;
  if ( (*(_DWORD *)(a1 + 112) & 0x10) == 0 )
    *(_DWORD *)(a1 + 192) = 8;
  if ( (*(_DWORD *)(a1 + 112) & 0x1000000) == 0 )
    *(_DWORD *)(a1 + 224) = 0;
  if ( (*(_DWORD *)(a1 + 112) & 0x2000000) == 0 )
    *(_DWORD *)(a1 + 208) = *(_DWORD *)(a1 + 188);
  if ( (*(_DWORD *)(a1 + 112) & 0x4000000) == 0 )
    *(_DWORD *)(a1 + 220) = *(_DWORD *)(a1 + 200);
  if ( (*(_DWORD *)(a1 + 112) & 0x8000000) == 0 )
    *(_DWORD *)(a1 + 216) = *(_DWORD *)(a1 + 196);
  if ( (*(_DWORD *)(a1 + 112) & 0x10000000) == 0 )
    *(_DWORD *)(a1 + 212) = *(_DWORD *)(a1 + 192);
  result = a1;
  *(_DWORD *)(a1 + 184) = 0;
  *(_DWORD *)(a1 + 108) = 1;
  return result;
}
