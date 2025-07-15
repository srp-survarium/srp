btVector3 *__usercall gjkepa2_impl::MinkowskiDiff::Support1@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<esi>,
        const btVector3 *d@<eax>,
        int a3@<edi>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  btConvexShape *v6; // ecx
  float v7; // xmm4_4
  btVector3 *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v17[4]; // [esp+0h] [ebp-20h] BYREF
  _BYTE v18[16]; // [esp+10h] [ebp-10h] BYREF

  v3 = d->mVec128.m128_f32[2];
  v4 = d->mVec128.m128_f32[1];
  v5 = d->mVec128.m128_f32[0];
  v6 = (btConvexShape *)this->m_shapes[1];
  v7 = this->m_toshape1.m_el[1].mVec128.m128_f32[2];
  v17[0] = (float)((float)(this->m_toshape1.m_el[0].mVec128.m128_f32[1] * v4)
                 + (float)(this->m_toshape1.m_el[0].mVec128.m128_f32[2] * v3))
         + (float)(this->m_toshape1.m_el[0].mVec128.m128_f32[0] * d->mVec128.m128_f32[0]);
  v17[1] = (float)((float)(this->m_toshape1.m_el[1].mVec128.m128_f32[1] * v4) + (float)(v7 * v3))
         + (float)(this->m_toshape1.m_el[1].mVec128.m128_f32[0] * v5);
  v17[2] = (float)((float)(this->m_toshape1.m_el[2].mVec128.m128_f32[1] * v4)
                 + (float)(this->m_toshape1.m_el[2].mVec128.m128_f32[2] * v3))
         + (float)(this->m_toshape1.m_el[2].mVec128.m128_f32[0] * v5);
  v17[3] = 0.0;
  v8 = this->Ls(v6, v18, v17);
  v9 = v8->mVec128.m128_f32[1];
  v10 = v8->mVec128.m128_f32[2];
  v11 = v8->mVec128.m128_f32[0];
  v12 = this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[2];
  *(float *)a3 = (float)((float)((float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[1] * v9)
                               + (float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[2] * v10))
                       + (float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[0] * v8->mVec128.m128_f32[0]))
               + this->m_toshape0.m_origin.mVec128.m128_f32[0];
  v13 = (float)(this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[1] * v9) + (float)(v12 * v10);
  v14 = v11 * this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[0];
  v15 = v11 * this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[0];
  *(float *)(a3 + 4) = (float)(v13 + v14) + this->m_toshape0.m_origin.mVec128.m128_f32[1];
  *(float *)(a3 + 8) = (float)((float)((float)(this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[1] * v9)
                                     + (float)(this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[2] * v10))
                             + v15)
                     + this->m_toshape0.m_origin.mVec128.m128_f32[2];
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
