unsigned int __cdecl png_write_tEXt(_DWORD *a1, LPCSTR a2, char *lpString)
{
  unsigned int result; // eax
  void *pointer; // [esp+0h] [ebp-8h] BYREF
  unsigned int v5; // [esp+4h] [ebp-4h]
  int v7; // [esp+1Ch] [ebp+14h]

  result = png_check_keyword((int)a1, a2, &pointer);
  v5 = result;
  if ( result )
  {
    if ( lpString && *lpString )
      v7 = lstrlenA(lpString);
    else
      v7 = 0;
    sub_36AD20(a1, 1950701684, v5 + v7 + 1);
    png_write_chunk_data(a1, (unsigned __int8 *)pointer, v5 + 1);
    if ( v7 )
      png_write_chunk_data(a1, (unsigned __int8 *)lpString, v7);
    png_write_chunk_end((int)a1);
    return png_free((int)a1, pointer);
  }
  return result;
}
