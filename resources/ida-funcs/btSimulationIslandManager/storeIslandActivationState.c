void __thiscall btSimulationIslandManager::storeIslandActivationState(
        btSimulationIslandManager *this,
        btCollisionWorld *colWorld)
{
  btCollisionWorld *v2; // eax
  int v3; // edi
  btCollisionObject *v5; // esi
  int i; // [esp+8h] [ebp-4h]

  v2 = colWorld;
  v3 = 0;
  for ( i = 0; v3 < v2->m_collisionObjects.m_size; ++v3 )
  {
    v5 = v2->m_collisionObjects.m_data[v3];
    if ( (v5->m_collisionFlags & 3) != 0 )
    {
      v5->m_islandTag1 = -1;
      v5->m_companionId = -2;
    }
    else
    {
      v5->m_islandTag1 = btUnionFind::find(&this->m_unionFind, i);
      this->m_unionFind.m_elements.m_data[i].m_sz = v3;
      v5->m_companionId = -1;
      ++i;
      v2 = colWorld;
    }
  }
}
