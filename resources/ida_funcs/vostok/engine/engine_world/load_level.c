void __thiscall vostok::engine::engine_world::load_level(
        vostok::engine::engine_world *this,
        char *project_resource_name)
{
  vostok::apc::callback *v3; // esi
  vostok::apc::callback *v4; // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine_user::world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::engine_user::world *>,boost::_bi::value<char const *> > > v6; // [esp-Ch] [ebp-44h]
  int v7; // [esp+0h] [ebp-38h]
  __int64 v8; // [esp+Ch] [ebp-2Ch]
  boost::function0<void> v9; // [esp+18h] [ebp-20h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 100))(&this[-1].m_timer.m_time_factor) )
  {
    ((void (__thiscall *)(vostok::sound::world *volatile, char *))this->m_sound_world->start_destruction)(
      this->m_sound_world,
      project_resource_name);
  }
  else
  {
    HIDWORD(v8) = this->m_sound_world;
    LODWORD(v8) =  __thiscall vostok::sound::world::`vcall'{12,{flat}};
    *(_QWORD *)&v6.f_.f_ = v8;
    v6.l_.a2_.t_ = project_resource_name;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)project_resource_name,
      (int)&v9,
      (unsigned int)this,
      v6,
      v7);
    v3 = g_threads.m_begin + 1;
    if ( v3->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v9);
    }
    else
    {
      vostok::apc::wait(logic);
      v4 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v9);
      v4->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v4->m_pending, 1);
      vostok::apc::wait(logic);
    }
    if ( v9.vtable && ((int)v9.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v9.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&v9.functor, &v9.functor, 2);
    }
  }
}
