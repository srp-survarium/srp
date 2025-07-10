stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *__thiscall stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vector deleting destructor'(
        stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        char a2)
{
  stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::~time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
