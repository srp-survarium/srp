void __cdecl run(
        __int32 thread_id,
        boost::function<void __cdecl(void)> *callback,
        vostok::apc::break_parameters break_parameters,
        const vostok::apc::wait_parameters wait_parameters,
        bool remote_only)
{
  vostok::apc::threads_enum v5; // edi
  vostok::apc::callback *v6; // esi
  boost::function0<bool> *v7; // ecx
  vostok::apc::callback *v8; // esi
  vostok::command_line::key *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // [esp-4h] [ebp-30h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // [esp-4h] [ebp-30h]
  boost::function<void __cdecl(void)> v12; // [esp+8h] [ebp-24h] BYREF

  v5 = thread_id;
  v6 = &g_threads.m_begin[thread_id];
  if ( v6->m_thread_id == GetCurrentThreadId() )
  {
    if ( !remote_only )
      boost::function0<void>::operator()(v7, callback);
  }
  else
  {
    v12.vtable = 0;
    vostok::apc::wait((const vostok::apc::threads_enum)thread_id, (vostok::command_line::key *)v7, &v12);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)&v12);
    v8 = &g_threads.m_begin[v5];
    boost::function<void __cdecl (void)>::operator=(
      callback,
      (boost::function1<void,vostok::physics::contact_point const &> *)&g_threads.m_begin[v5]);
    v8->m_break_parameters = break_parameters;
    _InterlockedExchange(&v8->m_pending, 1);
    if ( wait_parameters == wait_for_completion )
    {
      v12.vtable = 0;
      vostok::apc::wait((const vostok::apc::threads_enum)thread_id, v9, &v12);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v11,
        (int *)&v12);
    }
  }
}
