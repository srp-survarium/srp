stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::collate<wchar_t>::do_transform(
        stlp_std::collate<wchar_t> *this,
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *result,
        wchar_t *low,
        const wchar_t *high)
{
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
    result,
    low,
    high,
    (const stlp_std::allocator<wchar_t> *)&high);
  return result;
}
