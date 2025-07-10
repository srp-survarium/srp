stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall stlp_std::collate<char>::do_transform(
        stlp_std::collate<char> *this,
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *result,
        char *low,
        const char *high)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    result,
    low,
    high,
    (const stlp_std::allocator<char> *)&high);
  return result;
}
