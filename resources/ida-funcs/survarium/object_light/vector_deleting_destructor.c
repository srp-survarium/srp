survarium::object_light *__thiscall survarium::object_light::`vector deleting destructor'(
        survarium::object_light *this,
        char a2)
{
  this->__vftable = (survarium::object_light_vtbl *)&survarium::object_light::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
