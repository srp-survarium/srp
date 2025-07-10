void __thiscall std::bad_exception::bad_exception(std::bad_exception *this, const char *_Message)
{
  std::exception::exception(this, &_Message);
  this->__vftable = (std::bad_exception_vtbl *)&std::bad_exception::`vftable';
}
