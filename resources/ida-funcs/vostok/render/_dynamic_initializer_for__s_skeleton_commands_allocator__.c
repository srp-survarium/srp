int vostok::render::_dynamic_initializer_for__s_skeleton_commands_allocator__()
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v0; // ecx
  void *v2; // [esp+0h] [ebp-28h]
  unsigned int v3; // [esp+4h] [ebp-24h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<10340,vostok::threading::multi_threading_policy> const &)> v4; // [esp+8h] [ebp-20h] BYREF

  v4.vtable = 0;
  vostok::memory::single_size_buffer_allocator<10340,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<10340,vostok::threading::multi_threading_policy>(
    &v4,
    (vostok::memory::single_size_buffer_allocator<10340,vostok::threading::multi_threading_policy>::node *)s_skeleton_commands_allocator.m_buffer,
    v2,
    v3);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v0,
    (int *)&v4);
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_skeleton_commands_allocator__);
}
