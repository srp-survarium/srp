stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned short,char>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__end,
        stlp_std::ios_base *__str,
        int *__err,
        unsigned __int16 *__val)
{
  stlp_std::ctype<char> *v6; // eax
  int v7; // esi
  stlp_std::moneypunct<wchar_t,0> *v8; // edi
  wchar_t (__thiscall *do_thousands_sep)(stlp_std::moneypunct<wchar_t,0> *); // eax
  char v10; // al
  int v11; // edx
  stlp_std::locale __loc; // [esp+14h] [ebp-2Ch] BYREF
  BOOL __negative; // [esp+18h] [ebp-28h]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v15; // [esp+1Ch] [ebp-24h] BYREF
  int v16; // [esp+3Ch] [ebp-4h]
  bool __result; // [esp+50h] [ebp+10h]
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__resulta; // [esp+50h] [ebp+10h]

  stlp_std::ios_base::getloc(__str, &__loc);
  v16 = 0;
  v6 = (stlp_std::ctype<char> *)stlp_std::locale::_M_use_facet(&__loc, &stlp_std::ctype<char>::id);
  v7 = stlp_std::priv::__get_base_or_zero<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char>(
         __in_ite,
         __end,
         __str->_M_fmtflags,
         v6);
  if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
  {
    if ( (v7 & 1) != 0 )
    {
      *__val = 0;
      __result = 1;
    }
    else
    {
      __result = 0;
    }
  }
  else
  {
    v8 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(&__loc, &stlp_std::numpunct<char>::id);
    LOBYTE(__negative) = (v7 & 2) != 0;
    __resulta = stlp_std::moneypunct<wchar_t,1>::grouping(v8, &v15);
    do_thousands_sep = v8->do_thousands_sep;
    LOBYTE(v16) = 1;
    v10 = do_thousands_sep(v8);
    __result = stlp_std::priv::__get_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned short,char>(
                 __in_ite,
                 __end,
                 v7 >> 2,
                 __val,
                 v7 & 1,
                 __negative,
                 v10,
                 __resulta);
    LOBYTE(v16) = 0;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v15._M_start_of_storage._M_data != &v15
      && v15._M_start_of_storage._M_data )
    {
      if ( (unsigned int)(v15._M_buffers._M_end_of_storage - v15._M_start_of_storage._M_data) <= 0x80 )
        stlp_std::__node_alloc::_M_deallocate(
          (_STLP_atomic_freelist::item *)v15._M_start_of_storage._M_data,
          v15._M_buffers._M_end_of_storage - v15._M_start_of_storage._M_data);
      else
        operator delete(v15._M_start_of_storage._M_data);
    }
  }
  *__err = __result ? 0 : 4;
  if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
    *__err |= 2u;
  v11 = *(_DWORD *)&__in_ite->_M_c;
  result->_M_buf = __in_ite->_M_buf;
  *(_DWORD *)&result->_M_c = v11;
  stlp_std::locale::~locale(&__loc);
  return result;
}
