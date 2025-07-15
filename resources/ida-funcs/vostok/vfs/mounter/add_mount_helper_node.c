void __thiscall vostok::vfs::mounter::add_mount_helper_node(
        vostok::vfs::mounter *this,
        vostok::vfs::mount_helper_node<1> *in_out_helper_node,
        vostok::fs_new::virtual_path_string *path,
        unsigned int path_hash,
        vostok::vfs::base_node<1> **in_out_current_helper,
        vostok::vfs::base_node<1> **in_out_branch_lock)
{
  unsigned int v6; // eax
  vostok::vfs::base_node<1> *v7; // eax
  unsigned int m_mount_id; // [esp-4h] [ebp-10h]
  const char *name; // [esp+8h] [ebp-4h]

  name = (const char *)vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
  m_mount_id = this->m_mount_id;
  v6 = vostok::strings::length(name);
  vostok::vfs::mount_helper_node<1>::create_inplace(in_out_helper_node, this->m_args.allocator, name, v6, m_mount_id);
  v7 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_helper_node,1>(in_out_helper_node);
  vostok::vfs::mounter::add_mount_helper_node_impl(this, v7, path, path_hash, in_out_current_helper, in_out_branch_lock);
}
