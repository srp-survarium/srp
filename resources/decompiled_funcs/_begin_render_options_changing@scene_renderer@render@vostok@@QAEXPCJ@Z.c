void __thiscall vostok::render::scene_renderer::begin_render_options_changing(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *waiting_for,
        volatile int *waiting_fora)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  __int32 v5; // ebp
  vostok::render::one_way_render_channel *m_channel; // ebx
  bool v7; // zf
  char v8; // bl
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,long volatile *>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<long volatile *> > > v11; // [esp-Ch] [ebp-70h]
  int v12; // [esp+0h] [ebp-64h]
  __int64 v13; // [esp+14h] [ebp-50h]
  boost::function4<void,unsigned int,float,float,char const *> v14; // [esp+20h] [ebp-44h] BYREF
  boost::function0<void> f; // [esp+40h] [ebp-24h] BYREF
  char thisa; // [esp+68h] [ebp+4h]

  m_allocator = waiting_for->m_allocator;
  thisa = 0;
  v5 = (__int32)m_allocator->call_malloc(m_allocator, 152u);
  if ( v5 )
  {
    HIDWORD(v13) = waiting_for->m_render_engine_world;
    LODWORD(v13) = vostok::render::engine::world::begin_render_options_changing;
    *(_QWORD *)&v11.f_.f_ = v13;
    v11.l_.a2_.t_ = waiting_fora;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)waiting_fora,
      (int)&f,
      0,
      v11,
      v12);
    v14.vtable = 0;
    *(_BYTE *)(v5 + 12) = 0;
    *(_BYTE *)(v5 + 13) = 1;
    *(_DWORD *)(v5 + 80) = 0;
    *(_DWORD *)v5 = &vostok::render::functor_command::`vftable';
    thisa = 3;
    *(_DWORD *)(v5 + 88) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v5 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v14, v5 + 120);
  }
  else
  {
    v5 = 0;
  }
  m_channel = waiting_for->m_channel;
  v7 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
  *(_DWORD *)(v5 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, v5);
  m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v5;
  if ( v7 )
    SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
  v8 = thisa;
  if ( (thisa & 2) != 0 )
  {
    v8 = thisa & 0xFD;
    if ( v14.vtable )
    {
      if ( ((int)v14.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v14.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&v14.functor, &v14.functor, 2);
      }
      v14.vtable = 0;
    }
  }
  if ( (v8 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v10 )
      v10(&f.functor, &f.functor, 2);
  }
}
