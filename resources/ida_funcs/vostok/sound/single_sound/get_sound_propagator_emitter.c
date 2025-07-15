const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::single_sound::get_sound_propagator_emitter(
        vostok::sound::single_sound *this)
{
  if ( this )
    return &this->vostok::sound::sound_propagator_emitter;
  else
    return 0;
}


const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::single_sound::get_sound_propagator_emitter(
        vostok::sound::single_sound *this,
        unsigned __int64 address)
{
  vostok::sound::single_sound *v4; // [esp+4h] [ebp-Ch]

  if ( this->m_old_address == address )
    v4 = this;
  else
    v4 = 0;
  if ( v4 )
    return &v4->vostok::sound::sound_propagator_emitter;
  else
    return 0;
}


const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::single_sound::get_sound_propagator_emitter(
        char *this,
        unsigned __int64 a2)
{
  return vostok::sound::single_sound::get_sound_propagator_emitter((vostok::sound::single_sound *)(this - 272), a2);
}
