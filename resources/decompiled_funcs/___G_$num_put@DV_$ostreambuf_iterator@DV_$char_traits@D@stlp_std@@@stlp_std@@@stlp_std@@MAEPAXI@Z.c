stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *__thiscall stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`scalar deleting destructor'(
        stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        char a2)
{
  this->__vftable = (stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > >_vtbl *)&stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
