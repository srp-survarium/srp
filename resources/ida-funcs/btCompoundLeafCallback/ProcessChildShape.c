void __thiscall btCompoundLeafCallback::ProcessChildShape(
        btCompoundLeafCallback *this,
        btCollisionShape *childShape,
        int index,
        int a4)
{
  btCollisionShape_vtbl *v4; // ecx
  float (__thiscall **p_getContactBreakingThreshold)(btCollisionShape *, float); // eax
  void (__thiscall *setMargin)(btCollisionShape *, float); // edx
  int v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  int v19; // xmm2_4
  float v20; // xmm2_4
  char v21; // al
  int *p_setMargin; // eax
  int v23; // ecx
  int v24; // esi
  bool v25; // zf
  int v26; // eax
  btCollisionShape_vtbl *v27; // eax
  btCollisionShape_vtbl *v28; // eax
  btCollisionShape_vtbl *v29; // eax
  const float *v30; // [esp+38h] [ebp-190h]
  btMatrix3x3 v31; // [esp+48h] [ebp-180h] BYREF
  btCollisionObject v32; // [esp+78h] [ebp-150h] BYREF
  _DWORD v33[16]; // [esp+188h] [ebp-40h] BYREF

  v4 = childShape->__vftable;
  p_getContactBreakingThreshold = &childShape->getContactBreakingThreshold;
  v32.__vftable = (btCollisionObject_vtbl *)*p_getContactBreakingThreshold;
  *((_DWORD *)&v32.__vftable + 1) = p_getContactBreakingThreshold[1];
  *((_DWORD *)&v32.__vftable + 2) = p_getContactBreakingThreshold[2];
  *((_DWORD *)&v32.__vftable + 3) = p_getContactBreakingThreshold[3];
  v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = *((_QWORD *)p_getContactBreakingThreshold + 2);
  v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1] = *((_QWORD *)p_getContactBreakingThreshold + 3);
  v32.m_worldTransform.m_basis.m_el[1] = (btVector3)*((_OWORD *)p_getContactBreakingThreshold + 2);
  v32.m_worldTransform.m_basis.m_el[2] = (btVector3)*((_OWORD *)p_getContactBreakingThreshold + 3);
  v33[0] = v4[1].getLocalScaling;
  v33[1] = v4[1].calculateLocalInertia;
  v33[2] = v4[1].getName;
  v33[3] = v4[1].setMargin;
  v33[4] = v4[1].getMargin;
  v33[5] = v4[1].calculateSerializeBufferSize;
  v33[6] = v4[1].serialize;
  v33[7] = v4[1].serializeSingleShape;
  setMargin = v4[3].setMargin;
  v33[8] = v4[2].~btCollisionShape;
  v33[9] = v4[2].getAabb;
  v33[10] = v4[2].getBoundingSphere;
  v33[11] = v4[2].getAngularMotionDisc;
  v7 = *((_DWORD *)setMargin + 6) + 80 * a4;
  v8 = *(float *)(v7 + 52);
  v9 = *(float *)(v7 + 48);
  v10 = *(float *)(v7 + 56);
  v33[12] = v4[2].getContactBreakingThreshold;
  v33[13] = v4[2].setLocalScaling;
  v31.m_el[1].mVec128.m128_f32[0] = (float)((float)((float)(v9 * *(float *)&v32.__vftable)
                                                  + (float)(v8 * *((float *)&v32.__vftable + 1)))
                                          + (float)(v10 * *((float *)&v32.__vftable + 2)))
                                  + v32.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  v33[14] = v4[2].getLocalScaling;
  v11 = (float)((float)((float)(v9 * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                      + (float)(v8 * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
              + (float)(v10 * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
      + v32.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v33[15] = v4[2].calculateLocalInertia;
  v12 = *(float *)(v7 + 24);
  v31.m_el[2].mVec128.m128_i32[3] = *(_DWORD *)(v7 + 20);
  v31.m_el[1].mVec128.m128_f32[2] = (float)((float)((float)(v9 * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                                                  + (float)(v8 * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                                          + (float)(v10 * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]))
                                  + v32.m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
  v31.m_el[1].mVec128.m128_i32[3] = 0;
  v13 = *(float *)(v7 + 8);
  v31.m_el[1].mVec128.m128_f32[1] = v11;
  v14 = *(float *)(v7 + 40);
  v15 = *(float *)(v7 + 36);
  v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2] = (float)((float)(v13
                                                                                        * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                                                                                + (float)(v12
                                                                                        * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                                                                        + (float)(v14
                                                                                * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
  v16 = *(float *)(v7 + 4);
  v31.m_el[0].mVec128.m128_f32[1] = v15;
  v17 = *(float *)(v7 + 16);
  v18 = (float)((float)(v16 * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v31.m_el[2].mVec128.m128_f32[3] * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v15 * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
  v19 = *(_DWORD *)(v7 + 32);
  v32.m_worldTransform.m_origin.mVec128.m128_f32[3] = v18;
  v31.m_el[0].mVec128.m128_f32[0] = v17;
  v31.m_el[0].mVec128.m128_i32[2] = v19;
  v20 = *(float *)v7;
  v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(*(float *)v7
                                                                                        * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                                                                                + (float)(v17
                                                                                        * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                                                                        + (float)(v31.m_el[0].mVec128.m128_f32[2]
                                                                                * v32.m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
  v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v13
                                                                                        * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                                                + (float)(v12
                                                                                        * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                                                        + (float)(v14
                                                                                * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
  v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[3] = (float)((float)(v16
                                                                                        * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                                                + (float)(v31.m_el[2].mVec128.m128_f32[3]
                                                                                        * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                                                        + (float)(v31.m_el[0].mVec128.m128_f32[1]
                                                                                * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
  v32.m_worldTransform.m_origin.mVec128.m128_f32[2] = (float)((float)(v20
                                                                    * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
                                                            + (float)(v17
                                                                    * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                                    + (float)(v31.m_el[0].mVec128.m128_f32[2]
                                                            * v32.m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
  v31.m_el[0].mVec128.m128_f32[3] = (float)((float)(v13 * *(float *)&v32.__vftable)
                                          + (float)(v12 * *((float *)&v32.__vftable + 1)))
                                  + (float)(v14 * *((float *)&v32.__vftable + 2));
  v31.m_el[0].mVec128.m128_f32[1] = (float)((float)(v16 * *(float *)&v32.__vftable)
                                          + (float)(v31.m_el[2].mVec128.m128_f32[3] * *((float *)&v32.__vftable + 1)))
                                  + (float)(v31.m_el[0].mVec128.m128_f32[1] * *((float *)&v32.__vftable + 2));
  v31.m_el[0].mVec128.m128_f32[0] = (float)((float)(v20 * *(float *)&v32.__vftable)
                                          + (float)(v17 * *((float *)&v32.__vftable + 1)))
                                  + (float)(v31.m_el[0].mVec128.m128_f32[2] * *((float *)&v32.__vftable + 2));
  btMatrix3x3::setValue(
    &v31,
    (int)&v32.m_companionId,
    &v31.m_el[0].mVec128.m128_f32[1],
    &v31.m_el[0].mVec128.m128_f32[3],
    &v32.m_worldTransform.m_origin.mVec128.m128_f32[2],
    &v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[3],
    (float *)&v32.m_interpolationWorldTransform,
    &v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[1],
    &v32.m_worldTransform.m_origin.mVec128.m128_f32[3],
    &v32.m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[2],
    v30);
  v32.m_interpolationAngularVelocity = *(btVector3 *)&v32.m_companionId;
  v32.m_anisotropicFriction = *(btVector3 *)&v32.m_restitution;
  v32.m_hasAnisotropicFriction = LODWORD(v32.m_ccdSweptSphereRadius);
  v32.m_contactProcessingThreshold = v32.m_ccdMotionThreshold;
  v32.m_broadphaseHandle = (btBroadphaseProxy *)v32.m_checkCollideWith;
  v32.m_collisionShape = (btCollisionShape *)*(&v32.m_checkCollideWith + 1);
  *(btVector3 *)&v32.m_extensionPointer = v31.m_el[1];
  (*(void (__thiscall **)(int, btVector3 *, btVector3 *, btVector3 *))(*(_DWORD *)index + 4))(
    index,
    &v32.m_interpolationAngularVelocity,
    &v32.m_interpolationWorldTransform.m_basis.m_el[1],
    &v32.m_interpolationLinearVelocity);
  (*(void (__thiscall **)(_DWORD, int, btVector3 *, btVector3 *))(**(_DWORD **)(childShape->m_shapeType + 204) + 4))(
    *(_DWORD *)(childShape->m_shapeType + 204),
    childShape->m_shapeType + 16,
    &v32.m_interpolationWorldTransform.m_basis.m_el[2],
    &v32.m_interpolationWorldTransform.m_origin);
  v21 = 1;
  if ( v32.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0] > v32.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[0]
    || v32.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[0] > v32.m_interpolationLinearVelocity.mVec128.m128_f32[0] )
  {
    v21 = 0;
  }
  if ( v32.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] > v32.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2]
    || v32.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[2] > v32.m_interpolationLinearVelocity.mVec128.m128_f32[2] )
  {
    v21 = 0;
  }
  if ( v32.m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] > v32.m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1]
    || v32.m_interpolationWorldTransform.m_basis.m_el[2].mVec128.m128_f32[1] > v32.m_interpolationLinearVelocity.mVec128.m128_f32[1] )
  {
    v21 = 0;
  }
  if ( v21 )
  {
    btCollisionObject::setWorldTransform(
      (btCollisionObject *)&v32.m_interpolationAngularVelocity,
      (btVector3 *)childShape->__vftable);
    btCollisionObject::setInterpolationWorldTransform(
      (btCollisionObject *)&v32.m_interpolationAngularVelocity,
      (btVector3 *)childShape->__vftable);
    p_setMargin = (int *)&childShape->__vftable[3].setMargin;
    v23 = *p_setMargin;
    *p_setMargin = index;
    v24 = 4 * a4;
    v25 = *((_DWORD *)childShape[1].m_userPointer + a4) == 0;
    v31.m_el[0].mVec128.m128_i32[3] = v23;
    if ( v25 )
      *(_DWORD *)((char *)childShape[1].m_userPointer + v24) = (*(int (__thiscall **)(void *, btCollisionShape_vtbl *, int, btCollisionShape_vtbl *))(*(_DWORD *)childShape->m_userPointer + 4))(
                                                                 childShape->m_userPointer,
                                                                 childShape->__vftable,
                                                                 childShape->m_shapeType,
                                                                 childShape[2].__vftable);
    v26 = *(_DWORD *)childShape[1].m_shapeType;
    if ( *(btCollisionShape_vtbl **)(childShape[1].m_shapeType + 144) == childShape->__vftable )
      (*(void (__stdcall **)(int, int))(v26 + 4))(-1, a4);
    else
      (*(void (__stdcall **)(int, int))(v26 + 8))(-1, a4);
    (*(void (__thiscall **)(_DWORD, btCollisionShape_vtbl *, int, btCollisionShape_vtbl *, int))(**(_DWORD **)((char *)childShape[1].m_userPointer + v24)
                                                                                               + 4))(
      *(_DWORD *)((char *)childShape[1].m_userPointer + v24),
      childShape->__vftable,
      childShape->m_shapeType,
      childShape[1].__vftable,
      childShape[1].m_shapeType);
    v27 = childShape[1].__vftable;
    if ( v27->setLocalScaling )
    {
      if ( ((*(int (__thiscall **)(void (__thiscall *)(btCollisionShape *, const btVector3 *)))(*(_DWORD *)v27->setLocalScaling
                                                                                              + 48))(v27->setLocalScaling)
          & 2) != 0 )
      {
        v28 = childShape[1].__vftable;
        v31.m_el[1].mVec128.m128_f32[0] = s_bm_current_air_resistance;
        v31.m_el[1].mVec128.m128_f32[1] = s_bm_current_air_resistance;
        v31.m_el[1].mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
        (*(void (__thiscall **)(void (__thiscall *)(btCollisionShape *, const btVector3 *), btVector3 *, btVector3 *, btVector3 *))(*(_DWORD *)v28->setLocalScaling + 52))(
          v28->setLocalScaling,
          &v32.m_interpolationWorldTransform.m_basis.m_el[1],
          &v32.m_interpolationLinearVelocity,
          &v31.m_el[1]);
        v29 = childShape[1].__vftable;
        v31.m_el[1].mVec128.m128_f32[0] = s_bm_current_air_resistance;
        v31.m_el[1].mVec128.m128_f32[1] = s_bm_current_air_resistance;
        v31.m_el[1].mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
        (*(void (__thiscall **)(void (__thiscall *)(btCollisionShape *, const btVector3 *), btVector3 *, btVector3 *, btVector3 *))(*(_DWORD *)v29->setLocalScaling + 52))(
          v29->setLocalScaling,
          &v32.m_interpolationWorldTransform.m_basis.m_el[2],
          &v32.m_interpolationWorldTransform.m_origin,
          &v31.m_el[1]);
      }
    }
    childShape->__vftable[3].setMargin = (void (__thiscall *)(btCollisionShape *, float))v31.m_el[0].mVec128.m128_i32[3];
    btCollisionObject::setWorldTransform(&v32, (btVector3 *)childShape->__vftable);
    btCollisionObject::setInterpolationWorldTransform((btCollisionObject *)v33, (btVector3 *)childShape->__vftable);
  }
}
