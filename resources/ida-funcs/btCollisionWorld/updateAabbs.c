void __thiscall btCollisionWorld::updateAabbs(btCollisionWorld *this)
{
  int i; // ebx
  btCollisionObject *v3; // edi
  int m_activationState1; // eax

  for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
  {
    v3 = this->m_collisionObjects.m_data[i];
    if ( !this->m_forceUpdateAllAabbs )
    {
      m_activationState1 = v3->m_activationState1;
      if ( m_activationState1 == 2 || m_activationState1 == 5 )
        continue;
    }
    btCollisionWorld::updateSingleAabb(this, v3);
  }
}
