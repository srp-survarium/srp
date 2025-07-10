stlp_std::__Named_exception *__thiscall stlp_std::__Named_exception::`scalar deleting destructor'(
        stlp_std::__Named_exception *this,
        char a2)
{
  stlp_std::__Named_exception *M_name; // eax

  M_name = (stlp_std::__Named_exception *)this->_M_name;
  this->__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::__Named_exception::`vftable';
  if ( M_name != (stlp_std::__Named_exception *)this->_M_static_name )
    free(M_name);
  std::exception::~exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
