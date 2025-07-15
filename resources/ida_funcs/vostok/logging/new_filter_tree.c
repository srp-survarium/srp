vostok::logging::filter_tree *__cdecl vostok::logging::new_filter_tree(vostok::memory::base_allocator *allocator)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::base_allocator *v2; // eax
  int v3; // eax
  void *_Where; // [esp+4h] [ebp-Ch]
  vostok::logging::filter_tree *v7; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::base_allocator::malloc_impl(v2, 0x38u);
  v7 = (vostok::logging::filter_tree *)operator new(0x38u, _Where);
  if ( !v7 )
    return 0;
  vostok::logging::filter_tree::filter_tree(v7, allocator);
  return (vostok::logging::filter_tree *)v3;
}
