stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_get_float<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,float,char>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__end,
        stlp_std::ios_base *__str,
        int *__err,
        float *__val)
{
  const stlp_std::ctype<char> *v6; // ebp
  stlp_std::moneypunct<wchar_t,0> *v7; // ebx
  int *v8; // ebx
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // edi
  char *M_data; // eax
  stlp_std::locale __loc; // [esp+18h] [ebp-23Ch] BYREF
  float *val; // [esp+1Ch] [ebp-238h]
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v14; // [esp+20h] [ebp-234h]
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+27h] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+128h] [ebp-12Ch] BYREF
  int v17; // [esp+250h] [ebp-4h]

  v14 = result;
  val = __val;
  stlp_std::ios_base::getloc(__str, &__loc);
  v17 = 0;
  v6 = (const stlp_std::ctype<char> *)stlp_std::locale::_M_use_facet(&__loc, &stlp_std::ctype<char>::id);
  v7 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(&__loc, &stlp_std::numpunct<char>::id);
  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  LOBYTE(v17) = 1;
  if ( stlp_std::priv::__read_float<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char>(
         &__buf,
         __in_ite,
         __end,
         v6,
         v7) )
  {
    stlp_std::priv::__string_to_float(&__buf, val);
    v8 = __err;
    *__err = 0;
  }
  else
  {
    *__err = 4;
    v8 = __err;
  }
  if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
    *v8 |= 2u;
  v9 = v14;
  v14->_M_buf = __in_ite->_M_buf;
  M_data = __buf._M_start_of_storage._M_data;
  *(_DWORD *)&v9->_M_c = *(_DWORD *)&__in_ite->_M_c;
  LOBYTE(v17) = 0;
  if ( M_data != (char *)&__buf && M_data && M_data != (char *)&__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        __buf._M_buffers._M_end_of_storage - M_data);
    else
      operator delete(M_data);
  }
  stlp_std::locale::~locale(&__loc);
  return v9;
}
