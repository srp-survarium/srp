void __thiscall vostok::render::stage_visibility::gather_statistics(vostok::render::stage_visibility *this)
{
  vostok::render::renderer_context *m_context; // eax
  _DWORD *v2; // esi
  int v3; // ebx
  int *v4; // edi
  int *i; // edx
  int v6; // edx
  vostok::render::statistics *v7; // edx
  int *v8; // ebx
  int *j; // edi
  int v10; // eax
  vostok::particle::render_particle_emitter_instance **v11; // ebx
  vostok::particle::render_particle_emitter_instance **v12; // edi
  bool v13; // al
  int *v14; // edi
  int *v15; // ebx
  int *v16; // edi
  int k; // ebx
  int *v18; // ebx
  int *m; // edi
  int v20; // eax
  int *v21; // ebx
  int *n; // edi
  int v23; // eax
  int *v24; // ebx
  int *ii; // edi
  int v26; // eax
  int *v27; // ebx
  int *jj; // edi
  int v29; // eax
  int *v30; // ebx
  int *kk; // edi
  int v32; // eax
  _DWORD *v33; // ebx
  _DWORD *v34; // edi
  int v35; // eax
  int *v36; // edi
  int *v37; // ebx
  int *v38; // edi
  int mm; // ebx
  int *v40; // ebx
  int *nn; // edi
  int v42; // eax
  int *v43; // ebx
  int *i1; // edi
  int *v45; // edi
  int *v46; // esi
  int v47; // ebx
  vostok::render::stage_visibility *v48; // [esp-4h] [ebp-18h]
  int v49; // [esp+Ch] [ebp-8h]
  int v50; // [esp+Ch] [ebp-8h]
  int v51; // [esp+Ch] [ebp-8h]
  int v52; // [esp+Ch] [ebp-8h]
  int v53; // [esp+10h] [ebp-4h]
  int v54; // [esp+10h] [ebp-4h]
  int v55; // [esp+10h] [ebp-4h]
  int v56; // [esp+10h] [ebp-4h]
  int v57; // [esp+10h] [ebp-4h]
  int v58; // [esp+10h] [ebp-4h]
  int v59; // [esp+10h] [ebp-4h]
  int v60; // [esp+10h] [ebp-4h]
  int v61; // [esp+10h] [ebp-4h]

  m_context = this->m_context;
  v2 = &m_context->m_scene_view.m_object->__vftable;
  v3 = 0;
  if ( *(int *)((char *)&dword_8B9668 + (unsigned int)m_context->m_scene)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v49 = *(int *)((char *)&dword_8B9668 + (unsigned int)this->m_context->m_scene) + 340;
  }
  else
  {
    v49 = 0;
  }
  v4 = (int *)v2[2343];
  for ( i = (int *)v2[2342]; i != v4; i = (int *)(v6 + 4) )
  {
    if ( !vostok::render::render_surface_instance::is_occluded((vostok::render::render_surface_instance *)this, *i) )
      ++v3;
  }
  v7 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  v53 = 0;
  vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_surfaces.value = v3;
  v8 = (int *)v2[11062];
  for ( j = (int *)v2[11061]; j != v8; ++j )
  {
    if ( !vostok::render::light::is_occluded((vostok::render::light *)this, *j) )
      ++v53;
  }
  v10 = v53;
  v54 = 0;
  v7->visibility_stat_group.num_lights.value = v10;
  v11 = (vostok::particle::render_particle_emitter_instance **)v2[14143];
  v12 = (vostok::particle::render_particle_emitter_instance **)v2[14142];
  if ( v12 != v11 )
  {
    do
    {
      v13 = vostok::render::is_not_occluded_predicate_vostok::particle::render_particle_emitter_instance_(*v12);
      this = v48;
      if ( v13 )
        ++v54;
      ++v12;
    }
    while ( v12 != v11 );
    v7 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  }
  v7->visibility_stat_group.num_particle_instances.value = v54;
  if ( v49 )
  {
    v55 = 0;
    v14 = *(int **)v49;
    v15 = *(int **)(v49 + 4);
    while ( v14 != v15 )
    {
      if ( !vostok::render::grass_patch::is_occluded((vostok::render::grass_patch *)this, *v14) )
        ++v55;
      ++v14;
    }
    v7->grass_stat_group.num_visible_patches.value = v55;
  }
  else
  {
    v7->grass_stat_group.num_visible_patches.value = 0;
  }
  v16 = (int *)v2[12088];
  for ( k = 0; v16 != (int *)v2[12089]; ++v16 )
  {
    if ( !vostok::render::decal_instance::is_occluded((vostok::render::decal_instance *)this, *v16) )
      ++k;
  }
  v56 = 0;
  v7->deferred_decals_stat_group.num_decals.value = k;
  v18 = (int *)v2[13116];
  for ( m = (int *)v2[13115]; m != v18; ++m )
  {
    if ( !vostok::render::environment_probe::is_occluded((vostok::render::environment_probe *)this, *m) )
      ++v56;
  }
  v20 = v56;
  v57 = 0;
  v7->visibility_stat_group.num_environment_probes.value = v20;
  v21 = (int *)v2[15170];
  for ( n = (int *)v2[15169]; n != v21; ++n )
  {
    if ( !vostok::render::ambient_volume::is_occluded((vostok::render::ambient_volume *)this, *n) )
      ++v57;
  }
  v23 = v57;
  v58 = 0;
  v7->visibility_stat_group.num_ambient_volumes.value = v23;
  v24 = (int *)v2[16197];
  for ( ii = (int *)v2[16196]; ii != v24; ++ii )
  {
    if ( !vostok::render::ambient_light::is_occluded((vostok::render::ambient_light *)this, *ii) )
      ++v58;
  }
  v26 = v58;
  v59 = 0;
  v7->visibility_stat_group.num_ambient_lights.value = v26;
  v27 = (int *)v2[2343];
  for ( jj = (int *)v2[2342]; jj != v27; ++jj )
  {
    if ( vostok::render::render_surface_instance::is_occluded((vostok::render::render_surface_instance *)this, *jj) )
      ++v59;
  }
  v29 = v59;
  v60 = 0;
  v7->visibility_stat_group.num_occlusion_culled_surfaces.value = v29;
  v30 = (int *)v2[11062];
  for ( kk = (int *)v2[11061]; kk != v30; ++kk )
  {
    if ( vostok::render::light::is_occluded((vostok::render::light *)this, *kk) )
      ++v60;
  }
  v32 = v60;
  v61 = 0;
  v7->visibility_stat_group.num_occlusion_culled_lights.value = v32;
  v33 = (_DWORD *)v2[14143];
  v34 = (_DWORD *)v2[14142];
  if ( v34 != v33 )
  {
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)*v34 + 16))(*v34) )
        ++v61;
      ++v34;
    }
    while ( v34 != v33 );
    v7 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  }
  v7->visibility_stat_group.num_occlusion_culled_particle_instances.value = v61;
  v35 = v49;
  if ( v49 )
  {
    v50 = 0;
    v36 = *(int **)v35;
    v37 = *(int **)(v35 + 4);
    while ( v36 != v37 )
    {
      if ( vostok::render::grass_patch::is_occluded((vostok::render::grass_patch *)this, *v36) )
        ++v50;
      ++v36;
    }
    v7->visibility_stat_group.num_occlusion_culled_grass_patches.value = v50;
  }
  else
  {
    v7->visibility_stat_group.num_occlusion_culled_grass_patches.value = 0;
  }
  v38 = (int *)v2[12088];
  for ( mm = 0; v38 != (int *)v2[12089]; ++v38 )
  {
    if ( vostok::render::decal_instance::is_occluded((vostok::render::decal_instance *)this, *v38) )
      ++mm;
  }
  v51 = 0;
  v7->visibility_stat_group.num_occlusion_culled_decals.value = mm;
  v40 = (int *)v2[13116];
  for ( nn = (int *)v2[13115]; nn != v40; ++nn )
  {
    if ( vostok::render::environment_probe::is_occluded((vostok::render::environment_probe *)this, *nn) )
      ++v51;
  }
  v42 = v51;
  v52 = 0;
  v7->visibility_stat_group.num_occlusion_culled_env_probes.value = v42;
  v43 = (int *)v2[15170];
  for ( i1 = (int *)v2[15169]; i1 != v43; ++i1 )
  {
    if ( vostok::render::ambient_volume::is_occluded((vostok::render::ambient_volume *)this, *i1) )
      ++v52;
  }
  v7->visibility_stat_group.num_occlusion_culled_ambient_volumes.value = v52;
  v45 = (int *)v2[16197];
  v46 = (int *)v2[16196];
  v47 = 0;
  while ( v46 != v45 )
  {
    if ( vostok::render::ambient_light::is_occluded((vostok::render::ambient_light *)this, *v46) )
      ++v47;
    ++v46;
  }
  v7->visibility_stat_group.num_occlusion_culled_ambient_lights.value = v47;
}
