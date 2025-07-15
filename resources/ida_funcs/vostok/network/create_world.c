vostok::network::network_world *__cdecl vostok::network::create_world(
        vostok::network::engine *engine,
        vostok::memory::base_allocator *orders_allocator)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::network::network_world *v6; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v2);
  v6 = (vostok::network::network_world *)operator new(0x124u, &s_world_5);
  if ( v6 )
    vostok::network::network_world::network_world(v6, engine, orders_allocator);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::threading::interlocked_exchange_pointer(&s_world_5.m_initialized, 1);
  survarium::weapon_user_dead_state::finalize(v4);
  return s_world_5.m_variable;
}
