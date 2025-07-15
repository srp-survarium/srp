void __usercall btVoronoiSimplexSolver::reduceVertices(
        btVoronoiSimplexSolver *this@<eax>,
        const btUsageBitfield *usedVerts@<edi>)
{
  if ( this->m_numVertices >= 4 && (*(_BYTE *)usedVerts & 8) == 0 )
    btVoronoiSimplexSolver::removeVertex(this, 3);
  if ( this->m_numVertices >= 3 && (*(_BYTE *)usedVerts & 4) == 0 )
    btVoronoiSimplexSolver::removeVertex(this, 2);
  if ( this->m_numVertices >= 2 && (*(_BYTE *)usedVerts & 2) == 0 )
    btVoronoiSimplexSolver::removeVertex(this, 1);
  if ( this->m_numVertices >= 1 && (*(_BYTE *)usedVerts & 1) == 0 )
    btVoronoiSimplexSolver::removeVertex(this, 0);
}
