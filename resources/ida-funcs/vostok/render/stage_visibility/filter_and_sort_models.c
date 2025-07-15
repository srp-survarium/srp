void __thiscall vostok::render::stage_visibility::filter_and_sort_models(
        vostok::render::stage_visibility *this,
        vostok::render::ambient_light **probes_generate_pass,
        vostok::render::render_surface_instance **__pred)
{
  vostok::render::ambient_light **v3; // ebx
  vostok::buffer_vector<vostok::render::ambient_light *> *v4; // esi
  vostok::render::ambient_light **v5; // ecx
  vostok::render::render_surface_instance **m_begin; // edx
  vostok::render::render_surface_instance **v7; // eax
  vostok::render::render_surface_instance *v8; // ecx
  int *i; // edx
  int v10; // edi
  int v11; // edx
  vostok::render::render_surface_instance **v12; // eax
  void *v13; // esp
  vostok::render::render_surface_instance **v14; // eax
  vostok::render::render_surface *v15; // ecx
  const vostok::render::render_surface_instance *const *j; // edi
  const vostok::render::render_surface_instance *v17; // eax
  vostok::buffer_vector<vostok::render::ambient_light *> *v18; // esi
  vostok::render::ambient_light **v19; // ebx
  vostok::render::render_surface_instance **v20; // eax
  vostok::render::render_surface *v21; // ecx
  vostok::render::render_surface_instance **v22; // eax
  vostok::render::render_surface *v23; // ecx
  vostok::render::ambient_light **k; // edi
  vostok::render::render_surface_vtbl *v25; // eax
  vostok::render::render_surface_instance **v26; // [esp-4h] [ebp-24h]
  vostok::render::render_surface_instance **v27; // [esp-4h] [ebp-24h]
  vostok::render::render_surface_instance **v28; // [esp-4h] [ebp-24h]
  vostok::render::render_surface_instance *v29; // [esp+0h] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> __first; // [esp+10h] [ebp-10h] BYREF
  vostok::render::ambient_light **end; // [esp+1Ch] [ebp-4h] BYREF

  v3 = probes_generate_pass;
  v4 = (vostok::buffer_vector<vostok::render::ambient_light *> *)&probes_generate_pass[1][96].m_collision_tree[2342];
  if ( !(_BYTE)__pred )
  {
    v5 = (vostok::render::ambient_light **)probes_generate_pass[1][96].m_collision_tree[2343].__vftable;
    m_begin = (vostok::render::render_surface_instance **)v4->m_begin;
    LOBYTE(__pred) = 0;
    v26 = __pred;
    probes_generate_pass = v5;
    end = v5;
    v7 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_if_occluded_predicate<vostok::render::render_surface_instance>>(
           (vostok::render::render_surface_instance *)v5,
           m_begin,
           (vostok::render::render_surface_instance **)v5);
    v8 = (vostok::render::render_surface_instance *)v26;
    if ( v7 != (vostok::render::render_surface_instance **)probes_generate_pass )
    {
      __pred = v7;
      for ( i = (int *)(v7 + 1); i != (int *)probes_generate_pass; i = (int *)(v11 + 4) )
      {
        v10 = *i;
        if ( !vostok::render::render_surface_instance::is_occluded(v8, *i) )
        {
          v12 = __pred++;
          *v12 = (vostok::render::render_surface_instance *)v10;
        }
      }
      v7 = __pred;
    }
    __pred = v7;
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      v4,
      (vostok::render::ambient_light ***)&__pred,
      &end);
  }
  v13 = alloca(4 * (v4->m_end - v4->m_begin));
  vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
    &v29,
    (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)v4,
    &__first,
    v4->m_end - v4->m_begin);
  LOBYTE(__pred) = 0;
  v27 = __pred;
  probes_generate_pass = (vostok::render::ambient_light **)__first.m_end;
  v14 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_a_forward_predicate>(
          (const vostok::render::render_surface_instance *const *)__first.m_begin,
          (vostok::render::render_surface *)__first.m_end,
          __first.m_end);
  v15 = (vostok::render::render_surface *)v27;
  if ( v14 != __first.m_end )
  {
    __pred = v14;
    for ( j = (const vostok::render::render_surface_instance *const *)(v14 + 1);
          j != (const vostok::render::render_surface_instance *const *)__first.m_end;
          ++j )
    {
      if ( !vostok::render::remove_model_if_not_a_forward_predicate::operator()(*j, v15) )
      {
        v15 = (vostok::render::render_surface *)__pred;
        v17 = *j;
        ++__pred;
        v15->__vftable = (vostok::render::render_surface_vtbl *)v17;
      }
    }
    v14 = __pred;
  }
  __pred = v14;
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    (vostok::buffer_vector<vostok::render::ambient_light *> *)&__first,
    (vostok::render::ambient_light ***)&__pred,
    &probes_generate_pass);
  __pred = __first.m_end;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
    __first.m_begin,
    &__pred,
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v3[1][96].m_collision_tree[6444]);
  __pred = (vostok::render::render_surface_instance **)v4->m_end;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
    (vostok::render::render_surface_instance **)v4->m_begin,
    &__pred,
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v3[1][96].m_collision_tree[8495]);
  v18 = (vostok::buffer_vector<vostok::render::ambient_light *> *)&v3[1][96].m_collision_tree[8495];
  v19 = (vostok::render::ambient_light **)v3[1][96].m_collision_tree[8496].__vftable;
  LOBYTE(__pred) = 0;
  v28 = __pred;
  v20 = (vostok::render::render_surface_instance **)v18->m_begin;
  probes_generate_pass = v19;
  v22 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_gbuffer_forward_predicate>(
          v20,
          v21,
          (vostok::render::render_surface_instance **)v19);
  v23 = (vostok::render::render_surface *)v28;
  if ( v22 != (vostok::render::render_surface_instance **)v19 )
  {
    __pred = v22;
    for ( k = (vostok::render::ambient_light **)(v22 + 1); k != v19; ++k )
    {
      if ( vostok::render::render_surface::get_material_effects(v23, LODWORD((*k)->m_properties.transform.i.w))->draw_to_gbuffer )
      {
        v23 = (vostok::render::render_surface *)__pred;
        v25 = (vostok::render::render_surface_vtbl *)*k;
        ++__pred;
        v23->__vftable = v25;
      }
    }
    v22 = __pred;
  }
  __pred = v22;
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    v18,
    (vostok::render::ambient_light ***)&__pred,
    &probes_generate_pass);
}
