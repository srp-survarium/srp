void __thiscall vostok::sound::sound_scene::clear_resources(vostok::sound::sound_scene *this)
{
  vostok::sound::sound_world::free_submix_voice(this->m_world, this->m_fade_in_environment);
  vostok::sound::sound_world::free_submix_voice(this->m_world, this->m_fade_out_environment);
  vostok::sound::sound_world::free_submix_voice(this->m_world, this->m_submix_voice);
}
