void stlp_std::_dynamic_atexit_destructor_for___S_empty_wstring__()
{
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)S_empty_wstring._M_start_of_storage._M_data != &S_empty_wstring
    && S_empty_wstring._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(2 * (S_empty_wstring._M_buffers._M_end_of_storage - S_empty_wstring._M_start_of_storage._M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)S_empty_wstring._M_start_of_storage._M_data,
        2 * (S_empty_wstring._M_buffers._M_end_of_storage - S_empty_wstring._M_start_of_storage._M_data));
    else
      operator delete(S_empty_wstring._M_start_of_storage._M_data);
  }
}
