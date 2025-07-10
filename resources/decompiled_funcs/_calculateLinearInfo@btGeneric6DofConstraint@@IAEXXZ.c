void __usercall btGeneric6DofConstraint::calculateLinearInfo(btGeneric6DofConstraint *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm5_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  unsigned int v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // [esp+Ch] [ebp-24h]
  float v24; // [esp+14h] [ebp-1Ch]
  float v25; // [esp+18h] [ebp-18h]
  __int64 v26; // [esp+20h] [ebp-10h]
  unsigned int v27; // [esp+28h] [ebp-8h]
  unsigned int v28; // [esp+28h] [ebp-8h]

  *(float *)&v26 = *(float *)(a2 + 1280) - *(float *)(a2 + 1216);
  *((float *)&v26 + 1) = *(float *)(a2 + 1284) - *(float *)(a2 + 1220);
  *(float *)&v27 = *(float *)(a2 + 1288) - *(float *)(a2 + 1224);
  *(_QWORD *)(a2 + 1360) = v26;
  *(_QWORD *)(a2 + 1368) = v27;
  v2 = *(float *)(a2 + 1188);
  v3 = *(float *)(a2 + 1208);
  v4 = *(float *)(a2 + 1204);
  v5 = (float)(v2 * v3) - (float)(*(float *)(a2 + 1192) * v4);
  v6 = (float)(*(float *)(a2 + 1200) * *(float *)(a2 + 1192)) - (float)(*(float *)(a2 + 1184) * v3);
  v7 = (float)(*(float *)(a2 + 1184) * v4) - (float)(*(float *)(a2 + 1200) * v2);
  v23 = *(float *)(a2 + 1172);
  v8 = *(float *)&clear_value
     / (float)((float)((float)(v23 * v6) + (float)(v7 * *(float *)(a2 + 1176))) + (float)(v5 * *(float *)(a2 + 1168)));
  v9 = *(float *)(a2 + 1168);
  v25 = v7 * v8;
  v10 = *(float *)(a2 + 1176);
  v24 = (float)((float)(v9 * *(float *)(a2 + 1208)) - (float)(v10 * *(float *)(a2 + 1200))) * v8;
  v11 = *(float *)(a2 + 1364);
  *(float *)&v12 = (float)((float)((float)(v5 * v8) * *(float *)(a2 + 1360))
                         + (float)(*(float *)(a2 + 1368)
                                 * (float)((float)((float)(v23 * *(float *)(a2 + 1192)) - (float)(v10 * v2)) * v8)))
                 + (float)((float)((float)((float)(v10 * *(float *)(a2 + 1204)) - (float)(v23 * *(float *)(a2 + 1208)))
                                 * v8)
                         * v11);
  v13 = *(float *)(a2 + 1360);
  *(float *)&v28 = (float)((float)(v25 * v13)
                         + (float)(*(float *)(a2 + 1368)
                                 * (float)((float)((float)(v9 * v2) - (float)(v23 * *(float *)(a2 + 1184))) * v8)))
                 + (float)((float)((float)((float)(v23 * *(float *)(a2 + 1200)) - (float)(v9 * *(float *)(a2 + 1204)))
                                 * v8)
                         * v11);
  *(_QWORD *)(a2 + 1360) = __PAIR64__(
                             (float)((float)((float)(v6 * v8) * v13)
                                   + (float)(*(float *)(a2 + 1368)
                                           * (float)((float)((float)(*(float *)(a2 + 1176) * *(float *)(a2 + 1184))
                                                           - (float)(v9 * *(float *)(a2 + 1192)))
                                                   * v8)))
                           + (float)(v24 * v11),
                             v12);
  *(_QWORD *)(a2 + 1368) = v28;
  v14 = *(float *)(a2 + 1360);
  *(float *)(a2 + 928) = v14;
  v15 = *(float *)(a2 + 752);
  v16 = *(float *)(a2 + 768);
  if ( v15 > v16 )
    goto LABEL_6;
  if ( v15 > v14 )
  {
    *(_DWORD *)(a2 + 944) = 2;
    *(float *)(a2 + 912) = v14 - v15;
    goto LABEL_7;
  }
  if ( v14 <= v16 )
  {
LABEL_6:
    *(_DWORD *)(a2 + 912) = 0;
    *(_DWORD *)(a2 + 944) = 0;
  }
  else
  {
    *(_DWORD *)(a2 + 944) = 1;
    *(float *)(a2 + 912) = v14 - v16;
  }
LABEL_7:
  v17 = *(float *)(a2 + 1364);
  *(float *)(a2 + 932) = v17;
  v18 = *(float *)(a2 + 756);
  v19 = *(float *)(a2 + 772);
  if ( v18 > v19 )
    goto LABEL_12;
  if ( v18 <= v17 )
  {
    if ( v17 > v19 )
    {
      *(_DWORD *)(a2 + 948) = 1;
      *(float *)(a2 + 916) = v17 - v19;
      goto LABEL_13;
    }
LABEL_12:
    *(_DWORD *)(a2 + 916) = 0;
    *(_DWORD *)(a2 + 948) = 0;
    goto LABEL_13;
  }
  *(_DWORD *)(a2 + 948) = 2;
  *(float *)(a2 + 916) = v17 - v18;
LABEL_13:
  v20 = *(float *)(a2 + 1368);
  *(float *)(a2 + 936) = v20;
  v21 = *(float *)(a2 + 760);
  v22 = *(float *)(a2 + 776);
  if ( v21 > v22 )
    goto LABEL_18;
  if ( v21 > v20 )
  {
    *(_DWORD *)(a2 + 952) = 2;
    *(float *)(a2 + 920) = v20 - v21;
    return;
  }
  if ( v20 <= v22 )
  {
LABEL_18:
    *(_DWORD *)(a2 + 920) = 0;
    *(_DWORD *)(a2 + 952) = 0;
  }
  else
  {
    *(_DWORD *)(a2 + 952) = 1;
    *(float *)(a2 + 920) = v20 - v22;
  }
}
