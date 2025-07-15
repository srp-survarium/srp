void __userpurge vostok::render::stage_visibility::get_results_and_prepare_bounds_portals(
        vostok::render::stage_visibility *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  _BYTE *v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-4h]

  v5 = *(_DWORD *)(a2[1] + 16264);
  v6 = *(int *)((char *)&dword_8B9670 + v5);
  v12 = v5;
  if ( v6 )
    v7 = (*(_DWORD *)(*(_DWORD *)(v6 + 264) + 276) - *(_DWORD *)(*(_DWORD *)(v6 + 264) + 272)) / 76;
  else
    v7 = 0;
  if ( v7 )
  {
    v8 = a2[9];
    if ( v8 )
    {
      if ( v6 )
        vostok::render::culling::portal_sector_system::update_portals_occlusion_culling(
          (vostok::render::culling::portal_sector_system *)(v8 + a2[7]),
          v6,
          (unsigned __int8 *)(v8 + a2[7]));
      v9 = (_BYTE *)(a2[7] + a2[9]);
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
    v11 = *(int *)((char *)&dword_8B9670 + v12);
    if ( v11 )
      stlp_std::priv::__copy_trivial(
        *(unsigned __int8 **)(v11 + 49444),
        *(unsigned __int8 **)(v11 + 49448),
        (unsigned __int8 *)*out_bounds);
    *out_bounds += v7;
    *out_counter += v7;
  }
}
