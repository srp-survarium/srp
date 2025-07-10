BOOL __thiscall vostok::fs_new::windows_hdd_file_system::open(
        vostok::fs_new::windows_hdd_file_system *this,
        char **out_handle,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *absolute_path,
        const vostok::fs_new::open_file_params *params)
{
  const char *v4; // eax
  survarium::game_camera *v5; // ecx
  DWORD desired_access; // [esp+8h] [ebp-14h]
  char *handle; // [esp+Ch] [ebp-10h]
  DWORD creation_disposition; // [esp+10h] [ebp-Ch]
  DWORD flags; // [esp+14h] [ebp-8h]

  flags = 128;
  if ( params->use_buffering == use_buffering_false )
    flags = 536871040;
  desired_access = 0;
  if ( params->access == read )
  {
    desired_access = 0x80000000;
  }
  else if ( params->access )
  {
    if ( params->access == read_write )
      desired_access = -1073741824;
  }
  else
  {
    desired_access = 0x40000000;
  }
  creation_disposition = 0;
  if ( params->mode )
  {
    if ( params->mode == open_existing )
    {
      creation_disposition = 3;
    }
    else if ( params->mode == append_or_create )
    {
      creation_disposition = 4;
    }
  }
  else
  {
    creation_disposition = 2;
  }
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(absolute_path);
  handle = (char *)CreateFileA(v4, desired_access, 3u, 0, creation_disposition, flags, 0);
  if ( handle == (char *)-1 && params->assert_on_fail )
  {
    vostok::fs_new::log_last_error(
      (const char *)&stru_955E40.m_fat_it.m_type,
      (survarium::game_camera *)&stru_955E40.m_prev_in_memory_type);
    survarium::weapon_user_dead_state::finalize(v5);
  }
  if ( handle != (char *)-1 && params->mode == append_or_create )
    SetFilePointer(handle, 0, 0, 2u);
  *out_handle = handle;
  return handle + 1 != 0;
}
