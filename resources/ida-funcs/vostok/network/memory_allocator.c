void __cdecl vostok::network::memory_allocator(vostok::memory::doug_lea_allocator *allocator)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  vostok::network::g_allocator = allocator;
  vostok::network_core::memory_allocator(allocator);
}
