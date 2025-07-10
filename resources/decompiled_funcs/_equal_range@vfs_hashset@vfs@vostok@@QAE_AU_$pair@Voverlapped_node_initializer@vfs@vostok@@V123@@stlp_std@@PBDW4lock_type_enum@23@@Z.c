stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *__thiscall vostok::vfs::vfs_hashset::equal_range(
        vostok::vfs::vfs_hashset *this,
        stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *result,
        const char *path,
        vostok::vfs::lock_type_enum lock_type)
{
  const char *v4; // eax
  unsigned int v6; // [esp-8h] [ebp-124h]
  vostok::fs_new::path_string_impl v8; // [esp+4h] [ebp-118h] BYREF
  unsigned int hash; // [esp+118h] [ebp-4h]

  vostok::fs_new::path_string_impl::path_string_impl(&v8, 47, &path);
  v6 = vostok::fs_new::path_string_impl::length(&v8);
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  hash = vostok::fs_new::path_crc32(v4, v6, 0);
  vostok::vfs::vfs_hashset::equal_range(this, result, path, hash, lock_type);
  return result;
}
