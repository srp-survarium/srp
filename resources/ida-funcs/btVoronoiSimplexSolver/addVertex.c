void __usercall btVoronoiSimplexSolver::addVertex(
        btVoronoiSimplexSolver *this@<eax>,
        const btVector3 *w@<edx>,
        const btVector3 *p@<edi>,
        const btVector3 *q@<esi>)
{
  int m_numVertices; // ecx

  m_numVertices = this->m_numVertices;
  this->m_lastW = (btVector3)w->mVec128;
  this->m_needsUpdate = 1;
  this->m_simplexVectorW[m_numVertices] = (btVector3)w->mVec128;
  this->m_simplexPointsP[this->m_numVertices] = (btVector3)p->mVec128;
  this->m_simplexPointsQ[this->m_numVertices++] = (btVector3)q->mVec128;
}
