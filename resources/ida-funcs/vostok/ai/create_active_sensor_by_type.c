vostok::ai::sensors::active_sensor_base *__cdecl vostok::ai::create_active_sensor_by_type(
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        const char *active_sensor_type,
        vostok::ai::brain_unit *brain)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  int v6; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  int v10; // eax
  int *v13; // [esp+8h] [ebp-20h]
  int *_Where; // [esp+14h] [ebp-14h]
  vostok::ai::sensors::interaction_sensor *v15; // [esp+20h] [ebp-8h]
  vostok::ai::sensors::vision_sensor *v16; // [esp+24h] [ebp-4h]

  if ( vostok::strings::equal(active_sensor_type, "vision") )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x90u);
    v16 = (vostok::ai::sensors::vision_sensor *)operator new(0x90u, _Where);
    if ( !v16 )
      return 0;
    vostok::ai::sensors::vision_sensor::vision_sensor(v16, npc, world, brain);
    return (vostok::ai::sensors::active_sensor_base *)v6;
  }
  else if ( vostok::strings::equal(active_sensor_type, "interaction") )
  {
    survarium::weapon_user_dead_state::finalize(v8);
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x18u);
    v15 = (vostok::ai::sensors::interaction_sensor *)operator new(0x18u, v13);
    if ( !v15 )
      return 0;
    vostok::ai::sensors::interaction_sensor::interaction_sensor(v15, npc, world, brain);
    return (vostok::ai::sensors::active_sensor_base *)v10;
  }
  else
  {
    return 0;
  }
}
