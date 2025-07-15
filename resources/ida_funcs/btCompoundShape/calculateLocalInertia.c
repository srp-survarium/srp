void __thiscall btCompoundShape::calculateLocalInertia(btCompoundShape *this, float mass, btVector3 *inertia)
{
  void (__thiscall *getAabb)(struct btCompoundShape *, const btTransform *, btVector3 *, btVector3 *); // eax
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // [esp+F0h] [ebp-60h] BYREF
  float v9; // [esp+F4h] [ebp-5Ch]
  float v10; // [esp+F8h] [ebp-58h]
  float v11; // [esp+100h] [ebp-50h] BYREF
  float v12; // [esp+104h] [ebp-4Ch]
  float v13; // [esp+108h] [ebp-48h]
  _DWORD v14[16]; // [esp+110h] [ebp-40h] BYREF

  getAabb = this->getAabb;
  v14[0] = clear_value;
  memset(&v14[1], 0, 16);
  v14[5] = clear_value;
  memset(&v14[6], 0, 16);
  v14[10] = clear_value;
  memset(&v14[11], 0, 20);
  getAabb(this, (const btTransform *)v14, (btVector3 *)&v11, (btVector3 *)&v8);
  v4 = (float)((float)(v8 - v11) * 0.5) * 2.0;
  v5 = (float)((float)((float)(v9 - v12) * 0.5) * 2.0) * (float)((float)((float)(v9 - v12) * 0.5) * 2.0);
  v6 = (float)((float)((float)(v10 - v13) * 0.5) * 2.0) * (float)((float)((float)(v10 - v13) * 0.5) * 2.0);
  inertia->mVec128.m128_f32[0] = (float)((float)(v5 + v6) * mass) * 0.083333336;
  v7 = v4 * v4;
  inertia->mVec128.m128_f32[1] = (float)((float)(v7 + v6) * mass) * 0.083333336;
  inertia->mVec128.m128_f32[2] = (float)((float)(v7 + v5) * mass) * 0.083333336;
}
