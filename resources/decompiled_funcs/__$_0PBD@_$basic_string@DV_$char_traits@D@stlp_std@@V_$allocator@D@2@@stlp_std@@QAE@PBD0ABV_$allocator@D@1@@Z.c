void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        const char *__l,
        const stlp_std::allocator<char> *__a)
{
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize<char const *>(
    this,
    __f,
    __l,
    (const stlp_std::forward_iterator_tag *)&__l);
}
