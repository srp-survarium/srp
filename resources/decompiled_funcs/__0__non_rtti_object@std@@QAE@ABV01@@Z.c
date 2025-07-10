void __thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const std::__non_rtti_object *that)
{
  std::bad_typeid::bad_typeid(this, that);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
}
