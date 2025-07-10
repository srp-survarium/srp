void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__f,
        const wchar_t *__l,
        const stlp_std::allocator<wchar_t> *__a)
{
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize<wchar_t const *>(
    this,
    __f,
    __l,
    (const stlp_std::forward_iterator_tag *)&__l);
}
