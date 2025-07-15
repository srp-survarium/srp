btMatrix3x3 *__usercall AngularImpulseMatrix@<eax>(
        const btMatrix3x3 *iia@<edx>,
        const btMatrix3x3 *iib@<ecx>,
        int a3@<esi>)
{
  float *v3; // eax
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v19; // [esp+Ch] [ebp-44h]
  float v20; // [esp+10h] [ebp-40h]
  float v21; // [esp+14h] [ebp-3Ch]
  float v22; // [esp+18h] [ebp-38h]
  float v23; // [esp+1Ch] [ebp-34h]
  _BYTE v24[48]; // [esp+20h] [ebp-30h] BYREF

  v3 = (float *)Add(iib, iia, (int)v24);
  v4 = v3[5];
  v5 = v3[10];
  v6 = v3[9];
  v7 = v3[8];
  v8 = (float)(v4 * v5) - (float)(v3[6] * v6);
  v9 = v3[4];
  v10 = (float)(v9 * v6) - (float)(v7 * v4);
  v11 = (float)(v7 * v3[6]) - (float)(v9 * v5);
  v12 = v3[1];
  v13 = *(float *)&clear_value / (float)((float)((float)(*v3 * v8) + (float)(v12 * v11)) + (float)(v10 * v3[2]));
  v23 = (float)((float)(*v3 * v4) - (float)(v12 * v3[4])) * v13;
  v22 = (float)((float)(v12 * v3[8]) - (float)(*v3 * v6)) * v13;
  v21 = v10 * v13;
  v14 = v3[2];
  v20 = (float)((float)(v14 * v3[4]) - (float)(*v3 * v3[6])) * v13;
  v15 = v13 * v11;
  v19 = (float)((float)(*v3 * v3[10]) - (float)(v14 * v3[8])) * v13;
  v16 = v12 * v3[6];
  v17 = v12 * v3[10];
  *(float *)(a3 + 8) = (float)(v16 - (float)(v14 * v3[5])) * v13;
  *(float *)(a3 + 4) = (float)((float)(v14 * v6) - v17) * v13;
  *(float *)a3 = v8 * v13;
  *(_DWORD *)(a3 + 12) = 0;
  *(float *)(a3 + 20) = v19;
  *(float *)(a3 + 24) = v20;
  *(float *)(a3 + 16) = v15;
  *(_DWORD *)(a3 + 28) = 0;
  *(float *)(a3 + 32) = v21;
  *(float *)(a3 + 36) = v22;
  *(float *)(a3 + 40) = v23;
  *(_DWORD *)(a3 + 44) = 0;
  return (btMatrix3x3 *)a3;
}
