void __thiscall btGImpactCollisionAlgorithm::gimpact_vs_shape(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btStaticPlaneShape *shape0,
        btGImpactShapeInterface *shape1,
        bool swapped)
{
  int *p_m_part1; // esi
  int v8; // eax
  btGImpactCollisionAlgorithm *v9; // ecx
  int m_shapeType; // ecx
  btTransform *v11; // ecx
  btAlignedObjectArray<GrahamVector2> *v12; // ecx
  GIM_ShapeRetriever *v13; // ecx
  char v14; // al
  int m_size; // edi
  int v16; // esi
  btGImpactCollisionAlgorithm *v17; // ecx
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm2_4
  float v33; // xmm2_4
  GIM_ShapeRetriever *v34; // ecx
  btCollisionShape *v35; // [esp+0h] [ebp-330h]
  const float *v36; // [esp+0h] [ebp-330h]
  char v37; // [esp+17h] [ebp-319h]
  float v39; // [esp+1Ch] [ebp-314h]
  float v40; // [esp+20h] [ebp-310h]
  btCollisionShape *v41; // [esp+28h] [ebp-308h]
  float v42; // [esp+2Ch] [ebp-304h]
  btTransform m_worldTransform; // [esp+30h] [ebp-300h] BYREF
  float v44; // [esp+74h] [ebp-2BCh] BYREF
  int v45; // [esp+78h] [ebp-2B8h]
  float v46; // [esp+7Ch] [ebp-2B4h] BYREF
  float v47; // [esp+80h] [ebp-2B0h] BYREF
  float v48; // [esp+84h] [ebp-2ACh] BYREF
  float v49; // [esp+88h] [ebp-2A8h] BYREF
  float v50; // [esp+8Ch] [ebp-2A4h] BYREF
  float v51; // [esp+90h] [ebp-2A0h] BYREF
  float v52; // [esp+94h] [ebp-29Ch] BYREF
  float v53; // [esp+98h] [ebp-298h] BYREF
  btAlignedObjectArray<int> v54; // [esp+9Ch] [ebp-294h] BYREF
  btVector3 v55; // [esp+B0h] [ebp-280h]
  _QWORD v56[4]; // [esp+C0h] [ebp-270h] BYREF
  btVector3 v57; // [esp+E0h] [ebp-250h]
  btCollisionObject v58[2]; // [esp+F0h] [ebp-240h] BYREF
  int (__thiscall ***v59)(_DWORD, int); // [esp+328h] [ebp-8h]

  if ( ((int (__thiscall *)(btStaticPlaneShape *))shape0->__vftable[1].getAngularMotionDisc)(shape0) == 2 )
  {
    p_m_part1 = &this->m_part1;
    if ( !swapped )
      p_m_part1 = &this->m_part0;
    v8 = shape0[1].m_localScaling.mVec128.m128_i32[2];
    for ( *p_m_part1 = v8;
          *p_m_part1;
          btGImpactCollisionAlgorithm::gimpact_vs_shape(
            this,
            body0,
            body1,
            *((btStaticPlaneShape **)&shape0[2].~btStaticPlaneShape + *p_m_part1),
            shape1,
            swapped) )
    {
      --*p_m_part1;
    }
    --*p_m_part1;
  }
  else if ( ((int (__thiscall *)(btStaticPlaneShape *))shape0->__vftable[1].getAngularMotionDisc)(shape0) == 1
         && shape1->m_shapeType == 28 )
  {
    btGImpactCollisionAlgorithm::gimpacttrimeshpart_vs_plane_collision(
      v9,
      (btCollisionObject *)this,
      body0,
      body1,
      shape0,
      (float *)shape1,
      swapped);
  }
  else
  {
    m_shapeType = shape1->m_shapeType;
    if ( m_shapeType == 31 )
    {
      btGImpactCollisionAlgorithm::gimpact_vs_compoundshape(
        (btGImpactCollisionAlgorithm *)0x1F,
        (btCollisionObject *)this,
        body0,
        (btGImpactShapeInterface *)body1,
        (btCompoundShape *)shape0,
        (bool)shape1);
    }
    else
    {
      v11 = (btTransform *)(m_shapeType - 21);
      if ( (unsigned int)v11 > 8 )
      {
        m_worldTransform = body0->m_worldTransform;
        *(btTransform *)v58[0].m_worldTransform.m_origin.mVec128.m128_f32 = body1->m_worldTransform;
        v54.m_ownsMemory = 1;
        memset(&v54.m_size, 0, 12);
        btGImpactCollisionAlgorithm::gimpact_vs_shape_find_pairs(
          &v54,
          v11,
          (btGImpactCollisionAlgorithm *)&m_worldTransform,
          (const btTransform *)&v58[0].m_worldTransform.m_origin,
          (const btTransform *)shape0,
          shape1,
          v35);
        if ( v54.m_size )
        {
          shape0->__vftable[1].calculateSerializeBufferSize(shape0);
          GIM_ShapeRetriever::GIM_ShapeRetriever(
            v13,
            (GIM_ShapeRetriever *)&v58[0].m_hasAnisotropicFriction,
            (btGImpactShapeInterface *)shape0);
          v14 = (char)shape0->__vftable[1].getLocalScaling(shape0);
          m_size = v54.m_size;
          v37 = v14;
          do
          {
            v16 = v54.m_data[--m_size];
            v45 = m_size;
            if ( swapped )
              this->m_triface1 = v16;
            else
              this->m_triface0 = v16;
            v41 = (btCollisionShape *)(**v59)(v59, v16);
            if ( v37 )
            {
              v18 = ((int (__thiscall *)(btStaticPlaneShape *, btVector3 *, int))shape0->__vftable[2].getAabb)(
                      shape0,
                      &v58[0].m_interpolationWorldTransform.m_origin,
                      v16);
              v19 = *(float *)(v18 + 48);
              v20 = *(float *)(v18 + 56);
              v21 = *(float *)(v18 + 20);
              v22 = *(float *)(v18 + 52);
              v55.mVec128.m128_f32[0] = (float)((float)((float)(v19
                                                              * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                      + (float)(v22
                                                              * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                              + (float)(v20 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                                      + m_worldTransform.m_origin.mVec128.m128_f32[0];
              v55.mVec128.m128_f32[2] = (float)((float)((float)(v19
                                                              * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                                                      + (float)(v22
                                                              * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                                              + (float)(v20 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]))
                                      + m_worldTransform.m_origin.mVec128.m128_f32[2];
              v23 = (float)((float)(v19 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(v22 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                  + (float)(v20 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
              v24 = *(float *)(v18 + 24);
              v55.mVec128.m128_i32[3] = 0;
              v25 = *(float *)(v18 + 8);
              v55.mVec128.m128_f32[1] = v23 + m_worldTransform.m_origin.mVec128.m128_f32[1];
              v26 = *(float *)(v18 + 40);
              v40 = v21;
              v27 = *(float *)(v18 + 36);
              v49 = (float)((float)(v25 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                          + (float)(v24 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v26 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
              v28 = *(float *)(v18 + 4);
              v42 = v27;
              v29 = (float)(v28 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                  + (float)(v21 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]);
              v30 = *(float *)(v18 + 16);
              v31 = v29 + (float)(v27 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
              v32 = *(float *)(v18 + 32);
              v47 = v31;
              v39 = v32;
              v33 = *(float *)v18;
              v50 = (float)((float)(*(float *)v18 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                          + (float)(v30 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v39 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
              v52 = (float)((float)(v25 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(v24 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                  + (float)(v26 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
              v53 = (float)((float)(v25 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                          + (float)(v24 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                  + (float)(v26 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
              v51 = (float)((float)(v28 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(v40 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                  + (float)(v42 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
              v44 = (float)((float)(v33 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                          + (float)(v30 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                  + (float)(v39 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
              v46 = (float)((float)(v28 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                          + (float)(v40 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                  + (float)(v42 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
              v48 = (float)((float)(v33 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                          + (float)(v30 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                  + (float)(v39 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
              btMatrix3x3::setValue((btMatrix3x3 *)&v48, (int)v56, &v46, &v53, &v44, &v51, &v52, &v50, &v47, &v49, v36);
              *(_QWORD *)&v58[0].__vftable = v56[0];
              *((_QWORD *)&v58[0].__vftable + 1) = v56[1];
              v58[0].m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = v56[2];
              v58[0].m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = v56[3];
              v58[0].m_worldTransform.m_basis.m_el[1] = (btVector3)v57.mVec128;
              v58[0].m_worldTransform.m_basis.m_el[2] = (btVector3)v55.mVec128;
              btCollisionObject::setWorldTransform(v58, (btVector3 *)body0);
              m_size = v45;
            }
            if ( swapped )
              btGImpactCollisionAlgorithm::shape_vs_shape_collision(v17, (int)this, body1, body0, shape1, v41);
            else
              btGImpactCollisionAlgorithm::shape_vs_shape_collision(v17, (int)this, body0, body1, v41, shape1);
            if ( v37 )
              btCollisionObject::setWorldTransform((btCollisionObject *)&m_worldTransform, (btVector3 *)body0);
          }
          while ( m_size );
          ((void (__thiscall *)(btStaticPlaneShape *))shape0->__vftable[1].serialize)(shape0);
          GIM_ShapeRetriever::~GIM_ShapeRetriever(v34, (int)&v58[0].m_hasAnisotropicFriction);
        }
        btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v12, (int)&v54);
      }
      else
      {
        btGImpactCollisionAlgorithm::gimpact_vs_concave(
          this,
          body1,
          body0,
          (btGImpactShapeInterface *)shape0,
          shape1,
          swapped);
      }
    }
  }
}
