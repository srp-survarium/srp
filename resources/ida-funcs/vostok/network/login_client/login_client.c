void __userpurge vostok::network::login_client::login_client(
        vostok::network::network_world *world@<eax>,
        vostok::command_line::key *a2@<ecx>,
        vostok::network::login_client *this)
{
  vostok::command_line::key *v4; // ecx
  vostok::network::network_world *m_world; // eax
  vostok::memory::base_allocator *m_orders_allocator; // edi
  char *v7; // eax
  boost::function<void __cdecl(void)> *v8; // ecx
  __int32 v9; // edi
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,8> > *p_orders; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *> > > v12; // [esp-8h] [ebp-CCh]
  vostok::command_line::key *v13; // [esp-4h] [ebp-C8h]
  int v14; // [esp+0h] [ebp-C4h]
  vostok::buffer_string v15; // [esp+10h] [ebp-B4h] BYREF
  _BYTE v16[128]; // [esp+1Ch] [ebp-A8h] BYREF
  char v17; // [esp+9Ch] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v18; // [esp+A0h] [ebp-24h] BYREF
  char v19; // [esp+CCh] [ebp+8h]

  this->m_on_sign_up.vtable = 0;
  this->m_on_sign_in.vtable = 0;
  this->m_on_sign_out.vtable = 0;
  this->m_world = world;
  v15.m_begin = v16;
  v15.m_end = v16;
  v15.m_max_end = &v17;
  v19 = 0;
  this->m_client = 0;
  this->m_client_state = signed_out;
  v16[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(a2, &s_net_client_account_name_cl.m_string_value, &v15) )
  {
    vostok::strings::copy<128>((char (*)[128])s_net_client_account_name, v15.m_begin);
    v4 = v13;
  }
  if ( vostok::command_line::key::is_set_as_string(v4, &s_net_client_account_password_cl.m_string_value, &v15) )
    vostok::strings::copy<128>((char (*)[128])s_net_client_account_password, v15.m_begin);
  vostok::strings::copy<128>((char (*)[128])this->m_net_client_account_password, s_net_client_account_password);
  m_world = this->m_world;
  this->m_local_host_ip[0] = 0;
  m_orders_allocator = m_world->m_orders_allocator;
  v7 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v9 = (__int32)m_orders_allocator->call_malloc(
                  m_orders_allocator,
                  48u,
                  v7,
                  "vostok::network::login_client::login_client",
                  ".\\login_client.cpp",
                  77u);
  if ( v9 )
  {
    v12.l_.a1_.t_ = this;
    v12.f_.f_ = vostok::network::login_client::create_client;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v8,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *> > > *)&v18,
      v12,
      v14);
    *(_DWORD *)(v9 + 4) = this->m_world->m_orders_allocator;
    v19 = 1;
    *(_DWORD *)v9 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v18,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v9 + 16));
  }
  else
  {
    v9 = 0;
  }
  p_orders = &this->m_world->m_channel.orders;
  *(_DWORD *)(v9 + 8) = 0;
  v11 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)&p_orders->m_forward_queue.m_head->next_for_orders,
                                                                                          v9);
  p_orders->m_forward_queue.m_head = (vostok::network::order *)v9;
  if ( (v19 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&v18);
}
