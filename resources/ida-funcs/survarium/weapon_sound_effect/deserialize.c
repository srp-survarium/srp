void __fastcall survarium::weapon_sound_effect::deserialize(survarium::weapon_sound_effect *this, int a2)
{
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *m_end; // eax
  char m_object; // [esp+1h] [ebp-1h]

  if ( this )
  {
    m_end = this->m_first_view_sounds.sounds_emitters.m_end;
    m_object = (char)m_end->m_object;
    this->m_first_view_sounds.sounds_emitters.m_end = (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)((char *)&m_end->m_object + 1);
    *(_BYTE *)(a2 + 57) = m_object;
  }
  else
  {
    *(_BYTE *)(a2 + 57) = -1;
  }
}
