void __thiscall std::bad_alloc::bad_alloc(std::bad_alloc *this, const std::bad_alloc *__that)
{
  std::exception::exception(this, __that);
  this->__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
}
