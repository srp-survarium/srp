void __cdecl sub_7F34F0()
{
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)stru_A9B0E8._M_start_of_storage._M_data != &stru_A9B0E8
    && stru_A9B0E8._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(stru_A9B0E8._M_buffers._M_end_of_storage - stru_A9B0E8._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)stru_A9B0E8._M_start_of_storage._M_data,
        stru_A9B0E8._M_buffers._M_end_of_storage - stru_A9B0E8._M_start_of_storage._M_data);
    else
      operator delete(stru_A9B0E8._M_start_of_storage._M_data);
  }
}
