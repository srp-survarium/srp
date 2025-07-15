int __thiscall dynamic_initializer_for__cfg_save_system_cc__(boost::function<void __cdecl(char const *)> *this)
{
  vostok::console_commands::cc_delegate *v1; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v4; // [esp-8h] [ebp-38h]
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v7; // [esp+10h] [ebp-20h] BYREF

  *(_DWORD *)&v4.l_ = v6;
  v4.f_ = (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl;
  boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
    this,
    (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v7,
    v4,
    v5);
  vostok::console_commands::cc_delegate::cc_delegate(
    v1,
    (int)&cfg_save_system_cc,
    "cfg_save_system",
    &v7,
    0,
    command_type_engine_internal);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v7);
  return atexit(dynamic_atexit_destructor_for__cfg_save_system_cc__);
}
