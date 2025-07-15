int __cdecl png_formatted_warning(int a1, int a2, char *a3)
{
  _BYTE *j; // [esp+0h] [ebp-D8h]
  int i; // [esp+8h] [ebp-D0h]
  _BYTE v6[192]; // [esp+10h] [ebp-C8h] BYREF
  unsigned int v7; // [esp+D4h] [ebp-4h]

  v7 = 0;
  while ( v7 < 0xBF && *a3 )
  {
    if ( !a2 || *a3 != 64 || !a3[1] )
      goto LABEL_18;
    ++a3;
    for ( i = 0; byte_85E634[i] != *a3 && byte_85E634[i]; ++i )
      ;
    if ( i < 8 )
    {
      for ( j = (_BYTE *)(a2 + 32 * i); v7 < 0xBF && *j && (unsigned int)j < a2 + 32 * i + 32; ++j )
        v6[v7++] = *j;
      ++a3;
    }
    else
    {
LABEL_18:
      v6[v7++] = *a3++;
    }
  }
  v6[v7] = 0;
  return png_warning(a1, v6);
}
