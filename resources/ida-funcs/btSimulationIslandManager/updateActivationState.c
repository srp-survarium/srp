void __thiscall btSimulationIslandManager::updateActivationState(
        btSimulationIslandManager *this,
        btCollisionWorld *colWorld,
        btDispatcher *dispatcher)
{
  int v4; // ecx
  int v5; // ebx
  btCollisionObject *v6; // eax
  btUnionFind *p_m_unionFind; // esi
  int j; // eax
  btDispatcher *v9; // [esp+0h] [ebp-10h]
  btSimulationIslandManager *i; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  for ( i = this; v4 < colWorld->m_collisionObjects.m_size; v6->m_hitFraction = s_bm_current_air_resistance )
  {
    v6 = colWorld->m_collisionObjects.m_data[v4];
    if ( (v6->m_collisionFlags & 3) == 0 )
      v6->m_islandTag1 = v5++;
    v6->m_companionId = -1;
    ++v4;
  }
  p_m_unionFind = &this->m_unionFind;
  btUnionFind::allocate((btUnionFind *)v4, (int)p_m_unionFind, v5);
  for ( j = 0; j < v5; ++j )
  {
    p_m_unionFind->m_elements.m_data[j].m_id = j;
    p_m_unionFind->m_elements.m_data[j].m_sz = 1;
  }
  btSimulationIslandManager::findUnions(colWorld, i, v9);
}
