const char *__thiscall btCollisionObject::serialize(
        btCollisionObject *this,
        float *dataBuffer,
        btSerializer *serializer)
{
  btTransform *p_m_worldTransform; // edx
  float *v6; // ecx
  int *v7; // ebx
  float *v8; // eax
  bool v9; // zf
  int *v10; // ecx
  float *v11; // eax
  const char *v13; // ebp
  void *v14; // eax
  int v16; // [esp+10h] [ebp-4h]
  int dataBuffera; // [esp+18h] [ebp+4h]
  int dataBufferb; // [esp+18h] [ebp+4h]

  p_m_worldTransform = &this->m_worldTransform;
  v6 = dataBuffer + 4;
  v7 = &p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[3];
  v8 = dataBuffer + 5;
  v16 = (char *)p_m_worldTransform - (char *)(dataBuffer + 4);
  dataBuffera = 3;
  do
  {
    *(v8 - 1) = *((float *)v7 - 3);
    v8 += 4;
    v7 += 4;
    v9 = dataBuffera-- == 1;
    *(v8 - 4) = *(float *)((char *)v8 + v16 - 16);
    *(v8 - 3) = *((float *)v7 - 5);
    *(v8 - 2) = *((float *)v7 - 4);
  }
  while ( !v9 );
  v6[12] = p_m_worldTransform->m_origin.mVec128.m128_f32[0];
  dataBufferb = 3;
  v6[13] = p_m_worldTransform->m_origin.mVec128.m128_f32[1];
  v6[14] = p_m_worldTransform->m_origin.mVec128.m128_f32[2];
  v6[15] = p_m_worldTransform->m_origin.mVec128.m128_f32[3];
  v10 = &this->m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_i32[3];
  v11 = dataBuffer + 21;
  do
  {
    *(v11 - 1) = *((float *)v10 - 3);
    v11 += 4;
    v10 += 4;
    v9 = dataBufferb-- == 1;
    *(v11 - 4) = *(float *)((char *)v11 + (char *)this - (char *)dataBuffer - 16);
    *(v11 - 3) = *((float *)v10 - 5);
    *(v11 - 2) = *((float *)v10 - 4);
  }
  while ( !v9 );
  dataBuffer[32] = this->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[0];
  dataBuffer[33] = this->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1];
  dataBuffer[34] = this->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2];
  dataBuffer[35] = this->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[3];
  dataBuffer[36] = this->m_interpolationLinearVelocity.mVec128.m128_f32[0];
  dataBuffer[37] = this->m_interpolationLinearVelocity.mVec128.m128_f32[1];
  dataBuffer[38] = this->m_interpolationLinearVelocity.mVec128.m128_f32[2];
  dataBuffer[39] = this->m_interpolationLinearVelocity.mVec128.m128_f32[3];
  dataBuffer[40] = this->m_interpolationAngularVelocity.mVec128.m128_f32[0];
  dataBuffer[41] = this->m_interpolationAngularVelocity.mVec128.m128_f32[1];
  dataBuffer[42] = this->m_interpolationAngularVelocity.mVec128.m128_f32[2];
  dataBuffer[43] = this->m_interpolationAngularVelocity.mVec128.m128_f32[3];
  dataBuffer[44] = this->m_anisotropicFriction.mVec128.m128_f32[0];
  dataBuffer[45] = this->m_anisotropicFriction.mVec128.m128_f32[1];
  dataBuffer[46] = this->m_anisotropicFriction.mVec128.m128_f32[2];
  dataBuffer[47] = this->m_anisotropicFriction.mVec128.m128_f32[3];
  dataBuffer[55] = *(float *)&this->m_hasAnisotropicFriction;
  dataBuffer[48] = this->m_contactProcessingThreshold;
  *dataBuffer = 0.0;
  *((_DWORD *)dataBuffer + 1) = serializer->getUniquePointer(serializer, this->m_collisionShape);
  dataBuffer[2] = 0.0;
  dataBuffer[56] = *(float *)&this->m_collisionFlags;
  dataBuffer[57] = *(float *)&this->m_islandTag1;
  dataBuffer[58] = *(float *)&this->m_companionId;
  dataBuffer[59] = *(float *)&this->m_activationState1;
  dataBuffer[59] = *(float *)&this->m_activationState1;
  dataBuffer[49] = this->m_deactivationTime;
  dataBuffer[50] = this->m_friction;
  dataBuffer[51] = this->m_restitution;
  dataBuffer[60] = *(float *)&this->m_internalType;
  v13 = serializer->findNameForPointer(serializer, this);
  v14 = serializer->getUniquePointer(serializer, v13);
  *((_DWORD *)dataBuffer + 3) = v14;
  if ( v14 )
    serializer->serializeName(serializer, v13);
  dataBuffer[52] = this->m_hitFraction;
  dataBuffer[53] = this->m_ccdSweptSphereRadius;
  dataBuffer[54] = this->m_ccdMotionThreshold;
  dataBuffer[54] = this->m_ccdMotionThreshold;
  dataBuffer[61] = *(float *)&this->m_checkCollideWith;
  return "btCollisionObjectFloatData";
}
