char *__thiscall stlp_std::ctype<char>::do_toupper(stlp_std::ctype<char> *this, char *__low, char *__high)
{
  char *v3; // ecx
  char *result; // eax

  v3 = __low;
  for ( result = __high; v3 < __high; ++v3 )
    *v3 = S_upper[(unsigned __int8)*v3];
  return result;
}
