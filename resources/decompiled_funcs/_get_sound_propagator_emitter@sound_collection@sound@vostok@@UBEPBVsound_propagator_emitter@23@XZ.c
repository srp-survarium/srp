const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::sound_collection::get_sound_propagator_emitter(
        vostok::sound::sound_collection *this)
{
  const vostok::sound::sound_emitter *emitter; // [esp+8h] [ebp-4h]

  emitter = vostok::sound::sound_collection::get_sound(this);
  if ( emitter )
    return emitter->get_sound_propagator_emitter(emitter);
  else
    return 0;
}
