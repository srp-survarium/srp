survarium::weapon_core_idle_state_base *__thiscall survarium::weapon_core_base_state::`vector deleting destructor'(
        survarium::weapon_core_idle_state_base *this,
        char a2)
{
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
