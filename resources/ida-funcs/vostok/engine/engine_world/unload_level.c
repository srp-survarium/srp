void __thiscall vostok::engine::engine_world::unload_level(vostok::engine::engine_world *this)
{
  boost::function<void __cdecl(void)> *v2; // ecx
  boost::detail::function::vtable_base *m_sound_world; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::engine_user::world,char const *,bool>,boost::_bi::list3<boost::_bi::value<vostok::engine_user::world *>,boost::_bi::value<char const *>,boost::_bi::value<bool> > > v5; // [esp-14h] [ebp-4Ch]
  void *v6; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void)> f; // [esp+18h] [ebp-20h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 104))(&this[-1].m_timer.m_time_factor) )
  {
    ((void (__thiscall *)(vostok::sound::world *volatile, const char *, _DWORD))this->m_sound_world->__vftable[1].clear_resources)(
      this->m_sound_world,
      uri,
      0);
  }
  else
  {
    m_sound_world = (boost::detail::function::vtable_base *)this->m_sound_world;
    f.vtable = (boost::detail::function::vtable_base *) __thiscall vostok::engine_user::world::`vcall'{28,{flat}};
    LOBYTE(v6) = 0;
    (&f.vtable)[1] = m_sound_world;
    f.functor.obj_ptr = (void *)uri;
    f.functor.vostok_pointer_size_alignment[1] = v6;
    v5.l_.a1_.t_ = (vostok::engine_user::world *) __thiscall vostok::engine_user::world::`vcall'{28,{flat}};
    *(_QWORD *)&v5.l_.a2_.t_ = __PAIR64__(uri, (unsigned int)m_sound_world);
    v5.f_.f_ = (void (__thiscall *)(vostok::engine_user::world *, const char *, bool))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, v5, (int)v6);
    run(logic, &f, continue_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&f);
  }
}
