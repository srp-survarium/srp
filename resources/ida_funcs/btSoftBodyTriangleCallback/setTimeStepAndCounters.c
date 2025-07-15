void __usercall btSoftBodyTriangleCallback::setTimeStepAndCounters(
        btSoftBodyTriangleCallback *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>,
        float a4@<xmm0>)
{
  int v4; // ecx
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // [esp+1CCh] [ebp-B4h]
  float v14; // [esp+1D0h] [ebp-B0h]
  float v15; // [esp+1D4h] [ebp-ACh]
  float v16; // [esp+1D8h] [ebp-A8h]
  float v17; // [esp+1D8h] [ebp-A8h]
  float v18; // [esp+1DCh] [ebp-A4h]
  float v19; // [esp+1E0h] [ebp-A0h]
  float v20; // [esp+1E0h] [ebp-A0h]
  float _X; // [esp+1E4h] [ebp-9Ch]
  float v22; // [esp+1E4h] [ebp-9Ch]
  float v23; // [esp+1E8h] [ebp-98h]
  float v24; // [esp+1E8h] [ebp-98h]
  float v25; // [esp+1ECh] [ebp-94h]
  float v26; // [esp+1ECh] [ebp-94h]
  float v27; // [esp+1F0h] [ebp-90h]
  float v28; // [esp+1F0h] [ebp-90h]
  float v29; // [esp+1F4h] [ebp-8Ch]
  float v30; // [esp+1F4h] [ebp-8Ch]
  float v31; // [esp+1F8h] [ebp-88h]
  float v32; // [esp+1F8h] [ebp-88h]
  float v33; // [esp+200h] [ebp-80h]
  __int64 v34; // [esp+200h] [ebp-80h]
  float v35; // [esp+204h] [ebp-7Ch]
  float v36; // [esp+208h] [ebp-78h]
  unsigned int v37; // [esp+208h] [ebp-78h]
  float v38; // [esp+210h] [ebp-70h]
  __int64 v39; // [esp+210h] [ebp-70h]
  float v40; // [esp+214h] [ebp-6Ch]
  float v41; // [esp+218h] [ebp-68h]
  __int64 v42; // [esp+218h] [ebp-68h]
  float v43; // [esp+220h] [ebp-60h] BYREF
  float v44; // [esp+224h] [ebp-5Ch]
  float v45; // [esp+228h] [ebp-58h]
  float v46; // [esp+230h] [ebp-50h] BYREF
  float v47; // [esp+234h] [ebp-4Ch]
  float v48[2]; // [esp+238h] [ebp-48h]
  btTransform v49; // [esp+240h] [ebp-40h] BYREF

  *(_DWORD *)(a3 + 56) = a2;
  *(_DWORD *)(a3 + 48) = this;
  v4 = *(_DWORD *)(a3 + 4);
  *(float *)(a3 + 60) = a4 + 0.059999999;
  (*(void (__thiscall **)(int, float *, float *))(*(_DWORD *)v4 + 24))(v4, &v46, &v43);
  v33 = (float)(v43 - v46) * 0.5;
  v35 = (float)(v44 - v47) * 0.5;
  v36 = (float)(v45 - v48[0]) * 0.5;
  v27 = (float)(v46 + v43) * 0.5;
  v29 = (float)(v47 + v44) * 0.5;
  v31 = (float)(v45 + v48[0]) * 0.5;
  v5 = (float *)btTransform::inverse((btTransform *)(*(_DWORD *)(a3 + 8) + 16), &v49);
  v6 = v5[1];
  v7 = *v5;
  v8 = v5[2];
  v38 = (float)((float)((float)(*v5 * v27) + (float)(v6 * v29)) + (float)(v31 * v8)) + v5[12];
  v40 = (float)((float)((float)(v5[5] * v29) + (float)(v5[6] * v31)) + (float)(v5[4] * v27)) + v5[13];
  v41 = (float)((float)((float)(v5[9] * v29) + (float)(v5[10] * v31)) + (float)(v27 * v5[8])) + v5[14];
  _X = (float)((float)(v5[10] + v5[8]) * 0.0) + v5[9];
  v16 = (float)((float)(v5[10] + v5[9]) * 0.0) + v5[8];
  v25 = (float)((float)(v5[5] + v5[4]) * 0.0) + v5[6];
  v19 = (float)((float)(v5[6] + v5[4]) * 0.0) + v5[5];
  v23 = (float)((float)(v5[6] + v5[5]) * 0.0) + v5[4];
  v9 = *(float *)(a3 + 60);
  v28 = v9 + v33;
  v30 = v35 + v9;
  v32 = v36 + v9;
  v14 = fabsf((float)((float)(v5[9] + v5[8]) * 0.0) + v5[10]);
  v22 = fabsf(_X);
  v17 = fabsf(v16);
  v26 = fabsf(v25);
  v20 = fabsf(v19);
  v24 = fabsf(v23);
  v18 = fabsf((float)((float)(v7 * 0.0) + (float)(v6 * 0.0)) + v8);
  v13 = fabsf((float)((float)(v8 * 0.0) + (float)(v7 * 0.0)) + v6);
  v15 = fabsf((float)((float)(v8 * 0.0) + (float)(v6 * 0.0)) + v7);
  v10 = (float)((float)((float)(v35 + v9) * v13) + (float)((float)(v36 + v9) * v18)) + (float)(v15 * (float)(v9 + v33));
  v11 = (float)((float)(v30 * v22) + (float)(v32 * v14)) + (float)(v28 * v17);
  v12 = (float)((float)(v32 * v26) + (float)(v30 * v20)) + (float)(v24 * v28);
  *(float *)&v34 = v38 - v10;
  *((float *)&v34 + 1) = v40 - v12;
  *(float *)&v37 = v41 - v11;
  *(float *)&v39 = v10 + v38;
  *((float *)&v39 + 1) = v12 + v40;
  *(_QWORD *)(a3 + 16) = v34;
  *(_QWORD *)(a3 + 32) = v39;
  *(float *)&v42 = v11 + v41;
  HIDWORD(v42) = 0;
  *(_QWORD *)(a3 + 24) = v37;
  *(_QWORD *)(a3 + 40) = v42;
}
