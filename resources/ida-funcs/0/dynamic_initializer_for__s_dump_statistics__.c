int __thiscall dynamic_initializer_for__s_dump_statistics__(boost::function<void __cdecl(char const *)> *this)
{
  vostok::console_commands::cc_delegate *v1; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  int v4; // [esp+0h] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v5; // [esp+4h] [ebp-20h] BYREF

  boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
    this,
    &v5,
    (void (__cdecl *)(const char *))dump_memory_statistics,
    v4);
  vostok::console_commands::cc_delegate::cc_delegate(
    v1,
    (int)&s_dump_statistics,
    "dump_memory_statistics",
    &v5,
    0,
    command_type_user_specific);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v5);
  return atexit(dynamic_atexit_destructor_for__s_dump_statistics__);
}
