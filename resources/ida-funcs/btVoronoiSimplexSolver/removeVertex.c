void __usercall btVoronoiSimplexSolver::removeVertex(btVoronoiSimplexSolver *this@<ecx>, _DWORD *a2@<eax>)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // edi

  v2 = &a2[4 * (*a2)--];
  v3 = &a2[4 * ((_DWORD)&this->m_numVertices + 1)];
  *v3 = *v2++;
  *++v3 = *v2++;
  *++v3 = *v2;
  v3[1] = v2[1];
  v4 = &a2[4 * *a2 + 24];
  v5 = &a2[4 * ((_DWORD)&this->m_numVertices + 6)];
  *v5 = *v4++;
  *++v5 = *v4++;
  *++v5 = *v4;
  v5[1] = v4[1];
  v6 = &a2[4 * *a2 + 44];
  v7 = &a2[4 * ((_DWORD)&this->m_numVertices + 11)];
  *v7 = *v6++;
  *++v7 = *v6++;
  *++v7 = *v6;
  v7[1] = v6[1];
}
