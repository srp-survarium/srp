void __thiscall btCollisionShape::getBoundingSphere(btCollisionShape *this, btVector3 *center, float *radius)
{
  void (__thiscall *getAabb)(btCollisionShape *, const btTransform *, btVector3 *, btVector3 *); // eax
  long double v4; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // [esp+F0h] [ebp-60h] BYREF
  float v10; // [esp+F4h] [ebp-5Ch]
  float v11; // [esp+F8h] [ebp-58h]
  unsigned __int64 v12; // [esp+100h] [ebp-50h] BYREF
  unsigned __int64 v13; // [esp+108h] [ebp-48h]
  _DWORD v14[16]; // [esp+110h] [ebp-40h] BYREF

  getAabb = this->getAabb;
  v14[0] = clear_value;
  memset(&v14[1], 0, 16);
  v14[5] = clear_value;
  memset(&v14[6], 0, 16);
  v14[10] = clear_value;
  memset(&v14[11], 0, 20);
  getAabb(this, (const btTransform *)v14, (btVector3 *)&v9, (btVector3 *)&v12);
  v4 = sqrtf(
         (float)((float)((float)(*(float *)&v13 - v11) * (float)(*(float *)&v13 - v11))
               + (float)((float)(*((float *)&v12 + 1) - v10) * (float)(*((float *)&v12 + 1) - v10)))
       + (float)((float)(*(float *)&v12 - v9) * (float)(*(float *)&v12 - v9)));
  v5 = v9 + *(float *)&v12;
  v6 = *((float *)&v12 + 1) + v10;
  v7 = v11;
  *radius = v4 * 0.5;
  *(float *)&v12 = v5 * 0.5;
  HIDWORD(v13) = 0;
  *((float *)&v12 + 1) = v6 * 0.5;
  v8 = (float)(v7 + *(float *)&v13) * 0.5;
  center->mVec128.m128_u64[0] = v12;
  *(float *)&v13 = v8;
  center->mVec128.m128_u64[1] = v13;
}
