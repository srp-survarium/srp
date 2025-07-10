void __thiscall std::bad_typeid::bad_typeid(std::bad_typeid *this, const std::bad_typeid *that)
{
  std::exception::exception(this, that);
  this->__vftable = (std::bad_typeid_vtbl *)&std::bad_typeid::`vftable';
}
