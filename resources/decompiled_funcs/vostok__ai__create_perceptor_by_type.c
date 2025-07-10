vostok::ai::perceptors::perceptor_base *__cdecl vostok::ai::create_perceptor_by_type(
        vostok::ai::npc *npc,
        const char *perceptor_type,
        vostok::ai::working_memory *memory,
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
  vostok::ai::perceptors::pickup_item_perceptor *v15; // [esp+20h] [ebp-8h]
  vostok::ai::perceptors::enemy_perceptor *v16; // [esp+24h] [ebp-4h]

  if ( vostok::strings::equal(perceptor_type, "enemy") )
  {
    survarium::weapon_user_dead_state::finalize(v4);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x40u);
    v16 = (vostok::ai::perceptors::enemy_perceptor *)operator new(0x40u, _Where);
    if ( !v16 )
      return 0;
    vostok::ai::perceptors::enemy_perceptor::enemy_perceptor(v16, npc, brain, memory);
    return (vostok::ai::perceptors::perceptor_base *)v6;
  }
  else if ( vostok::strings::equal(perceptor_type, "pickup_item") )
  {
    survarium::weapon_user_dead_state::finalize(v8);
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x40u);
    v15 = (vostok::ai::perceptors::pickup_item_perceptor *)operator new(0x40u, v13);
    if ( !v15 )
      return 0;
    vostok::ai::perceptors::pickup_item_perceptor::pickup_item_perceptor(v15, npc, brain, memory);
    return (vostok::ai::perceptors::perceptor_base *)v10;
  }
  else
  {
    return 0;
  }
}
