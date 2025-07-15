void __cdecl btSoftBody::solveClusters(int bodies)
{
  btSoftBody *v1; // ecx
  int v2; // ebx
  int v3; // edx
  int v4; // esi
  int *p_bodies; // eax
  int v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // edi
  int v10; // edi
  int v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  int j; // [esp+24h] [ebp-4h]

  v2 = bodies;
  v3 = *(_DWORD *)(bodies + 4);
  bodies = 0;
  v12 = v3;
  if ( v3 > 0 )
  {
    v1 = *(btSoftBody **)(v2 + 12);
    v4 = v3;
    do
    {
      p_bodies = (int *)&v1->__vftable[14];
      if ( bodies > *p_bodies )
        p_bodies = &bodies;
      v1 = (btSoftBody *)((char *)v1 + 4);
      --v4;
      bodies = *p_bodies;
    }
    while ( v4 );
  }
  for ( i = 0; i < v3; ++i )
  {
    v1 = (btSoftBody *)i;
    v6 = *(_DWORD *)(*(_DWORD *)(v2 + 12) + 4 * i);
    v7 = 0;
    if ( *(int *)(v6 + 860) > 0 )
    {
      do
        (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)(v6 + 868) + 4 * v7++) + 4))(
          *(float *)(v6 + 460),
          bodies);
      while ( v7 < *(_DWORD *)(v6 + 860) );
      v3 = v12;
    }
  }
  if ( bodies > 0 )
  {
    v11 = bodies;
    do
    {
      for ( j = 0; j < v3; ++j )
      {
        v1 = (btSoftBody *)j;
        v8 = *(_DWORD *)(*(_DWORD *)(v2 + 12) + 4 * j);
        v9 = *(_DWORD *)(v8 + 860);
        bodies = 0;
        if ( v9 > 0 )
        {
          do
            (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(v8 + 868) + 4 * bodies++) + 8))(
              *(float *)(v8 + 460),
              1.0);
          while ( bodies < v9 );
          v3 = v12;
        }
      }
      --v11;
    }
    while ( v11 );
  }
  v10 = 0;
  if ( v3 > 0 )
  {
    do
      btSoftBody::cleanupClusters(v1, *(_DWORD *)(*(_DWORD *)(v2 + 12) + 4 * v10++));
    while ( v10 < v12 );
  }
}
