stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::money_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::money_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        bool __intl,
        stlp_std::ios_base *__str,
        wchar_t __fill,
        long double __units)
{
  stlp_std::priv::__iostring_allocator<wchar_t> __a; // [esp+16h] [ebp-43Eh] BYREF
  stlp_std::priv::__basic_iostring<wchar_t> __digits; // [esp+218h] [ebp-23Ch] BYREF
  int v10; // [esp+450h] [ebp-4h]

  stlp_std::priv::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>(
    &__digits,
    &__a,
    257);
  *__digits._M_finish = 0;
  v10 = 0;
  stlp_std::priv::__get_money_digits_aux(&__digits, __str, __units);
  stlp_std::priv::__money_do_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>,stlp_std::priv::__basic_iostring<wchar_t>>(
    result,
    __s,
    __intl,
    __str,
    __fill,
    &__digits,
    0);
  v10 = -1;
  if ( (stlp_std::priv::__basic_iostring<wchar_t> *)__digits._M_start_of_storage._M_data != &__digits
    && __digits._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::priv::__iostring_allocator<wchar_t> > *)__digits._M_start_of_storage._M_data != &__digits._M_start_of_storage )
  {
    if ( (unsigned int)(2 * (__digits._M_buffers._M_end_of_storage - __digits._M_start_of_storage._M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__digits._M_start_of_storage._M_data,
        2 * (__digits._M_buffers._M_end_of_storage - __digits._M_start_of_storage._M_data));
    else
      operator delete(__digits._M_start_of_storage._M_data);
  }
  return result;
}
