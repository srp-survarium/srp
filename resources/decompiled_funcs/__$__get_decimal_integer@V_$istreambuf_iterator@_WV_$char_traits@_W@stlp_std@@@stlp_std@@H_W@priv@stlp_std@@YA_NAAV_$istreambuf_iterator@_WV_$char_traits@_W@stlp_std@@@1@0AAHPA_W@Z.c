bool __cdecl stlp_std::priv::__get_decimal_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__first,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__last,
        int *__val)
{
  bool v3; // bl
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __grp; // [esp+10h] [ebp-28h] BYREF
  int v6; // [esp+34h] [ebp-4h]

  __grp._M_finish = (char *)&__grp;
  __grp._M_start_of_storage._M_data = (char *)&__grp;
  __grp._M_buffers._M_static_buf[0] = 0;
  v6 = 0;
  v3 = stlp_std::priv::__get_integer<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
         __first,
         __last,
         10,
         __val,
         0,
         0,
         0,
         &__grp);
  v6 = -1;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)__grp._M_start_of_storage._M_data != &__grp
    && __grp._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(__grp._M_buffers._M_end_of_storage - __grp._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__grp._M_start_of_storage._M_data,
        __grp._M_buffers._M_end_of_storage - __grp._M_start_of_storage._M_data);
    else
      operator delete(__grp._M_start_of_storage._M_data);
  }
  return v3;
}
