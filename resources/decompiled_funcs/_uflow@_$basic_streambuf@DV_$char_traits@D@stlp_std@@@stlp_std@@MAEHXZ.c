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
