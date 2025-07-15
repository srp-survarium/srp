void __thiscall survarium::weapon_core_throw_grenade_state::~weapon_core_throw_grenade_state(
        survarium::weapon_core_throw_grenade_state *this)
{
  vostok::ai::fsm *p_m_logic; // edi
  vostok::resources::unmanaged_resource *v3; // ebx
  vostok::ai::fsm *v4; // ecx
  vostok::ai::fsm *i; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::ai::fsm *v7; // [esp-4h] [ebp-14h]
  const char *v8; // [esp+0h] [ebp-10h]
  const char *v9; // [esp+4h] [ebp-Ch]
  unsigned int v10; // [esp+8h] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+Ch] [ebp-4h] BYREF

  p_m_logic = &this->m_logic;
  v3 = &this->vostok::resources::unmanaged_resource;
  this->survarium::weapon_core_throw_grenade_state_base::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_throw_grenade_state_vtbl *)&survarium::weapon_core_throw_grenade_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_throw_grenade_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_throw_grenade_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  vostok::ai::fsm::clear_transitions((vostok::ai::fsm *)this, (int)&this->m_logic);
  for ( i = p_m_logic; ; i = &this->m_logic )
  {
    pointer = vostok::ai::fsm::pop_state(v4, i);
    if ( !pointer )
      break;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      survarium::g_allocator,
      &pointer,
      v8,
      v9,
      v10);
    v4 = v7;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_grenade_set);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&this->m_logic.m_on_transition);
  vostok::resources::unmanaged_resource::~unmanaged_resource(v3);
}
