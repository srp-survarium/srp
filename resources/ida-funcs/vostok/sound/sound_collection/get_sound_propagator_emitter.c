const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::sound_collection::get_sound_propagator_emitter(
        vostok::sound::single_sound *this)
{
  if ( this )
    return &this->vostok::sound::sound_propagator_emitter;
  else
    return 0;
}
