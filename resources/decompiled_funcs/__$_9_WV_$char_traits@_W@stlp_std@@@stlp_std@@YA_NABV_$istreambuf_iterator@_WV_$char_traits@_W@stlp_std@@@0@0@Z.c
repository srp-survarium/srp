bool __cdecl stlp_std::operator!=<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__x,
        const stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__y)
{
  return !stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(__x, __y);
}
