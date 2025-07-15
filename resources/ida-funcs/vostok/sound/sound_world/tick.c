void __usercall vostok::sound::sound_world::tick(
        vostok::sound::sound_world *this@<ecx>,
        float a2@<xmm0>,
        float a3@<xmm10>)
{
  unsigned int elapsed_msec; // ebp
  unsigned int v5; // ebx
  vostok::sound::sound_world *v6; // ecx
  vostok::sound::sound_scene *v7; // ecx
  vostok::sound::sound_scene *i; // esi
  vostok::sound::sound_scene *m_first; // esi
  IXAudio2SubmixVoice *m_submix_voice; // eax
  float v11; // xmm0_4

  vostok::sound::op_set = 0;
  vostok::sound::voice_bridge::operation_set = 0;
  elapsed_msec = vostok::timing::timer::get_elapsed_msec((vostok::timing::timer *)this, (int)&this->m_timer);
  v5 = elapsed_msec - this->m_last_current_time_in_ms;
  vostok::sound::sound_world::process_orders(v6, (int)this);
  for ( i = this->m_active_scenes.m_first; i; i = i->m_next )
    vostok::sound::sound_scene::tick(v7, a2, a3, i, v5);
  this->m_last_current_time_in_ms = elapsed_msec;
  if ( this->m_base_volume != (unsigned __int8)(int)s_general_vol )
  {
    m_first = this->m_active_scenes.m_first;
    this->m_base_volume = (int)s_general_vol;
    while ( m_first )
    {
      m_submix_voice = m_first->m_submix_voice;
      v11 = (float)this->m_base_volume * 0.0099999998;
      m_first->m_base_volume_koeff = v11;
      if ( m_submix_voice )
        ((void (__stdcall *)(IXAudio2SubmixVoice *, _DWORD, _DWORD))m_submix_voice->SetVolume)(
          m_submix_voice,
          m_first->m_volume * v11,
          0);
      m_first = m_first->m_next;
    }
  }
  vostok::sound::voice_bridge::operation_set = -1;
  if ( vostok::sound::op_set )
    this->m_xaudio->CommitChanges(this->m_xaudio, vostok::sound::op_set);
}
