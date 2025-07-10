void __cdecl vostok::network::destroy_world(vostok::network::world **world)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  vostok::uninitialized_reference<vostok::network::network_world>::destroy(&s_world_5);
  *world = 0;
}
