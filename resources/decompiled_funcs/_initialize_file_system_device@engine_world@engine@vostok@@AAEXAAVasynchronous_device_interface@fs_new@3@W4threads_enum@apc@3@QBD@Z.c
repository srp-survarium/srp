void __userpurge vostok::engine::engine_world::initialize_file_system_device(
        unsigned int apc_thread_id@<esi>,
        vostok::engine::engine_world *this,
        vostok::fs_new::asynchronous_device_interface *device,
        const char *debug_thread_id)
{
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::engine::engine_world,enum vostok::apc::threads_enum,vostok::engine::device_ticker const &>,boost::_bi::list3<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum>,boost::_bi::value<vostok::engine::device_ticker> > > v5; // [esp-18h] [ebp-68h]
  __int64 v6; // [esp+28h] [ebp-28h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+30h] [ebp-20h] BYREF

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    g_threads.m_begin[apc_thread_id].m_thread_id = -1;
    LODWORD(v6) = device;
    v5.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, vostok::apc::threads_enum, const vostok::engine::device_ticker *))(unsigned int)vostok::engine::engine_world::thread_function<vostok::engine::device_ticker>;
    v5.l_.boost::_bi::storage2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > = (boost::_bi::storage2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> >)__PAIR64__(apc_thread_id, (unsigned int)this);
    function_to_call.vtable = 0;
    *(_QWORD *)&v5.l_.a3_.t_.m_device = v6;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::engine::engine_world,enum vostok::apc::threads_enum,vostok::engine::device_ticker const &>,boost::_bi::list3<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum>,boost::_bi::value<vostok::engine::device_ticker>>>>(
      0,
      (int)&function_to_call,
      apc_thread_id,
      v5);
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count();
    vostok::threading::spawn(&function_to_call, debug_thread_id, debug_thread_id, 7 % s_logical_core_count, tasks_aware);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
