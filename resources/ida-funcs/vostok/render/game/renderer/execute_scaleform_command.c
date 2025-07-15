void __thiscall vostok::render::game::renderer::execute_scaleform_command(
        vostok::render::game::renderer *this,
        vostok::render::game::renderer *command,
        Scaleform::Render::ThreadCommand *commanda)
{
  char *v3; // ebx
  Scaleform::Render::ThreadCommand_vtbl *m_world; // eax
  bool v5; // zf
  char v6; // bl
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,survarium::scaleform_render_command>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<survarium::scaleform_render_command> > > v9; // [esp-Ch] [ebp-6Ch]
  int v10; // [esp+0h] [ebp-60h]
  char v11; // [esp+10h] [ebp-50h]
  __int64 v12; // [esp+14h] [ebp-4Ch]
  boost::function4<void,unsigned int,float,float,char const *> v13; // [esp+20h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+40h] [ebp-20h] BYREF

  v11 = 0;
  v3 = (char *)vostok::render::logic::g_allocator->call_malloc(vostok::render::logic::g_allocator, 152);
  if ( v3 )
  {
    HIDWORD(v12) = command->m_render_engine_world;
    LODWORD(v12) = vostok::render::engine::world::execute_scaleform_command;
    *(_QWORD *)&v9.f_.f_ = v12;
    v9.l_.a2_.t_.thread_command = commanda;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)commanda,
      (int)&f,
      0,
      v9,
      v10);
    v13.vtable = 0;
    v3[12] = 0;
    v3[13] = 1;
    *((_DWORD *)v3 + 20) = 0;
    *(_DWORD *)v3 = &vostok::render::functor_command::`vftable';
    v11 = 3;
    *((_DWORD *)v3 + 22) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v3 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v13, (int)(v3 + 120));
  }
  else
  {
    v3 = 0;
  }
  m_world = (Scaleform::Render::ThreadCommand_vtbl *)command->m_world;
  v5 = command->m_world->m_logic_channel.m_channel.m_forward_queue.m_tail->next == 0;
  *((_DWORD *)v3 + 1) = 0;
  _InterlockedExchange((volatile __int32 *)m_world->~Scaleform::Render::ThreadCommand + 1, (__int32)v3);
  m_world->~Scaleform::Render::ThreadCommand = (void (__thiscall *)(struct Scaleform::Render::ThreadCommand *))v3;
  if ( v5 )
    SetEvent(m_world[18].~Scaleform::Render::ThreadCommand);
  v6 = v11;
  if ( (v11 & 2) != 0 )
  {
    v6 = v11 & 0xFD;
    if ( v13.vtable )
    {
      if ( ((int)v13.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v13.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&v13.functor, &v13.functor, 2);
      }
      v13.vtable = 0;
    }
  }
  if ( (v6 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&f.functor, &f.functor, 2);
  }
}
