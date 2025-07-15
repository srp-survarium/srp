void __thiscall survarium::object_volume_fog::remove(survarium::object_volume_fog *this)
{
  vostok::render::scene_renderer::remove_volume_fog(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    this->m_volume_fog_id);
}
