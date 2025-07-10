char __userpurge vostok::physics::bt_ghost_object::contact_test@<al>(
        vostok::physics::bt_ghost_object *this@<ecx>,
        int a2@<eax>,
        vostok::physics::world *world)
{
  int v3; // ebp
  int j; // edi
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int i; // [esp+10h] [ebp-1Ch]
  int pairs_count; // [esp+14h] [ebp-18h]
  btAlignedObjectArray<btPersistentManifold *> manifold_results; // [esp+18h] [ebp-14h] BYREF

  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 16) + 304) + 24))(*(_DWORD *)(*(_DWORD *)(a2 + 16)
                                                                                                  + 304));
  pairs_count = *(_DWORD *)(v3 + 4);
  i = 0;
  if ( pairs_count <= 0 )
    return 0;
  for ( j = 0; ; j += 16 )
  {
    v5 = (_DWORD *)(j + *(_DWORD *)(v3 + 12));
    v6 = (*(int (__thiscall **)(vostok::math::aabb *(__thiscall *)(vostok::physics::world *, vostok::math::aabb *)))(*(_DWORD *)world[13].get_world_aabb + 36))(world[13].get_world_aabb);
    v7 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v6 + 48))(v6, *v5, v5[1]);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 8) )
        break;
    }
LABEL_11:
    if ( ++i >= pairs_count )
      return 0;
  }
  v8 = *(_DWORD *)(v7 + 8);
  manifold_results.m_ownsMemory = 1;
  memset(&manifold_results.m_size, 0, 12);
  (*(void (__thiscall **)(int, btAlignedObjectArray<btPersistentManifold *> *))(*(_DWORD *)v8 + 12))(
    v8,
    &manifold_results);
  v9 = 0;
  if ( manifold_results.m_size <= 0 )
  {
LABEL_8:
    if ( manifold_results.m_data )
    {
      if ( manifold_results.m_ownsMemory )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(manifold_results.m_data);
      }
    }
    goto LABEL_11;
  }
  while ( !manifold_results.m_data[v9]->m_cachedPoints )
  {
    if ( ++v9 >= manifold_results.m_size )
      goto LABEL_8;
  }
  if ( manifold_results.m_data && manifold_results.m_ownsMemory )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(manifold_results.m_data);
  }
  return 1;
}
