int __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::uflow(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this)
{
  char *M_gnext; // [esp+8h] [ebp-Ch]

  if ( this->underflow(this) == -1 )
    return -1;
  M_gnext = this->_M_gnext;
  this->_M_gnext = M_gnext + 1;
  return (unsigned __int8)*M_gnext;
}


int __thiscall stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::uflow(
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  wchar_t *M_gnext; // eax

  if ( this->underflow(this) == 0xFFFF )
    return 0xFFFF;
  M_gnext = this->_M_gnext;
  this->_M_gnext = M_gnext + 1;
  return *M_gnext;
}
