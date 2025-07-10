unsigned int __fastcall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(
        int a1,
        const char *__s,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __pos)
{
  return stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(
           this,
           __s,
           __pos,
           strlen(__s));
}
