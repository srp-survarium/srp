std::__non_rtti_object *__thiscall std::bad_typeid::`vector deleting destructor'(std::__non_rtti_object *this, char a2)
{
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::bad_typeid::`vftable';
  std::exception::~exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
