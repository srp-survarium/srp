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
