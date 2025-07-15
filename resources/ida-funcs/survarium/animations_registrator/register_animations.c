void __thiscall survarium::animations_registrator<survarium::pistol_weapon_core_idle_state,survarium::weapon_core_idle_state_base>::register_animations(
        survarium::animations_registrator<survarium::pistol_weapon_core_idle_state,survarium::weapon_core_idle_state_base> *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v3; // esi
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // esi
  vostok::resources::resource_reconstruction_info *v6; // edi

  v3 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1];
  p_m_flags = &this[1].survarium::weapon_core_idle_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  while ( v3 != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_flags )
  {
    survarium::animations_registry::register_animation(v3, animations_registry, v3 + 1);
    v3 += 2;
  }
  v5 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].survarium::weapon_core_idle_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v6 = &this[1].vostok::resources::resource_reconstruction_info;
  while ( v5 != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v6 )
  {
    survarium::animations_registry::register_animation(v5, animations_registry, v5);
    ++v5;
  }
}


void __thiscall survarium::animations_registrator<survarium::weapon_core_fire_state,survarium::weapon_core_fire_state_base>::register_animations(
        survarium::animations_registrator<survarium::weapon_core_chamber_a_round_state,survarium::weapon_core_chamber_a_round_state_base> *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_next; // esi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v4; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // esi
  vostok::resources::resource_reconstruction_info *v6; // edi

  p_next = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].next;
  v4 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(&this[1].vostok::resources::resource_flags + 1);
  while ( p_next != v4 )
  {
    survarium::animations_registry::register_animation(p_next, animations_registry, p_next + 1);
    p_next += 2;
  }
  v5 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(&this[1].vostok::resources::resource_flags + 1);
  v6 = &this[1].vostok::resources::resource_reconstruction_info;
  while ( v5 != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v6 )
  {
    survarium::animations_registry::register_animation(v5, animations_registry, v5);
    ++v5;
  }
}


void __thiscall survarium::animations_registrator<survarium::weapon_core_hide_state,survarium::weapon_core_hide_state_base>::register_animations(
        survarium::animations_registrator<survarium::weapon_core_show_state,survarium::weapon_core_show_state_base> *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_next; // esi
  vostok::ai::fsm_state_transition **p_m_last; // edi

  p_next = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].next;
  p_m_last = &this[1].transitions.m_last;
  while ( p_next != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_last )
  {
    survarium::animations_registry::register_animation(p_next, animations_registry, p_next + 1);
    p_next += 2;
  }
}


void __thiscall survarium::animations_registrator<survarium::weapon_core_idle_state,survarium::weapon_core_idle_state_base>::register_animations(
        survarium::animations_registrator<survarium::weapon_core_idle_state,survarium::weapon_core_idle_state_base> *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v3; // esi
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // esi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v6; // edi

  v3 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1];
  p_m_flags = &this[1].survarium::weapon_core_idle_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  while ( v3 != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_flags )
  {
    survarium::animations_registry::register_animation(v3, animations_registry, v3 + 1);
    v3 += 2;
  }
  v5 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].survarium::weapon_core_idle_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v6 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(&this[1].vostok::resources::resource_flags + 1);
  while ( v5 != v6 )
  {
    survarium::animations_registry::register_animation(v5, animations_registry, v5);
    ++v5;
  }
}


void __thiscall survarium::animations_registrator<survarium::weapon_core_reload_state,survarium::weapon_core_reload_state_base>::register_animations(
        survarium::animations_registrator<survarium::weapon_core_reload_state,survarium::weapon_core_reload_state_base> *this,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_next; // esi
  vostok::ai::fsm_state_transition **p_m_last; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // esi
  vostok::resources::unmanaged_resource *v6; // edi

  p_next = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].next;
  p_m_last = &this[1].transitions.m_last;
  while ( p_next != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_last )
  {
    survarium::animations_registry::register_animation(p_next, animations_registry, p_next + 1);
    p_next += 2;
  }
  v5 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this[1].transitions.m_last;
  v6 = &this[1].vostok::resources::unmanaged_resource;
  while ( v5 != (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v6 )
  {
    survarium::animations_registry::register_animation(v5, animations_registry, v5);
    ++v5;
  }
}
