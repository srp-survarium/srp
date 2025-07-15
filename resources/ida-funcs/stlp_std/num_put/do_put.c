stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        int __val)
{
  stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,long>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        unsigned int __val)
{
  stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned long>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        long double __val)
{
  stlp_std::priv::__do_put_float<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,double>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        long double __val)
{
  stlp_std::priv::__do_put_float<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,long double>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


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


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        __int64 __val)
{
  stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::do_put(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        unsigned __int64 __val)
{
  stlp_std::priv::__do_put_integer<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned __int64>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


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


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        int __val)
{
  stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        unsigned int __val)
{
  stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned long>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        long double __val)
{
  stlp_std::priv::__do_put_float<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,double>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        long double __val)
{
  stlp_std::priv::__do_put_float<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,long double>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __formal,
        const void *__val)
{
  stlp_std::ios_base *v6; // esi
  stlp_std::locale *v7; // eax
  stlp_std::locale::facet *v8; // edi
  int M_fmtflags; // ebx
  const char *v10; // eax
  stlp_std::locale::facet_vtbl *v11; // edx
  unsigned __int16 v12; // ax
  stlp_std::locale::facet_vtbl *v13; // eax
  unsigned __int16 v14; // ax
  wchar_t v15; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v16; // eax
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // edx
  stlp_std::locale v19; // [esp+14h] [ebp-18h] BYREF
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > v20; // [esp+18h] [ebp-14h] BYREF
  int v21; // [esp+28h] [ebp-4h]

  v6 = __f;
  v7 = stlp_std::ios_base::getloc(__f, &v19);
  v21 = 0;
  v8 = stlp_std::locale::_M_use_facet(v7, &stlp_std::ctype<wchar_t>::id);
  v21 = -1;
  stlp_std::locale::~locale(&v19);
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
    v12 = ((int (__thiscall *)(stlp_std::locale::facet *, int))v11[10].~stlp_std::locale::facet)(v8, 48);
    stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(&__s, v12);
    v13 = v8->__vftable;
    LOBYTE(__f) = __f->_M_openmode;
    v14 = ((int (__thiscall *)(stlp_std::locale::facet *, stlp_std::ios_base *))v13[10].~stlp_std::locale::facet)(
            v8,
            __f);
    stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(&__s, v14);
    LODWORD(v6->_M_width) = 8;
  }
  HIDWORD(v6->_M_width) = 0;
  v15 = ((int (__thiscall *)(stlp_std::locale::facet *, int))v8->__vftable[10].~stlp_std::locale::facet)(v8, 48);
  v16 = stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned long>(
          &v20,
          __s,
          v6,
          v15,
          (unsigned int)__val);
  M_buf = v16->_M_buf;
  *(_DWORD *)&result->_M_ok = *(_DWORD *)&v16->_M_ok;
  result->_M_buf = M_buf;
  v6->_M_fmtflags = M_fmtflags;
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        __int64 __val)
{
  stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __fill,
        unsigned __int64 __val)
{
  stlp_std::priv::__do_put_integer<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned __int64>(
    result,
    __s,
    __f,
    __fill,
    __val);
  return result;
}


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
