unsigned int __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_compute_next_size(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > **p_n; // eax
  unsigned int result; // eax
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = this;
  v4 = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)(this->_M_finish
                                                                                             - this->_M_start_of_storage._M_data);
  if ( __n > -2 - (int)v4 )
    stlp_std::__stl_throw_length_error("basic_string");
  p_n = &v4;
  if ( __n >= (unsigned int)v4 )
    p_n = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > **)&__n;
  result = (unsigned int)&v4->_M_buffers._M_static_buf[(_DWORD)*p_n + 1];
  if ( result == -1 || result < (unsigned int)v4 )
    return -2;
  return result;
}


unsigned int __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        unsigned int __n)
{
  unsigned int v2; // edx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > **p_n; // eax
  unsigned int result; // eax
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  v2 = this->_M_finish - this->_M_start_of_storage._M_data;
  v5 = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)v2;
  if ( __n > -2 - v2 )
    stlp_std::__stl_throw_length_error("basic_string");
  p_n = &v5;
  if ( __n >= v2 )
    p_n = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > **)&__n;
  result = (unsigned int)&(*p_n)->_M_buffers._M_static_buf[v2 + 1];
  if ( result == -1 || result < v2 )
    return -2;
  return result;
}


unsigned int __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_compute_next_size(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n)
{
  unsigned int v2; // edx
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > **p_n; // eax
  unsigned int result; // eax
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  v2 = this->_M_finish - this->_M_start_of_storage._M_data;
  v5 = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)v2;
  if ( __n > 2147483646 - v2 )
    stlp_std::__stl_throw_length_error("basic_string");
  p_n = &v5;
  if ( __n >= v2 )
    p_n = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > **)&__n;
  result = (unsigned int)(*p_n)->_M_buffers._M_static_buf + v2 + 1;
  if ( result > 0x7FFFFFFE || result < v2 )
    return 2147483646;
  return result;
}


unsigned int __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_compute_next_size(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        unsigned int __n)
{
  unsigned int v2; // edx
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > **p_n; // eax
  unsigned int result; // eax
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *v5; // [esp+0h] [ebp-4h] BYREF

  v5 = this;
  v2 = this->_M_finish - this->_M_start_of_storage._M_data;
  v5 = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *)v2;
  if ( __n > 2147483646 - v2 )
    stlp_std::__stl_throw_length_error("basic_string");
  p_n = &v5;
  if ( __n >= v2 )
    p_n = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > **)&__n;
  result = (unsigned int)(*p_n)->_M_buffers._M_static_buf + v2 + 1;
  if ( result > 0x7FFFFFFE || result < v2 )
    return 2147483646;
  return result;
}
