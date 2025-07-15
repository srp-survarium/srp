void __cdecl vostok::network_core::memory_allocator(vostok::memory::base_allocator *allocator)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  vostok::network_core::g_allocator = allocator;
}
