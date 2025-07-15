int __cdecl png_handle_IHDR(int a1, int a2, int a3)
{
  unsigned int v4; // [esp+0h] [ebp-38h]
  char v5; // [esp+4h] [ebp-34h]
  char v6; // [esp+8h] [ebp-30h]
  char v7; // [esp+Ch] [ebp-2Ch]
  char v8; // [esp+10h] [ebp-28h]
  unsigned __int8 buf[4]; // [esp+14h] [ebp-24h] BYREF
  unsigned __int8 v10[12]; // [esp+18h] [ebp-20h] BYREF
  unsigned int uint_31; // [esp+28h] [ebp-10h]
  int v12; // [esp+2Ch] [ebp-Ch]
  int v13; // [esp+30h] [ebp-8h]
  int v14; // [esp+34h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) != 0 )
    png_error(a1, (int)"Out of place IHDR");
  if ( a3 != 13 )
    png_error(a1, (int)"Invalid IHDR chunk");
  *(_DWORD *)(a1 + 108) |= 1u;
  png_crc_read((_DWORD *)a1, buf, 13);
  png_crc_finish(a1, 0);
  uint_31 = png_get_uint_31(a1, buf);
  v12 = png_get_uint_31(a1, v10);
  v7 = v10[4];
  v8 = v10[5];
  v13 = v10[6];
  v6 = v10[7];
  v14 = v10[8];
  *(_DWORD *)(a1 + 228) = uint_31;
  *(_DWORD *)(a1 + 232) = v12;
  *(_BYTE *)(a1 + 316) = v7;
  *(_BYTE *)(a1 + 312) = v14;
  *(_BYTE *)(a1 + 315) = v8;
  *(_BYTE *)(a1 + 604) = v6;
  *(_BYTE *)(a1 + 636) = v13;
  v5 = *(_BYTE *)(a1 + 315);
  switch ( v5 )
  {
    case 2:
      *(_BYTE *)(a1 + 319) = 3;
      break;
    case 4:
      *(_BYTE *)(a1 + 319) = 2;
      break;
    case 6:
      *(_BYTE *)(a1 + 319) = 4;
      break;
    default:
      *(_BYTE *)(a1 + 319) = 1;
      break;
  }
  *(_BYTE *)(a1 + 318) = *(_BYTE *)(a1 + 319) * *(_BYTE *)(a1 + 316);
  if ( *(unsigned __int8 *)(a1 + 318) < 8u )
    v4 = (*(_DWORD *)(a1 + 228) * (unsigned int)*(unsigned __int8 *)(a1 + 318) + 7) >> 3;
  else
    v4 = *(_DWORD *)(a1 + 228) * (*(unsigned __int8 *)(a1 + 318) >> 3);
  *(_DWORD *)(a1 + 244) = v4;
  return png_set_IHDR((_DWORD *)a1, a2, uint_31, v12, v7, v8, v14, v13, v6);
}
