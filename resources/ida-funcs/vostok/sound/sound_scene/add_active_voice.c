void __usercall vostok::sound::sound_scene::add_active_voice(
        vostok::sound::sound_scene *this@<eax>,
        vostok::sound::sound_voice *voice@<edi>,
        vostok::threading::mutex *a3@<ecx>)
{
  vostok::threading::mutex *v3; // ebx
  vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_active_voices; // esi

  v3 = 0;
  p_m_active_voices = &this->m_active_voices;
  voice->m_next_for_active = 0;
  if ( this != (vostok::sound::sound_scene *)-680 )
    v3 = &this->m_active_voices.vostok::threading::mutex;
  vostok::threading::mutex::lock(a3, (_RTL_CRITICAL_SECTION *)v3);
  ++p_m_active_voices->m_size;
  if ( p_m_active_voices->m_first )
    p_m_active_voices->m_last->m_next_for_active = voice;
  else
    p_m_active_voices->m_first = voice;
  p_m_active_voices->m_last = voice;
  LeaveCriticalSection((LPCRITICAL_SECTION)v3);
}
