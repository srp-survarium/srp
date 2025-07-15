void __thiscall survarium::object_lpv_occluder::remove(survarium::object_lpv_occluder *this)
{
  vostok::render::scene_renderer::remove_lpv_occluder(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    this->m_occluder_id);
}
