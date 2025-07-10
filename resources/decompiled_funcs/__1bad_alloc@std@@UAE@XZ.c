void __thiscall std::bad_alloc::~bad_alloc(std::bad_alloc *this)
{
  this->__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  std::exception::~exception(this);
}
