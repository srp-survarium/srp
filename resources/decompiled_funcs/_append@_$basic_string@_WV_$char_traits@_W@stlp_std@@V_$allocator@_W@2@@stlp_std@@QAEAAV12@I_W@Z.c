stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::append(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n,
        wchar_t __c)
{
  wchar_t *M_finish; // ecx
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *M_data; // eax
  unsigned int v6; // eax
  unsigned int size; // eax

  if ( __n )
  {
    M_finish = this->_M_finish;
    M_data = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data;
    if ( __n > 2147483646 - (((char *)this->_M_finish - (char *)M_data) >> 1) )
      stlp_std::__stl_throw_length_error("basic_string");
    if ( M_data == this )
      v6 = 16 - (((char *)M_finish - (char *)this) >> 1);
    else
      v6 = this->_M_buffers._M_end_of_storage - M_finish;
    if ( __n >= v6 )
    {
      size = stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_compute_next_size(
               this,
               __n);
      stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_reserve(
        this,
        size);
    }
    stlp_std::priv::__ufill<wchar_t *,wchar_t,int>(this->_M_finish + 1, &this->_M_finish[__n], &__c);
    this->_M_finish[__n] = 0;
    *this->_M_finish = __c;
    this->_M_finish += __n;
  }
  return this;
}
