int __cdecl png_write_zTXt(_DWORD *a1, LPCSTR a2, char *lpString, int a4, int a5)
{
  int v6; // eax
  unsigned __int8 buf; // [esp+3h] [ebp-1Dh] BYREF
  void *pointer; // [esp+4h] [ebp-1Ch] BYREF
  _DWORD v9[5]; // [esp+8h] [ebp-18h] BYREF
  unsigned int v10; // [esp+1Ch] [ebp-4h]
  unsigned int v11; // [esp+34h] [ebp+14h]

  memset(v9, 0, sizeof(v9));
  v10 = png_check_keyword((int)a1, a2, &pointer);
  if ( !v10 )
    return png_free((int)a1, pointer);
  if ( lpString && *lpString && a5 != -1 )
  {
    v6 = lstrlenA(lpString);
    v11 = sub_478660((int)a1, (int)lpString, v6, a5, v9);
    sub_4779E0(a1, 2052348020, v10 + v11 + 2);
    png_write_chunk_data(a1, (unsigned __int8 *)pointer, v10 + 1);
    png_free((int)a1, pointer);
    buf = a5;
    png_write_chunk_data(a1, &buf, 1);
    sub_478D30((int)a1, (int)v9, v11);
    return png_write_chunk_end((int)a1);
  }
  else
  {
    png_write_tEXt(a1, (LPCSTR)pointer, lpString);
    return png_free((int)a1, pointer);
  }
}
