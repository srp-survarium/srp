void __thiscall vostok::sound::sound_world::remove_scene_from_active(
        vostok::sound::sound_world *this,
        vostok::sound::sound_scene *scene)
{
  vostok::sound::sound_scene *m_first; // eax
  vostok::sound::sound_scene *v3; // edx
  vostok::sound::sound_scene **p_m_next; // eax
  vostok::sound::sound_scene *v5; // esi
  vostok::sound::sound_scene *v6; // eax

  m_first = this->m_active_scenes.m_first;
  if ( m_first )
  {
    v3 = 0;
    while ( m_first != scene )
    {
      v3 = m_first;
      m_first = m_first->m_next;
      if ( !m_first )
      {
        if ( scene )
          return;
        break;
      }
    }
    --this->m_active_scenes.m_size;
    p_m_next = &m_first->m_next;
    v5 = *p_m_next;
    if ( v3 )
      v3->m_next = v5;
    else
      this->m_active_scenes.m_first = v5;
    if ( !*p_m_next )
    {
      v6 = v3;
      if ( !v3 )
        v6 = this->m_active_scenes.m_first;
      this->m_active_scenes.m_last = v6;
    }
  }
}
