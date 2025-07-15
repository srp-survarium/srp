btMatrix3x3 *__usercall MassMatrix@<eax>(const btVector3 *r@<ecx>, int a2@<esi>, unsigned int im)
{
  float *v4; // edx
  float v5; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  btMatrix3x3 *v11; // eax
  float v13; // [esp+68h] [ebp-98h]
  unsigned __int64 v14; // [esp+68h] [ebp-98h]
  float v15; // [esp+6Ch] [ebp-94h]
  float v16; // [esp+70h] [ebp-90h]
  float v17; // [esp+74h] [ebp-8Ch]
  float v18; // [esp+74h] [ebp-8Ch]
  float v19; // [esp+78h] [ebp-88h]
  float v20; // [esp+7Ch] [ebp-84h]
  float v21; // [esp+7Ch] [ebp-84h]
  float v22; // [esp+80h] [ebp-80h]
  float v23; // [esp+84h] [ebp-7Ch]
  unsigned int v24; // [esp+84h] [ebp-7Ch]
  float v25; // [esp+88h] [ebp-78h]
  float v26; // [esp+88h] [ebp-78h]
  float v27; // [esp+90h] [ebp-70h]
  float v28; // [esp+94h] [ebp-6Ch]
  float v29; // [esp+98h] [ebp-68h]
  float v30; // [esp+9Ch] [ebp-64h]
  btMatrix3x3 b; // [esp+A0h] [ebp-60h] BYREF
  btMatrix3x3 v32; // [esp+D0h] [ebp-30h] BYREF

  Cross(r, &b);
  v5 = v4[6];
  v6 = v4[2];
  v7 = v4[10];
  v15 = v4[5];
  v22 = (float)((float)(v6 * b.m_el[2].mVec128.m128_f32[0]) + (float)(v5 * b.m_el[2].mVec128.m128_f32[1]))
      + (float)(v7 * b.m_el[2].mVec128.m128_f32[2]);
  v29 = v4[9];
  v20 = v4[1];
  v25 = v4[4];
  v17 = (float)((float)(v20 * b.m_el[2].mVec128.m128_f32[0]) + (float)(v15 * b.m_el[2].mVec128.m128_f32[1]))
      + (float)(v29 * b.m_el[2].mVec128.m128_f32[2]);
  v13 = v4[8];
  v16 = (float)((float)(*v4 * b.m_el[2].mVec128.m128_f32[0]) + (float)(v25 * b.m_el[2].mVec128.m128_f32[1]))
      + (float)(v13 * b.m_el[2].mVec128.m128_f32[2]);
  v8 = b.m_el[1].mVec128.m128_f32[0];
  v28 = (float)((float)(v6 * b.m_el[1].mVec128.m128_f32[0]) + (float)(v5 * b.m_el[1].mVec128.m128_f32[1]))
      + (float)(v7 * b.m_el[1].mVec128.m128_f32[2]);
  v19 = (float)((float)(v20 * b.m_el[1].mVec128.m128_f32[0]) + (float)(v15 * b.m_el[1].mVec128.m128_f32[1]))
      + (float)(v29 * b.m_el[1].mVec128.m128_f32[2]);
  v30 = (float)((float)(*v4 * b.m_el[1].mVec128.m128_f32[0]) + (float)(v25 * b.m_el[1].mVec128.m128_f32[1]))
      + (float)(v13 * b.m_el[1].mVec128.m128_f32[2]);
  v27 = (float)((float)(v5 * b.m_el[0].mVec128.m128_f32[1]) + (float)(v6 * b.m_el[0].mVec128.m128_f32[0]))
      + (float)(v7 * b.m_el[0].mVec128.m128_f32[2]);
  v21 = (float)((float)(v15 * b.m_el[0].mVec128.m128_f32[1]) + (float)(v20 * b.m_el[0].mVec128.m128_f32[0]))
      + (float)(v29 * b.m_el[0].mVec128.m128_f32[2]);
  v23 = (float)((float)(v25 * b.m_el[0].mVec128.m128_f32[1]) + (float)(*v4 * b.m_el[0].mVec128.m128_f32[0]))
      + (float)(v13 * b.m_el[0].mVec128.m128_f32[2]);
  *((float *)&v14 + 1) = (float)((float)(b.m_el[1].mVec128.m128_f32[2] * v17)
                               + (float)(b.m_el[2].mVec128.m128_f32[2] * v22))
                       + (float)(b.m_el[0].mVec128.m128_f32[2] * v16);
  *(float *)&v14 = (float)((float)(b.m_el[1].mVec128.m128_f32[1] * v17) + (float)(b.m_el[2].mVec128.m128_f32[1] * v22))
                 + (float)(b.m_el[0].mVec128.m128_f32[1] * v16);
  v18 = (float)((float)(b.m_el[1].mVec128.m128_f32[0] * v17) + (float)(b.m_el[2].mVec128.m128_f32[0] * v22))
      + (float)(b.m_el[0].mVec128.m128_f32[0] * v16);
  v26 = (float)((float)(b.m_el[1].mVec128.m128_f32[1] * v19) + (float)(b.m_el[2].mVec128.m128_f32[1] * v28))
      + (float)(b.m_el[0].mVec128.m128_f32[1] * v30);
  v9 = v23;
  *(float *)&v24 = (float)((float)(b.m_el[1].mVec128.m128_f32[2] * v21) + (float)(b.m_el[2].mVec128.m128_f32[2] * v27))
                 + (float)(b.m_el[0].mVec128.m128_f32[2] * v23);
  b.m_el[0].mVec128.m128_f32[1] = (float)((float)(b.m_el[1].mVec128.m128_f32[1] * v21)
                                        + (float)(b.m_el[2].mVec128.m128_f32[1] * v27))
                                + (float)(b.m_el[0].mVec128.m128_f32[1] * v9);
  b.m_el[1].mVec128.m128_f32[0] = (float)((float)(b.m_el[1].mVec128.m128_f32[0] * v19)
                                        + (float)(b.m_el[2].mVec128.m128_f32[0] * v28))
                                + (float)(b.m_el[0].mVec128.m128_f32[0] * v30);
  b.m_el[1].mVec128.m128_f32[1] = v26;
  b.m_el[1].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                    (float)((float)(b.m_el[1].mVec128.m128_f32[2] * v19)
                                          + (float)(b.m_el[2].mVec128.m128_f32[2] * v28))
                                  + (float)(b.m_el[0].mVec128.m128_f32[2] * v30));
  v10 = (float)(v8 * v21) + (float)(b.m_el[2].mVec128.m128_f32[0] * v27);
  b.m_el[2].mVec128.m128_f32[0] = v18;
  b.m_el[0].mVec128.m128_f32[0] = v10 + (float)(b.m_el[0].mVec128.m128_f32[0] * v9);
  *(unsigned __int64 *)((char *)b.m_el[2].mVec128.m128_u64 + 4) = v14;
  b.m_el[0].mVec128.m128_u64[1] = v24;
  b.m_el[2].mVec128.m128_i32[3] = 0;
  v11 = Diagonal(&v32, im);
  Sub(&b, v11, a2);
  return (btMatrix3x3 *)a2;
}
