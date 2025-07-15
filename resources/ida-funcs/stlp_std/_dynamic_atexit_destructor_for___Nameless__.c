void __cdecl stlp_std::_dynamic_atexit_destructor_for___Nameless__()
{
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)Nameless._M_start_of_storage._M_data != &Nameless
    && Nameless._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(Nameless._M_buffers._M_end_of_storage - Nameless._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)Nameless._M_start_of_storage._M_data,
        Nameless._M_buffers._M_end_of_storage - Nameless._M_start_of_storage._M_data);
    else
      operator delete(Nameless._M_start_of_storage._M_data);
  }
}
