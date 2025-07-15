int __cdecl png_write_iCCP(_DWORD *a1, LPCSTR lpString, int a3, unsigned int *a4, int a5)
{
  int result; // eax
  int v6; // [esp+0h] [ebp-20h]
  void *v7[5]; // [esp+4h] [ebp-1Ch] BYREF
  void *pointer; // [esp+18h] [ebp-8h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  v9 = 0;
  memset(v7, 0, sizeof(v7));
  result = png_check_keyword((int)a1, lpString, (int)&pointer);
  v6 = result;
  if ( result )
  {
    if ( a3 )
      png_warning((int)a1, "Unknown compression type in iCCP chunk");
    if ( !a4 )
      a5 = 0;
    if ( a5 > 3 )
      v9 = _byteswap_ulong(*a4);
    if ( v9 >= 0 )
    {
      if ( a5 >= v9 )
      {
        if ( a5 > v9 )
        {
          png_warning((int)a1, "Truncating profile to actual length in iCCP chunk");
          a5 = v9;
        }
        if ( a5 )
          a5 = sub_478660(a1, a4, a5, 0, v7);
        sub_4779E0(a1, 1766015824, v6 + a5 + 2);
        *((_BYTE *)pointer + v6 + 1) = 0;
        png_write_chunk_data(a1, (unsigned __int8 *)pointer, v6 + 2);
        if ( a5 )
          sub_478D30(a1, v7, a5);
        png_write_chunk_end((int)a1);
        return png_free((int)a1, pointer);
      }
      else
      {
        png_warning((int)a1, "Embedded profile length too large in iCCP chunk");
        return png_free((int)a1, pointer);
      }
    }
    else
    {
      png_warning((int)a1, "Embedded profile length in iCCP chunk is negative");
      return png_free((int)a1, pointer);
    }
  }
  return result;
}
