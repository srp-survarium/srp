void __cdecl vostok::threading::thread_entry(const boost::function0<void> *argument)
{
  const boost::function0<void> *v1; // esi
  const char *v2; // ecx
  unsigned int obj_ptr; // edx
  volatile int v4; // ecx
  unsigned int v5; // kr00_4
  void *v6; // esp
  unsigned int v7; // kr04_4
  void *v8; // esp
  vostok::threading::tasks_awareness tasks_awareness; // esi
  vostok::tasks::thread_pool *v10; // ecx
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::math *v12[3]; // [esp+0h] [ebp-48h] BYREF
  vostok::threading::thread_entry_params params; // [esp+Ch] [ebp-3Ch] BYREF
  volatile __int32 *v14; // [esp+44h] [ebp-4h]

  v1 = argument;
  params.function_to_call.vtable = 0;
  boost::function0<void>::assign_to_own(&params.function_to_call, argument);
  params.thread_name_for_logging = (const char *volatile)v1[1].vtable;
  v2 = (const char *)(&v1[1].vtable)[1];
  obj_ptr = (unsigned int)v1[1].functor.obj_ptr;
  params.tasks_awareness = (vostok::threading::tasks_awareness)v1[1].functor.vostok_pointer_size_alignment[1];
  params.thread_name_for_debugger = v2;
  v4 = (volatile int)v1[1].functor.vostok_pointer_size_alignment[2];
  params.hardware_thread = obj_ptr;
  v14 = (volatile __int32 *)&v1[1].functor.vostok_pointer_size_alignment[2];
  params.processed = v4;
  v5 = strlen((const char *)(&v1[1].vtable)[1]);
  v6 = alloca(v5 + 1);
  strcpy_s((char *)v12, v5 + 1, (const char *)(&v1[1].vtable)[1]);
  v7 = strlen((const char *)v1[1].vtable);
  v8 = alloca(v7 + 1);
  strcpy_s((char *)v12, v7 + 1, (const char *)v1[1].vtable);
  TlsSetValue(s_thread_logging_name_tls_key, v12);
  _InterlockedExchange((volatile __int32 *)&argument, vostok::debug::is_debugger_present());
  _InterlockedExchange(v14, 1);
  vostok::threading::set_current_thread_affinity((char *)params.hardware_thread);
  tasks_awareness = params.tasks_awareness;
  vostok::math::on_thread_spawn(v12[0]);
  if ( tasks_awareness == tasks_aware && s_thread_pool.m_initialized )
    vostok::tasks::thread_pool::register_current_thread_as_core_user(v10, (DWORD *)s_thread_pool.m_variable);
  boost::function0<void>::operator()(&params.function_to_call);
  if ( TlsGetValue(s_thread_logging_name_tls_key) )
    TlsSetValue(s_thread_logging_name_tls_key, 0);
  if ( params.function_to_call.vtable && ((int)params.function_to_call.vtable & 1) == 0 )
  {
    v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)params.function_to_call.vtable & 0xFFFFFFFE);
    if ( v11 )
      v11(&params.function_to_call.functor, &params.function_to_call.functor, 2);
  }
}
