void __thiscall survarium::pvp_match_core::~pvp_match_core(survarium::pvp_match_core *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  survarium::game_world_core *v3; // eax
  survarium::bullet_manager *m_bullet_manager; // edi
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  survarium::game_world_core *m_game_world_core; // [esp-2h] [ebp-14h]

  m_game_world_core = this->m_game_world_core;
  this->__vftable = (survarium::pvp_match_core_vtbl *)&survarium::pvp_match_core::`vftable';
  survarium::game_world_core::~game_world_core((survarium::game_world_core *)this, (int)m_game_world_core);
  v3 = this->m_game_world_core;
  if ( v3 )
  {
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      v3,
      "survarium::pvp_match_core::~pvp_match_core",
      ".\\pvp_match_core.cpp",
      101u);
    this->m_game_world_core = 0;
  }
  m_bullet_manager = this->m_bullet_manager;
  if ( m_bullet_manager )
  {
    if ( m_bullet_manager->m_bullets_allocator_ref.m_initialized )
    {
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v2,
        (int *)m_bullet_manager->m_bullets_allocator_ref.m_variable);
      m_bullet_manager->m_bullets_allocator_ref.m_initialized = 0;
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_bullet_manager->m_bullets_memory_ptr);
    m_bullet_manager->m_bullets.m_end = m_bullet_manager->m_bullets.m_begin;
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      m_bullet_manager,
      "survarium::pvp_match_core::~pvp_match_core",
      ".\\pvp_match_core.cpp",
      102u);
    this->m_bullet_manager = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_material_manager);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_project);
  survarium::registry_of_artefacts::unregister_artefacts(
    v5,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&this->m_game_rules);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
