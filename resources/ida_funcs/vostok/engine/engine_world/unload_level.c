void __thiscall vostok::engine::engine_world::unload_level(vostok::engine::engine_world *this)
{
  vostok::apc::callback *v2; // esi
  vostok::apc::callback *v3; // esi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::engine_user::world,char const *,bool>,boost::_bi::list3<boost::_bi::value<vostok::engine_user::world *>,boost::_bi::value<char const *>,boost::_bi::value<bool> > > v5; // [esp-10h] [ebp-48h]
  int v6; // [esp+0h] [ebp-38h]
  __int64 v7; // [esp+Ch] [ebp-2Ch]
  boost::function0<void> *v8; // [esp+14h] [ebp-24h]
  boost::function0<void> v9; // [esp+18h] [ebp-20h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 100))(&this[-1].m_timer.m_time_factor) )
  {
    ((void (__thiscall *)(vostok::sound::world *volatile, const survarium::flash_text *, _DWORD))this->m_sound_world->set_calculation_type)(
      this->m_sound_world,
      &buf,
      0);
  }
  else
  {
    LODWORD(v7) = this->m_sound_world;
    HIDWORD(v7) = &buf;
    *(_QWORD *)&(&v9.vtable)[1] = v7;
    LOBYTE(v8) = 0;
    v9.vtable = (boost::detail::function::vtable_base *) __thiscall vostok::engine_user::world::`vcall'{20,{flat}};
    *(_QWORD *)&v5.f_.f_ = *(_QWORD *)&v9.vtable;
    v9.functor.vostok_pointer_size_alignment[1] = v8;
    *(_QWORD *)&v5.l_.a2_.t_ = *(_QWORD *)&v9.functor.obj_ptr;
    boost::function0<void>::function0<void>(v8, (int)&v9, (int)this, v5, v6);
    v2 = g_threads.m_begin + 1;
    if ( v2->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v9);
    }
    else
    {
      vostok::apc::wait(logic);
      v3 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v9);
      v3->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v3->m_pending, 1);
      vostok::apc::wait(logic);
    }
    if ( v9.vtable && ((int)v9.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v9.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&v9.functor, &v9.functor, 2);
    }
  }
}
