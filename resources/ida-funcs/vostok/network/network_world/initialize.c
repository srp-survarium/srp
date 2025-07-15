void __thiscall vostok::network::network_world::initialize(vostok::network::network_world *this)
{
  vostok::memory::base_allocator *m_orders_allocator; // esi
  char *v3; // eax
  boost::function<void __cdecl(void)> *v4; // ecx
  int v5; // ebx
  vostok::memory::base_allocator *v6; // esi
  char *v7; // eax
  boost::function<void __cdecl(void)> *v8; // ecx
  int v9; // ebx
  vostok::network::order *v10; // esi
  DWORD CurrentThreadId; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *p_m_pop_thread_id; // ecx
  int v13; // [esp+18h] [ebp-58h]
  char v14; // [esp+28h] [ebp-48h]
  vostok::network::order *v15; // [esp+2Ch] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v16; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v17; // [esp+50h] [ebp-20h] BYREF

  v14 = 0;
  m_orders_allocator = this->m_orders_allocator;
  v3 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v5 = (int)m_orders_allocator->call_malloc(
              m_orders_allocator,
              48u,
              v3,
              "vostok::network::network_world::initialize",
              ".\\network_world.cpp",
              38u);
  if ( v5 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v4,
      &v17,
      (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl,
      v13);
    *(_DWORD *)(v5 + 4) = this->m_orders_allocator;
    v14 = 1;
    *(_DWORD *)v5 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v17,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v5 + 16));
    v15 = (vostok::network::order *)v5;
  }
  else
  {
    v15 = 0;
  }
  v6 = this->m_orders_allocator;
  v7 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v9 = (int)v6->call_malloc(v6, 48u, v7, "vostok::network::network_world::initialize", ".\\network_world.cpp", 38u);
  if ( v9 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v8,
      &v16,
      (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl,
      v13);
    v14 |= 2u;
    *(_DWORD *)(v9 + 4) = this->m_orders_allocator;
    *(_DWORD *)v9 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v16,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v9 + 16));
    v10 = (vostok::network::order *)v9;
  }
  else
  {
    v10 = 0;
  }
  _InterlockedExchange(&this->m_channel.orders.m_forward_queue.m_push_thread_id, GetCurrentThreadId());
  v15->next_for_orders = 0;
  this->m_channel.orders.m_forward_queue.m_tail = v15;
  this->m_channel.orders.m_forward_queue.m_head = v15;
  CurrentThreadId = GetCurrentThreadId();
  p_m_pop_thread_id = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&this->m_channel.orders.m_backward_queue.m_pop_thread_id;
  _InterlockedExchange(&this->m_channel.orders.m_backward_queue.m_pop_thread_id, CurrentThreadId);
  v10->next_for_orders = 0;
  this->m_channel.orders.m_backward_queue.m_tail = v10;
  this->m_channel.orders.m_backward_queue.m_head = v10;
  if ( (v14 & 2) != 0 )
  {
    v14 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      p_m_pop_thread_id,
      (int *)&v16);
  }
  if ( (v14 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      p_m_pop_thread_id,
      (int *)&v17);
  _InterlockedExchange(&this->m_channel.responses.m_forward_queue.m_pop_thread_id, GetCurrentThreadId());
  _InterlockedExchange(&this->m_channel.responses.m_backward_queue.m_push_thread_id, GetCurrentThreadId());
}
