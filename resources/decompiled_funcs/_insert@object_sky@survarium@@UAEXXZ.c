void __thiscall survarium::object_sky::insert(survarium::object_sky *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::scene_renderer *m_scene; // [esp-Ch] [ebp-Ch]

  m_game_scene = this->m_game_scene;
  m_scene = m_game_scene->m_game->m_renderer->m_scene;
  vostok::render::scene_renderer::set_sky_material(
    m_scene,
    m_scene,
    &m_game_scene->m_render_scene,
    &this->m_sky_material);
}
