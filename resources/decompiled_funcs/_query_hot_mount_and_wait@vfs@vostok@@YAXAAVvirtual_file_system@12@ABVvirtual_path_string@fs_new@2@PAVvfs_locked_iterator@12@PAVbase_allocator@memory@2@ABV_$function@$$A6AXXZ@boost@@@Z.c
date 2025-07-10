void __cdecl vostok::vfs::query_hot_mount_and_wait(
        vostok::vfs::virtual_file_system *file_system,
        const vostok::fs_new::virtual_path_string *in_virtual_path,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::memory::base_allocator *allocator,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *dispatch_callback)
{
  vostok::fs_new::virtual_path_string virtual_path; // [esp+2Ch] [ebp-238h] BYREF
  unsigned int index; // [esp+148h] [ebp-11Ch]
  vostok::fs_new::native_path_string physical_path; // [esp+14Ch] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&physical_path);
  if ( out_iterator )
    vostok::vfs::vfs_locked_iterator::clear(out_iterator);
  vostok::fs_new::virtual_path_string::virtual_path_string(&virtual_path, in_virtual_path);
  for ( index = 0;
        vostok::vfs::virtual_file_system::convert_virtual_to_physical_path(
          file_system,
          &physical_path,
          &virtual_path,
          index,
          0);
        ++index )
  {
    vostok::vfs::query_hot_mount_and_wait(
      file_system,
      &physical_path,
      &virtual_path,
      out_iterator,
      allocator,
      dispatch_callback);
  }
}
