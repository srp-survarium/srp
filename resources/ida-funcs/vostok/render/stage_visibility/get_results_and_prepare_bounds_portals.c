void __userpurge vostok::render::stage_visibility::get_results_and_prepare_bounds_portals(
        vostok::render::stage_visibility *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter)
{
  int v5; // ebp
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  _BYTE *v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // ecx
  unsigned int v13; // eax

  v5 = *(_DWORD *)(a2[1] + 12388);
  v6 = *(_DWORD *)(v5 + 972);
  if ( v6 )
  {
    v7 = (*(_DWORD *)(*(_DWORD *)(v6 + 264) + 276) - *(_DWORD *)(*(_DWORD *)(v6 + 264) + 272)) / 76;
    if ( v7 )
    {
      v8 = a2[9];
      if ( v8 )
      {
        vostok::render::culling::portal_sector_system::update_portals_occlusion_culling(
          (vostok::render::culling::portal_sector_system *)(v8 + a2[7]),
          v6,
          (unsigned __int8 *)(v8 + a2[7]));
        v9 = (_BYTE *)(a2[9] + a2[7]);
        v10 = 0;
        if ( v9 != &v9[v7] )
        {
          do
          {
            if ( !*v9 )
              ++v10;
            ++v9;
          }
          while ( v9 != (_BYTE *)(v7 + a2[7] + a2[9]) );
        }
        vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_occlusion_culled_portals.value = v10;
      }
      a2[9] = *out_counter;
      v11 = *(_DWORD *)(v5 + 972);
      if ( v11 && (v12 = *(unsigned __int8 **)(v11 + 292), (v13 = *(_DWORD *)(v11 + 296) - (_DWORD)v12) != 0) )
      {
        memmove((unsigned __int8 *)*out_bounds, v12, v13);
        *out_bounds += v7;
        *out_counter += v7;
      }
      else
      {
        *out_bounds += v7;
        *out_counter += v7;
      }
    }
  }
}
