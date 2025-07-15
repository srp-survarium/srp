void __userpurge btSimulationIslandManager::findUnions(
        btCollisionWorld *colWorld@<eax>,
        btSimulationIslandManager *this,
        btDispatcher *__formal)
{
  btOverlappingPairCache *v3; // esi
  int v4; // ebx
  int v5; // eax
  int **v6; // edi
  int v7; // eax
  int v8; // ecx

  v3 = colWorld->m_broadphasePairCache->getOverlappingPairCache(colWorld->m_broadphasePairCache);
  v4 = v3->getNumOverlappingPairs(v3);
  if ( v4 )
  {
    v5 = (int)v3->getOverlappingPairArrayPtr(v3);
    if ( v4 > 0 )
    {
      v6 = (int **)v5;
      do
      {
        v7 = **v6;
        v8 = *v6[1];
        if ( v7 && (*(_BYTE *)(v7 + 216) & 7) == 0 && v8 && (*(_BYTE *)(v8 + 216) & 7) == 0 )
          btUnionFind::unite(&this->m_unionFind, *(_DWORD *)(v7 + 220), *(_DWORD *)(v8 + 220));
        v6 += 4;
        --v4;
      }
      while ( v4 );
    }
  }
}
