const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::composite_sound::get_sound_propagator_emitter(
        vostok::sound::composite_sound *this,
        unsigned __int64 address)
{
  __int64 v3; // [esp+0h] [ebp-38h]
  const vostok::sound::sound_propagator_emitter *emt; // [esp+2Ch] [ebp-Ch]
  const vostok::sound::sound_propagator_emitter *generator; // [esp+30h] [ebp-8h]
  unsigned int i; // [esp+34h] [ebp-4h]

  if ( address == this->m_old_address )
  {
    if ( this )
      return &this->vostok::sound::sound_propagator_emitter;
    else
      return 0;
  }
  else
  {
    for ( i = 0; i < this->m_collection.m_end - this->m_collection.m_begin; ++i )
    {
      generator = (const vostok::sound::sound_propagator_emitter *)((int (__thiscall *)(vostok::sound::sound_emitter *, _DWORD, _DWORD, vostok::sound::sound_emitter *))this->m_collection.m_begin[i].first.m_object->get_sound_propagator_emitter)(
                                                                     this->m_collection.m_begin[i].first.m_object,
                                                                     v3,
                                                                     HIDWORD(v3),
                                                                     this->m_collection.m_begin[i].first.m_object);
      if ( generator )
      {
        emt = (const vostok::sound::sound_propagator_emitter *)((int (__thiscall *)(const vostok::sound::sound_propagator_emitter *, _DWORD, _DWORD))generator->get_sound_propagator_emitter)(
                                                                 generator,
                                                                 address,
                                                                 HIDWORD(address));
        v3 = (int)emt;
        if ( emt )
          return emt;
      }
    }
    return 0;
  }
}
