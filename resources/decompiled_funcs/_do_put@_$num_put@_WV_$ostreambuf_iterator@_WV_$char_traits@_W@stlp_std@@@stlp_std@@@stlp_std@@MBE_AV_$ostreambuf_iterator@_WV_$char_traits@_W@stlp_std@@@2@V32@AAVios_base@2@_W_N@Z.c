stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        int __fill,
        bool __val)
{
  if ( (__f->_M_fmtflags & 0x100) != 0 )
    stlp_std::priv::__do_put_bool<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
      result,
      __s,
      __f,
      __fill,
      __val);
  else
    ((void (__thiscall *)(stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *, stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *, stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *, _DWORD, stlp_std::ios_base *, int, bool))this->do_put)(
      this,
      result,
      __s._M_buf,
      *(_DWORD *)&__s._M_ok,
      __f,
      __fill,
      __val);
  return result;
}
