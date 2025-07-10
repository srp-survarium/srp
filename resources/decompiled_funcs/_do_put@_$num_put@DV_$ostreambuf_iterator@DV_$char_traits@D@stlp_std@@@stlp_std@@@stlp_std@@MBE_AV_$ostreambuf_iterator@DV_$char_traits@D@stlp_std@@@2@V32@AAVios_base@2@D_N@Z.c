stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        int __fill,
        bool __val)
{
  if ( (__f->_M_fmtflags & 0x100) != 0 )
    stlp_std::priv::__do_put_bool<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
      result,
      __s,
      __f,
      __fill,
      __val);
  else
    ((void (__thiscall *)(stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *, stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *, stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *, _DWORD, stlp_std::ios_base *, int, bool))this->do_put)(
      this,
      result,
      __s._M_buf,
      *(_DWORD *)&__s._M_ok,
      __f,
      __fill,
      __val);
  return result;
}
