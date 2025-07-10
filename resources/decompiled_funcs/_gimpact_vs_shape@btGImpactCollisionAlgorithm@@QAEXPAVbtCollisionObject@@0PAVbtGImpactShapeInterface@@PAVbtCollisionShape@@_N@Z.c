void __thiscall btGImpactCollisionAlgorithm::gimpact_vs_shape(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btGImpactMeshShapePart *shape0,
        btStaticPlaneShape *shape1,
        bool swapped)
{
  int *p_m_part1; // esi
  btStridingMeshInterface *m_meshInterface; // eax
  int m_shapeType; // ecx
  btPairSet *v10; // ecx
  GIM_ShapeRetriever *v11; // ecx
  int i; // eax
  int v13; // esi
  btCollisionShape *v14; // eax
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  int v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  unsigned int v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  __m128i v27; // xmm0
  GIM_ShapeRetriever *v28; // ecx
  btGImpactShapeInterface *v29; // [esp+11EAh] [ebp-320h]
  bool v30; // [esp+1201h] [ebp-309h]
  float v32; // [esp+1206h] [ebp-304h]
  float v33; // [esp+120Ah] [ebp-300h]
  float v34; // [esp+120Eh] [ebp-2FCh]
  float v35; // [esp+1212h] [ebp-2F8h]
  int v36; // [esp+1216h] [ebp-2F4h]
  btTransform m_worldTransform; // [esp+121Ah] [ebp-2F0h] BYREF
  float v38; // [esp+125Eh] [ebp-2ACh]
  btAlignedObjectArray<int> collided_primitives; // [esp+1262h] [ebp-2A8h] BYREF
  btCollisionShape *v40; // [esp+1276h] [ebp-294h]
  float v41; // [esp+127Ah] [ebp-290h]
  float v42; // [esp+127Eh] [ebp-28Ch]
  int v43; // [esp+1282h] [ebp-288h]
  float v44; // [esp+1286h] [ebp-284h]
  __m128i v45; // [esp+128Ah] [ebp-280h] BYREF
  __m128i v46; // [esp+129Ah] [ebp-270h] BYREF
  __m128i v47; // [esp+12AAh] [ebp-260h] BYREF
  __m128i v48; // [esp+12BAh] [ebp-250h] BYREF
  btTransform trans0; // [esp+12CAh] [ebp-240h] BYREF
  btTransform worldTrans; // [esp+130Ah] [ebp-200h] BYREF
  _BYTE v51[64]; // [esp+134Ah] [ebp-1C0h] BYREF
  GIM_ShapeRetriever v52; // [esp+138Ah] [ebp-180h] BYREF

  if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE )
  {
    p_m_part1 = &this->m_part1;
    if ( !swapped )
      p_m_part1 = &this->m_part0;
    m_meshInterface = shape0->m_primitive_manager.m_meshInterface;
    *p_m_part1 = (int)m_meshInterface;
    if ( m_meshInterface )
    {
      do
      {
        --*p_m_part1;
        btGImpactCollisionAlgorithm::gimpact_vs_shape(
          this,
          body0,
          body1,
          *(btGImpactShapeInterface **)(shape0->m_primitive_manager.m_scale.mVec128.m128_i32[0] + 4 * *p_m_part1),
          shape1,
          swapped);
      }
      while ( *p_m_part1 );
    }
    --*p_m_part1;
  }
  else if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE_PART && shape1->m_shapeType == 28 )
  {
    btGImpactCollisionAlgorithm::gimpacttrimeshpart_vs_plane_collision(shape1, this, body0, body1, shape0, swapped);
  }
  else
  {
    m_shapeType = shape1->m_shapeType;
    if ( m_shapeType == 31 )
    {
      btGImpactCollisionAlgorithm::gimpact_vs_compoundshape(
        body1,
        this,
        body0,
        shape0,
        (btCompoundShape *)shape1,
        swapped);
    }
    else if ( (unsigned int)(m_shapeType - 21) > 8 )
    {
      m_worldTransform = body0->m_worldTransform;
      trans0 = body1->m_worldTransform;
      collided_primitives.m_ownsMemory = 1;
      memset(&collided_primitives.m_size, 0, 12);
      btGImpactCollisionAlgorithm::gimpact_vs_shape_find_pairs(
        shape1,
        &collided_primitives,
        (btGImpactCollisionAlgorithm *)&m_worldTransform,
        &trans0,
        shape0,
        v29);
      if ( collided_primitives.m_size )
      {
        shape0->lockChildShapes(shape0);
        GIM_ShapeRetriever::GIM_ShapeRetriever(v11, &v52, shape0);
        v30 = shape0->childrenHasTransform(shape0);
        for ( i = collided_primitives.m_size; ; i = v36 )
        {
          v13 = collided_primitives.m_data[i - 1];
          v36 = i - 1;
          if ( swapped )
            this->m_triface1 = v13;
          else
            this->m_triface0 = v13;
          v14 = v52.m_current_retriever->getChildShape(v52.m_current_retriever, v13);
          v40 = v14;
          if ( v30 )
          {
            v15 = (float *)shape0->getChildTransform(shape0, v51, v13);
            v16 = v15[12];
            v17 = v15[14];
            v18 = v15[13] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
            v19 = v15[13] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
            *(float *)v48.m128i_i32 = (float)((float)((float)(v16 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                    + (float)(v15[13]
                                                            * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                            + (float)(v17 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                                    + m_worldTransform.m_origin.mVec128.m128_f32[0];
            *(float *)&v48.m128i_i32[2] = (float)((float)((float)(v16
                                                                * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                                                        + v19)
                                                + (float)(v17 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]))
                                        + m_worldTransform.m_origin.mVec128.m128_f32[2];
            *(float *)&v20 = (float)((float)((float)(v16 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]) + v18)
                                   + (float)(v17 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]))
                           + m_worldTransform.m_origin.mVec128.m128_f32[1];
            v21 = v15[6];
            v48.m128i_i32[3] = 0;
            v22 = v15[2];
            v48.m128i_i32[1] = v20;
            v23 = v15[10];
            *(float *)&v24 = (float)((float)(v22 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                                   + (float)(v21 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                           + (float)(v23 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
            v32 = v15[9];
            v35 = v15[5];
            v25 = v15[1];
            *(float *)&v43 = (float)((float)(v25 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                                   + (float)(v35 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                           + (float)(v32 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
            v33 = v15[8];
            v34 = v15[4];
            v26 = *v15;
            v44 = (float)((float)(*v15 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                        + (float)(v34 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                + (float)(v33 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
            v38 = (float)((float)(v22 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                        + (float)(v21 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                + (float)(v23 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
            v41 = (float)((float)(v25 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                        + (float)(v35 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                + (float)(v32 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
            v42 = (float)((float)(v26 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                        + (float)(v34 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                + (float)(v33 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
            *(float *)&v45.m128i_i32[1] = (float)((float)(v25 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                + (float)(v35 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                        + (float)(v32 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
            *(float *)v46.m128i_i32 = v42;
            *(float *)&v46.m128i_i32[1] = v41;
            v45.m128i_i64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)(v22 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                       + (float)(v21 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                               + (float)(v23 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]));
            v46.m128i_i64[1] = LODWORD(v38);
            *(float *)v45.m128i_i32 = (float)((float)(v26 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                            + (float)(v34 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(v33 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
            *(float *)v47.m128i_i32 = v44;
            v27 = _mm_load_si128(&v45);
            v47.m128i_i32[1] = v43;
            v47.m128i_i64[1] = v24;
            worldTrans.m_basis.m_el[0] = (btVector3)v27;
            worldTrans.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v46);
            worldTrans.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v47);
            worldTrans.m_origin = (btVector3)_mm_load_si128(&v48);
            btCollisionObject::setWorldTransform(body0, &worldTrans);
            v14 = v40;
          }
          if ( swapped )
            btGImpactCollisionAlgorithm::shape_vs_shape_collision(this, shape1, body1, body0, v14);
          else
            btGImpactCollisionAlgorithm::shape_vs_shape_collision(this, v14, body0, body1, shape1);
          if ( v30 )
            btCollisionObject::setWorldTransform(body0, &m_worldTransform);
          if ( !v36 )
            break;
        }
        shape0->unlockChildShapes(shape0);
        GIM_ShapeRetriever::~GIM_ShapeRetriever(v28, &v52);
      }
      btPairSet::~btPairSet(v10, (int)&collided_primitives);
    }
    else
    {
      btGImpactCollisionAlgorithm::gimpact_vs_concave(this, body0, shape1, swapped, body1, shape0);
    }
  }
}
