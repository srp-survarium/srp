stlp_std::ios_base::failure *__thiscall stlp_std::ios_base::failure::`vector deleting destructor'(
        stlp_std::ios_base::failure *this,
        char a2)
{
  this->__vftable = (stlp_std::ios_base::failure_vtbl *)&stlp_std::ios_base::failure::`vftable';
  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
