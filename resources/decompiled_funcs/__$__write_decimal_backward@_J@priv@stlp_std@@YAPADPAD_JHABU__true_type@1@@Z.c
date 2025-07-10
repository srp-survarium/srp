char *__cdecl stlp_std::priv::__write_decimal_backward<__int64>(char *__ptr, __int64 __x, __int16 __flags)
{
  unsigned int v3; // ecx
  unsigned __int64 v4; // rax
  unsigned __int64 v6; // rcx
  char *v7; // esi
  unsigned __int64 v9; // [esp-18h] [ebp-20h]

  v3 = HIDWORD(__x);
  LODWORD(v4) = __x;
  if ( __x < 0 )
  {
    LODWORD(v4) = -(int)__x;
    LOBYTE(__x) = 1;
    v3 = (unsigned __int64)-__SPAIR64__(HIDWORD(__x), v4) >> 32;
  }
  else
  {
    LOBYTE(__x) = 0;
  }
  if ( v3 | (unsigned int)v4 )
  {
    do
    {
      v9 = __PAIR64__(v3, v4);
      --__ptr;
      v6 = __PAIR64__(v3, v4) % 0xA;
      v4 = v9 / 0xA;
      *__ptr = v6 + 48;
      v3 = (v9 / 0xA) >> 32;
    }
    while ( v9 / 0xA );
  }
  if ( (_BYTE)__x )
  {
    v7 = __ptr - 1;
    *v7 = 45;
    return v7;
  }
  else
  {
    if ( (__flags & 0x800) != 0 )
      *--__ptr = 43;
    return __ptr;
  }
}
