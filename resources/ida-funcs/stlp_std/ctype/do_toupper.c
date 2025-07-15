unsigned __int8 __thiscall stlp_std::ctype<char>::do_toupper(stlp_std::ctype<char> *this, unsigned __int8 __c)
{
  return S_upper[__c];
}


char *__thiscall stlp_std::ctype<char>::do_toupper(stlp_std::ctype<char> *this, char *__low, char *__high)
{
  char *v3; // ecx
  char *result; // eax

  v3 = __low;
  for ( result = __high; v3 < __high; ++v3 )
    *v3 = S_upper[(unsigned __int8)*v3];
  return result;
}


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


int __thiscall stlp_std::ctype<wchar_t>::do_toupper(stlp_std::ctype<wchar_t> *this, wchar_t c)
{
  int result; // eax

  LOWORD(result) = c;
  if ( c < 0x100u )
    LOWORD(result) = S_upper[c];
  return (unsigned __int16)result;
}
