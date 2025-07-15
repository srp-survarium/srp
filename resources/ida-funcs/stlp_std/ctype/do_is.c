const wchar_t *__thiscall stlp_std::ctype<wchar_t>::do_is(
        stlp_std::ctype<wchar_t> *this,
        const wchar_t *low,
        const wchar_t *high,
        stlp_std::ctype_base::mask *vec)
{
  const wchar_t *v4; // ecx
  const wchar_t *result; // eax
  stlp_std::ctype_base::mask v7; // edx

  v4 = low;
  for ( result = high; v4 < high; ++vec )
  {
    if ( *v4 >= 0x100u )
      v7 = 0;
    else
      v7 = dword_6B3930[*v4];
    *vec = v7;
    ++v4;
  }
  return result;
}


BOOL __thiscall stlp_std::ctype<wchar_t>::do_is(
        stlp_std::ctype<wchar_t> *this,
        stlp_std::ctype_base::mask m,
        wchar_t c)
{
  return c < 0x100u && (m & dword_6B3930[c]) != 0;
}
