survarium::object_ambient_light *__thiscall survarium::object_ambient_light::`vector deleting destructor'(
        survarium::object_ambient_light *this,
        char a2)
{
  this->__vftable = (survarium::object_ambient_light_vtbl *)&survarium::object_ambient_light::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
