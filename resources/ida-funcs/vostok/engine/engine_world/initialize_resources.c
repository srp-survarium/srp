void __thiscall vostok::engine::engine_world::initialize_resources(
        vostok::engine::engine_world *this,
        vostok::apc::threads_enum a2)
{
  void *v2; // ecx
  unsigned int v3; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(void)> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  void *v7; // ecx
  unsigned int v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(void)> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,enum vostok::apc::threads_enum>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > > v12; // [esp-14h] [ebp-48h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,enum vostok::apc::threads_enum>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum> > > v13; // [esp-14h] [ebp-48h]
  vostok::command_line::key *v14; // [esp-4h] [ebp-38h]
  int v15; // [esp+0h] [ebp-34h]
  int v16; // [esp+0h] [ebp-34h]
  boost::function<void __cdecl(void)> f; // [esp+10h] [ebp-24h] BYREF

  vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_fs_watch);
  vostok::core::initialize_resources(
    *(vostok::fs_new::asynchronous_device_interface **)(a2 + 232),
    *(vostok::fs_new::asynchronous_device_interface **)(a2 + 448));
  g_threads.m_begin[8].m_thread_id = -1;
  g_threads.m_begin[9].m_thread_id = -1;
  g_threads.m_begin[10].m_thread_id = -1;
  if ( !vostok::command_line::key::is_set(v14, (int)&vostok::threading::g_debug_single_thread) )
  {
    *((_QWORD *)&f.functor.data + 2) = (unsigned int)a2 | 0x800000000LL;
    f.functor.vostok_pointer_size_alignment[2] = vostok::engine::engine_world::resources_thread;
    f.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v12.f_.f_) = vostok::engine::engine_world::resources_thread;
    v12.l_.a1_.t_ = 0;
    v12.l_.a2_.t_ = a2;
    LODWORD(v12.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)8,
      v12,
      8);
    v3 = vostok::threading::core_count(v2);
    vostok::threading::spawn(&f, "res_man", "resources manager", 5 % v3, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&f);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v5,
      &f,
      vostok::resources::on_resources_thread_started,
      v15);
    run(8, &f, break_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
    f.functor.vostok_pointer_size_alignment[2] = vostok::engine::engine_world::cooker_thread;
    *((_QWORD *)&f.functor.data + 2) = (unsigned int)a2 | 0x900000000LL;
    f.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v13.f_.f_) = vostok::engine::engine_world::cooker_thread;
    v13.l_.a1_.t_ = 0;
    v13.l_.a2_.t_ = a2;
    LODWORD(v13.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)9,
      v13,
      9);
    v8 = vostok::threading::core_count(v7);
    vostok::threading::spawn(&f, "res_cook", "resources cooker", 6 % v8, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&f);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v10,
      &f,
      (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl,
      v16);
    run(9, &f, break_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&f);
  }
}
