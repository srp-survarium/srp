void __usercall btSoftBody::updateConstants(btSoftBody *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // edi
  float *v3; // eax
  float *v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  long double v8; // st7
  float v9; // xmm0_4
  bool v10; // zf
  int v11; // ebx
  int v12; // edi
  float *v13; // eax
  float *v14; // ecx
  float *v15; // edx
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  int v25; // edi
  _DWORD *v26; // eax
  int v27; // edx
  int v28; // edi
  int v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  int v32; // edx
  int *v33; // edi
  int v34; // eax
  int v35; // ebx
  long double v36; // st7
  int v37; // ebx
  int v38; // edi
  int v39; // eax
  int *v40; // edx
  unsigned int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // ecx
  int v46; // ecx
  int v47; // edi
  int v48; // ecx
  int v49; // eax
  int v50; // edx
  int v51; // [esp+6Ch] [ebp-24h]
  int v52; // [esp+6Ch] [ebp-24h]
  int v53; // [esp+70h] [ebp-20h]
  int v54; // [esp+70h] [ebp-20h]
  int v55; // [esp+70h] [ebp-20h]
  int v56; // [esp+74h] [ebp-1Ch]
  int v57; // [esp+74h] [ebp-1Ch]
  int v58; // [esp+78h] [ebp-18h]
  int v59; // [esp+78h] [ebp-18h]
  _DWORD *ptr; // [esp+88h] [ebp-8h]

  if ( (int)a2[185] > 0 )
  {
    v51 = 0;
    v53 = a2[185];
    do
    {
      v2 = v51 + a2[187];
      v3 = *(float **)(v2 + 8);
      v4 = *(float **)(v2 + 12);
      v5 = v3[5] - v4[5];
      v6 = v3[6] - v4[6];
      v7 = v3[4] - v4[4];
      v8 = sqrtf((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v7 * v7));
      *(float *)(v2 + 16) = v8;
      v9 = (float)(*(float *)(*(_DWORD *)(v2 + 8) + 96) + v4[24]) / *(float *)(*(_DWORD *)(v2 + 4) + 4);
      *(float *)(v2 + 28) = v8 * v8;
      v51 += 64;
      v10 = v53-- == 1;
      *(float *)(v2 + 24) = v9;
    }
    while ( !v10 );
  }
  if ( (int)a2[190] > 0 )
  {
    v11 = 0;
    v54 = a2[190];
    do
    {
      v12 = a2[192];
      v13 = *(float **)(v12 + v11 + 16);
      v14 = *(float **)(v12 + v11 + 12);
      v15 = *(float **)(v12 + v11 + 8);
      v16 = v15[4];
      v17 = v15[5];
      v18 = v15[6];
      v19 = v13[4] - v16;
      v20 = v14[4] - v16;
      v21 = v14[5] - v17;
      v22 = v13[5] - v17;
      v23 = v14[6] - v18;
      v24 = v13[6] - v18;
      *(float *)(v11 + v12 + 48) = sqrtf(
                                     (float)((float)((float)((float)(v22 * v20) - (float)(v21 * v19))
                                                   * (float)((float)(v22 * v20) - (float)(v21 * v19)))
                                           + (float)((float)((float)(v23 * v19) - (float)(v24 * v20))
                                                   * (float)((float)(v23 * v19) - (float)(v24 * v20))))
                                   + (float)((float)((float)(v24 * v21) - (float)(v22 * v23))
                                           * (float)((float)(v24 * v21) - (float)(v22 * v23))));
      v11 += 64;
      --v54;
    }
    while ( v54 );
  }
  v25 = a2[180];
  ptr = 0;
  if ( v25 > 0 )
  {
    ++gNumAlignedAllocs;
    ptr = sAlignedAllocFunc(4 * v25, 16);
    v26 = ptr;
    do
    {
      if ( v26 )
        *v26 = 0;
      ++v26;
      --v25;
    }
    while ( v25 );
  }
  v27 = a2[180];
  v28 = 0;
  if ( v27 >= 4 )
  {
    v29 = 0;
    v30 = ((unsigned int)(v27 - 4) >> 2) + 1;
    v28 = 4 * v30;
    do
    {
      *(_DWORD *)(a2[182] + v29 + 100) = 0;
      *(_DWORD *)(a2[182] + v29 + 212) = 0;
      *(_DWORD *)(a2[182] + v29 + 324) = 0;
      *(_DWORD *)(a2[182] + v29 + 436) = 0;
      v29 += 448;
      --v30;
    }
    while ( v30 );
  }
  if ( v28 < v27 )
  {
    v31 = 112 * v28;
    v32 = v27 - v28;
    do
    {
      *(_DWORD *)(a2[182] + v31 + 100) = 0;
      v31 += 112;
      --v32;
    }
    while ( v32 );
  }
  if ( (int)a2[190] > 0 )
  {
    v52 = 0;
    v56 = a2[190];
    do
    {
      v55 = 3;
      v58 = v52 + a2[192];
      v33 = (int *)(v58 + 8);
      do
      {
        v34 = (*v33 - a2[182]) / 112;
        ++ptr[v34];
        v35 = *v33;
        v36 = fabsf(*(float *)(v58 + 48));
        ++v33;
        v10 = v55-- == 1;
        *(float *)(v35 + 100) = v36 + *(float *)(v35 + 100);
      }
      while ( !v10 );
      v52 += 64;
      --v56;
    }
    while ( v56 );
  }
  v37 = a2[180];
  v38 = 0;
  v57 = v37;
  if ( v37 >= 4 )
  {
    v39 = 0;
    v40 = ptr + 2;
    v41 = ((unsigned int)(v37 - 4) >> 2) + 1;
    v59 = 4 * v41;
    do
    {
      v42 = *(v40 - 2);
      v43 = a2[182];
      if ( v42 <= 0 )
        *(_DWORD *)(v43 + v39 + 100) = 0;
      else
        *(float *)(v43 + v39 + 100) = *(float *)(v43 + v39 + 100) / (float)v42;
      v44 = *(v40 - 1);
      v45 = a2[182];
      if ( v44 <= 0 )
        *(_DWORD *)(v45 + v39 + 212) = 0;
      else
        *(float *)(v45 + v39 + 212) = *(float *)(v45 + v39 + 212) / (float)v44;
      v46 = a2[182];
      if ( *v40 <= 0 )
        *(_DWORD *)(v46 + v39 + 324) = 0;
      else
        *(float *)(v46 + v39 + 324) = *(float *)(v46 + v39 + 324) / (float)*v40;
      v47 = v40[1];
      v48 = a2[182];
      if ( v47 <= 0 )
        *(_DWORD *)(v48 + v39 + 436) = 0;
      else
        *(float *)(v48 + v39 + 436) = *(float *)(v48 + v39 + 436) / (float)v47;
      v40 += 4;
      v39 += 448;
      --v41;
    }
    while ( v41 );
    v38 = v59;
    v37 = v57;
  }
  if ( v38 < v37 )
  {
    v49 = 112 * v38;
    do
    {
      v50 = ptr[v38];
      if ( v50 <= 0 )
        *(_DWORD *)(a2[182] + v49 + 100) = 0;
      else
        *(float *)(a2[182] + v49 + 100) = *(float *)(a2[182] + v49 + 100) / (float)v50;
      ++v38;
      v49 += 112;
    }
    while ( v38 < v57 );
  }
  if ( ptr )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr);
  }
}
