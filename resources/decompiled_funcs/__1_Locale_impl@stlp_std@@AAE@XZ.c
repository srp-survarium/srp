void __thiscall stlp_std::_Locale_impl::~_Locale_impl(stlp_std::_Locale_impl *this)
{
  void **M_finish; // ebp
  void **i; // esi
  _STLP_atomic_freelist::item *M_start; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // ecx
  char *v6; // eax

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    Addend = 0;
  }
  InterlockedDecrement(&Addend);
  M_finish = this->facets_vec._M_impl._M_finish;
  for ( i = this->facets_vec._M_impl._M_start; i != M_finish; ++i )
  {
    if ( *i && !InterlockedDecrement((volatile LONG *)*i + 1) )
    {
      if ( *i )
        (**(void (__thiscall ***)(void *, int))*i)(*i, 1);
      *i = 0;
    }
  }
  M_start = (_STLP_atomic_freelist::item *)this->facets_vec._M_impl._M_start;
  if ( M_start )
  {
    if ( (unsigned int)(4 * (((char *)this->facets_vec._M_impl._M_end_of_storage._M_data - (char *)M_start) >> 2)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        M_start,
        4 * (((char *)this->facets_vec._M_impl._M_end_of_storage._M_data - (char *)M_start) >> 2));
    else
      operator delete(M_start);
  }
  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->name._M_start_of_storage._M_data;
  if ( M_data != &this->name && M_data )
  {
    v6 = (char *)(this->name._M_buffers._M_end_of_storage - (char *)M_data);
    if ( (unsigned int)v6 <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate((_STLP_atomic_freelist::item *)M_data, (unsigned int)v6);
    else
      operator delete(M_data);
  }
}
