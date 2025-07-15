void __thiscall stlp_std::__Named_exception::~__Named_exception(stlp_std::out_of_range *this)
{
  stlp_std::out_of_range *M_name; // eax

  M_name = (stlp_std::out_of_range *)this->_M_name;
  this->__vftable = (stlp_std::out_of_range_vtbl *)&stlp_std::__Named_exception::`vftable';
  if ( M_name != (stlp_std::out_of_range *)this->_M_static_name )
    free(M_name);
  std::exception::~exception(this);
}
