char *__cdecl stlp_std::priv::__write_integer_backward<unsigned __int64>(
        char *__buf,
        __int16 __flags,
        unsigned __int64 __x)
{
  char *v3; // esi
  char *result; // eax
  int v5; // eax
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // ecx
  char *v8; // esi
  const char *v9; // eax
  unsigned __int64 v10; // kr08_8
  unsigned int v11; // edx
  char *v12; // esi

  v3 = __buf;
  if ( __x )
  {
    v5 = __flags & 0x38;
    if ( v5 == 16 )
    {
      if ( (__flags & 0x4000) != 0 )
        v9 = stlp_std::priv::__hex_char_table_hi();
      else
        v9 = stlp_std::priv::__hex_char_table_lo();
      v10 = __x;
      do
      {
        *--v3 = v9[v10 & 0xF];
        v11 = HIDWORD(v10) >> 4;
        v10 >>= 4;
      }
      while ( __PAIR64__(v10, v11) );
      if ( (__flags & 0x200) != 0 )
      {
        v12 = v3 - 1;
        *v12 = v9[16];
        v3 = v12 - 1;
        *v3 = 48;
      }
    }
    else
    {
      if ( v5 != 32 )
        return stlp_std::priv::__write_decimal_backward<unsigned __int64>(__buf, __x, __flags);
      v6 = __x;
      do
      {
        *--v3 = (v6 & 7) + 48;
        v7 = HIDWORD(v6) >> 3;
        v6 >>= 3;
      }
      while ( __PAIR64__(v7, v6) );
      if ( (__flags & 0x200) != 0 )
      {
        v8 = v3 - 1;
        *v8 = 48;
        return v8;
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
