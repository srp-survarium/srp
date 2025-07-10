stlp_std::time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *__thiscall stlp_std::time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`scalar deleting destructor'(
        stlp_std::time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > > *this,
        char a2)
{
  stlp_std::time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::~time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
