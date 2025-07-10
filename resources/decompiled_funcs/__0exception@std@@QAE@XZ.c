void __thiscall std::exception::exception(std::exception *this)
{
  this->_m_what = 0;
  this->_m_doFree = 0;
  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
}
