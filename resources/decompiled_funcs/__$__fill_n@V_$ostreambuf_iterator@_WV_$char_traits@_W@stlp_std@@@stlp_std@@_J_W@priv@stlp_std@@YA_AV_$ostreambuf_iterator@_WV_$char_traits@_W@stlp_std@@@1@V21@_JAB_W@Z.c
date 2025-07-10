stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __first,
        __int64 __n,
        const wchar_t *__val)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  bool M_ok; // al
  wchar_t *M_pnext; // edx
  unsigned __int16 v8; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v9; // eax

  v4 = HIDWORD(__n);
  if ( __n >= 0 )
  {
    v5 = __n;
    if ( __n > 0 )
    {
      M_ok = __first._M_ok;
      do
      {
        M_ok = M_ok
            && ((M_pnext = __first._M_buf->_M_pnext, M_pnext >= __first._M_buf->_M_pend)
              ? (v8 = __first._M_buf->overflow(__first._M_buf, *__val))
              : (*M_pnext = *__val, ++__first._M_buf->_M_pnext, v8 = *M_pnext),
                v8 != 0xFFFF);
        v4 = (__PAIR64__(v4, v5--) - 1) >> 32;
        __first._M_ok = M_ok;
      }
      while ( __SPAIR64__(v4, v5) > 0 );
    }
  }
  v9 = result;
  *result = __first;
  return v9;
}
