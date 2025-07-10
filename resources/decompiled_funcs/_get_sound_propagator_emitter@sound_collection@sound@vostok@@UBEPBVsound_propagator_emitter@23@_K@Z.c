const vostok::sound::sound_propagator_emitter *__thiscall vostok::sound::sound_collection::get_sound_propagator_emitter(
        vostok::sound::sound_collection *this,
        unsigned __int64 address)
{
  const vostok::sound::sound_propagator_emitter *emitter; // [esp+18h] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *end; // [esp+1Ch] [ebp-8h]
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *begin; // [esp+20h] [ebp-4h]

  begin = this->m_sounds.m_begin;
  end = this->m_sounds.m_end;
  while ( begin != end )
  {
    emitter = (const vostok::sound::sound_propagator_emitter *)((int (__thiscall *)(vostok::sound::sound_emitter *, _DWORD, _DWORD))begin->m_object->get_sound_propagator_emitter)(
                                                                 begin->m_object,
                                                                 address,
                                                                 HIDWORD(address));
    if ( emitter )
      return emitter;
    ++begin;
  }
  return 0;
}
