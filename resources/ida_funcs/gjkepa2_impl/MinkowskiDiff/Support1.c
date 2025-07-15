btVector3 *__usercall gjkepa2_impl::MinkowskiDiff::Support1@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<esi>,
        const btVector3 *d@<eax>,
        int a3@<edi>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  btVector3 *(__thiscall *Ls)(btConvexShape *, btVector3 *, const btVector3 *); // edx
  float v7; // xmm4_4
  const btConvexShape *v8; // ecx
  float *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v18[4]; // [esp+0h] [ebp-20h] BYREF
  btVector3 v19; // [esp+10h] [ebp-10h] BYREF

  v3 = d->mVec128.m128_f32[2];
  v4 = d->mVec128.m128_f32[1];
  v5 = d->mVec128.m128_f32[0];
  Ls = this->Ls;
  v7 = this->m_toshape1.m_el[1].mVec128.m128_f32[2];
  v18[0] = (float)((float)(this->m_toshape1.m_el[0].mVec128.m128_f32[1] * v4)
                 + (float)(this->m_toshape1.m_el[0].mVec128.m128_f32[2] * v3))
         + (float)(this->m_toshape1.m_el[0].mVec128.m128_f32[0] * d->mVec128.m128_f32[0]);
  v18[1] = (float)((float)(this->m_toshape1.m_el[1].mVec128.m128_f32[1] * v4) + (float)(v7 * v3))
         + (float)(this->m_toshape1.m_el[1].mVec128.m128_f32[0] * v5);
  v8 = this->m_shapes[1];
  v18[2] = (float)((float)(this->m_toshape1.m_el[2].mVec128.m128_f32[1] * v4)
                 + (float)(this->m_toshape1.m_el[2].mVec128.m128_f32[2] * v3))
         + (float)(this->m_toshape1.m_el[2].mVec128.m128_f32[0] * v5);
  v18[3] = 0.0;
  v9 = (float *)Ls((btConvexShape *)v8, &v19, (const btVector3 *)v18);
  v10 = v9[1];
  v11 = v9[2];
  v12 = *v9;
  v13 = this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[2];
  *(float *)a3 = (float)((float)((float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[1] * v10)
                               + (float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[2] * v11))
                       + (float)(this->m_toshape0.m_basis.m_el[0].mVec128.m128_f32[0] * *v9))
               + this->m_toshape0.m_origin.mVec128.m128_f32[0];
  v14 = (float)(this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[1] * v10) + (float)(v13 * v11);
  v15 = v12 * this->m_toshape0.m_basis.m_el[1].mVec128.m128_f32[0];
  v16 = v12 * this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[0];
  *(float *)(a3 + 4) = (float)(v14 + v15) + this->m_toshape0.m_origin.mVec128.m128_f32[1];
  *(float *)(a3 + 8) = (float)((float)((float)(this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[1] * v10)
                                     + (float)(this->m_toshape0.m_basis.m_el[2].mVec128.m128_f32[2] * v11))
                             + v16)
                     + this->m_toshape0.m_origin.mVec128.m128_f32[2];
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
