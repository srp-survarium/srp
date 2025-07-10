void __thiscall survarium::object_particle_visual::remove(survarium::object_particle_visual *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::render::scene_renderer *m_scene; // [esp-Ch] [ebp-Ch]

  m_game_scene = this->m_game_scene;
  m_scene = m_game_scene->m_game->m_renderer->m_scene;
  vostok::render::scene_renderer::remove_particle_system_instance(
    m_scene,
    m_scene,
    &m_game_scene->m_render_scene,
    &this->m_particle_system_instance_ptr);
}
