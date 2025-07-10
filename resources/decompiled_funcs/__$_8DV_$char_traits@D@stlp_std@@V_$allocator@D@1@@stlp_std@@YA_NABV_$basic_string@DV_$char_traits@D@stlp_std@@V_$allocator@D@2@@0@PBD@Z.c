bool __cdecl stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__x,
        const char *__s)
{
  unsigned int __n; // [esp+20h] [ebp-4h]

  __n = stlp_std::char_traits<char>::length(__s);
  return __x->_M_finish - __x->_M_start_of_storage._M_data == __n && !memcmp(__x->_M_start_of_storage._M_data, __s, __n);
}
