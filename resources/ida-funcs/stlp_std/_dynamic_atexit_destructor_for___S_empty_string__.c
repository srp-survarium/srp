void stlp_std::_dynamic_atexit_destructor_for___S_empty_string__()
{
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)S_empty_string._M_start_of_storage._M_data != &S_empty_string
    && S_empty_string._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(S_empty_string._M_buffers._M_end_of_storage - S_empty_string._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)S_empty_string._M_start_of_storage._M_data,
        S_empty_string._M_buffers._M_end_of_storage - S_empty_string._M_start_of_storage._M_data);
    else
      operator delete(S_empty_string._M_start_of_storage._M_data);
  }
}
