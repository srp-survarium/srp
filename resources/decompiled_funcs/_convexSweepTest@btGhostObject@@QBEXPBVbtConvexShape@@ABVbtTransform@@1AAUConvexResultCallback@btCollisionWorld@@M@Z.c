void __thiscall btGhostObject::convexSweepTest(
        btGhostObject *this,
        const btGhostObject *castShape,
        btConvexShape *convexFromWorld,
        const btTransform *convexToWorld,
        const btTransform *resultCallback,
        btCollisionWorld::ConvexResultCallback *allowedCcdPenetration)
{
  float *v6; // ebx
  const btConvexShape *v7; // ecx
  int v8; // eax
  btCollisionObject *v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm4_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  int v28; // edi
  int v29; // esi
  int v30; // edx
  int v31; // ecx
  int v32; // eax
  int v33; // edi
  int v34; // esi
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  float v39; // xmm2_4
  float v40; // xmm3_4
  int v41; // edx
  float v42; // xmm1_4
  int v43; // edi
  int j; // ecx
  float v45; // [esp+C20h] [ebp-1A0h]
  int i; // [esp+C38h] [ebp-188h]
  btCollisionObject *v47; // [esp+C3Ch] [ebp-184h]
  float v48; // [esp+C40h] [ebp-180h]
  float v49; // [esp+C44h] [ebp-17Ch]
  float v50; // [esp+C48h] [ebp-178h]
  float v51; // [esp+C4Ch] [ebp-174h]
  float v52; // [esp+C5Ch] [ebp-164h]
  _DWORD v53[2]; // [esp+C60h] [ebp-160h]
  float v54; // [esp+C68h] [ebp-158h]
  int v55; // [esp+C6Ch] [ebp-154h]
  float v56; // [esp+C74h] [ebp-14Ch]
  float v57; // [esp+C78h] [ebp-148h]
  int v58; // [esp+C7Ch] [ebp-144h]
  __m128i v59; // [esp+C80h] [ebp-140h] BYREF
  btVector3 linvel; // [esp+C90h] [ebp-130h] BYREF
  btMatrix3x3 q; // [esp+CA0h] [ebp-120h] BYREF
  btTransform curTrans; // [esp+CD0h] [ebp-F0h] BYREF
  btVector3 temporalAabbMin; // [esp+D10h] [ebp-B0h] BYREF
  btVector3 temporalAabbMax; // [esp+D20h] [ebp-A0h] BYREF
  btTransform transform0; // [esp+D30h] [ebp-90h] BYREF
  btTransform transform1; // [esp+D70h] [ebp-50h] BYREF

  v52 = s_cc_max_allowed_penetration_value;
  transform0 = *convexToWorld;
  v6 = (float *)resultCallback;
  transform1.m_basis.m_el[0].mVec128.m128_u64[0] = resultCallback->m_basis.m_el[0].mVec128.m128_u64[0];
  transform1.m_basis.m_el[0].mVec128.m128_u64[1] = resultCallback->m_basis.m_el[0].mVec128.m128_u64[1];
  transform1.m_basis.m_el[1] = resultCallback->m_basis.m_el[1];
  transform1.m_basis.m_el[2] = resultCallback->m_basis.m_el[2];
  transform1.m_origin.mVec128.m128_u64[0] = resultCallback->m_origin.mVec128.m128_u64[0];
  transform1.m_origin.mVec128.m128_u64[1] = resultCallback->m_origin.mVec128.m128_u64[1];
  btTransformUtil::calculateVelocity(&transform1, &linvel, &q.m_el[1], &transform0, 1.0);
  curTrans.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&curTrans.m_basis.m_el[0].m_floats[2], 0, 12);
  *(unsigned __int64 *)((char *)curTrans.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  memset(&curTrans.m_basis.m_el[1].m_floats[3], 0, 12);
  curTrans.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  memset(&curTrans.m_origin, 0, sizeof(curTrans.m_origin));
  btMatrix3x3::getRotation(&q, (float *)&transform0, (btQuaternion *)&q);
  btMatrix3x3::setRotation(&q, (int)&curTrans);
  btCollisionShape::calculateTemporalAabb(
    &curTrans,
    &temporalAabbMin,
    &temporalAabbMax,
    convexFromWorld,
    &linvel,
    &q.m_el[1],
    v45);
  v7 = (const btConvexShape *)castShape;
  v8 = 0;
  for ( i = 0; i < castShape->m_overlappingObjects.m_size; ++i )
  {
    v9 = *(btCollisionObject **)(*((_DWORD *)&v7[17].btCollisionShape + 3) + 4 * v8);
    v47 = v9;
    if ( allowedCcdPenetration->needsCollision(allowedCcdPenetration, v9->m_broadphaseHandle) )
    {
      v9->m_collisionShape->getAabb(v9->m_collisionShape, &v9->m_worldTransform, &linvel, q.m_el);
      *(float *)&v59.m128i_i32[1] = temporalAabbMin.mVec128.m128_f32[1] + linvel.mVec128.m128_f32[1];
      *(float *)&v59.m128i_i32[2] = temporalAabbMin.mVec128.m128_f32[2] + linvel.mVec128.m128_f32[2];
      v59.m128i_i32[3] = 0;
      *(float *)v59.m128i_i32 = temporalAabbMin.mVec128.m128_f32[0] + linvel.mVec128.m128_f32[0];
      linvel.mVec128 = (__m128)_mm_load_si128(&v59);
      v10 = temporalAabbMax.mVec128.m128_f32[0] + q.m_el[0].mVec128.m128_f32[0];
      q.m_el[1].mVec128.m128_f32[0] = temporalAabbMax.mVec128.m128_f32[0] + q.m_el[0].mVec128.m128_f32[0];
      q.m_el[1].mVec128.m128_f32[1] = temporalAabbMax.mVec128.m128_f32[1] + q.m_el[0].mVec128.m128_f32[1];
      q.m_el[1].mVec128.m128_f32[2] = temporalAabbMax.mVec128.m128_f32[2] + q.m_el[0].mVec128.m128_f32[2];
      v11 = (float)(temporalAabbMax.mVec128.m128_f32[1] + q.m_el[0].mVec128.m128_f32[1]) + *(float *)&v59.m128i_i32[1];
      v12 = (float)(temporalAabbMax.mVec128.m128_f32[1] + q.m_el[0].mVec128.m128_f32[1]) - *(float *)&v59.m128i_i32[1];
      q.m_el[1].mVec128.m128_i32[3] = 0;
      v13 = (float)(temporalAabbMax.mVec128.m128_f32[2] + q.m_el[0].mVec128.m128_f32[2]) + *(float *)&v59.m128i_i32[2];
      v14 = (float)(temporalAabbMax.mVec128.m128_f32[2] + q.m_el[0].mVec128.m128_f32[2]) - *(float *)&v59.m128i_i32[2];
      q.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&q.m_el[1]);
      v15 = v11 * 0.5;
      v16 = v13 * 0.5;
      v17 = (float)(v10 - *(float *)v59.m128i_i32) * 0.5;
      v18 = v6[12];
      v19 = (float)(v10 + *(float *)v59.m128i_i32) * 0.5;
      v20 = convexToWorld->m_origin.mVec128.m128_f32[0];
      v49 = v12 * 0.5;
      v50 = v14 * 0.5;
      v21 = v20 - v19;
      v22 = convexToWorld->m_origin.mVec128.m128_f32[2] - v16;
      v51 = 0.0;
      v23 = v18 - v19;
      v24 = v6[13];
      v25 = convexToWorld->m_origin.mVec128.m128_f32[1] - v15;
      v54 = v22;
      v26 = v24 - v15;
      v27 = v6[14] - v16;
      v55 = 0;
      v48 = v17;
      *(float *)v53 = v21;
      *(float *)&v53[1] = v25;
      if ( v21 <= v17 )
        v28 = 0;
      else
        v28 = 8;
      v56 = -v49;
      if ( (float)-v49 <= v25 )
        v29 = 0;
      else
        v29 = 2;
      if ( v25 <= v49 )
        v30 = 0;
      else
        v30 = 16;
      v57 = -v50;
      if ( (float)-v50 <= v54 )
        v31 = 0;
      else
        v31 = 4;
      if ( v54 <= v50 )
        v32 = 0;
      else
        v32 = 32;
      v58 = ((float)-v17 > v21) | v28 | v29 | v30 | v31 | v32;
      if ( v23 <= v48 )
        v33 = 0;
      else
        v33 = 8;
      if ( v56 <= v26 )
        v34 = 0;
      else
        v34 = 2;
      if ( v26 <= v49 )
        v35 = 0;
      else
        v35 = 16;
      if ( v57 <= v27 )
        v36 = 0;
      else
        v36 = 4;
      if ( v27 <= v50 )
        v37 = 0;
      else
        v37 = 32;
      v38 = ((float)-v17 > v23) | v33 | v34 | v35 | v36 | v37;
      if ( (v38 & v58) == 0 )
      {
        v39 = 0.0;
        v40 = *(float *)&clear_value;
        v41 = 1;
        q.m_el[2].mVec128.m128_f32[2] = v27 - v54;
        q.m_el[2].mVec128.m128_f32[0] = v23 - v21;
        q.m_el[2].mVec128.m128_f32[1] = v26 - v25;
        q.m_el[2].mVec128.m128_i32[3] = 0;
        v42 = *(float *)&clear_value;
        v43 = 2;
        do
        {
          for ( j = 0; j != 3; ++j )
          {
            if ( (v41 & v58) != 0 )
            {
              if ( (float)((float)((float)-*(float *)&v53[j] - (float)(*(float *)((char *)&v48 + j * 4) * v42))
                         / q.m_el[2].mVec128.m128_f32[j]) >= v39 )
                v39 = (float)((float)-*(float *)&v53[j] - (float)(*(float *)((char *)&v48 + j * 4) * v42))
                    / q.m_el[2].mVec128.m128_f32[j];
            }
            else if ( (v41 & v38) != 0
                   && v40 > (float)((float)((float)-*(float *)&v53[j] - (float)(*(float *)((char *)&v48 + j * 4) * v42))
                                  / q.m_el[2].mVec128.m128_f32[j]) )
            {
              v40 = (float)((float)-*(float *)&v53[j] - (float)(*(float *)((char *)&v48 + j * 4) * v42))
                  / q.m_el[2].mVec128.m128_f32[j];
            }
            v41 *= 2;
          }
          --v43;
          v42 = -1.0;
        }
        while ( v43 );
        if ( v40 >= v39 )
          btCollisionWorld::objectQuerySingle(
            convexFromWorld,
            &transform0,
            &transform1,
            v47,
            (btBvhTriangleMeshShape *)v47->m_collisionShape,
            &v47->m_worldTransform,
            allowedCcdPenetration,
            v52);
      }
      v6 = (float *)resultCallback;
    }
    v7 = (const btConvexShape *)castShape;
    v8 = i + 1;
  }
}
