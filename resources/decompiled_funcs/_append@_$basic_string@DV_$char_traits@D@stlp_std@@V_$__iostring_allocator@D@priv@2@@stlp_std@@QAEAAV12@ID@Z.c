stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::append(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        unsigned int __n,
        char __c)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *M_data; // eax
  char *M_finish; // ecx
  char *v6; // eax
  unsigned int size; // eax
  char v8; // cl

  if ( __n )
  {
    M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data;
    M_finish = this->_M_finish;
    if ( __n > this->_M_start_of_storage._M_data - M_finish - 2 )
      stlp_std::__stl_throw_length_error("basic_string");
    if ( M_data == this )
      v6 = (char *)((char *)this - M_finish + 16);
    else
      v6 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
    if ( __n >= (unsigned int)v6 )
    {
      size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
               this,
               __n);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        this,
        size);
    }
    stlp_std::priv::__ufill<char *,char,int>(this->_M_finish + 1, &this->_M_finish[__n], &__c);
    v8 = __c;
    this->_M_finish[__n] = 0;
    *this->_M_finish = v8;
    this->_M_finish += __n;
  }
  return this;
}
