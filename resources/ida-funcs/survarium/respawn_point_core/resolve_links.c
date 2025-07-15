void __thiscall survarium::respawn_point_core::resolve_links(
        survarium::respawn_point_core *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  _DWORD v4[6]; // [esp-18h] [ebp-28h] BYREF
  survarium::link_resolver_vtbl *v5; // [esp+Ch] [ebp-4h]

  v5 = this->m_ally_checker->__vftable;
  qmemcpy(v4, vostok::configs::binary_config_value::operator[](&cfg, "ally_zones"), sizeof(v4));
  ((void (__thiscall *)(survarium::link_resolver *, survarium::base_project *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v5->resolve_links)(
    &this->m_ally_checker->survarium::link_resolver,
    p,
    v4[0],
    v4[1],
    v4[2],
    v4[3],
    v4[4],
    v4[5]);
  v5 = this->m_enemy_checker->__vftable;
  qmemcpy(v4, vostok::configs::binary_config_value::operator[](&cfg, "enemy_zones"), sizeof(v4));
  ((void (__thiscall *)(survarium::link_resolver *, survarium::base_project *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v5->resolve_links)(
    &this->m_enemy_checker->survarium::link_resolver,
    p,
    v4[0],
    v4[1],
    v4[2],
    v4[3],
    v4[4],
    v4[5]);
}
