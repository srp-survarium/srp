void __userpurge vostok::engine::engine_world::initialize(
        vostok::engine::engine_world *this@<ecx>,
        double a2@<st0>,
        vostok::engine::engine_world *thisa)
{
  vostok::buffer_vector<vostok::apc::callback> *v3; // ecx
  vostok::engine::engine_world *v4; // ecx
  vostok::apc::callback *v5; // esi
  vostok::apc::callback *v6; // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v8; // esi
  vostok::engine::engine_world *v9; // ecx
  vostok::apc::callback *v10; // esi
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::collision::collision_cook *v12; // ecx
  vostok::engine::engine_world *v13; // ecx
  vostok::command_line::key *v14; // ecx
  LARGE_INTEGER v15; // rax
  const char *v16; // eax
  const char *v17; // eax
  char *m_buffer; // ecx
  char *v19; // esi
  char *v20; // eax
  char *v21; // esi
  bool v22; // zf
  vostok::apc::callback *p_m_pending; // esi
  vostok::engine::engine_world *v24; // ecx
  vostok::apc::callback *v25; // esi
  void (__cdecl *v26)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v27; // edi
  vostok::engine::engine_world *v28; // ecx
  vostok::apc::callback *v29; // edi
  void (__cdecl *v30)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v31; // edi
  vostok::engine::engine_world *v32; // ecx
  vostok::apc::callback *v33; // esi
  void (__cdecl *v34)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v35; // esi
  vostok::apc::callback *v36; // esi
  void (__cdecl *v37)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v38; // esi
  vostok::apc::callback *v39; // esi
  void (__cdecl *v40)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v41; // esi
  vostok::resources::resources_manager *v42; // ecx
  vostok::apc::callback *v43; // esi
  void (__cdecl *v44)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::tasks::thread_pool *v45; // ecx
  vostok::apc::callback *v46; // esi
  vostok::apc::callback *v47; // esi
  void (__cdecl *v48)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v49; // esi
  vostok::apc::callback *v50; // esi
  void (__cdecl *v51)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v52; // esi
  vostok::apc::callback *v53; // esi
  void (__cdecl *v54)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v55; // esi
  vostok::apc::callback *v56; // esi
  void (__cdecl *v57)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v58; // esi
  vostok::apc::callback *v59; // esi
  void (__cdecl *v60)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v61; // esi
  vostok::apc::callback *v62; // esi
  void (__cdecl *v63)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v64; // esi
  vostok::engine::engine_world *v65; // ecx
  vostok::apc::callback *v66; // esi
  void (__cdecl *v67)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v68; // esi
  vostok::apc::callback *v69; // esi
  void (__cdecl *v70)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list3<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *>,boost::arg<1> > > v71; // [esp-2Ch] [ebp-594h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list2<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::arg<1> > > v72; // [esp-28h] [ebp-590h]
  _BYTE v73[36]; // [esp-20h] [ebp-588h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-558h] BYREF
  __int64 v75; // [esp+18h] [ebp-550h]
  vostok::engine::engine_world *is_editor; // [esp+24h] [ebp-544h]
  boost::function0<void> *m_network_world; // [esp+28h] [ebp-540h]
  vostok::command_line::key_initializator predicate[4]; // [esp+2Ch] [ebp-53Ch]
  boost::function0<void> v79; // [esp+30h] [ebp-538h] BYREF
  boost::function0<void> v80; // [esp+50h] [ebp-518h] BYREF
  boost::function0<void> v81; // [esp+70h] [ebp-4F8h] BYREF
  boost::function0<void> v82; // [esp+90h] [ebp-4D8h] BYREF
  boost::function0<void> v83; // [esp+B0h] [ebp-4B8h] BYREF
  boost::function0<void> v84; // [esp+D0h] [ebp-498h] BYREF
  boost::function0<void> v85; // [esp+F0h] [ebp-478h] BYREF
  boost::function0<void> v86; // [esp+110h] [ebp-458h] BYREF
  boost::function0<void> v87; // [esp+130h] [ebp-438h] BYREF
  boost::function0<void> v88; // [esp+150h] [ebp-418h] BYREF
  boost::function0<void> v89; // [esp+170h] [ebp-3F8h] BYREF
  boost::function0<void> v90; // [esp+190h] [ebp-3D8h] BYREF
  boost::function0<void> v91; // [esp+1B0h] [ebp-3B8h] BYREF
  boost::function0<void> v92; // [esp+1D0h] [ebp-398h] BYREF
  boost::function0<void> v93; // [esp+1F0h] [ebp-378h] BYREF
  boost::function0<void> v94; // [esp+210h] [ebp-358h] BYREF
  vostok::fs_new::virtual_path_string virtual_path; // [esp+230h] [ebp-338h] BYREF
  vostok::fs_new::native_path_string physical_path; // [esp+344h] [ebp-224h] BYREF
  vostok::fixed_string<256> build_resources_string; // [esp+458h] [ebp-110h] BYREF
  char v98; // [esp+564h] [ebp-4h] BYREF

  *(_DWORD *)&v73[28] = thisa;
  thisa->m_initialized = 1;
  vostok::engine::engine_world::initialize_core(this, *(vostok::engine::engine_world **)&v73[28]);
  vostok::buffer_vector<vostok::apc::callback>::resize(v3);
  vostok::engine::engine_world::initialize_file_system_devices(v4, (int)thisa);
  *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
  *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
  v83.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
    (boost::function0<void> *)PerformanceCount.HighPart,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v83,
    *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
  v5 = g_threads.m_begin + 6;
  if ( v5->m_thread_id == GetCurrentThreadId() )
  {
    boost::function0<void>::operator()(&v83);
  }
  else
  {
    vostok::apc::wait(hdd);
    v6 = g_threads.m_begin + 6;
    boost::function<void __cdecl (void)>::operator=(
      &g_threads.m_begin[6].m_callback,
      (const boost::function<void __cdecl(void)> *)&v83);
    v6->m_break_parameters = break_process_loop;
    _InterlockedExchange(&v6->m_pending, 1);
    vostok::apc::wait(hdd);
  }
  if ( v83.vtable )
  {
    if ( ((int)v83.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v83.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&v83.functor, &v83.functor, 2);
    }
  }
  *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
  *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
  v87.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
    (boost::function0<void> *)PerformanceCount.HighPart,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v87,
    *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
  v8 = g_threads.m_begin + 7;
  if ( v8->m_thread_id == GetCurrentThreadId() )
  {
    boost::function0<void>::operator()(&v87);
  }
  else
  {
    vostok::apc::wait(dvd);
    v10 = g_threads.m_begin + 7;
    boost::function<void __cdecl (void)>::operator=(
      &g_threads.m_begin[7].m_callback,
      (const boost::function<void __cdecl(void)> *)&v87);
    v10->m_break_parameters = break_process_loop;
    _InterlockedExchange(&v10->m_pending, 1);
    vostok::apc::wait(dvd);
  }
  if ( v87.vtable )
  {
    if ( ((int)v87.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v87.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&v87.functor, &v87.functor, 2);
    }
  }
  *(_DWORD *)&v73[28] = thisa;
  vostok::engine::engine_world::initialize_resources(v9);
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    vostok::collision::collision_cook::collision_cook(v12);
    atexit(vostok::collision::initialize_::_2_::_dynamic_atexit_destructor_for__collision_cooker__);
  }
  vostok::resources::resources_manager::register_cook((int)v12, &collision_cooker);
  *(_DWORD *)&v73[28] = thisa;
  vostok::engine::engine_world::initialize_terminate_on_timeout(v13);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v15.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v15 = PerformanceCount;
  }
  thisa->m_timer.m_start_time = v15.QuadPart;
  LODWORD(thisa->m_timer.m_current_time) = 0;
  HIDWORD(thisa->m_timer.m_current_time) = 0;
  vostok::core::run_tests(v14);
  if ( thisa->m_destruction_started )
  {
    thisa->m_early_destruction_started = 1;
  }
  else
  {
    if ( vostok::testing::run_tests_command_line(0) )
    {
      v16 = thisa->get_resources_path(thisa);
      mount_tests_resources(a2, &thisa->m_test_resources_mount, v16);
    }
    v17 = s_engine_0->get_user_data_directory(s_engine_0);
    m_buffer = physical_path.m_string.m_buffer;
    physical_path.m_string.m_begin = physical_path.m_string.m_buffer;
    physical_path.m_string.m_end = physical_path.m_string.m_buffer;
    physical_path.m_string.m_max_end = &physical_path.m_separator;
    physical_path.m_string.m_buffer[0] = 0;
    v19 = (char *)v17;
    if ( v17 )
    {
      if ( *v17 )
      {
        do
        {
          if ( m_buffer >= physical_path.m_string.m_max_end )
            break;
          *m_buffer = *v19;
          m_buffer = physical_path.m_string.m_end + 1;
          ++v19;
          ++physical_path.m_string.m_end;
        }
        while ( *v19 );
      }
      *m_buffer = 0;
    }
    v20 = virtual_path.m_string.m_buffer;
    physical_path.m_separator = 92;
    virtual_path.m_string.m_begin = virtual_path.m_string.m_buffer;
    virtual_path.m_string.m_end = virtual_path.m_string.m_buffer;
    virtual_path.m_string.m_max_end = &virtual_path.m_separator;
    virtual_path.m_string.m_buffer[0] = 0;
    v21 = &stru_954D10.m_string.m_buffer[16];
    do
    {
      if ( v20 >= virtual_path.m_string.m_max_end )
        break;
      *v20 = *v21;
      v20 = virtual_path.m_string.m_end + 1;
      v22 = *++v21 == 0;
      ++virtual_path.m_string.m_end;
    }
    while ( !v22 );
    *v20 = 0;
    v72.l_.a1_.t_ = &thisa->m_user_data_mount;
    virtual_path.m_separator = 47;
    v72.f_ = (void (__cdecl *)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *, vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>))on_mounted_user_data;
    *(_DWORD *)v73 = 0;
    boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list2<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::arg<1>>>>(
      (boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> > *)on_mounted_user_data,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list2<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::arg<1> > > *)v73,
      v72);
    p_m_pending = (vostok::apc::callback *)&vostok::engine::g_allocator;
    vostok::resources::query_mount_physical(
      &vostok::engine::g_allocator,
      &virtual_path,
      &physical_path,
      &stru_954D10.m_string.m_buffer[16],
      watcher_enabled_false,
      *(boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)v73);
    PerformanceCount.HighPart = (int)&thisa->m_resources_mount;
    PerformanceCount.LowPart = (unsigned int)on_mounted_resources;
    *(LARGE_INTEGER *)&v71.f_ = PerformanceCount;
    v71.l_.a2_.t_ = &thisa->m_shader_mask_config;
    boost::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>(
      (boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)&thisa->m_shader_mask_config,
      (int)v73,
      (unsigned int)&vostok::engine::g_allocator,
      v71,
      *(int *)v73);
    vostok::resources::query_mount(
      *(unsigned int *)v73,
      *(boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)&v73[4]);
    build_resources_string.m_begin = build_resources_string.m_buffer;
    build_resources_string.m_max_end = &v98;
    build_resources_string.m_end = build_resources_string.m_buffer;
    build_resources_string.m_buffer[0] = 0;
    if ( vostok::command_line::key::is_set_as_string(
           &s_build_resources,
           (vostok::command_line::key *)&build_resources_string) )
    {
      *(_DWORD *)&v73[28] = build_resources_string.m_begin;
      vostok::engine::engine_world::initialize_build(
        (vostok::engine::engine_world *)build_resources_string.m_begin,
        (const char *const)thisa);
    }
    LOBYTE(is_editor) = thisa->command_line_editor(&thisa->vostok::engine_user::engine);
    if ( (_BYTE)is_editor )
    {
      vostok::engine::engine_world::initialize_editor(v24, thisa);
      PerformanceCount.LowPart = (unsigned int)vostok::engine::engine_world::try_load_editor;
      PerformanceCount.HighPart = 0;
      *(_QWORD *)&v73[16] = (unsigned int)vostok::engine::engine_world::try_load_editor;
      LODWORD(v75) = thisa;
      *(_QWORD *)&v73[24] = v75;
      boost::function0<void>::function0<void>(
        0,
        (int)&v90,
        (int)thisa,
        *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v73[16],
        *(int *)&v73[32]);
      p_m_pending = g_threads.m_begin + 2;
      if ( p_m_pending->m_thread_id == GetCurrentThreadId() )
      {
        boost::function0<void>::operator()(&v90);
      }
      else
      {
        vostok::apc::wait(editor);
        v25 = g_threads.m_begin + 2;
        boost::function<void __cdecl (void)>::operator=(
          &g_threads.m_begin[2].m_callback,
          (const boost::function<void __cdecl(void)> *)&v90);
        v25->m_break_parameters = continue_process_loop;
        p_m_pending = (vostok::apc::callback *)&v25->m_pending;
        _InterlockedExchange((volatile __int32 *)p_m_pending, 1);
      }
      if ( v90.vtable )
      {
        if ( ((int)v90.vtable & 1) == 0 )
        {
          v26 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v90.vtable & 0xFFFFFFFE);
          if ( v26 )
            v26(&v90.functor, &v90.functor, 2);
        }
      }
    }
    vostok::engine::engine_world::initialize_sound(v24, (int)p_m_pending, thisa);
    PerformanceCount.LowPart = (unsigned int)vostok::engine::engine_world::initialize_sound_modules;
    PerformanceCount.HighPart = 0;
    *(_QWORD *)&v73[16] = (unsigned int)vostok::engine::engine_world::initialize_sound_modules;
    LODWORD(v75) = thisa;
    *(_QWORD *)&v73[24] = v75;
    boost::function0<void>::function0<void>(
      0,
      (int)&v92,
      (int)p_m_pending,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v73[16],
      *(int *)&v73[32]);
    v27 = g_threads.m_begin + 4;
    if ( v27->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v92);
    }
    else
    {
      vostok::apc::wait(sound);
      v29 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v92);
      v29->m_break_parameters = continue_process_loop;
      v28 = (vostok::engine::engine_world *)_InterlockedExchange(&v29->m_pending, 1);
    }
    if ( v92.vtable )
    {
      if ( ((int)v92.vtable & 1) == 0 )
      {
        v30 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v92.vtable & 0xFFFFFFFE);
        if ( v30 )
          v30(&v92.functor, &v92.functor, 2);
      }
    }
    *(_DWORD *)&v73[28] = thisa;
    vostok::engine::engine_world::initialize_network(v28);
    PerformanceCount.LowPart = (unsigned int)vostok::engine::engine_world::initialize_network_modules;
    PerformanceCount.HighPart = 0;
    *(_QWORD *)&v73[16] = (unsigned int)vostok::engine::engine_world::initialize_network_modules;
    LODWORD(v75) = thisa;
    *(_QWORD *)&v73[24] = v75;
    boost::function0<void>::function0<void>(
      0,
      (int)&v93,
      (int)GetCurrentThreadId,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v73[16],
      *(int *)&v73[32]);
    v31 = g_threads.m_begin + 3;
    if ( v31->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v93);
    }
    else
    {
      vostok::apc::wait(network);
      v33 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[3].m_callback,
        (const boost::function<void __cdecl(void)> *)&v93);
      v33->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v33->m_pending, 1);
    }
    if ( v93.vtable )
    {
      if ( ((int)v93.vtable & 1) == 0 )
      {
        v34 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v93.vtable & 0xFFFFFFFE);
        if ( v34 )
          v34(&v93.functor, &v93.functor, 2);
      }
    }
    vostok::engine::engine_world::initialize_logic(v32, thisa);
    PerformanceCount.LowPart = (unsigned int)vostok::engine::engine_world::initialize_logic_thread;
    PerformanceCount.HighPart = 0;
    *(_QWORD *)&v73[16] = (unsigned int)vostok::engine::engine_world::initialize_logic_thread;
    LODWORD(v75) = thisa;
    *(_QWORD *)&v73[24] = v75;
    boost::function0<void>::function0<void>(
      0,
      (int)&v94,
      (int)thisa,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v73[16],
      *(int *)&v73[32]);
    v35 = g_threads.m_begin + 1;
    if ( v35->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v94);
    }
    else
    {
      vostok::apc::wait(logic);
      v36 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v94);
      v36->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v36->m_pending, 1);
    }
    if ( v94.vtable )
    {
      if ( ((int)v94.vtable & 1) == 0 )
      {
        v37 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v94.vtable & 0xFFFFFFFE);
        if ( v37 )
          v37(&v94.functor, &v94.functor, 2);
      }
    }
    vostok::apc::wait(sound);
    *(_DWORD *)&v73[28] = thisa->m_sound_world->get_logic_world_user(thisa->m_sound_world);
    *(_DWORD *)&v73[24] = vostok::sound::world_user::initialize;
    v82.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *>>>>(
      (boost::function0<void> *)vostok::sound::world_user::initialize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v82,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v73[24]);
    v38 = g_threads.m_begin + 1;
    if ( v38->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v82);
    }
    else
    {
      vostok::apc::wait(logic);
      v39 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v82);
      v39->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v39->m_pending, 1);
    }
    if ( v82.vtable )
    {
      if ( ((int)v82.vtable & 1) == 0 )
      {
        v40 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v82.vtable & 0xFFFFFFFE);
        if ( v40 )
          v40(&v82.functor, &v82.functor, 2);
      }
    }
    m_network_world = (boost::function0<void> *)thisa->m_network_world;
    *(_DWORD *)&v73[28] = m_network_world;
    *(_DWORD *)&v73[24] =  __thiscall vostok::network::world::`vcall'{0,{flat}};
    v89.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *>>>>(
      m_network_world,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v89,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v73[24]);
    v41 = g_threads.m_begin + 1;
    if ( v41->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v89);
    }
    else
    {
      vostok::apc::wait(logic);
      v43 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v89);
      v43->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v43->m_pending, 1);
    }
    if ( v89.vtable )
    {
      if ( ((int)v89.vtable & 1) == 0 )
      {
        v44 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v89.vtable & 0xFFFFFFFE);
        if ( v44 )
          v44(&v89.functor, &v89.functor, 2);
      }
    }
    while ( 1 )
    {
      if ( vostok::resources::g_resources_manager.m_initialized )
      {
        if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
        {
          predicate[0] = 0;
          *(_DWORD *)&v73[28] = *(_DWORD *)predicate;
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
          vostok::resources::tick(v42);
        vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
      }
      if ( thisa->m_shader_mask_config.m_object )
        break;
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_locks(v45, s_thread_pool.m_variable);
      Sleep(1u);
      if ( s_thread_pool.m_initialized )
      {
        if ( TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_unlocks(
            (vostok::tasks::thread_pool *)v42,
            s_thread_pool.m_variable);
      }
    }
    vostok::engine::engine_world::initialize_render(
      is_editor,
      (int)thisa,
      (vostok::engine::engine_world *)&thisa->m_shader_mask_config,
      (bool)is_editor);
    PerformanceCount.LowPart = (unsigned int)vostok::engine::engine_world::initialize_logic_modules;
    PerformanceCount.HighPart = 0;
    *(_QWORD *)&v73[16] = (unsigned int)vostok::engine::engine_world::initialize_logic_modules;
    LODWORD(v75) = thisa;
    *(_QWORD *)&v73[24] = v75;
    boost::function0<void>::function0<void>(
      0,
      (int)&v91,
      (int)TlsGetValue,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v73[16],
      *(int *)&v73[32]);
    v46 = g_threads.m_begin + 1;
    if ( v46->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v91);
    }
    else
    {
      vostok::apc::wait(logic);
      v47 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v91);
      v47->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v47->m_pending, 1);
    }
    if ( v91.vtable )
    {
      if ( ((int)v91.vtable & 1) == 0 )
      {
        v48 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v91.vtable & 0xFFFFFFFE);
        if ( v48 )
          v48(&v91.functor, &v91.functor, 2);
      }
    }
    if ( (_BYTE)is_editor )
    {
      *(_DWORD *)&v73[28] = &thisa->m_render_world->m_editor_channel;
      *(_DWORD *)&v73[24] = vostok::render::one_way_render_channel::owner_initialize;
      v84.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *>>>>(
        (boost::function0<void> *)vostok::render::one_way_render_channel::owner_initialize,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v84,
        *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v73[24]);
      v49 = g_threads.m_begin + 2;
      if ( v49->m_thread_id == GetCurrentThreadId() )
      {
        boost::function0<void>::operator()(&v84);
      }
      else
      {
        vostok::apc::wait(editor);
        v50 = g_threads.m_begin + 2;
        boost::function<void __cdecl (void)>::operator=(
          &g_threads.m_begin[2].m_callback,
          (const boost::function<void __cdecl(void)> *)&v84);
        v50->m_break_parameters = continue_process_loop;
        _InterlockedExchange(&v50->m_pending, 1);
      }
      if ( v84.vtable )
      {
        if ( ((int)v84.vtable & 1) == 0 )
        {
          v51 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v84.vtable & 0xFFFFFFFE);
          if ( v51 )
            v51(&v84.functor, &v84.functor, 2);
        }
      }
    }
    *(_DWORD *)&v73[28] = thisa->m_render_world;
    *(_DWORD *)&v73[24] = vostok::render::one_way_render_channel::owner_initialize;
    v88.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *>>>>(
      (boost::function0<void> *)vostok::render::one_way_render_channel::owner_initialize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v88,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v73[24]);
    v52 = g_threads.m_begin + 1;
    if ( v52->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v88);
    }
    else
    {
      vostok::apc::wait(logic);
      v53 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v88);
      v53->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v53->m_pending, 1);
    }
    if ( v88.vtable )
    {
      if ( ((int)v88.vtable & 1) == 0 )
      {
        v54 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v88.vtable & 0xFFFFFFFE);
        if ( v54 )
          v54(&v88.functor, &v88.functor, 2);
      }
    }
    vostok::render::engine::world::initialize(
      (vostok::render::engine::world *)thisa->m_render_world->m_engine_renderer,
      thisa->m_render_world->m_engine_renderer->m_render_engine_world);
    *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
    *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
    v86.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      (boost::function0<void> *)PerformanceCount.HighPart,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v86,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
    v55 = g_threads.m_begin + 5;
    if ( v55->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v86);
    }
    else
    {
      vostok::apc::wait(build);
      v56 = g_threads.m_begin + 5;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[5].m_callback,
        (const boost::function<void __cdecl(void)> *)&v86);
      v56->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v56->m_pending, 1);
    }
    if ( v86.vtable )
    {
      if ( ((int)v86.vtable & 1) == 0 )
      {
        v57 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v86.vtable & 0xFFFFFFFE);
        if ( v57 )
          v57(&v86.functor, &v86.functor, 2);
      }
    }
    *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
    *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
    v79.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      (boost::function0<void> *)PerformanceCount.HighPart,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v79,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
    v58 = g_threads.m_begin + 3;
    if ( v58->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v79);
    }
    else
    {
      vostok::apc::wait(network);
      v59 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[3].m_callback,
        (const boost::function<void __cdecl(void)> *)&v79);
      v59->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v59->m_pending, 1);
    }
    if ( v79.vtable )
    {
      if ( ((int)v79.vtable & 1) == 0 )
      {
        v60 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v79.vtable & 0xFFFFFFFE);
        if ( v60 )
          v60(&v79.functor, &v79.functor, 2);
      }
    }
    *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
    *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
    v85.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      (boost::function0<void> *)PerformanceCount.HighPart,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v85,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
    v61 = g_threads.m_begin + 4;
    if ( v61->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v85);
    }
    else
    {
      vostok::apc::wait(sound);
      v62 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v85);
      v62->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v62->m_pending, 1);
    }
    if ( v85.vtable )
    {
      if ( ((int)v85.vtable & 1) == 0 )
      {
        v63 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v85.vtable & 0xFFFFFFFE);
        if ( v63 )
          v63(&v85.functor, &v85.functor, 2);
      }
    }
    *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
    *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
    v80.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      (boost::function0<void> *)PerformanceCount.HighPart,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v80,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
    v64 = g_threads.m_begin + 1;
    if ( v64->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v80);
    }
    else
    {
      vostok::apc::wait(logic);
      v66 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v80);
      v66->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v66->m_pending, 1);
    }
    if ( v80.vtable )
    {
      if ( ((int)v80.vtable & 1) == 0 )
      {
        v67 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v80.vtable & 0xFFFFFFFE);
        if ( v67 )
          v67(&v80.functor, &v80.functor, 2);
      }
    }
    if ( (_BYTE)is_editor )
    {
      *(_DWORD *)&v73[28] = PerformanceCount.HighPart;
      *(_DWORD *)&v73[24] = survarium::weapon_user_dead_state::finalize;
      v81.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
        (boost::function0<void> *)PerformanceCount.HighPart,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v81,
        *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v73[24]);
      v68 = g_threads.m_begin + 2;
      if ( v68->m_thread_id == GetCurrentThreadId() )
      {
        boost::function0<void>::operator()(&v81);
      }
      else
      {
        vostok::apc::wait(editor);
        v69 = g_threads.m_begin + 2;
        boost::function<void __cdecl (void)>::operator=(
          &g_threads.m_begin[2].m_callback,
          (const boost::function<void __cdecl(void)> *)&v81);
        v69->m_break_parameters = break_process_loop;
        _InterlockedExchange(&v69->m_pending, 1);
      }
      if ( v81.vtable )
      {
        if ( ((int)v81.vtable & 1) == 0 )
        {
          v70 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v81.vtable & 0xFFFFFFFE);
          if ( v70 )
            v70(&v81.functor, &v81.functor, 2);
        }
      }
    }
    else
    {
      vostok::engine::engine_world::show_window(v65, (int)thisa);
    }
    if ( thisa->m_editor || vostok::command_line::key::is_set(&s_build_resources) )
      thisa->enable_game(&thisa->vostok::editor::engine, 0);
    vostok::testing::suite_base<vostok::engine_test_suite>::run_tests();
  }
}
