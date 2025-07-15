void __usercall vostok::sound::sound_debug_stats::start(
        vostok::sound::sound_debug_stats *this@<ecx>,
        vostok::sound::sound_debug_stats *a2@<edi>)
{
  vostok::memory::base_allocator *m_orders_allocator; // esi
  char *v3; // eax
  boost::function<void __cdecl(void)> *v4; // ecx
  vostok::sound::functor_command<vostok::sound::sound_order> *v5; // ebx
  vostok::memory::base_allocator *v6; // eax
  __int32 v7; // eax
  __int32 v8; // ebx
  vostok::sound::world_user *m_world_user; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v10; // [esp-8h] [ebp-38h]
  int v11; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v12; // [esp+8h] [ebp-28h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  v13 = 0;
  _InterlockedExchange(&a2->m_actual_statistic, 0);
  m_orders_allocator = a2->m_world_user->m_orders_allocator;
  v3 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v5 = (vostok::sound::functor_command<vostok::sound::sound_order> *)m_orders_allocator->call_malloc(
                                                                       m_orders_allocator,
                                                                       48u,
                                                                       v3,
                                                                       "vostok::sound::sound_debug_stats::start",
                                                                       ".\\sound_debug_stats.cpp",
                                                                       99u);
  if ( v5 )
  {
    v10.l_.a1_.t_ = a2;
    v10.f_.f_ = vostok::sound::sound_debug_stats::update_statistic;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v4,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > *)&v12,
      v10,
      v11);
    v6 = a2->m_world_user->m_orders_allocator;
    v13 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v5,
      v6,
      &v12);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( (v13 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&v12);
  m_world_user = a2->m_world_user;
  *(_DWORD *)(v8 + 8) = 0;
  m_world_user = (vostok::sound::world_user *)((char *)m_world_user + 136);
  _InterlockedExchange((volatile __int32 *)&m_world_user->m_channel.responses.m_forward_queue.m_head->m_next, v8);
  m_world_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v8;
  a2->m_started = 1;
}
