void __usercall vostok::network::http_client::http_client(
        vostok::network::http_client *this@<edi>,
        vostok::network::network_world *world@<eax>)
{
  vostok::network::network_world *m_world; // eax
  vostok::memory::base_allocator *m_orders_allocator; // ebx
  char *v4; // eax
  boost::function<void __cdecl(void)> *v5; // ecx
  __int32 v6; // ebx
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *p_orders; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  bool v9; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *> > > v10; // [esp-8h] [ebp-38h]
  int v11; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v12; // [esp+8h] [ebp-28h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  this->m_world = world;
  this->m_on_content_downloaded.vtable = 0;
  this->m_on_error.vtable = 0;
  this->m_client_on_error.vtable = 0;
  m_world = this->m_world;
  this->m_client = 0;
  this->m_busy = 1;
  m_orders_allocator = m_world->m_orders_allocator;
  v13 = 0;
  v4 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v6 = (__int32)m_orders_allocator->call_malloc(
                  m_orders_allocator,
                  48u,
                  v4,
                  "vostok::network::http_client::http_client",
                  ".\\http_client.cpp",
                  29u);
  if ( v6 )
  {
    v10.l_.a1_.t_ = this;
    v10.f_.f_ = vostok::network::http_client::create_client_impl;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v5,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *> > > *)&v12,
      v10,
      v11);
    *(_DWORD *)(v6 + 4) = this->m_world->m_orders_allocator;
    v13 = 1;
    *(_DWORD *)v6 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v12,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v6 + 16));
  }
  else
  {
    v6 = 0;
  }
  p_orders = &this->m_world->m_channel.orders;
  *(_DWORD *)(v6 + 8) = 0;
  v8 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)&p_orders->m_forward_queue.m_head->next_for_orders,
                                                                                         v6);
  v9 = (v13 & 1) == 0;
  p_orders->m_forward_queue.m_head = (vostok::network::order *)v6;
  if ( !v9 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&v12);
}
