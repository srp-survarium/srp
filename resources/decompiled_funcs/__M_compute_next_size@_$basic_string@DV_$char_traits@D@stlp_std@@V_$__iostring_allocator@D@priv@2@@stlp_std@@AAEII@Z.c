unsigned int __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        unsigned int __n)
{
  unsigned int v2; // edx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v2 = this->_M_finish - this->_M_start_of_storage._M_data;
  __size = v2;
  if ( __n > -2 - v2 )
    stlp_std::__stl_throw_length_error("basic_string");
  p_size = &__size;
  if ( __n >= v2 )
    p_size = &__n;
  result = *p_size + v2 + 1;
  if ( result == -1 || result < v2 )
    return -2;
  return result;
}
