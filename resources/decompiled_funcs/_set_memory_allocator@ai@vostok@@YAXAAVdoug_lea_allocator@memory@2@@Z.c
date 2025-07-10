void __cdecl vostok::ai::set_memory_allocator(vostok::memory::doug_lea_allocator *allocator)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  vostok::ai::g_allocator = allocator;
}
