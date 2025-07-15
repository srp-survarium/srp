void __userpurge btVoronoiSimplexSolver::addVertex(
        btVoronoiSimplexSolver *this@<ecx>,
        btVector3 *a2@<eax>,
        const btVector3 *w,
        const btVector3 *p,
        const btVector3 *q)
{
  btVector3 *v5; // edi
  btVector3 *v6; // edi
  btVector3 *v7; // edi

  a2[19] = (btVector3)w->mVec128;
  v5 = &a2[a2->mVec128.m128_i32[0] + 1];
  a2[24].mVec128.m128_i8[0] = 1;
  v5->mVec128.m128_i32[0] = w->mVec128.m128_i32[0];
  v5 = (btVector3 *)((char *)v5 + 4);
  v5->mVec128.m128_i32[0] = w->mVec128.m128_i32[1];
  *(unsigned __int64 *)((char *)v5->mVec128.m128_u64 + 4) = w->mVec128.m128_u64[1];
  v6 = &a2[a2->mVec128.m128_i32[0] + 6];
  v6->mVec128.m128_i32[0] = p->mVec128.m128_i32[0];
  v6 = (btVector3 *)((char *)v6 + 4);
  v6->mVec128.m128_i32[0] = p->mVec128.m128_i32[1];
  *(unsigned __int64 *)((char *)v6->mVec128.m128_u64 + 4) = p->mVec128.m128_u64[1];
  v7 = &a2[a2->mVec128.m128_i32[0] + 11];
  v7->mVec128.m128_i32[0] = q->mVec128.m128_i32[0];
  v7 = (btVector3 *)((char *)v7 + 4);
  v7->mVec128.m128_i32[0] = q->mVec128.m128_i32[1];
  *(unsigned __int64 *)((char *)v7->mVec128.m128_u64 + 4) = q->mVec128.m128_u64[1];
  ++a2->mVec128.m128_i32[0];
}
