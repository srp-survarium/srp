void __cdecl vostok::logging::delete_filter_tree(vostok::logging::filter_tree **filter_tree)
{
  vostok::memory::base_allocator *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)filter_tree);
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::filter_tree>(v1, filter_tree);
}
