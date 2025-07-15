void __usercall btSoftBody::dampClusters(btSoftBody *this@<ecx>, int a2@<edi>)
{
  int i; // ebx
  int v3; // ecx
  int j; // esi
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4

  for ( i = 0; i < *(_DWORD *)(a2 + 1072); ++i )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 1080) + 4 * i);
    if ( *(float *)(v3 + 372) > 0.0 )
    {
      for ( j = 0; j < *(_DWORD *)(v3 + 24); ++j )
      {
        v5 = *(float **)(*(_DWORD *)(v3 + 32) + 4 * j);
        if ( v5[24] > 0.0 )
        {
          v6 = v5[10] - *(float *)(v3 + 248);
          v7 = v5[9] - *(float *)(v3 + 244);
          v8 = v5[8] - *(float *)(v3 + 240);
          v9 = *(float *)(v3 + 336) + (float)((float)(*(float *)(v3 + 356) * v6) - (float)(*(float *)(v3 + 360) * v7));
          v10 = *(float *)(v3 + 340) + (float)((float)(*(float *)(v3 + 360) * v8) - (float)(*(float *)(v3 + 352) * v6));
          v11 = *(float *)(v3 + 344) + (float)((float)(*(float *)(v3 + 352) * v7) - (float)(*(float *)(v3 + 356) * v8));
          v12 = v5[14];
          if ( (float)((float)((float)(v5[12] * v5[12]) + (float)(v5[13] * v5[13])) + (float)(v12 * v12)) >= (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v9 * v9)) )
          {
            v13 = v11 - v12;
            v14 = (float)(*(float *)(v3 + 372) * (float)(v9 - v5[12])) + v5[12];
            v15 = (float)(*(float *)(v3 + 372) * (float)(v10 - v5[13])) + v5[13];
            v16 = (float)(*(float *)(v3 + 372) * v13) + v5[14];
            v5[12] = v14;
            v5[13] = v15;
            v5[14] = v16;
          }
        }
      }
    }
  }
}
