void __userpurge vostok::render::culling::portal_sector_structure::sort_portal_ids(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<eax>,
        const float *distances)
{
  int v3; // ebx
  int i; // esi

  v3 = *(_DWORD *)(a2 + 292);
  for ( i = *(_DWORD *)(a2 + 288); i != v3; i += 32 )
    stlp_std::sort<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
      *(unsigned int **)(i + 24),
      (vostok::render::culling::portal_id_closer_to_point)distances,
      (unsigned int *)(*(_DWORD *)(i + 24) + 4 * *(_DWORD *)(i + 28)),
      (vostok::render::culling::portal_id_closer_to_point)distances);
}
