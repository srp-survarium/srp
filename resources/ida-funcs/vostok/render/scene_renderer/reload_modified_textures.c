void __thiscall vostok::render::scene_renderer::reload_modified_textures(vostok::render::scene_renderer *this)
{
  char *v2; // edi
  vostok::render::one_way_render_channel *m_channel; // ebp
  bool v4; // zf
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *> > > v7; // [esp-8h] [ebp-60h]
  char v8; // [esp+14h] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> v9; // [esp+18h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+38h] [ebp-20h] BYREF

  v8 = 0;
  v2 = (char *)this->m_allocator->call_malloc(this->m_allocator, 152);
  if ( v2 )
  {
    v7.l_.a1_.t_ = this->m_render_engine_world;
    v7.f_.f_ = vostok::render::engine::world::reload_modified_textures;
    f.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *>>>>(
      (boost::function0<void> *)vostok::render::engine::world::reload_modified_textures,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *> > > *)&f,
      v7);
    v9.vtable = 0;
    v2[12] = 0;
    v2[13] = 1;
    *((_DWORD *)v2 + 20) = 0;
    *(_DWORD *)v2 = &vostok::render::functor_command::`vftable';
    v8 = 3;
    *((_DWORD *)v2 + 22) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v2 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v9, (int)(v2 + 120));
  }
  else
  {
    v2 = 0;
  }
  m_channel = this->m_channel;
  v4 = m_channel->m_channel.m_forward_queue.m_tail->next == 0;
  *((_DWORD *)v2 + 1) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->m_channel.m_forward_queue.m_head->next, (__int32)v2);
  m_channel->m_channel.m_forward_queue.m_head = (vostok::render::base_command *)v2;
  if ( v4 )
    SetEvent(*(HANDLE *)m_channel->m_wait_form_command_event.m_event.m_event);
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( v9.vtable )
    {
      if ( ((int)v9.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v9.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&v9.functor, &v9.functor, 2);
      }
      v9.vtable = 0;
    }
  }
  if ( (v8 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&f.functor, &f.functor, 2);
  }
}
