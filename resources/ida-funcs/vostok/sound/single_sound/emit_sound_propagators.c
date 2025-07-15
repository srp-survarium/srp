void __thiscall vostok::sound::single_sound::emit_sound_propagators(
        vostok::sound::single_sound *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        vostok::sound::playback_mode mode,
        unsigned int playback_id,
        unsigned int before_playing_offset,
        unsigned int after_playing_offset,
        const vostok::sound::sound_producer *const producer,
        const vostok::sound::sound_receiver *const ignorable_receiver)
{
  const vostok::sound::sound_propagator_emitter *owner; // [esp+0h] [ebp-18h]
  vostok::sound::new_sound_propagator *new_propagator; // [esp+14h] [ebp-4h]

  if ( this == (vostok::sound::single_sound *)272 )
    owner = 0;
  else
    owner = (const vostok::sound::sound_propagator_emitter *)this;
  new_propagator = vostok::sound::sound_scene::create_sound_propagator(
                     proxy->m_scene,
                     owner,
                     proxy,
                     mode,
                     playback_id,
                     0,
                     before_playing_offset,
                     after_playing_offset,
                     producer,
                     ignorable_receiver);
  if ( new_propagator )
    vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &proxy->m_propagators,
      new_propagator,
      0);
}
