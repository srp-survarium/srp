stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__thiscall stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::do_put(
        stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        wchar_t __formal,
        const tm *__tmb,
        char __format,
        char __modifier)
{
  stlp_std::locale *v9; // eax
  const stlp_std::ctype<wchar_t> *v10; // ebp
  stlp_std::locale v12; // [esp+18h] [ebp-444h] BYREF
  stlp_std::priv::__iostring_allocator<wchar_t> __a; // [esp+1Eh] [ebp-43Eh] BYREF
  stlp_std::priv::__basic_iostring<wchar_t> __buf; // [esp+220h] [ebp-23Ch] BYREF
  int v15; // [esp+458h] [ebp-4h]

  v9 = stlp_std::ios_base::getloc(__f, &v12);
  v15 = 0;
  v10 = (const stlp_std::ctype<wchar_t> *)stlp_std::locale::_M_use_facet(v9, &stlp_std::ctype<wchar_t>::id);
  v15 = -1;
  stlp_std::locale::~locale(&v12);
  stlp_std::priv::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>(
    &__buf,
    &__a,
    257);
  *__buf._M_finish = 0;
  v15 = 1;
  stlp_std::priv::__write_formatted_time(&__buf, v10, __format, __modifier, &this->_M_timeinfo, __tmb);
  stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
    result,
    __buf._M_start_of_storage._M_data,
    __buf._M_finish,
    __s);
  v15 = -1;
  if ( (stlp_std::priv::__basic_iostring<wchar_t> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::priv::__iostring_allocator<wchar_t> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(2 * (__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        2 * (__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data));
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
  return result;
}
