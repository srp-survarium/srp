void __userpurge gjkepa2_impl::GJK::appendvertice(
        gjkepa2_impl::GJK *this@<edx>,
        gjkepa2_impl::GJK::sSimplex *simplex@<eax>,
        const btVector3 *v)
{
  unsigned int rank; // ecx
  gjkepa2_impl::GJK::sSV *v4; // esi

  simplex->p[simplex->rank] = 0.0;
  simplex->c[simplex->rank] = this->m_free[--this->m_nfree];
  rank = simplex->rank;
  v4 = simplex->c[rank];
  simplex->rank = rank + 1;
  gjkepa2_impl::GJK::getsupport(v, this, v4);
}
