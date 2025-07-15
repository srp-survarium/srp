void __thiscall vostok::sound::sound_debug_stats::on_statistic_updated(vostok::sound::sound_debug_stats *this)
{
  vostok::memory::base_allocator *m_orders_allocator; // esi
  char *v3; // eax
  boost::function<void __cdecl(void)> *v4; // ecx
  vostok::sound::functor_command<vostok::sound::sound_order> *v5; // ebx
  __int32 v6; // eax
  __int32 v7; // ebx
  vostok::sound::world_user *m_world_user; // edi
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v9; // [esp+0h] [ebp-38h]
  int v10; // [esp+8h] [ebp-30h]
  char v11; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v12; // [esp+18h] [ebp-20h] BYREF

  v11 = 0;
  if ( this->m_actual_statistic != -1 )
  {
    m_orders_allocator = this->m_world_user->m_orders_allocator;
    v3 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
    v5 = (vostok::sound::functor_command<vostok::sound::sound_order> *)m_orders_allocator->call_malloc(
                                                                         m_orders_allocator,
                                                                         48u,
                                                                         v3,
                                                                         "vostok::sound::sound_debug_stats::on_statistic_updated",
                                                                         ".\\sound_debug_stats.cpp",
                                                                         146u);
    if ( v5 )
    {
      v9.l_.a1_.t_ = this;
      v9.f_.f_ = vostok::sound::sound_debug_stats::update_statistic;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        v4,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > *)&v12,
        v9,
        v10);
      v11 = 1;
      vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
        v5,
        this->m_world_user->m_orders_allocator,
        &v12);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    if ( (v11 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v12);
    m_world_user = this->m_world_user;
    *(_DWORD *)(v7 + 8) = 0;
    m_world_user = (vostok::sound::world_user *)((char *)m_world_user + 136);
    _InterlockedExchange((volatile __int32 *)&m_world_user->m_channel.responses.m_forward_queue.m_head->m_next, v7);
    m_world_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v7;
  }
}
