void __thiscall survarium::game_world::clear_resources(survarium::game_world *this)
{
  vostok::physics::world *m_physics_world; // esi
  _BYTE *v3; // ebp
  vostok::sound::world_user *v4; // eax
  survarium::damage_model_stats *m_damage_model_stats; // esi
  int f; // ebp
  survarium::damage_model_stats *v7; // eax
  void *v8; // esi
  survarium::npc_stats *m_active_npc_stats; // esi
  int v10; // ebp
  survarium::npc_stats *v11; // eax
  void *v12; // esi
  survarium::game_material_manager *m_object; // ecx
  survarium::game_material_manager *v14; // eax
  survarium::bullet_manager *m_bullet_manager; // esi
  int v16; // ebp
  survarium::bullet_manager *v17; // eax
  void *v18; // esi

  m_physics_world = this->m_physics_world;
  m_physics_world->destroy(m_physics_world);
  v3 = __RTCastToVoid((void **)&m_physics_world->__vftable);
  ((void (__thiscall *)(vostok::physics::world *, _DWORD))m_physics_world->~vostok::physics::world)(m_physics_world, 0);
  vostok::memory::g_mt_allocator.call_free(&vostok::memory::g_mt_allocator, v3);
  if ( this->m_sound_scene.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v4 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
    vostok::sound::world_user::remove_sound_scene(v4, &this->m_sound_scene);
  }
  m_damage_model_stats = this->m_damage_model_stats;
  f = (int)survarium::g_allocator.f_.f_;
  if ( m_damage_model_stats )
  {
    m_damage_model_stats->m_ui_world->destroy_window(
      m_damage_model_stats->m_ui_world,
      m_damage_model_stats->m_main_window);
    v7 = m_damage_model_stats;
    v8 = *(void **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v8, v7);
    this->m_damage_model_stats = 0;
  }
  m_active_npc_stats = this->m_active_npc_stats;
  v10 = (int)survarium::g_allocator.f_.f_;
  if ( m_active_npc_stats )
  {
    m_active_npc_stats->m_ui_world->destroy_window(m_active_npc_stats->m_ui_world, m_active_npc_stats->m_main_window);
    v11 = m_active_npc_stats;
    v12 = *(void **)(v10 + 20);
    *(_BYTE *)(v10 + 42) = 0;
    vostok_mspace_free(v12, v11);
    this->m_active_npc_stats = 0;
  }
  this->m_ai_navigation_world->clear_resources(this->m_ai_navigation_world);
  this->m_ai_world->clear_resources(this->m_ai_world);
  this->show_ui(this, 0);
  if ( this->m_text_manager )
    vostok::render::game::renderer::hide_text_manager(
      (vostok::render::game::renderer *)this->m_game,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
      (survarium::flash_text_manager *)&this->m_render_scene_view);
  m_object = this->m_game_material_manager.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::game_material_manager::clear_resources(m_object);
    v14 = this->m_game_material_manager.m_object;
    this->m_game_material_manager.m_object = 0;
    if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
    m_bullet_manager = this->m_bullet_manager;
    v16 = (int)survarium::g_allocator.f_.f_;
    if ( m_bullet_manager )
    {
      survarium::bullet_manager::~bullet_manager(this->m_bullet_manager);
      v17 = m_bullet_manager;
      v18 = *(void **)(v16 + 20);
      *(_BYTE *)(v16 + 42) = 0;
      vostok_mspace_free(v18, v17);
      this->m_bullet_manager = 0;
    }
  }
}
