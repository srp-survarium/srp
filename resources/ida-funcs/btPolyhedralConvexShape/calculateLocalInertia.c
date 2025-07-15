void __thiscall btPolyhedralConvexShape::calculateLocalInertia(
        btPolyhedralConvexShape *this,
        float mass,
        btVector3 *inertia)
{
  void (__thiscall *getAabb)(struct btPolyhedralConvexShape *, const btTransform *, btVector3 *, btVector3 *); // edx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // [esp+160h] [ebp-64h]
  btVector3 v9; // [esp+164h] [ebp-60h] BYREF
  float v10; // [esp+174h] [ebp-50h] BYREF
  float v11; // [esp+178h] [ebp-4Ch]
  float v12; // [esp+17Ch] [ebp-48h]
  _DWORD v13[16]; // [esp+184h] [ebp-40h] BYREF

  v8 = this->getMargin(this);
  getAabb = this->getAabb;
  v13[0] = clear_value;
  memset(&v13[1], 0, 16);
  v13[5] = clear_value;
  memset(&v13[6], 0, 16);
  v13[10] = clear_value;
  memset(&v13[11], 0, 20);
  getAabb(this, (const btTransform *)v13, (btVector3 *)&v10, &v9);
  v5 = (float)((float)((float)((float)(v9.mVec128.m128_f32[1] - v11) * 0.5) + v8) * 2.0)
     * (float)((float)((float)((float)(v9.mVec128.m128_f32[1] - v11) * 0.5) + v8) * 2.0);
  v6 = (float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8) * 2.0)
     * (float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8) * 2.0);
  v7 = (float)((float)((float)((float)(v9.mVec128.m128_f32[0] - v10) * 0.5) + v8) * 2.0)
     * (float)((float)((float)((float)(v9.mVec128.m128_f32[0] - v10) * 0.5) + v8) * 2.0);
  v9.mVec128.m128_f32[2] = (float)(v5 + v7) * (float)(mass * 0.083333328);
  v9.mVec128.m128_i32[3] = 0;
  v9.mVec128.m128_f32[0] = (float)(v6 + v5) * (float)(mass * 0.083333328);
  v9.mVec128.m128_f32[1] = (float)(v6 + v7) * (float)(mass * 0.083333328);
  *inertia = (btVector3)v9.mVec128;
}
