void __thiscall btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btGImpactMeshShapePart *shape0,
        btGImpactMeshShapePart *shape1)
{
  btGImpactMeshShapePart *v5; // edi
  btStridingMeshInterface *m_meshInterface; // eax
  btPairSet *v8; // ecx
  btStridingMeshInterface *v9; // eax
  btPairSet *v10; // ecx
  btPairSet *v11; // ecx
  GIM_ShapeRetriever *v12; // ecx
  btGImpactMeshShapePart *v13; // esi
  int m_size; // eax
  GIM_PAIR *m_data; // ecx
  int m_index1; // edx
  int m_index2; // eax
  GIM_ShapeRetriever::ChildShapeRetriever *m_current_retriever; // ecx
  btCollisionShape *v19; // esi
  float *v20; // eax
  float v21; // xmm5_4
  float v22; // xmm2_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  unsigned int v25; // xmm5_4
  float v26; // xmm7_4
  __m128i v27; // xmm0
  float *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  GIM_ShapeRetriever *v35; // ecx
  GIM_ShapeRetriever *v36; // ecx
  bool v37; // [esp+22FEh] [ebp-4D6h]
  bool v38; // [esp+22FFh] [ebp-4D5h]
  float v39; // [esp+2300h] [ebp-4D4h]
  float v40; // [esp+2304h] [ebp-4D0h]
  float v41; // [esp+2308h] [ebp-4CCh]
  float v42; // [esp+230Ch] [ebp-4C8h]
  float v43; // [esp+2310h] [ebp-4C4h]
  float v44; // [esp+2314h] [ebp-4C0h]
  float v45; // [esp+2318h] [ebp-4BCh]
  float v46; // [esp+231Ch] [ebp-4B8h]
  float v47; // [esp+2320h] [ebp-4B4h]
  float v48; // [esp+232Ch] [ebp-4A8h]
  float v49; // [esp+2330h] [ebp-4A4h]
  int v50; // [esp+2334h] [ebp-4A0h]
  float v51; // [esp+233Ch] [ebp-498h]
  float v52; // [esp+2340h] [ebp-494h]
  __m128i v53; // [esp+2344h] [ebp-490h] BYREF
  __m128i v54; // [esp+2354h] [ebp-480h] BYREF
  __m128i v55; // [esp+2364h] [ebp-470h] BYREF
  btTransform trans1; // [esp+2374h] [ebp-460h] BYREF
  btTransform trans0; // [esp+23B4h] [ebp-420h] BYREF
  float v58; // [esp+23F4h] [ebp-3E0h]
  float v59; // [esp+23F8h] [ebp-3DCh]
  float v60; // [esp+23FCh] [ebp-3D8h]
  btCollisionShape *v61; // [esp+2400h] [ebp-3D4h]
  float v62; // [esp+2404h] [ebp-3D0h]
  float v63; // [esp+2408h] [ebp-3CCh]
  float v64; // [esp+240Ch] [ebp-3C8h]
  btPairSet v65; // [esp+2410h] [ebp-3C4h] BYREF
  int v66; // [esp+2424h] [ebp-3B0h]
  float v67; // [esp+2428h] [ebp-3ACh]
  float v68; // [esp+242Ch] [ebp-3A8h]
  float v69; // [esp+2430h] [ebp-3A4h]
  __m128i v70; // [esp+2434h] [ebp-3A0h] BYREF
  __m128i v71; // [esp+2444h] [ebp-390h] BYREF
  btTransform worldTrans; // [esp+2454h] [ebp-380h] BYREF
  btTransform v73; // [esp+2494h] [ebp-340h] BYREF
  GIM_ShapeRetriever v74; // [esp+24D4h] [ebp-300h] BYREF
  GIM_ShapeRetriever v75; // [esp+2654h] [ebp-180h] BYREF

  v5 = shape0;
  if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE )
  {
    m_meshInterface = shape0->m_primitive_manager.m_meshInterface;
    for ( this->m_part0 = (int)m_meshInterface;
          this->m_part0;
          btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
            this,
            body0,
            body1,
            *(btGImpactShapeInterface **)(shape0->m_primitive_manager.m_scale.mVec128.m128_i32[0] + 4 * this->m_part0),
            shape1) )
    {
      --this->m_part0;
    }
    --this->m_part0;
  }
  else if ( shape1->getGImpactShapeType(shape1) == CONST_GIMPACT_TRIMESH_SHAPE )
  {
    v9 = shape1->m_primitive_manager.m_meshInterface;
    for ( this->m_part1 = (int)v9;
          this->m_part1;
          btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
            this,
            body0,
            body1,
            shape0,
            *(btGImpactShapeInterface **)(shape1->m_primitive_manager.m_scale.mVec128.m128_i32[0] + 4 * this->m_part1)) )
    {
      --this->m_part1;
    }
    --this->m_part1;
  }
  else
  {
    trans0 = body0->m_worldTransform;
    trans1 = body1->m_worldTransform;
    btPairSet::btPairSet(v8, &v65);
    btGImpactCollisionAlgorithm::gimpact_vs_gimpact_find_pairs(
      (btGImpactCollisionAlgorithm *)&trans0,
      &trans0,
      &trans1,
      shape0,
      shape1,
      &v65);
    if ( v65.m_size )
    {
      if ( shape0->getGImpactShapeType(shape0) == CONST_GIMPACT_TRIMESH_SHAPE_PART
        && shape1->getGImpactShapeType(shape1) == CONST_GIMPACT_TRIMESH_SHAPE_PART )
      {
        btGImpactCollisionAlgorithm::collide_sat_triangles(
          (btGImpactCollisionAlgorithm *)body0,
          (int)this,
          body0,
          body1,
          shape0,
          shape1,
          &v65.m_data->m_index1,
          v65.m_size);
        btPairSet::~btPairSet(v11, (int)&v65);
        return;
      }
      shape0->lockChildShapes(shape0);
      shape1->lockChildShapes(shape1);
      GIM_ShapeRetriever::GIM_ShapeRetriever(v12, &v75, shape0);
      GIM_ShapeRetriever::GIM_ShapeRetriever((GIM_ShapeRetriever *)shape1, &v74, shape1);
      v13 = shape1;
      v38 = shape0->childrenHasTransform(shape0);
      v37 = shape1->childrenHasTransform(shape1);
      m_size = v65.m_size;
      if ( v65.m_size )
      {
        while ( 1 )
        {
          m_data = v65.m_data;
          m_index1 = v65.m_data[m_size - 1].m_index1;
          v50 = m_size - 1;
          this->m_triface0 = m_index1;
          m_index2 = m_data[m_size - 1].m_index2;
          m_current_retriever = v75.m_current_retriever;
          this->m_triface1 = m_index2;
          v19 = (btCollisionShape *)m_current_retriever->getChildShape(m_current_retriever, m_index1);
          v61 = v74.m_current_retriever->getChildShape(v74.m_current_retriever, this->m_triface1);
          if ( v38 )
          {
            v20 = (float *)v5->getChildTransform(v5, &v73, this->m_triface0);
            v21 = v20[13];
            v22 = v20[14];
            v58 = v20[12];
            *(float *)v71.m128i_i32 = (float)((float)((float)(trans0.m_basis.m_el[0].mVec128.m128_f32[0] * v58)
                                                    + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[1] * v21))
                                            + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[2] * v22))
                                    + trans0.m_origin.mVec128.m128_f32[0];
            *(float *)&v71.m128i_i32[1] = (float)((float)((float)(trans0.m_basis.m_el[1].mVec128.m128_f32[0] * v58)
                                                        + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[1] * v21))
                                                + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[2] * v22))
                                        + trans0.m_origin.mVec128.m128_f32[1];
            v67 = v22;
            v23 = v20[2];
            *(float *)&v71.m128i_i32[2] = (float)((float)((float)(trans0.m_basis.m_el[2].mVec128.m128_f32[0] * v58)
                                                        + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[1] * v21))
                                                + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[2] * v22))
                                        + trans0.m_origin.mVec128.m128_f32[2];
            v24 = v20[6];
            v71.m128i_i32[3] = 0;
            v44 = v20[10];
            v51 = v23;
            *(float *)&v25 = (float)((float)(trans0.m_basis.m_el[2].mVec128.m128_f32[0] * v23)
                                   + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[1] * v24))
                           + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[2] * v44);
            v42 = v20[9];
            v47 = v20[5];
            v49 = v20[1];
            v68 = (float)((float)(trans0.m_basis.m_el[2].mVec128.m128_f32[0] * v49)
                        + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[1] * v47))
                + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[2] * v42);
            v26 = v20[4];
            v46 = v20[8];
            v52 = *v20;
            v63 = (float)((float)(trans0.m_basis.m_el[2].mVec128.m128_f32[0] * *v20)
                        + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[1] * v26))
                + (float)(trans0.m_basis.m_el[2].mVec128.m128_f32[2] * v46);
            v69 = (float)((float)(trans0.m_basis.m_el[1].mVec128.m128_f32[0] * v52)
                        + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[1] * v26))
                + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[2] * v46);
            v60 = (float)((float)(trans0.m_basis.m_el[1].mVec128.m128_f32[0] * v49)
                        + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[1] * v47))
                + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[2] * v42);
            *(float *)&v53.m128i_i32[1] = (float)((float)(trans0.m_basis.m_el[0].mVec128.m128_f32[0] * v49)
                                                + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[1] * v47))
                                        + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[2] * v42);
            *(float *)v54.m128i_i32 = v69;
            *(float *)&v54.m128i_i32[1] = v60;
            *(float *)v53.m128i_i32 = (float)((float)(trans0.m_basis.m_el[0].mVec128.m128_f32[0] * v52)
                                            + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[1] * v26))
                                    + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[2] * v46);
            *(float *)v55.m128i_i32 = v63;
            *(float *)&v53.m128i_i32[2] = (float)((float)(trans0.m_basis.m_el[0].mVec128.m128_f32[0] * v51)
                                                + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[1] * v24))
                                        + (float)(trans0.m_basis.m_el[0].mVec128.m128_f32[2] * v44);
            v53.m128i_i32[3] = 0;
            v27 = _mm_load_si128(&v53);
            v54.m128i_i64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)(trans0.m_basis.m_el[1].mVec128.m128_f32[0] * v51)
                                       + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[1] * v24))
                               + (float)(trans0.m_basis.m_el[1].mVec128.m128_f32[2] * v44));
            *(float *)&v55.m128i_i32[1] = v68;
            v55.m128i_i64[1] = v25;
            worldTrans.m_basis.m_el[0] = (btVector3)v27;
            worldTrans.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v54);
            worldTrans.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v55);
            worldTrans.m_origin = (btVector3)_mm_load_si128(&v71);
            btCollisionObject::setWorldTransform(body0, &worldTrans);
          }
          if ( v37 )
          {
            v28 = (float *)shape1->getChildTransform(shape1, &v73, this->m_triface1);
            v29 = v28[14];
            v30 = v28[13];
            v31 = v28[12];
            *(float *)v70.m128i_i32 = (float)((float)((float)(trans1.m_basis.m_el[0].mVec128.m128_f32[1] * v30)
                                                    + (float)(trans1.m_basis.m_el[0].mVec128.m128_f32[2] * v29))
                                            + (float)(v31 * trans1.m_basis.m_el[0].mVec128.m128_f32[0]))
                                    + trans1.m_origin.mVec128.m128_f32[0];
            *(float *)&v70.m128i_i32[1] = (float)((float)((float)(v31 * trans1.m_basis.m_el[1].mVec128.m128_f32[0])
                                                        + (float)(v30 * trans1.m_basis.m_el[1].mVec128.m128_f32[1]))
                                                + (float)(v29 * trans1.m_basis.m_el[1].mVec128.m128_f32[2]))
                                        + trans1.m_origin.mVec128.m128_f32[1];
            v32 = v28[6];
            *(float *)&v70.m128i_i32[2] = (float)((float)((float)(v31 * trans1.m_basis.m_el[2].mVec128.m128_f32[0])
                                                        + (float)(v30 * trans1.m_basis.m_el[2].mVec128.m128_f32[1]))
                                                + (float)(v29 * trans1.m_basis.m_el[2].mVec128.m128_f32[2]))
                                        + trans1.m_origin.mVec128.m128_f32[2];
            v70.m128i_i32[3] = 0;
            v40 = v28[10];
            v33 = v28[2];
            v43 = v28[9];
            v41 = v28[5];
            v34 = v28[1];
            v39 = v28[8];
            v45 = v28[4];
            v48 = *v28;
            v59 = (float)((float)(*v28 * trans1.m_basis.m_el[2].mVec128.m128_f32[0])
                        + (float)(v45 * trans1.m_basis.m_el[2].mVec128.m128_f32[1]))
                + (float)(v39 * trans1.m_basis.m_el[2].mVec128.m128_f32[2]);
            v64 = (float)((float)(v33 * trans1.m_basis.m_el[1].mVec128.m128_f32[0])
                        + (float)(v32 * trans1.m_basis.m_el[1].mVec128.m128_f32[1]))
                + (float)(v40 * trans1.m_basis.m_el[1].mVec128.m128_f32[2]);
            *(float *)&v66 = (float)((float)(v34 * trans1.m_basis.m_el[1].mVec128.m128_f32[0])
                                   + (float)(v41 * trans1.m_basis.m_el[1].mVec128.m128_f32[1]))
                           + (float)(v43 * trans1.m_basis.m_el[1].mVec128.m128_f32[2]);
            v62 = (float)((float)(v48 * trans1.m_basis.m_el[1].mVec128.m128_f32[0])
                        + (float)(v45 * trans1.m_basis.m_el[1].mVec128.m128_f32[1]))
                + (float)(v39 * trans1.m_basis.m_el[1].mVec128.m128_f32[2]);
            *(float *)v53.m128i_i32 = (float)((float)(trans1.m_basis.m_el[0].mVec128.m128_f32[1] * v45)
                                            + (float)(trans1.m_basis.m_el[0].mVec128.m128_f32[2] * v39))
                                    + (float)(v48 * trans1.m_basis.m_el[0].mVec128.m128_f32[0]);
            *(float *)v54.m128i_i32 = v62;
            v54.m128i_i32[1] = v66;
            *(float *)&v53.m128i_i32[1] = (float)((float)(trans1.m_basis.m_el[0].mVec128.m128_f32[1] * v41)
                                                + (float)(trans1.m_basis.m_el[0].mVec128.m128_f32[2] * v43))
                                        + (float)(v34 * trans1.m_basis.m_el[0].mVec128.m128_f32[0]);
            v54.m128i_i64[1] = LODWORD(v64);
            v53.m128i_i64[1] = COERCE_UNSIGNED_INT(
                                 (float)((float)(trans1.m_basis.m_el[0].mVec128.m128_f32[1] * v32)
                                       + (float)(trans1.m_basis.m_el[0].mVec128.m128_f32[2] * v40))
                               + (float)(v33 * trans1.m_basis.m_el[0].mVec128.m128_f32[0]));
            *(float *)v55.m128i_i32 = (float)((float)(v48 * trans1.m_basis.m_el[2].mVec128.m128_f32[0])
                                            + (float)(v45 * trans1.m_basis.m_el[2].mVec128.m128_f32[1]))
                                    + (float)(v39 * trans1.m_basis.m_el[2].mVec128.m128_f32[2]);
            *(float *)&v55.m128i_i32[1] = (float)((float)(v34 * trans1.m_basis.m_el[2].mVec128.m128_f32[0])
                                                + (float)(v41 * trans1.m_basis.m_el[2].mVec128.m128_f32[1]))
                                        + (float)(v43 * trans1.m_basis.m_el[2].mVec128.m128_f32[2]);
            *(float *)&v55.m128i_i32[2] = (float)((float)(v33 * trans1.m_basis.m_el[2].mVec128.m128_f32[0])
                                                + (float)(v32 * trans1.m_basis.m_el[2].mVec128.m128_f32[1]))
                                        + (float)(v40 * trans1.m_basis.m_el[2].mVec128.m128_f32[2]);
            v55.m128i_i32[3] = 0;
            worldTrans.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v53);
            worldTrans.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v54);
            worldTrans.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v55);
            worldTrans.m_origin = (btVector3)_mm_load_si128(&v70);
            btCollisionObject::setWorldTransform(body1, &worldTrans);
          }
          btGImpactCollisionAlgorithm::convex_vs_convex_collision(this, body1, v19, v61, body0);
          if ( v38 )
            btCollisionObject::setWorldTransform(body0, &trans0);
          if ( v37 )
            btCollisionObject::setWorldTransform(body1, &trans1);
          v5 = shape0;
          if ( !v50 )
            break;
          m_size = v50;
        }
        v13 = shape1;
      }
      v5->unlockChildShapes(v5);
      v13->unlockChildShapes(v13);
      GIM_ShapeRetriever::~GIM_ShapeRetriever(v35, &v74);
      GIM_ShapeRetriever::~GIM_ShapeRetriever(v36, &v75);
    }
    btPairSet::~btPairSet(v10, (int)&v65);
  }
}
