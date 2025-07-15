void __thiscall std::bad_cast::bad_cast(std::bad_cast *this, const std::bad_cast *that)
{
  std::exception::exception(this, that);
  this->__vftable = (std::bad_cast_vtbl *)&std::bad_cast::`vftable';
}


void __thiscall std::bad_cast::bad_cast(std::bad_cast *this, const char *_Message)
{
  std::exception::exception(this, &_Message);
  this->__vftable = (std::bad_cast_vtbl *)&std::bad_cast::`vftable';
}
