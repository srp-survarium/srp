btMatrix3x3 *__usercall ImpulseMatrix@<eax>(
        const btVector3 *rb@<ecx>,
        int a2@<edi>,
        unsigned int ima,
        const btMatrix3x3 *iia,
        const btVector3 *ra,
        unsigned int imb)
{
  btMatrix3x3 *v7; // ebx
  btMatrix3x3 *v8; // eax
  float *v9; // eax
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v24; // [esp+10h] [ebp-A4h]
  float v25; // [esp+14h] [ebp-A0h]
  float v26; // [esp+18h] [ebp-9Ch]
  float v27; // [esp+1Ch] [ebp-98h]
  float v28; // [esp+20h] [ebp-94h]
  _BYTE v29[48]; // [esp+24h] [ebp-90h] BYREF
  _BYTE v30[48]; // [esp+54h] [ebp-60h] BYREF
  _BYTE v31[48]; // [esp+84h] [ebp-30h] BYREF

  v7 = MassMatrix(rb, (int)v29, imb);
  v8 = MassMatrix(ra, (int)v30, ima);
  v9 = (float *)Add(v7, v8, (int)v31);
  v10 = v9[5];
  v11 = v9[10];
  v12 = v9[9];
  v13 = v9[8];
  v14 = (float)(v10 * v11) - (float)(v9[6] * v12);
  v15 = (float)(v9[4] * v12) - (float)(v13 * v10);
  v16 = (float)(v13 * v9[6]) - (float)(v9[4] * v11);
  v17 = v9[1];
  v18 = *(float *)&clear_value / (float)((float)((float)(*v9 * v14) + (float)(v17 * v16)) + (float)(v15 * v9[2]));
  v26 = (float)((float)(*v9 * v10) - (float)(v17 * v9[4])) * v18;
  v28 = v15 * v18;
  v19 = v9[2];
  v25 = (float)((float)(v17 * v9[8]) - (float)(*v9 * v12)) * v18;
  v27 = (float)((float)(v19 * v9[4]) - (float)(*v9 * v9[6])) * v18;
  v24 = (float)((float)(*v9 * v9[10]) - (float)(v19 * v9[8])) * v18;
  v20 = v18 * v16;
  v21 = v17 * v9[6];
  v22 = v17 * v9[10];
  *(float *)(a2 + 8) = (float)(v21 - (float)(v19 * v9[5])) * v18;
  *(float *)(a2 + 4) = (float)((float)(v19 * v12) - v22) * v18;
  *(float *)a2 = v14 * v18;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 20) = v24;
  *(float *)(a2 + 24) = v27;
  *(float *)(a2 + 16) = v20;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 32) = v28;
  *(float *)(a2 + 36) = v25;
  *(float *)(a2 + 40) = v26;
  *(_DWORD *)(a2 + 44) = 0;
  return (btMatrix3x3 *)a2;
}
