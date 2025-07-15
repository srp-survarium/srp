vostok::ai::navigation::world *__cdecl vostok::ai::navigation::create_world(
        vostok::ai::navigation::engine *engine,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  int v5; // eax
  void *_Where; // [esp+4h] [ebp-Ch]
  vostok::ai::navigation::navigation_world *v9; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v3);
  _Where = vostok::memory::base_allocator::malloc_impl(v4, 0x30u);
  v9 = (vostok::ai::navigation::navigation_world *)operator new(0x30u, _Where);
  if ( !v9 )
    return 0;
  vostok::ai::navigation::navigation_world::navigation_world(v9, engine, scene, renderer);
  return (vostok::ai::navigation::world *)v5;
}
