void __thiscall survarium::base_game_scene::tick(
        survarium::base_game_scene *this,
        vostok::math::float4x4 *frame_delta_in_ms,
        survarium::scheduler::record *current_time_in_ms,
        const bool __formal)
{
  survarium::game_camera **p_m_active_camera; // eax
  bool *p_m_windowed_changed; // ecx
  vostok::input::world *v7; // eax
  vostok::input::mouse *v8; // ebx
  void (__thiscall **p_set_exclusive_mode)(vostok::input::mouse *, bool); // esi
  bool v10; // al
  survarium::drawable_object *i; // edi

  p_m_active_camera = &this->m_camera_director->m_active_camera;
  if ( *p_m_active_camera )
    (*p_m_active_camera)->tick(*p_m_active_camera);
  if ( frame_delta_in_ms )
    survarium::scheduler::on_frame(
      (survarium::scheduler *)this,
      &this->m_scheduler.m_inactive_objects._M_impl._M_start,
      frame_delta_in_ms,
      current_time_in_ms);
  p_m_windowed_changed = &this->m_game->m_render_output_window.m_object->m_windowed_changed;
  if ( *p_m_windowed_changed )
  {
    *p_m_windowed_changed = 0;
    v7 = this->m_game->input_world(this->m_game);
    v8 = v7->get_mouse(v7);
    p_set_exclusive_mode = &v8->set_exclusive_mode;
    v10 = this->mouse_exclusive_mode(this);
    (*p_set_exclusive_mode)(v8, v10);
  }
  for ( i = this->m_drawable_objects.m_first; i; i = i->next )
    i->draw(i);
}
