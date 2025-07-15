void __thiscall vostok::engine::engine_world::initialize_resources(
        vostok::engine::engine_world *this,
        vostok::engine::engine_world *thisa)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *p_m_pending; // esi
  vostok::apc::callback *v4; // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v7; // esi
  vostok::apc::callback *v8; // esi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,enum vostok::apc::threads_enum>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > > v10; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,enum vostok::apc::threads_enum>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > > v11; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v12; // [esp-8h] [ebp-38h]
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+10h] [ebp-20h] BYREF

  if ( s_no_fs_watch.m_type == type_unset )
  {
    s_no_fs_watch.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  vostok::core::initialize_resources(
    (vostok::resources::resources_manager *)thisa->m_hdd_async_interface.m_variable,
    thisa->m_dvd_async_interface.m_variable);
  g_threads.m_begin[8].m_thread_id = -1;
  g_threads.m_begin[9].m_thread_id = -1;
  g_threads.m_begin[10].m_thread_id = -1;
  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::resources_thread;
    (&function_to_call.vtable)[1] = 0;
    v10.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, vostok::apc::threads_enum))(unsigned int)vostok::engine::engine_world::resources_thread;
    *(_QWORD *)&function_to_call.functor.obj_ptr = (unsigned int)thisa | 0x800000000LL;
    v10.l_ = *(boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > *)&function_to_call.functor.obj_ptr;
    boost::function0<void>::function0<void>(0, (int)&function_to_call, 1, v10, v13);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(&function_to_call, "res_man", "resources manager", 2 % s_logical_core_count, tasks_aware);
    if ( function_to_call.vtable )
    {
      if ( ((int)function_to_call.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&function_to_call.functor, &function_to_call.functor, 2);
      }
    }
    function_to_call.vtable = 0;
    if ( `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable )
      `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable(
        &function_to_call.functor,
        &function_to_call.functor,
        destroy_functor_tag);
    if ( vostok::resources::on_resources_thread_started )
    {
      function_to_call.functor.obj_ptr = vostok::resources::on_resources_thread_started;
      function_to_call.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable
                                                                       + 1);
    }
    else
    {
      function_to_call.vtable = 0;
    }
    p_m_pending = g_threads.m_begin + 8;
    if ( p_m_pending->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&function_to_call);
    }
    else
    {
      vostok::apc::wait(res_man);
      v4 = g_threads.m_begin + 8;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[8].m_callback, &function_to_call);
      v4->m_break_parameters = break_process_loop;
      p_m_pending = (vostok::apc::callback *)&v4->m_pending;
      _InterlockedExchange((volatile __int32 *)p_m_pending, 1);
      vostok::apc::wait(res_man);
    }
    if ( function_to_call.vtable )
    {
      if ( ((int)function_to_call.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&function_to_call.functor, &function_to_call.functor, 2);
      }
    }
    function_to_call.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::cooker_thread;
    (&function_to_call.vtable)[1] = 0;
    v11.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, vostok::apc::threads_enum))(unsigned int)vostok::engine::engine_world::cooker_thread;
    *(_QWORD *)&function_to_call.functor.obj_ptr = (unsigned int)thisa | 0x900000000LL;
    v11.l_ = *(boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > *)&function_to_call.functor.obj_ptr;
    boost::function0<void>::function0<void>(0, (int)&function_to_call, (int)p_m_pending, v11, v14);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(&function_to_call, "res_cook", "resources cooker", 2 % s_logical_core_count, tasks_aware);
    if ( function_to_call.vtable )
    {
      if ( ((int)function_to_call.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&function_to_call.functor, &function_to_call.functor, 2);
      }
    }
    *(_DWORD *)&v12.l_ = (&function_to_call.vtable)[1];
    v12.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
    function_to_call.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      (boost::function0<void> *)(&function_to_call.vtable)[1],
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&function_to_call,
      v12);
    v7 = g_threads.m_begin + 9;
    if ( v7->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&function_to_call);
    }
    else
    {
      vostok::apc::wait(res_cook);
      v8 = g_threads.m_begin + 9;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[9].m_callback, &function_to_call);
      v8->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v8->m_pending, 1);
      vostok::apc::wait(res_cook);
    }
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
