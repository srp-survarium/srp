bool __thiscall vostok::vfs::same_mount_predicate::operator()(
        vostok::vfs::same_mount_predicate *this,
        vostok::vfs::mounter *mount)
{
  bool result; // al
  vostok::fs_new::native_path_string *p_fat_physical_path; // [esp+4h] [ebp-78h]
  vostok::fs_new::native_path_string *p_physical_path; // [esp+2Ch] [ebp-50h]
  vostok::vfs::query_mount_arguments *s2; // [esp+54h] [ebp-28h]

  if ( mount->m_args.type != this->args->type )
    return 0;
  s2 = this->args;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !vostok::operator==(&mount->m_args.virtual_path, &s2->virtual_path) )
    return 0;
  if ( mount->m_args.submount_node != this->args->submount_node )
    return 0;
  p_physical_path = &this->args->physical_path;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)p_physical_path);
  result = 0;
  if ( vostok::operator==(&mount->m_args.physical_path, p_physical_path) )
  {
    p_fat_physical_path = &this->args->fat_physical_path;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( vostok::operator==(&mount->m_args.fat_physical_path, p_fat_physical_path) )
      return 1;
  }
  return result;
}
