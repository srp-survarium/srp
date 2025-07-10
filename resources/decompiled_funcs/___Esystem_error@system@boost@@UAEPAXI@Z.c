boost::system::system_error *__thiscall boost::system::system_error::`vector deleting destructor'(
        boost::system::system_error *this,
        char a2)
{
  this->__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&this->m_what);
  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
