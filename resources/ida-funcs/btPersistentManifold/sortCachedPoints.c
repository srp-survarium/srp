int __usercall btPersistentManifold::sortCachedPoints@<eax>(btPersistentManifold *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm0_4
  int v3; // edi
  int v4; // esi
  float *v5; // edx
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float *v24; // ecx
  float v25; // xmm3_4
  float *v26; // eax
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  int result; // eax
  float v34; // [esp+0h] [ebp-28h]
  float v35; // [esp+8h] [ebp-20h]
  float v36; // [esp+8h] [ebp-20h]
  float v37; // [esp+8h] [ebp-20h]
  float v38; // [esp+18h] [ebp-10h]
  float v39; // [esp+18h] [ebp-10h]

  v2 = this->m_pointCache[0].m_normalWorldOnB.mVec128.m128_f32[0];
  v3 = -1;
  v4 = 0;
  v5 = a2 + 24;
  do
  {
    if ( v2 > *v5 )
    {
      v3 = v4;
      v2 = *v5;
    }
    ++v4;
    v5 += 72;
  }
  while ( v4 < 4 );
  v6 = 0.0;
  v7 = 0.0;
  v34 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  if ( v3 )
  {
    v10 = *((float *)&this->btTypedObject + 1) - a2[77];
    v35 = *(float *)&this->m_objectType - a2[76];
    v11 = *((float *)&this->btTypedObject + 2) - a2[78];
    v12 = a2[222] - a2[150];
    v38 = a2[220] - a2[148];
    v13 = a2[221] - a2[149];
    v6 = (float)((float)((float)((float)(v13 * v35) - (float)(v10 * v38))
                       * (float)((float)(v13 * v35) - (float)(v10 * v38)))
               + (float)((float)((float)(v11 * v38) - (float)(v12 * v35))
                       * (float)((float)(v11 * v38) - (float)(v12 * v35))))
       + (float)((float)((float)(v12 * v10) - (float)(v13 * v11)) * (float)((float)(v12 * v10) - (float)(v13 * v11)));
    v34 = v6;
    v7 = 0.0;
  }
  if ( v3 != 1 )
  {
    v14 = *((float *)&this->btTypedObject + 1) - a2[5];
    v15 = *((float *)&this->btTypedObject + 2) - a2[6];
    v16 = a2[222] - a2[150];
    v36 = a2[220] - a2[148];
    v17 = a2[221] - a2[149];
    v6 = v34;
    v7 = (float)((float)((float)((float)(v17 * (float)(*(float *)&this->m_objectType - a2[4])) - (float)(v14 * v36))
                       * (float)((float)(v17 * (float)(*(float *)&this->m_objectType - a2[4])) - (float)(v14 * v36)))
               + (float)((float)((float)(v15 * v36) - (float)(v16 * (float)(*(float *)&this->m_objectType - a2[4])))
                       * (float)((float)(v15 * v36) - (float)(v16 * (float)(*(float *)&this->m_objectType - a2[4])))))
       + (float)((float)((float)(v16 * v14) - (float)(v17 * v15)) * (float)((float)(v16 * v14) - (float)(v17 * v15)));
  }
  if ( v3 != 2 )
  {
    v18 = *((float *)&this->btTypedObject + 1) - a2[5];
    v19 = *((float *)&this->btTypedObject + 2) - a2[6];
    v20 = a2[222] - a2[78];
    v37 = a2[220] - a2[76];
    v21 = a2[221] - a2[77];
    v6 = v34;
    v8 = (float)((float)((float)((float)(v21 * (float)(*(float *)&this->m_objectType - a2[4])) - (float)(v18 * v37))
                       * (float)((float)(v21 * (float)(*(float *)&this->m_objectType - a2[4])) - (float)(v18 * v37)))
               + (float)((float)((float)(v19 * v37) - (float)(v20 * (float)(*(float *)&this->m_objectType - a2[4])))
                       * (float)((float)(v19 * v37) - (float)(v20 * (float)(*(float *)&this->m_objectType - a2[4])))))
       + (float)((float)((float)(v20 * v18) - (float)(v21 * v19)) * (float)((float)(v20 * v18) - (float)(v21 * v19)));
  }
  if ( v3 != 3 )
  {
    v22 = *((float *)&this->btTypedObject + 1) - a2[5];
    v39 = *(float *)&this->m_objectType - a2[4];
    v23 = *((float *)&this->btTypedObject + 2) - a2[6];
    v24 = a2 + 76;
    v25 = a2[150] - a2[78];
    v26 = a2 + 148;
    v27 = v26[1] - v24[1];
    v6 = v34;
    v9 = (float)((float)((float)((float)(v27 * v39) - (float)(v22 * (float)(*v26 - *v24)))
                       * (float)((float)(v27 * v39) - (float)(v22 * (float)(*v26 - *v24))))
               + (float)((float)((float)(v23 * (float)(*v26 - *v24)) - (float)(v25 * v39))
                       * (float)((float)(v23 * (float)(*v26 - *v24)) - (float)(v25 * v39))))
       + (float)((float)((float)(v25 * v22) - (float)(v27 * v23)) * (float)((float)(v25 * v22) - (float)(v27 * v23)));
  }
  LODWORD(v28) = LODWORD(v6) & _mask__AbsFloat_;
  LODWORD(v29) = LODWORD(v7) & _mask__AbsFloat_;
  LODWORD(v30) = LODWORD(v8) & _mask__AbsFloat_;
  LODWORD(v31) = LODWORD(v9) & _mask__AbsFloat_;
  v32 = FLOAT_N9_9999998e17;
  result = -1;
  if ( v28 > -9.9999998e17 )
  {
    result = 0;
    v32 = v28;
  }
  if ( v29 > v32 )
  {
    result = 1;
    v32 = v29;
  }
  if ( v30 > v32 )
  {
    result = 2;
    v32 = v30;
  }
  if ( v31 > v32 )
    return 3;
  return result;
}
