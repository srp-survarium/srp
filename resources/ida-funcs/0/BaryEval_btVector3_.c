btVector3 *__usercall BaryEval_btVector3_@<eax>(
        const btVector3 *a@<edi>,
        const btVector3 *b@<esi>,
        const btVector3 *c@<edx>,
        const btVector3 *coord@<ecx>,
        btVector3 *a5)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  btVector3 *result; // eax
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // [esp+18h] [ebp-8h]

  v5 = coord->mVec128.m128_f32[1];
  v6 = coord->mVec128.m128_f32[2];
  v7 = coord->mVec128.m128_f32[0];
  result = a5;
  v16 = b->mVec128.m128_f32[2] * v5;
  v9 = c->mVec128.m128_f32[0] * v6;
  v10 = c->mVec128.m128_f32[2] * v6;
  v11 = c->mVec128.m128_f32[1] * v6;
  v12 = b->mVec128.m128_f32[1] * v5;
  v13 = b->mVec128.m128_f32[0] * v5;
  v14 = a->mVec128.m128_f32[0];
  v15 = (float)(a->mVec128.m128_f32[2] * coord->mVec128.m128_f32[0]) + v16;
  a5->mVec128.m128_f32[1] = (float)(v12 + (float)(a->mVec128.m128_f32[1] * coord->mVec128.m128_f32[0])) + v11;
  a5->mVec128.m128_f32[0] = (float)((float)(v14 * v7) + v13) + v9;
  a5->mVec128.m128_f32[2] = v15 + v10;
  a5->mVec128.m128_i32[3] = 0;
  return result;
}
