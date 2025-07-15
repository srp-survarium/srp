void __thiscall vostok::collision::loose_oct_tree::for_each_iterate<void (__cdecl *)(vostok::collision::object const *)>(
        vostok::collision::loose_oct_tree *this,
        void (__cdecl *const *predicate)(const vostok::collision::object *),
        const vostok::collision::oct_node *const node,
        const vostok::math::float3 *aabb_center,
        float aabb_extents)
{
  const vostok::collision::oct_node *v5; // eax
  float v6; // xmm2_4
  const vostok::collision::oct_node *v7; // esi
  float v8; // xmm0_4
  int v9; // ebx
  const vostok::collision::oct_node *v10; // ecx
  int v11; // eax
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  const vostok::collision::object *i; // esi
  vostok::math::float3 v20; // [esp+18h] [ebp-Ch] BYREF
  float octant_radius; // [esp+34h] [ebp+10h]

  v5 = node;
  v6 = aabb_extents * 0.5;
  octant_radius = aabb_extents * 0.5;
  v7 = node;
  v8 = *(float *)&clear_value;
  v9 = 0;
  do
  {
    v10 = v7->octants[0];
    if ( v7->octants[0] )
    {
      v11 = v9 >> 2;
      if ( ((v9 >> 2) & 4) != 0 )
        v12 = v8;
      else
        v12 = -1.0;
      if ( (v11 & 2) != 0 )
        v13 = v8;
      else
        v13 = -1.0;
      if ( (v11 & 1) == 0 )
        v8 = -1.0;
      v14 = v13 * v6;
      v15 = v12 * v6;
      v16 = aabb_center->x + (float)(v8 * v6);
      v20.y = aabb_center->y + v14;
      v17 = aabb_center->z + v15;
      v20.x = v16;
      v20.z = v17;
      vostok::collision::loose_oct_tree::for_each_iterate<void (__cdecl *)(vostok::collision::object const *)>(
        this,
        predicate,
        v10,
        &v20,
        octant_radius);
      v8 = *(float *)&clear_value;
      v6 = octant_radius;
      v5 = node;
    }
    v7 = (const vostok::collision::oct_node *)((char *)v7 + 4);
    v9 += 4;
  }
  while ( v7 != (const vostok::collision::oct_node *)&node->parent );
  for ( i = v5->objects; i; i = i->m_next )
    (*predicate)(i);
}
