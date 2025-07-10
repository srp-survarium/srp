int __cdecl png_write_pCAL(_DWORD *a1, LPCSTR a2, int a3, int a4, int a5, int a6, char *lpString, int a8)
{
  int v8; // eax
  unsigned __int8 buf[4]; // [esp+0h] [ebp-28h] BYREF
  _BYTE v11[8]; // [esp+4h] [ebp-24h] BYREF
  void *pointer; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+14h] [ebp-14h]
  int v14; // [esp+18h] [ebp-10h]
  void *v15; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h]

  if ( a5 >= 4 )
    png_warning((int)a1, "Unrecognized equation type for pCAL chunk");
  v13 = png_check_keyword((int)a1, a2, &pointer) + 1;
  v17 = (a6 != 0) + lstrlenA(lpString);
  v14 = v13 + v17 + 10;
  v15 = (void *)png_malloc((int)a1, 4 * a6);
  for ( i = 0; i < a6; ++i )
  {
    v8 = lstrlenA(*(LPCSTR *)(a8 + 4 * i));
    *((_DWORD *)v15 + i) = (i != a6 - 1) + v8;
    v14 += *((_DWORD *)v15 + i);
  }
  sub_36AD20(a1, 1883455820, v14);
  png_write_chunk_data(a1, (unsigned __int8 *)pointer, v13);
  png_save_int_32(buf, a3);
  png_save_int_32(v11, a4);
  v11[4] = a5;
  v11[5] = a6;
  png_write_chunk_data(a1, buf, 10);
  png_write_chunk_data(a1, (unsigned __int8 *)lpString, v17);
  png_free((int)a1, pointer);
  for ( i = 0; i < a6; ++i )
    png_write_chunk_data(a1, *(unsigned __int8 **)(a8 + 4 * i), *((_DWORD *)v15 + i));
  png_free((int)a1, v15);
  return png_write_chunk_end((int)a1);
}
