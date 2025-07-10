stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::numpunct<wchar_t>::do_truename(
        stlp_std::numpunct<wchar_t> *this,
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *result)
{
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *v2; // esi

  v2 = result;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
    result,
    (wchar_t *)L"true",
    (const stlp_std::allocator<wchar_t> *)&result);
  return v2;
}
