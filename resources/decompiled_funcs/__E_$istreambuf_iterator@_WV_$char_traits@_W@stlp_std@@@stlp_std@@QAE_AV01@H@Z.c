stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        int __formal)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // ecx
  wchar_t *M_gnext; // eax
  wchar_t v6; // ax
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *v7; // eax
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *v8; // ecx
  wchar_t *v9; // eax
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v10; // eax

  if ( !this->_M_have_c )
  {
    M_buf = this->_M_buf;
    M_gnext = this->_M_buf->_M_gnext;
    if ( M_gnext >= this->_M_buf->_M_gend )
      v6 = M_buf->underflow(M_buf);
    else
      v6 = *M_gnext;
    this->_M_c = v6;
    this->_M_eof = v6 == 0xFFFFu;
    this->_M_have_c = 1;
  }
  v7 = this->_M_buf;
  *(_DWORD *)&result->_M_c = *(_DWORD *)&this->_M_c;
  v8 = v7;
  result->_M_buf = v7;
  v9 = v7->_M_gnext;
  if ( v9 >= v8->_M_gend )
    v8->uflow(v8);
  else
    v8->_M_gnext = v9 + 1;
  v10 = result;
  this->_M_have_c = 0;
  return v10;
}
