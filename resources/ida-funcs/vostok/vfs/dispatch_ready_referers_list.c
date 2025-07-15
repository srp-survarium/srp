char *vostok::vfs::dispatch_ready_referers_list()
{
  char *result; // eax
  vostok::threading::mutex *v1; // ecx
  char *v2; // ebx
  int *v3; // ebp
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v4; // eax
  boost::function1<void,vostok::vfs::mount_result> *v5; // ecx
  vostok::vfs::mount_result *v6; // ecx
  boost::function1<void,vostok::vfs::mount_result> *v7; // ecx
  int v8; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v10; // [esp-10h] [ebp-24h] BYREF
  vostok::vfs::mount_result v11; // [esp-Ch] [ebp-20h] BYREF
  _RTL_CRITICAL_SECTION *v12; // [esp-4h] [ebp-18h]
  vostok::vfs::result_enum *p_result; // [esp+10h] [ebp-4h]

  result = (char *)TlsGetValue(s_ready_referers_tls_key);
  v2 = result;
  if ( result )
  {
    while ( *((_DWORD *)v2 + 9) )
    {
      vostok::threading::mutex::lock(v1, (_RTL_CRITICAL_SECTION *)(v2 + 8));
      v3 = (int *)*((_DWORD *)v2 + 9);
      if ( v3 )
      {
        --*(_DWORD *)v2;
        v4.m_object = (vostok::vfs::vfs_mount *)*v3;
        *((_DWORD *)v2 + 9) = *v3;
        if ( !v4.m_object )
          *((_DWORD *)v2 + 10) = 0;
        v12 = (_RTL_CRITICAL_SECTION *)(v2 + 8);
        *v3 = 0;
        LeaveCriticalSection(v12);
      }
      else
      {
        LeaveCriticalSection((LPCRITICAL_SECTION)(v2 + 8));
        v3 = 0;
      }
      v12 = (_RTL_CRITICAL_SECTION *)v5;
      v11.result = (vostok::vfs::result_enum)v5;
      v11.mount.m_object = (vostok::vfs::vfs_mount *)1;
      v10.m_object = (vostok::vfs::vfs_mount *)v5;
      p_result = &v11.result;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v10,
        (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v3
      + 1);
      vostok::vfs::mount_result::mount_result(
        v6,
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)p_result,
        v10,
        v11.mount.m_object);
      v11.mount.m_object = (vostok::vfs::vfs_mount *)(v3 + 2);
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        v7,
        v11,
        (boost::function1<void,vostok::vfs::mount_result> *)v12);
      v8 = v3[10];
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v9,
        v3 + 2);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v3
      + 1);
      result = (char *)(*(int (__thiscall **)(int, int *, vostok::threading::mutex *, vostok::logging::node **, int))(*(_DWORD *)v8 + 24))(
                         v8,
                         v3,
                         &stru_7FD250.filter_stack.m_policy,
                         &stru_7FD250.initiator_tree,
                         42);
    }
  }
  return result;
}
