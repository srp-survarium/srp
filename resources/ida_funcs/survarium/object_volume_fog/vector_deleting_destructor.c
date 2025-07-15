survarium::object_volume_fog *__thiscall survarium::object_volume_fog::`vector deleting destructor'(
        survarium::object_volume_fog *this,
        char a2)
{
  this->__vftable = (survarium::object_volume_fog_vtbl *)&survarium::object_volume_fog::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
