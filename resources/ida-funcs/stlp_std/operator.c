BOOL __cdecl stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__x,
        const char *__s)
{
  char *v2; // eax
  char *M_data; // esi

  v2 = (char *)strlen(__s);
  M_data = __x->_M_start_of_storage._M_data;
  return (char *)(__x->_M_finish - M_data) == v2 && !memcmp(M_data, __s, (unsigned int)v2);
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
