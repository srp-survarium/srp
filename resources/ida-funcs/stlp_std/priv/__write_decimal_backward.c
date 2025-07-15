char *__cdecl stlp_std::priv::__write_decimal_backward<long>(char *__ptr, int __x, __int16 __flags)
{
  bool v3; // bl
  unsigned __int64 v4; // rax
  unsigned int v6; // ecx
  unsigned __int64 v7; // rcx
  char *v8; // esi
  unsigned __int64 v10; // [esp-10h] [ebp-20h]
  bool __negative; // [esp+18h] [ebp+8h]

  LODWORD(v4) = __x;
  v3 = __x < 0;
  __negative = v3;
  v4 = (int)v4;
  if ( v3 )
    v4 = -(__int64)(int)v4;
  v6 = HIDWORD(v4);
  if ( v4 )
  {
    do
    {
      v10 = __PAIR64__(v6, v4);
      --__ptr;
      v7 = __PAIR64__(v6, v4) % 0xA;
      v4 = v10 / 0xA;
      *__ptr = v7 + 48;
      v6 = (v10 / 0xA) >> 32;
    }
    while ( v10 / 0xA );
    v3 = __negative;
  }
  if ( v3 )
  {
    v8 = __ptr - 1;
    *v8 = 45;
    return v8;
  }
  else
  {
    if ( (__flags & 0x800) != 0 )
      *--__ptr = 43;
    return __ptr;
  }
}


char *__cdecl stlp_std::priv::__write_decimal_backward<unsigned long>(char *__ptr, unsigned int __x, __int16 __flags)
{
  unsigned int i; // ecx

  for ( i = __x; i; i /= 0xAu )
    *--__ptr = i % 0xA + 48;
  if ( (__flags & 0x800) != 0 )
    *--__ptr = 43;
  return __ptr;
}


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


char *__cdecl stlp_std::priv::__write_decimal_backward<unsigned __int64>(
        char *__ptr,
        unsigned __int64 __x,
        __int16 __flags)
{
  unsigned __int64 v3; // rax
  unsigned int v4; // ecx
  unsigned __int64 v6; // rcx
  unsigned __int64 v8; // [esp-14h] [ebp-18h]

  v4 = HIDWORD(__x);
  LODWORD(v3) = __x;
  if ( __x )
  {
    do
    {
      v8 = __PAIR64__(v4, v3);
      --__ptr;
      v6 = __PAIR64__(v4, v3) % 0xA;
      v3 = v8 / 0xA;
      *__ptr = v6 + 48;
      v4 = (v8 / 0xA) >> 32;
    }
    while ( v8 / 0xA );
  }
  if ( (__flags & 0x800) != 0 )
    *--__ptr = 43;
  return __ptr;
}
