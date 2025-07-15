void __thiscall vostok::engine::engine_world::initialize_sound(vostok::engine::engine_world *this, void *a2)
{
  void *v2; // ecx
  unsigned int v3; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v5; // [esp-14h] [ebp-40h]
  boost::function<void __cdecl(void)> f; // [esp+8h] [ebp-24h] BYREF

  if ( !vostok::command_line::key::is_set(
          (vostok::command_line::key *)this,
          (int)&vostok::threading::g_debug_single_thread) )
  {
    g_threads.m_begin[4].m_thread_id = -1;
    f.functor.vostok_pointer_size_alignment[2] = vostok::engine::engine_world::sound;
    f.functor.bound_memfunc_ptr.obj_ptr = a2;
    f.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v5.f_.f_) = vostok::engine::engine_world::sound;
    v5.l_.a1_.t_ = 0;
    *((_DWORD *)&v5.l_ + 1) = a2;
    LODWORD(v5.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      v5,
      (int)f.functor.vostok_pointer_size_alignment[5]);
    v3 = vostok::threading::core_count(v2);
    vostok::threading::spawn(
      &f,
      (const char *)&initiator_raw.filter_stack.m_last,
      (const char *)&initiator_raw.filter_stack.m_last,
      3 % v3,
      0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&f);
  }
}
