void __thiscall survarium::object_ambient_volume::remove(survarium::object_ambient_volume *this)
{
  if ( this->m_valid )
    vostok::render::scene_renderer::remove_ambient_volume(
      (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
      this->m_game_scene->m_game->m_renderer->m_scene,
      &this->m_game_scene->m_render_scene,
      this->m_id);
}
