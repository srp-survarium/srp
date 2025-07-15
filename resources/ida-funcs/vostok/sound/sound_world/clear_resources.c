void __thiscall vostok::sound::sound_world::clear_resources(vostok::sound::sound_world *this)
{
  vostok::sound::sound_scene *i; // edi

  vostok::sound::voice_bridge::operation_set = 0;
  for ( i = this->m_active_scenes.m_first; i; i = i->m_next )
    vostok::sound::sound_scene::stop((vostok::sound::sound_scene *)this, i);
  this->tick(this);
}
