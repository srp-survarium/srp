void __thiscall vostok::collision::loose_oct_tree::for_each_iterate<void (__cdecl *)(vostok::collision::object const *)>(
        vostok::collision::loose_oct_tree *this,
        void (__cdecl **predicate)(const vostok::collision::object *),
        const vostok::collision::oct_node *const node,
        const vostok::math::float3 *aabb_center,
        const float aabb_extents)
{
  const vostok::collision::oct_node *v5; // edi
  const vostok::collision::oct_node *v6; // ebx
  vostok::math::float3 *v7; // eax
  unsigned int v8; // xmm2_4
  unsigned int v9; // xmm0_4
  const vostok::collision::object *i; // esi
  vostok::math::float3 v11; // [esp+10h] [ebp-20h] BYREF
  vostok::math::float3 aabb_centera; // [esp+1Ch] [ebp-14h] BYREF
  vostok::collision::loose_oct_tree *v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]
  float v15; // [esp+44h] [ebp+14h]

  v5 = node;
  v13 = this;
  v15 = aabb_extents * 0.5;
  v14 = 0;
  do
  {
    v6 = node->octants[0];
    if ( node->octants[0] )
    {
      v7 = vostok::collision::octant_vector(&v11, (vostok::math::float3 *)(v14 >> 2));
      *(float *)&v8 = aabb_center->y + (float)(v7->y * v15);
      *(float *)&v9 = aabb_center->z + (float)(v7->z * v15);
      aabb_centera.x = aabb_center->x + (float)(v15 * v7->x);
      *(_QWORD *)&aabb_centera.elements[1] = __PAIR64__(v9, v8);
      vostok::collision::loose_oct_tree::for_each_iterate<void (__cdecl *)(vostok::collision::object const *)>(
        v13,
        predicate,
        v6,
        &aabb_centera,
        v15);
    }
    node = (const vostok::collision::oct_node *const)((char *)node + 4);
    v14 += 4;
  }
  while ( node != (const vostok::collision::oct_node *const)&v5->parent );
  for ( i = v5->objects; i; i = i->m_next )
    (*predicate)(i);
}
