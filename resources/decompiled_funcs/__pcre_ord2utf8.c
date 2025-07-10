int __cdecl _pcre_ord2utf8(int a1, int a2)
{
  int j; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]
  _BYTE *v5; // [esp+14h] [ebp+Ch]

  for ( i = 0; i < _pcre_utf8_table1_size && a1 > _pcre_utf8_table1[i]; ++i )
    ;
  v5 = (_BYTE *)(i + a2);
  for ( j = i; j > 0; --j )
  {
    *v5-- = a1 & 0x3F | 0x80;
    a1 >>= 6;
  }
  *v5 = a1 | _pcre_utf8_table2[i];
  return i + 1;
}
