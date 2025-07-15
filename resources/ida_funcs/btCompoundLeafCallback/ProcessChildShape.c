void __userpurge btCompoundLeafCallback::ProcessChildShape(
        btCompoundLeafCallback *this@<esi>,
        int index@<edi>,
        btCollisionShape *childShape)
{
  btCollisionObject *m_compoundColObj; // eax
  btCollisionShape *m_collisionShape; // edx
  float *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  void (__thiscall *getAabb)(btCollisionShape *, const btTransform *, btVector3 *, btVector3 *); // eax
  __m128i v16; // xmm0
  char v17; // al
  btCollisionShape *v18; // ebx
  btManifoldResult_vtbl *v19; // edx
  btCollisionAlgorithm *v20; // ecx
  const btDispatcherInfo *m_dispatchInfo; // eax
  const btDispatcherInfo *v22; // ecx
  const btDispatcherInfo *v23; // eax
  float v24; // [esp+4D8h] [ebp-168h]
  float v25; // [esp+4DCh] [ebp-164h]
  __m128i v26; // [esp+4E0h] [ebp-160h] BYREF
  float v27; // [esp+4F8h] [ebp-148h]
  float v28; // [esp+4FCh] [ebp-144h]
  btTransform v29; // [esp+500h] [ebp-140h] BYREF
  float v30; // [esp+540h] [ebp-100h]
  float v31; // [esp+544h] [ebp-FCh]
  float v32; // [esp+548h] [ebp-F8h]
  float v33; // [esp+54Ch] [ebp-F4h]
  float v34[4]; // [esp+550h] [ebp-F0h] BYREF
  __m128i v35; // [esp+560h] [ebp-E0h] BYREF
  __m128i v36; // [esp+570h] [ebp-D0h] BYREF
  __m128i v37; // [esp+580h] [ebp-C0h] BYREF
  float v38[4]; // [esp+590h] [ebp-B0h] BYREF
  float v39[4]; // [esp+5A0h] [ebp-A0h] BYREF
  float v40[4]; // [esp+5B0h] [ebp-90h] BYREF
  btTransform trans; // [esp+5C0h] [ebp-80h] BYREF
  btTransform worldTrans; // [esp+600h] [ebp-40h] BYREF

  m_compoundColObj = this->m_compoundColObj;
  v29.m_basis.m_el[0].mVec128.m128_u64[0] = this->m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v29.m_basis.m_el[0].mVec128.m128_u64[1] = m_compoundColObj->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v29.m_basis.m_el[1] = m_compoundColObj->m_worldTransform.m_basis.m_el[1];
  v29.m_basis.m_el[2] = m_compoundColObj->m_worldTransform.m_basis.m_el[2];
  m_collisionShape = m_compoundColObj->m_collisionShape;
  v29.m_origin = m_compoundColObj->m_worldTransform.m_origin;
  trans = m_compoundColObj->m_interpolationWorldTransform;
  v5 = (float *)((char *)m_collisionShape[2].__vftable + 80 * index);
  v6 = v5[13];
  v7 = v5[12];
  v8 = v5[14];
  *(float *)v26.m128i_i32 = (float)((float)((float)(v7 * v29.m_basis.m_el[0].mVec128.m128_f32[0])
                                          + (float)(v6 * v29.m_basis.m_el[0].mVec128.m128_f32[1]))
                                  + (float)(v8 * v29.m_basis.m_el[0].mVec128.m128_f32[2]))
                          + v29.m_origin.mVec128.m128_f32[0];
  v9 = v5[6];
  *(float *)&v26.m128i_i32[2] = (float)((float)((float)(v7 * v29.m_basis.m_el[2].mVec128.m128_f32[0])
                                              + (float)(v6 * v29.m_basis.m_el[2].mVec128.m128_f32[1]))
                                      + (float)(v8 * v29.m_basis.m_el[2].mVec128.m128_f32[2]))
                              + v29.m_origin.mVec128.m128_f32[2];
  *(float *)&v26.m128i_i32[1] = (float)((float)((float)(v7 * v29.m_basis.m_el[1].mVec128.m128_f32[0])
                                              + (float)(v6 * v29.m_basis.m_el[1].mVec128.m128_f32[1]))
                                      + (float)(v8 * v29.m_basis.m_el[1].mVec128.m128_f32[2]))
                              + v29.m_origin.mVec128.m128_f32[1];
  v10 = v5[10];
  v26.m128i_i32[3] = 0;
  v11 = v5[2];
  v12 = (float)(v10 * v29.m_basis.m_el[2].mVec128.m128_f32[2]) + (float)(v11 * v29.m_basis.m_el[2].mVec128.m128_f32[0]);
  v27 = v5[9];
  v24 = v5[5];
  v13 = v5[1];
  v28 = v5[8];
  v30 = (float)((float)(v27 * v29.m_basis.m_el[2].mVec128.m128_f32[2])
              + (float)(v13 * v29.m_basis.m_el[2].mVec128.m128_f32[0]))
      + (float)(v24 * v29.m_basis.m_el[2].mVec128.m128_f32[1]);
  v25 = v5[4];
  v14 = *v5;
  v32 = (float)((float)(v28 * v29.m_basis.m_el[2].mVec128.m128_f32[2])
              + (float)(*v5 * v29.m_basis.m_el[2].mVec128.m128_f32[0]))
      + (float)(v25 * v29.m_basis.m_el[2].mVec128.m128_f32[1]);
  v31 = (float)((float)(v11 * v29.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v9 * v29.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v10 * v29.m_basis.m_el[1].mVec128.m128_f32[2]);
  v33 = (float)((float)(v13 * v29.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v24 * v29.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v27 * v29.m_basis.m_el[1].mVec128.m128_f32[2]);
  getAabb = childShape->getAabb;
  *(float *)&v35.m128i_i32[1] = (float)((float)(v13 * v29.m_basis.m_el[0].mVec128.m128_f32[0])
                                      + (float)(v24 * v29.m_basis.m_el[0].mVec128.m128_f32[1]))
                              + (float)(v27 * v29.m_basis.m_el[0].mVec128.m128_f32[2]);
  *(float *)v36.m128i_i32 = (float)((float)(v14 * v29.m_basis.m_el[1].mVec128.m128_f32[0])
                                  + (float)(v25 * v29.m_basis.m_el[1].mVec128.m128_f32[1]))
                          + (float)(v28 * v29.m_basis.m_el[1].mVec128.m128_f32[2]);
  v35.m128i_i64[1] = COERCE_UNSIGNED_INT(
                       (float)((float)(v11 * v29.m_basis.m_el[0].mVec128.m128_f32[0])
                             + (float)(v9 * v29.m_basis.m_el[0].mVec128.m128_f32[1]))
                     + (float)(v10 * v29.m_basis.m_el[0].mVec128.m128_f32[2]));
  *(float *)&v36.m128i_i32[1] = v33;
  v36.m128i_i64[1] = LODWORD(v31);
  *(float *)v35.m128i_i32 = (float)((float)(v14 * v29.m_basis.m_el[0].mVec128.m128_f32[0])
                                  + (float)(v25 * v29.m_basis.m_el[0].mVec128.m128_f32[1]))
                          + (float)(v28 * v29.m_basis.m_el[0].mVec128.m128_f32[2]);
  worldTrans.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v35);
  v16 = _mm_load_si128(&v36);
  *(float *)v37.m128i_i32 = v32;
  worldTrans.m_basis.m_el[1] = (btVector3)v16;
  *(float *)&v37.m128i_i32[1] = v30;
  v37.m128i_i64[1] = COERCE_UNSIGNED_INT(v12 + (float)(v9 * v29.m_basis.m_el[2].mVec128.m128_f32[1]));
  worldTrans.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v37);
  worldTrans.m_origin = (btVector3)_mm_load_si128(&v26);
  getAabb(childShape, &worldTrans, (btVector3 *)v38, (btVector3 *)v40);
  this->m_otherObj->m_collisionShape->getAabb(
    this->m_otherObj->m_collisionShape,
    &this->m_otherObj->m_worldTransform,
    (btVector3 *)v39,
    (btVector3 *)v34);
  v17 = 1;
  if ( v38[0] > v34[0] || v39[0] > v40[0] )
    v17 = 0;
  if ( v38[2] > v34[2] || v39[2] > v40[2] )
    v17 = 0;
  if ( v38[1] <= v34[1] && v39[1] <= v40[1] && v17 )
  {
    btCollisionObject::setWorldTransform(this->m_compoundColObj, &worldTrans);
    btCollisionObject::setInterpolationWorldTransform(this->m_compoundColObj, &worldTrans);
    v18 = this->m_compoundColObj->m_collisionShape;
    this->m_compoundColObj->m_collisionShape = childShape;
    if ( !this->m_childCollisionAlgorithms[index] )
      this->m_childCollisionAlgorithms[index] = this->m_dispatcher->findAlgorithm(
                                                  this->m_dispatcher,
                                                  this->m_compoundColObj,
                                                  this->m_otherObj,
                                                  this->m_sharedManifold);
    v19 = this->m_resultOut->__vftable;
    if ( this->m_resultOut->m_body0 == this->m_compoundColObj )
      ((void (__stdcall *)(int, int))v19->setShapeIdentifiersA)(-1, index);
    else
      ((void (__stdcall *)(int, int))v19->setShapeIdentifiersB)(-1, index);
    v20 = this->m_childCollisionAlgorithms[index];
    v20->processCollision(v20, this->m_compoundColObj, this->m_otherObj, this->m_dispatchInfo, this->m_resultOut);
    m_dispatchInfo = this->m_dispatchInfo;
    if ( m_dispatchInfo->m_debugDraw )
    {
      if ( (m_dispatchInfo->m_debugDraw->getDebugMode(m_dispatchInfo->m_debugDraw) & 2) != 0 )
      {
        v22 = this->m_dispatchInfo;
        v26.m128i_i32[0] = (int)clear_value;
        v26.m128i_i32[1] = (int)clear_value;
        v26.m128i_i64[1] = (unsigned int)clear_value;
        v22->m_debugDraw->drawAabb(
          v22->m_debugDraw,
          (const btVector3 *)v38,
          (const btVector3 *)v40,
          (const btVector3 *)&v26);
        v23 = this->m_dispatchInfo;
        v26.m128i_i32[0] = (int)clear_value;
        v26.m128i_i32[1] = (int)clear_value;
        v26.m128i_i64[1] = (unsigned int)clear_value;
        v23->m_debugDraw->drawAabb(
          v23->m_debugDraw,
          (const btVector3 *)v39,
          (const btVector3 *)v34,
          (const btVector3 *)&v26);
      }
    }
    this->m_compoundColObj->m_collisionShape = v18;
    btCollisionObject::setWorldTransform(this->m_compoundColObj, &v29);
    btCollisionObject::setInterpolationWorldTransform(this->m_compoundColObj, &trans);
  }
}
