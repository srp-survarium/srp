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
