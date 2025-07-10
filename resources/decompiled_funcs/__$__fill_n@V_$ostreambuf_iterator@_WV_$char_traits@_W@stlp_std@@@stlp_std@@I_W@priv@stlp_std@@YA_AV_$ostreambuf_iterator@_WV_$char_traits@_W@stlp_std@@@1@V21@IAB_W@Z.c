stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned int,wchar_t>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __first,
        unsigned int __n,
        const wchar_t *__val)
{
  unsigned int v4; // ebx
  bool M_ok; // al
  wchar_t *M_pnext; // edx
  unsigned __int16 v7; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v8; // eax

  v4 = __n;
  if ( __n )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, M_pnext >= __first._M_buf->_M_pend)
            ? (v7 = __first._M_buf->overflow(__first._M_buf, *__val))
            : (*M_pnext = *__val, ++__first._M_buf->_M_pnext, v7 = *M_pnext),
              v7 != 0xFFFF);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 );
  }
  v8 = result;
  *result = __first;
  return v8;
}
