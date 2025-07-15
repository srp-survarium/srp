void __thiscall vostok::vfs::physical_path_mounter::mount_root(
        vostok::vfs::physical_path_mounter *this,
        vostok::vfs::physical_path_mounter *a2)
{
  signed __int32 mount_id; // eax
  vostok::vfs::mounter *v4; // ecx
  bool v5; // al
  char *m_begin; // eax
  int v7; // edx
  void *v8; // esp
  vostok::vfs::mounter *v9; // ecx
  vostok::vfs::physical_file_mount_root_node<1> *mount_root; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *file_size; // ecx
  bool v12; // zf
  vostok::vfs::base_node<1> *v13; // eax
  vostok::vfs::physical_folder_mount_root_node<1> *v14; // edi
  vostok::vfs::physical_folder_node<1> *p_folder; // eax
  bool has_passed_filters; // al
  int *v17; // esi
  bool v18; // al
  vostok::vfs::vfs_mount *m_object; // ecx
  vostok::vfs::mounter *v20; // [esp-4h] [ebp-3F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v21; // [esp-4h] [ebp-3F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v22; // [esp-4h] [ebp-3F8h]
  _DWORD v23[4]; // [esp+0h] [ebp-3F4h] BYREF
  vostok::fs_new::virtual_path_string folder_path; // [esp+10h] [ebp-3E4h] BYREF
  vostok::fs_new::native_path_string absolute_path; // [esp+128h] [ebp-2CCh] BYREF
  vostok::fs_new::physical_path_info v26; // [esp+240h] [ebp-1B4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+378h] [ebp-7Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v28; // [esp+398h] [ebp-5Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v29; // [esp+3B8h] [ebp-3Ch] BYREF
  vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> out_helper_nodes; // [esp+3DCh] [ebp-18h] BYREF
  unsigned int path_hash; // [esp+3E8h] [ebp-Ch] BYREF
  bool mounting_folder[4]; // [esp+3ECh] [ebp-8h] BYREF
  char v33; // [esp+3FCh] [ebp+8h]

  mount_id = a2->m_args.mount_id;
  v33 = 0;
  if ( !mount_id )
  {
    this = (vostok::vfs::physical_path_mounter *)&vostok::vfs::s_mount_id;
    mount_id = _InterlockedIncrement(&vostok::vfs::s_mount_id);
  }
  a2->m_mount_id = mount_id;
  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
    (vostok::fs_new::device_file_system_proxy_base *)this,
    &a2->m_device->m_device.m_device_file_system,
    &v26,
    &a2->m_args.physical_path);
  if ( v26.data.type )
  {
    m_begin = a2->m_args.virtual_path.m_string.m_begin;
    v7 = 0;
    while ( 1 )
    {
      LOBYTE(v4) = *m_begin;
      if ( !*m_begin )
        break;
      if ( (_BYTE)v4 == 47 )
        ++v7;
      ++m_begin;
    }
    v8 = alloca(4 * v7 + 4);
    out_helper_nodes.m_begin = (vostok::vfs::mount_helper_node<1> **)v23;
    out_helper_nodes.m_end = (vostok::vfs::mount_helper_node<1> **)v23;
    out_helper_nodes.m_max_end = (vostok::vfs::mount_helper_node<1> **)&v23[v7 + 1];
    if ( !vostok::vfs::mounter::allocate_mount_branch(v4, a2, &out_helper_nodes) )
      goto LABEL_16;
    mounting_folder[0] = v26.data.type == type_folder;
    mount_root = vostok::vfs::mounter::create_mount_root(a2, &a2->m_args.virtual_path, v26.data.type == type_folder);
    if ( !mount_root )
    {
      vostok::vfs::mounter::free_mount_branch(&out_helper_nodes, a2);
LABEL_16:
      vostok::vfs::mounter::finish_with_out_of_memory(v9, (int)a2);
      return;
    }
    *(_DWORD *)mounting_folder = 0;
    path_hash = 0;
    vostok::vfs::mounter::add_mount_branch(
      (vostok::vfs::mounter *)&path_hash,
      a2,
      (vostok::vfs::base_node<1> **)&out_helper_nodes,
      (vostok::vfs::base_node<1> **)mounting_folder,
      &a2->m_args.root_write_lock,
      &path_hash);
    path_hash = vostok::fs_new::path_crc32(
                  a2->m_args.virtual_path.m_string.m_begin,
                  a2->m_args.virtual_path.m_string.m_end - a2->m_args.virtual_path.m_string.m_begin,
                  0);
    vostok::vfs::mounter::add_mount_helper_node_impl(
      mount_root->node.pointer,
      a2,
      &a2->m_args.virtual_path,
      path_hash,
      (vostok::vfs::base_node<1> **)mounting_folder,
      &a2->m_args.root_write_lock);
    v12 = v26.data.type == type_file;
    a2->m_mount_root_base = mount_root;
    if ( v12 )
    {
      v13 = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(mount_root->node.pointer);
      file_size = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v26.data.file_size;
      *(_DWORD *)&v13->m_name[45] = 0;
      *(_DWORD *)&v13->m_name[53] = file_size;
    }
    else if ( a2->m_args.recursive == recursive_true )
    {
      v14 = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(mount_root->node.pointer);
      vostok::fixed_string<260>::fixed_string<260>(&absolute_path.m_string, &a2->m_args.physical_path.m_string);
      absolute_path.m_separator = 92;
      vostok::fixed_string<260>::fixed_string<260>(&folder_path.m_string, &a2->m_args.virtual_path.m_string);
      folder_path.m_separator = 47;
      if ( v14 )
        p_folder = &v14->folder;
      else
        p_folder = 0;
      vostok::vfs::physical_path_mounter::mount_physical_folder(a2, &folder_path, p_folder, &absolute_path, path_hash);
    }
    if ( v26.data.type == type_file )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&stru_7FD250,
                                   (const char *)4),
            file_size = v21,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          file_size,
          &v29);
        v33 = 2;
        vostok::logging::append(
          &v29,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\mount_physical_path.cpp",
          0x8Eu,
          "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
          (char *)&stru_7FD250,
          info,
          "mounting file '%s' on '%s'",
          a2->m_args.physical_path.m_string.m_begin,
          a2->m_args.virtual_path.m_string.m_begin);
      }
      if ( (v33 & 2) == 0 )
        goto LABEL_38;
      v17 = (int *)&v29;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_7FD250, (const char *)4),
            file_size = v22,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          file_size,
          &v28);
        v33 = 4;
        vostok::logging::append(
          &v28,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\mount_physical_path.cpp",
          0x90u,
          "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
          (char *)&stru_7FD250,
          info,
          "mounted folder '%s' on '%s'",
          a2->m_args.physical_path.m_string.m_begin,
          a2->m_args.virtual_path.m_string.m_begin);
      }
      if ( (v33 & 4) == 0 )
        goto LABEL_38;
      v17 = (int *)&v28;
    }
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)file_size,
      v17);
LABEL_38:
    a2->m_mount_ptr.m_object->m_mount_root = a2->m_mount_root_base;
    m_object = a2->m_mount_ptr.m_object;
    a2->m_mount_root_base->mount.pointer = m_object;
    vostok::vfs::add_to_mount_history(
      a2->m_mount_ptr.m_object,
      a2->m_file_system,
      (vostok::threading::simple_lock *)m_object);
    return;
  }
  if ( !vostok::core::g_log_filter_tree
    || (v5 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_7FD250, (const char *)2),
        v4 = v20,
        v5) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
      &log_callback);
    v33 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_physical_path.cpp",
      0x59u,
      "void __thiscall vostok::vfs::physical_path_mounter::mount_root(void)",
      (char *)&stru_7FD250,
      error,
      "mount physical path doesnt exist : '%s'",
      a2->m_args.physical_path.m_string.m_begin);
  }
  if ( (v33 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&log_callback);
  a2->m_result = result_fail;
}
