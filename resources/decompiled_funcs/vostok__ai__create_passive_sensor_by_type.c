vostok::ai::sensors::passive_sensor_base *__cdecl vostok::ai::create_passive_sensor_by_type(
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        const char *passive_sensor_type,
        vostok::ai::brain_unit *brain)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  int v6; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  int v10; // eax
  bool v11; // al
  vostok::memory::doug_lea_allocator *v12; // eax
  int v13; // eax
  int *v17; // [esp+Ch] [ebp-30h]
  int *v18; // [esp+18h] [ebp-24h]
  int *_Where; // [esp+24h] [ebp-18h]
  vostok::ai::sensors::damage_sensor *v20; // [esp+30h] [ebp-Ch]
  vostok::ai::sensors::smell_sensor *v21; // [esp+34h] [ebp-8h]
  vostok::ai::sensors::hearing_sensor *v22; // [esp+38h] [ebp-4h]

  if ( vostok::strings::equal(passive_sensor_type, "hearing") )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x60u);
    v22 = (vostok::ai::sensors::hearing_sensor *)operator new(0x60u, _Where);
    if ( !v22 )
      return 0;
    vostok::ai::sensors::hearing_sensor::hearing_sensor(v22, npc, world, brain);
    return (vostok::ai::sensors::passive_sensor_base *)v6;
  }
  else if ( vostok::strings::equal(passive_sensor_type, "smell") )
  {
    survarium::weapon_user_dead_state::finalize(v8);
    v18 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x3Cu);
    v21 = (vostok::ai::sensors::smell_sensor *)operator new(0x3Cu, v18);
    if ( !v21 )
      return 0;
    vostok::ai::sensors::smell_sensor::smell_sensor(v21, npc, world, brain);
    return (vostok::ai::sensors::passive_sensor_base *)v10;
  }
  else
  {
    v11 = vostok::strings::equal(passive_sensor_type, "damage");
    if ( v11 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v11);
      v17 = vostok::memory::doug_lea_allocator::malloc_impl(v12, 0x48u);
      v20 = (vostok::ai::sensors::damage_sensor *)operator new(0x48u, v17);
      if ( !v20 )
        return 0;
      vostok::ai::sensors::damage_sensor::damage_sensor(v20, npc, world, brain);
      return (vostok::ai::sensors::passive_sensor_base *)v13;
    }
    else
    {
      return 0;
    }
  }
}
