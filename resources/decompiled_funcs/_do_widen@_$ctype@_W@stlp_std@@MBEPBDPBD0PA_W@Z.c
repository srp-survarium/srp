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
