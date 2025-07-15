void __thiscall vostok::resources::device_manager::on_query_processed(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        bool result)
{
  vostok::resources::query_result *v4; // ecx
  vostok::resources::save_generated_data *m_save_generated_data; // edi
  vostok::fixed_string<260> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::vfs::vfs_locked_iterator *v8; // ecx
  vostok::vfs::vfs_iterator v9; // [esp-14h] [ebp-2A4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > v10; // [esp-10h] [ebp-2A0h]
  vostok::vfs::vfs_locked_iterator v11; // [esp+10h] [ebp-280h] BYREF
  void (__thiscall *v12)(vostok::resources::resources_manager *, vostok::resources::allocate_functionality *); // [esp+24h] [ebp-26Ch]
  vostok::resources::resources_manager *v13; // [esp+28h] [ebp-268h]
  int v14; // [esp+2Ch] [ebp-264h]
  int v15; // [esp+34h] [ebp-25Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+38h] [ebp-258h]
  boost::function<void __cdecl(void)> f; // [esp+40h] [ebp-250h] BYREF
  boost::function<void __cdecl(vostok::vfs::mount_result)> v18[8]; // [esp+60h] [ebp-230h] BYREF
  char v19; // [esp+170h] [ebp-120h]
  vostok::fs_new::virtual_path_string v20; // [esp+178h] [ebp-118h] BYREF

  lpCriticalSection = (LPCRITICAL_SECTION)&this->m_pre_allocated_mutex;
  vostok::threading::mutex::lock(
    (vostok::threading::mutex *)this,
    (_RTL_CRITICAL_SECTION *)&this->m_pre_allocated_mutex);
  if ( (query->m_flags & 2) != 0 )
    this->m_pre_allocated_size -= vostok::resources::query_result::raw_buffer_size(v4, query);
  if ( (query->m_flags & 8) != 0 )
  {
    m_save_generated_data = query->m_save_generated_data;
    vostok::fixed_string<260>::fixed_string<260>(
      (vostok::fixed_string<260> *)v4,
      &v20.m_string,
      m_save_generated_data->m_physical_path);
    v20.m_separator = 92;
    vostok::fixed_string<260>::fixed_string<260>(
      v6,
      (vostok::buffer_string *)v18,
      m_save_generated_data->m_virtual_path);
    memset(&v11, 0, sizeof(v11));
    LOBYTE(v15) = 0;
    v14 = v15;
    v13 = &s_resources_manager_buffer;
    v12 = vostok::resources::resources_manager::dispatch_callbacks;
    v10.l_.a1_.t_ = (vostok::resources::resources_manager *)vostok::resources::resources_manager::dispatch_callbacks;
    *(_DWORD *)&v10.l_.a2_.t_ = &s_resources_manager_buffer;
    v10.f_.f_ = (void (__thiscall *)(vostok::resources::resources_manager *, bool))&f;
    v19 = 47;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&s_resources_manager_buffer,
      v10,
      v15);
    vostok::vfs::query_hot_mount_and_wait(
      (vostok::fs_new::native_path_string *)&s_resources_manager_buffer.m_vfs,
      &v20,
      v18,
      &v11,
      &vostok::memory::g_resources_helper_allocator,
      &f);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&f);
    *(_QWORD *)&v9.m_link_target = *(_QWORD *)&v11.m_node;
    *(_QWORD *)&v9.m_hashset = __PAIR64__((unsigned int)v11.m_hashset, (unsigned int)query);
    vostok::resources::query_result::late_set_fat_it(
      (vostok::resources::query_result *)v11.m_type,
      v9,
      (vostok::resources::managed_resource *)v11.m_type);
    vostok::vfs::vfs_locked_iterator::clear(v8, (int)&v11);
  }
  vostok::resources::query_result::on_file_operation_end(v4, (int)query);
  LeaveCriticalSection(lpCriticalSection);
}
