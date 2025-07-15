char __thiscall vostok::fs_new::windows_hdd_file_system::find_next(
        vostok::fs_new::windows_hdd_file_system *this,
        unsigned __int64 *in_out_search_handle,
        vostok::fs_new::physical_path_info_data *out_data)
{
  _finddata32i64_t file_desc; // [esp+8h] [ebp-120h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( _findnext32i64(*(void **)in_out_search_handle, &file_desc) == -1 )
  {
    *(_DWORD *)in_out_search_handle = -1;
    *((_DWORD *)in_out_search_handle + 1) = -1;
    return 0;
  }
  else
  {
    vostok::fs_new::init_from_os_struct(out_data, &file_desc);
    return 1;
  }
}
