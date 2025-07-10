int __cdecl png_write_sPLT(_DWORD *a1, int a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-24h]
  unsigned __int8 buf[2]; // [esp+4h] [ebp-20h] BYREF
  _BYTE v5[2]; // [esp+6h] [ebp-1Eh] BYREF
  _BYTE v6[2]; // [esp+8h] [ebp-1Ch] BYREF
  _BYTE v7[2]; // [esp+Ah] [ebp-1Ah] BYREF
  _BYTE v8[4]; // [esp+Ch] [ebp-18h] BYREF
  __int16 *i; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  void *pointer; // [esp+20h] [ebp-4h] BYREF

  v11 = 4 * (*(_BYTE *)(a2 + 4) != 8) + 6;
  v10 = *(_DWORD *)(a2 + 12) * v11;
  result = png_check_keyword((int)a1, *(LPCSTR *)a2, (int)&pointer);
  v3 = result;
  if ( result )
  {
    sub_36AD20(a1, 1934642260, result + v10 + 2);
    png_write_chunk_data(a1, (unsigned __int8 *)pointer, v3 + 1);
    png_write_chunk_data(a1, (unsigned __int8 *)(a2 + 4), 1);
    for ( i = *(__int16 **)(a2 + 8); (unsigned int)i < *(_DWORD *)(a2 + 8) + 10 * *(_DWORD *)(a2 + 12); i += 5 )
    {
      if ( *(_BYTE *)(a2 + 4) == 8 )
      {
        buf[0] = *(_BYTE *)i;
        buf[1] = *((_BYTE *)i + 2);
        v5[0] = *((_BYTE *)i + 4);
        v5[1] = *((_BYTE *)i + 6);
        png_save_uint_16(v6, i[4]);
      }
      else
      {
        png_save_uint_16(buf, *i);
        png_save_uint_16(v5, i[1]);
        png_save_uint_16(v6, i[2]);
        png_save_uint_16(v7, i[3]);
        png_save_uint_16(v8, i[4]);
      }
      png_write_chunk_data(a1, buf, v11);
    }
    png_write_chunk_end((int)a1);
    return png_free((int)a1, pointer);
  }
  return result;
}
