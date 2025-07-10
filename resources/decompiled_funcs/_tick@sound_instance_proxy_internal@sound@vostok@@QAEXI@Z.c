void __thiscall vostok::sound::sound_instance_proxy_internal::tick(
        vostok::sound::sound_instance_proxy_internal *this,
        unsigned int delta_time)
{
  vostok::sound::new_sound_propagator *next; // [esp+4h] [ebp-8h]
  vostok::sound::new_sound_propagator *propagator; // [esp+8h] [ebp-4h]

  for ( propagator = this->m_propagators.m_first; propagator; propagator = next )
  {
    next = propagator->m_next_for_proxies;
    vostok::sound::new_sound_propagator::tick(propagator, delta_time);
    if ( propagator->m_propagation_state == propagating_finished )
      vostok::sound::sound_scene::delete_sound_propagator(this->m_scene, this, propagator);
  }
}
