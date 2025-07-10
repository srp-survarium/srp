void __thiscall survarium::booby_trap_set::tick(
        survarium::booby_trap_set *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::game_world *m_game_world; // eax
  vostok::render::scene_renderer *m_scene; // [esp-10h] [ebp-58h]
  char is_placing_allowed; // [esp+4h] [ebp-44h]
  vostok::math::float4x4 transform; // [esp+8h] [ebp-40h] BYREF

  if ( this->m_amount )
  {
    is_placing_allowed = survarium::booby_trap_set_core::get_visible_place_transform(this, &transform);
    if ( !survarium::booby_trap_set::pick_current_ghost_model(this, &transform, is_placing_allowed) )
    {
      m_game_world = this->m_game_world;
      m_scene = m_game_world->m_game->m_renderer->m_scene;
      vostok::render::scene_renderer::update_model(
        m_scene,
        m_scene,
        &m_game_world->m_render_scene,
        &this->m_current_rendering_model.m_object->m_render_model,
        &transform);
    }
  }
  else
  {
    survarium::booby_trap_set::toggle_ghost_model(this, 0);
  }
}
