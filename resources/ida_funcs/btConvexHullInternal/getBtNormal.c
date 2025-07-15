btVector3 *__userpurge btConvexHullInternal::getBtNormal@<eax>(
        btConvexHullInternal *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>,
        btConvexHullInternal::Face *result,
        btConvexHullInternal::Face *face)
{
  int v5; // edx
  float v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // edi
  int v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v18; // [esp+10h] [ebp-14h]
  float v19; // [esp+14h] [ebp-10h]
  float v20; // [esp+18h] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 112);
  v6 = *(float *)a2;
  v7 = *(float *)(a2 + 8);
  v8 = *(_DWORD *)(a2 + 104);
  v9 = 4 * *(_DWORD *)(a2 + 108);
  *(float *)((char *)&v19 + v9) = (float)result->dir1.x;
  v5 *= 4;
  *(float *)((char *)&v19 + v5) = (float)result->dir1.y;
  v8 *= 4;
  *(float *)((char *)&v19 + v8) = (float)result->dir1.z;
  v10 = *(float *)(a2 + 4);
  v11 = v6 * v19;
  v12 = v7 * v21;
  v13 = v10 * v20;
  *(float *)((char *)&v19 + v9) = (float)result->dir0.x;
  *(float *)((char *)&v19 + v5) = (float)result->dir0.y;
  *(float *)((char *)&v19 + v8) = (float)result->dir0.z;
  v14 = v6 * v19;
  v15 = v10 * v20;
  v16 = (float)((float)(v10 * v20) * v12) - (float)((float)(v7 * v21) * v13);
  v20 = (float)((float)(v7 * v21) * v11) - (float)(v14 * v12);
  v21 = (float)(v14 * v13) - (float)(v15 * v11);
  v19 = v16;
  v18 = 1.0 / sqrtf((float)((float)(v20 * v20) + (float)(v21 * v21)) + (float)(v16 * v16));
  *(float *)a3 = v19 * v18;
  *(float *)(a3 + 4) = v20 * v18;
  *(float *)(a3 + 8) = v21 * v18;
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
