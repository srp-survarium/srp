BOOL __cdecl stlp_std::operator!=<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__x,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__y)
{
  char *M_data; // edx

  M_data = __y->_M_start_of_storage._M_data;
  return __x->_M_finish - __x->_M_start_of_storage._M_data != __y->_M_finish - M_data
      || stlp_std::char_traits<char>::compare(
           __x->_M_start_of_storage._M_data,
           M_data,
           __x->_M_finish - __x->_M_start_of_storage._M_data);
}
