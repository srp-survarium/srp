void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(
        vostok::vfs::query_notification_operation *this,
        const char ***only_update_size)
{
  vostok::vfs::vfs_hashset *v2; // ecx
  vostok::vfs::base_node<1> *v3; // ecx
  vostok::vfs::base_node<1> *node_on_virtual_path; // edi
  const char **v5; // esi
  vostok::fs_new::native_path_string *v6; // eax
  vostok::vfs::mount_result *v7; // ecx
  vostok::vfs::vfs_mount *v8; // ecx
  const vostok::vfs::mount_result *v9; // eax
  boost::function1<void,vostok::vfs::mount_result> *v10; // ecx
  vostok::vfs::overlapped_node_iterator *v11; // ecx
  const char **v12; // eax
  vostok::fs_new::device_file_system_proxy_base *v13; // ecx
  vostok::vfs::mount_result *v14; // ecx
  vostok::vfs::vfs_mount *v15; // ecx
  const vostok::vfs::mount_result *v16; // eax
  boost::function1<void,vostok::vfs::mount_result> *v17; // ecx
  vostok::vfs::query_mount_arguments *v18; // ecx
  vostok::vfs::result_enum v19; // ecx
  int v20; // eax
  const char **v21; // esi
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v22; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v23; // ecx
  vostok::vfs::query_notification_operation *v24; // ecx
  vostok::vfs::query_notification_operation *v25; // ecx
  vostok::vfs::base_node<1> *v26; // eax
  vostok::threading::mutex *v27; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v28; // ecx
  vostok::vfs::overlapped_node_iterator *v29; // ecx
  vostok::vfs::mount_result v30; // [esp-Ch] [ebp-798h] BYREF
  int v31; // [esp-4h] [ebp-790h]
  vostok::fs_new::watcher_enabled_bool v32; // [esp+0h] [ebp-78Ch]
  vostok::vfs::query_mount_arguments v33; // [esp+10h] [ebp-77Ch] BYREF
  vostok::fs_new::native_path_string v34; // [esp+4ECh] [ebp-2A0h] BYREF
  vostok::fs_new::physical_path_info v35; // [esp+600h] [ebp-18Ch] BYREF
  vostok::fs_new::synchronous_device_interface v36; // [esp+73Ch] [ebp-50h] BYREF
  vostok::vfs::overlapped_node_iterator v37; // [esp+748h] [ebp-44h] BYREF
  vostok::vfs::overlapped_node_iterator v38; // [esp+758h] [ebp-34h] BYREF
  const char *v39; // [esp+768h] [ebp-24h] BYREF
  vostok::vfs::base_node<1> *v40; // [esp+76Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v41; // [esp+770h] [ebp-1Ch] BYREF
  int v42; // [esp+774h] [ebp-18h]
  vostok::vfs::overlapped_node_iterator v43; // [esp+778h] [ebp-14h] BYREF

  if ( vostok::vfs::query_notification_operation::try_convert_to_virtual_path(
         this,
         (const vostok::fs_new::native_path_string *)only_update_size,
         (const vostok::fs_new::native_path_string *)only_update_size[1]) )
  {
    vostok::vfs::vfs_hashset::equal_range(
      v2,
      (vostok::vfs::vfs_hashset *)(*only_update_size + 6),
      (char *)&v38,
      (char *)*only_update_size[11],
      lock_type_read);
    v43 = v38;
    v37.path = v39;
    v37.node = v40;
    v37.lock_type = (vostok::vfs::lock_type_enum)v41.m_object;
    v37.hashset_lock = (vostok::threading::reader_writer_lock *)v42;
    node_on_virtual_path = vostok::vfs::query_notification_operation::find_node_on_virtual_path(
                             &v43,
                             (vostok::vfs::overlapped_node_iterator *)only_update_size,
                             &v37);
    if ( node_on_virtual_path )
    {
      v5 = only_update_size[1];
      v6 = vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(node_on_virtual_path, v3, &v34);
      if ( vostok::detail::strcmp_s(v6->m_string.m_begin, *v5) )
      {
        v31 = 0;
        v30.result = (vostok::vfs::result_enum)v3;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v30.result,
          (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)only_update_size
        + 7);
LABEL_5:
        vostok::vfs::mount_result::mount_result(
          v7,
          &v41,
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v30.result,
          (vostok::vfs::vfs_mount *)v31);
        v31 = (int)v8;
        v30.result = (vostok::vfs::result_enum)v8;
        vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v30.result, v9);
        v30.mount.m_object = (vostok::vfs::vfs_mount *)only_update_size[4];
        boost::function1<void,vostok::vfs::mount_result>::operator()(
          v10,
          v30,
          (boost::function1<void,vostok::vfs::mount_result> *)v31);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v41);
LABEL_21:
        vostok::vfs::overlapped_node_iterator::clear(v11, &v37);
        vostok::vfs::overlapped_node_iterator::clear(v29, &v43);
        return;
      }
      if ( (node_on_virtual_path->m_flags & 1) != 0 )
      {
        v12 = only_update_size[8];
        v31 = 1;
        v30.result = (vostok::vfs::result_enum)v3;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v30.result,
          (vostok::vfs::vfs_mount *)v12[14]);
        goto LABEL_5;
      }
    }
    vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
      &v36,
      (vostok::fs_new::device_file_system_interface *)only_update_size[8][4],
      (vostok::fs_new::asynchronous_device_interface *)v3,
      (vostok::fs_new::asynchronous_device_query_vtbl *)only_update_size[8][6],
      (vostok::memory::base_allocator *)only_update_size[8][2],
      v32);
    if ( v36.m_out_of_memory )
    {
      v31 = 3;
      v30.result = (vostok::vfs::result_enum)v13;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v30.result,
        0);
    }
    else
    {
      vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
        v13,
        &v36.m_device.m_device_file_system,
        &v35,
        (const vostok::fs_new::native_path_string *)only_update_size[1]);
      if ( v35.data.type )
      {
        if ( !node_on_virtual_path )
        {
          vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)v19, &v43);
          if ( vostok::vfs::query_notification_operation::try_write_lock(v24, (int)only_update_size) )
          {
            vostok::vfs::query_mount_arguments::query_mount_arguments(v18, (int)&v33);
            v26 = (vostok::vfs::base_node<1> *)only_update_size[8];
            if ( v26 )
              v26 = *(vostok::vfs::base_node<1> **)&v26->m_name[13];
            vostok::vfs::query_notification_operation::fill_mount_arguments(
              v25,
              (vostok::vfs::query_mount_arguments *)only_update_size,
              &v33,
              (vostok::fs_new::asynchronous_device_interface *)&v36,
              v26,
              (vostok::fs_new::device_file_system_interface *)4,
              (const vostok::fs_new::virtual_path_string *)only_update_size[1]);
            vostok::vfs::virtual_file_system::query_mount(
              &v33,
              v27,
              (vostok::vfs::virtual_file_system *)*only_update_size);
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v28,
              (int *)&v33.callback);
          }
          goto LABEL_20;
        }
        _InterlockedExchange(&vostok::vfs::cast_physical_file<1>(node_on_virtual_path)->m_size, v35.data.file_size);
        v20 = (int)*only_update_size;
        v21 = *only_update_size + 32866;
        v19 = -(*v21 != 0);
        if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v19) != 0 )
        {
          v41.m_object = 0;
          v39 = (const char *)(v20 + 24);
          v40 = node_on_virtual_path;
          v42 = 2;
          vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)node_on_virtual_path, (int)&v39);
          boost::function1<void,vostok::collision::object const &>::operator()(v23, v21, v22);
        }
      }
      v31 = 1;
      v30.result = v19;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v30.result,
        (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)only_update_size
      + 7);
    }
    vostok::vfs::mount_result::mount_result(
      v14,
      &v41,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v30.result,
      (vostok::vfs::vfs_mount *)v31);
    v31 = (int)v15;
    v30.result = (vostok::vfs::result_enum)v15;
    vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v30.result, v16);
    v30.mount.m_object = (vostok::vfs::vfs_mount *)only_update_size[4];
    boost::function1<void,vostok::vfs::mount_result>::operator()(
      v17,
      v30,
      (boost::function1<void,vostok::vfs::mount_result> *)v31);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v41);
LABEL_20:
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(
      (vostok::fs_new::synchronous_device_interface *)v18,
      (int *)&v36);
    goto LABEL_21;
  }
}
