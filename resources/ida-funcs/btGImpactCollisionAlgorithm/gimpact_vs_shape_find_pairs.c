void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_shape_find_pairs(
        btCollisionShape *shape1@<ecx>,
        btAlignedObjectArray<int> *collided_primitives@<eax>,
        btGImpactCollisionAlgorithm *this,
        const btTransform *trans0,
        btGImpactShapeInterface *trans1,
        btGImpactShapeInterface *shape0)
{
  const btTransform *v8; // edi
  int v9; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v12; // edi
  int v13; // edx
  int v14; // eax
  int *v15; // ecx
  int *m_data; // eax
  int *v17; // eax
  int *v18; // [esp+15Ch] [ebp-68h]
  int v19; // [esp+160h] [ebp-64h]
  btAABB box; // [esp+164h] [ebp-60h] BYREF
  btTransform v21; // [esp+184h] [ebp-40h] BYREF

  if ( trans1->m_box_set.m_box_tree.m_num_nodes )
  {
    btTransform::inverse((btTransform *)this, &v21);
    btTransform::operator*=(trans0, &v21);
    shape1->getAabb(shape1, &v21, (btVector3 *)&box, &box.m_max);
    btGImpactQuantizedBvh::boxQuery(&trans1->m_box_set, &box, collided_primitives);
  }
  else
  {
    shape1->getAabb(shape1, trans0, (btVector3 *)&box, &box.m_max);
    v8 = (const btTransform *)trans1;
    v9 = trans1->getNumChildShapes(trans1);
    while ( v9 )
    {
      v19 = --v9;
      (*(void (__thiscall **)(const btTransform *, int, btGImpactCollisionAlgorithm *, btTransform *, btVector3 *))(v8->m_basis.m_el[0].mVec128.m128_i32[0] + 112))(
        v8,
        v9,
        this,
        &v21,
        &v21.m_basis.m_el[1]);
      if ( box.m_min.mVec128.m128_f32[0] <= v21.m_basis.m_el[1].mVec128.m128_f32[0]
        && v21.m_basis.m_el[0].mVec128.m128_f32[0] <= box.m_max.mVec128.m128_f32[0]
        && box.m_min.mVec128.m128_f32[1] <= v21.m_basis.m_el[1].mVec128.m128_f32[1]
        && v21.m_basis.m_el[0].mVec128.m128_f32[1] <= box.m_max.mVec128.m128_f32[1]
        && box.m_min.mVec128.m128_f32[2] <= v21.m_basis.m_el[1].mVec128.m128_f32[2]
        && v21.m_basis.m_el[0].mVec128.m128_f32[2] <= box.m_max.mVec128.m128_f32[2] )
      {
        m_capacity = collided_primitives->m_capacity;
        m_size = collided_primitives->m_size;
        if ( m_size == m_capacity )
        {
          v12 = 2 * m_size;
          if ( !m_size )
            v12 = 1;
          if ( m_capacity < v12 )
          {
            if ( v12 )
            {
              ++gNumAlignedAllocs;
              v18 = (int *)sAlignedAllocFunc(4 * v12, 16);
            }
            else
            {
              v18 = 0;
            }
            v13 = collided_primitives->m_size;
            v14 = 0;
            if ( v13 > 0 )
            {
              v15 = v18;
              do
              {
                if ( v15 )
                {
                  *v15 = collided_primitives->m_data[v14];
                  v9 = v19;
                }
                ++v14;
                ++v15;
              }
              while ( v14 < v13 );
            }
            m_data = collided_primitives->m_data;
            if ( m_data )
            {
              if ( collided_primitives->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(m_data);
              }
              collided_primitives->m_data = 0;
            }
            collided_primitives->m_ownsMemory = 1;
            collided_primitives->m_data = v18;
            collided_primitives->m_capacity = v12;
          }
          v8 = (const btTransform *)trans1;
        }
        v17 = &collided_primitives->m_data[collided_primitives->m_size];
        if ( v17 )
          *v17 = v9;
        ++collided_primitives->m_size;
      }
    }
  }
}
