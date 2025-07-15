survarium::victory_item_core_carry_state *__thiscall survarium::victory_item_core_carry_state::`scalar deleting destructor'(
        survarium::victory_item_core_carry_state *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_item_animations,
    4u,
    2,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  `vector destructor iterator'(
    (char *)this->m_user_animations,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
