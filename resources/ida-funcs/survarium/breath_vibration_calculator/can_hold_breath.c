BOOL __thiscall survarium::breath_vibration_calculator::can_hold_breath(survarium::breath_vibration_calculator *this)
{
  survarium::base_player *m_user; // eax
  unsigned int actions_mask; // eax
  BOOL result; // eax

  m_user = this->m_user;
  result = 0;
  if ( !*((_BYTE *)&m_user->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
        + (_DWORD)&loc_11106
        + 2) )
  {
    actions_mask = m_user->m_input.actions_mask;
    if ( (actions_mask & 0x400000) != 0
      && (actions_mask & 0x100) != 0
      && this->m_penalty_factor == 0.0
      && this->m_weapon->m_aimed )
    {
      return 1;
    }
  }
  return result;
}
