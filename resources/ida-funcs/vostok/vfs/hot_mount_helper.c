void __cdecl vostok::vfs::hot_mount_helper(
        bool *out_got_lock,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::virtual_file_system *file_system,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *virtual_path,
        vostok::memory::base_allocator *allocator,
        vostok::vfs::mount_result result)
{
  char *src; // [esp+4h] [ebp-118h] BYREF
  vostok::fs_new::path_string_impl v7; // [esp+8h] [ebp-114h] BYREF

  if ( result.result == result_requery || (*out_got_lock = 1, !out_iterator) || out_iterator->m_node )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&result.mount);
  }
  else
  {
    src = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(virtual_path);
    vostok::fs_new::path_string_impl::path_string_impl(&v7, 47, (const char **)&src);
    vostok::vfs::virtual_file_system::try_find_sync(
      file_system,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7,
      out_iterator,
      (vostok::vfs::find_enum)0,
      allocator);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&result.mount);
  }
}
