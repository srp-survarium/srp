unsigned int __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_compute_next_size(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  const unsigned int *v2; // eax
  unsigned int v3; // eax
  unsigned int v6; // [esp+20h] [ebp-20h]
  unsigned int __size; // [esp+38h] [ebp-8h] BYREF
  unsigned int __len; // [esp+3Ch] [ebp-4h]

  __size = this->_M_finish - this->_M_start_of_storage._M_data;
  v6 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::max_size(this);
  if ( __n > v6 - __size )
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_throw_length_error(this);
  v2 = stlp_std::max<unsigned int>(&__n, &__size);
  __len = __size + *v2 + 1;
  v3 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::max_size(this);
  if ( __len > v3 || __len < __size )
    return stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::max_size(this);
  return __len;
}
