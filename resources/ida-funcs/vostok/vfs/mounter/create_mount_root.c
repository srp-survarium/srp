vostok::vfs::physical_file_mount_root_node<1> *__userpurge vostok::vfs::mounter::create_mount_root@<eax>(
        vostok::vfs::mounter *this@<edi>,
        const vostok::fs_new::virtual_path_string *path@<eax>,
        bool mounting_folder)
{
  char *v3; // eax
  vostok::vfs::physical_file_mount_root_node<1> *result; // eax

  v3 = vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>(path);
  if ( this->m_args.type == mount_type_physical_path && mounting_folder )
    result = (vostok::vfs::physical_file_mount_root_node<1> *)vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_folder_mount_root_node,1>(
                                                                strlen(v3),
                                                                &this->m_args,
                                                                v3,
                                                                this->m_file_system);
  else
    result = vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_file_mount_root_node,1>(
               strlen(v3),
               &this->m_args,
               v3,
               this->m_file_system);
  result->mount_id = this->m_mount_id;
  result->mount_operation_id = _InterlockedIncrement(&vostok::vfs::s_mount_operation_id);
  return result;
}
