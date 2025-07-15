void __thiscall btCylinderShape::calculateLocalInertia(btCylinderShape *this, float mass, btVector3 *inertia)
{
  int m_upAxis; // esi
  int v5; // eax
  int v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  btVector3 *v10; // eax
  btVector3 v11; // [esp+10h] [ebp-10h] BYREF

  btBoxShape::getHalfExtentsWithMargin((btBoxShape *)this, (btVector3 *)this, &v11);
  m_upAxis = this->m_upAxis;
  if ( m_upAxis )
  {
    v5 = 0;
    if ( m_upAxis == 2 )
      v6 = 2;
    else
      v6 = 1;
  }
  else
  {
    v5 = 1;
    v6 = 0;
  }
  v7 = v11.mVec128.m128_f32[v5] * v11.mVec128.m128_f32[v5];
  v8 = (float)((float)((float)(v11.mVec128.m128_f32[v6] * v11.mVec128.m128_f32[v6]) * 4.0) * (float)(mass * 0.083333336))
     + (float)(v7 * (float)(mass * 0.25));
  v9 = v7 * (float)(mass * 0.5);
  if ( !m_upAxis )
  {
    v10 = inertia;
    inertia->mVec128.m128_f32[0] = v9;
    inertia->mVec128.m128_f32[1] = v8;
    goto LABEL_11;
  }
  v10 = inertia;
  inertia->mVec128.m128_f32[0] = v8;
  if ( m_upAxis != 2 )
  {
    inertia->mVec128.m128_f32[1] = v9;
LABEL_11:
    v10->mVec128.m128_f32[2] = v8;
    goto LABEL_12;
  }
  inertia->mVec128.m128_f32[1] = v8;
  inertia->mVec128.m128_f32[2] = v9;
LABEL_12:
  v10->mVec128.m128_i32[3] = 0;
}
