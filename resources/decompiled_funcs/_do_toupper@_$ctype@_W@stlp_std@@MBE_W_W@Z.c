int __thiscall stlp_std::ctype<wchar_t>::do_toupper(stlp_std::ctype<wchar_t> *this, wchar_t c)
{
  int result; // eax

  LOWORD(result) = c;
  if ( c < 0x100u )
    LOWORD(result) = S_upper[c];
  return (unsigned __int16)result;
}
