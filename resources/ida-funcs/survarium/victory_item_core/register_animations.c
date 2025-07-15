void __thiscall survarium::victory_item_core::register_animations(
        survarium::victory_item_core *this,
        survarium::animations_registry *animations_registry)
{
  vostok::ai::fsm_state *i; // esi

  survarium::weapon_user_animations_container::register_animations(
    (survarium::weapon_user_animations_container *)this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this->m_portable_interactive_object->m_user_animations_selector.m_animations.m_object,
    animations_registry);
  for ( i = this->m_logic.m_states.m_first; i; i = i->next )
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::animations_registry *))i->__vftable[1].~vostok::ai::fsm_state)(
      i,
      animations_registry);
}
