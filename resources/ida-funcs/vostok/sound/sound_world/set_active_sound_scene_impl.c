void __thiscall vostok::sound::sound_world::set_active_sound_scene_impl(
        vostok::sound::sound_world *this,
        vostok::sound::sound_scene *scene)
{
  vostok::sound::sound_scene *m_current_scene; // esi

  m_current_scene = this->m_current_scene;
  if ( m_current_scene != scene )
  {
    if ( m_current_scene )
      m_current_scene->m_fade_state = detail;
    this->m_current_scene = scene;
    if ( scene )
      vostok::sound::sound_scene::fade_in(scene, this);
  }
}
