void __cdecl ApplyScaleToIndexedTriangles(struct SpeedTree::SIndexedTriangles *a1, float a2)
{
  float *m_pLodCoords; // [esp+0h] [ebp-Ch]
  float *m_pCoords; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  if ( a1->m_pCoords )
  {
    m_pCoords = (float *)a1->m_pCoords;
    for ( i = 0; i < 3 * a1->m_nNumVertices; ++i )
    {
      *m_pCoords = *m_pCoords * a2;
      ++m_pCoords;
    }
    if ( a1->m_pLodCoords )
    {
      m_pLodCoords = (float *)a1->m_pLodCoords;
      for ( j = 0; j < 3 * a1->m_nNumVertices; ++j )
      {
        *m_pLodCoords = *m_pLodCoords * a2;
        ++m_pLodCoords;
      }
    }
  }
}
