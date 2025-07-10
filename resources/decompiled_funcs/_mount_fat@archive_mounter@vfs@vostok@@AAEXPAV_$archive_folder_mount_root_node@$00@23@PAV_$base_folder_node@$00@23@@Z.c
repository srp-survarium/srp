void __thiscall vostok::vfs::archive_mounter::mount_fat(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::archive_folder_mount_root_node<1> *mount_root,
        vostok::vfs::base_folder_node<1> *parent)
{
  vostok::vfs::base_node<1> *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *physical_path; // eax
  const char *v6; // eax
  const char *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  signed int v9; // [esp-8h] [ebp-1C4h]
  char *virtual_path_holder; // [esp+4h] [ebp-1B8h]
  vostok::fs_new::device_file_system_interface *m_device_file_system; // [esp+54h] [ebp-168h]
  char *v13; // [esp+64h] [ebp-158h]
  char *v14; // [esp+68h] [ebp-154h]
  char *v15; // [esp+6Ch] [ebp-150h]
  char *source; // [esp+70h] [ebp-14Ch]
  vostok::fs_new::native_path_string result; // [esp+98h] [ebp-124h] BYREF
  const char *virtual_path_last_part; // [esp+1ACh] [ebp-10h]
  const char *last_slash_pos; // [esp+1B0h] [ebp-Ch]
  unsigned int hash; // [esp+1B4h] [ebp-8h]
  vostok::vfs::base_node<1> *mount_root_base; // [esp+1B8h] [ebp-4h]

  this->m_mount_root_base = mount_root;
  this->m_mount_root_base->mount_id = this->m_mount_id;
  this->m_mount_root_base->mount_operation_id = vostok::vfs::next_mount_operation_id();
  mount_root->nodes_buffer.pointer = this->m_nodes_buffer;
  mount_root->attach_node.pointer = this->m_args.submount_node;
  v3 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::archive_folder_mount_root_node,1>(mount_root);
  vostok::vfs::archive_mounter::recursive_fixup_node(this, v3, (char *)mount_root);
  mount_root->attach_node.pointer = this->m_args.submount_node;
  mount_root->allocator.pointer = this->m_args.allocator;
  mount_root->file_system.pointer = this->m_file_system;
  source = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
  vostok::strings::copy(mount_root->virtual_path_holder, 0x104u, source);
  v15 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.archive_physical_path);
  vostok::strings::copy(mount_root->archive_path_holder, 0x104u, v15);
  v14 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v4,
                  (int)&this->m_args.descriptor);
  vostok::strings::copy(mount_root->descriptor, 0x20u, v14);
  physical_path = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::vfs::query_mount_arguments::get_physical_path(&this->m_args, &result);
  v13 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(physical_path);
  vostok::strings::copy(mount_root->fat_path_holder, 0x104u, v13);
  if ( this->m_args.synchronous_device )
    m_device_file_system = this->m_args.synchronous_device->m_device.m_device_file_system;
  else
    m_device_file_system = 0;
  mount_root->device.pointer = m_device_file_system;
  mount_root->async_device.pointer = this->m_args.asynchronous_device;
  mount_root->watcher_enabled = this->m_args.watcher_enabled;
  this->m_mount_root_base->virtual_path.pointer = mount_root->virtual_path_holder;
  this->m_mount_root_base->physical_path.pointer = mount_root->fat_path_holder;
  if ( this->m_args.submount_type == submount_type_automatic_archive )
  {
    vostok::vfs::base_node<1>::set_name(mount_root->node.pointer, this->m_args.submount_node->m_name);
  }
  else if ( this->m_args.submount_type == submount_type_unset )
  {
    strrchr((unsigned __int8 *)mount_root->virtual_path_holder, 0x2Fu);
    last_slash_pos = v6;
    if ( v6 )
      virtual_path_holder = (char *)(last_slash_pos + 1);
    else
      virtual_path_holder = mount_root->virtual_path_holder;
    virtual_path_last_part = virtual_path_holder;
    vostok::vfs::base_node<1>::set_name(mount_root->node.pointer, virtual_path_holder);
  }
  v9 = vostok::fs_new::path_string_impl::length(&this->m_args.virtual_path);
  v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args);
  hash = vostok::fs_new::path_crc32(v7, v9, 0);
  mount_root_base = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::archive_folder_mount_root_node,1>(mount_root);
  vostok::vfs::archive_mounter::recursive_merge(this, &this->m_args.virtual_path, hash, mount_root_base, parent);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)&this->m_mount_ptr)[13] = (const vostok::variant<32> *)mount_root;
  this->m_mount_root_base->mount.pointer = (vostok::vfs::vfs_mount *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_mount_ptr);
}
