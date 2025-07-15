char __cdecl vostok::vfs::check_is_archive_file(
        const char *physical_path,
        vostok::fs_new::synchronous_device_interface *device)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  int v5; // edx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  unsigned int v8; // [esp+7Ch] [ebp-188h] BYREF
  unsigned int max_count; // [esp+80h] [ebp-184h] BYREF
  char v10; // [esp+85h] [ebp-17Fh]
  bool v11; // [esp+86h] [ebp-17Eh]
  char v12; // [esp+87h] [ebp-17Dh]
  char *v13; // [esp+88h] [ebp-17Ch] BYREF
  char *end_src; // [esp+8Ch] [ebp-178h] BYREF
  vostok::fs_new::native_path_string v15; // [esp+94h] [ebp-170h] BYREF
  char magic; // [esp+1ABh] [ebp-59h] BYREF
  vostok::fixed_string<11> big_endian_string_part; // [esp+1ACh] [ebp-58h] BYREF
  unsigned int char_count; // [esp+1C4h] [ebp-40h]
  vostok::fixed_string<11> part; // [esp+1C8h] [ebp-3Ch] BYREF
  vostok::fs_new::file_type_pointer file; // [esp+1E0h] [ebp-24h] BYREF
  vostok::fixed_string<11> little_endian_string_part; // [esp+1E8h] [ebp-1Ch] BYREF
  bool is_db_file; // [esp+203h] [ebp-1h]

  vostok::fs_new::native_path_string::native_path_string(&v15, &physical_path);
  survarium::weapon_user_dead_state::finalize(v2);
  file.device = device;
  v10 = vostok::fs_new::open_cached_file(
          device,
          &file.file,
          (vostok::fs_new::open_file_cache *)&v15,
          open_existing,
          read,
          assert_on_fail_false,
          notify_watcher_true,
          use_buffering_true);
  if ( file.file )
  {
    char_count = 10;
    end_src = (char *)(big_endian_string_0 + 10);
    max_count = 11;
    vostok::buffer_string::buffer_string(
      &big_endian_string_part,
      big_endian_string_part.m_buffer,
      &max_count,
      &big_endian_string_0,
      (const char *const *)&end_src);
    v13 = (char *)(little_endian_string + 10);
    v8 = 11;
    vostok::buffer_string::buffer_string(
      &little_endian_string_part,
      little_endian_string_part.m_buffer,
      &v8,
      &little_endian_string,
      (const char *const *)&v13);
    vostok::fixed_string<11>::fixed_string<11>(&part);
    vostok::fs_new::path_string_impl::set_length((vostok::fs_new::path_string_impl *)&part, 0xAu);
    is_db_file = 0;
    if ( vostok::fs_new::device_file_system_proxy_base::read(&device->m_device, file.file, part.m_buffer, 0xAu) == 10
      && !v5
      && (vostok::operator==(
            (vostok::fs_new::path_string_impl *)&part,
            (vostok::fs_new::path_string_impl *)&big_endian_string_part)
       || vostok::operator==(
            (vostok::fs_new::path_string_impl *)&part,
            (vostok::fs_new::path_string_impl *)&little_endian_string_part)) )
    {
      is_db_file = 1;
    }
    if ( !is_db_file
      || (vostok::fs_new::device_file_system_proxy_base::seek(&device->m_device, file.file, 0x400u, seek_file_begin),
          magic = 0,
          vostok::fs_new::device_file_system_proxy_base::read(&device->m_device, file.file, &magic, 1u),
          magic == 13) )
    {
      v11 = is_db_file;
      vostok::fs_new::file_type_pointer::close(&file);
      survarium::weapon_user_dead_state::finalize(v7);
      return v11;
    }
    else
    {
      v12 = 0;
      vostok::fs_new::file_type_pointer::close(&file);
      survarium::weapon_user_dead_state::finalize(v6);
      return v12;
    }
  }
  else
  {
    vostok::fs_new::file_type_pointer::close(&file);
    survarium::weapon_user_dead_state::finalize(v3);
    return 0;
  }
}
