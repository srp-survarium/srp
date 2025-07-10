void __thiscall survarium::object_sky_ambient_occlusion::remove(survarium::object_sky_ambient_occlusion *this)
{
  vostok::render::scene_renderer::remove_sky_ambient_occlusion(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    this->m_sky_ao_volume_id);
}
