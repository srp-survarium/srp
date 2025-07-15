void __thiscall vostok::render::game::renderer::end_frame(
        vostok::render::game::renderer *this,
        vostok::render::game::renderer *thisa)
{
  char *v3; // edi
  vostok::render::world *m_world; // eax
  bool v5; // zf
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::world>,boost::_bi::list1<boost::_bi::value<vostok::render::world *> > > v8; // [esp-8h] [ebp-58h]
  boost::function4<void,unsigned int,float,float,char const *> v9; // [esp+10h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+30h] [ebp-20h] BYREF
  char thisb; // [esp+54h] [ebp+4h]

  thisb = 0;
  v3 = (char *)vostok::render::logic::g_allocator->call_malloc(vostok::render::logic::g_allocator, 152);
  if ( v3 )
  {
    v8.l_.a1_.t_ = thisa->m_world;
    v8.f_.f_ = vostok::render::world::end_frame_logic;
    f.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::world>,boost::_bi::list1<boost::_bi::value<vostok::render::world *>>>>(
      (boost::function0<void> *)vostok::render::world::end_frame_logic,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::world>,boost::_bi::list1<boost::_bi::value<vostok::render::world *> > > *)&f,
      v8);
    v9.vtable = 0;
    v3[12] = 0;
    v3[13] = 1;
    *((_DWORD *)v3 + 20) = 0;
    *(_DWORD *)v3 = &vostok::render::functor_command::`vftable';
    thisb = 3;
    *((_DWORD *)v3 + 22) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v3 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v9, (int)(v3 + 120));
  }
  else
  {
    v3 = 0;
  }
  m_world = thisa->m_world;
  v5 = thisa->m_world->m_logic_channel.m_channel.m_forward_queue.m_tail->next == 0;
  *((_DWORD *)v3 + 1) = 0;
  _InterlockedExchange(
    (volatile __int32 *)&m_world->m_logic_channel.m_channel.m_forward_queue.m_head->next,
    (__int32)v3);
  m_world->m_logic_channel.m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v3;
  if ( v5 )
    SetEvent(*(HANDLE *)m_world->m_logic_channel.m_wait_form_command_event.m_event.m_event);
  if ( (thisb & 2) != 0 )
  {
    thisb &= ~2u;
    if ( v9.vtable )
    {
      if ( ((int)v9.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v9.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&v9.functor, &v9.functor, 2);
      }
      v9.vtable = 0;
    }
  }
  if ( (thisb & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&f.functor, &f.functor, 2);
  }
}
