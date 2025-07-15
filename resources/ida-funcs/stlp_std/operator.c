bool __cdecl stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__x,
        const char *__s)
{
  unsigned int __n; // [esp+20h] [ebp-4h]

  __n = stlp_std::char_traits<char>::length(__s);
  return __x->_M_finish - __x->_M_start_of_storage._M_data == __n && !memcmp(__x->_M_start_of_storage._M_data, __s, __n);
}


bool __cdecl stlp_std::operator!=<char,stlp_std::char_traits<char>>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__x,
        const stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__y)
{
  return !stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__x, __y);
}


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


bool __cdecl stlp_std::operator!=<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__x,
        const stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__y)
{
  return !stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(__x, __y);
}
