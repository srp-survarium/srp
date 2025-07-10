vostok::vfs::mount_root_node_base<1> *__thiscall vostok::vfs::mounter::create_mount_root(
        vostok::vfs::mounter *this,
        bool mounting_folder,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *path)
{
  vostok::vfs::mounter *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  vostok::vfs::virtual_file_system *m_file_system; // [esp-8h] [ebp-CCh]
  vostok::vfs::virtual_file_system *v8; // [esp-8h] [ebp-CCh]
  vostok::vfs::mount_root_node_base<1> *new_mount_root; // [esp+BCh] [ebp-8h]
  const char *root_name; // [esp+C0h] [ebp-4h]

  root_name = (const char *)vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>(path);
  v3 = this;
  if ( this->m_args.type == mount_type_archive )
  {
    new_mount_root = 0;
  }
  else if ( this->m_args.type == mount_type_physical_path && mounting_folder )
  {
    m_file_system = this->m_file_system;
    v4 = vostok::strings::length(root_name);
    new_mount_root = vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_folder_mount_root_node,1>(
                       root_name,
                       v4,
                       m_file_system,
                       &this->m_args);
  }
  else
  {
    v8 = this->m_file_system;
    v5 = vostok::strings::length(root_name);
    new_mount_root = vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_file_mount_root_node,1>(
                       root_name,
                       v5,
                       v8,
                       &this->m_args);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  new_mount_root->mount_id = this->m_mount_id;
  new_mount_root->mount_operation_id = vostok::vfs::next_mount_operation_id();
  return new_mount_root;
}
