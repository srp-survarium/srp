char __thiscall stlp_std::ctype<char>::do_widen(stlp_std::ctype<char> *this, char __c)
{
  return __c;
}


const char *__thiscall stlp_std::ctype<char>::do_widen(
        stlp_std::ctype<char> *this,
        char *__low,
        const char *__high,
        char *__to)
{
  if ( __high != __low )
    memmove((unsigned __int8 *)__to, (unsigned __int8 *)__low, __high - __low);
  return __high;
}


const char *__thiscall stlp_std::ctype<wchar_t>::do_widen(
        stlp_std::ctype<wchar_t> *this,
        const char *low,
        const char *high,
        wchar_t *dest)
{
  const char *v4; // ecx
  const char *result; // eax

  v4 = low;
  for ( result = high; v4 != high; ++dest )
    *dest = *(unsigned __int8 *)v4++;
  return result;
}


wchar_t __thiscall stlp_std::ctype<wchar_t>::do_widen(stlp_std::ctype<wchar_t> *this, unsigned __int8 c)
{
  return c;
}
