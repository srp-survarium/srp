void __userpurge btGImpactCollisionAlgorithm::gimpacttrimeshpart_vs_plane_collision(
        btStaticPlaneShape *shape1@<eax>,
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btGImpactMeshShapePart *shape0,
        bool swapped)
{
  btCollisionObject *v7; // esi
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  btGImpactMeshShapePart_vtbl *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  double v22; // st7
  int numverts; // edi
  const unsigned __int8 *v24; // eax
  float v25; // xmm3_4
  double v26; // xmm0_8
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // [esp+3D4h] [ebp-D4h]
  float v30; // [esp+3D4h] [ebp-D4h]
  float v31; // [esp+3D4h] [ebp-D4h]
  btVector3 normal; // [esp+3D8h] [ebp-D0h] BYREF
  btVector3 v33; // [esp+3E8h] [ebp-C0h] BYREF
  __m128i v34; // [esp+3F8h] [ebp-B0h] BYREF
  unsigned __int64 v35; // [esp+408h] [ebp-A0h] BYREF
  unsigned __int64 v36; // [esp+410h] [ebp-98h]
  unsigned __int64 v37; // [esp+418h] [ebp-90h] BYREF
  unsigned __int64 v38; // [esp+420h] [ebp-88h]
  btVector3 v39; // [esp+428h] [ebp-80h]
  btVector3 v40; // [esp+438h] [ebp-70h]
  float point_8; // [esp+454h] [ebp-54h]
  btVector3 point_12; // [esp+458h] [ebp-50h] BYREF
  btTransform m_worldTransform; // [esp+468h] [ebp-40h] BYREF

  v7 = body1;
  m_worldTransform = body0->m_worldTransform;
  v35 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v36 = body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v37 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
  v8 = shape1->m_planeNormal.mVec128.m128_f32[2] * *(float *)&v36;
  v38 = body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
  v39.mVec128 = (__m128)body1->m_worldTransform.m_basis.m_el[2];
  v40.mVec128 = (__m128)body1->m_worldTransform.m_origin;
  v9 = (float)((float)(shape1->m_planeNormal.mVec128.m128_f32[1] * *((float *)&v35 + 1)) + v8)
     + (float)(shape1->m_planeNormal.mVec128.m128_f32[0] * *(float *)&v35);
  v10 = shape1->m_planeNormal.mVec128.m128_f32[2] * *(float *)&v38;
  normal.mVec128.m128_f32[0] = v9;
  v11 = (float)((float)(shape1->m_planeNormal.mVec128.m128_f32[1] * *((float *)&v37 + 1)) + v10)
      + (float)(*(float *)&v37 * shape1->m_planeNormal.mVec128.m128_f32[0]);
  v12 = shape1->m_planeNormal.mVec128.m128_f32[2] * v39.mVec128.m128_f32[2];
  v13 = shape0->__vftable;
  normal.mVec128.m128_f32[1] = v11;
  v14 = (float)((float)(shape1->m_planeNormal.mVec128.m128_f32[1] * v39.mVec128.m128_f32[1]) + v12)
      + (float)(v39.mVec128.m128_f32[0] * shape1->m_planeNormal.mVec128.m128_f32[0]);
  v15 = shape1->m_planeNormal.mVec128.m128_f32[2] * v40.mVec128.m128_f32[2];
  normal.mVec128.m128_f32[2] = v14;
  normal.mVec128.m128_f32[3] = (float)((float)((float)(shape1->m_planeNormal.mVec128.m128_f32[1]
                                                     * v40.mVec128.m128_f32[1])
                                             + v15)
                                     + (float)(shape1->m_planeNormal.mVec128.m128_f32[0] * v40.mVec128.m128_f32[0]))
                             + shape1->m_planeConstant;
  v13->getAabb(shape0, &m_worldTransform, (btVector3 *)&v35, (btVector3 *)&v37);
  v29 = shape1->getMargin(shape1);
  *(float *)&v35 = *(float *)&v35 - v29;
  v16 = (float)(*((float *)&v37 + 1) + v29) + (float)(*((float *)&v35 + 1) - v29);
  *((float *)&v35 + 1) = *((float *)&v35 + 1) - v29;
  v17 = (float)((float)(*(float *)&v38 + v29) + (float)(*(float *)&v36 - v29)) * 0.5;
  v18 = v16 * 0.5;
  *((float *)&v37 + 1) = *((float *)&v37 + 1) + v29;
  *(float *)&v38 = *(float *)&v38 + v29;
  v19 = (float)((float)(*(float *)&v37 + v29) + *(float *)&v35) * 0.5;
  *(float *)&v37 = *(float *)&v37 + v29;
  *(float *)&v36 = *(float *)&v36 - v29;
  *(float *)v34.m128i_i32 = *(float *)&v37 - v19;
  *(float *)&v34.m128i_i32[1] = *((float *)&v37 + 1) - v18;
  *(float *)&v34.m128i_i32[2] = *(float *)&v38 - v17;
  v33.mVec128.m128_f32[0] = fabsf(normal.mVec128.m128_f32[0]);
  v33.mVec128.m128_f32[1] = fabsf(normal.mVec128.m128_f32[1]);
  v33.mVec128.m128_f32[2] = fabsf(v14);
  v20 = (float)((float)(v17 * v14) + (float)(v18 * normal.mVec128.m128_f32[1]))
      + (float)(v19 * normal.mVec128.m128_f32[0]);
  v21 = (float)((float)(v33.mVec128.m128_f32[2] * *(float *)&v34.m128i_i32[2])
              + (float)(v33.mVec128.m128_f32[1] * *(float *)&v34.m128i_i32[1]))
      + (float)(v33.mVec128.m128_f32[0] * *(float *)v34.m128i_i32);
  if ( normal.mVec128.m128_f32[3] <= (float)((float)(v21 + v20) + 0.000001)
    && (float)(normal.mVec128.m128_f32[3] + 0.000001) >= (float)(v20 - v21) )
  {
    shape0->lockChildShapes(shape0);
    v30 = shape0->getMargin(shape0);
    v22 = ((double (__thiscall *)(btStaticPlaneShape *))shape1->getMargin)(shape1);
    numverts = shape0->m_primitive_manager.numverts;
    point_8 = v22 + v30;
    if ( numverts )
    {
      v34.m128i_i32[3] = 0;
      do
      {
        v24 = &shape0->m_primitive_manager.vertexbase[--numverts * shape0->m_primitive_manager.stride];
        if ( shape0->m_primitive_manager.type == PHY_DOUBLE )
        {
          v25 = shape0->m_primitive_manager.m_scale.mVec128.m128_f32[0] * *(double *)v24;
          v26 = shape0->m_primitive_manager.m_scale.mVec128.m128_f32[1];
          point_12.mVec128.m128_f32[0] = v25;
          v27 = v26 * *((double *)v24 + 1);
          LODWORD(v26) = shape0->m_primitive_manager.m_scale.mVec128.m128_i32[2];
          point_12.mVec128.m128_f32[1] = v27;
          v28 = *(float *)&v26 * *((double *)v24 + 2);
        }
        else
        {
          v25 = shape0->m_primitive_manager.m_scale.mVec128.m128_f32[0] * *(float *)v24;
          point_12.mVec128.m128_f32[0] = v25;
          v27 = *((float *)v24 + 1) * shape0->m_primitive_manager.m_scale.mVec128.m128_f32[1];
          point_12.mVec128.m128_f32[1] = v27;
          v28 = *((float *)v24 + 2) * shape0->m_primitive_manager.m_scale.mVec128.m128_f32[2];
        }
        *(float *)&v34.m128i_i32[2] = (float)((float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v28)
                                                    + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v27))
                                            + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v25))
                                    + m_worldTransform.m_origin.mVec128.m128_f32[2];
        *(float *)&v34.m128i_i32[1] = (float)((float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v28)
                                                    + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v27))
                                            + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v25))
                                    + m_worldTransform.m_origin.mVec128.m128_f32[1];
        *(float *)v34.m128i_i32 = (float)((float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v28)
                                                + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v27))
                                        + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v25))
                                + m_worldTransform.m_origin.mVec128.m128_f32[0];
        point_12.mVec128 = (__m128)_mm_load_si128(&v34);
        v31 = (float)((float)((float)((float)(*(float *)&v34.m128i_i32[2] * normal.mVec128.m128_f32[2])
                                    + (float)(*(float *)&v34.m128i_i32[1] * normal.mVec128.m128_f32[1]))
                            + (float)(*(float *)v34.m128i_i32 * normal.mVec128.m128_f32[0]))
                    - normal.mVec128.m128_f32[3])
            - point_8;
        if ( v31 < 0.0 )
        {
          if ( swapped )
          {
            v33.mVec128.m128_i32[0] = normal.mVec128.m128_i32[0] ^ 0x80000000;
            v33.mVec128.m128_f32[1] = -normal.mVec128.m128_f32[1];
            v33.mVec128.m128_f32[2] = -normal.mVec128.m128_f32[2];
            v33.mVec128.m128_i32[3] = 0;
            btGImpactCollisionAlgorithm::addContactPoint(
              (btGImpactCollisionAlgorithm *)&point_12,
              (int)this,
              v7,
              body0,
              &point_12,
              &v33,
              v31);
          }
          else
          {
            btGImpactCollisionAlgorithm::addContactPoint(
              (btGImpactCollisionAlgorithm *)&point_12,
              (int)this,
              body0,
              v7,
              &point_12,
              &normal,
              v31);
          }
          v7 = body1;
        }
      }
      while ( numverts );
    }
    shape0->unlockChildShapes(shape0);
  }
}
