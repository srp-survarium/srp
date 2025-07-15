void __thiscall boost::bad_function_call::bad_function_call(boost::bad_function_call *this)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+8h] [ebp-18h] BYREF

  __str._M_finish = (char *)&__str;
  __str._M_start_of_storage._M_data = (char *)&__str;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
    &__str,
    "call to empty boost::function",
    "");
  stlp_std::__Named_exception::__Named_exception(this, &__str);
  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)__str._M_start_of_storage._M_data;
  this->__vftable = (boost::bad_function_call_vtbl *)&stlp_std::runtime_error::`vftable';
  if ( M_data != &__str && M_data )
  {
    if ( (unsigned int)(__str._M_buffers._M_end_of_storage - (char *)M_data) > 0x80 )
    {
      operator delete(M_data);
      this->__vftable = (boost::bad_function_call_vtbl *)&boost::bad_function_call::`vftable';
      return;
    }
    stlp_std::__node_alloc::_M_deallocate(M_data, __str._M_buffers._M_end_of_storage - (char *)M_data);
  }
  this->__vftable = (boost::bad_function_call_vtbl *)&boost::bad_function_call::`vftable';
}
