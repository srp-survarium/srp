char __thiscall stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *this)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_gnext; // eax
  int v4; // eax

  if ( !this->_M_have_c )
  {
    M_buf = this->_M_buf;
    M_gnext = this->_M_buf->_M_gnext;
    if ( M_gnext >= this->_M_buf->_M_gend )
      v4 = M_buf->underflow(M_buf);
    else
      v4 = (unsigned __int8)*M_gnext;
    this->_M_c = v4;
    this->_M_eof = v4 == -1;
    this->_M_have_c = 1;
  }
  return this->_M_c;
}
