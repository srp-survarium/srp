stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall stlp_std::numpunct<char>::do_grouping(
        stlp_std::numpunct<wchar_t> *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v2; // eax

  v2 = result;
  result->_M_finish = (char *)result;
  result->_M_start_of_storage._M_data = (char *)result;
  *result->_M_finish = 0;
  return v2;
}
