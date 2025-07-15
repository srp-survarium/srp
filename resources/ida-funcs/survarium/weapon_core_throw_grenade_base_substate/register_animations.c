void __thiscall survarium::weapon_core_throw_grenade_base_substate::register_animations(
        survarium::weapon_core_throw_grenade_base_substate *this,
        survarium::animations_registry *animations_registry)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // esi
  unsigned __int8 *p_m_index_of_animation_to_wait; // edi

  v2 = this->m_user_animations[0];
  p_m_index_of_animation_to_wait = &this->m_index_of_animation_to_wait;
  while ( v2 != (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_index_of_animation_to_wait )
  {
    survarium::animations_registry::register_animation(v2, animations_registry, v2 + 1);
    v2 += 2;
  }
}
