void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::udp_network_flow_emulator>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::udp_network_flow_emulator **pointer)
{
  vostok::network_core::udp_network_flow_emulator *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::udp_network_flow_emulator::~udp_network_flow_emulator(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
