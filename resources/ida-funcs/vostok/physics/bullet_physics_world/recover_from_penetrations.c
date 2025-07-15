char __thiscall vostok::physics::bullet_physics_world::recover_from_penetrations(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_collision_shape *const shape,
        const vostok::math::float4x4 *transform_initial,
        vostok::math::float4x4 *transform_result,
        int filter_group,
        int filter_mask)
{
  btCollisionShape *m_bt_shape; // esi
  vostok::physics::bullet_physics_world *v7; // edi
  btCollisionObject *v8; // eax
  int v9; // esi
  int v10; // ecx
  btBroadphasePair *v11; // eax
  float v12; // xmm3_4
  int i; // edx
  int v14; // eax
  float v15; // xmm4_4
  int v16; // ecx
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  btHashedOverlappingPairCache_vtbl *v22; // eax
  long double v23; // rdi
  btAlignedObjectArray<GrahamVector2> *v24; // ecx
  vostok::math::float4x4 *v25; // esi
  vostok::physics::bullet_physics_world *v26; // eax
  int v28; // [esp+1Ch] [ebp-1D8h]
  int v29; // [esp+20h] [ebp-1D4h]
  int v30; // [esp+24h] [ebp-1D0h] BYREF
  int v31; // [esp+28h] [ebp-1CCh]
  int v32; // [esp+2Ch] [ebp-1C8h]
  void *ptr; // [esp+30h] [ebp-1C4h]
  int v34; // [esp+34h] [ebp-1C0h]
  float v35; // [esp+38h] [ebp-1BCh]
  vostok::physics::bullet_physics_world *v36; // [esp+3Ch] [ebp-1B8h]
  int v37; // [esp+40h] [ebp-1B4h]
  btVector3 v38; // [esp+44h] [ebp-1B0h]
  float v39; // [esp+54h] [ebp-1A0h]
  float v40; // [esp+58h] [ebp-19Ch]
  float v41; // [esp+5Ch] [ebp-198h]
  int v42; // [esp+60h] [ebp-194h]
  float v43; // [esp+64h] [ebp-190h]
  float v44; // [esp+68h] [ebp-18Ch]
  float v45; // [esp+6Ch] [ebp-188h]
  int v46; // [esp+70h] [ebp-184h]
  vostok::math::float4x4 v47; // [esp+74h] [ebp-180h] BYREF
  btPairCachingGhostObject v48; // [esp+B4h] [ebp-140h] BYREF

  m_bt_shape = shape->m_bt_shape;
  v7 = this;
  v36 = this;
  btPairCachingGhostObject::btPairCachingGhostObject((btPairCachingGhostObject *)this, &v48);
  v48.m_collisionShape = m_bt_shape;
  v48.m_rootCollisionShape = m_bt_shape;
  v48.m_collisionFlags = 16;
  v8 = (btCollisionObject *)vostok::physics::from_vostok(transform_initial, (btMatrix3x3 *)&v47);
  btCollisionObject::setWorldTransform(v8, (btVector3 *)&v48);
  v7->m_dynamicsWorld->addCollisionObject(v7->m_dynamicsWorld, &v48, filter_group, filter_mask);
  v37 = 3;
  while ( 1 )
  {
    ((void (__stdcall *)(btHashedOverlappingPairCache *, btDispatcherInfo *, btDispatcher *))v7->m_dynamicsWorld->m_dispatcher1->dispatchAllCollisionPairs)(
      v48.m_hashPairCache,
      &v7->m_dynamicsWorld->m_dispatchInfo,
      v7->m_dynamicsWorld->m_dispatcher1);
    v38.mVec128 = (__m128)v48.m_worldTransform.m_origin;
    LOBYTE(v34) = 1;
    ptr = 0;
    v31 = 0;
    v32 = 0;
    v28 = 0;
    if ( v48.m_hashPairCache->getNumOverlappingPairs(v48.m_hashPairCache) > 0 )
    {
      v29 = 0;
      do
      {
        v9 = v31;
        v35 = 0.0;
        if ( v31 < 0 )
        {
          if ( v32 < 0 )
          {
            if ( ptr && (_BYTE)v34 )
              btAlignedFreeInternal(ptr);
            LOBYTE(v34) = 1;
            ptr = 0;
            v32 = 0;
          }
          if ( v9 < 0 )
          {
            v10 = 4 * v9;
            do
            {
              if ( (char *)ptr + v10 )
                *(_DWORD *)((char *)ptr + v10) = 0;
              v10 += 4;
            }
            while ( v10 < 0 );
          }
        }
        v31 = 0;
        v11 = &v48.m_hashPairCache->getOverlappingPairArray(v48.m_hashPairCache)->m_data[v29];
        if ( v11->m_algorithm )
          v11->m_algorithm->getAllContactManifolds(
            v11->m_algorithm,
            (btAlignedObjectArray<btPersistentManifold *> *)&v30);
        v12 = v35;
        for ( i = 0; i < v31; ++i )
        {
          v14 = *((_DWORD *)ptr + i);
          if ( *(btPairCachingGhostObject **)(v14 + 1168) == &v48 )
            v15 = FLOAT_N1_0;
          else
            v15 = s_bm_current_air_resistance;
          v16 = *(_DWORD *)(v14 + 1176);
          if ( v16 > 0 )
          {
            v17 = (float *)(v14 + 88);
            do
            {
              v18 = v17[2];
              if ( v18 < 0.0 && v12 > v18 )
              {
                v19 = *(v17 - 1);
                if ( v19 > 0.0 )
                {
                  v40 = v19 * v15;
                  v20 = *v17;
                  v12 = v18;
                  v21 = *(v17 - 2);
                  v42 = 0;
                  v39 = v21 * v15;
                  v41 = v20 * v15;
                  v43 = v21 * v15;
                  v44 = v40;
                  v45 = v20 * v15;
                  v46 = 0;
                }
              }
              v17 += 72;
              --v16;
            }
            while ( v16 );
          }
        }
        v22 = v48.m_hashPairCache->__vftable;
        ++v28;
        ++v29;
        v38.mVec128.m128_f32[0] = (float)(v43 * v12) + v38.mVec128.m128_f32[0];
        v38.mVec128.m128_f32[1] = v38.mVec128.m128_f32[1] + (float)(v44 * v12);
        v38.mVec128.m128_f32[2] = v38.mVec128.m128_f32[2] + (float)(v45 * v12);
      }
      while ( v28 < v22->getNumOverlappingPairs(v48.m_hashPairCache) );
    }
    *(_QWORD *)&v47.i.x = v48.m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    *(_QWORD *)&v47.lines[0].elements[2] = v48.m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    v47.lines[1] = (vostok::math::float4_pod)v48.m_worldTransform.m_basis.m_el[1];
    v47.lines[2] = (vostok::math::float4_pod)v48.m_worldTransform.m_basis.m_el[2];
    v47.lines[3] = (vostok::math::float4_pod)v38.mVec128;
    LODWORD(v23) = &v48;
    btCollisionObject::setWorldTransform((btCollisionObject *)&v47, (btVector3 *)&v48);
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v24, (int)&v30);
    if ( !--v37 )
      break;
    v7 = v36;
  }
  HIDWORD(v23) = &v48.m_worldTransform;
  v25 = vostok::physics::from_bullet(v23, &v47);
  v26 = v36;
  qmemcpy(transform_result, v25, sizeof(vostok::math::float4x4));
  v26->m_dynamicsWorld->removeCollisionObject(v26->m_dynamicsWorld, &v48);
  btPairCachingGhostObject::~btPairCachingGhostObject(&v48);
  return 1;
}
