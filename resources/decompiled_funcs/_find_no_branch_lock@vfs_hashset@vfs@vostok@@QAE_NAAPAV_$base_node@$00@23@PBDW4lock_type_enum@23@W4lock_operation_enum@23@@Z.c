char __thiscall vostok::vfs::vfs_hashset::find_no_branch_lock(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_node,
        const char *path,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  const char *v5; // eax
  unsigned int v7; // [esp-8h] [ebp-124h]
  vostok::fs_new::path_string_impl v9; // [esp+4h] [ebp-118h] BYREF
  unsigned int hash; // [esp+118h] [ebp-4h]

  vostok::fs_new::path_string_impl::path_string_impl(&v9, 47, &path);
  v7 = vostok::fs_new::path_string_impl::length(&v9);
  v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9);
  hash = vostok::fs_new::path_crc32(v5, v7, 0);
  return vostok::vfs::vfs_hashset::find_no_branch_lock(this, out_locked_node, path, hash, lock_type, lock_operation);
}
