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


bool __thiscall stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        const stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__i)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // ecx
  wchar_t *M_gnext; // eax
  wchar_t v5; // ax
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *v6; // ecx
  wchar_t *v7; // eax
  wchar_t v8; // ax

  M_buf = this->_M_buf;
  if ( M_buf && !this->_M_have_c )
  {
    M_gnext = M_buf->_M_gnext;
    if ( M_gnext >= M_buf->_M_gend )
      v5 = M_buf->underflow(M_buf);
    else
      v5 = *M_gnext;
    this->_M_c = v5;
    this->_M_eof = v5 == 0xFFFFu;
    this->_M_have_c = 1;
  }
  v6 = __i->_M_buf;
  if ( __i->_M_buf && !__i->_M_have_c )
  {
    v7 = v6->_M_gnext;
    if ( v7 >= v6->_M_gend )
      v8 = v6->underflow(v6);
    else
      v8 = *v7;
    __i->_M_c = v8;
    __i->_M_eof = v8 == 0xFFFFu;
    __i->_M_have_c = 1;
  }
  return this->_M_eof == __i->_M_eof;
}
