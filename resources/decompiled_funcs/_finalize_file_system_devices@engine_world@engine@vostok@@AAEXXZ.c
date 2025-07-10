void __usercall vostok::engine::engine_world::finalize_file_system_devices(
        vostok::engine::engine_world *this@<ecx>,
        __int64 a2@<edx:eax>)
{
  int v2; // esi
  vostok::apc::callback *v3; // edi
  vostok::apc::callback *v4; // edi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned int v6; // edx
  vostok::apc::callback *v7; // edi
  vostok::apc::callback *v8; // edi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *v10; // ecx
  vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,vostok::fs_new::asynchronous_device_interface *>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<vostok::fs_new::asynchronous_device_interface *> > > v12; // [esp-10h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,vostok::fs_new::asynchronous_device_interface *>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<vostok::fs_new::asynchronous_device_interface *> > > v13; // [esp-10h] [ebp-44h]
  int v14; // [esp+0h] [ebp-34h]
  int v15; // [esp+0h] [ebp-34h]
  boost::function0<void> v16; // [esp+10h] [ebp-24h] BYREF

  v2 = a2;
  _InterlockedExchange((volatile __int32 *)(a2 + 696), 1);
  HIDWORD(a2) = *(_DWORD *)(a2 + 224);
  v16.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::finalize_file_system_device;
  (&v16.vtable)[1] = 0;
  v12.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, vostok::fs_new::asynchronous_device_interface *))(unsigned int)vostok::engine::engine_world::finalize_file_system_device;
  *(_QWORD *)&v16.functor.obj_ptr = a2;
  v12.l_ = (boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<vostok::fs_new::asynchronous_device_interface *> >)a2;
  boost::function0<void>::function0<void>(0, (int)&v16, a2, v12, v14);
  v3 = g_threads.m_begin + 6;
  if ( v3->m_thread_id == GetCurrentThreadId() )
  {
    boost::function0<void>::operator()(&v16);
  }
  else
  {
    vostok::apc::wait(hdd);
    v4 = g_threads.m_begin + 6;
    boost::function<void __cdecl (void)>::operator=(
      &g_threads.m_begin[6].m_callback,
      (const boost::function<void __cdecl(void)> *)&v16);
    v4->m_break_parameters = break_process_loop;
    _InterlockedExchange(&v4->m_pending, 1);
    vostok::apc::wait(hdd);
  }
  if ( v16.vtable )
  {
    if ( ((int)v16.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v16.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&v16.functor, &v16.functor, 2);
    }
  }
  v6 = *(_DWORD *)(v2 + 440);
  v16.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::finalize_file_system_device;
  (&v16.vtable)[1] = 0;
  v13.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *, vostok::fs_new::asynchronous_device_interface *))(unsigned int)vostok::engine::engine_world::finalize_file_system_device;
  *(_QWORD *)&v16.functor.obj_ptr = __PAIR64__(v6, v2);
  v13.l_ = (boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<vostok::fs_new::asynchronous_device_interface *> >)__PAIR64__(v6, v2);
  boost::function0<void>::function0<void>(0, (int)&v16, v2, v13, v15);
  v7 = g_threads.m_begin + 7;
  if ( v7->m_thread_id == GetCurrentThreadId() )
  {
    boost::function0<void>::operator()(&v16);
  }
  else
  {
    vostok::apc::wait(dvd);
    v8 = g_threads.m_begin + 7;
    boost::function<void __cdecl (void)>::operator=(
      &g_threads.m_begin[7].m_callback,
      (const boost::function<void __cdecl(void)> *)&v16);
    v8->m_break_parameters = break_process_loop;
    _InterlockedExchange(&v8->m_pending, 1);
    vostok::apc::wait(dvd);
  }
  if ( v16.vtable )
  {
    if ( ((int)v16.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v16.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&v16.functor, &v16.functor, 2);
    }
  }
  vostok::fs_new::asynchronous_device_interface::finalize_thread_usage(*(vostok::fs_new::asynchronous_device_interface **)(v2 + 224));
  vostok::fs_new::asynchronous_device_interface::finalize_thread_usage(*(vostok::fs_new::asynchronous_device_interface **)(v2 + 440));
  vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface>::destroy(
    v10,
    (vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *)(v2 + 24));
  vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface>::destroy(
    v11,
    (vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *)(v2 + 240));
  vostok::apc::wait(hdd);
  vostok::apc::wait(dvd);
}
