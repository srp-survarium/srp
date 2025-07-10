survarium::object_lpv_occluder *__thiscall survarium::object_lpv_occluder::`scalar deleting destructor'(
        survarium::object_lpv_occluder *this,
        char a2)
{
  this->__vftable = (survarium::object_lpv_occluder_vtbl *)&survarium::object_lpv_occluder::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
