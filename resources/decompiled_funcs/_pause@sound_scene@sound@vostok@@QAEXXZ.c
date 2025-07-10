void __thiscall vostok::sound::sound_scene::pause(vostok::sound::sound_scene *this)
{
  vostok::sound::sound_scene::pause_propagate_all_sounds(this);
  this->m_is_paused = 1;
}
