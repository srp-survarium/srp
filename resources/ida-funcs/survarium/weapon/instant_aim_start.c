void __thiscall survarium::weapon::instant_aim_start(survarium::weapon *this)
{
  survarium::base_player *m_user; // esi
  survarium::player *v3; // ecx

  survarium::weapon_core::instant_aim_start(this);
  m_user = this->m_user;
  if ( survarium::player::is_current(v3, (int)m_user) )
    (*(survarium::base_player_vtbl **)((char *)&m_user->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                     + (_DWORD)&loc_11403
                                     + 5))[13].clear = (void (__thiscall *)(survarium::base_player *))4;
}
