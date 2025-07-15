void __thiscall survarium::victory_item_core_put_state::register_animations(
        survarium::victory_item_core_put_state *this,
        survarium::animations_registry *animations_registry)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // esi
  float *p_m_time_scale; // edi

  v2 = this->m_user_animations[0];
  p_m_time_scale = &this->m_time_scale;
  while ( v2 != (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_time_scale )
  {
    survarium::animations_registry::register_animation(v2, animations_registry, v2 + 1);
    v2 += 2;
  }
}
