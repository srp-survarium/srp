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
