void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__s,
        const stlp_std::allocator<wchar_t> *__a)
{
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize(
    this,
    __s,
    &__s[wcslen(__s)]);
}
