vostok::vfs::result_enum __thiscall vostok::vfs::virtual_file_system::try_find_sync(
        vostok::vfs::virtual_file_system *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        vostok::vfs::find_enum find_flags,
        vostok::memory::base_allocator *allocator)
{
  const char *v5; // eax

  v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(path);
  return vostok::vfs::try_find_sync(v5, out_iterator, find_flags, this, allocator);
}
