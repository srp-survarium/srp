void __thiscall vostok::sound::sound_scene::resume(vostok::sound::sound_scene *this)
{
  vostok::sound::sound_scene::resume_propagate_all_sounds(this);
  this->m_is_paused = 0;
}
