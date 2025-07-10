char *__cdecl stlp_std::priv::__write_integer_backward<unsigned long>(char *__buf, __int16 __flags, unsigned int __x)
{
  char *v3; // esi
  char *result; // eax
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ecx
  char v8; // dl
  char *v9; // esi
  const char *v10; // eax
  const char *v11; // ebp
  unsigned int v12; // ecx
  unsigned int v13; // edx
  char v14; // al
  char *v15; // esi

  v3 = __buf;
  if ( __x )
  {
    v5 = __flags & 0x38;
    if ( v5 == 16 )
    {
      if ( (__flags & 0x4000) != 0 )
        v10 = stlp_std::priv::__hex_char_table_hi();
      else
        v10 = stlp_std::priv::__hex_char_table_lo();
      v11 = v10;
      v12 = __x;
      v13 = 0;
      do
      {
        v14 = v11[v12 & 0xF];
        v12 = __PAIR64__(v13, v12) >> 4;
        *--v3 = v14;
        v13 >>= 4;
      }
      while ( __PAIR64__(v12, v13) );
      if ( (__flags & 0x200) != 0 )
      {
        v15 = v3 - 1;
        *v15 = v11[16];
        v3 = v15 - 1;
        *v3 = 48;
      }
    }
    else
    {
      if ( v5 != 32 )
        return stlp_std::priv::__write_decimal_backward<unsigned long>(__buf, __x, __flags);
      v6 = __x;
      v7 = 0;
      do
      {
        v8 = v6 & 7;
        v6 = __PAIR64__(v7, v6) >> 3;
        *--v3 = v8 + 48;
        v7 >>= 3;
      }
      while ( __PAIR64__(v7, v6) );
      if ( (__flags & 0x200) != 0 )
      {
        v9 = v3 - 1;
        *v9 = 48;
        return v9;
      }
    }
    return v3;
  }
  else
  {
    result = __buf - 1;
    *(__buf - 1) = 48;
    if ( (__flags & 0x800) != 0 && (__flags & 0x30) == 0 )
    {
      result = __buf - 2;
      *(__buf - 2) = 43;
    }
  }
  return result;
}
