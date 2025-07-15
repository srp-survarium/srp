void __thiscall btDiscreteDynamicsWorld::addAction(btDiscreteDynamicsWorld *this, btActionInterface *action)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v5; // edi
  btActionInterface **v6; // ebx
  int v7; // edx
  int v8; // eax
  btActionInterface **v9; // ecx
  btActionInterface **v10; // eax

  m_capacity = this->m_actions.m_capacity;
  m_size = this->m_actions.m_size;
  if ( m_size == m_capacity )
  {
    v5 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v5 )
    {
      if ( v5 )
        v6 = (btActionInterface **)btAlignedAllocInternal(4 * v5);
      else
        v6 = 0;
      v7 = this->m_actions.m_size;
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = v6;
        do
        {
          if ( v9 )
            *v9 = this->m_actions.m_data[v8];
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      if ( this->m_actions.m_data )
      {
        if ( this->m_actions.m_ownsMemory )
          btAlignedFreeInternal(this->m_actions.m_data);
        this->m_actions.m_data = 0;
      }
      this->m_actions.m_data = v6;
      this->m_actions.m_ownsMemory = 1;
      this->m_actions.m_capacity = v5;
    }
  }
  v10 = &this->m_actions.m_data[this->m_actions.m_size];
  if ( v10 )
    *v10 = action;
  ++this->m_actions.m_size;
}
