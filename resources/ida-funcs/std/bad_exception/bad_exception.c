void __thiscall std::bad_exception::bad_exception(std::bad_exception *this, const std::bad_exception *__that)
{
  std::exception::exception(this, __that);
  this->__vftable = (std::bad_exception_vtbl *)&std::bad_exception::`vftable';
}


void __thiscall std::bad_exception::bad_exception(std::bad_exception *this, char *_Message)
{
  std::exception::exception(this, (const char *const *)&_Message);
  this->__vftable = (std::bad_exception_vtbl *)&std::bad_exception::`vftable';
}
