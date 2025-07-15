btVector3 *__userpurge gjkepa2_impl::MinkowskiDiff::Support0@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<ecx>,
        int a2@<eax>,
        btVector3 *result,
        const btVector3 *d)
{
  int v4; // esi
  btVector3 *v5; // eax
  _BYTE v6[16]; // [esp+10h] [ebp-10h] BYREF

  v4 = (*(int (__thiscall **)(_DWORD, _BYTE *, const btVector3 *))(a2 + 128))(*(_DWORD *)a2, v6, d);
  v5 = result;
  result->mVec128.m128_i32[0] = *(_DWORD *)v4;
  v4 += 4;
  result->mVec128.m128_i32[1] = *(_DWORD *)v4;
  result->mVec128.m128_u64[1] = *(_QWORD *)(v4 + 4);
  return v5;
}
