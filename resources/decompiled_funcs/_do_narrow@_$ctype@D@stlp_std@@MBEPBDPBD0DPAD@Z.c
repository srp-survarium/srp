const char *__thiscall stlp_std::ctype<char>::do_narrow(
        stlp_std::ctype<char> *this,
        char *__low,
        const char *__high,
        char __formal,
        char *__to)
{
  if ( __high != __low )
    memmove((unsigned __int8 *)__to, (unsigned __int8 *)__low, __high - __low);
  return __high;
}
