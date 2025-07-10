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
