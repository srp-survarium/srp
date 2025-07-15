gjkepa2_impl::MinkowskiDiff *__userpurge gjkepa2_impl::MinkowskiDiff::operator=@<eax>(
        gjkepa2_impl::MinkowskiDiff *this@<ecx>,
        gjkepa2_impl::MinkowskiDiff *result@<eax>,
        const gjkepa2_impl::MinkowskiDiff *__that)
{
  gjkepa2_impl::MinkowskiDiff *v3; // ecx
  int v4; // esi

  v3 = result;
  v4 = 2;
  do
  {
    v3->m_shapes[0] = *(const btConvexShape **)((char *)v3->m_shapes + (char *)__that - (char *)result);
    v3 = (gjkepa2_impl::MinkowskiDiff *)((char *)v3 + 4);
    --v4;
  }
  while ( v4 );
  result->m_toshape1 = __that->m_toshape1;
  result->m_toshape0 = __that->m_toshape0;
  result->Ls = __that->Ls;
  return result;
}
