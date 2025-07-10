void __userpurge gjkepa2_impl::GJK::getsupport(
        const btVector3 *d@<edi>,
        gjkepa2_impl::GJK::sSV *sv@<esi>,
        gjkepa2_impl::GJK *this)
{
  long double v3; // st7
  long double v4; // st6
  long double v5; // st7
  float v6; // [esp+Ch] [ebp-18h]
  float v7; // [esp+10h] [ebp-14h]
  unsigned __int64 v8; // [esp+14h] [ebp-10h] BYREF
  unsigned __int64 v9; // [esp+1Ch] [ebp-8h]

  v6 = d->mVec128.m128_f32[0];
  v3 = 1.0
     / sqrtf(
         (float)((float)(v6 * v6) + (float)(d->mVec128.m128_f32[1] * d->mVec128.m128_f32[1]))
       + (float)(d->mVec128.m128_f32[2] * d->mVec128.m128_f32[2]));
  v7 = v3;
  v4 = v3 * d->mVec128.m128_f32[1];
  *(float *)&v8 = v6 * v7;
  HIDWORD(v9) = 0;
  *((float *)&v8 + 1) = v4;
  v5 = v3 * d->mVec128.m128_f32[2];
  sv->d.mVec128.m128_u64[0] = v8;
  *(float *)&v9 = v5;
  sv->d.mVec128.m128_u64[1] = v9;
  sv->w = (btVector3)gjkepa2_impl::MinkowskiDiff::Support(&this->m_shape, &sv->d, (int)&v8)->mVec128;
}
