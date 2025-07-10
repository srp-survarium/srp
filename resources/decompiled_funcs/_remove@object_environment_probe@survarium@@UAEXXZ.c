void __thiscall survarium::object_environment_probe::remove(survarium::object_environment_probe *this)
{
  vostok::render::scene_renderer::remove_environment_probe(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    this->m_probe_id);
}
