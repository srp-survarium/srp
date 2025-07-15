void __thiscall vostok::engine::engine_world::enable_game_impl(
        vostok::engine::engine_world *this,
        vostok::engine::engine_world *value,
        boost::function<void __cdecl(void)> *a3)
{
  boost::function<void __cdecl(void)> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,bool>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<bool> > > v5; // [esp-14h] [ebp-4Ch]
  int v6; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void)> f; // [esp+18h] [ebp-20h] BYREF

  if ( value->command_line_editor_singlethread(value) )
  {
    vostok::engine::engine_world::enable_game_in_logic_thread(value, (BOOL)a3);
  }
  else
  {
    LOBYTE(v3) = (_BYTE)a3;
    (&f.vtable)[1] = 0;
    f.vtable = (boost::detail::function::vtable_base *)vostok::engine::engine_world::enable_game_in_logic_thread;
    LOBYTE(v6) = (_BYTE)a3;
    *(_QWORD *)&f.functor.obj_ptr = __PAIR64__(v6, (unsigned int)value);
    HIDWORD(v5.f_.f_) = vostok::engine::engine_world::enable_game_in_logic_thread;
    v5.l_.a1_.t_ = 0;
    *(_DWORD *)&v5.l_.a2_.t_ = value;
    LODWORD(v5.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, v5, v6);
    run(logic, &f, continue_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&f);
  }
  value->m_game_enabled = (char)a3;
}
