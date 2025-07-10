void __thiscall survarium::game_world::~game_world(survarium::game_world *this)
{
  int f; // ecx
  int v3; // ebp
  _BYTE *v4; // esi
  void *v5; // eax
  void *v6; // esi
  survarium::npc_stats *m_active_npc_stats; // esi
  int v8; // ebp
  survarium::npc_stats *v9; // eax
  void *v10; // esi
  survarium::step_manager *m_step_manager; // eax
  void *v12; // esi
  survarium::damage_model_stats *m_damage_model_stats; // esi
  int v14; // ebp
  survarium::damage_model_stats *v15; // eax
  void *v16; // esi
  vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v17; // ecx
  survarium::human_npc *m_object; // eax
  survarium::human_npc *v19; // eax
  vostok::resources::unmanaged_resource *v20; // ecx
  unsigned __int8 *p_m_death_particles_it; // esi
  int i; // ebp
  int v23; // eax
  survarium::game_world::bullet_tracer *M_start; // eax
  void *v25; // esi
  survarium::game_material_manager *v26; // eax
  vostok::render::culling::portal_sector_structure *v27; // eax
  survarium::simple_game_project *v28; // eax
  vostok::math::float3 *v29; // eax
  void *v30; // esi
  vostok::math::float3 *v31; // eax
  void *v32; // esi

  f = (int)survarium::g_allocator.f_.f_;
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::game_world_vtbl *)&survarium::game_world::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::engine'};
  this->vostok::ai::engine::__vftable = (vostok::ai::engine_vtbl *)&survarium::game_world::`vftable'{for `vostok::ai::engine'};
  this->vostok::ai::navigation::engine::__vftable = (vostok::ai::navigation::engine_vtbl *)&survarium::game_world::`vftable'{for `vostok::ai::navigation::engine'};
  this->survarium::bullet_manager_engine::__vftable = (survarium::bullet_manager_engine_vtbl *)&survarium::game_world::`vftable'{for `survarium::bullet_manager_engine'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::game_world::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::game_world::`vftable'{for `vostok::input::handler'};
  v3 = f;
  if ( this->m_free_fly_camera )
  {
    v4 = __RTCastToVoid((void **)&this->m_free_fly_camera->__vftable);
    ((void (__thiscall *)(vostok::input::handler *, _DWORD))this->m_free_fly_camera->~vostok::input::handler)(
      &this->m_free_fly_camera->vostok::input::handler,
      0);
    if ( v4 )
    {
      v5 = v4;
      v6 = *(void **)(v3 + 20);
      *(_BYTE *)(v3 + 42) = 0;
      vostok_mspace_free(v6, v5);
    }
    f = (int)survarium::g_allocator.f_.f_;
    this->m_free_fly_camera = 0;
  }
  m_active_npc_stats = this->m_active_npc_stats;
  v8 = f;
  if ( m_active_npc_stats )
  {
    m_active_npc_stats->m_ui_world->destroy_window(m_active_npc_stats->m_ui_world, m_active_npc_stats->m_main_window);
    v9 = m_active_npc_stats;
    v10 = *(void **)(v8 + 20);
    *(_BYTE *)(v8 + 42) = 0;
    vostok_mspace_free(v10, v9);
    f = (int)survarium::g_allocator.f_.f_;
    this->m_active_npc_stats = 0;
  }
  m_step_manager = this->m_step_manager;
  if ( m_step_manager )
  {
    v12 = *(void **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v12, m_step_manager);
    f = (int)survarium::g_allocator.f_.f_;
    this->m_step_manager = 0;
  }
  m_damage_model_stats = this->m_damage_model_stats;
  v14 = f;
  if ( m_damage_model_stats )
  {
    m_damage_model_stats->m_ui_world->destroy_window(
      m_damage_model_stats->m_ui_world,
      m_damage_model_stats->m_main_window);
    v15 = m_damage_model_stats;
    v16 = *(void **)(v14 + 20);
    *(_BYTE *)(v14 + 42) = 0;
    vostok_mspace_free(v16, v15);
    this->m_damage_model_stats = 0;
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *>)this->m_victory_items._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *>)this->m_victory_items._M_impl._M_start);
  if ( this->m_victory_items._M_impl._M_start )
    this->m_victory_items._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_victory_items._M_impl._M_end_of_storage.m_allocator,
      this->m_victory_items._M_impl._M_start);
  m_object = this->m_selected_npc.m_object;
  if ( m_object )
  {
    v17 = (vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v17 )
    {
      v19 = this->m_selected_npc.m_object;
      if ( v19 )
        v20 = &v19->survarium::game_object_;
      else
        v20 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v19->vostok::resources::unmanaged_intrusive_base, v20);
    }
  }
  vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(
    v17,
    (int)&this->m_npcs);
  p_m_death_particles_it = &this->m_death_particles_it;
  for ( i = 15; i >= 0; --i )
  {
    v23 = *((_DWORD *)p_m_death_particles_it - 1);
    p_m_death_particles_it -= 4;
    if ( v23 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v23 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)p_m_death_particles_it + 208),
        *(vostok::resources::unmanaged_resource **)p_m_death_particles_it);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *>,survarium::game_world::bullet_tracer>(
    (stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *>)this->m_bullet_tracers._M_impl._M_finish,
    (stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *>)this->m_bullet_tracers._M_impl._M_start);
  M_start = this->m_bullet_tracers._M_impl._M_start;
  if ( M_start )
  {
    v25 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v25, M_start);
  }
  v26 = this->m_game_material_manager.m_object;
  if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_game_material_manager.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_game_material_manager.m_object);
  v27 = this->m_portal_sector_structure.m_object;
  if ( v27 && !_InterlockedExchangeAdd(&v27->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_portal_sector_structure.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_portal_sector_structure.m_object);
  v28 = this->m_game_project.m_object;
  if ( v28 && !_InterlockedExchangeAdd(&v28->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_game_project.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_game_project.m_object);
  v29 = this->m_enemies_for_team_2._M_impl._M_start;
  if ( v29 )
  {
    v30 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v30, v29);
  }
  v31 = this->m_enemies_for_team_1._M_impl._M_start;
  if ( v31 )
  {
    v32 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v32, v31);
  }
  survarium::game_world_ui::~game_world_ui(&this->game_ui);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  survarium::base_game_scene::~base_game_scene(this);
}
