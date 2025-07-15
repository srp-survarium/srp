void __userpurge vostok::engine::engine_world::initialize_file_system_device(
        unsigned int apc_thread_id@<eax>,
        vostok::command_line::key *a2@<ecx>,
        vostok::engine::engine_world *this,
        vostok::fs_new::asynchronous_device_interface *device,
        char *debug_thread_id)
{
  void *v6; // ecx
  unsigned int v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-58h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+8h] [ebp-34h] BYREF
  vostok::engine::engine_world *v11; // [esp+2Ch] [ebp-10h]
  unsigned int v12; // [esp+30h] [ebp-Ch]
  vostok::fs_new::asynchronous_device_interface *v13; // [esp+34h] [ebp-8h]

  if ( !vostok::command_line::key::is_set(a2, (int)&vostok::threading::g_debug_single_thread) )
  {
    g_threads.m_begin[apc_thread_id].m_thread_id = -1;
    v11 = this;
    v12 = apc_thread_id;
    f.functor.vostok_pointer_size_alignment[1] = 0;
    f.functor.obj_ptr = vostok::engine::engine_world::thread_function<vostok::engine::device_ticker>;
    v13 = device;
    *((_QWORD *)&f.functor.data + 1) = __PAIR64__(apc_thread_id, (unsigned int)this);
    f.functor.bound_memfunc_ptr.obj_ptr = device;
    *(_DWORD *)v9 = &f;
    qmemcpy(&v9[4], &f.functor, 0x18u);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::engine::engine_world,enum vostok::apc::threads_enum,vostok::engine::device_ticker const &>,boost::_bi::list3<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<enum vostok::apc::threads_enum>,boost::_bi::value<vostok::engine::device_ticker> > > *)v9,
      *(int *)&v9[24]);
    *(_DWORD *)&v9[24] = 0;
    *(_DWORD *)&v9[20] = v6;
    v7 = vostok::threading::core_count(v6);
    vostok::threading::spawn(&f, debug_thread_id, debug_thread_id, 4 % v7, v9[24]);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&f);
  }
}
