std::bad_alloc *__thiscall std::bad_alloc::`vector deleting destructor'(std::bad_alloc *this, char a2)
{
  this->__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  std::exception::~exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
