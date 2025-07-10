void __usercall btVoronoiSimplexSolver::removeVertex(btVoronoiSimplexSolver *this@<eax>, int index@<esi>)
{
  int *v2; // ecx
  int v3; // edx
  btVector3 *v4; // ecx
  int v5; // edx
  btVector3 *v6; // ecx
  btVector3 *v7; // edx

  v2 = &this->m_numVertices + 4 * this->m_numVertices--;
  v3 = 16 * (index + 1);
  *(_QWORD *)((char *)&this->m_numVertices + v3) = *(_QWORD *)v2;
  *(_QWORD *)((char *)&this->m_numVertices + v3 + 8) = *((_QWORD *)v2 + 1);
  v4 = &this->m_simplexPointsP[this->m_numVertices];
  v5 = 16 * (index + 6);
  *(_QWORD *)((char *)&this->m_numVertices + v5) = v4->mVec128.m128_u64[0];
  *(_QWORD *)((char *)&this->m_numVertices + v5 + 8) = v4->mVec128.m128_u64[1];
  v6 = &this->m_simplexPointsQ[this->m_numVertices];
  v7 = &this->m_simplexPointsQ[index];
  v7->mVec128.m128_u64[0] = v6->mVec128.m128_u64[0];
  v7->mVec128.m128_u64[1] = v6->mVec128.m128_u64[1];
}
