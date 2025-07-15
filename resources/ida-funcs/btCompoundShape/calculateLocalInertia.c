void __thiscall btCompoundShape::calculateLocalInertia(btCompoundShape *this, float mass, btVector3 *inertia)
{
  btCompoundShape_vtbl *v4; // eax
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // [esp+10h] [ebp-60h] BYREF
  float v10; // [esp+14h] [ebp-5Ch]
  float v11; // [esp+18h] [ebp-58h]
  float v12; // [esp+20h] [ebp-50h] BYREF
  float v13; // [esp+24h] [ebp-4Ch]
  float v14; // [esp+28h] [ebp-48h]
  _BYTE v15[48]; // [esp+30h] [ebp-40h] BYREF
  int v16; // [esp+60h] [ebp-10h]
  int v17; // [esp+64h] [ebp-Ch]
  int v18; // [esp+68h] [ebp-8h]
  int v19; // [esp+6Ch] [ebp-4h]

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)v15);
  v4 = this->__vftable;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v4->getAabb(this, (const btTransform *)v15, (btVector3 *)&v12, (btVector3 *)&v9);
  v5 = (float)((float)(v9 - v12) * 0.5) * 2.0;
  v6 = (float)((float)((float)(v10 - v13) * 0.5) * 2.0) * (float)((float)((float)(v10 - v13) * 0.5) * 2.0);
  v7 = (float)((float)((float)(v11 - v14) * 0.5) * 2.0) * (float)((float)((float)(v11 - v14) * 0.5) * 2.0);
  inertia->mVec128.m128_f32[0] = (float)((float)(v6 + v7) * mass) * 0.083333336;
  v8 = v5 * v5;
  inertia->mVec128.m128_f32[1] = (float)((float)(v8 + v7) * mass) * 0.083333336;
  inertia->mVec128.m128_f32[2] = (float)((float)(v8 + v6) * mass) * 0.083333336;
}
