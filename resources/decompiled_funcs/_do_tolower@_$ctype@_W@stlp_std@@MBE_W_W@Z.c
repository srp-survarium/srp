int __thiscall stlp_std::ctype<wchar_t>::do_tolower(stlp_std::ctype<wchar_t> *this, wchar_t c)
{
  int result; // eax

  LOWORD(result) = c;
  if ( c < 0x100u )
    LOWORD(result) = S_lower[c];
  return (unsigned __int16)result;
}
