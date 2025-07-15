void __userpurge vostok::network_core::udp_match_packets_allocator::udp_match_packets_allocator(
        vostok::network_core::udp_match_packets_allocator *this@<ecx>,
        int a2@<edi>,
        vostok::memory::base_allocator *allocator,
        vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *arena,
        unsigned int arena_size)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> const &)> v6; // [esp+8h] [ebp-20h] BYREF

  v6.vtable = 0;
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>(
    &v6,
    (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)a2,
    arena,
    arena_size);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v6);
  *(_DWORD *)(a2 + 56) = allocator;
  *(_DWORD *)(a2 + 60) = 0;
}
