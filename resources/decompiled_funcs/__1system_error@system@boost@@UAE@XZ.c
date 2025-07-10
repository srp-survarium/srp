void __thiscall boost::system::system_error::~system_error(boost::system::system_error *this)
{
  this->__vftable = (boost::system::system_error_vtbl *)&boost::system::system_error::`vftable';
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&this->m_what);
  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)this);
}
