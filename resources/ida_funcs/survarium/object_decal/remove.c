void __thiscall survarium::object_decal::remove(survarium::object_decal *this)
{
  vostok::render::scene_renderer::remove_decal(
    (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
    this->m_game_scene->m_game->m_renderer->m_scene,
    &this->m_game_scene->m_render_scene,
    this->m_decal_id);
}
