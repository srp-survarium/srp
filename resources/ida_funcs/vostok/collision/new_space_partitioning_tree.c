vostok::collision::space_partitioning_tree *__cdecl vostok::collision::new_space_partitioning_tree(
        vostok::memory::base_allocator *allocator,
        float min_aabb_radius)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // eax

  v2 = allocator->call_malloc(allocator, 40);
  v3 = v2;
  if ( !v2 )
    return 0;
  *v2 = &vostok::collision::loose_oct_tree::`vftable';
  v4 = allocator->call_malloc(allocator, 12);
  if ( v4 )
  {
    *v4 = allocator;
    v4[1] = 0;
    v4[2] = 0;
  }
  else
  {
    v4 = 0;
  }
  v3[4] = v4;
  v3[5] = 0;
  v3[8] = 0;
  *((_BYTE *)v3 + 36) = 0;
  *((float *)v3 + 7) = min_aabb_radius;
  return (vostok::collision::space_partitioning_tree *)v3;
}
