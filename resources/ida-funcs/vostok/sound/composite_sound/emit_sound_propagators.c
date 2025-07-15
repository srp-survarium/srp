void __thiscall vostok::sound::composite_sound::emit_sound_propagators(
        vostok::sound::composite_sound *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        vostok::sound::playback_mode mode,
        unsigned int playback_id,
        unsigned int before_playing_offset,
        unsigned int after_playing_offset,
        const vostok::sound::sound_producer *const producer,
        const vostok::sound::sound_receiver *const ignorable_receiver)
{
  int v9; // [esp+10h] [ebp-40h]
  const vostok::sound::sound_propagator_emitter *generator; // [esp+48h] [ebp-8h]
  unsigned int i; // [esp+4Ch] [ebp-4h]

  for ( i = 0;
        i < (signed int)(this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                       - this->type)
          / 12;
        ++i )
  {
    generator = (const vostok::sound::sound_propagator_emitter *)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this->type + 12 * i) + 32))(
                                                                   *(_DWORD *)(this->type + 12 * i),
                                                                   *(_DWORD *)(this->type + 12 * i));
    if ( generator )
    {
      if ( *(_DWORD *)(this->type + 12 * i + 4) == *(_DWORD *)(this->type + 12 * i + 8) )
      {
        generator->emit_sound_propagators(
          generator,
          proxy,
          mode,
          playback_id,
          *(_DWORD *)(this->type + 12 * i + 4) + before_playing_offset,
          after_playing_offset,
          producer,
          ignorable_receiver);
      }
      else
      {
        v9 = *(_DWORD *)(this->type + 12 * i + 8) - *(_DWORD *)(this->type + 12 * i + 4);
        *((_DWORD *)&this->vostok::resources::resource_flags + 3) = 134775813
                                                                  * *((_DWORD *)&this->vostok::resources::resource_flags
                                                                    + 3)
                                                                  + 1;
        generator->emit_sound_propagators(
          generator,
          proxy,
          mode,
          playback_id,
          *(_DWORD *)(this->type + 12 * i + 4)
        + (((unsigned int)v9 * (unsigned __int64)*((unsigned int *)&this->vostok::resources::resource_flags + 3)) >> 32)
        + before_playing_offset,
          after_playing_offset,
          producer,
          ignorable_receiver);
      }
    }
  }
}
