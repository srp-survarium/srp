void __userpurge vostok::sound::sound_scene::remove_active_voice(
        vostok::sound::sound_scene *this@<ecx>,
        int a2@<esi>,
        vostok::sound::sound_voice *voice)
{
  vostok::sound::sound_voice *v3; // eax
  vostok::sound::sound_voice *v4; // ecx
  vostok::sound::sound_voice *m_next_for_active; // edx
  vostok::sound::sound_voice *v6; // eax

  if ( *(_DWORD *)(a2 + 716) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)(a2 + 688));
    v3 = *(vostok::sound::sound_voice **)(a2 + 716);
    v4 = 0;
    while ( v3 )
    {
      if ( v3 == voice )
        goto LABEL_7;
      v4 = v3;
      v3 = v3->m_next_for_active;
    }
    if ( voice )
      goto LABEL_14;
LABEL_7:
    --*(_DWORD *)(a2 + 680);
    m_next_for_active = v3->m_next_for_active;
    if ( v4 )
      v4->m_next_for_active = m_next_for_active;
    else
      *(_DWORD *)(a2 + 716) = m_next_for_active;
    if ( !v3->m_next_for_active )
    {
      v6 = v4;
      if ( !v4 )
        v6 = *(vostok::sound::sound_voice **)(a2 + 716);
      *(_DWORD *)(a2 + 720) = v6;
    }
LABEL_14:
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 688));
  }
}
