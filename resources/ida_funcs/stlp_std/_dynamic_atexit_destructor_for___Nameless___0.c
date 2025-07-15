void __cdecl stlp_std::_dynamic_atexit_destructor_for___Nameless___0()
{
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)Nameless_0._M_start_of_storage._M_data != &Nameless_0
    && Nameless_0._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(Nameless_0._M_buffers._M_end_of_storage - Nameless_0._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)Nameless_0._M_start_of_storage._M_data,
        Nameless_0._M_buffers._M_end_of_storage - Nameless_0._M_start_of_storage._M_data);
    else
      operator delete(Nameless_0._M_start_of_storage._M_data);
  }
}
