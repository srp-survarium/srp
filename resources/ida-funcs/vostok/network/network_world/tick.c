void __thiscall vostok::network::network_world::tick(vostok::network::network_world *this, bool single_threaded)
{
  vostok::network::response **p_m_tail; // ebx
  vostok::network::response *v4; // esi
  vostok::network::response *next_for_responses; // eax
  vostok::network::order *m_tail; // eax
  vostok::network::order *next_for_orders; // ecx
  __int32 v8; // edx
  boost::asio::io_service *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-3Ch]
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *v13; // [esp+0h] [ebp-38h]
  char v14; // [esp+10h] [ebp-28h]
  unsigned int elapsed_msec; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v14 = 0;
  p_m_tail = &this->m_channel.responses.m_backward_queue.m_tail;
  while ( 1 )
  {
    v4 = *p_m_tail;
    next_for_responses = (*p_m_tail)->next_for_responses;
    if ( !next_for_responses )
      break;
    *p_m_tail = next_for_responses;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::delete_value(
      v4,
      v13);
  }
  while ( 1 )
  {
    m_tail = this->m_channel.orders.m_forward_queue.m_tail;
    next_for_orders = m_tail->next_for_orders;
    if ( !next_for_orders )
      break;
    this->m_channel.orders.m_forward_queue.m_tail = next_for_orders;
    m_tail->next_for_orders = 0;
    v8 = _InterlockedExchange(
           (volatile __int32 *)&this->m_channel.orders.m_backward_queue.m_head->next_for_orders,
           (__int32)m_tail);
    this->m_channel.orders.m_backward_queue.m_head = m_tail;
    ((void (__fastcall *)(vostok::network::order *, __int32))next_for_orders->execute)(next_for_orders, v8);
  }
  if ( single_threaded )
  {
    boost::asio::io_service::run_one(0, (int)this->m_io_service);
  }
  else
  {
    vostok::timing::timer::timer(0, (LARGE_INTEGER *)&log_callback);
    *(LARGE_INTEGER *)&log_callback.functor.obj_ptr = vostok::timing::get_QPC();
    log_callback.vtable = 0;
    (&log_callback.vtable)[1] = 0;
    while ( boost::asio::io_service::poll_one(v9, (int)this->m_io_service)
         && (unsigned int)vostok::timing::timer::get_elapsed_msec((vostok::timing::timer *)v9, (int)&log_callback) < 0x28 )
      ;
    elapsed_msec = vostok::timing::timer::get_elapsed_msec((vostok::timing::timer *)v9, (int)&log_callback);
    if ( elapsed_msec >= 0x64 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                                   (const char *)3),
            v10 = v12,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &log_callback);
        v14 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_world.cpp",
          0x41u,
          "void __thiscall vostok::network::network_world::tick(bool)",
          &initiator_raw.filter_stack.gap0,
          warning,
          "lag during polling : %d.%03d",
          elapsed_msec / 0x3E8,
          elapsed_msec % 0x3E8);
      }
      if ( (v14 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&log_callback);
    }
  }
}
