int __thiscall btBU_Simplex1to4::getNumPlanes(btBU_Simplex1to4 *this)
{
  int m_numVertices; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax

  m_numVertices = this->m_numVertices;
  if ( m_numVertices )
  {
    v2 = m_numVertices - 1;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( !v4 )
          return 2;
        if ( v4 == 1 )
          return 4;
      }
    }
  }
  return 0;
}
