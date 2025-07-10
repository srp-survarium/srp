stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __formal,
        const void *__val)
{
  stlp_std::ios_base *v6; // esi
  stlp_std::locale *v7; // eax
  stlp_std::locale::facet *v8; // edi
  int M_fmtflags; // ebx
  const char *v10; // eax
  stlp_std::locale::facet_vtbl *v11; // edx
  void (__thiscall *v12)(stlp_std::locale::facet *); // edx
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v13; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // edx
  stlp_std::locale v16; // [esp+14h] [ebp-1Ch] BYREF
  char __c; // [esp+18h] [ebp-18h]
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > v18; // [esp+1Ch] [ebp-14h] BYREF
  int v19; // [esp+2Ch] [ebp-4h]

  v6 = __f;
  v7 = stlp_std::ios_base::getloc(__f, &v16);
  v19 = 0;
  v8 = stlp_std::locale::_M_use_facet(v7, &stlp_std::ctype<char>::id);
  v19 = -1;
  stlp_std::locale::~locale(&v16);
  M_fmtflags = v6->_M_fmtflags;
  v6->_M_fmtflags = M_fmtflags & 0xFFFFFDC0 | 0x214;
  v6->_M_width = 10;
  if ( __val )
  {
    LODWORD(v6->_M_width) = 10;
  }
  else
  {
    if ( (M_fmtflags & 0x4000) != 0 )
      v10 = stlp_std::priv::__hex_char_table_hi();
    else
      v10 = stlp_std::priv::__hex_char_table_lo();
    v11 = v8->__vftable;
    __f = (stlp_std::ios_base *)v10;
    __c = ((int (__thiscall *)(stlp_std::locale::facet *, int))v11[6].~stlp_std::locale::facet)(v8, 48);
    stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>::operator=(&__s, __c);
    v12 = v8->__vftable[6].~stlp_std::locale::facet;
    LOBYTE(__f) = __f->_M_openmode;
    LOBYTE(__f) = ((int (__thiscall *)(stlp_std::locale::facet *, stlp_std::ios_base *))v12)(v8, __f);
    stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>::operator=(&__s, (unsigned __int8)__f);
    LODWORD(v6->_M_width) = 8;
  }
  HIDWORD(v6->_M_width) = 0;
  LOBYTE(__f) = ((int (__thiscall *)(stlp_std::locale::facet *, int))v8->__vftable[6].~stlp_std::locale::facet)(v8, 48);
  v13 = stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned long>(
          &v18,
          __s,
          v6,
          (char)__f,
          (unsigned int)__val);
  M_buf = v13->_M_buf;
  *(_DWORD *)&result->_M_ok = *(_DWORD *)&v13->_M_ok;
  result->_M_buf = M_buf;
  v6->_M_fmtflags = M_fmtflags;
  return result;
}
