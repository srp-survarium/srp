stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *this)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_gnext; // eax
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result; // eax

  M_buf = this->_M_buf;
  M_gnext = M_buf->_M_gnext;
  if ( M_gnext >= M_buf->_M_gend )
    M_buf->uflow(M_buf);
  else
    M_buf->_M_gnext = M_gnext + 1;
  result = this;
  this->_M_have_c = 0;
  return result;
}
