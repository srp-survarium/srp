void __thiscall btGImpactCollisionAlgorithm::collide_sat_triangles(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btCollisionObject *shape0,
        btGImpactMeshShapePart *shape1,
        btVector3 *pairs,
        int *pair_count,
        int a8)
{
  btGImpactMeshShapePart_vtbl *v8; // eax
  const btPrimitiveManagerBase *v10; // eax
  int v11; // eax
  btPrimitiveTriangle *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  unsigned int v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  btGImpactCollisionAlgorithm *v27; // ecx
  int v28; // [esp+2Ch] [ebp-298h]
  int v29; // [esp+2Ch] [ebp-298h]
  int v30; // [esp+2Ch] [ebp-298h]
  const btVector3 *v31; // [esp+30h] [ebp-294h]
  float v32; // [esp+34h] [ebp-290h]
  float v33; // [esp+38h] [ebp-28Ch]
  float v34; // [esp+3Ch] [ebp-288h]
  float v35; // [esp+48h] [ebp-27Ch]
  float v36; // [esp+4Ch] [ebp-278h]
  btPrimitiveTriangle other; // [esp+64h] [ebp-260h] BYREF
  GIM_TRIANGLE_CONTACT contacts; // [esp+B4h] [ebp-210h] BYREF

  contacts.m_points[5] = body1->m_worldTransform.m_basis.m_el[0];
  contacts.m_points[6] = body1->m_worldTransform.m_basis.m_el[1];
  contacts.m_points[7] = body1->m_worldTransform.m_basis.m_el[2];
  contacts.m_points[8] = body1->m_worldTransform.m_origin;
  contacts.m_points[9] = shape0->m_worldTransform.m_basis.m_el[0];
  contacts.m_points[10] = shape0->m_worldTransform.m_basis.m_el[1];
  contacts.m_points[11] = shape0->m_worldTransform.m_basis.m_el[2];
  v8 = shape1->__vftable;
  contacts.m_points[12] = shape0->m_worldTransform.m_origin;
  other.m_margin = FLOAT_0_0099999998;
  contacts.m_points[2].mVec128.m128_f32[0] = FLOAT_0_0099999998;
  v8->lockChildShapes(shape1);
  (*(void (__thiscall **)(btVector3 *))(pairs->mVec128.m128_i32[0] + 104))(pairs);
  while ( a8 )
  {
    --a8;
    body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2] = *pair_count;
    body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0] = pair_count[1];
    v28 = body0->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
    pair_count += 2;
    v10 = shape1->getPrimitiveManager(shape1);
    v10->get_primitive_triangle((btPrimitiveManagerBase *)v10, v28, &other);
    v29 = body0->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
    v11 = (*(int (__thiscall **)(btVector3 *))(pairs->mVec128.m128_i32[0] + 76))(pairs);
    (*(void (__thiscall **)(int, int, GIM_TRIANGLE_CONTACT *))(*(_DWORD *)v11 + 16))(v11, v29, &contacts);
    btPrimitiveTriangle::applyTransform(&other, (const btTransform *)&contacts.m_points[5]);
    btPrimitiveTriangle::applyTransform((btPrimitiveTriangle *)&contacts, (const btTransform *)&contacts.m_points[9]);
    v13 = (float)((float)(other.m_vertices[1].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[2].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2]))
        - (float)((float)(other.m_vertices[1].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[2].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1]));
    v14 = (float)((float)(other.m_vertices[1].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[2].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(other.m_vertices[2].mVec128.m128_f32[2] - other.m_vertices[0].mVec128.m128_f32[2])
                * (float)(other.m_vertices[1].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]));
    v15 = (float)((float)(other.m_vertices[2].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[1].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]))
        - (float)((float)(other.m_vertices[1].mVec128.m128_f32[1] - other.m_vertices[0].mVec128.m128_f32[1])
                * (float)(other.m_vertices[2].mVec128.m128_f32[0] - other.m_vertices[0].mVec128.m128_f32[0]));
    v16 = fsqrt((float)((float)(v13 * v13) + (float)(v15 * v15)) + (float)(v14 * v14));
    v32 = v13 * (float)(s_bm_current_air_resistance / v16);
    v33 = v14 * (float)(s_bm_current_air_resistance / v16);
    v34 = v15 * (float)(s_bm_current_air_resistance / v16);
    other.m_plane.mVec128.m128_f32[2] = v34;
    v17 = (float)((float)(v32 * other.m_vertices[0].mVec128.m128_f32[0])
                + (float)(v33 * other.m_vertices[0].mVec128.m128_f32[1]))
        + (float)(v34 * other.m_vertices[0].mVec128.m128_f32[2]);
    other.m_plane.mVec128.m128_f32[1] = v33;
    contacts.m_points[4].mVec128.m128_f32[0] = contacts.m_points[0].mVec128.m128_f32[0] - contacts.m_penetration_depth;
    other.m_plane.mVec128.m128_f32[0] = v32;
    contacts.m_points[3].mVec128.m128_f32[0] = contacts.m_separating_normal.mVec128.m128_f32[0]
                                             - contacts.m_penetration_depth;
    v18 = (float)((float)(contacts.m_separating_normal.mVec128.m128_f32[2] - *((float *)&contacts.m_point_count + 1))
                * (float)(contacts.m_points[0].mVec128.m128_f32[0] - contacts.m_penetration_depth))
        - (float)((float)(contacts.m_points[0].mVec128.m128_f32[2] - *((float *)&contacts.m_point_count + 1))
                * (float)(contacts.m_separating_normal.mVec128.m128_f32[0] - contacts.m_penetration_depth));
    v19 = (float)((float)(contacts.m_points[0].mVec128.m128_f32[1] - *(float *)&contacts.m_point_count)
                * (float)(contacts.m_separating_normal.mVec128.m128_f32[0] - contacts.m_penetration_depth))
        - (float)((float)(contacts.m_separating_normal.mVec128.m128_f32[1] - *(float *)&contacts.m_point_count)
                * (float)(contacts.m_points[0].mVec128.m128_f32[0] - contacts.m_penetration_depth));
    v20 = (float)((float)(contacts.m_separating_normal.mVec128.m128_f32[1] - *(float *)&contacts.m_point_count)
                * (float)(contacts.m_points[0].mVec128.m128_f32[2] - *((float *)&contacts.m_point_count + 1)))
        - (float)((float)(contacts.m_separating_normal.mVec128.m128_f32[2] - *((float *)&contacts.m_point_count + 1))
                * (float)(contacts.m_points[0].mVec128.m128_f32[1] - *(float *)&contacts.m_point_count));
    v21 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v18 * v18));
    *(float *)&v22 = v18 * (float)(s_bm_current_air_resistance / v21);
    v36 = v19 * (float)(s_bm_current_air_resistance / v21);
    v23 = v20 * (float)(s_bm_current_air_resistance / v21);
    v24 = (float)(v23 * contacts.m_penetration_depth) + (float)(*(float *)&v22 * *(float *)&contacts.m_point_count);
    v35 = *(float *)&v22;
    *(unsigned __int64 *)((char *)contacts.m_points[1].mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v36), v22);
    v25 = contacts.m_points[2].mVec128.m128_f32[0] + other.m_margin;
    v26 = v24 + (float)(v36 * *((float *)&contacts.m_point_count + 1));
    other.m_plane.mVec128.m128_f32[3] = v17;
    contacts.m_points[1].mVec128.m128_f32[0] = v23;
    contacts.m_points[1].mVec128.m128_f32[3] = v26;
    if ( ((float)((float)((float)((float)((float)(contacts.m_penetration_depth * v32)
                                        + (float)(*((float *)&contacts.m_point_count + 1) * v34))
                                + (float)(*(float *)&contacts.m_point_count * v33))
                        - v17)
                - (float)(contacts.m_points[2].mVec128.m128_f32[0] + other.m_margin)) <= 0.0
       || (float)((float)((float)((float)((float)(contacts.m_separating_normal.mVec128.m128_f32[0] * v32)
                                        + (float)(contacts.m_separating_normal.mVec128.m128_f32[2] * v34))
                                + (float)(contacts.m_separating_normal.mVec128.m128_f32[1] * v33))
                        - v17)
                - v25) <= 0.0
       || (float)((float)((float)((float)((float)(contacts.m_points[0].mVec128.m128_f32[0] * v32)
                                        + (float)(contacts.m_points[0].mVec128.m128_f32[2] * v34))
                                + (float)(contacts.m_points[0].mVec128.m128_f32[1] * v33))
                        - v17)
                - v25) <= 0.0)
      && ((float)((float)((float)((float)((float)(v23 * other.m_vertices[0].mVec128.m128_f32[0])
                                        + (float)(v35 * other.m_vertices[0].mVec128.m128_f32[1]))
                                + (float)(v36 * other.m_vertices[0].mVec128.m128_f32[2]))
                        - v26)
                - v25) <= 0.0
       || (float)((float)((float)((float)((float)(other.m_vertices[1].mVec128.m128_f32[0] * v23)
                                        + (float)(other.m_vertices[1].mVec128.m128_f32[2] * v36))
                                + (float)(other.m_vertices[1].mVec128.m128_f32[1] * v35))
                        - v26)
                - v25) <= 0.0
       || (float)((float)((float)((float)((float)(other.m_vertices[2].mVec128.m128_f32[0] * v23)
                                        + (float)(other.m_vertices[2].mVec128.m128_f32[2] * v36))
                                + (float)(other.m_vertices[2].mVec128.m128_f32[1] * v35))
                        - v26)
                - v25) <= 0.0) )
    {
      if ( btPrimitiveTriangle::find_triangle_collision_clip_method(
             v12,
             pairs,
             &other,
             (btPrimitiveTriangle *)&contacts,
             (int *)&contacts.m_points[13]) )
      {
        v30 = contacts.m_points[13].mVec128.m128_i32[1];
        if ( contacts.m_points[13].mVec128.m128_i32[1] )
        {
          v31 = &contacts.m_points[contacts.m_points[13].mVec128.m128_i32[1] + 15];
          do
          {
            --v31;
            --v30;
            btGImpactCollisionAlgorithm::addContactPoint(
              v27,
              (int)body0,
              body1,
              shape0,
              v31,
              &contacts.m_points[14],
              COERCE_FLOAT(contacts.m_points[13].mVec128.m128_i32[0] ^ _mask__NegFloat_));
          }
          while ( v30 );
        }
      }
    }
  }
  shape1->unlockChildShapes(shape1);
  (*(void (__thiscall **)(btVector3 *))(pairs->mVec128.m128_i32[0] + 108))(pairs);
}
