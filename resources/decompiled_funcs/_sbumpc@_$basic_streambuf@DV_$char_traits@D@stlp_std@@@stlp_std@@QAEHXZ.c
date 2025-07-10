int __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::sbumpc(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this)
{
  char *M_gnext; // [esp+8h] [ebp-4h]

  if ( this->_M_gnext >= this->_M_gend )
    return this->uflow(this);
  M_gnext = this->_M_gnext;
  this->_M_gnext = M_gnext + 1;
  return (unsigned __int8)*M_gnext;
}
