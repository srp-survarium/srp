char __userpurge btSoftBody::checkContact@<al>(
        btSoftBody *this@<edx>,
        btSoftBody::sCti *cti@<edi>,
        btCollisionObject *colObj,
        const btVector3 *x,
        float margin)
{
  btCollisionShape *m_collisionShape; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  int v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  int v13; // xmm4_4
  int v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  btSparseSdf<3> *p_m_sparsesdf; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  unsigned int v22; // xmm5_4
  btVector3 v24; // [esp+48h] [ebp-50h] BYREF
  btVector3 normal; // [esp+58h] [ebp-40h] BYREF
  float v26; // [esp+78h] [ebp-20h]
  float v27; // [esp+7Ch] [ebp-1Ch]
  float v28; // [esp+88h] [ebp-10h]
  float v29; // [esp+8Ch] [ebp-Ch]

  m_collisionShape = colObj->m_collisionShape;
  v6 = x->mVec128.m128_f32[0] - colObj->m_worldTransform.m_origin.mVec128.m128_f32[0];
  v7 = x->mVec128.m128_f32[2] - colObj->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v8 = colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
  v9 = x->mVec128.m128_f32[1] - colObj->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v10 = colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
  v11 = colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
  v12 = colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v7;
  v26 = colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
  v13 = colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1];
  v28 = *(float *)&v8;
  v14 = colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2];
  v27 = *(float *)&v13;
  v15 = colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v29 = *(float *)&v14;
  v16 = colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v7;
  v24.mVec128.m128_f32[0] = (float)(v12 + (float)(v10 * v6)) + (float)(v11 * v9);
  p_m_sparsesdf = &this->m_worldInfo->m_sparsesdf;
  v24.mVec128.m128_f32[1] = (float)((float)(v15 * v7) + (float)(v26 * v6)) + (float)(v27 * v9);
  v24.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(v16 + (float)(v28 * v6)) + (float)(v29 * v9));
  v18 = btSparseSdf<3>::Evaluate(p_m_sparsesdf, &v24, m_collisionShape, &normal, margin);
  if ( v18 >= 0.0 )
    return 0;
  v19 = normal.mVec128.m128_f32[1];
  v20 = normal.mVec128.m128_f32[2];
  cti->m_colObj = colObj;
  v21 = colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
  v24.mVec128.m128_f32[0] = (float)((float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v19)
                                  + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v20))
                          + (float)(colObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                  * normal.mVec128.m128_f32[0]);
  v24.mVec128.m128_f32[1] = (float)((float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v19)
                                  + (float)(v21 * v20))
                          + (float)(colObj->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                  * normal.mVec128.m128_f32[0]);
  *(float *)&v22 = (float)((float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v19)
                         + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v20))
                 + (float)(colObj->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * normal.mVec128.m128_f32[0]);
  cti->m_normal.mVec128.m128_u64[0] = v24.mVec128.m128_u64[0];
  v24.mVec128.m128_u64[1] = v22;
  cti->m_normal.mVec128.m128_u64[1] = v22;
  cti->m_offset = -(float)((float)((float)(cti->m_normal.mVec128.m128_f32[2]
                                         * (float)(x->mVec128.m128_f32[2]
                                                 - (float)(cti->m_normal.mVec128.m128_f32[2] * v18)))
                                 + (float)(cti->m_normal.mVec128.m128_f32[1]
                                         * (float)(x->mVec128.m128_f32[1]
                                                 - (float)(cti->m_normal.mVec128.m128_f32[1] * v18))))
                         + (float)((float)(x->mVec128.m128_f32[0] - (float)(cti->m_normal.mVec128.m128_f32[0] * v18))
                                 * cti->m_normal.mVec128.m128_f32[0]));
  return 1;
}
