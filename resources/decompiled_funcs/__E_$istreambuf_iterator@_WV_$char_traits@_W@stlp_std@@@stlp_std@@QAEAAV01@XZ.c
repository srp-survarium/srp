stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *this)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // ecx
  wchar_t *M_gnext; // eax
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result; // eax

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
