void __thiscall btPolyhedralConvexShape::calculateLocalInertia(
        btPolyhedralConvexShape *this,
        float mass,
        btVector3 *inertia)
{
  btMatrix3x3 *v4; // ecx
  btPolyhedralConvexShape_vtbl *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // [esp+Ch] [ebp-64h]
  btVector3 v9; // [esp+10h] [ebp-60h] BYREF
  float v10; // [esp+20h] [ebp-50h] BYREF
  float v11; // [esp+24h] [ebp-4Ch]
  float v12; // [esp+28h] [ebp-48h]
  _BYTE v13[48]; // [esp+30h] [ebp-40h] BYREF
  int v14; // [esp+60h] [ebp-10h]
  int v15; // [esp+64h] [ebp-Ch]
  int v16; // [esp+68h] [ebp-8h]
  int v17; // [esp+6Ch] [ebp-4h]

  v8 = this->getMargin(this);
  btMatrix3x3::setIdentity(v4, (int)v13);
  v5 = this->__vftable;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v5->getAabb(this, (const btTransform *)v13, (btVector3 *)&v10, &v9);
  v6 = (float)((float)((float)((float)(v9.mVec128.m128_f32[0] - v10) * 0.5) + v8) * 2.0)
     * (float)((float)((float)((float)(v9.mVec128.m128_f32[0] - v10) * 0.5) + v8) * 2.0);
  v7 = (float)((float)((float)((float)(v9.mVec128.m128_f32[1] - v11) * 0.5) + v8) * 2.0)
     * (float)((float)((float)((float)(v9.mVec128.m128_f32[1] - v11) * 0.5) + v8) * 2.0);
  v9.mVec128.m128_f32[0] = (float)((float)((float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8)
                                                 * 2.0)
                                         * (float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8)
                                                 * 2.0))
                                 + v7)
                         * (float)(mass * 0.083333328);
  v9.mVec128.m128_i32[3] = 0;
  v9.mVec128.m128_f32[1] = (float)((float)((float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8)
                                                 * 2.0)
                                         * (float)((float)((float)((float)(v9.mVec128.m128_f32[2] - v12) * 0.5) + v8)
                                                 * 2.0))
                                 + v6)
                         * (float)(mass * 0.083333328);
  v9.mVec128.m128_f32[2] = (float)(v7 + v6) * (float)(mass * 0.083333328);
  *inertia = (btVector3)v9.mVec128;
}
