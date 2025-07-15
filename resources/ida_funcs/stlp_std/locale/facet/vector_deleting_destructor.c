stlp_std::locale::facet *__thiscall stlp_std::locale::facet::`vector deleting destructor'(
        stlp_std::locale::facet *this,
        char a2)
{
  this->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::locale::facet::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
