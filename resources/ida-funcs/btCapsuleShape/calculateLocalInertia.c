void __thiscall btCapsuleShape::calculateLocalInertia(btCapsuleShape *this, float mass, btVector3 *inertia)
{
  int m_upAxis; // ecx
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // [esp+10h] [ebp-50h]
  float v9; // [esp+14h] [ebp-4Ch]
  float v10; // [esp+18h] [ebp-48h]
  int v11; // [esp+1Ch] [ebp-44h]
  _BYTE v12[64]; // [esp+20h] [ebp-40h] BYREF

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)v12);
  m_upAxis = this->m_upAxis;
  v8 = this->m_implicitShapeDimensions.mVec128.m128_f32[(m_upAxis + 2) % 3];
  v10 = v8;
  v9 = v8;
  v11 = 0;
  *(&v8 + m_upAxis) = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis] + *(&v8 + m_upAxis);
  v5 = (float)((float)(v8 + 0.039999999) * 2.0) * (float)((float)(v8 + 0.039999999) * 2.0);
  v6 = (float)((float)(v10 + 0.039999999) * 2.0) * (float)((float)(v10 + 0.039999999) * 2.0);
  v7 = (float)((float)(v9 + 0.039999999) * 2.0) * (float)((float)(v9 + 0.039999999) * 2.0);
  inertia->mVec128.m128_f32[0] = (float)(v6 + v7) * (float)(mass * 0.083333328);
  inertia->mVec128.m128_f32[1] = (float)(v6 + v5) * (float)(mass * 0.083333328);
  inertia->mVec128.m128_f32[2] = (float)(v7 + v5) * (float)(mass * 0.083333328);
}
