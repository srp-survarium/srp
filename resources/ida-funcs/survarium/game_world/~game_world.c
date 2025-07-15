void __thiscall survarium::game_world::~game_world(survarium::game_world *this)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  unsigned __int8 *m_third_person_game_effect_presenters; // esi
  int v8; // edi
  stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer> > *v9; // ecx
  survarium::first_person_game_effect_presenter *v10; // ecx
  vostok::memory::doug_lea_allocator *v11; // [esp-4h] [ebp-18h]
  const char *v12; // [esp+0h] [ebp-14h]
  const char *v13; // [esp+4h] [ebp-10h]
  unsigned int v14; // [esp+8h] [ebp-Ch]

  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::game_world_vtbl *)&survarium::game_world::`vftable'{for `survarium::base_game_scene'};
  this->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::bullet_manager_engine'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::game_world::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::game_world::`vftable'{for `vostok::input::handler'};
  survarium::g_animations_registry.m_has_been_queried = 0;
  survarium::g_animations_registry.m_is_valid = 1;
  v2 = survarium::g_allocator;
  if ( this->m_free_fly_camera )
  {
    v3 = __RTCastToVoid((void **)&this->m_free_fly_camera->__vftable);
    ((void (__thiscall *)(vostok::input::handler *, _DWORD))this->m_free_fly_camera->~vostok::input::handler)(
      &this->m_free_fly_camera->vostok::input::handler,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v2, v3, v12, v13, v14);
    this->m_free_fly_camera = 0;
  }
  v5 = survarium::g_allocator;
  if ( this->m_demo_camera )
  {
    v6 = __RTCastToVoid((void **)&this->m_demo_camera->__vftable);
    vostok::memory::doug_lea_allocator::free_impl(v11, (int)v5, v6, v12, v13, v14);
    this->m_demo_camera = 0;
  }
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::damage_model_stats>(
    survarium::g_allocator,
    &this->m_damage_model_stats,
    v12,
    v13,
    v14);
  m_third_person_game_effect_presenters = this->m_third_person_game_effect_presenters;
  v8 = 20;
  do
  {
    (**(void (__thiscall ***)(unsigned __int8 *, _DWORD))m_third_person_game_effect_presenters)(
      m_third_person_game_effect_presenters,
      0);
    m_third_person_game_effect_presenters += 560;
    --v8;
  }
  while ( v8 );
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_material_manager);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_match);
  stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>::~_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>(
    v9,
    (void **)&this->m_bullet_tracers._M_impl._M_start);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_portal_sector_structure);
  survarium::first_person_game_effect_presenter::~first_person_game_effect_presenter(
    v10,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_first_person_game_effect_presenter);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_game_project);
  survarium::game_world_ui::~game_world_ui(&this->game_ui);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  survarium::base_game_scene::~base_game_scene(this);
}
