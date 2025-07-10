void __usercall btSoftBody::getVolume(btSoftBody *this@<ecx>, int *a2@<edi>)
{
  int v2; // ebx
  float v3; // xmm6_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  _DWORD *v6; // eax
  unsigned int v7; // edx
  float *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float *v12; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float *v26; // ecx
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm7_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // [esp+70h] [ebp-4Ch]
  float v37; // [esp+74h] [ebp-48h]
  float v38; // [esp+7Ch] [ebp-40h]
  float v39; // [esp+8Ch] [ebp-30h]
  float v40; // [esp+8Ch] [ebp-30h]
  __int64 v41; // [esp+9Ch] [ebp-20h]
  float v42; // [esp+B0h] [ebp-Ch]
  float v43; // [esp+B0h] [ebp-Ch]

  if ( a2[180] > 0 )
  {
    v2 = a2[190];
    v41 = *(_QWORD *)(a2[182] + 16);
    v3 = *(float *)(a2[182] + 20);
    v4 = *(float *)(a2[182] + 16);
    v5 = *(float *)(a2[182] + 24);
    v37 = 0.0;
    v36 = 0.0;
    if ( v2 >= 2 )
    {
      v6 = (_DWORD *)(a2[192] + 76);
      v7 = ((unsigned int)(v2 - 2) >> 1) + 1;
      do
      {
        v8 = (float *)*(v6 - 15);
        v9 = v8[5];
        v10 = v8[6];
        v11 = v8[4] - v4;
        v12 = (float *)*(v6 - 16);
        v13 = v12[6];
        v38 = v11;
        v14 = v12[4] - v4;
        v15 = v12[5];
        v16 = (float *)*(v6 - 17);
        v39 = v14;
        v17 = v9 - v3;
        v18 = v10 - v5;
        v19 = v15 - v3;
        v20 = (float)(v18 * v19) - (float)((float)(v13 - v5) * v17);
        v21 = v16[4];
        v22 = (float)((float)(v13 - v5) * v38) - (float)(v18 * v39);
        v23 = v16[5];
        v42 = v22;
        v24 = (float)(v17 * v39) - (float)(v19 * v38);
        v25 = v16[6];
        v26 = (float *)v6[1];
        v27 = (float)((float)((float)((float)(v25 - v5) * v24) + (float)((float)(v23 - v3) * v42))
                    + (float)((float)(v21 - *(float *)&v41) * v20))
            + v37;
        v28 = v26[4];
        v37 = v27;
        v29 = *(float *)(*v6 + 24);
        v40 = *(float *)(*v6 + 16) - *(float *)&v41;
        v30 = v26[5] - v3;
        v31 = v26[6] - v5;
        v32 = *(float *)(*v6 + 20) - v3;
        v33 = (float)(v31 * v32) - (float)((float)(v29 - v5) * v30);
        v43 = (float)((float)(v29 - v5) * (float)(v28 - *(float *)&v41)) - (float)(v31 * v40);
        v34 = (float)(v30 * v40) - (float)(v32 * (float)(v28 - *(float *)&v41));
        v4 = *(float *)(a2[182] + 16);
        v35 = (float)((float)((float)((float)(*(float *)(*(v6 - 1) + 24) - v5) * v34)
                            + (float)((float)(*(float *)(*(v6 - 1) + 20) - v3) * v43))
                    + (float)((float)(*(float *)(*(v6 - 1) + 16) - *(float *)&v41) * v33))
            + v36;
        v6 += 32;
        --v7;
        v36 = v35;
      }
      while ( v7 );
    }
  }
}
