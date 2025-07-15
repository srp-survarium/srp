void __thiscall vostok::sound::sound_instance_proxy_internal::play(
        vostok::sound::sound_instance_proxy_internal *this,
        vostok::sound::playback_mode mode,
        const vostok::sound::sound_producer *producer,
        const vostok::sound::sound_receiver *ignorable_receiver)
{
  this->m_playback_mode = mode;
  this->m_producer = producer;
  this->m_ignorable_receiver = ignorable_receiver;
  if ( producer )
    producer->m_world_user = this->m_user;
  vostok::sound::sound_scene::emit_sound_propagators(
    ++this->m_playback_id,
    this->m_scene,
    (boost::detail::function::vtable_base *)this);
}
