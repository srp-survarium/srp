stlp_std::moneypunct<char,1> *__thiscall stlp_std::moneypunct<char,1>::`scalar deleting destructor'(
        stlp_std::moneypunct<char,1> *this,
        char a2)
{
  this->__vftable = (stlp_std::moneypunct<char,1>_vtbl *)&stlp_std::moneypunct<char,1>::`vftable';
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
