void __usercall gjkepa2_impl::GJK::removevertice(
        gjkepa2_impl::GJK *this@<ecx>,
        gjkepa2_impl::GJK::sSimplex *simplex@<eax>)
{
  this->m_free[this->m_nfree++] = simplex->c[--simplex->rank];
}
