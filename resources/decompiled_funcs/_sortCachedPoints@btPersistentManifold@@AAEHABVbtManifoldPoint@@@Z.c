int __usercall btPersistentManifold::sortCachedPoints@<eax>(btPersistentManifold *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm0_4
  int v3; // edx
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  int v29; // ecx
  int result; // eax
  float _X; // [esp+48h] [ebp-20h]
  float res1; // [esp+4Ch] [ebp-1Ch]
  float v33; // [esp+50h] [ebp-18h]
  float v34; // [esp+54h] [ebp-14h]
  float v35; // [esp+58h] [ebp-10h]
  float v36; // [esp+5Ch] [ebp-Ch]
  float v37; // [esp+60h] [ebp-8h]
  float v38; // [esp+64h] [ebp-4h]

  v2 = this->m_pointCache[0].m_normalWorldOnB.mVec128.m128_f32[0];
  v3 = -1;
  if ( v2 > a2[24] )
  {
    v3 = 0;
    v2 = a2[24];
  }
  if ( v2 > a2[96] )
  {
    v3 = 1;
    v2 = a2[96];
  }
  if ( v2 > a2[168] )
  {
    v3 = 2;
    v2 = a2[168];
  }
  if ( v2 > a2[240] )
    v3 = 3;
  _X = 0.0;
  res1 = 0.0;
  v33 = 0.0;
  v34 = 0.0;
  if ( v3 )
  {
    v4 = a2[222] - a2[150];
    v5 = *((float *)&this->btTypedObject + 1) - a2[77];
    v6 = a2[221] - a2[149];
    v7 = *(float *)&this->m_objectType - a2[76];
    v8 = a2[220] - a2[148];
    v9 = *((float *)&this->btTypedObject + 2) - a2[78];
    _X = (float)((float)((float)((float)(v6 * v7) - (float)(v5 * v8)) * (float)((float)(v6 * v7) - (float)(v5 * v8)))
               + (float)((float)((float)(v9 * v8) - (float)(v4 * v7)) * (float)((float)(v9 * v8) - (float)(v4 * v7))))
       + (float)((float)((float)(v4 * v5) - (float)(v6 * v9)) * (float)((float)(v4 * v5) - (float)(v6 * v9)));
  }
  if ( v3 != 1 )
  {
    v10 = a2[222] - a2[150];
    v11 = *((float *)&this->btTypedObject + 1) - a2[5];
    v12 = a2[221] - a2[149];
    v13 = *(float *)&this->m_objectType - a2[4];
    v14 = a2[220] - a2[148];
    v15 = *((float *)&this->btTypedObject + 2) - a2[6];
    res1 = (float)((float)((float)((float)(v12 * v13) - (float)(v11 * v14))
                         * (float)((float)(v12 * v13) - (float)(v11 * v14)))
                 + (float)((float)((float)(v15 * v14) - (float)(v10 * v13))
                         * (float)((float)(v15 * v14) - (float)(v10 * v13))))
         + (float)((float)((float)(v10 * v11) - (float)(v12 * v15)) * (float)((float)(v10 * v11) - (float)(v12 * v15)));
  }
  if ( v3 != 2 )
  {
    v16 = a2[222] - a2[78];
    v17 = *((float *)&this->btTypedObject + 1) - a2[5];
    v18 = a2[221] - a2[77];
    v19 = *(float *)&this->m_objectType - a2[4];
    v20 = a2[220] - a2[76];
    v21 = *((float *)&this->btTypedObject + 2) - a2[6];
    v33 = (float)((float)((float)((float)(v18 * v19) - (float)(v17 * v20))
                        * (float)((float)(v18 * v19) - (float)(v17 * v20)))
                + (float)((float)((float)(v21 * v20) - (float)(v16 * v19))
                        * (float)((float)(v21 * v20) - (float)(v16 * v19))))
        + (float)((float)((float)(v16 * v17) - (float)(v18 * v21)) * (float)((float)(v16 * v17) - (float)(v18 * v21)));
  }
  if ( v3 != 3 )
  {
    v22 = a2[150] - a2[78];
    v23 = *((float *)&this->btTypedObject + 1) - a2[5];
    v24 = a2[149] - a2[77];
    v25 = *(float *)&this->m_objectType - a2[4];
    v26 = a2[148] - a2[76];
    v27 = *((float *)&this->btTypedObject + 2) - a2[6];
    v34 = (float)((float)((float)((float)(v24 * v25) - (float)(v23 * v26))
                        * (float)((float)(v24 * v25) - (float)(v23 * v26)))
                + (float)((float)((float)(v27 * v26) - (float)(v22 * v25))
                        * (float)((float)(v27 * v26) - (float)(v22 * v25))))
        + (float)((float)((float)(v22 * v23) - (float)(v24 * v27)) * (float)((float)(v22 * v23) - (float)(v24 * v27)));
  }
  v35 = fabsf(_X);
  v36 = fabsf(res1);
  v37 = fabsf(v33);
  v28 = -9.9999998e17;
  v38 = fabsf(v34);
  v29 = -1;
  if ( v35 > -9.9999998e17 )
  {
    v28 = v35;
    v29 = 0;
  }
  if ( v36 > v28 )
  {
    v29 = 1;
    v28 = v36;
  }
  if ( v37 > v28 )
  {
    v29 = 2;
    v28 = v37;
  }
  result = 3;
  if ( v38 <= v28 )
    return v29;
  return result;
}
