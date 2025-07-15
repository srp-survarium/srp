void __usercall vostok::engine::engine_world::initialize_logic(
        vostok::engine::engine_world *this@<ecx>,
        _DWORD *a2@<eax>)
{
  void *v3; // ecx
  HWND v4; // eax
  void *v5; // ecx
  unsigned int v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v8; // [esp-14h] [ebp-44h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void)> process_callback; // [esp+10h] [ebp-20h] BYREF

  process_callback.vtable = 0;
  vostok::apc::wait(editor, &process_callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&process_callback);
  if ( !a2[169] )
  {
    v4 = new_window();
    a2[178] = v4;
    a2[179] = v4;
  }
  a2[180] = 0;
  if ( vostok::threading::core_count(v3) != 1
    && (!a2[169] || !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*a2 + 104))(a2)) )
  {
    g_threads.m_begin[1].m_thread_id = -1;
    process_callback.functor.bound_memfunc_ptr.obj_ptr = a2;
    process_callback.functor.vostok_pointer_size_alignment[2] = vostok::engine::engine_world::logic;
    process_callback.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v8.f_.f_) = vostok::engine::engine_world::logic;
    v8.l_.a1_.t_ = 0;
    *((_DWORD *)&v8.l_ + 1) = a2;
    LODWORD(v8.f_.f_) = &process_callback;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      v8,
      (int)process_callback.functor.vostok_pointer_size_alignment[5]);
    v6 = vostok::threading::core_count(v5);
    vostok::threading::spawn(&process_callback, "logic", "logic", 1 % v6, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&process_callback);
  }
}
