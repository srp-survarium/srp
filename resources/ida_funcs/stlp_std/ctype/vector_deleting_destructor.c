stlp_std::ctype<char> *__thiscall stlp_std::ctype<char>::`vector deleting destructor'(
        stlp_std::ctype<char> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->_M_delete;
  this->__vftable = (stlp_std::ctype<char>_vtbl *)&stlp_std::ctype<char>::`vftable';
  if ( !v3 )
    operator delete[]((void *)this->_M_ctype_table);
  stlp_std::locale::facet::~facet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
