void __thiscall std::bad_exception::~bad_exception(std::bad_exception *this)
{
  this->__vftable = (std::bad_exception_vtbl *)&std::bad_exception::`vftable';
  std::exception::~exception(this);
}
