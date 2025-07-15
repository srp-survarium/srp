survarium::object_environment_probe *__thiscall survarium::object_environment_probe::`vector deleting destructor'(
        survarium::object_environment_probe *this,
        char a2)
{
  this->__vftable = (survarium::object_environment_probe_vtbl *)&survarium::object_environment_probe::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
