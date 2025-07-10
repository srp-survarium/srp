void __thiscall vostok::render::scene_renderer::reset_renderer(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *thisa)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  __int32 v4; // ebp
  vostok::render::one_way_render_channel *m_channel; // eax
  bool v6; // zf
  char v7; // bl
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<bool> > > v10; // [esp-Ch] [ebp-74h]
  int v11; // [esp+0h] [ebp-68h]
  boost::function<void __cdecl(void)> *v12; // [esp+18h] [ebp-50h]
  boost::function<void __cdecl(void)> *v13[2]; // [esp+1Ch] [ebp-4Ch]
  boost::function4<void,unsigned int,float,float,char const *> v14; // [esp+28h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+48h] [ebp-20h] BYREF
  char thisb; // [esp+6Ch] [ebp+4h]

  m_allocator = thisa->m_allocator;
  thisb = 0;
  v4 = (__int32)m_allocator->call_malloc(m_allocator, 152u);
  if ( v4 )
  {
    v13[1] = (boost::function<void __cdecl(void)> *)thisa->m_render_engine_world;
    LOBYTE(v12) = 1;
    v13[0] = (boost::function<void __cdecl(void)> *)vostok::render::engine::world::reset_renderer;
    *(_QWORD *)&v10.f_.f_ = *(_QWORD *)v13;
    *(_DWORD *)&v10.l_.a2_.t_ = v12;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v12, (int)&f, 0, v10, v11);
    v14.vtable = 0;
    *(_BYTE *)(v4 + 12) = 0;
    *(_BYTE *)(v4 + 13) = 1;
    *(_DWORD *)(v4 + 80) = 0;
    *(_DWORD *)v4 = &vostok::render::functor_command::`vftable';
    thisb = 3;
    *(_DWORD *)(v4 + 88) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v4 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v14, v4 + 120);
  }
  else
  {
    v4 = 0;
  }
  m_channel = thisa->m_channel;
  v6 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
  *(_DWORD *)(v4 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, v4);
  m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v4;
  if ( v6 )
    SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
  v7 = thisb;
  if ( (thisb & 2) != 0 )
  {
    v7 = thisb & 0xFD;
    if ( v14.vtable )
    {
      if ( ((int)v14.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v14.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&v14.functor, &v14.functor, 2);
      }
      v14.vtable = 0;
    }
  }
  if ( (v7 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v9 )
      v9(&f.functor, &f.functor, 2);
  }
}
