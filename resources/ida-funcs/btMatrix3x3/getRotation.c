void __thiscall btMatrix3x3::getRotation(btMatrix3x3 *this, btQuaternion *q)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  btQuaternion *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // esi
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // edi
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  _DWORD v21[3]; // [esp+0h] [ebp-18h]
  float v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]

  v2 = this->m_el[0].mVec128.m128_f32[0];
  v3 = this->m_el[1].mVec128.m128_f32[1];
  v4 = this->m_el[2].mVec128.m128_f32[2];
  v5 = q;
  v6 = (float)(this->m_el[0].mVec128.m128_f32[0] + v3) + v4;
  if ( v6 <= 0.0 )
  {
    if ( v3 <= v2 )
    {
      if ( v4 <= v2 )
      {
        v13 = 0;
        goto LABEL_9;
      }
    }
    else if ( v4 <= v3 )
    {
      v13 = 1;
LABEL_9:
      v14 = this->m_el[0].mVec128.m128_f32[5 * v13] - this->m_el[0].mVec128.m128_f32[5 * ((v13 + 1) % 3)];
      v23 = (v13 + 1) % 3;
      v15 = (float)(v14 - this->m_el[0].mVec128.m128_f32[5 * ((v13 + 2) % 3)]) + s_bm_current_air_resistance;
      v24 = (v13 + 2) % 3;
      v16 = fsqrt(v15);
      v17 = v23;
      v18 = v16 * 0.5;
      v19 = 0.5 / v16;
      v20 = (float)(this->m_el[v24].mVec128.m128_f32[v23] - this->m_el[v23].mVec128.m128_f32[v24]) * (float)(0.5 / v16);
      *(float *)&v21[v13] = v18;
      v22 = v20;
      *(float *)&v21[v17] = (float)(this->m_el[v17].mVec128.m128_f32[v13]
                                  + this->m_el[v13].mVec128.m128_f32[(v13 + 1) % 3])
                          * v19;
      v5 = q;
      *(float *)&v21[v24] = (float)(this->m_el[v24].mVec128.m128_f32[v13] + this->m_el[v13].mVec128.m128_f32[v24]) * v19;
      v8 = v22;
      v12 = *(float *)&v21[2];
      v11 = *(float *)&v21[1];
      v10 = *(float *)v21;
      goto LABEL_10;
    }
    v13 = 2;
    goto LABEL_9;
  }
  v7 = fsqrt(v6 + s_bm_current_air_resistance);
  v8 = v7 * 0.5;
  v9 = 0.5 / v7;
  v10 = (float)(this->m_el[2].mVec128.m128_f32[1] - this->m_el[1].mVec128.m128_f32[2]) * (float)(0.5 / v7);
  v11 = (float)(this->m_el[0].mVec128.m128_f32[2] - this->m_el[2].mVec128.m128_f32[0]) * (float)(0.5 / v7);
  v12 = (float)(this->m_el[1].mVec128.m128_f32[0] - this->m_el[0].mVec128.m128_f32[1]) * v9;
LABEL_10:
  v5->m_floats[0] = v10;
  v5->m_floats[1] = v11;
  v5->m_floats[2] = v12;
  v5->m_floats[3] = v8;
}
