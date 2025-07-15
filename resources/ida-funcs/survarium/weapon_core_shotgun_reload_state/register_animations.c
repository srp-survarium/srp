void __thiscall survarium::weapon_core_shotgun_reload_state::register_animations(
        survarium::weapon_core_shotgun_reload_state *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *i; // esi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *j; // edi

  for ( i = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this->m_logic->m_states.m_first;
        i;
        i = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)i[1].m_object )
  {
    for ( j = i + 73; j != &i[77]; j += 2 )
      survarium::animations_registry::register_animation(j, animations_registry, j + 1);
    survarium::animations_registry::register_animation(i + 77, animations_registry, i + 77);
  }
}
