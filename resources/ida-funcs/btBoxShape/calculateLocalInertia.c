void __thiscall btBoxShape::calculateLocalInertia(btBoxShape *this, float mass, btVector3 *inertia)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  btVector3 v6; // [esp+0h] [ebp-10h] BYREF

  btBoxShape::getHalfExtentsWithMargin(this, (btVector3 *)this, &v6);
  v3 = (float)(v6.mVec128.m128_f32[1] * 2.0) * (float)(v6.mVec128.m128_f32[1] * 2.0);
  v4 = (float)(v6.mVec128.m128_f32[2] * 2.0) * (float)(v6.mVec128.m128_f32[2] * 2.0);
  v5 = (float)(v6.mVec128.m128_f32[0] * 2.0) * (float)(v6.mVec128.m128_f32[0] * 2.0);
  inertia->mVec128.m128_f32[0] = (float)((float)(v3 + v4) * mass) * 0.083333336;
  inertia->mVec128.m128_f32[2] = (float)((float)(v5 + v3) * mass) * 0.083333336;
  inertia->mVec128.m128_f32[1] = (float)((float)(v5 + v4) * mass) * 0.083333336;
  inertia->mVec128.m128_i32[3] = 0;
}
