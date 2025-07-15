void __cdecl vostok::ai::navigation::set_memory_allocator(vostok::memory::base_allocator *allocator)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  vostok::ai::navigation::g_allocator = allocator;
}
