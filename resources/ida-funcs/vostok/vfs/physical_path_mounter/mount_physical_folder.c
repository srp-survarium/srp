void __thiscall vostok::vfs::physical_path_mounter::mount_physical_folder(
        vostok::vfs::physical_path_mounter *this,
        vostok::fs_new::virtual_path_string *folder_path,
        vostok::vfs::physical_folder_node<1> *folder,
        vostok::fs_new::native_path_string *absolute_path,
        unsigned int folder_hash)
{
  vostok::fs_new::physical_path_info *v5; // ecx
  vostok::fs_new::physical_path_initializer *v6; // eax
  vostok::fs_new::physical_path_info *v7; // ecx
  vostok::fs_new::physical_path_initializer *v8; // ecx
  vostok::fs_new::physical_path_info *v9; // ecx
  vostok::fs_new::physical_path_iterator *v10; // ecx
  char *m_begin; // edx
  char *v12; // eax
  vostok::vfs::physical_path_mounter *v13; // edi
  vostok::vfs::physical_file_node<1> *v14; // eax
  int v15; // ecx
  vostok::vfs::base_node<1> *p_base; // esi
  vostok::vfs::physical_folder_node<1> *v17; // eax
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v18; // ecx
  vostok::fs_new::physical_path_iterator *v19; // ecx
  vostok::fs_new::physical_path_iterator *v20; // ecx
  vostok::vfs::physical_path_mounter *v21; // ecx
  vostok::vfs::base_folder_node<1> *p_folder; // eax
  bool v23; // cl
  vostok::fs_new::physical_path_iterator *v24; // [esp-4h] [ebp-52Ch]
  bool *v25; // [esp+0h] [ebp-528h]
  char v26; // [esp+Fh] [ebp-519h]
  vostok::vfs::base_folder_node<1> *folder_size; // [esp+14h] [ebp-514h]
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_nodes; // [esp+18h] [ebp-510h] BYREF
  vostok::fs_new::physical_path_initializer v30; // [esp+30h] [ebp-4F8h] BYREF
  vostok::fs_new::physical_path_iterator v31; // [esp+170h] [ebp-3B8h] BYREF
  vostok::fs_new::device_file_system_interface *v32[78]; // [esp+2B0h] [ebp-278h] BYREF
  unsigned __int64 search_handle; // [esp+3E8h] [ebp-140h]
  vostok::fs_new::physical_path_info v34; // [esp+3F0h] [ebp-138h] BYREF

  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
    (vostok::fs_new::device_file_system_proxy_base *)this,
    &this->m_device->m_device.m_device_file_system,
    &v34,
    absolute_path);
  folder_size = 0;
  new_nodes.m_size = 0;
  memset(&new_nodes.m_first, 0, 16);
  v26 = 0;
  v6 = vostok::fs_new::physical_path_info::children_begin(v5, &v34, &v30);
  vostok::fs_new::physical_path_iterator::physical_path_iterator(&v31, v6, v7);
  vostok::fs_new::physical_path_initializer::physical_path_initializer(v8, &v30);
  vostok::fs_new::physical_path_info::physical_path_info(v9, v32, &v30);
  search_handle = v30.search_handle;
  while ( v31.search_handle != search_handle )
  {
    LODWORD(v30.search_handle) = &v30.parent + 1;
    HIDWORD(v30.search_handle) = &v30.parent + 1;
    v30.parent = (const vostok::fs_new::physical_path_info *)&v30.data.path.m_string.m_buffer[228];
    *((_BYTE *)&v30.parent + 4) = 0;
    v30.data.path.m_string.m_buffer[228] = 47;
    if ( v31.data.path_type == path_type_contains_name )
    {
      m_begin = v31.data.path.m_string.m_begin;
      if ( &v30.parent + 1 == (const vostok::fs_new::physical_path_info **)v31.data.path.m_string.m_begin )
        goto LABEL_9;
      HIDWORD(v30.search_handle) = &v30.parent + 1;
    }
    else
    {
      v12 = vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>(&v31.data.path);
      if ( &v30.parent + 1 == (const vostok::fs_new::physical_path_info **)v12 )
        goto LABEL_9;
      HIDWORD(v30.search_handle) = &v30.parent + 1;
      m_begin = v12;
    }
    *((_BYTE *)&v30.parent + 4) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)&v30, m_begin);
LABEL_9:
    if ( HIDWORD(v30.search_handle) != LODWORD(v30.search_handle) )
      _strlwr_s((char *)v30.search_handle, HIDWORD(v30.search_handle) - LODWORD(v30.search_handle) + 1);
    if ( v31.data.type == type_file )
    {
      v13 = this;
      v14 = vostok::vfs::physical_file_node<1>::create(
              this->m_mount_root_base,
              (const vostok::fs_new::virtual_path_string *)&v30,
              v31.data.file_size);
      if ( !v14 )
      {
        v26 = 1;
        goto LABEL_20;
      }
      v15 = 8;
      _InterlockedOr(&v14->m_file_flags.m_flags, 8u);
      p_base = &v14->base;
    }
    else
    {
      v17 = vostok::vfs::physical_folder_node<1>::create(
              this->m_args.allocator,
              (const vostok::fs_new::virtual_path_string *)&v30,
              this->m_mount_root_base);
      v10 = v24;
      if ( !v17 )
      {
        v26 = 1;
        break;
      }
      v15 = 4;
      _InterlockedOr(&v17->m_folder_flags.m_flags, 4u);
      p_base = &v17->folder.base;
    }
    vostok::vfs::base_node<1>::sizeof_with_name((vostok::vfs::base_node<1> *)v15, p_base);
    folder_size = (vostok::vfs::base_folder_node<1> *)vostok::math::align_up<unsigned long>(4u);
    vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v18,
      (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&new_nodes,
      (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)p_base,
      v25);
    vostok::fs_new::physical_path_iterator::operator++(v19, &v31);
  }
  v13 = this;
LABEL_20:
  vostok::fs_new::physical_path_iterator::~physical_path_iterator(v10, v32);
  vostok::fs_new::physical_path_iterator::~physical_path_iterator(v20, &v31);
  if ( v26 )
  {
    v13->m_result = result_out_of_memory;
    vostok::vfs::physical_path_mounter::free_node_list(v21, (int)v13, &new_nodes);
  }
  else
  {
    if ( new_nodes.m_first.pointer )
    {
      vostok::vfs::physical_path_mounter::flatten_helper_nodes_and_merge(
        folder,
        absolute_path,
        v13,
        &new_nodes,
        folder_path,
        folder_hash,
        folder_size);
      if ( folder )
        p_folder = &folder->folder;
      else
        p_folder = 0;
      vostok::vfs::mounter::remove_marked_to_unlink_from_parent(p_folder);
      v13 = this;
    }
    v23 = v13->m_args.recursive == recursive_true && v13->m_result != result_out_of_memory;
    vostok::vfs::physical_folder_node<1>::set_is_scanned(folder, v23);
  }
}
