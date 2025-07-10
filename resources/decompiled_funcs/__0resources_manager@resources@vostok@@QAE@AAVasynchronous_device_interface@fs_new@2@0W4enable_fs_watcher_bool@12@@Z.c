void __userpurge vostok::resources::resources_manager::resources_manager(
        vostok::resources::resources_manager *this@<ecx>,
        unsigned int a2@<esi>,
        vostok::fs_new::asynchronous_device_interface *hdd,
        vostok::fs_new::asynchronous_device_interface *dvd,
        vostok::resources::enable_fs_watcher_bool enable_fs_watcher)
{
  _DWORD *v5; // eax
  _DWORD *v6; // ebp
  vostok::ppmd_compressor *v7; // ecx
  vostok::resources::hdd_manager *v8; // ecx
  void **v9; // eax
  boost::function<void __cdecl(vostok::vfs::base_node<1> *)> *m_variable; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *v11; // edi
  LARGE_INTEGER v12; // rax
  vostok::resources::resources_manager *v13; // ecx
  int v14; // ecx
  vostok::resources::unknown_data_class_cook *v15; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,vostok::vfs::base_node<1> *>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::arg<1> > > v16; // [esp-Ch] [ebp-30h]
  const stlp_std::__true_type *v17; // [esp+0h] [ebp-24h]
  unsigned int v18; // [esp+4h] [ebp-20h]
  bool v19; // [esp+8h] [ebp-1Ch]
  void *__x; // [esp+14h] [ebp-10h] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+18h] [ebp-Ch]
  LARGE_INTEGER PerformanceCount; // [esp+1Ch] [ebp-8h] BYREF

  *(_DWORD *)(a2 + 16) = a2 + 28;
  *(_DWORD *)(a2 + 20) = a2 + 28;
  *(_DWORD *)(a2 + 24) = a2 + 288;
  *(_BYTE *)(a2 + 28) = 0;
  *(_BYTE *)(a2 + 288) = 92;
  *(_DWORD *)(a2 + 296) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 304), 0x2710u);
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)((char *)&loc_20160 + a2) = 0;
  memset(a2 + 352, 0, (unsigned int)&loc_20000);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&byte_20168[a2], 0x2710u);
  *(_DWORD *)((char *)&loc_2017F + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20186 + a2 + 2), 0x2710u);
  *(_DWORD *)((char *)&loc_201A2 + a2 + 2) = 0;
  *(int *)((char *)&dword_201A8 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_201BF + a2 + 1), 0x2710u);
  *(_DWORD *)((char *)&loc_201DA + a2 + 2) = 0;
  *(_DWORD *)((char *)&loc_201E0 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&byte_201E8[a2], 0x2710u);
  *(_DWORD *)((char *)&loc_201FF + a2 + 1) = 0;
  *(_DWORD *)((char *)&loc_20204 + a2) = 0;
  *(_DWORD *)((char *)&loc_20206 + a2 + 2) = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)((char *)nullsub_153 + a2));
  *(_DWORD *)((char *)&loc_20227 + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20230 + a2), 0x2710u);
  *(_DWORD *)((char *)&loc_2024B + a2 + 1) = 0;
  *(_DWORD *)((char *)&loc_2024D + a2 + 3) = 0;
  *(_DWORD *)((char *)&loc_20257 + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20260 + a2), 0x2710u);
  *(_DWORD *)((char *)&loc_2027C + a2) = 0;
  *(_DWORD *)((char *)&loc_2027E + a2 + 2) = 0;
  *(_DWORD *)((char *)&loc_20288 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20290 + a2), 0x2710u);
  *(_DWORD *)((char *)&loc_202AC + a2) = 0;
  *(_DWORD *)((char *)&loc_202AF + a2 + 1) = 0;
  *(_DWORD *)((char *)&loc_202B8 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_202C0 + a2), 0x2710u);
  *(_DWORD *)((char *)&loc_202D9 + a2 + 3) = 0;
  *(_DWORD *)((char *)&loc_202DE + a2 + 2) = 0;
  *(_DWORD *)((char *)&loc_202E7 + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_202EF + a2 + 1), 0x2710u);
  *(_DWORD *)((char *)&loc_2030B + a2 + 1) = 0;
  *(_DWORD *)((char *)&loc_20310 + a2) = 0;
  *(int *)((char *)&dword_20318 + a2) = 0;
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *>>>>::manage_small
                       + a2),
    0x2710u);
  *(_DWORD *)((char *)&loc_2033C + a2) = 0;
  *(_DWORD *)((char *)&loc_2033E + a2 + 2) = 0;
  *(_DWORD *)((char *)&loc_20345 + a2 + 3) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_2034F + a2 + 1), 0x2710u);
  *(_DWORD *)((char *)&loc_2036C + a2) = 0;
  *(_DWORD *)((char *)&loc_20370 + a2) = 0;
  *(int *)((char *)dword_20380 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)dword_20388 + a2), 0x2710u);
  *(int *)((char *)&dword_203A4 + a2) = 0;
  *(int *)((char *)&dword_203A8 + a2) = 0;
  vostok::threading::reader_writer_lock::reader_writer_lock((vostok::threading::reader_writer_lock *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>>::manage_small + a2));
  v5 = (int *)((char *)&dword_203B8 + a2);
  *v5 = 0;
  v5[1] = v5;
  v5[2] = v5;
  v5[3] = 0;
  *(int *)((char *)&dword_203D0 + a2) = (int)CreateEventA(0, 0, 0, 0);
  *(int *)((char *)&dword_203E0 + a2) = (int)CreateEventA(0, 0, 0, 0);
  *(int *)((char *)&dword_203E8 + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)nullsub_154 + a2), 0x2710u);
  *(int *)((char *)&dword_2040C + a2) = 0;
  *(_UNKNOWN **)((char *)&off_20410 + a2) = 0;
  *(_DWORD *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *>>>>::manage_small
            + a2) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20426 + a2 + 2), 0x2710u);
  *(_DWORD *)((char *)&loc_20444 + a2) = 0;
  *(_DWORD *)((char *)&loc_20448 + a2) = 0;
  *(_DWORD *)((char *)&loc_2044D + a2 + 3) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20456 + a2 + 2), 0x2710u);
  *(_DWORD *)((char *)&loc_20471 + a2 + 3) = 0;
  *(_DWORD *)((char *)&loc_20478 + a2) = 0;
  *(_DWORD *)((char *)&loc_2047F + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20486 + a2 + 2), 0x2710u);
  *(_DWORD *)((char *)&loc_204A4 + a2) = 0;
  *(_DWORD *)((char *)&loc_204A8 + a2) = 0;
  *(_DWORD *)((char *)&loc_204AD + a2 + 3) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_204B7 + a2 + 1), 0x2710u);
  *(_DWORD *)((char *)&loc_204D3 + a2 + 1) = 0;
  *(_DWORD *)((char *)&loc_204D5 + a2 + 3) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_204DD + a2 + 3), 0x2710u);
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,long volatile *>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<long volatile *>>>>::manage_small
                       + a2),
    0x2710u);
  *(_DWORD *)((char *)&loc_20517 + a2 + 1) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_2051C + a2 + 4), 0x2710u);
  *(_DWORD *)((char *)&loc_2053C + a2) = 0;
  *(_DWORD *)((char *)&loc_2053E + a2 + 2) = 0;
  *(_DWORD *)((char *)&loc_20546 + a2 + 2) = 0;
  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<bool>>>>::manage_small
                       + a2),
    0x2710u);
  *(_DWORD *)((char *)&loc_2056C + a2) = 0;
  *(_DWORD *)((char *)&loc_2056C + a2 + 4) = 0;
  v6 = (_DWORD *)((char *)&loc_20578 + a2);
  v6[4] = v6;
  v6[5] = 0;
  v6[6] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((char *)&loc_20596 + a2 + 2), 0x2710u);
  *(int *)((char *)&dword_205B0 + a2) = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)((char *)stlp_std::priv::__unguarded_partition<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>
                                                       + a2));
  vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
    (vostok::fs_new::synchronous_device_interface *)((char *)&loc_205EB + a2 + 1),
    hdd->m_device);
  *(_DWORD *)((char *)&loc_205F8 + a2) = hdd;
  *(_DWORD *)((char *)&loc_205FB + a2 + 1) = dvd;
  vostok::vfs::virtual_file_system::virtual_file_system((vostok::vfs::virtual_file_system *)((char *)&loc_20600 + a2));
  *(_DWORD *)(a2 + 264168) = 0;
  *(_DWORD *)(a2 + 264172) = 0;
  if ( (_UNKNOWN *)((char *)&loc_20578 + a2) )
    vostok::ppmd_compressor::ppmd_compressor(v7, (char *)&loc_20578 + a2);
  _InterlockedExchange((volatile __int32 *)((char *)&loc_2058C + a2), 1);
  *(int *)((char *)&dword_203C8 + a2) = TlsAlloc();
  *(int *)((char *)&dword_204F8 + a2) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)((char *)&loc_201B0 + a2) = 0;
  *(_DWORD *)((char *)&loc_201B0 + a2 + 4) = 0;
  *(_UNKNOWN **)((char *)&off_20378 + a2) = 0;
  vostok::resources::hdd_manager::hdd_manager(v8, (int)&vostok::resources::s_hdd_device);
  _InterlockedExchange(&vostok::resources::s_hdd_device.m_initialized, 1);
  v9 = *(void ***)((char *)&loc_20204 + a2);
  m_variable = (boost::function<void __cdecl(vostok::vfs::base_node<1> *)> *)vostok::resources::s_hdd_device.m_variable;
  v11 = (stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *)((char *)&loc_201FF + a2 + 1);
  __x = vostok::resources::s_hdd_device.m_variable;
  if ( v9 == *(void ***)((char *)&loc_201FF + a2 + 9) )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *>>::_M_insert_overflow(
      v11,
      v9,
      (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)vostok::resources::s_hdd_device.m_variable,
      &__x,
      v17,
      v18,
      v19);
  }
  else
  {
    *v9 = vostok::resources::s_hdd_device.m_variable;
    ++v11->_M_finish;
  }
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(int *)((char *)&dword_201B8 + a2) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)((char *)&loc_20415 + a2 + 3) = 0;
  *((_BYTE *)&loc_205E8 + a2) = 0;
  *(int *)((char *)&dword_203CC + a2) = 0;
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v12.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v12 = PerformanceCount;
  }
  *(_DWORD *)((char *)&loc_20218 + a2) = v12.LowPart;
  *(_DWORD *)((char *)&loc_20218 + a2 + 4) = v12.HighPart;
  *(_DWORD *)((char *)nullsub_153 + a2) = 0;
  *(_DWORD *)((char *)&loc_20214 + a2) = 0;
  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    predicate[0] = 0;
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
  {
    *(int *)((char *)&dword_203CC + a2) = GetCurrentThreadId();
    *(_DWORD *)&byte_203D8[a2] = GetCurrentThreadId();
  }
  v16.l_.a1_.t_ = (vostok::resources::resources_manager *)vostok::resources::resources_manager::on_mounted;
  v16.f_.f_ = (void (__thiscall *)(vostok::resources::resources_manager *, vostok::vfs::base_node<1> *))&byte_407C8[a2];
  boost::function<void __cdecl (vostok::vfs::base_node<1> *)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,vostok::vfs::base_node<1> *>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::arg<1>>>>(
    m_variable,
    v16,
    a2);
  vostok::resources::resources_manager::get_binary_config_cook(v13);
  vostok::resources::resources_manager::register_cook(v14, &s_sub_fat_cook);
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    vostok::resources::unknown_data_class_cook::unknown_data_class_cook(v15);
    atexit(vostok::resources::resources_manager::register_cooks_::_2_::_dynamic_atexit_destructor_for__unknown_data_cook__);
  }
  vostok::resources::resources_manager::register_cook((int)v15, &unknown_data_cook);
}
