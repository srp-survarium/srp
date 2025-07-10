bool __cdecl stlp_std::operator!=<char,stlp_std::char_traits<char>>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__x,
        const stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__y)
{
  return !stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__x, __y);
}
