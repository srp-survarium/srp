void __thiscall btCollisionWorld::rayTestSingle_::_32_::RayTester::Process(
        btCollisionWorld::rayTestSingle::__l32::RayTester *this,
        unsigned int i)
{
  btCompoundShapeChild *m_data; // eax
  float v4; // xmm4_4
  float v5; // xmm3_4
  float v6; // xmm5_4
  __int64 v7; // rcx
  float *v8; // eax
  float *m_colObjWorldTransform; // ecx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  unsigned int v14; // xmm3_4
  unsigned int v15; // xmm4_4
  unsigned int v16; // xmm5_4
  int v17; // xmm6_4
  btCollisionObject *m_collisionObject; // eax
  btCollisionShape *m_collisionShape; // ecx
  btCollisionWorld::RayResultCallback *m_resultCallback; // edi
  const btTransform *m_rayToTrans; // edx
  __int64 childWorldTrans_48; // [esp+178h] [ebp-CCh]
  unsigned int v23; // [esp+19Ch] [ebp-A8h]
  btCollisionShape *v24; // [esp+19Ch] [ebp-A8h]
  unsigned int v25; // [esp+1A0h] [ebp-A4h]
  btCollisionWorld::RayResultCallback resultCallback; // [esp+1A4h] [ebp-A0h] BYREF
  btCollisionWorld::RayResultCallback *v27; // [esp+1BCh] [ebp-88h]
  unsigned int v28; // [esp+1C0h] [ebp-84h]
  float v29; // [esp+1CCh] [ebp-78h]
  float v30; // [esp+1D0h] [ebp-74h]
  __m128i v31; // [esp+1D4h] [ebp-70h] BYREF
  __m128i v32; // [esp+1E4h] [ebp-60h] BYREF
  __m128i v33; // [esp+1F4h] [ebp-50h] BYREF
  btTransform colObjWorldTransform; // [esp+204h] [ebp-40h] BYREF

  m_data = this->m_compoundShape->m_children.m_data;
  v4 = m_data[i].m_transform.m_origin.mVec128.m128_f32[2];
  v5 = m_data[i].m_transform.m_origin.mVec128.m128_f32[0];
  v6 = m_data[i].m_transform.m_origin.mVec128.m128_f32[1];
  HIDWORD(v7) = m_data[i].m_childShape;
  v8 = (float *)&m_data[i];
  m_colObjWorldTransform = (float *)this->m_colObjWorldTransform;
  v10 = m_colObjWorldTransform[2];
  v11 = *m_colObjWorldTransform;
  v12 = m_colObjWorldTransform[1];
  *(float *)&resultCallback.__vftable = (float)((float)((float)(v10 * v4) + (float)(*m_colObjWorldTransform * v5))
                                              + (float)(v12 * v6))
                                      + m_colObjWorldTransform[12];
  resultCallback.m_closestHitFraction = (float)((float)((float)(m_colObjWorldTransform[5] * v6)
                                                      + (float)(m_colObjWorldTransform[6] * v4))
                                              + (float)(m_colObjWorldTransform[4] * v5))
                                      + m_colObjWorldTransform[13];
  v13 = (float)((float)((float)(m_colObjWorldTransform[9] * v6) + (float)(m_colObjWorldTransform[10] * v4))
              + (float)(v5 * m_colObjWorldTransform[8]))
      + m_colObjWorldTransform[14];
  *(_DWORD *)&resultCallback.m_collisionFilterGroup = 0;
  *(float *)&resultCallback.m_collisionObject = v13;
  *(float *)&v14 = (float)((float)(m_colObjWorldTransform[9] * v8[6]) + (float)(m_colObjWorldTransform[10] * v8[10]))
                 + (float)(v8[2] * m_colObjWorldTransform[8]);
  *(float *)&v15 = (float)((float)(m_colObjWorldTransform[9] * v8[5]) + (float)(m_colObjWorldTransform[10] * v8[9]))
                 + (float)(v8[1] * m_colObjWorldTransform[8]);
  *(float *)&v16 = (float)((float)(m_colObjWorldTransform[9] * v8[4]) + (float)(m_colObjWorldTransform[10] * v8[8]))
                 + (float)(*v8 * m_colObjWorldTransform[8]);
  *(float *)&v23 = (float)((float)(m_colObjWorldTransform[5] * v8[6]) + (float)(m_colObjWorldTransform[6] * v8[10]))
                 + (float)(v8[2] * m_colObjWorldTransform[4]);
  *(float *)&v25 = (float)((float)(m_colObjWorldTransform[5] * v8[5]) + (float)(m_colObjWorldTransform[6] * v8[9]))
                 + (float)(v8[1] * m_colObjWorldTransform[4]);
  v30 = (float)((float)(m_colObjWorldTransform[5] * v8[4]) + (float)(m_colObjWorldTransform[6] * v8[8]))
      + (float)(m_colObjWorldTransform[4] * *v8);
  v29 = (float)((float)(v11 * v8[2]) + (float)(v12 * v8[6])) + (float)(v10 * v8[10]);
  *(float *)&v17 = (float)((float)(v11 * v8[1]) + (float)(v12 * v8[5])) + (float)(v10 * v8[9]);
  *(float *)v31.m128i_i32 = (float)((float)(v11 * *v8) + (float)(v12 * v8[4])) + (float)(v10 * v8[8]);
  v31.m128i_i32[1] = v17;
  m_collisionObject = this->m_collisionObject;
  v31.m128i_i64[1] = LODWORD(v29);
  v32.m128i_i64[0] = __PAIR64__(v25, LODWORD(v30));
  colObjWorldTransform.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v31);
  v32.m128i_i64[1] = v23;
  colObjWorldTransform.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v32);
  v33.m128i_i64[0] = __PAIR64__(v15, v16);
  v33.m128i_i64[1] = v14;
  colObjWorldTransform.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v33);
  colObjWorldTransform.m_origin = (btVector3)_mm_load_si128((const __m128i *)&resultCallback);
  m_collisionShape = m_collisionObject->m_collisionShape;
  m_collisionObject->m_collisionShape = (btCollisionShape *)HIDWORD(v7);
  m_resultCallback = this->m_resultCallback;
  v24 = m_collisionShape;
  v28 = m_resultCallback->getShapeId(m_resultCallback, i);
  resultCallback.m_shape_id = v28;
  resultCallback.m_collisionFilterGroup = 1;
  resultCallback.m_collisionObject = 0;
  resultCallback.m_flags = 0;
  LODWORD(v7) = this->m_collisionObject;
  resultCallback.m_collisionFilterMask = -1;
  m_rayToTrans = this->m_rayToTrans;
  childWorldTrans_48 = v7;
  LODWORD(v7) = this->m_rayFromTrans;
  LODWORD(resultCallback.m_closestHitFraction) = clear_value;
  resultCallback.__vftable = (btCollisionWorld::RayResultCallback_vtbl *)&`btCollisionWorld::rayTestSingle'::`31'::LocalInfoAdder2::`vftable';
  v27 = m_resultCallback;
  resultCallback.m_closestHitFraction = m_resultCallback->m_closestHitFraction;
  btCollisionWorld::rayTestSingle(
    (const btTransform *)v7,
    &colObjWorldTransform,
    m_rayToTrans,
    (btCollisionObject *)childWorldTrans_48,
    (btBvhTriangleMeshShape *)HIDWORD(childWorldTrans_48),
    &resultCallback);
  this->m_collisionObject->m_collisionShape = v24;
}
