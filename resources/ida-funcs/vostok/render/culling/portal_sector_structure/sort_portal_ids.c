void __userpurge vostok::render::culling::portal_sector_structure::sort_portal_ids(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<eax>,
        float *distances)
{
  int v4; // ecx
  int v5; // eax
  unsigned int *v6; // edi
  int v7; // eax
  unsigned int *v8; // ebx
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  unsigned int *j; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // edi
  unsigned int *k; // edx
  int v16; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 296);
  v5 = *(_DWORD *)(a2 + 292);
  v16 = v4;
  for ( i = v5; v5 != v16; i = v5 )
  {
    v6 = *(unsigned int **)(v5 + 24);
    v7 = *(_DWORD *)(v5 + 28);
    v8 = &v6[v7];
    if ( v6 != v8 )
    {
      v9 = (4 * v7) >> 2;
      v10 = v9;
      v11 = 0;
      while ( v10 != 1 )
      {
        ++v11;
        v10 >>= 1;
      }
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        (vostok::render::culling::portal_id_closer_to_point)v6,
        v6,
        v8,
        0,
        2 * v11,
        (vostok::render::culling::portal_id_closer_to_point)distances);
      if ( v9 <= 16 )
      {
        stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          v6,
          v8,
          (unsigned int *)distances);
      }
      else
      {
        stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          v6,
          v6 + 16,
          (unsigned int *)distances);
        for ( j = v6 + 16; j != v8; *v14 = v13 )
        {
          v13 = *j;
          v14 = j;
          for ( k = j - 1; distances[*k] > distances[v13]; --k )
          {
            *v14 = *k;
            v14 = k;
          }
          ++j;
        }
      }
    }
    v5 = i + 32;
  }
}
