void __thiscall survarium::weapon_core_chamber_a_round_state::~weapon_core_chamber_a_round_state(
        survarium::weapon_core_show_state *this,
        survarium::weapon_core_show_state *thisa)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_m_time_scale; // esi
  int i; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  int j; // edi

  p_m_time_scale = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_time_scale;
  for ( i = 3; i >= 0; --i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(--p_m_time_scale);
  v4 = &thisa->m_user_animations[0][0];
  for ( j = 3; j >= 0; --j )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(--v4);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&thisa->m_animation_to_wait_for);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&thisa->vostok::resources::unmanaged_resource);
}
