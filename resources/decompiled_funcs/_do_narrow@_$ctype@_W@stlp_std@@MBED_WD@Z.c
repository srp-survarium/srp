char __thiscall stlp_std::ctype<wchar_t>::do_narrow(stlp_std::ctype<wchar_t> *this, wchar_t c, char dfault)
{
  char result; // al

  result = c;
  if ( (unsigned __int8)c != c )
    return dfault;
  return result;
}
