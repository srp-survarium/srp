vostok::ai::world *__cdecl vostok::ai::create_world(vostok::ai::engine *engine)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  int v3; // eax
  int *_Where; // [esp+4h] [ebp-Ch]
  vostok::ai::ai_world *v7; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x688u);
  v7 = (vostok::ai::ai_world *)operator new(0x688u, _Where);
  if ( !v7 )
    return 0;
  vostok::ai::ai_world::ai_world(v7, engine);
  return (vostok::ai::world *)v3;
}
