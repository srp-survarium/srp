btVector3 *__userpurge gjkepa2_impl::MinkowskiDiff::Support@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<ecx>,
        const btVector3 *d@<eax>,
        int a3)
{
  const btConvexShape *v4; // ecx
  btVector3 *(__thiscall *Ls)(btConvexShape *, btVector3 *, const btVector3 *); // edx
  __int64 *v6; // eax
  btVector3 *v7; // eax
  btVector3 v9; // [esp+8h] [ebp-40h] BYREF
  __int64 v10; // [esp+18h] [ebp-30h]
  __int64 v11; // [esp+20h] [ebp-28h]
  btVector3 v12; // [esp+28h] [ebp-20h] BYREF
  _BYTE v13[16]; // [esp+38h] [ebp-10h] BYREF

  v9.mVec128.m128_f32[0] = -d->mVec128.m128_f32[0];
  v9.mVec128.m128_f32[1] = -d->mVec128.m128_f32[1];
  v4 = this->m_shapes[0];
  Ls = this->Ls;
  v9.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-d->mVec128.m128_f32[2]);
  v6 = (__int64 *)Ls((btConvexShape *)v4, &v12, d);
  v10 = *v6;
  v11 = v6[1];
  v7 = gjkepa2_impl::MinkowskiDiff::Support1(this, &v9, (int)v13);
  *(float *)a3 = *(float *)&v10 - v7->mVec128.m128_f32[0];
  *(float *)(a3 + 4) = *((float *)&v10 + 1) - v7->mVec128.m128_f32[1];
  *(float *)(a3 + 8) = *(float *)&v11 - v7->mVec128.m128_f32[2];
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
