void __thiscall btSimulationIslandManager::updateActivationState(
        btSimulationIslandManager *this,
        btCollisionWorld *colWorld,
        btDispatcher *dispatcher)
{
  int v4; // ecx
  int v5; // edi
  const vostok::math::float4x4 *v6; // xmm0_4
  btCollisionObject *v7; // eax
  btUnionFind *p_m_unionFind; // esi
  int i; // eax
  btDispatcher *v10; // [esp+0h] [ebp-10h]
  btSimulationIslandManager *v11; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  v11 = this;
  if ( colWorld->m_collisionObjects.m_size > 0 )
  {
    v6 = clear_value;
    do
    {
      v7 = colWorld->m_collisionObjects.m_data[v4];
      if ( (v7->m_collisionFlags & 3) == 0 )
        v7->m_islandTag1 = v5++;
      ++v4;
      v7->m_companionId = -1;
      LODWORD(v7->m_hitFraction) = v6;
    }
    while ( v4 < colWorld->m_collisionObjects.m_size );
  }
  p_m_unionFind = &this->m_unionFind;
  btUnionFind::allocate((btUnionFind *)v4, (int)&this->m_unionFind, v5);
  for ( i = 0; i < v5; ++i )
  {
    p_m_unionFind->m_elements.m_data[i].m_id = i;
    p_m_unionFind->m_elements.m_data[i].m_sz = 1;
  }
  btSimulationIslandManager::findUnions(colWorld, v11, v10);
}
