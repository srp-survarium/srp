void __thiscall vostok::engine::engine_world::initialize(
        vostok::engine::engine_world *this,
        boost::function<void __cdecl(void)> *on_before_render_window_shown,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *__formal)
{
  boost::function<void __cdecl(void)> *v3; // ebx
  vostok::buffer_vector<vostok::apc::callback> *v4; // ecx
  vostok::fs_new::asynchronous_device_interface *v5; // ecx
  vostok::command_line::key *v6; // ecx
  boost::function<void __cdecl(char const *)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function<void __cdecl(char const *)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::engine::engine_world *v11; // ecx
  char *m_begin; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v13; // ecx
  vostok::timing::timer *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::core_test_suite *v16; // eax
  vostok::core_test_suite *v17; // esi
  vostok::intrusive_list<vostok::testing::test_base,vostok::testing::test_base *,4,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v18; // ecx
  vostok::testing::test_base *v19; // eax
  vostok::command_line::key *v20; // ecx
  char *v21; // eax
  char *v22; // eax
  vostok::fixed_string<260> *v23; // ecx
  vostok::fixed_string<260> *v24; // ecx
  vostok::engine::engine_world *v25; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v27; // ecx
  vostok::engine::engine_world *v28; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v29; // ecx
  vostok::engine::engine_world *v30; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v31; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  boost::function<void __cdecl(void)> *v33; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v34; // ecx
  vostok::command_line::key *v35; // ecx
  vostok::tasks *v36; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v37; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v38; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v39; // ecx
  boost::function<void __cdecl(char const *)> *v40; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v41; // ecx
  boost::function<void __cdecl(char const *)> *v42; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v43; // ecx
  boost::function<void __cdecl(char const *)> *v44; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v45; // ecx
  boost::function<void __cdecl(char const *)> *v46; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v47; // ecx
  boost::function<void __cdecl(char const *)> *v48; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v49; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list3<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *>,boost::arg<1> > > v50; // [esp-30h] [ebp-4B0h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list2<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::arg<1> > > v51; // [esp-28h] [ebp-4A8h]
  vostok::resources::fs_task_mount v52; // [esp-20h] [ebp-4A0h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+3D8h] [ebp-A8h] BYREF
  boost::function<void __cdecl(void)> v54; // [esp+3F8h] [ebp-88h] BYREF
  boost::function<void __cdecl(void)> v55; // [esp+418h] [ebp-68h] BYREF
  boost::function<void __cdecl(void)> v56; // [esp+438h] [ebp-48h] BYREF
  char *s; // [esp+45Ch] [ebp-24h] BYREF
  void (__thiscall *v58)(vostok::engine::engine_world *); // [esp+460h] [ebp-20h]
  int v59; // [esp+464h] [ebp-1Ch]
  boost::function<void __cdecl(void)> *v60; // [esp+468h] [ebp-18h]
  int v61; // [esp+46Ch] [ebp-14h]
  void (__thiscall *v62)(vostok::engine::engine_world *); // [esp+470h] [ebp-10h]
  void (__cdecl *v63)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *, vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>); // [esp+474h] [ebp-Ch]
  boost::function<void __cdecl(void)> *v64; // [esp+478h] [ebp-8h]
  boost::detail::function::function_buffer *p_functor; // [esp+47Ch] [ebp-4h]

  v3 = on_before_render_window_shown;
  *(&on_before_render_window_shown[23].functor.data + 9) = 1;
  vostok::engine::engine_world::initialize_core(this, on_before_render_window_shown);
  vostok::buffer_vector<vostok::apc::callback>::resize(v4);
  if ( on_before_render_window_shown != (boost::function<void __cdecl(void)> *)-32 )
    vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
      v5,
      &on_before_render_window_shown[1].vtable,
      (vostok::fs_new::device_file_system_interface *)&on_before_render_window_shown->functor.data + 2,
      (vostok::fs_new::watcher_enabled_bool)v52.m_virtual_path.m_string.m_end);
  _InterlockedExchange(
    (volatile __int32 *)&on_before_render_window_shown[7].functor.vostok_pointer_size_alignment[1],
    1);
  if ( on_before_render_window_shown != (boost::function<void __cdecl(void)> *)-248 )
    vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
      (vostok::fs_new::asynchronous_device_interface *)((char *)&on_before_render_window_shown[7].functor.bound_memfunc_ptr.memfunc_ptr
                                                      + 4),
      &on_before_render_window_shown[7].functor.bound_memfunc_ptr.obj_ptr,
      (vostok::fs_new::device_file_system_interface *)&on_before_render_window_shown->functor.data + 4,
      (vostok::fs_new::watcher_enabled_bool)v52.m_virtual_path.m_string.m_end);
  _InterlockedExchange((volatile __int32 *)&(&on_before_render_window_shown[14].vtable)[1], 1);
  vostok::engine::engine_world::initialize_file_system_device(
    6u,
    (vostok::command_line::key *)&(&on_before_render_window_shown[14].vtable)[1],
    (vostok::engine::engine_world *)on_before_render_window_shown,
    (vostok::fs_new::asynchronous_device_interface *)on_before_render_window_shown[7].functor.obj_ptr,
    "hdd");
  vostok::engine::engine_world::initialize_file_system_device(
    7u,
    v6,
    (vostok::engine::engine_world *)on_before_render_window_shown,
    (vostok::fs_new::asynchronous_device_interface *)on_before_render_window_shown[14].vtable,
    "dvd");
  v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
  v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
  boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
    v7,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_string.m_buffer[100],
    *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
    (int)v52.m_virtual_path.m_string.m_end);
  run(
    hdd,
    (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[100],
    break_process_loop,
    wait_for_completion,
    0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v52.m_archive_physical_path.m_string.m_buffer[100]);
  v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
  v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
  boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
    v9,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_string.m_buffer[4],
    *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
    (int)v52.m_virtual_path.m_string.m_end);
  run(
    dvd,
    (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[4],
    break_process_loop,
    wait_for_completion,
    0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v52.m_archive_physical_path.m_string.m_buffer[4]);
  vostok::engine::engine_world::initialize_resources(v11, (vostok::apc::threads_enum)on_before_render_window_shown);
  if ( (_S5_11 & 1) == 0 )
  {
    _S5_11 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x1B,
      &stru_47ECA08,
      reuse_true,
      0xFFFFFFFC,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v52.m_virtual_path.m_string.m_end);
    stru_47ECA08.__vftable = (vostok::resources::cook_base_vtbl *)&vostok::collision::collision_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&stru_47ECA08, v13);
    atexit((int (__cdecl *)())vostok::collision::initialize_collision_cook_::_2_::_dynamic_atexit_destructor_for__s_collision_cook__);
    m_begin = v52.m_virtual_path.m_string.m_begin;
  }
  vostok::engine::engine_world::initialize_terminate_on_timeout(
    (vostok::engine::engine_world *)m_begin,
    on_before_render_window_shown);
  vostok::timing::timer::start(v14, (LARGE_INTEGER *)&on_before_render_window_shown[23].functor.data + 2);
  vostok::testing::initialize(v15);
  s = (char *)s_engine_0->get_resources_path(s_engine_0);
  v16 = vostok::testing::suite_base<vostok::core_test_suite>::singleton(0);
  vostok::fs_new::path_string_impl::assign_with_conversion<char const *>(&v16->m_resources_path, (const char **)&s);
  v52.m_virtual_path.m_string.m_begin = (char *)type_info::name(
                                                  &vostok::core_test_suite `RTTI Type Descriptor',
                                                  &__type_info_root_node);
  v17 = vostok::testing::suite_base<vostok::core_test_suite>::singleton(0);
  v19 = vostok::intrusive_list<vostok::testing::test_base,vostok::testing::test_base *,4,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
          v18,
          (int)v17);
  vostok::testing::detail::run_tests_impl(v19, v20, v52.m_virtual_path.m_string.m_begin);
  if ( on_before_render_window_shown[22].functor.vostok_pointer_size_alignment[5] )
  {
    *(&on_before_render_window_shown[23].functor.data + 8) = 1;
  }
  else
  {
    if ( vostok::testing::run_tests_command_line((vostok::command_line::key *)v52.m_virtual_path.m_string.m_begin) )
    {
      v21 = (char *)((int (__thiscall *)(boost::function<void __cdecl(void)> *))on_before_render_window_shown->vtable[18].manager)(on_before_render_window_shown);
      mount_tests_resources(
        (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)&(&on_before_render_window_shown[22].vtable)[1],
        v21);
    }
    v22 = (char *)s_engine_0->get_user_data_directory(s_engine_0);
    vostok::fixed_string<260>::fixed_string<260>(
      v23,
      (vostok::buffer_string *)&v52.m_physical_path.m_string.m_buffer[8],
      v22);
    v52.m_archive_physical_path.m_string.m_buffer[0] = 92;
    vostok::fixed_string<260>::fixed_string<260>(
      v24,
      (vostok::buffer_string *)&v52.m_virtual_path.m_string.m_buffer[8],
      &stru_7F94B0.m_string.m_buffer[16]);
    v51.l_.a1_.t_ = (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)&on_before_render_window_shown[22];
    v51.f_ = _LN32;
    v52.m_physical_path.m_string.m_buffer[4] = 47;
    boost::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>(
      (boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)_LN32,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>),boost::_bi::list2<boost::_bi::value<vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *>,boost::arg<1> > > *)&v52,
      v51,
      (int)v52.__vftable);
    vostok::resources::query_mount_physical(
      &vostok::engine::g_allocator,
      (const vostok::fs_new::virtual_path_string *)&v52.m_virtual_path.m_string.m_buffer[8],
      (const vostok::fs_new::native_path_string *)&v52.m_physical_path.m_string.m_buffer[8],
      &stru_7F94B0.m_string.m_buffer[16],
      watcher_enabled_false,
      v52);
    v64 = (boost::function<void __cdecl(void)> *)((char *)on_before_render_window_shown + 700);
    p_functor = &on_before_render_window_shown[21].functor;
    v63 = on_mounted_resources;
    v50.l_.a1_.t_ = (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)on_mounted_resources;
    v50.l_.a2_.t_ = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)(&on_before_render_window_shown[21].functor.data + 20);
    v50.f_ = (void (__cdecl *)(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *, vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>))&v52;
    boost::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>::function<void __cdecl (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)>(
      (boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *)&on_before_render_window_shown[21].functor,
      v50,
      (int)&on_before_render_window_shown[21].functor);
    vostok::resources::query_mount((const char *)v52.__vftable);
    LOBYTE(on_before_render_window_shown) = ((int (__thiscall *)(boost::detail::function::vtable_base **))(&on_before_render_window_shown->vtable)[1][3].manager)(&(&on_before_render_window_shown->vtable)[1]);
    if ( (_BYTE)on_before_render_window_shown )
    {
      vostok::engine::engine_world::initialize_editor(v25, v3);
      v62 = vostok::engine::engine_world::try_load_editor;
      v63 = 0;
      v64 = v3;
      v52.m_allocator = (vostok::memory::base_allocator *)vostok::engine::engine_world::try_load_editor;
      v52.m_thread_id = 0;
      v52.m_parent_query = (vostok::resources::query_result_for_cook *)v3;
      v52.m_type = (vostok::resources::fs_task::type_enum)&f;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        0,
        *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v52.m_type,
        (int)p_functor);
      run(editor, &f, continue_process_loop, dont_wait_for_completion, 0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v26,
        (int *)&f);
    }
    vostok::engine::engine_world::initialize_sound(v25, v3);
    v58 = vostok::engine::engine_world::initialize_sound_modules;
    v59 = 0;
    v60 = v3;
    v52.m_allocator = (vostok::memory::base_allocator *)vostok::engine::engine_world::initialize_sound_modules;
    v52.m_thread_id = 0;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)v3;
    v52.m_type = (vostok::resources::fs_task::type_enum)&v52.m_archive_physical_path.m_string.m_buffer[164];
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v52.m_type,
      v61);
    run(
      sound,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[164],
      continue_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v27,
      (int *)&v52.m_archive_physical_path.m_string.m_buffer[164]);
    vostok::engine::engine_world::initialize_network(v28, v3);
    v58 = vostok::engine::engine_world::initialize_network_modules;
    v59 = 0;
    v60 = v3;
    v52.m_allocator = (vostok::memory::base_allocator *)vostok::engine::engine_world::initialize_network_modules;
    v52.m_thread_id = 0;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)v3;
    v52.m_type = (vostok::resources::fs_task::type_enum)&v52.m_mount_callback.functor;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v52.m_type,
      v61);
    run(
      network,
      (boost::function<void __cdecl(void)> *)&v52.m_mount_callback.functor,
      continue_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v29,
      (int *)&v52.m_mount_callback.functor);
    vostok::engine::engine_world::initialize_logic(v30, v3);
    v58 = vostok::engine::engine_world::initialize_logic_thread;
    v59 = 0;
    v60 = v3;
    v52.m_allocator = (vostok::memory::base_allocator *)vostok::engine::engine_world::initialize_logic_thread;
    v52.m_thread_id = 0;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)v3;
    v52.m_type = (vostok::resources::fs_task::type_enum)&v52.m_archive_physical_path.m_string.m_buffer[36];
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v52.m_type,
      v61);
    run(
      logic,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[36],
      continue_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v31,
      (int *)&v52.m_archive_physical_path.m_string.m_buffer[36]);
    *(_DWORD *)&v52.m_descriptor.m_buffer[16] = 0;
    vostok::apc::wait(sound, (const boost::function<void __cdecl(void)> *)&v52.m_descriptor.m_buffer[16]);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v52.m_virtual_path.m_string.m_begin,
      (int *)&v52.m_descriptor.m_buffer[16]);
    v52.m_virtual_path.m_string.m_begin = (char *)(*(int (__thiscall **)(void *))(*(_DWORD *)v3[21].functor.vostok_pointer_size_alignment[2]
                                                                                + 8))(v3[21].functor.vostok_pointer_size_alignment[2]);
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::sound::world_user::initialize;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::sound::world_user::initialize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v56,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(logic, &v56, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v32,
      (int *)&v56);
    p_functor = (boost::detail::function::function_buffer *)v3[21].functor.vostok_pointer_size_alignment[1];
    v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *) __thiscall vostok::network::world::`vcall'{0,{flat}};
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v33,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v52.m_archive_physical_path.m_string.m_buffer[228],
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      logic,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[228],
      continue_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v34,
      (int *)&v52.m_archive_physical_path.m_string.m_buffer[228]);
    while ( 1 )
    {
      vostok::resources::dispatch_callbacks(v35);
      if ( v3[21].functor.obj_ptr )
        break;
      vostok::threading::yield(1u, v36);
    }
    vostok::engine::engine_world::initialize_render(
      (vostok::engine::engine_world *)v36,
      (unsigned int)v3,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v3[21].functor,
      s_video_memory_we_may_use,
      on_before_render_window_shown,
      __formal);
    v58 = vostok::engine::engine_world::initialize_logic_modules;
    v59 = 0;
    v60 = v3;
    v52.m_allocator = (vostok::memory::base_allocator *)vostok::engine::engine_world::initialize_logic_modules;
    v52.m_thread_id = 0;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)v3;
    v52.m_type = (vostok::resources::fs_task::type_enum)&v55;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > *)&v52.m_type,
      v61);
    run(logic, &v55, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v37,
      (int *)&v55);
    if ( (_BYTE)on_before_render_window_shown )
    {
      v52.m_virtual_path.m_string.m_begin = (char *)&v3[21].vtable[44];
      v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::render::one_way_render_channel::owner_initialize;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)vostok::render::one_way_render_channel::owner_initialize,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v54,
        *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v52.m_parent_query,
        (int)v52.m_virtual_path.m_string.m_end);
      run(editor, &v54, continue_process_loop, dont_wait_for_completion, 0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v38,
        (int *)&v54);
    }
    v52.m_virtual_path.m_string.m_begin = (char *)v3[21].vtable;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::render::one_way_render_channel::owner_initialize;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::render::one_way_render_channel::owner_initialize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v52.m_mount_ptr,
      *(boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      logic,
      (boost::function<void __cdecl(void)> *)&v52.m_mount_ptr,
      continue_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v39,
      (int *)&v52.m_mount_ptr);
    v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v40,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_callback.functor.data + 1,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      build,
      (boost::function<void __cdecl(void)> *)(&v52.m_callback.functor.data + 8),
      break_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v41,
      (int *)&v52.m_callback.functor.vostok_pointer_size_alignment[2]);
    v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v42,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_separator,
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      network,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_separator,
      break_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v43,
      (int *)&v52.m_archive_physical_path.m_separator);
    v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v44,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_string.m_buffer[196],
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      sound,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[196],
      break_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v45,
      (int *)&v52.m_archive_physical_path.m_string.m_buffer[196]);
    v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
    v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v46,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_string.m_buffer[132],
      *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
      (int)v52.m_virtual_path.m_string.m_end);
    run(
      logic,
      (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[132],
      break_process_loop,
      dont_wait_for_completion,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v47,
      (int *)&v52.m_archive_physical_path.m_string.m_buffer[132]);
    if ( (_BYTE)on_before_render_window_shown )
    {
      v52.m_virtual_path.m_string.m_begin = (char *)p_functor;
      v52.m_parent_query = (vostok::resources::query_result_for_cook *)vostok::memory::process_allocator::finalize_impl;
      boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        v48,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_archive_physical_path.m_string.m_buffer[68],
        *(boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v52.m_parent_query,
        (int)v52.m_virtual_path.m_string.m_end);
      run(
        editor,
        (boost::function<void __cdecl(void)> *)&v52.m_archive_physical_path.m_string.m_buffer[68],
        break_process_loop,
        wait_for_completion,
        0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v49,
        (int *)&v52.m_archive_physical_path.m_string.m_buffer[68]);
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        __formal,
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v52);
      vostok::engine::engine_world::on_before_render_window_shown(
        (vostok::engine::engine_world *)v3,
        *(boost::function<void __cdecl(void)> *)&v52.__vftable);
    }
    vostok::render::engine::world::initialize(
      (vostok::render::engine::world *)v48,
      *(_DWORD *)v3[21].vtable[89].manager);
    if ( (&v3[21].vtable)[1] )
      (*((void (__thiscall **)(boost::detail::function::function_buffer *, _DWORD))v3->functor.obj_ptr + 4))(
        &v3->functor,
        0);
    vostok::testing::suite_base<vostok::engine_test_suite>::run_tests();
  }
}
