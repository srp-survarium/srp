BOOL __thiscall stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *this,
        const stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__i)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_gnext; // eax
  int v5; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *v6; // ecx
  char *v7; // eax
  int v8; // eax

  M_buf = this->_M_buf;
  if ( M_buf && !this->_M_have_c )
  {
    M_gnext = M_buf->_M_gnext;
    if ( M_gnext >= M_buf->_M_gend )
      v5 = M_buf->underflow(M_buf);
    else
      v5 = (unsigned __int8)*M_gnext;
    this->_M_c = v5;
    this->_M_eof = v5 == -1;
    this->_M_have_c = 1;
  }
  v6 = __i->_M_buf;
  if ( __i->_M_buf && !__i->_M_have_c )
  {
    v7 = v6->_M_gnext;
    if ( v7 >= v6->_M_gend )
      v8 = v6->underflow(v6);
    else
      v8 = (unsigned __int8)*v7;
    __i->_M_c = v8;
    __i->_M_eof = v8 == -1;
    __i->_M_have_c = 1;
  }
  return this->_M_eof == __i->_M_eof;
}
