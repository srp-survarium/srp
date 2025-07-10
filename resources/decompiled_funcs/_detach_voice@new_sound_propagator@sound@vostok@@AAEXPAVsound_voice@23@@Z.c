void __thiscall vostok::sound::new_sound_propagator::detach_voice(
        vostok::sound::new_sound_propagator *this,
        vostok::sound::sound_voice *voice)
{
  vostok::sound::sound_voice::stop(voice);
  vostok::sound::sound_world::delete_sound_voice(this->m_proxy->m_user->m_owner_world, this->m_proxy->m_scene, voice);
}
