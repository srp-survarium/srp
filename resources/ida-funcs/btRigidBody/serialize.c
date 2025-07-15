const char *__thiscall btRigidBody::serialize(btRigidBody *this, float *dataBuffer, btSerializer *serializer)
{
  float *v4; // ecx
  int *v5; // eax
  int v6; // edx
  double v7; // st7
  const char *result; // eax

  btCollisionObject::serialize(this, dataBuffer, serializer);
  v4 = dataBuffer + 63;
  v5 = &this->m_invInertiaTensorWorld.m_el[0].mVec128.m128_i32[1];
  v6 = 3;
  do
  {
    v7 = *((float *)v5 - 1);
    v5 += 4;
    *(v4 - 1) = v7;
    v4 += 4;
    --v6;
    *(v4 - 4) = *((float *)v5 - 4);
    *(v4 - 3) = *((float *)v5 - 3);
    *(v4 - 2) = *((float *)v5 - 2);
  }
  while ( v6 );
  dataBuffer[74] = this->m_linearVelocity.mVec128.m128_f32[0];
  dataBuffer[75] = this->m_linearVelocity.mVec128.m128_f32[1];
  dataBuffer[76] = this->m_linearVelocity.mVec128.m128_f32[2];
  dataBuffer[77] = this->m_linearVelocity.mVec128.m128_f32[3];
  dataBuffer[78] = this->m_angularVelocity.mVec128.m128_f32[0];
  dataBuffer[79] = this->m_angularVelocity.mVec128.m128_f32[1];
  dataBuffer[80] = this->m_angularVelocity.mVec128.m128_f32[2];
  dataBuffer[81] = this->m_angularVelocity.mVec128.m128_f32[3];
  dataBuffer[110] = this->m_inverseMass;
  dataBuffer[82] = this->m_angularFactor.mVec128.m128_f32[0];
  dataBuffer[83] = this->m_angularFactor.mVec128.m128_f32[1];
  dataBuffer[84] = this->m_angularFactor.mVec128.m128_f32[2];
  dataBuffer[85] = this->m_angularFactor.mVec128.m128_f32[3];
  dataBuffer[86] = this->m_linearFactor.mVec128.m128_f32[0];
  dataBuffer[87] = this->m_linearFactor.mVec128.m128_f32[1];
  dataBuffer[88] = this->m_linearFactor.mVec128.m128_f32[2];
  dataBuffer[89] = this->m_linearFactor.mVec128.m128_f32[3];
  dataBuffer[90] = this->m_gravity.mVec128.m128_f32[0];
  dataBuffer[91] = this->m_gravity.mVec128.m128_f32[1];
  dataBuffer[92] = this->m_gravity.mVec128.m128_f32[2];
  dataBuffer[93] = this->m_gravity.mVec128.m128_f32[3];
  dataBuffer[94] = this->m_gravity_acceleration.mVec128.m128_f32[0];
  dataBuffer[95] = this->m_gravity_acceleration.mVec128.m128_f32[1];
  dataBuffer[96] = this->m_gravity_acceleration.mVec128.m128_f32[2];
  dataBuffer[97] = this->m_gravity_acceleration.mVec128.m128_f32[3];
  dataBuffer[98] = this->m_invInertiaLocal.mVec128.m128_f32[0];
  dataBuffer[99] = this->m_invInertiaLocal.mVec128.m128_f32[1];
  dataBuffer[100] = this->m_invInertiaLocal.mVec128.m128_f32[2];
  dataBuffer[101] = this->m_invInertiaLocal.mVec128.m128_f32[3];
  dataBuffer[102] = this->m_totalForce.mVec128.m128_f32[0];
  dataBuffer[103] = this->m_totalForce.mVec128.m128_f32[1];
  dataBuffer[104] = this->m_totalForce.mVec128.m128_f32[2];
  dataBuffer[105] = this->m_totalForce.mVec128.m128_f32[3];
  dataBuffer[106] = this->m_totalTorque.mVec128.m128_f32[0];
  dataBuffer[107] = this->m_totalTorque.mVec128.m128_f32[1];
  dataBuffer[108] = this->m_totalTorque.mVec128.m128_f32[2];
  dataBuffer[109] = this->m_totalTorque.mVec128.m128_f32[3];
  dataBuffer[111] = this->m_linearDamping;
  dataBuffer[112] = this->m_angularDamping;
  *((_DWORD *)dataBuffer + 119) = this->m_additionalDamping;
  dataBuffer[113] = this->m_additionalDampingFactor;
  result = "btRigidBodyFloatData";
  dataBuffer[114] = this->m_additionalLinearDampingThresholdSqr;
  dataBuffer[115] = this->m_additionalAngularDampingThresholdSqr;
  dataBuffer[116] = this->m_additionalAngularDampingFactor;
  dataBuffer[117] = this->m_linearSleepingThreshold;
  dataBuffer[118] = this->m_angularSleepingThreshold;
  return result;
}
