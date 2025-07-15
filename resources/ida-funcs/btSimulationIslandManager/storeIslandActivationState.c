void __thiscall btSimulationIslandManager::storeIslandActivationState(
        btSimulationIslandManager *this,
        btCollisionWorld *colWorld)
{
  btCollisionWorld *v2; // eax
  int v3; // edx
  int v4; // esi
  btCollisionObject *v5; // edi
  int v6; // ebp
  int v7; // eax
  int v8; // edx
  btElement *m_data; // eax
  int m_id; // esi
  int index; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = colWorld;
  v3 = 0;
  v4 = 0;
  index = 0;
  for ( i = 0; v4 < v2->m_collisionObjects.m_size; i = v4 )
  {
    v5 = v2->m_collisionObjects.m_data[v4];
    if ( (v5->m_collisionFlags & 3) != 0 )
    {
      v5->m_islandTag1 = -1;
      v5->m_companionId = -2;
    }
    else
    {
      v6 = v3;
      v7 = v3;
      if ( v3 != this->m_unionFind.m_elements.m_data[v3].m_id )
      {
        v8 = v3;
        do
        {
          m_data = this->m_unionFind.m_elements.m_data;
          m_id = m_data[v8].m_id;
          m_data[v8].m_id = m_data[m_id].m_id;
          v7 = m_data[m_id].m_id;
          v8 = v7;
        }
        while ( v7 != this->m_unionFind.m_elements.m_data[v7].m_id );
        v3 = index;
        v4 = i;
      }
      v5->m_islandTag1 = v7;
      this->m_unionFind.m_elements.m_data[v6].m_sz = v4;
      v2 = colWorld;
      ++v3;
      v5->m_companionId = -1;
      index = v3;
    }
    ++v4;
  }
}
