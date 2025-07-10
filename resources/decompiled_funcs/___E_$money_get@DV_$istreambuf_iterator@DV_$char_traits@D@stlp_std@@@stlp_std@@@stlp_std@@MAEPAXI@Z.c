stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *__thiscall stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vector deleting destructor'(
        stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        char a2)
{
  this->__vftable = (stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > >_vtbl *)&stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
