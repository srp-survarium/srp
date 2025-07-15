void __cdecl vostok::vfs::hot_mount_helper(
        bool *out_got_lock,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::virtual_file_system *file_system,
        const vostok::fs_new::virtual_path_string *virtual_path,
        vostok::memory::base_allocator *allocator,
        vostok::vfs::mount_result result)
{
  vostok::fixed_string<260> *v6; // ecx
  vostok::buffer_string path_to_find[22]; // [esp+8h] [ebp-114h] BYREF
  char v8; // [esp+118h] [ebp-4h]

  if ( result.result != result_cannot_lock )
  {
    *out_got_lock = 1;
    if ( out_iterator )
    {
      if ( !out_iterator->m_node )
      {
        vostok::fixed_string<260>::fixed_string<260>(v6, path_to_find, virtual_path->m_string.m_begin);
        v8 = 47;
        vostok::vfs::try_find_sync(path_to_find[0].m_begin, out_iterator, 0, file_system, allocator);
      }
    }
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&result.mount);
}
