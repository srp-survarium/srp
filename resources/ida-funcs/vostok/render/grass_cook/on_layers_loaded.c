void __thiscall vostok::render::grass_cook::on_layers_loaded(
        vostok::render::grass_cook *this,
        vostok::resources::queries_result *result,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent,
        vostok::render::grass_world *desc,
        vostok::render::grass_layer_data *const data,
        vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *count)
{
  unsigned int v6; // eax
  void *v7; // esp
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *m_end; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // ebx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *m_begin; // edi
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *i; // edi
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v15; // eax
  vostok::render::grass_cook **v16; // edi
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *p_type; // eax
  vostok::resources::managed_resource *v18; // esi
  vostok::resources::managed_resource *m_object; // ecx
  void *v20; // esp
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v21; // ebx
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v22; // eax
  vostok::resources::query_result *j; // edx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_layer_data_raw_file; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::resources::managed_resource *v26; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v27; // ecx
  vostok::memory::chunk_reader *v28; // ecx
  int v29; // ecx
  vostok::memory::reader *v30; // eax
  bool has_passed_filters; // al
  void *v32; // esp
  void *v33; // esp
  vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *v34; // ebx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v35; // ecx
  vostok::memory::chunk_reader *v36; // ecx
  vostok::memory::chunk_reader *v37; // ecx
  int v38; // ecx
  int v39; // eax
  int v40; // edi
  float v41; // xmm0_4
  float *v42; // esi
  float v43; // xmm0_4
  unsigned __int8 v44; // al
  unsigned int v45; // eax
  float v46; // xmm0_4
  unsigned int v47; // eax
  vostok::render::patch_sample *v48; // edi
  vostok::memory::chunk_reader::chunk_type v49; // eax
  vostok::render::patch_sample *v50; // edi
  bool v51; // zf
  vostok::render::patch_sample *v52; // edi
  int v53; // esi
  int v54; // ecx
  int v55; // eax
  vostok::render::patch_sample *v56; // ebx
  survarium::pure_game_effect_emitter_base *v57; // ebx
  vostok::render::patch_sample *v58; // eax
  vostok::render::patch_sample *v59; // edx
  vostok::render::patch_sample *v60; // edx
  vostok::render::patch_sample *k; // ecx
  vostok::render::patch_sample *m; // ecx
  unsigned int v63; // edi
  unsigned int v64; // esi
  unsigned int v65; // ebx
  const char *v66; // eax
  char *unmanaged_memory; // edx
  float v68; // edi
  survarium::pure_game_effect_emitter_base *v69; // ecx
  vostok::render::grass_patch **v70; // esi
  vostok::collision::space_partitioning_tree *v71; // eax
  survarium::pure_game_effect_emitter_base *v72; // eax
  vostok::resources::query_result_for_cook *v73; // ecx
  vostok::resources::query_result_for_cook *v74; // ecx
  vostok::memory::doug_lea_allocator *v75; // ecx
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *v76; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v77; // edi
  vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *v78; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *n; // esi
  vostok::render::grass_template *const v80; // [esp-18h] [ebp-9Ch]
  vostok::render::grass_instance *const v81; // [esp-14h] [ebp-98h]
  unsigned int v82; // [esp-10h] [ebp-94h]
  vostok::render::grass_patch *v83; // [esp-Ch] [ebp-90h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v84; // [esp+0h] [ebp-84h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> sum; // [esp+4h] [ebp-80h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v86; // [esp+8h] [ebp-7Ch] BYREF
  const char *v87[3]; // [esp+Ch] [ebp-78h] BYREF
  const unsigned __int8 *v88; // [esp+18h] [ebp-6Ch] BYREF
  vostok::memory::chunk_reader v89; // [esp+24h] [ebp-60h] BYREF
  const unsigned __int8 *v90; // [esp+44h] [ebp-40h] BYREF
  int v91; // [esp+48h] [ebp-3Ch]
  unsigned int v92; // [esp+4Ch] [ebp-38h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v93; // [esp+50h] [ebp-34h] BYREF
  const unsigned __int8 *v94; // [esp+54h] [ebp-30h]
  unsigned int v95; // [esp+58h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+5Ch] [ebp-28h] BYREF
  const unsigned __int8 *v97; // [esp+60h] [ebp-24h]
  unsigned int v98; // [esp+64h] [ebp-20h]
  vostok::memory::chunk_reader v99; // [esp+68h] [ebp-1Ch] BYREF
  _DWORD v100[3]; // [esp+88h] [ebp+4h] BYREF
  float *values; // [esp+94h] [ebp+10h] BYREF
  float *v102; // [esp+98h] [ebp+14h]
  char *v103; // [esp+9Ch] [ebp+18h]
  vostok::math::random32 random; // [esp+A0h] [ebp+1Ch]
  vostok::render::patch_sample *__last; // [esp+A8h] [ebp+24h]
  const char **v106; // [esp+ACh] [ebp+28h]
  unsigned int v107; // [esp+B0h] [ebp+2Ch]
  unsigned int grass_templates_count; // [esp+B4h] [ebp+30h] BYREF
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> > v109; // [esp+B8h] [ebp+34h] BYREF
  int v110; // [esp+C4h] [ebp+40h]
  int v111; // [esp+C8h] [ebp+44h]
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> value; // [esp+CCh] [ebp+48h] BYREF
  unsigned int v113; // [esp+D0h] [ebp+4Ch]
  unsigned int nodes_count; // [esp+D4h] [ebp+50h]
  bool v115; // [esp+DBh] [ebp+57h] BYREF
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *end; // [esp+DCh] [ebp+58h] BYREF
  float v117; // [esp+E0h] [ebp+5Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v118; // [esp+E4h] [ebp+60h] BYREF

  v6 = result->m_size - (_DWORD)count;
  v110 = 0;
  nodes_count = v6;
  v111 = 4 * v6;
  v7 = alloca(4 * v6);
  m_end = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v87;
  v109.m_begin = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)v87;
  v109.m_end = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)v87;
  v109.m_max_end = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)&v87[v6];
  if ( v6 )
  {
    p_m_unmanaged_resource = &result->m_queries[(_DWORD)count].m_unmanaged_resource;
    v113 = v6;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v118,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)p_m_unmanaged_resource);
      vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v118,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v118);
      vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>::push_back(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value,
        &v109);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value);
      p_m_unmanaged_resource += 184;
      --v113;
    }
    while ( v113 );
    m_end = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v109.m_end;
    if ( v109.m_begin != v109.m_end )
    {
      m_begin = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v109.m_begin;
      v11 = v109.m_end - v109.m_begin;
      v12 = v11;
      v13 = 0;
      while ( v12 != 1 )
      {
        ++v13;
        v12 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,int,stlp_std::less<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>>(
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v109.m_begin,
        v109.m_end,
        0,
        2 * v13,
        count);
      v86.m_object = (vostok::resources::managed_resource *)count;
      if ( v11 <= 16 )
      {
        stlp_std::priv::__insertion_sort<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>>(
          m_begin,
          m_end,
          (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)v86.m_object);
      }
      else
      {
        stlp_std::priv::__insertion_sort<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>>(
          m_begin,
          m_begin + 16,
          (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)v86.m_object);
        for ( i = m_begin + 16; i != m_end; ++i )
        {
          v86.m_object = (vostok::resources::managed_resource *)count;
          sum.m_object = (vostok::particle::particle_system_instance_impl *)this;
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &sum,
            i);
          stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>>(
            i,
            (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)sum.m_object);
          this = (vostok::render::grass_cook *)v86.m_object;
        }
      }
    }
  }
  v15 = v109.m_begin;
  grass_templates_count = (unsigned int)m_end;
  v16 = (vostok::render::grass_cook **)v109.m_begin;
  if ( (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v109.m_begin == m_end )
  {
    v16 = (vostok::render::grass_cook **)m_end;
LABEL_21:
    p_type = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)v16;
    goto LABEL_28;
  }
  while ( ++v15 != (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)m_end )
  {
    this = *v16;
    if ( *v16 == (vostok::render::grass_cook *)v15->m_object )
      goto LABEL_20;
    v16 = (vostok::render::grass_cook **)v15;
  }
  v16 = (vostok::render::grass_cook **)m_end;
LABEL_20:
  if ( v16 == (vostok::render::grass_cook **)m_end )
    goto LABEL_21;
  v18 = (vostok::resources::managed_resource *)v16;
  v86.m_object = (vostok::resources::managed_resource *)v16;
LABEL_25:
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v16,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v86.m_object);
  while ( ++v16 != (vostok::render::grass_cook **)m_end )
  {
    if ( (vostok::render::grass_cook *)v18->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable != *v16 )
    {
      v18 = (vostok::resources::managed_resource *)((char *)v18 + 4);
      v86.m_object = v18;
      goto LABEL_25;
    }
  }
  p_type = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)&v18->type;
LABEL_28:
  end = p_type;
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>>::erase(
    (vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> > *)this,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v109,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&end,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&grass_templates_count);
  grass_templates_count = v109.m_end - v109.m_begin;
  v20 = alloca(v111);
  v100[0] = v87;
  v100[1] = v87;
  v100[2] = (char *)v87 + v111;
  if ( nodes_count )
  {
    LODWORD(v117) = ((char *)v109.m_end - (char *)v109.m_begin) >> 4;
    v21 = &result->m_queries[(_DWORD)count].m_unmanaged_resource;
    v113 = nodes_count;
    while ( 1 )
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v118,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v21);
      vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v118,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v118);
      v22 = v109.m_begin;
      for ( j = (vostok::resources::query_result *)LODWORD(v117);
            (int)j > 0;
            j = (vostok::resources::query_result *)((char *)j - 1) )
      {
        if ( v22->m_object == value.m_object )
          goto LABEL_46;
        ++v22;
        if ( v22->m_object == value.m_object )
          goto LABEL_46;
        ++v22;
        if ( v22->m_object == value.m_object )
          goto LABEL_46;
        ++v22;
        if ( v22->m_object == value.m_object )
          goto LABEL_46;
        ++v22;
      }
      if ( v109.m_end - v22 == 1 )
        goto LABEL_44;
      if ( v109.m_end - v22 == 2 )
        goto LABEL_42;
      if ( v109.m_end - v22 != 3 )
        goto LABEL_45;
      if ( v22->m_object != value.m_object )
        break;
LABEL_46:
      end = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)(v22 - v109.m_begin);
      vostok::buffer_vector<unsigned int>::push_back(
        (vostok::buffer_vector<unsigned int> *)value.m_object,
        (int)v100,
        (const unsigned int *)&end);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value);
      v21 += 184;
      if ( !--v113 )
        goto LABEL_47;
    }
    ++v22;
LABEL_42:
    if ( v22->m_object == value.m_object )
      goto LABEL_46;
    ++v22;
LABEL_44:
    if ( v22->m_object != value.m_object )
    {
LABEL_45:
      v22 = v109.m_end;
      goto LABEL_46;
    }
    goto LABEL_46;
  }
LABEL_47:
  nodes_count = 0;
  if ( count )
  {
    p_layer_data_raw_file = &data->layer_data_raw_file;
    LODWORD(v117) = result->m_queries;
    v118.m_object = (survarium::pure_game_effect_emitter_base *)count;
    do
    {
      managed_resource = vostok::resources::query_result_for_user::get_managed_resource(
                           (vostok::resources::query_result_for_user *)LODWORD(v117),
                           (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&end);
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        managed_resource,
        p_layer_data_raw_file);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&end);
      v86.m_object = v26;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        &v86,
        p_layer_data_raw_file);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v27,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
        v86);
      vostok::memory::chunk_reader::chunk_reader(&v99, v97, v28, v98, (vostok::memory::chunk_reader::chunk_type)v87[0]);
      if ( vostok::memory::chunk_reader::chunk_position(
             &v99,
             (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate)88) != -1 )
      {
        v30 = vostok::memory::chunk_reader::open_reader(
                (vostok::memory::chunk_reader *)v29,
                &v99,
                &v88,
                (vostok::memory::chunk_reader::chunk_type *)0x58,
                (unsigned int)v87[0]);
        v29 = 12;
        nodes_count += v30->m_size / 0xC;
      }
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>((vostok::resources::pinned_ptr_const<unsigned char> *)v29);
      LODWORD(v117) += 736;
      p_layer_data_raw_file += 9;
      --v118.m_object;
    }
    while ( v118.m_object );
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"render_pc_dx11",
                               (const char *)2),
        m_object = v86.m_object,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_object,
      &v99);
    v110 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v99,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\grass_cook.cpp",
      0x10Bu,
      "void __thiscall vostok::render::grass_cook::on_layers_loaded(class vostok::resources::queries_result &,class vosto"
      "k::resources::query_result_for_cook *const ,struct vostok::render::grass_layer_desc *const ,struct vostok::render:"
      ":grass_layer_data *const ,const unsigned int)",
      "render_pc_dx11",
      error,
      "cook(before erasing)");
  }
  if ( (v110 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
      (int *)&v99);
  random.m_seed = 0;
  v32 = alloca(16 * nodes_count);
  v106 = &v87[4 * nodes_count];
  v118.m_object = (survarium::pure_game_effect_emitter_base *)v87;
  __last = (vostok::render::patch_sample *)v87;
  v33 = alloca(v111);
  values = (float *)v87;
  v102 = (float *)v87;
  v103 = (char *)v87 + v111;
  v113 = 0;
  v110 = 0;
  if ( count )
  {
    v34 = (vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *)((char *)&desc->m_reconstruction_info_actuality_tick
                                                                                  + 4);
    value.m_object = (vostok::render::grass_render_model *)&data->layer_data_raw_file;
    end = count;
    do
    {
      v86.m_object = m_object;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        &v86,
        (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)value.m_object);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v35,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v93,
        v86);
      vostok::memory::chunk_reader::chunk_reader(&v89, v94, v36, v95, (vostok::memory::chunk_reader::chunk_type)v87[0]);
      if ( vostok::memory::chunk_reader::chunk_position(
             &v89,
             (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate)88) != -1 )
      {
        vostok::memory::chunk_reader::open_reader(
          v37,
          &v89,
          &v90,
          (vostok::memory::chunk_reader::chunk_type *)0x58,
          (unsigned int)v87[0]);
        v38 = 280;
        v117 = 0.0;
        v107 = v92 / 0xC;
        v102 = values;
        v39 = v34->m_end - v34->m_begin;
        if ( (_BYTE)v39 )
        {
          v40 = 0;
          v111 = (unsigned __int8)v39;
          do
          {
            v41 = v34->m_begin[v40].probability_ + v117;
            v86.m_object = (vostok::resources::managed_resource *)&v34->m_begin[v40].probability_;
            v117 = v41;
            vostok::buffer_vector<float>::push_back(
              (vostok::buffer_vector<float> *)v38,
              (int)&values,
              (float *)v86.m_object);
            ++v40;
            --v111;
          }
          while ( v111 );
        }
        if ( v107 )
        {
          v42 = (float *)v91;
          v111 = v91;
          do
          {
            v86.m_object = (vostok::resources::managed_resource *)(v34->m_end - v34->m_begin);
            vostok::render::select_model_template(values, v117);
            v43 = *v42 * 0.0625;
            v99.m_chunks = *(const unsigned __int8 **)(v100[0] + 4 * (v113 + v44));
            v45 = vostok::math::floor(v43);
            v46 = v42[2] * 0.0625;
            v99.m_last_position = v45;
            v47 = vostok::math::floor(v46);
            v48 = __last;
            v99.m_chunk_count = v47;
            v49 = v110++;
            v99.m_type = v49;
            if ( __last >= (vostok::render::patch_sample *)v106
              && !`vostok::buffer_vector<vostok::render::patch_sample>::push_back'::`11'::debug_macro_helper_ignore_always )
            {
              v115 = 0;
              vostok::debug::on_error(
                &v115,
                process_error_true,
                0,
                "assertion_failed",
                "fatal error",
                "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
                "vostok::buffer_vector<struct vostok::render::patch_sample>::push_back",
                (const char *)0x12E,
                "buffer overflow",
                v87[0]);
              if ( vostok::debug::is_debugger_present() || v115 )
                __debugbreak();
            }
            if ( v48 )
            {
              v50 = __last;
              __last->template_id = (unsigned int)v99.m_chunks;
              v50 = (vostok::render::patch_sample *)((char *)v50 + 4);
              v50->template_id = v99.m_last_position;
              v50 = (vostok::render::patch_sample *)((char *)v50 + 4);
              v50->template_id = v99.m_chunk_count;
              v50->x = v99.m_type;
              v42 = (float *)v111;
            }
            ++__last;
            v42 += 3;
            v51 = v107-- == 1;
            v111 = (int)v42;
          }
          while ( !v51 );
        }
      }
      v113 += v34->m_end - v34->m_begin;
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>((vostok::resources::pinned_ptr_const<unsigned char> *)0x118);
      value.m_object = (vostok::render::grass_render_model *)((char *)value.m_object + 36);
      v34 = (vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *)((char *)v34 + 4512);
      end = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)((char *)end - 1);
    }
    while ( end );
    if ( (vostok::render::patch_sample *)v118.m_object != __last )
    {
      v52 = (vostok::render::patch_sample *)v118.m_object;
      v53 = ((char *)__last - (char *)v118.m_object) >> 4;
      v54 = v53;
      v55 = 0;
      while ( v54 != 1 )
      {
        ++v55;
        v54 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::render::patch_sample *,vostok::render::patch_sample,int,stlp_std::less<vostok::render::patch_sample>>(
        (stlp_std::less<vostok::render::patch_sample> *)v118.m_object,
        (vostok::render::patch_sample *)v118.m_object,
        __last,
        0,
        2 * v55,
        (vostok::render::patch_sample *)count);
      v86.m_object = (vostok::resources::managed_resource *)count;
      if ( v53 <= 16 )
      {
        stlp_std::priv::__insertion_sort<vostok::render::patch_sample *,vostok::render::patch_sample,stlp_std::less<vostok::render::patch_sample>>(
          v52,
          __last,
          (vostok::render::patch_sample *)v86.m_object);
      }
      else
      {
        v56 = v52 + 16;
        stlp_std::priv::__insertion_sort<vostok::render::patch_sample *,vostok::render::patch_sample,stlp_std::less<vostok::render::patch_sample>>(
          v52,
          v52 + 16,
          (vostok::render::patch_sample *)v86.m_object);
        while ( v56 != __last )
        {
          v86.m_object = (vostok::resources::managed_resource *)count;
          stlp_std::priv::__unguarded_linear_insert<vostok::render::patch_sample *,vostok::render::patch_sample,stlp_std::less<vostok::render::patch_sample>>(
            v56,
            *v56);
          ++v56;
        }
      }
    }
  }
  v57 = v118.m_object;
  v58 = __last;
  v59 = (vostok::render::patch_sample *)v118.m_object;
  if ( (vostok::render::patch_sample *)v118.m_object == __last )
  {
    v60 = __last;
LABEL_102:
    if ( v60 != v58 )
      v58 = (vostok::render::patch_sample *)((char *)v57 + 16 * ((((char *)v58 - (char *)v57) >> 4) - (v58 - v60)));
    goto LABEL_104;
  }
  for ( k = (vostok::render::patch_sample *)&v118.m_object->vostok::resources::resource_reconstruction_info;
        k != __last;
        ++k )
  {
    if ( v59->template_id == k->template_id && v59->x == k->x && v59->y == k->y )
      goto LABEL_93;
    v59 = k;
  }
  v59 = __last;
LABEL_93:
  if ( v59 != __last )
  {
    for ( m = v59 + 1; m != v58; ++m )
    {
      if ( v59->template_id != m->template_id || v59->x != m->x || v59->y != m->y )
      {
        ++v59;
        v59->template_id = m->template_id;
        v59->x = m->x;
        v59->y = m->y;
        v59->id = m->id;
      }
    }
    v60 = v59 + 1;
    goto LABEL_102;
  }
LABEL_104:
  v63 = 36 * grass_templates_count;
  v64 = 92 * nodes_count;
  v65 = ((char *)v58 - (char *)v57) >> 4;
  end = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)(36 * grass_templates_count + 16572 * v65 + 40 * nodes_count + 92 * nodes_count + 524);
  v66 = type_info::name(&unsigned char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = (char *)vostok::resources::allocate_unmanaged_memory((unsigned int)end, v66);
  LODWORD(v68) = &unmanaged_memory[v63 + 472];
  v69 = (survarium::pure_game_effect_emitter_base *)(v64 + LODWORD(v68));
  v70 = (vostok::render::grass_patch **)(v64 + LODWORD(v68) + 16568 * v65);
  random.m_seed = (unsigned int)unmanaged_memory;
  if ( unmanaged_memory )
  {
    v86.m_object = (vostok::resources::managed_resource *)count;
    sum.m_object = (vostok::particle::particle_system_instance_impl *)result;
    v83 = (vostok::render::grass_patch *)v69;
    v82 = nodes_count;
    v71 = vostok::collision::new_space_partitioning_tree(
            &v70[v65],
            (const unsigned int)(unmanaged_memory + 472),
            v68,
            nodes_count);
    vostok::render::grass_world::grass_world(
      (vostok::resources::unmanaged_resource *)grass_templates_count,
      v70,
      (vostok::render::grass_world *)random.m_seed,
      v71,
      v80,
      v81,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v82,
      v83,
      v65,
      desc,
      data,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)sum.m_object,
      (vostok::math::float3 **)v86.m_object);
  }
  else
  {
    v72 = 0;
  }
  v86.m_object = (vostok::resources::managed_resource *)end;
  sum.m_object = (vostok::particle::particle_system_instance_impl *)&vostok::resources::nocache_memory;
  v84.m_object = v69;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v84,
    v72);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v73,
    parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v84.m_object,
    (const vostok::resources::memory_type *)sum.m_object,
    (unsigned int)v86.m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v74,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  v76 = count;
  if ( count )
  {
    v77 = &data->layer_data_raw_file;
    v78 = (vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *)((char *)&desc->m_reconstruction_info_actuality_tick
                                                                                  + 4);
    do
    {
      v78->m_end = v78->m_begin;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v77);
      v78 = (vostok::fixed_vector<vostok::render::grass_layer_desc::model_desc,16> *)((char *)v78 + 4512);
      v77 += 9;
      v76 = (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> *)((char *)v76 - 1);
    }
    while ( v76 );
  }
  if ( desc )
    vostok::memory::doug_lea_allocator::free_impl(
      v75,
      (int)&vostok::memory::g_resources_helper_allocator,
      (char *)desc,
      v87[0],
      v87[1],
      (const unsigned int)v87[2]);
  for ( n = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v109.m_begin;
        n != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v109.m_end;
        ++n )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(n);
  }
}
