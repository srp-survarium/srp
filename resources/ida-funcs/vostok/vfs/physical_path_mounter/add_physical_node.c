vostok::vfs::base_node<1> *__userpurge vostok::vfs::physical_path_mounter::add_physical_node@<eax>(
        vostok::vfs::physical_path_mounter *this@<esi>,
        const vostok::fs_new::virtual_path_string *name@<eax>,
        vostok::fs_new::device_file_system_proxy_base *a3@<ecx>,
        vostok::fs_new::virtual_path_string *virtual_path,
        vostok::vfs::base_node<1> *virtual_path_hash,
        const vostok::fs_new::native_path_string *physical_path,
        vostok::vfs::base_node<1> *parent)
{
  vostok::vfs::physical_file_node<1> *v9; // eax
  vostok::vfs::mounter *v10; // ecx
  vostok::vfs::base_node<1> *p_base; // edi
  vostok::vfs::physical_folder_node<1> *v12; // eax
  vostok::vfs::base_node<1> *v13; // eax
  vostok::vfs::mounter *v14; // [esp-4h] [ebp-144h]
  vostok::fs_new::physical_path_info v15; // [esp+8h] [ebp-138h] BYREF

  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
    a3,
    &this->m_device->m_device.m_device_file_system,
    &v15,
    physical_path);
  if ( v15.data.type == type_error_no_path )
    return 0;
  if ( v15.data.type == type_file )
  {
    v9 = vostok::vfs::physical_file_node<1>::create(this->m_mount_root_base, name, v15.data.file_size);
    if ( v9 )
    {
      p_base = &v9->base;
      goto LABEL_8;
    }
LABEL_9:
    this->m_result = result_out_of_memory;
    return 0;
  }
  v12 = vostok::vfs::physical_folder_node<1>::create(this->m_args.allocator, name, this->m_mount_root_base);
  v10 = v14;
  if ( !v12 )
    goto LABEL_9;
  p_base = &v12->folder.base;
LABEL_8:
  if ( !p_base )
    goto LABEL_9;
  if ( parent )
    v13 = (vostok::vfs::base_node<1> *)vostok::vfs::cast_folder<1>(parent);
  else
    v13 = 0;
  vostok::vfs::mounter::merge_node_with_tree(
    v10,
    this,
    virtual_path,
    __PAIR64__((unsigned int)p_base, (unsigned int)virtual_path_hash),
    v13);
  return p_base;
}
