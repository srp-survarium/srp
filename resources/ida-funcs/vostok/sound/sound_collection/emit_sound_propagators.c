void __thiscall vostok::sound::sound_collection::emit_sound_propagators(
        vostok::sound::sound_collection *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        unsigned int playback_id,
        unsigned int start_delay_ms)
{
  int m_reconstruction_info_actuality_tick; // eax
  unsigned int v6; // edi
  int v7; // eax
  unsigned __int64 v8; // rax
  int v9; // ecx
  void (__thiscall ***v10)(_DWORD, vostok::sound::sound_instance_proxy_internal *, unsigned int, unsigned int); // ecx
  unsigned int v11; // eax
  int v12; // edx
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax

  m_reconstruction_info_actuality_tick = this->m_reconstruction_info_actuality_tick;
  v6 = (signed int)(this->vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::sound::sound_emitter::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                  - this->type) >> 4;
  if ( m_reconstruction_info_actuality_tick )
  {
    if ( m_reconstruction_info_actuality_tick == 1 )
      *(&this->m_reconstruction_size + 1) = (*(&this->m_reconstruction_size + 1) + 1) % v6;
  }
  else
  {
    do
    {
      v7 = 134775813 * HIDWORD(this->m_reconstruction_info_actuality_tick) + 1;
      HIDWORD(this->m_reconstruction_info_actuality_tick) = v7;
      v8 = ((unsigned int)v7 * (unsigned __int64)v6) >> 32;
    }
    while ( (_DWORD)v8 == *(&this->m_reconstruction_size + 1) && !LOBYTE(this->m_uid) && v6 != 1 );
    *(&this->m_reconstruction_size + 1) = v8;
  }
  v9 = *(_DWORD *)(16 * *(&this->m_reconstruction_size + 1) + this->type);
  v10 = (void (__thiscall ***)(_DWORD, vostok::sound::sound_instance_proxy_internal *, unsigned int, unsigned int))(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 28))(v9);
  v11 = this->type + 16 * *(&this->m_reconstruction_size + 1);
  v12 = *(_DWORD *)(v11 + 4);
  v13 = *(_DWORD *)(v11 + 8);
  if ( v12 != v13 )
  {
    v14 = v13 - v12;
    v15 = 134775813 * HIDWORD(this->m_reconstruction_info_actuality_tick) + 1;
    HIDWORD(this->m_reconstruction_info_actuality_tick) = v15;
    v12 = *(_DWORD *)(16 * *(&this->m_reconstruction_size + 1) + this->type + 4)
        + ((v14 * (unsigned __int64)(unsigned int)v15) >> 32);
  }
  (**v10)(v10, proxy, playback_id, start_delay_ms + v12);
}
