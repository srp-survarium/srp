btMatrix3x3 *__usercall ImpulseMatrix_0@<eax>(
        const btVector3 *r@<ecx>,
        int a2@<edi>,
        float dt,
        unsigned int ima,
        unsigned int imb)
{
  btMatrix3x3 *v6; // eax
  const btMatrix3x3 *v7; // ecx
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm7_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v30; // [esp+8h] [ebp-FCh]
  float v31; // [esp+8h] [ebp-FCh]
  float v32; // [esp+Ch] [ebp-F8h]
  float v33; // [esp+14h] [ebp-F0h]
  float v34; // [esp+18h] [ebp-ECh]
  float v35; // [esp+1Ch] [ebp-E8h]
  float v36; // [esp+20h] [ebp-E4h]
  float v37; // [esp+24h] [ebp-E0h]
  float v38; // [esp+28h] [ebp-DCh]
  float v39; // [esp+2Ch] [ebp-D8h]
  float v40; // [esp+30h] [ebp-D4h]
  float v41; // [esp+38h] [ebp-CCh]
  _BYTE v42[48]; // [esp+44h] [ebp-C0h] BYREF
  _BYTE v43[48]; // [esp+74h] [ebp-90h] BYREF
  btMatrix3x3 v44; // [esp+A4h] [ebp-60h] BYREF
  btMatrix3x3 v45; // [esp+D4h] [ebp-30h] BYREF

  MassMatrix(r, (int)v42, imb);
  v6 = Diagonal(&v44, ima);
  v8 = (float *)Add(v7, v6, (int)v43);
  v9 = v8[5];
  v10 = v8[9];
  v11 = v8[10];
  v12 = (float)(v9 * v11) - (float)(v8[6] * v10);
  v13 = v8[8];
  v14 = (float)(v8[4] * v10) - (float)(v13 * v9);
  v41 = (float)(v13 * v8[6]) - (float)(v8[4] * v11);
  v15 = *(float *)&clear_value / (float)((float)((float)(*v8 * v12) + (float)(v8[1] * v41)) + (float)(v14 * v8[2]));
  v30 = v8[1];
  v36 = v14 * v15;
  v16 = v8[2];
  v35 = (float)((float)(v16 * v8[4]) - (float)(*v8 * v8[6])) * v15;
  v17 = (float)((float)(*v8 * v9) - (float)(v30 * v8[4])) * v15;
  v18 = (float)((float)(v30 * v8[8]) - (float)(*v8 * v10)) * v15;
  v33 = v15 * v41;
  v37 = (float)((float)(*v8 * v11) - (float)(v16 * v8[8])) * v15;
  v19 = (float)((float)(v30 * v8[6]) - (float)(v16 * v9)) * v15;
  v32 = (float)((float)(v16 * v8[9]) - (float)(v30 * v11)) * v15;
  v34 = v12 * v15;
  v20 = (float *)Diagonal(&v45, COERCE_UNSIGNED_INT(*(float *)&clear_value / dt));
  v21 = (float)((float)(v20[9] * v35) + (float)(v20[10] * v17)) + (float)(v20[8] * v19);
  v22 = (float)((float)(v20[9] * v37) + (float)(v20[10] * v18)) + (float)(v20[8] * v32);
  v23 = (float)((float)(v20[9] * (float)(v15 * v41)) + (float)(v20[10] * v36)) + (float)(v20[8] * (float)(v12 * v15));
  v39 = (float)((float)(v20[5] * v35) + (float)(v20[6] * v17)) + (float)(v19 * v20[4]);
  v38 = (float)((float)(v20[5] * v37) + (float)(v20[6] * v18)) + (float)(v20[4] * v32);
  v31 = v20[2];
  v40 = (float)((float)(v20[5] * (float)(v15 * v41)) + (float)(v20[6] * v36)) + (float)(v20[4] * v34);
  v24 = *v20 * v19;
  v25 = v31 * v17;
  v26 = v20[1];
  v27 = *v20 * v34;
  v28 = (float)(*v20 * v32) + (float)(v31 * v18);
  *(float *)(a2 + 8) = (float)(v24 + v25) + (float)(v26 * v35);
  *(float *)(a2 + 4) = v28 + (float)(v26 * v37);
  *(float *)a2 = (float)(v27 + (float)(v31 * v36)) + (float)(v26 * v33);
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 16) = v40;
  *(float *)(a2 + 20) = v38;
  *(float *)(a2 + 24) = v39;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 32) = v23;
  *(float *)(a2 + 36) = v22;
  *(float *)(a2 + 40) = v21;
  *(_DWORD *)(a2 + 44) = 0;
  return (btMatrix3x3 *)a2;
}
