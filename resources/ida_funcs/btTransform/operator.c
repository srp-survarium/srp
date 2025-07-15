btTransform *__usercall btTransform::operator*=@<eax>(btTransform *this@<ecx>, btTransform *result@<eax>)
{
  float v2; // xmm5_4
  float v3; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // [esp+Ch] [ebp-14h]
  float v17; // [esp+10h] [ebp-10h]
  float v18; // [esp+14h] [ebp-Ch]
  float v19; // [esp+18h] [ebp-8h]
  float v20; // [esp+1Ch] [ebp-4h]

  v2 = this->m_origin.mVec128.m128_f32[1];
  v3 = this->m_origin.mVec128.m128_f32[0];
  v4 = this->m_origin.mVec128.m128_f32[2];
  v5 = (float)((float)(result->m_basis.m_el[1].mVec128.m128_f32[1] * v2)
             + (float)(result->m_basis.m_el[1].mVec128.m128_f32[2] * v4))
     + (float)(result->m_basis.m_el[1].mVec128.m128_f32[0] * v3);
  v6 = (float)((float)(result->m_basis.m_el[2].mVec128.m128_f32[1] * v2)
             + (float)(result->m_basis.m_el[2].mVec128.m128_f32[2] * v4))
     + (float)(v3 * result->m_basis.m_el[2].mVec128.m128_f32[0]);
  v7 = result->m_origin.mVec128.m128_f32[1];
  result->m_origin.mVec128.m128_f32[0] = result->m_origin.mVec128.m128_f32[0]
                                       + (float)((float)((float)(v3 * result->m_basis.m_el[0].mVec128.m128_f32[0])
                                                       + (float)(result->m_basis.m_el[0].mVec128.m128_f32[1] * v2))
                                               + (float)(result->m_basis.m_el[0].mVec128.m128_f32[2] * v4));
  result->m_origin.mVec128.m128_f32[1] = v7 + v5;
  result->m_origin.mVec128.m128_f32[2] = result->m_origin.mVec128.m128_f32[2] + v6;
  v8 = this->m_basis.m_el[2].mVec128.m128_f32[2];
  v9 = this->m_basis.m_el[1].mVec128.m128_f32[2];
  v10 = (float)((float)(result->m_basis.m_el[2].mVec128.m128_f32[1] * v9)
              + (float)(result->m_basis.m_el[2].mVec128.m128_f32[2] * v8))
      + (float)(this->m_basis.m_el[0].mVec128.m128_f32[2] * result->m_basis.m_el[2].mVec128.m128_f32[0]);
  v11 = (float)((float)(result->m_basis.m_el[2].mVec128.m128_f32[1] * this->m_basis.m_el[1].mVec128.m128_f32[1])
              + (float)(result->m_basis.m_el[2].mVec128.m128_f32[2] * this->m_basis.m_el[2].mVec128.m128_f32[1]))
      + (float)(this->m_basis.m_el[0].mVec128.m128_f32[1] * result->m_basis.m_el[2].mVec128.m128_f32[0]);
  v12 = this->m_basis.m_el[2].mVec128.m128_f32[0];
  v13 = (float)((float)(result->m_basis.m_el[2].mVec128.m128_f32[1] * this->m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(result->m_basis.m_el[2].mVec128.m128_f32[2] * v12))
      + (float)(this->m_basis.m_el[0].mVec128.m128_f32[0] * result->m_basis.m_el[2].mVec128.m128_f32[0]);
  v14 = (float)((float)(result->m_basis.m_el[1].mVec128.m128_f32[1] * v9)
              + (float)(result->m_basis.m_el[1].mVec128.m128_f32[2] * v8))
      + (float)(result->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_basis.m_el[0].mVec128.m128_f32[2]);
  v15 = (float)((float)(result->m_basis.m_el[1].mVec128.m128_f32[1] * this->m_basis.m_el[1].mVec128.m128_f32[1])
              + (float)(result->m_basis.m_el[1].mVec128.m128_f32[2] * this->m_basis.m_el[2].mVec128.m128_f32[1]))
      + (float)(result->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_basis.m_el[0].mVec128.m128_f32[1]);
  v20 = (float)((float)(result->m_basis.m_el[1].mVec128.m128_f32[1] * this->m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(result->m_basis.m_el[1].mVec128.m128_f32[2] * v12))
      + (float)(result->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_basis.m_el[0].mVec128.m128_f32[0]);
  v18 = result->m_basis.m_el[0].mVec128.m128_f32[2];
  v17 = result->m_basis.m_el[0].mVec128.m128_f32[1];
  v19 = (float)((float)(result->m_basis.m_el[0].mVec128.m128_f32[0] * this->m_basis.m_el[0].mVec128.m128_f32[2])
              + (float)(v17 * v9))
      + (float)(v18 * this->m_basis.m_el[2].mVec128.m128_f32[2]);
  v16 = (float)((float)(result->m_basis.m_el[0].mVec128.m128_f32[0] * this->m_basis.m_el[0].mVec128.m128_f32[1])
              + (float)(v17 * this->m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v18 * this->m_basis.m_el[2].mVec128.m128_f32[1]);
  result->m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(result->m_basis.m_el[0].mVec128.m128_f32[0]
                                                              * this->m_basis.m_el[0].mVec128.m128_f32[0])
                                                      + (float)(v17 * this->m_basis.m_el[1].mVec128.m128_f32[0]))
                                              + (float)(v18 * v12);
  result->m_basis.m_el[0].mVec128.m128_f32[1] = v16;
  result->m_basis.m_el[0].mVec128.m128_f32[2] = v19;
  result->m_basis.m_el[0].mVec128.m128_i32[3] = 0;
  result->m_basis.m_el[1].mVec128.m128_f32[0] = v20;
  result->m_basis.m_el[1].mVec128.m128_f32[1] = v15;
  result->m_basis.m_el[1].mVec128.m128_f32[2] = v14;
  result->m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  result->m_basis.m_el[2].mVec128.m128_f32[0] = v13;
  result->m_basis.m_el[2].mVec128.m128_f32[1] = v11;
  result->m_basis.m_el[2].mVec128.m128_f32[2] = v10;
  result->m_basis.m_el[2].mVec128.m128_i32[3] = 0;
  return result;
}
