const char *__thiscall btRigidBody::serialize(btRigidBody *this, float *dataBuffer, btSerializer *serializer)
{
  btMatrix3x3 *p_m_invInertiaTensorWorld; // ecx
  float *v5; // edx
  int v6; // ebx
  double v7; // st7
  float *v8; // edx
  btVector3 *p_m_linearVelocity; // ecx
  int v10; // ebx
  double v11; // st7
  float *v12; // edx
  btVector3 *p_m_angularVelocity; // ecx
  int v14; // ebx
  double v15; // st7
  float *v16; // edx
  btVector3 *p_m_angularFactor; // ecx
  int v18; // ebx
  double v19; // st7
  float *v20; // edx
  btVector3 *p_m_linearFactor; // ecx
  int v22; // ebx
  double v23; // st7
  float *v24; // edx
  btVector3 *p_m_gravity; // ecx
  int v26; // ebx
  double v27; // st7
  float *v28; // edx
  btVector3 *p_m_gravity_acceleration; // ecx
  int v30; // ebx
  double v31; // st7
  float *v32; // edx
  btVector3 *p_m_invInertiaLocal; // ecx
  int v34; // ebx
  double v35; // st7
  float *v36; // edx
  btVector3 *p_m_totalForce; // ecx
  int v38; // ebx
  double v39; // st7
  float *v40; // edx
  btVector3 *p_m_totalTorque; // ecx
  int v42; // ebx
  double v43; // st7
  const char *result; // eax
  int serializera; // [esp+18h] [ebp+Ch]

  btCollisionObject::serialize(this, dataBuffer, serializer);
  p_m_invInertiaTensorWorld = &this->m_invInertiaTensorWorld;
  v5 = dataBuffer + 62;
  serializera = 3;
  do
  {
    v6 = 4;
    do
    {
      v7 = p_m_invInertiaTensorWorld->m_el[0].mVec128.m128_f32[0];
      p_m_invInertiaTensorWorld = (btMatrix3x3 *)((char *)p_m_invInertiaTensorWorld + 4);
      *v5++ = v7;
      --v6;
    }
    while ( v6 );
    --serializera;
  }
  while ( serializera );
  v8 = dataBuffer + 74;
  p_m_linearVelocity = &this->m_linearVelocity;
  v10 = 4;
  do
  {
    v11 = p_m_linearVelocity->mVec128.m128_f32[0];
    p_m_linearVelocity = (btVector3 *)((char *)p_m_linearVelocity + 4);
    *v8++ = v11;
    --v10;
  }
  while ( v10 );
  v12 = dataBuffer + 78;
  p_m_angularVelocity = &this->m_angularVelocity;
  v14 = 4;
  do
  {
    v15 = p_m_angularVelocity->mVec128.m128_f32[0];
    p_m_angularVelocity = (btVector3 *)((char *)p_m_angularVelocity + 4);
    *v12++ = v15;
    --v14;
  }
  while ( v14 );
  v16 = dataBuffer + 82;
  dataBuffer[110] = this->m_inverseMass;
  p_m_angularFactor = &this->m_angularFactor;
  v18 = 4;
  do
  {
    v19 = p_m_angularFactor->mVec128.m128_f32[0];
    p_m_angularFactor = (btVector3 *)((char *)p_m_angularFactor + 4);
    *v16++ = v19;
    --v18;
  }
  while ( v18 );
  v20 = dataBuffer + 86;
  p_m_linearFactor = &this->m_linearFactor;
  v22 = 4;
  do
  {
    v23 = p_m_linearFactor->mVec128.m128_f32[0];
    p_m_linearFactor = (btVector3 *)((char *)p_m_linearFactor + 4);
    *v20++ = v23;
    --v22;
  }
  while ( v22 );
  v24 = dataBuffer + 90;
  p_m_gravity = &this->m_gravity;
  v26 = 4;
  do
  {
    v27 = p_m_gravity->mVec128.m128_f32[0];
    p_m_gravity = (btVector3 *)((char *)p_m_gravity + 4);
    *v24++ = v27;
    --v26;
  }
  while ( v26 );
  v28 = dataBuffer + 94;
  p_m_gravity_acceleration = &this->m_gravity_acceleration;
  v30 = 4;
  do
  {
    v31 = p_m_gravity_acceleration->mVec128.m128_f32[0];
    p_m_gravity_acceleration = (btVector3 *)((char *)p_m_gravity_acceleration + 4);
    *v28++ = v31;
    --v30;
  }
  while ( v30 );
  v32 = dataBuffer + 98;
  p_m_invInertiaLocal = &this->m_invInertiaLocal;
  v34 = 4;
  do
  {
    v35 = p_m_invInertiaLocal->mVec128.m128_f32[0];
    p_m_invInertiaLocal = (btVector3 *)((char *)p_m_invInertiaLocal + 4);
    *v32++ = v35;
    --v34;
  }
  while ( v34 );
  v36 = dataBuffer + 102;
  p_m_totalForce = &this->m_totalForce;
  v38 = 4;
  do
  {
    v39 = p_m_totalForce->mVec128.m128_f32[0];
    p_m_totalForce = (btVector3 *)((char *)p_m_totalForce + 4);
    *v36++ = v39;
    --v38;
  }
  while ( v38 );
  v40 = dataBuffer + 106;
  p_m_totalTorque = &this->m_totalTorque;
  v42 = 4;
  do
  {
    v43 = p_m_totalTorque->mVec128.m128_f32[0];
    p_m_totalTorque = (btVector3 *)((char *)p_m_totalTorque + 4);
    *v40++ = v43;
    --v42;
  }
  while ( v42 );
  dataBuffer[111] = this->m_linearDamping;
  dataBuffer[112] = this->m_angularDamping;
  *((_DWORD *)dataBuffer + 119) = this->m_additionalDamping;
  result = "btRigidBodyFloatData";
  dataBuffer[113] = this->m_additionalDampingFactor;
  dataBuffer[114] = this->m_additionalLinearDampingThresholdSqr;
  dataBuffer[115] = this->m_additionalAngularDampingThresholdSqr;
  dataBuffer[116] = this->m_additionalAngularDampingFactor;
  dataBuffer[117] = this->m_linearSleepingThreshold;
  dataBuffer[118] = this->m_angularSleepingThreshold;
  return result;
}
