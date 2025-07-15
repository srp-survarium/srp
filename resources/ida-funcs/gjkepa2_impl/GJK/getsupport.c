void __userpurge gjkepa2_impl::GJK::getsupport(
        const btVector3 *d@<eax>,
        gjkepa2_impl::GJK *this,
        gjkepa2_impl::GJK::sSV *sv)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  btVector3 *v5; // esi
  gjkepa2_impl::MinkowskiDiff *v6; // ecx
  btVector3 *v7; // eax
  btVector3 v8; // [esp+4h] [ebp-30h] BYREF
  _BYTE v9[16]; // [esp+14h] [ebp-20h] BYREF
  btVector3 v10; // [esp+24h] [ebp-10h] BYREF

  v3 = fsqrt(
         (float)((float)(d->mVec128.m128_f32[0] * d->mVec128.m128_f32[0])
               + (float)(d->mVec128.m128_f32[1] * d->mVec128.m128_f32[1]))
       + (float)(d->mVec128.m128_f32[2] * d->mVec128.m128_f32[2]));
  v8.mVec128.m128_f32[0] = d->mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance / v3);
  v4 = (float)(s_bm_current_air_resistance / v3) * d->mVec128.m128_f32[1];
  v8.mVec128.m128_f32[2] = (float)(s_bm_current_air_resistance / v3) * d->mVec128.m128_f32[2];
  v8.mVec128.m128_f32[1] = v4;
  v8.mVec128.m128_i32[3] = 0;
  sv->d = (btVector3)v8.mVec128;
  v8.mVec128.m128_i32[0] = sv->d.mVec128.m128_i32[0] ^ _mask__NegFloat_;
  v8.mVec128.m128_i32[1] = sv->d.mVec128.m128_i32[1] ^ _mask__NegFloat_;
  v8.mVec128.m128_u64[1] = sv->d.mVec128.m128_u32[2] ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  v5 = gjkepa2_impl::MinkowskiDiff::Support1(&this->m_shape, &v8, (int)v9);
  v7 = gjkepa2_impl::MinkowskiDiff::Support0(v6, (int)this, &v10, &sv->d);
  v8.mVec128.m128_f32[0] = v7->mVec128.m128_f32[0] - v5->mVec128.m128_f32[0];
  v8.mVec128.m128_f32[1] = v7->mVec128.m128_f32[1] - v5->mVec128.m128_f32[1];
  v8.mVec128.m128_f32[2] = v7->mVec128.m128_f32[2] - v5->mVec128.m128_f32[2];
  v8.mVec128.m128_i32[3] = 0;
  sv->w = (btVector3)v8.mVec128;
}
