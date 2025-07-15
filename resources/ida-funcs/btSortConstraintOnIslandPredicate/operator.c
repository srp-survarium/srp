bool __fastcall btSortConstraintOnIslandPredicate::operator()(
        const btTypedConstraint *rhs,
        const btTypedConstraint *lhs,
        btSortConstraintOnIslandPredicate *this)
{
  int m_islandTag1; // ecx
  int v4; // eax

  if ( rhs->m_rbA->m_islandTag1 < 0 )
    m_islandTag1 = rhs->m_rbB->m_islandTag1;
  else
    m_islandTag1 = rhs->m_rbA->m_islandTag1;
  v4 = lhs->m_rbA->m_islandTag1;
  if ( v4 < 0 )
    v4 = lhs->m_rbB->m_islandTag1;
  return v4 < m_islandTag1;
}
