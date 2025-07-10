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
