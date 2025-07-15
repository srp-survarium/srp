void __usercall vostok::network::tcp_packet_client::tcp_packet_client(
        vostok::network::tcp_packet_client *this@<edi>,
        vostok::network::network_world *world@<eax>)
{
  vostok::memory::base_allocator *m_orders_allocator; // ebx
  char *v3; // eax
  boost::function<void __cdecl(void)> *v4; // ecx
  __int32 v5; // ebx
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *p_orders; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  bool v8; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v9; // [esp-8h] [ebp-38h]
  int v10; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v11; // [esp+8h] [ebp-28h] BYREF
  int v12; // [esp+2Ch] [ebp-4h]

  this->m_on_packet_received.vtable = 0;
  this->m_on_connected.vtable = 0;
  this->m_on_disconnected.vtable = 0;
  this->m_on_error.vtable = 0;
  this->m_world = world;
  this->m_client = 0;
  m_orders_allocator = world->m_orders_allocator;
  v12 = 0;
  v3 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v5 = (__int32)m_orders_allocator->call_malloc(
                  m_orders_allocator,
                  48u,
                  v3,
                  "vostok::network::tcp_packet_client::tcp_packet_client",
                  ".\\tcp_packet_client.cpp",
                  28u);
  if ( v5 )
  {
    v9.l_.a1_.t_ = this;
    v9.f_.f_ = vostok::network::tcp_packet_client::create_client;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v4,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > *)&v11,
      v9,
      v10);
    *(_DWORD *)(v5 + 4) = this->m_world->m_orders_allocator;
    v12 = 1;
    *(_DWORD *)v5 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v11,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v5 + 16));
  }
  else
  {
    v5 = 0;
  }
  p_orders = &this->m_world->m_channel.orders;
  *(_DWORD *)(v5 + 8) = 0;
  v7 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)&p_orders->m_forward_queue.m_head->next_for_orders,
                                                                                         v5);
  v8 = (v12 & 1) == 0;
  p_orders->m_forward_queue.m_head = (vostok::network::order *)v5;
  if ( !v8 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v11);
}
