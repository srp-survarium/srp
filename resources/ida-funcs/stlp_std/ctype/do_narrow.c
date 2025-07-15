char __thiscall stlp_std::ctype<char>::do_narrow(stlp_std::ctype<char> *this, char __c, char __formal)
{
  return __c;
}


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


char __thiscall stlp_std::ctype<wchar_t>::do_narrow(stlp_std::ctype<wchar_t> *this, wchar_t c, char dfault)
{
  char result; // al

  result = c;
  if ( (unsigned __int8)c != c )
    return dfault;
  return result;
}


const wchar_t *__thiscall stlp_std::ctype<wchar_t>::do_narrow(
        stlp_std::ctype<wchar_t> *this,
        const wchar_t *low,
        const wchar_t *high,
        char dfault,
        char *dest)
{
  const wchar_t *v5; // edx
  const wchar_t *result; // eax
  wchar_t v8; // cx

  v5 = low;
  for ( result = high; v5 != high; ++dest )
  {
    v8 = *v5++;
    if ( (unsigned __int8)v8 != v8 )
      LOBYTE(v8) = dfault;
    *dest = v8;
  }
  return result;
}
