stlp_std::time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *__thiscall stlp_std::time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`vector deleting destructor'(
        stlp_std::time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        char a2)
{
  stlp_std::time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::~time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
