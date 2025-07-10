stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int,char>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __first,
        int __n,
        const char *__val)
{
  int v4; // esi
  bool M_ok; // al
  char *M_pnext; // edx
  unsigned __int8 v7; // bl
  int v8; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax

  v4 = __n;
  if ( __n > 0 )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, v7 = *__val, M_pnext >= __first._M_buf->_M_pend)
            ? (v8 = __first._M_buf->overflow(__first._M_buf, v7))
            : (*M_pnext = v7, ++__first._M_buf->_M_pnext, v8 = (unsigned __int8)*M_pnext),
              v8 != -1);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 > 0 );
  }
  v9 = result;
  *result = __first;
  return v9;
}
