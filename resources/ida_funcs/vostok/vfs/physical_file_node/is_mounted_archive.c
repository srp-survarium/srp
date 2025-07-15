bool __thiscall vostok::vfs::physical_file_node<1>::is_mounted_archive(vostok::vfs::physical_file_node<1> *this)
{
  _DWORD v3[4]; // [esp+Ch] [ebp-14h] BYREF
  char v4; // [esp+1Fh] [ebp-1h]

  v4 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3[2] = v3;
  v3[0] = 4;
  v3[1] = 4;
  return (this->m_file_flags.m_flags & 4) == 4;
}
