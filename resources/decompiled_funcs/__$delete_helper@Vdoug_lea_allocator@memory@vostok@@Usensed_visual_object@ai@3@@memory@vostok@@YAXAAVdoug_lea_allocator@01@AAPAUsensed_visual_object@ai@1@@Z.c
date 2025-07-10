void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::sensed_visual_object>(
        vostok::memory::doug_lea_allocator *allocator,
        survarium::game_camera **pointer)
{
  survarium::game_camera *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    survarium::weapon_user_dead_state::finalize(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
