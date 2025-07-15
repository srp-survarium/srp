vostok::vfs::base_node<1> *__thiscall vostok::vfs::physical_path_mounter::add_physical_node(
        vostok::vfs::physical_path_mounter *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *name,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *virtual_path,
        unsigned int virtual_path_hash,
        const vostok::fs_new::native_path_string *physical_path,
        vostok::vfs::base_node<1> *parent)
{
  vostok::vfs::base_folder_node<1> *v7; // eax
  vostok::vfs::physical_folder_node<1> *folder_node; // [esp+14h] [ebp-144h]
  vostok::vfs::physical_file_node<1> *file_node; // [esp+18h] [ebp-140h]
  vostok::vfs::base_node<1> *node; // [esp+1Ch] [ebp-13Ch]
  vostok::fs_new::physical_path_info info; // [esp+20h] [ebp-138h] BYREF

  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(&this->m_device->m_device, &info, physical_path);
  if ( info.data.type == type_error_no_path )
    return 0;
  if ( info.data.type == type_file )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)1);
    file_node = vostok::vfs::physical_file_node<1>::create(
                  this->m_args.allocator,
                  this->m_mount_root_base,
                  name,
                  info.data.file_size);
    node = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>((vostok::vfs::hard_link_node<1> *)file_node);
  }
  else
  {
    folder_node = vostok::vfs::physical_folder_node<1>::create(this->m_args.allocator, this->m_mount_root_base, name);
    node = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_folder_node,1>(folder_node);
  }
  if ( node )
  {
    v7 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(parent);
    vostok::vfs::mounter::merge_node_with_tree(this, virtual_path, virtual_path_hash, node, v7);
    return node;
  }
  else
  {
    this->m_result = result_success;
    return 0;
  }
}
