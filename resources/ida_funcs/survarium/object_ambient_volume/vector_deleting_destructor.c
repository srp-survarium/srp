survarium::object_ambient_volume *__thiscall survarium::object_ambient_volume::`vector deleting destructor'(
        survarium::object_ambient_volume *this,
        char a2)
{
  this->__vftable = (survarium::object_ambient_volume_vtbl *)&survarium::object_ambient_volume::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
