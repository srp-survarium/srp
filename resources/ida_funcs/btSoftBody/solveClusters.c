void __usercall btSoftBody::solveClusters(btSoftBody *this@<ecx>, int a2@<edi>)
{
  int v2; // ebx
  int i; // esi
  int v4; // ecx

  v2 = *(_DWORD *)(a2 + 860);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 868) + 4 * i);
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 8))(v4, *(float *)(a2 + 460), 1.0);
  }
}


void __cdecl btSoftBody::solveClusters(const btAlignedObjectArray<btSoftBody *> *bodies)
{
  const btAlignedObjectArray<btSoftBody *> *v1; // ecx
  int m_size; // edx
  int v3; // ebx
  btSoftBody **m_data; // esi
  int v5; // edi
  int *p_citerations; // eax
  int i; // ebp
  btSoftBody *v8; // esi
  int v9; // edi
  int j; // ebp
  btSoftBody *v11; // edi
  int v12; // ebx
  int v13; // esi
  btSoftBody::Joint *v14; // ecx
  int v15; // edi
  int nb; // [esp+20h] [ebp-8h]
  int iterations; // [esp+24h] [ebp-4h] BYREF

  v1 = bodies;
  m_size = bodies->m_size;
  v3 = 0;
  nb = m_size;
  iterations = 0;
  if ( m_size > 0 )
  {
    m_data = bodies->m_data;
    v5 = m_size;
    do
    {
      p_citerations = &(*m_data)->m_cfg.citerations;
      if ( v3 > *p_citerations )
        p_citerations = &iterations;
      v3 = *p_citerations;
      ++m_data;
      --v5;
      iterations = *p_citerations;
    }
    while ( v5 );
  }
  for ( i = 0; i < m_size; ++i )
  {
    v8 = v1->m_data[i];
    v9 = 0;
    if ( v8->m_joints.m_size > 0 )
    {
      do
        ((void (__stdcall *)(_DWORD, int))v8->m_joints.m_data[v9++]->Prepare)(v8->m_sst.sdt, v3);
      while ( v9 < v8->m_joints.m_size );
      v1 = bodies;
      m_size = nb;
    }
  }
  if ( v3 > 0 )
  {
    iterations = v3;
    do
    {
      for ( j = 0; j < m_size; ++j )
      {
        v11 = v1->m_data[j];
        v12 = v11->m_joints.m_size;
        v13 = 0;
        if ( v12 > 0 )
        {
          do
          {
            v14 = v11->m_joints.m_data[v13];
            ((void (__thiscall *)(btSoftBody::Joint *, float, _DWORD))v14->Solve)(v14, v11->m_sst.sdt, 1.0);
            ++v13;
          }
          while ( v13 < v12 );
          v1 = bodies;
          m_size = nb;
        }
      }
      --iterations;
    }
    while ( iterations );
  }
  v15 = 0;
  if ( m_size > 0 )
  {
    while ( 1 )
    {
      btSoftBody::cleanupClusters((btSoftBody *)v1->m_data, (int)v1->m_data[v15++]);
      if ( v15 >= nb )
        break;
      v1 = bodies;
    }
  }
}
