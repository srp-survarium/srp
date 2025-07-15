void __thiscall survarium::victory_item_core_carry_state::register_animations(
        survarium::victory_item_core_carry_state *this,
        survarium::animations_registry *animations_registry)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // esi
  survarium::victory_item_core_carry_state *v3; // edi

  v2 = this->m_user_animations[0];
  v3 = this + 1;
  while ( v2 != (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v3 )
  {
    survarium::animations_registry::register_animation(v2, animations_registry, v2 + 1);
    v2 += 2;
  }
}
