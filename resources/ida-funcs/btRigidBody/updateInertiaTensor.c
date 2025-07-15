void __usercall btRigidBody::updateInertiaTensor(btRigidBody *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // [esp+8h] [ebp-58h]
  float v9; // [esp+Ch] [ebp-54h]
  float v10; // [esp+10h] [ebp-50h]
  float v11; // [esp+14h] [ebp-4Ch]
  float v12; // [esp+18h] [ebp-48h]
  float v13; // [esp+1Ch] [ebp-44h]
  float v14; // [esp+20h] [ebp-40h]
  float v15; // [esp+24h] [ebp-3Ch]
  float v16; // [esp+28h] [ebp-38h]
  __int64 v17; // [esp+30h] [ebp-30h]
  float v18; // [esp+40h] [ebp-20h]
  float v19; // [esp+44h] [ebp-1Ch]
  float v20; // [esp+48h] [ebp-18h]
  __int64 v21; // [esp+58h] [ebp-8h]

  v2 = *(float *)(a2 + 56);
  v3 = *(float *)(a2 + 48);
  v4 = *(float *)(a2 + 40);
  v5 = *(float *)(a2 + 32);
  v6 = *(float *)(a2 + 16);
  v9 = v2 * *(float *)(a2 + 424);
  v8 = *(float *)(a2 + 52) * *(float *)(a2 + 420);
  v10 = v3 * *(float *)(a2 + 416);
  v18 = *(float *)(a2 + 20);
  v12 = v4 * *(float *)(a2 + 424);
  v11 = *(float *)(a2 + 36) * *(float *)(a2 + 420);
  v19 = *(float *)(a2 + 36);
  v20 = *(float *)(a2 + 52);
  v7 = *(float *)(a2 + 24);
  v13 = v5 * *(float *)(a2 + 416);
  v15 = v7 * *(float *)(a2 + 424);
  v16 = v18 * *(float *)(a2 + 420);
  v14 = v6 * *(float *)(a2 + 416);
  *((float *)&v17 + 1) = (float)((float)(v4 * v15) + (float)(v19 * v16)) + (float)(v5 * v14);
  *(float *)&v17 = (float)((float)(v7 * v15) + (float)(v6 * v14)) + (float)(v18 * v16);
  v21 = COERCE_UNSIGNED_INT((float)((float)(v2 * v9) + (float)(v20 * v8)) + (float)(v3 * v10));
  *(_QWORD *)(a2 + 272) = v17;
  *(_QWORD *)(a2 + 280) = COERCE_UNSIGNED_INT((float)((float)(v2 * v15) + (float)(v3 * v14)) + (float)(v20 * v16));
  *(_QWORD *)(a2 + 288) = __PAIR64__(
                            (float)((float)(v19 * v11) + (float)(v4 * v12)) + (float)(v5 * v13),
                            (float)((float)(v18 * v11) + (float)(v7 * v12)) + (float)(v6 * v13));
  *(_QWORD *)(a2 + 296) = COERCE_UNSIGNED_INT((float)((float)(v2 * v12) + (float)(v20 * v11)) + (float)(v3 * v13));
  *(_QWORD *)(a2 + 304) = __PAIR64__(
                            (float)((float)(v19 * v8) + (float)(v4 * v9)) + (float)(v5 * v10),
                            (float)((float)(v18 * v8) + (float)(v7 * v9)) + (float)(v6 * v10));
  *(_QWORD *)(a2 + 312) = v21;
}
