std::bad_cast *__thiscall std::bad_cast::`vector deleting destructor'(std::bad_cast *this, char a2)
{
  this->__vftable = (std::bad_cast_vtbl *)&std::bad_cast::`vftable';
  std::exception::~exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
