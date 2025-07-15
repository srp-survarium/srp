void __thiscall vostok::testing::initialize(vostok::command_line::key *this)
{
  vostok::command_line::key *v1; // ecx
  boost::function<void __cdecl(void)> *v2; // ecx
  void *v3; // ecx
  unsigned int v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  int v6; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(void)> v7; // [esp+8h] [ebp-20h] BYREF

  s_environment.engine = s_engine_0;
  if ( vostok::testing::run_tests_command_line(this) )
  {
    if ( !vostok::command_line::key::is_set(v1, (int)&vostok::testing::s_no_test_watch) )
    {
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        v2,
        &v7,
        (void (__cdecl *)())vostok::testing::test_watcher_thread_proc,
        v6);
      v4 = vostok::threading::core_count(v3);
      vostok::threading::spawn(&v7, "test-watcher", "test watcher", 3 % v4, 0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v5,
        (int *)&v7);
    }
  }
}
