void __thiscall std::exception::~exception(std::exception *this)
{
  bool v1; // zf

  v1 = this->_m_doFree == 0;
  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  if ( !v1 )
    free((void *)this->_m_what);
}
