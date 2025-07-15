unsigned int __cdecl png_write_iTXt(_DWORD *a1, int a2, LPCSTR a3, LPCSTR a4, char *lpString, LPCSTR a6)
{
  unsigned int result; // eax
  int v7; // [esp+8h] [ebp-30h]
  unsigned __int8 buf[4]; // [esp+Ch] [ebp-2Ch] BYREF
  void *pointer; // [esp+10h] [ebp-28h] BYREF
  _DWORD v10[5]; // [esp+14h] [ebp-24h] BYREF
  void *v11; // [esp+28h] [ebp-10h] BYREF
  unsigned int v12; // [esp+2Ch] [ebp-Ch]
  unsigned int v13; // [esp+30h] [ebp-8h]
  int v14; // [esp+34h] [ebp-4h]

  pointer = 0;
  memset(&v10[2], 0, 12);
  v10[0] = 0;
  result = png_check_keyword((int)a1, a3, &pointer);
  v13 = result;
  if ( result )
  {
    v12 = png_check_keyword((int)a1, a4, &v11);
    if ( !v12 )
    {
      png_warning((int)a1, "Empty language field in iTXt chunk");
      v11 = 0;
      v12 = 0;
    }
    if ( lpString )
      v7 = lstrlenA(lpString);
    else
      v7 = 0;
    if ( a6 )
      v14 = lstrlenA(a6);
    else
      v14 = 0;
    v14 = sub_478660((int)a1, (int)a6, v14, a2 - 2, v10);
    sub_4779E0(a1, 1767135348, v14 + v7 + v13 + v12 + 5);
    png_write_chunk_data(a1, (unsigned __int8 *)pointer, v13 + 1);
    buf[0] = a2 != 1 && a2 != -1;
    buf[1] = 0;
    png_write_chunk_data(a1, buf, 2);
    buf[0] = 0;
    if ( v11 )
      png_write_chunk_data(a1, (unsigned __int8 *)v11, v12 + 1);
    else
      png_write_chunk_data(a1, buf, v12 + 1);
    if ( lpString )
      png_write_chunk_data(a1, (unsigned __int8 *)lpString, v7 + 1);
    else
      png_write_chunk_data(a1, buf, v7 + 1);
    sub_478D30((int)a1, (int)v10, v14);
    png_write_chunk_end((int)a1);
    png_free((int)a1, pointer);
    return png_free((int)a1, v11);
  }
  return result;
}
