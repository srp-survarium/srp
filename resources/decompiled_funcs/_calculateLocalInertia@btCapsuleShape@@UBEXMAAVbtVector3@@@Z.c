void __thiscall btCapsuleShape::calculateLocalInertia(btCapsuleShape *this, float mass, btVector3 *inertia)
{
  int m_upAxis; // esi
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // [esp+20h] [ebp-10h]
  float v8; // [esp+24h] [ebp-Ch]
  float v9; // [esp+28h] [ebp-8h]
  int v10; // [esp+2Ch] [ebp-4h]

  m_upAxis = this->m_upAxis;
  v7 = this->m_implicitShapeDimensions.mVec128.m128_f32[(m_upAxis + 2) % 3];
  v9 = v7;
  v8 = v7;
  v10 = 0;
  *(&v7 + m_upAxis) = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis] + *(&v7 + m_upAxis);
  v4 = (float)((float)(v7 + 0.039999999) * 2.0) * (float)((float)(v7 + 0.039999999) * 2.0);
  v5 = (float)((float)(v9 + 0.039999999) * 2.0) * (float)((float)(v9 + 0.039999999) * 2.0);
  v6 = (float)((float)(v8 + 0.039999999) * 2.0) * (float)((float)(v8 + 0.039999999) * 2.0);
  inertia->mVec128.m128_f32[0] = (float)(v5 + v6) * (float)(mass * 0.083333328);
  inertia->mVec128.m128_f32[1] = (float)(v5 + v4) * (float)(mass * 0.083333328);
  inertia->mVec128.m128_f32[2] = (float)(v6 + v4) * (float)(mass * 0.083333328);
}
