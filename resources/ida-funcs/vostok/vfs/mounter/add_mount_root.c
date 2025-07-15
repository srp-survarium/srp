void __thiscall vostok::vfs::mounter::add_mount_root(
        vostok::vfs::mounter *this,
        vostok::vfs::mount_root_node_base<1> *new_mount_root,
        vostok::fs_new::virtual_path_string *path,
        unsigned int *out_hash,
        vostok::vfs::base_node<1> **in_out_branch,
        vostok::vfs::base_node<1> **in_out_lock)
{
  const char *v6; // eax
  vostok::vfs::base_node<1> *v7; // eax
  unsigned int v8; // [esp-Ch] [ebp-10h]
  unsigned int v9; // [esp-8h] [ebp-Ch]

  v9 = vostok::fs_new::path_string_impl::length(path);
  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
  *out_hash = vostok::fs_new::path_crc32(v6, v9, 0);
  v8 = *out_hash;
  v7 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(new_mount_root);
  vostok::vfs::mounter::add_mount_helper_node_impl(this, v7, path, v8, in_out_branch, in_out_lock);
}
