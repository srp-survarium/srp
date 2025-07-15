stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get(
        stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        bool __intl,
        stlp_std::ios_base *__str,
        int *__err,
        long double *__units)
{
  bool v8; // bl
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // eax
  bool __is_positive; // [esp+17h] [ebp-35h] BYREF
  char *__b; // [esp+18h] [ebp-34h] BYREF
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __e; // [esp+1Ch] [ebp-30h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __buf; // [esp+24h] [ebp-28h] BYREF
  int v15; // [esp+48h] [ebp-4h]
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __sa; // [esp+54h] [ebp+8h]

  __buf._M_finish = (char *)&__buf;
  __buf._M_start_of_storage._M_data = (char *)&__buf;
  __buf._M_buffers._M_static_buf[0] = 0;
  v15 = 0;
  __is_positive = 1;
  __sa = *stlp_std::priv::__money_do_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>>(
            &__e,
            __s,
            __end,
            __intl,
            __str,
            __err,
            &__buf,
            &__is_positive);
  if ( !*__err || *__err == 2 )
  {
    v8 = __is_positive;
    __b = __buf._M_start_of_storage._M_data;
    __e._M_buf = (stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *)__buf._M_finish;
    if ( !__is_positive )
      __b = __buf._M_start_of_storage._M_data + 1;
    stlp_std::priv::__get_decimal_integer<char *,long double,char>(&__b, (char **)&__e, __units);
    if ( !v8 )
      *__units = -*__units;
  }
  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)__buf._M_start_of_storage._M_data;
  *result = __sa;
  v15 = -1;
  if ( M_data != &__buf && M_data )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - (char *)M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        __buf._M_buffers._M_end_of_storage - (char *)M_data);
    else
      operator delete(M_data);
  }
  return result;
}


stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::money_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_get(
        stlp_std::money_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __end,
        bool __intl,
        stlp_std::ios_base *__str,
        int *__err,
        long double *__units)
{
  bool v8; // bl
  wchar_t *M_data; // ecx
  bool __is_positive; // [esp+17h] [ebp-45h] BYREF
  wchar_t *__b; // [esp+18h] [ebp-44h] BYREF
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __e; // [esp+1Ch] [ebp-40h] BYREF
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > __buf; // [esp+24h] [ebp-38h] BYREF
  int v15; // [esp+58h] [ebp-4h]
  stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __sa; // [esp+64h] [ebp+8h]

  __buf._M_finish = (wchar_t *)&__buf;
  __buf._M_start_of_storage._M_data = (wchar_t *)&__buf;
  __buf._M_buffers._M_static_buf[0] = 0;
  v15 = 0;
  __is_positive = 1;
  __sa = *stlp_std::priv::__money_do_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>>(
            &__e,
            __s,
            __end,
            __intl,
            __str,
            __err,
            &__buf,
            &__is_positive);
  if ( !*__err || *__err == 2 )
  {
    v8 = __is_positive;
    __b = __buf._M_start_of_storage._M_data;
    __e._M_buf = (stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *)__buf._M_finish;
    if ( !__is_positive )
      __b = __buf._M_start_of_storage._M_data + 1;
    stlp_std::priv::__get_decimal_integer<wchar_t *,long double,wchar_t>(&__b, (wchar_t **)&__e, __units);
    if ( !v8 )
      *__units = -*__units;
  }
  result->_M_buf = __sa._M_buf;
  M_data = __buf._M_start_of_storage._M_data;
  *(_DWORD *)&result->_M_c = *(_DWORD *)&__sa._M_c;
  v15 = -1;
  if ( M_data != (wchar_t *)&__buf && M_data )
  {
    if ( (unsigned int)(2 * (__buf._M_buffers._M_end_of_storage - M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        2 * (__buf._M_buffers._M_end_of_storage - M_data));
    else
      operator delete(M_data);
  }
  return result;
}
