void __thiscall survarium::game_world::tick(
        survarium::game_world *this,
        survarium::game_world_ui *frame_delta_ms,
        vostok::animation::subscribed_channel **current_time_in_ms,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> is_game_paused)
{
  survarium::camera_director *m_camera_director; // eax
  survarium::bullet_manager *m_bullet_manager; // ecx
  survarium::flash_text_manager *m_text_manager; // esi

  m_camera_director = this->m_camera_director;
  if ( m_camera_director->m_active_camera )
    m_camera_director->m_active_camera->tick(m_camera_director->m_active_camera);
  if ( !LOBYTE(is_game_paused.m_object) && this->m_physics_world )
    this->m_physics_world->tick(this->m_physics_world, (const unsigned int)current_time_in_ms);
  m_bullet_manager = this->m_bullet_manager;
  if ( m_bullet_manager && !LOBYTE(is_game_paused.m_object) )
    survarium::bullet_manager::tick(m_bullet_manager, this->m_game->m_current_time_in_ms);
  if ( this->m_is_dictionary_created )
    survarium::game_world::tick_npcs(
      (survarium::game_world *)m_bullet_manager,
      (const vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
      current_time_in_ms,
      is_game_paused);
  if ( !LOBYTE(is_game_paused.m_object) )
    this->m_ai_world->tick(this->m_ai_world);
  survarium::game_world::update_npc_stats((survarium::game_world *)m_bullet_manager, (int)this);
  if ( this->m_is_ui_shown )
    survarium::game_world_ui::update_ui(frame_delta_ms, &this->game_ui, (int)this);
  m_text_manager = this->m_text_manager;
  if ( m_text_manager->need_capture )
  {
    Scaleform::GFx::DrawTextManager::Capture(m_text_manager->text_manager_impl, 1);
    m_text_manager->need_capture = 0;
  }
}
