btTransform *__usercall btTransform::operator*=@<eax>(btTransform *this@<esi>, const btTransform *t@<eax>)
{
  float v2; // xmm5_4
  float v3; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm7_4
  float v34; // xmm7_4
  float v35; // xmm4_4
  float v36; // xmm0_4
  const float *v38; // [esp+0h] [ebp-30h]
  float v39; // [esp+Ch] [ebp-24h] BYREF
  float v40; // [esp+10h] [ebp-20h] BYREF
  float v41; // [esp+14h] [ebp-1Ch] BYREF
  float v42; // [esp+18h] [ebp-18h] BYREF
  float v43; // [esp+1Ch] [ebp-14h] BYREF
  float v44; // [esp+20h] [ebp-10h] BYREF
  float v45; // [esp+24h] [ebp-Ch] BYREF
  float v46; // [esp+28h] [ebp-8h] BYREF
  float v47; // [esp+2Ch] [ebp-4h] BYREF

  v2 = t->m_origin.mVec128.m128_f32[1];
  v3 = t->m_origin.mVec128.m128_f32[0];
  v4 = t->m_origin.mVec128.m128_f32[2];
  v5 = (float)((float)(this->m_basis.m_el[1].mVec128.m128_f32[1] * v2)
             + (float)(this->m_basis.m_el[1].mVec128.m128_f32[2] * v4))
     + (float)(this->m_basis.m_el[1].mVec128.m128_f32[0] * v3);
  v6 = (float)((float)(this->m_basis.m_el[2].mVec128.m128_f32[1] * v2)
             + (float)(this->m_basis.m_el[2].mVec128.m128_f32[2] * v4))
     + (float)(v3 * this->m_basis.m_el[2].mVec128.m128_f32[0]);
  v7 = this->m_origin.mVec128.m128_f32[0]
     + (float)((float)((float)(v3 * this->m_basis.m_el[0].mVec128.m128_f32[0])
                     + (float)(this->m_basis.m_el[0].mVec128.m128_f32[1] * v2))
             + (float)(this->m_basis.m_el[0].mVec128.m128_f32[2] * v4));
  this->m_origin.mVec128.m128_f32[1] = this->m_origin.mVec128.m128_f32[1] + v5;
  v8 = this->m_origin.mVec128.m128_f32[2];
  this->m_origin.mVec128.m128_f32[0] = v7;
  this->m_origin.mVec128.m128_f32[2] = v8 + v6;
  v9 = t->m_basis.m_el[2].mVec128.m128_f32[2];
  v10 = t->m_basis.m_el[1].mVec128.m128_f32[2];
  v11 = t->m_basis.m_el[0].mVec128.m128_f32[2];
  v12 = t->m_basis.m_el[2].mVec128.m128_f32[1];
  v13 = this->m_basis.m_el[2].mVec128.m128_f32[1];
  v14 = this->m_basis.m_el[2].mVec128.m128_f32[2] * v12;
  v15 = t->m_basis.m_el[0].mVec128.m128_f32[1] * this->m_basis.m_el[2].mVec128.m128_f32[0];
  v39 = (float)((float)(v13 * v10) + (float)(this->m_basis.m_el[2].mVec128.m128_f32[2] * v9))
      + (float)(v11 * this->m_basis.m_el[2].mVec128.m128_f32[0]);
  v16 = t->m_basis.m_el[1].mVec128.m128_f32[1];
  v17 = (float)(v13 * v16) + v14;
  v18 = this->m_basis.m_el[2].mVec128.m128_f32[1];
  v19 = v17 + v15;
  v20 = t->m_basis.m_el[2].mVec128.m128_f32[0];
  v40 = v19;
  v21 = this->m_basis.m_el[2].mVec128.m128_f32[2] * v20;
  v22 = t->m_basis.m_el[0].mVec128.m128_f32[0];
  v23 = (float)((float)(v18 * t->m_basis.m_el[1].mVec128.m128_f32[0]) + v21)
      + (float)(t->m_basis.m_el[0].mVec128.m128_f32[0] * this->m_basis.m_el[2].mVec128.m128_f32[0]);
  v24 = this->m_basis.m_el[1].mVec128.m128_f32[1];
  v41 = v23;
  v42 = (float)((float)(v24 * v10) + (float)(this->m_basis.m_el[1].mVec128.m128_f32[2] * v9))
      + (float)(this->m_basis.m_el[1].mVec128.m128_f32[0] * v11);
  v25 = (float)(this->m_basis.m_el[1].mVec128.m128_f32[1] * v16)
      + (float)(this->m_basis.m_el[1].mVec128.m128_f32[2] * v12);
  v26 = t->m_basis.m_el[1].mVec128.m128_f32[0];
  v27 = this->m_basis.m_el[1].mVec128.m128_f32[2];
  v43 = v25 + (float)(this->m_basis.m_el[1].mVec128.m128_f32[0] * t->m_basis.m_el[0].mVec128.m128_f32[1]);
  v28 = this->m_basis.m_el[1].mVec128.m128_f32[1] * v26;
  v29 = this->m_basis.m_el[1].mVec128.m128_f32[0] * v22;
  v30 = this->m_basis.m_el[0].mVec128.m128_f32[2];
  v31 = (float)(v28 + (float)(v27 * t->m_basis.m_el[2].mVec128.m128_f32[0])) + v29;
  v32 = this->m_basis.m_el[0].mVec128.m128_f32[0];
  v33 = this->m_basis.m_el[0].mVec128.m128_f32[0];
  v44 = v31;
  v34 = (float)((float)(v33 * v11) + (float)(this->m_basis.m_el[0].mVec128.m128_f32[1] * v10)) + (float)(v30 * v9);
  v35 = (float)((float)(v32 * t->m_basis.m_el[0].mVec128.m128_f32[1])
              + (float)(this->m_basis.m_el[0].mVec128.m128_f32[1] * t->m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v30 * v12);
  v36 = (float)((float)(v32 * t->m_basis.m_el[0].mVec128.m128_f32[0])
              + (float)(this->m_basis.m_el[0].mVec128.m128_f32[1] * t->m_basis.m_el[1].mVec128.m128_f32[0]))
      + (float)(v30 * t->m_basis.m_el[2].mVec128.m128_f32[0]);
  v45 = v34;
  v46 = v35;
  v47 = v36;
  btMatrix3x3::setValue((btMatrix3x3 *)&v47, (int)this, &v46, &v45, &v44, &v43, &v42, &v41, &v40, &v39, v38);
  return this;
}
