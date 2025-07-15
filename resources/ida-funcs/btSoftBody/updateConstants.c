void __usercall btSoftBody::updateConstants(btSoftBody *this@<ecx>, _DWORD *a2@<edi>)
{
  int v2; // esi
  int v3; // ebx
  int v4; // eax
  float *v5; // ecx
  float *v6; // edx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // ebx
  int v12; // eax
  float *v13; // edx
  float *v14; // esi
  float v15; // xmm3_4
  float v16; // xmm6_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  bool v23; // zf
  btSoftBody *v24; // esi
  _DWORD *v25; // eax
  int v26; // eax
  btSoftBody_vtbl **v27; // esi
  _DWORD *v28; // eax
  btSoftBody_vtbl *v29; // eax
  const char *(__thiscall *v30)(struct btSoftBody *, void *, btSerializer *); // xmm1_4
  int v31; // ebx
  int v32; // esi
  int v33; // edx
  int v34; // eax
  int v35; // [esp+10h] [ebp-20h]
  int v36; // [esp+10h] [ebp-20h]
  int v37; // [esp+14h] [ebp-1Ch]
  int v38; // [esp+18h] [ebp-18h]
  char v39[4]; // [esp+1Ch] [ebp-14h] BYREF
  btSoftBody *v40; // [esp+20h] [ebp-10h]
  btSoftBody *v41; // [esp+24h] [ebp-Ch]
  _DWORD *v42; // [esp+28h] [ebp-8h]
  char v43; // [esp+2Ch] [ebp-4h]

  if ( (int)a2[185] > 0 )
  {
    v2 = 0;
    v3 = a2[185];
    do
    {
      v4 = v2 + a2[187];
      v5 = *(float **)(v4 + 12);
      v6 = *(float **)(v4 + 8);
      v7 = v6[6] - v5[6];
      v8 = v6[5] - v5[5];
      v9 = fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)((float)(v6[4] - v5[4]) * (float)(v6[4] - v5[4])));
      *(float *)(v4 + 16) = v9;
      v10 = v6[24] + v5[24];
      this = *(btSoftBody **)(v4 + 4);
      *(float *)(v4 + 24) = v10 / *((float *)&this->__vftable + 1);
      v2 += 64;
      --v3;
      *(float *)(v4 + 28) = v9 * v9;
    }
    while ( v3 );
  }
  if ( (int)a2[190] > 0 )
  {
    v11 = 0;
    v35 = a2[190];
    do
    {
      v12 = v11 + a2[192];
      v13 = *(float **)(v12 + 12);
      v14 = *(float **)(v12 + 8);
      v15 = v14[5];
      v16 = v14[6];
      this = (btSoftBody *)(*(_DWORD *)(v12 + 16) + 16);
      v14 += 4;
      v17 = *(float *)&this->__vftable - *v14;
      v18 = v13[4] - *v14;
      v19 = v13[5] - v15;
      v20 = *(float *)(*(_DWORD *)(v12 + 16) + 20) - v15;
      v21 = v13[6] - v16;
      v22 = *(float *)(*(_DWORD *)(v12 + 16) + 24) - v16;
      v11 += 64;
      v23 = v35-- == 1;
      *(float *)(v12 + 48) = fsqrt(
                               (float)((float)((float)((float)(v20 * v18) - (float)(v19 * v17))
                                             * (float)((float)(v20 * v18) - (float)(v19 * v17)))
                                     + (float)((float)((float)(v21 * v17) - (float)(v22 * v18))
                                             * (float)((float)(v21 * v17) - (float)(v22 * v18))))
                             + (float)((float)((float)(v22 * v19) - (float)(v20 * v21))
                                     * (float)((float)(v22 * v19) - (float)(v20 * v21))));
    }
    while ( !v23 );
  }
  v24 = (btSoftBody *)a2[180];
  v42 = 0;
  v41 = 0;
  v43 = 1;
  if ( (int)v24 > 0 )
  {
    v43 = 1;
    v42 = btAlignedAllocInternal(4 * (_DWORD)v24);
    v41 = v24;
    v25 = v42;
    this = v24;
    do
    {
      if ( v25 )
        *v25 = 0;
      ++v25;
      this = (btSoftBody *)((char *)this - 1);
    }
    while ( this );
  }
  v26 = a2[180];
  v40 = v24;
  if ( v26 > 0 )
  {
    this = 0;
    do
    {
      *(int *)((char *)&this->m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_i32[1] + a2[182]) = 0;
      this = (btSoftBody *)((char *)this + 112);
      --v26;
    }
    while ( v26 );
  }
  if ( (int)a2[190] > 0 )
  {
    v36 = 0;
    v38 = a2[190];
    do
    {
      this = (btSoftBody *)(v36 + a2[192]);
      v37 = 3;
      v27 = &this->__vftable + 2;
      do
      {
        v28 = &v42[((int)*v27 - a2[182]) / 112];
        ++*v28;
        v29 = *v27;
        *(float *)&v30 = COERCE_FLOAT(this->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[0] & _mask__AbsFloat_)
                       + *(float *)&(*v27++)[3].serialize;
        v23 = v37-- == 1;
        v29[3].serialize = v30;
      }
      while ( !v23 );
      v36 += 64;
      --v38;
    }
    while ( v38 );
  }
  v31 = a2[180];
  v32 = 0;
  if ( v31 > 0 )
  {
    this = 0;
    do
    {
      v33 = v42[v32];
      v34 = a2[182];
      if ( v33 <= 0 )
        *(int *)((char *)&this->m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_i32[1] + v34) = 0;
      else
        *(float *)((char *)&this->m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] + v34) = *(float *)((char *)&this->m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] + v34) / (float)v33;
      ++v32;
      this = (btSoftBody *)((char *)this + 112);
    }
    while ( v32 < v31 );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)v39);
}
