void __thiscall btCollisionShape::getBoundingSphere(btCollisionShape *this, btVector3 *center, float *radius)
{
  btCollisionShape_vtbl *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // [esp+10h] [ebp-60h] BYREF
  unsigned __int64 v9; // [esp+14h] [ebp-5Ch]
  int v10; // [esp+1Ch] [ebp-54h]
  float v11; // [esp+20h] [ebp-50h] BYREF
  float v12; // [esp+24h] [ebp-4Ch]
  float v13; // [esp+28h] [ebp-48h]
  _BYTE v14[48]; // [esp+30h] [ebp-40h] BYREF
  int v15; // [esp+60h] [ebp-10h]
  int v16; // [esp+64h] [ebp-Ch]
  int v17; // [esp+68h] [ebp-8h]
  int v18; // [esp+6Ch] [ebp-4h]

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)v14);
  v4 = this->__vftable;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v4->getAabb(this, (const btTransform *)v14, (btVector3 *)&v11, (btVector3 *)&v8);
  v5 = v12 + *(float *)&v9;
  v6 = v13 + *((float *)&v9 + 1);
  v7 = v11 + v8;
  *radius = fsqrt(
              (float)((float)((float)(*((float *)&v9 + 1) - v13) * (float)(*((float *)&v9 + 1) - v13))
                    + (float)((float)(*(float *)&v9 - v12) * (float)(*(float *)&v9 - v12)))
            + (float)((float)(v8 - v11) * (float)(v8 - v11)))
          * 0.5;
  *(float *)&v9 = v5 * 0.5;
  *((float *)&v9 + 1) = v6 * 0.5;
  v10 = 0;
  center->mVec128.m128_f32[0] = v7 * 0.5;
  *(unsigned __int64 *)((char *)center->mVec128.m128_u64 + 4) = v9;
  center->mVec128.m128_i32[3] = v10;
}
