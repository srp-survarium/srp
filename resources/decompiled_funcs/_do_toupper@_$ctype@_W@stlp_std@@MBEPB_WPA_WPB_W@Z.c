wchar_t *__thiscall stlp_std::ctype<wchar_t>::do_toupper(stlp_std::ctype<wchar_t> *this, wchar_t *low, wchar_t *high)
{
  wchar_t *v3; // ecx
  wchar_t *result; // eax
  int v5; // edx

  v3 = low;
  for ( result = high; v3 < high; ++v3 )
  {
    v5 = *v3;
    if ( *v3 < 0x100u )
      LOWORD(v5) = S_upper[v5];
    *v3 = v5;
  }
  return result;
}
