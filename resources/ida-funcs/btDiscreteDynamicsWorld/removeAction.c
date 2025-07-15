void __thiscall btDiscreteDynamicsWorld::removeAction(btDiscreteDynamicsWorld *this, btActionInterface *action)
{
  int m_size; // edi
  int v3; // eax
  int v4; // esi
  btActionInterface **m_data; // edx
  btActionInterface **v6; // edx
  btActionInterface **v7; // esi
  btActionInterface *v8; // ebx
  int v9; // edi

  m_size = this->m_actions.m_size;
  v3 = 0;
  v4 = m_size;
  if ( m_size > 0 )
  {
    m_data = this->m_actions.m_data;
    while ( *m_data != action )
    {
      ++v3;
      ++m_data;
      if ( v3 >= m_size )
        goto LABEL_7;
    }
    v4 = v3;
  }
LABEL_7:
  if ( v4 < m_size )
  {
    v6 = this->m_actions.m_data;
    v7 = &v6[v4];
    v8 = *v7;
    v9 = 4 * m_size - 4;
    *v7 = *(btActionInterface **)((char *)v6 + v9);
    *(btActionInterface **)((char *)this->m_actions.m_data + v9) = v8;
    --this->m_actions.m_size;
  }
}
