void __thiscall survarium::ladder::resolve_links(
        survarium::ladder *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  int m_current_satisfaction_update_tick_high; // eax
  void (__thiscall ***v5)(_DWORD, survarium::base_project *, const void *, _DWORD, const char *, _DWORD, unsigned int, _DWORD); // eax
  void (__thiscall **v6)(_DWORD, survarium::base_project *, const void *, _DWORD, const char *, _DWORD, unsigned int, _DWORD); // edx
  vostok::configs::binary_config_value v7; // [esp-18h] [ebp-24h] BYREF

  qmemcpy((void *)&v7, &cfg, sizeof(v7));
  survarium::usable_object::resolve_links((survarium::usable_object *)this, p, v7);
  m_current_satisfaction_update_tick_high = HIDWORD(this->m_current_satisfaction_update_tick);
  if ( m_current_satisfaction_update_tick_high )
  {
    v5 = (void (__thiscall ***)(_DWORD, survarium::base_project *, const void *, _DWORD, const char *, _DWORD, unsigned int, _DWORD))(m_current_satisfaction_update_tick_high + 4);
    v6 = *v5;
    qmemcpy((void *)&v7, &cfg, sizeof(v7));
    (*v6)(
      v5,
      p,
      v7.data.pointer,
      HIDWORD(v7.data.max_storage),
      v7.id.pointer,
      HIDWORD(v7.id.max_storage),
      v7.id_crc,
      *(_DWORD *)&v7.type);
  }
}
