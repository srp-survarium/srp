void __usercall vostok::render::stage_visibility::gather_statistics(
        vostok::render::stage_visibility *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v2; // esi
  int v3; // ecx
  int v4; // eax
  int i; // edi
  vostok::render::statistics *v6; // edx
  int v7; // ecx
  int v8; // eax
  int j; // edi
  _DWORD *v10; // ebx
  _DWORD *v11; // edi
  int v12; // ebp
  int v13; // ecx
  int v14; // eax
  int k; // edi
  int v16; // ecx
  int v17; // eax
  int m; // edi
  int v19; // ecx
  int v20; // eax
  int n; // edi
  int v22; // ecx
  int v23; // eax
  int ii; // edi
  int v25; // ecx
  int v26; // eax
  int jj; // edi
  int v28; // ecx
  int v29; // eax
  int kk; // edi
  _DWORD *v31; // ebx
  _DWORD *v32; // edi
  int v33; // ebp
  int v34; // ecx
  int v35; // eax
  int mm; // edi
  int v37; // ecx
  int v38; // eax
  int nn; // edi
  int v40; // ecx
  int v41; // eax
  int i1; // edi
  int v43; // eax
  int v44; // esi
  int i2; // ecx

  v2 = *(_DWORD **)(*(_DWORD *)(a2 + 4) + 12392);
  v3 = v2[333];
  v4 = v2[332];
  for ( i = 0; v4 != v3; v4 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v4 + 25) )
    {
      ++i;
    }
  }
  v6 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_surfaces.value = i;
  v7 = v2[339];
  v8 = v2[338];
  for ( j = 0; v8 != v7; v8 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v8 + 236) )
    {
      ++j;
    }
  }
  v6->visibility_stat_group.num_lights.value = j;
  v10 = (_DWORD *)v2[348];
  v11 = (_DWORD *)v2[347];
  v12 = 0;
  if ( v11 != v10 )
  {
    do
    {
      if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)*v11 + 16))(*v11) )
        ++v12;
      ++v11;
    }
    while ( v11 != v10 );
    v6 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  }
  v6->visibility_stat_group.num_particle_instances.value = v12;
  v13 = v2[352];
  v14 = v2[351];
  for ( k = 0; v14 != v13; v14 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v14 + 16557) )
    {
      ++k;
    }
  }
  v6->grass_stat_group.num_visible_patches.value = k;
  v16 = v2[342];
  v17 = v2[341];
  for ( m = 0; v17 != v16; v17 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v17 + 152) )
    {
      ++m;
    }
  }
  v6->deferred_decals_stat_group.num_decals.value = m;
  v19 = v2[345];
  v20 = v2[344];
  for ( n = 0; v20 != v19; v20 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v20 + 436) )
    {
      ++n;
    }
  }
  v6->visibility_stat_group.num_environment_probes.value = n;
  v22 = v2[355];
  v23 = v2[354];
  for ( ii = 0; v23 != v22; v23 += 4 )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !*(_BYTE *)(*(_DWORD *)v23 + 108) )
    {
      ++ii;
    }
  }
  v6->visibility_stat_group.num_ambient_volumes.value = ii;
  v25 = v2[333];
  v26 = v2[332];
  for ( jj = 0; v26 != v25; v26 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v26 + 25) )
    {
      ++jj;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_surfaces.value = jj;
  v28 = v2[339];
  v29 = v2[338];
  for ( kk = 0; v29 != v28; v29 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v29 + 236) )
    {
      ++kk;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_lights.value = kk;
  v31 = (_DWORD *)v2[348];
  v32 = (_DWORD *)v2[347];
  v33 = 0;
  if ( v32 != v31 )
  {
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)*v32 + 16))(*v32) )
        ++v33;
      ++v32;
    }
    while ( v32 != v31 );
    v6 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  }
  v6->visibility_stat_group.num_occlusion_culled_particle_instances.value = v33;
  v34 = v2[352];
  v35 = v2[351];
  for ( mm = 0; v35 != v34; v35 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v35 + 16557) )
    {
      ++mm;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_grass_patches.value = mm;
  v37 = v2[342];
  v38 = v2[341];
  for ( nn = 0; v38 != v37; v38 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v38 + 152) )
    {
      ++nn;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_decals.value = nn;
  v40 = v2[345];
  v41 = v2[344];
  for ( i1 = 0; v41 != v40; v41 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v41 + 436) )
    {
      ++i1;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_env_probes.value = i1;
  v43 = v2[355];
  v44 = v2[354];
  for ( i2 = 0; v44 != v43; v44 += 4 )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && *(_BYTE *)(*(_DWORD *)v44 + 108) )
    {
      ++i2;
    }
  }
  v6->visibility_stat_group.num_occlusion_culled_ambient_volumes.value = i2;
}
