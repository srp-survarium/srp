wchar_t __thiscall stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // ecx
  wchar_t *M_gnext; // eax
  wchar_t result; // ax

  if ( this->_M_have_c )
    return this->_M_c;
  M_buf = this->_M_buf;
  M_gnext = this->_M_buf->_M_gnext;
  if ( M_gnext >= this->_M_buf->_M_gend )
    result = M_buf->underflow(M_buf);
  else
    result = *M_gnext;
  this->_M_c = result;
  this->_M_eof = result == 0xFFFFu;
  this->_M_have_c = 1;
  return result;
}
