survarium::object_sky_ambient_occlusion *__thiscall survarium::object_sky_ambient_occlusion::`vector deleting destructor'(
        survarium::object_sky_ambient_occlusion *this,
        char a2)
{
  this->__vftable = (survarium::object_sky_ambient_occlusion_vtbl *)&survarium::object_sky_ambient_occlusion::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
