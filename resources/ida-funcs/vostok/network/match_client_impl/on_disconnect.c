void __thiscall vostok::network::match_client_impl::on_disconnect(
        vostok::network::match_client_impl *this,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *disconnect_type)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  int v4; // ecx
  boost::function<void __cdecl(void)> v5; // [esp+8h] [ebp-20h] BYREF

  v5.vtable = 0;
  *(_DWORD *)((char *)&loc_6EF80 + (_DWORD)this) = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v5,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_55F88 + (_DWORD)this));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v5);
  v4 = -(*(_UNKNOWN **)((char *)&off_55438 + (_DWORD)this) != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v4) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v4,
      (_UNKNOWN **)((char *)&off_55438 + (_DWORD)this),
      disconnect_type);
}
