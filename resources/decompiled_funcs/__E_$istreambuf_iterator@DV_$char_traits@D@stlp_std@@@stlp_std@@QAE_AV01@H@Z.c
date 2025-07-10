stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        int __formal)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_gnext; // eax
  int v6; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v7; // ecx
  char *v8; // eax
  int v9; // edx
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v10; // eax

  if ( !this->_M_have_c )
  {
    M_buf = this->_M_buf;
    M_gnext = this->_M_buf->_M_gnext;
    if ( M_gnext >= this->_M_buf->_M_gend )
      v6 = M_buf->underflow(M_buf);
    else
      v6 = (unsigned __int8)*M_gnext;
    this->_M_c = v6;
    this->_M_eof = v6 == -1;
    this->_M_have_c = 1;
  }
  v7 = this->_M_buf;
  v8 = this->_M_buf->_M_gnext;
  v9 = *(_DWORD *)&this->_M_c;
  result->_M_buf = this->_M_buf;
  *(_DWORD *)&result->_M_c = v9;
  if ( v8 >= v7->_M_gend )
    v7->uflow(v7);
  else
    v7->_M_gnext = v8 + 1;
  v10 = result;
  this->_M_have_c = 0;
  return v10;
}
