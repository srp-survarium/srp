stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::operator+=(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        char __c)
{
  int v3; // eax
  unsigned int size; // eax

  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v3 = (char *)this - this->_M_finish + 16;
  else
    v3 = this->_M_buffers._M_end_of_storage - this->_M_finish;
  if ( v3 == 1 )
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             1u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
      this,
      size);
  }
  this->_M_finish[1] = 0;
  *this->_M_finish++ = __c;
  return this;
}
