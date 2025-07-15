void __thiscall vostok::sound::sound_debug_stats::update_statistic(vostok::sound::sound_debug_stats *this)
{
  int v2; // esi
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  boost::function<void __cdecl(void)> *v6; // ecx
  char *v7; // edi
  vostok::memory::doug_lea_allocator *v8; // eax
  vostok::sound::world_user *m_world_user; // ebx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v10; // [esp-8h] [ebp-38h]
  const char *v11; // [esp+0h] [ebp-30h]
  int v12; // [esp+0h] [ebp-30h]
  const char *v13; // [esp+4h] [ebp-2Ch]
  unsigned int v14; // [esp+8h] [ebp-28h]
  char v15; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v16; // [esp+10h] [ebp-20h] BYREF

  v15 = 0;
  if ( this->m_actual_statistic != -1 )
  {
    v2 = this->m_actual_statistic ^ 1;
    if ( this->m_statistic[v2] )
      vostok::sound::sound_scene::delete_statistic(
        (vostok::memory::doug_lea_allocator *)this,
        this->m_statistic[v2]->values.m_sound_types);
    this->m_statistic[v2] = vostok::sound::sound_scene::create_statistic((vostok::sound::sound_scene *)this);
    _InterlockedExchange(&this->m_actual_statistic, v2);
    v3 = vostok::sound::g_allocator;
    v4 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_response> `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x30u, v4, v11, v13, v14);
    if ( v7 )
    {
      v10.l_.a1_.t_ = this;
      v10.f_.f_ = vostok::sound::sound_debug_stats::on_statistic_updated;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        v6,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > *)&v16,
        v10,
        v12);
      v8 = vostok::sound::g_allocator;
      *((_DWORD *)v7 + 2) = 0;
      *((_DWORD *)v7 + 1) = v8;
      v15 = 1;
      *(_DWORD *)v7 = &vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        &v16,
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v7 + 16));
    }
    else
    {
      v7 = 0;
    }
    if ( (v15 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v16);
    m_world_user = this->m_world_user;
    *((_DWORD *)v7 + 2) = 0;
    _InterlockedExchange(
      (volatile __int32 *)&m_world_user->m_channel.responses.m_forward_queue.m_head->m_next,
      (__int32)v7);
    m_world_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v7;
  }
}
