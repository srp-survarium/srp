void __usercall btCollisionWorld::objectQuerySingle_::_47_::VolumeTester::Process(
        btCollisionWorld::objectQuerySingle::__l47::VolumeTester *this@<esi>,
        int i@<edx>)
{
  btCompoundShapeChild *m_data; // eax
  btCollisionWorld::objectQuerySingle::__l45::input_params *m_input_params; // ebx
  float v4; // xmm5_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  btCompoundShapeChild *v7; // eax
  float *v8; // ecx
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  const btCollisionShape *m_childShape; // edi
  unsigned int v13; // xmm3_4
  unsigned int v14; // xmm4_4
  unsigned int v15; // xmm5_4
  float v16; // xmm7_4
  int v17; // xmm6_4
  btCollisionObject *collisionObject; // eax
  btCollisionShape *m_collisionShape; // ecx
  unsigned int v20; // xmm0_4
  btCollisionWorld::objectQuerySingle::__l45::input_params *v21; // eax
  btCollisionWorld::ConvexResultCallback *v22; // ecx
  unsigned int v23; // [esp+18Ch] [ebp-A4h]
  btCollisionShape *v24; // [esp+18Ch] [ebp-A4h]
  __m128i resultCallback; // [esp+190h] [ebp-A0h] BYREF
  int v26; // [esp+1A0h] [ebp-90h]
  float v27; // [esp+1B4h] [ebp-7Ch]
  float v28; // [esp+1B8h] [ebp-78h]
  float v29; // [esp+1BCh] [ebp-74h]
  __m128i v30; // [esp+1C0h] [ebp-70h] BYREF
  __m128i v31; // [esp+1D0h] [ebp-60h] BYREF
  __m128i v32; // [esp+1E0h] [ebp-50h] BYREF
  btTransform colObjWorldTransform; // [esp+1F0h] [ebp-40h] BYREF

  m_data = this->m_compoundShape->m_children.m_data;
  m_input_params = this->m_input_params;
  v4 = m_data[i].m_transform.m_origin.mVec128.m128_f32[1];
  v5 = m_data[i].m_transform.m_origin.mVec128.m128_f32[0];
  v6 = m_data[i].m_transform.m_origin.mVec128.m128_f32[2];
  v7 = &m_data[i];
  v8 = (float *)this->m_input_params->colObjWorldTransform;
  v9 = v8[1];
  v10 = *v8;
  v11 = v8[2];
  m_childShape = v7->m_childShape;
  *(float *)resultCallback.m128i_i32 = (float)((float)((float)(*v8 * v5) + (float)(v9 * v4)) + (float)(v11 * v6))
                                     + v8[12];
  *(float *)&resultCallback.m128i_i32[1] = (float)((float)((float)(v8[5] * v4) + (float)(v8[6] * v6))
                                                 + (float)(v8[4] * v5))
                                         + v8[13];
  resultCallback.m128i_i64[1] = COERCE_UNSIGNED_INT(
                                  (float)((float)((float)(v8[9] * v4) + (float)(v8[10] * v6)) + (float)(v5 * v8[8]))
                                + v8[14]);
  *(float *)&v13 = (float)((float)(v8[9] * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[2])
                         + (float)(v8[10] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[2]))
                 + (float)(v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[2] * v8[8]);
  *(float *)&v14 = (float)((float)(v8[9] * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[1])
                         + (float)(v8[10] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[1]))
                 + (float)(v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[1] * v8[8]);
  *(float *)&v15 = (float)((float)(v8[9] * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(v8[10] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[0]))
                 + (float)(v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[0] * v8[8]);
  *(float *)&v23 = (float)((float)(v8[5] * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[2])
                         + (float)(v8[6] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[2]))
                 + (float)(v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[2] * v8[4]);
  v16 = v8[5];
  v27 = (float)((float)(v16 * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[1])
              + (float)(v8[6] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[1]))
      + (float)(v8[4] * v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[1]);
  v29 = (float)((float)(v16 * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v8[6] * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[0]))
      + (float)(v8[4] * v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v28 = (float)((float)(v10 * v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[2])
              + (float)(v9 * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[2]))
      + (float)(v11 * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v17 = (float)((float)(v10 * v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v9 * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(v11 * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[1]);
  *(float *)v30.m128i_i32 = (float)((float)(v10 * v7->m_transform.m_basis.m_el[0].mVec128.m128_f32[0])
                                  + (float)(v9 * v7->m_transform.m_basis.m_el[1].mVec128.m128_f32[0]))
                          + (float)(v11 * v7->m_transform.m_basis.m_el[2].mVec128.m128_f32[0]);
  v30.m128i_i64[1] = LODWORD(v28);
  v31.m128i_i64[0] = __PAIR64__(LODWORD(v27), LODWORD(v29));
  v30.m128i_i32[1] = v17;
  colObjWorldTransform.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v30);
  v31.m128i_i64[1] = v23;
  colObjWorldTransform.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v31);
  v32.m128i_i64[0] = __PAIR64__(v14, v15);
  v32.m128i_i64[1] = v13;
  colObjWorldTransform.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v32);
  colObjWorldTransform.m_origin = (btVector3)_mm_load_si128(&resultCallback);
  collisionObject = m_input_params->collisionObject;
  m_collisionShape = collisionObject->m_collisionShape;
  v20 = (unsigned int)clear_value;
  collisionObject->m_collisionShape = m_childShape;
  v21 = this->m_input_params;
  v24 = m_collisionShape;
  v22 = this->m_input_params->resultCallback;
  *(__int64 *)((char *)resultCallback.m128i_i64 + 4) = v20 | 0xFFFF000100000000uLL;
  resultCallback.m128i_i32[3] = (int)v22;
  v26 = i;
  resultCallback.m128i_i32[0] = (int)&`btCollisionWorld::objectQuerySingle'::`46'::LocalInfoAdder::`vftable';
  resultCallback.m128i_i32[1] = LODWORD(v22->m_closestHitFraction);
  btCollisionWorld::objectQuerySingle(
    v21->castShape,
    v21->convexFromTrans,
    v21->convexToTrans,
    v21->collisionObject,
    m_childShape,
    &colObjWorldTransform,
    (btCollisionWorld::ConvexResultCallback *)&resultCallback,
    v21->allowedPenetration);
  this->m_input_params->collisionObject->m_collisionShape = v24;
}
