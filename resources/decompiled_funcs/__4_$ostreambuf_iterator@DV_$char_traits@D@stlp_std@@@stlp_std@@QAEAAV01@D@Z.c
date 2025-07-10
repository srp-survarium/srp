stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>::operator=(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *this,
        unsigned __int8 __c)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *M_pnext; // eax
  int v5; // eax

  if ( !this->_M_ok
    || ((M_buf = this->_M_buf, M_pnext = this->_M_buf->_M_pnext, M_pnext >= this->_M_buf->_M_pend)
      ? (v5 = M_buf->overflow(M_buf, __c))
      : (*M_pnext = __c, ++M_buf->_M_pnext, v5 = (unsigned __int8)*M_pnext),
        v5 == -1) )
  {
    this->_M_ok = 0;
    return this;
  }
  else
  {
    this->_M_ok = 1;
    return this;
  }
}
