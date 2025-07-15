std::bad_exception *__thiscall std::bad_exception::`vector deleting destructor'(std::bad_exception *this, char a2)
{
  this->__vftable = (std::bad_exception_vtbl *)&std::bad_exception::`vftable';
  std::exception::~exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
