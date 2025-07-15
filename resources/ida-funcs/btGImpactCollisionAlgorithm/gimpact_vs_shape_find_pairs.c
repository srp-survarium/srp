void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_shape_find_pairs(
        btAlignedObjectArray<int> *collided_primitives@<edi>,
        btTransform *a2@<ecx>,
        btGImpactCollisionAlgorithm *this,
        const btTransform *trans0,
        const btTransform *trans1,
        btGImpactShapeInterface *shape0,
        btCollisionShape *shape1)
{
  const btTransform *v7; // esi
  int i; // eax
  int m_capacity; // ecx
  int m_size; // eax
  int v11; // ebx
  int v12; // edx
  int v13; // ecx
  int *v14; // eax
  int *v15; // eax
  int *v16; // [esp+1Ch] [ebp-68h]
  int v17; // [esp+20h] [ebp-64h]
  btAABB box; // [esp+24h] [ebp-60h] BYREF
  btTransform v19; // [esp+44h] [ebp-40h] BYREF

  v7 = trans1;
  if ( trans1[1].m_basis.m_el[1].mVec128.m128_i32[0] )
  {
    btTransform::inverse(a2, (int)this, &v19);
    btTransform::operator*=(&v19, trans0);
    shape0->getAabb(shape0, &v19, (btVector3 *)&box, &box.m_max);
    btGImpactQuantizedBvh::boxQuery(&box, (btGImpactQuantizedBvh *)&trans1[1].m_basis.m_el[1], collided_primitives);
  }
  else
  {
    shape0->getAabb(shape0, trans0, (btVector3 *)&box, &box.m_max);
    for ( i = (*(int (__thiscall **)(const btTransform *))(trans1->m_basis.m_el[0].mVec128.m128_i32[0] + 80))(trans1);
          i;
          i = v17 )
    {
      v17 = i - 1;
      (*(void (__thiscall **)(const btTransform *, int, btGImpactCollisionAlgorithm *, btTransform *, btVector3 *))(v7->m_basis.m_el[0].mVec128.m128_i32[0] + 112))(
        v7,
        i - 1,
        this,
        &v19,
        &v19.m_basis.m_el[1]);
      if ( box.m_min.mVec128.m128_f32[0] <= v19.m_basis.m_el[1].mVec128.m128_f32[0]
        && v19.m_basis.m_el[0].mVec128.m128_f32[0] <= box.m_max.mVec128.m128_f32[0]
        && box.m_min.mVec128.m128_f32[1] <= v19.m_basis.m_el[1].mVec128.m128_f32[1]
        && v19.m_basis.m_el[0].mVec128.m128_f32[1] <= box.m_max.mVec128.m128_f32[1]
        && box.m_min.mVec128.m128_f32[2] <= v19.m_basis.m_el[1].mVec128.m128_f32[2]
        && v19.m_basis.m_el[0].mVec128.m128_f32[2] <= box.m_max.mVec128.m128_f32[2] )
      {
        m_capacity = collided_primitives->m_capacity;
        m_size = collided_primitives->m_size;
        if ( m_size == m_capacity )
        {
          v11 = m_size ? 2 * m_size : 1;
          if ( m_capacity < v11 )
          {
            if ( v11 )
              v16 = (int *)btAlignedAllocInternal(4 * v11);
            else
              v16 = 0;
            v12 = collided_primitives->m_size;
            v13 = 0;
            if ( v12 > 0 )
            {
              v14 = v16;
              do
              {
                if ( v14 )
                {
                  *v14 = collided_primitives->m_data[v13];
                  v7 = trans1;
                }
                ++v13;
                ++v14;
              }
              while ( v13 < v12 );
            }
            if ( collided_primitives->m_data )
            {
              if ( collided_primitives->m_ownsMemory )
                btAlignedFreeInternal(collided_primitives->m_data);
              collided_primitives->m_data = 0;
            }
            collided_primitives->m_ownsMemory = 1;
            collided_primitives->m_data = v16;
            collided_primitives->m_capacity = v11;
          }
        }
        v15 = &collided_primitives->m_data[collided_primitives->m_size];
        if ( v15 )
          *v15 = v17;
        ++collided_primitives->m_size;
      }
    }
  }
}
