void __userpurge btGImpactCollisionAlgorithm::gimpact_vs_compoundshape(
        btCollisionObject *body1@<esi>,
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btGImpactShapeInterface *shape0,
        btCompoundShape *shape1,
        bool swapped)
{
  int m_size; // edi
  int v7; // ebx
  btCompoundShapeChild *m_data; // edx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  btCollisionShape *m_childShape; // ecx
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // [esp+94h] [ebp-B4h]
  float v18; // [esp+9Ch] [ebp-ACh]
  float v19; // [esp+A0h] [ebp-A8h]
  float v20; // [esp+A8h] [ebp-A0h]
  float v21; // [esp+B0h] [ebp-98h]
  float v22; // [esp+B4h] [ebp-94h]
  btTransform m_worldTransform; // [esp+B8h] [ebp-90h]
  btVector3 v24; // [esp+108h] [ebp-40h]
  unsigned __int64 v25; // [esp+118h] [ebp-30h]

  m_worldTransform = body1->m_worldTransform;
  m_size = shape1->m_children.m_size;
  if ( m_size )
  {
    v24.mVec128.m128_i32[3] = 0;
    v7 = m_size;
    do
    {
      m_data = shape1->m_children.m_data;
      --m_size;
      v9 = m_data[--v7].m_transform.m_origin.mVec128.m128_f32[2];
      v10 = m_data[v7].m_transform.m_origin.mVec128.m128_f32[1];
      v11 = m_data[v7].m_transform.m_origin.mVec128.m128_f32[0];
      v24.mVec128.m128_f32[0] = (float)((float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v10)
                                              + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v9))
                                      + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v11))
                              + m_worldTransform.m_origin.mVec128.m128_f32[0];
      v12 = m_data[v7].m_transform.m_basis.m_el[0].mVec128.m128_f32[1];
      m_childShape = m_data[v7].m_childShape;
      v24.mVec128.m128_f32[1] = (float)((float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v11)
                                              + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v10))
                                      + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v9))
                              + m_worldTransform.m_origin.mVec128.m128_f32[1];
      v22 = m_data[v7].m_transform.m_basis.m_el[0].mVec128.m128_f32[2];
      v14 = (float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v11)
                  + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v10))
          + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v9);
      v20 = m_data[v7].m_transform.m_basis.m_el[1].mVec128.m128_f32[2];
      v15 = m_data[v7].m_transform.m_basis.m_el[1].mVec128.m128_f32[1];
      v24.mVec128.m128_f32[2] = v14 + m_worldTransform.m_origin.mVec128.m128_f32[2];
      v16 = m_data[v7].m_transform.m_basis.m_el[2].mVec128.m128_f32[2];
      v17 = m_data[v7].m_transform.m_basis.m_el[2].mVec128.m128_f32[1];
      v18 = m_data[v7].m_transform.m_basis.m_el[1].mVec128.m128_f32[0];
      v19 = m_data[v7].m_transform.m_basis.m_el[2].mVec128.m128_f32[0];
      v21 = m_data[v7].m_transform.m_basis.m_el[0].mVec128.m128_f32[0];
      *((float *)&v25 + 1) = (float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v15)
                                   + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v17))
                           + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v12);
      *(float *)&v25 = (float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v18)
                             + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v19))
                     + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v21);
      body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = v25;
      body1->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]
                                                                                    * v20)
                                                                            + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]
                                                                                    * v16))
                                                                    + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                                            * v22));
      body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0] = __PAIR64__(
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                                    * v12)
                                                                            + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                                    * v15))
                                                                    + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                            * v17),
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                                    * v21)
                                                                            + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                                    * v18))
                                                                    + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                            * v19));
      body1->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                                    * v22)
                                                                            + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                                    * v20))
                                                                    + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                            * v16));
      body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                                    * v12)
                                                                            + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                                    * v15))
                                                                    + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                            * v17),
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                                    * v21)
                                                                            + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                                    * v18))
                                                                    + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                            * v19));
      body1->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                                      (float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                                    * v22)
                                                                            + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                                    * v20))
                                                                    + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                            * v16));
      body1->m_worldTransform.m_origin = (btVector3)v24.mVec128;
      btGImpactCollisionAlgorithm::gimpact_vs_shape(this, body0, body1, shape0, m_childShape, swapped);
      body1->m_worldTransform = m_worldTransform;
    }
    while ( m_size );
  }
}
