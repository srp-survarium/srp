void __thiscall vostok::sound::sound_world::clear_resources(vostok::sound::sound_world *this)
{
  vostok::sound::sound_scene *scene; // [esp+8h] [ebp-4h]

  for ( scene = this->m_active_scenes.m_first; scene; scene = scene->m_next )
    vostok::sound::sound_scene::stop(scene);
  this->tick(this);
  while ( i < 5 && this->m_voices_to_delete.m_first )
  {
    this->tick(this);
    vostok::threading::yield(0xAu);
    ++i;
  }
}
