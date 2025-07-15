void __thiscall vostok::resources::resources_manager::resources_manager(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *hdd,
        vostok::vfs::virtual_file_system *dvd,
        volatile int enable_fs_watcher)
{
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  vostok::threading::mutex_tasks_unaware *v5; // ecx
  _DWORD *v6; // esi
  vostok::threading::mutex_tasks_unaware *v7; // ecx
  vostok::threading::mutex_tasks_unaware *v8; // ecx
  char *v9; // eax
  vostok::threading::mutex_tasks_unaware *v10; // ecx
  _DWORD *v11; // eax
  vostok::timing::timer *v12; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v13; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v14; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v15; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v16; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v17; // ecx
  _DWORD *v18; // esi
  vostok::threading::mutex_tasks_unaware *v19; // ecx
  _DWORD *v20; // esi
  vostok::threading::mutex_tasks_unaware *v21; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  vostok::threading::event_tasks_unaware *v25; // ecx
  vostok::threading::event_tasks_unaware *v26; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v27; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v28; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v29; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v30; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v31; // ecx
  vostok::threading::mutex_tasks_unaware *v32; // ecx
  vostok::threading::mutex_tasks_unaware *v33; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v34; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v35; // ecx
  _DWORD *v36; // eax
  vostok::threading::mutex_tasks_unaware *v37; // ecx
  vostok::timing::timer *v38; // ecx
  unsigned int writer_thread_id; // edx
  char *v40; // eax
  vostok::ppmd_compressor *v41; // ecx
  DWORD v42; // eax
  vostok::resources::device_manager *v43; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v44; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *v45; // ecx
  void **v46; // esi
  vostok::command_line::key *v47; // ecx
  boost::function<void __cdecl(vostok::vfs::base_node<1> *)> *v48; // ecx
  vostok::resources::resources_manager *v49; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v50; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v51; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,vostok::vfs::base_node<1> *>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::arg<1> > > v52; // [esp-8h] [ebp-1Ch]
  vostok::buffer_vector<vostok::resources::cook_base *> *v53; // [esp-4h] [ebp-18h]
  const stlp_std::__true_type *v54; // [esp+0h] [ebp-14h]
  unsigned int v55; // [esp+4h] [ebp-10h]
  bool v56; // [esp+8h] [ebp-Ch]
  void *__x; // [esp+Ch] [ebp-8h] BYREF
  char v58; // [esp+10h] [ebp-4h]
  char v59; // [esp+11h] [ebp-3h]
  char v60; // [esp+12h] [ebp-2h]
  char v61; // [esp+13h] [ebp-1h]

  vostok::fs_new::native_path_string::native_path_string(&hdd->m_mounts_path);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v4,
    (int)&hdd->m_allocate_functionality);
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20165 + 3) = 0;
  memset((int)hdd->m_name_registry.m_buffer, 0, (unsigned int)&loc_20000);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v5,
    (_RTL_CRITICAL_SECTION *)((char *)hdd + (_DWORD)&loc_2016D + 3));
  v6 = (_DWORD *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20185 + 3);
  *v6 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v7,
    (_RTL_CRITICAL_SECTION *)((char *)&hdd->m_uncooked_queries_count + (_DWORD)&loc_20185 + 3));
  v6[9] = 0;
  v6[10] = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v8,
    (_RTL_CRITICAL_SECTION *)((char *)&dword_201C8 + (_DWORD)hdd));
  v9 = (char *)hdd + (_DWORD)&loc_201DF + 1;
  *((_DWORD *)v9 + 1) = 0;
  *((_DWORD *)v9 + 2) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v10,
    (_RTL_CRITICAL_SECTION *)((char *)&hdd->m_num_cook_registrators + (_DWORD)&loc_201DF + 1));
  v11 = (_DWORD *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20205 + 3);
  *v11 = 0;
  v11[1] = 0;
  v11[2] = 0;
  vostok::timing::timer::timer(v12, (LARGE_INTEGER *)((char *)hdd + (_DWORD)&loc_20215 + 3));
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v13,
    (int)hdd + (_DWORD)&loc_2022F + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v14,
    (int)hdd + (_DWORD)&loc_2025F + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v15,
    (int)&loc_20290 + (_DWORD)hdd);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v16,
    (int)hdd + (_DWORD)&loc_202BF + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v17,
    (int)hdd + (_DWORD)&loc_202EF + 1);
  v18 = (_DWORD *)((char *)&loc_20320 + (_DWORD)hdd);
  *v18 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v19,
    (_RTL_CRITICAL_SECTION *)((char *)&loc_20320 + (_DWORD)hdd + 8));
  v18[9] = 0;
  v18[10] = 0;
  v20 = (_DWORD *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2034D + 3);
  *v20 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v21,
    (_RTL_CRITICAL_SECTION *)((char *)&hdd->m_uncooked_queries_count + (_DWORD)&loc_2034D + 3));
  v20[9] = 0;
  v20[10] = 0;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v22,
    (int)&loc_20388 + (_DWORD)hdd);
  v23 = (_DWORD *)((char *)&loc_203B8 + (_DWORD)hdd);
  *v23 = 0;
  v23[1] = 0;
  *v23 = 0;
  v23[1] = 0;
  v61 = 0;
  v24 = (_DWORD *)((char *)&loc_203C0 + (_DWORD)hdd);
  *v24 = 0;
  v24[1] = v24;
  v24[2] = v24;
  v24[3] = 0;
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v25, (HANDLE *)((char *)hdd + (_DWORD)&loc_203D7 + 1));
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v26, (HANDLE *)((char *)&loc_203E8 + (_DWORD)hdd));
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v27,
    (int)hdd + (_DWORD)&loc_203EF + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v28,
    (int)&loc_20428 + (_DWORD)hdd);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v29,
    (int)hdd + (_DWORD)&loc_20457 + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v30,
    (int)&loc_20488 + (_DWORD)hdd);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v31,
    (int)hdd + (_DWORD)&loc_204B4 + 4);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v32,
    (_RTL_CRITICAL_SECTION *)((char *)hdd + (_DWORD)&loc_204E6 + 2));
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v33,
    (_RTL_CRITICAL_SECTION *)((char *)hdd + (_DWORD)&loc_20505 + 3));
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v34,
    (int)hdd + (_DWORD)&loc_2051F + 1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v35,
    (int)hdd + (_DWORD)&loc_2054F + 1);
  v36 = (_DWORD *)((char *)&loc_20580 + (_DWORD)hdd);
  v36[4] = v36;
  v36[5] = 0;
  v36[6] = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v37,
    (_RTL_CRITICAL_SECTION *)((char *)&loc_205A0 + (_DWORD)hdd));
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205B4 + 4) = 0;
  vostok::timing::timer::timer(v38, (LARGE_INTEGER *)((char *)&loc_205D8 + (_DWORD)hdd));
  writer_thread_id = dvd->hashset.m_hashlocks[21].m_readers_writers_counter.writer_thread_id;
  v40 = (char *)hdd + (_DWORD)&loc_205F2 + 2;
  *(_DWORD *)v40 = 0;
  *((_DWORD *)v40 + 1) = writer_thread_id;
  v40[8] = 0;
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205FF + 1) = (volatile int)dvd;
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20603 + 1) = enable_fs_watcher;
  vostok::vfs::virtual_file_system::virtual_file_system(dvd, (char *)&loc_20608 + (_DWORD)hdd);
  *(_DWORD *)((char *)&loc_407F0 + (_DWORD)hdd) = 0;
  *(_DWORD *)((char *)&loc_407F4 + (_DWORD)hdd) = 0;
  if ( (_UNKNOWN *)((char *)&loc_20580 + (_DWORD)hdd) )
    vostok::ppmd_compressor::ppmd_compressor(v41, (char *)&loc_20580 + (_DWORD)hdd);
  _InterlockedExchange(
    (volatile __int32 *)((char *)vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::execute
                       + (_DWORD)hdd),
    1);
  v42 = TlsAlloc();
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_204FD + 3) = 0;
  *(_DWORD *)((char *)&loc_203D0 + (_DWORD)hdd) = v42;
  hdd->m_do_mount_mounts_path = 0;
  *(int *)((char *)&dword_201B8 + (_DWORD)hdd) = 0;
  *(int *)((char *)&dword_201BC + (_DWORD)hdd) = 0;
  *(int *)((char *)&dword_20380 + (_DWORD)hdd) = 0;
  vostok::resources::device_manager::device_manager(v43, (int)&vostok::resources::s_hdd_device);
  *(_DWORD *)vostok::resources::s_hdd_device.m_static_memory = &vostok::resources::hdd_manager::`vftable';
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v44,
    (int)&vostok::resources::s_hdd_device.m_static_memory[8616]);
  _InterlockedExchange(&vostok::resources::s_hdd_device.m_initialized, 1);
  v45 = (stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *)((char *)hdd
                                                                                         + (_DWORD)&loc_20205
                                                                                         + 3);
  v46 = *(void ***)((char *)&hdd->m_pending_queries_count + (_DWORD)&loc_20205 + 3);
  __x = vostok::resources::s_hdd_device.m_variable;
  if ( v46 == *(void ***)((char *)&hdd->m_uncooked_queries_count + (_DWORD)&loc_20205 + 3) )
  {
    v58 = 0;
    stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *>>::_M_insert_overflow(
      v45,
      (int)hdd + (_DWORD)&loc_20205 + 3,
      v46,
      &__x,
      v54,
      v55,
      v56);
  }
  else
  {
    v60 = 0;
    *v46 = vostok::resources::s_hdd_device.m_variable;
    ++v45->_M_finish;
    v59 = 0;
  }
  hdd->m_pending_queries_count = 0;
  hdd->m_save_resources_queries_count = 0;
  hdd->m_uncooked_queries_count = 0;
  hdd->m_num_cook_registrators = 0;
  *(int *)((char *)&dword_201C0 + (_DWORD)hdd) = 0;
  hdd->m_fs_tasks_execute_on_current_tick = 0;
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2041E + 2) = 0;
  *((_BYTE *)&loc_205F0 + (_DWORD)hdd) = 0;
  *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_203D3 + 1) = 0;
  vostok::timing::timer::start((vostok::timing::timer *)v45, (LARGE_INTEGER *)((char *)hdd + (_DWORD)&loc_20215 + 3));
  if ( vostok::command_line::key::is_set(v47, (int)&vostok::threading::g_debug_single_thread) )
  {
    *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_203D3 + 1) = GetCurrentThreadId();
    *(volatile int *)((char *)&hdd->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_203DF + 1) = GetCurrentThreadId();
  }
  v52.l_.a1_.t_ = hdd;
  v52.f_.f_ = (void (__thiscall *)(vostok::resources::resources_manager *, vostok::vfs::base_node<1> *))vostok::resources::resources_manager::on_mounted;
  boost::function<void __cdecl (vostok::vfs::base_node<1> *)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,vostok::vfs::base_node<1> *>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::arg<1>>>>(
    v48,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)hdd + (_DWORD)&loc_407CF + 1),
    v52);
  vostok::resources::resources_manager::get_binary_config_cook(v49);
  vostok::resources::resources_manager::register_cook(&s_sub_fat_cook, v50);
  if ( (_S5_9 & 1) == 0 )
  {
    _S5_9 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      0,
      &stru_47EAC0C,
      reuse_false,
      0xFFFFFFFB,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v54);
    stru_47EAC0C.__vftable = (vostok::resources::cook_base_vtbl *)&vostok::resources::unknown_data_class_cook::`vftable';
    atexit((int (__cdecl *)())vostok::resources::resources_manager::register_cooks_::_2_::_dynamic_atexit_destructor_for__unknown_data_cook__);
    v51 = v53;
  }
  vostok::resources::resources_manager::register_cook(&stru_47EAC0C, v51);
}
