survarium::weapon_preview_state *__thiscall survarium::weapon_preview_state::`vector deleting destructor'(
        survarium::weapon_preview_state *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_preview_animation);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::weapon_preview_state *__thiscall survarium::weapon_preview_state::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::weapon_preview_state::`vector deleting destructor'(
           (survarium::weapon_preview_state *)(this - 24),
           a2);
}
