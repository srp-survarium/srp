void __thiscall vostok::sound::sound_instance_proxy_internal::play(
        vostok::sound::sound_instance_proxy_internal *this,
        vostok::sound::playback_mode mode,
        const vostok::sound::sound_producer *const producer,
        const vostok::sound::sound_receiver *const ignorable_receiver)
{
  if ( producer )
    vostok::sound::sound_producer::on_play(producer, this->m_user);
  vostok::sound::sound_scene::emit_sound_propagators(
    this->m_scene,
    this,
    mode,
    ++this->m_playback_id,
    producer,
    ignorable_receiver);
  this->m_is_playing = 1;
  this->m_is_propagating_paused = 0;
  this->m_is_producing_paused = 0;
}
