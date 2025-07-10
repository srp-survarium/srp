char *__cdecl stlp_std::priv::__write_decimal_backward<unsigned long>(char *__ptr, unsigned int __x, __int16 __flags)
{
  unsigned int i; // ecx

  for ( i = __x; i; i /= 0xAu )
    *--__ptr = i % 0xA + 48;
  if ( (__flags & 0x800) != 0 )
    *--__ptr = 43;
  return __ptr;
}
