void __thiscall vostok::sound::sound_world::free_voice(
        vostok::sound::sound_world *this,
        vostok::sound::voice_bridge *voice)
{
  vostok::sound::voice_factory::delete_voice(this->m_voice_factory, voice);
}
