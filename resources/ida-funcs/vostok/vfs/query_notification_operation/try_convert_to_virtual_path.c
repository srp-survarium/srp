char __thiscall vostok::vfs::query_notification_operation::try_convert_to_virtual_path(
        vostok::vfs::query_notification_operation *this,
        const vostok::fs_new::native_path_string *physical_path,
        const vostok::fs_new::native_path_string *a3)
{
  const vostok::fs_new::native_path_string *v3; // ebx
  vostok::fs_new::virtual_path_string *v4; // eax
  boost::function<bool __cdecl(char const *,char const *,char const *)> *v5; // ecx
  vostok::threading::simple_lock *v6; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  int v9; // eax
  char *v10; // esi
  int v11; // ecx
  vostok::vfs::mount_result *v12; // ecx
  int v13; // ecx
  const vostok::vfs::mount_result *v14; // eax
  boost::function1<void,vostok::vfs::mount_result> *v15; // ecx
  int v17; // eax
  _BYTE v18[12]; // [esp-Ch] [ebp-44h] BYREF
  int v19; // [esp+0h] [ebp-38h]
  boost::_bi::bind_t<bool,boost::_mfi::mf3<bool,vostok::vfs::query_notification_operation,char const *,char const *,char const *>,boost::_bi::list4<boost::_bi::value<vostok::vfs::query_notification_operation *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v20[4]; // [esp+10h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v21; // [esp+30h] [ebp-8h] BYREF

  v3 = physical_path;
  v4 = *(vostok::fs_new::virtual_path_string **)&physical_path->m_string.m_buffer[32];
  v5 = (boost::function<bool __cdecl(char const *,char const *,char const *)> *)(v4->m_string.m_end
                                                                               - v4->m_string.m_begin);
  if ( v5 )
  {
    *(_DWORD *)&v18[8] = physical_path;
    *(_DWORD *)&v18[4] = vostok::vfs::query_notification_operation::mounts_filter;
    boost::function<bool __cdecl (char const *,char const *,char const *)>::function<bool __cdecl (char const *,char const *,char const *)>(
      v5,
      v20,
      *(boost::_bi::bind_t<bool,boost::_mfi::mf3<bool,vostok::vfs::query_notification_operation,char const *,char const *,char const *>,boost::_bi::list4<boost::_bi::value<vostok::vfs::query_notification_operation *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)&v18[4],
      v19);
    v7 = vostok::vfs::find_in_mount_history(
           (vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *)v3->m_string.m_begin,
           v6,
           (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&physical_path,
           v20);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      v7,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v3->m_string.m_buffer[16]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&physical_path);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)v20);
    v9 = *(_DWORD *)&v3->m_string.m_buffer[16];
  }
  else
  {
    v10 = &physical_path->m_string.m_buffer[16];
    if ( !vostok::vfs::convert_physical_to_virtual_path(
            (vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *)physical_path->m_string.m_begin,
            v4,
            a3,
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&physical_path->m_string.m_buffer[16]) )
    {
      *(_DWORD *)&v18[8] = 0;
      *(_DWORD *)&v18[4] = v11;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v18[4],
        0);
      vostok::vfs::mount_result::mount_result(
        v12,
        &v21,
        *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v18[4],
        *(vostok::vfs::vfs_mount **)&v18[8]);
      *(_DWORD *)&v18[8] = v13;
      *(_DWORD *)&v18[4] = v13;
      vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v18[4], v14);
      *(_DWORD *)v18 = *(_DWORD *)&v3->m_string.m_buffer[4];
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        v15,
        *(vostok::vfs::mount_result *)v18,
        *(boost::function1<void,vostok::vfs::mount_result> **)&v18[8]);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v21);
      return 0;
    }
    v9 = *(_DWORD *)v10;
  }
  v17 = *(_DWORD *)(v9 + 52);
  *(_DWORD *)&v3->m_string.m_buffer[20] = v17;
  *(_DWORD *)&v3->m_string.m_buffer[24] = *(_DWORD *)(v17 + 80);
  return 1;
}
