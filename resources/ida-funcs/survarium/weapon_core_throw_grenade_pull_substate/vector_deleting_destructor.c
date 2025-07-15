survarium::weapon_core_throw_grenade_idle_substate *__thiscall survarium::weapon_core_throw_grenade_pull_substate::`vector deleting destructor'(
        survarium::weapon_core_throw_grenade_idle_substate *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_user_animations,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
