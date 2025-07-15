survarium::weapon_core_idle_state *__thiscall survarium::weapon_core_idle_state::`scalar deleting destructor'(
        survarium::weapon_core_idle_state *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_weapon_animation);
  `vector destructor iterator'(
    (char *)this->m_user_animations,
    4u,
    8,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
