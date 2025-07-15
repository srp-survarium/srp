void __usercall vostok::render::stage_shadow_direct::execute(
        vostok::render::stage_shadow_direct *this@<ecx>,
        float a2@<xmm14>)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::base_scene_view *m_object; // ecx
  vostok::render::environment_properties *v5; // ecx
  vostok::render::renderer_context *v6; // eax
  vostok::render::base_scene_view *v7; // eax
  unsigned int v8; // esi
  bool v9; // zf
  vostok::fixed_vector<vostok::render::caster_model,2048> *m_caster_models; // ecx
  unsigned int v11; // edx
  unsigned int v12; // eax
  vostok::render::res_texture *v13; // eax
  vostok::render::renderer_context *v14; // ecx
  vostok::render::scene *m_scene; // edi
  vostok::render::renderer *v16; // eax
  unsigned int v17; // edi
  vostok::render::res_pass *v18; // eax
  vostok::math::cuboid *v19; // ecx
  vostok::render::stage_shadow_direct *v20; // ecx
  vostok::render::renderer *m_renderer; // eax
  unsigned int v22; // esi
  unsigned __int8 m_num_first_calls; // al
  unsigned int v24; // eax
  vostok::tasks::task *v25; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  unsigned int v27; // esi
  vostok::fixed_vector<vostok::render::caster_model,2048> *v28; // edi
  vostok::render::res_texture *v29; // esi
  int i; // ecx
  float *v31; // edi
  unsigned int v32; // eax
  vostok::render::material_effects *material_effects; // eax
  vostok::render::enum_vertex_input_type m_vertex_input_type; // eax
  D3D11_USAGE *p_Usage; // esi
  float max_tiling; // eax
  int v37; // edx
  int v38; // ecx
  const vostok::math::float4x4 *v39; // edx
  float *v40; // edi
  float *v41; // eax
  float v42; // xmm5_4
  float v43; // xmm4_4
  const vostok::math::float4x4 *v44; // edx
  int v45; // edi
  int z_low; // esi
  vostok::render::backend *v47; // ecx
  vostok::fixed_vector<vostok::render::caster_model,2048> *m_previous_caster_models; // ecx
  vostok::render::caster_model **p_m_end; // eax
  vostok::render::res_pass *v50; // ecx
  int v51; // eax
  vostok::render::res_pass *v52; // edi
  _DWORD *v53; // eax
  _DWORD *v54; // esi
  _DWORD *v55; // eax
  vostok::render::effect_manager *v56; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> > *p_m_techniques; // edi
  stlp_std::priv::_Rb_tree_node_base *v59; // eax
  vostok::memory::doug_lea_allocator *v60; // ecx
  vostok::memory::doug_lea_allocator *v61; // esi
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v62; // ecx
  vostok::memory::doug_lea_allocator *v63; // ecx
  vostok::render::res_texture *v64; // edi
  vostok::render::backend *v65; // ecx
  vostok::render::resource_manager *v66; // ecx
  unsigned int v67; // xmm0_4
  unsigned int v68; // xmm1_4
  float v69; // xmm2_4
  vostok::render::render_target *v70; // ecx
  unsigned int v71; // eax
  int v72; // esi
  vostok::render::backend *v73; // ecx
  vostok::render::stage_shadow_direct *v74; // ecx
  vostok::render::stage_shadow_direct *v75; // ecx
  float *v76; // esi
  vostok::render::res_texture *v77; // eax
  int v78; // ecx
  vostok::render::renderer_context *v79; // ecx
  vostok::render::renderer_context *v80; // ecx
  vostok::render::res_texture *v81; // esi
  vostok::render::res_texture *v82; // eax
  int v83; // eax
  _DWORD *v84; // ecx
  _DWORD *v85; // eax
  vostok::render::res_pass *v86; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v87; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *texture; // eax
  vostok::render::backend *v89; // ecx
  vostok::render::backend *v90; // ecx
  vostok::render::render_target *v91; // ecx
  vostok::render::render_target *v92; // ecx
  vostok::render::render_target *v93; // ecx
  vostok::render::stage_shadow_direct *v94; // ecx
  vostok::render::stage_shadow_direct *v95; // ecx
  float z; // esi
  unsigned int v97; // edi
  unsigned int v98; // edi
  int v99; // ecx
  char *v100; // eax
  char *v101; // esi
  _DWORD *v102; // edi
  unsigned int v103; // eax
  char *v104; // eax
  vostok::fixed_vector<vostok::render::caster_model,2048> *v105; // esi
  vostok::render::caster_model **v106; // edx
  vostok::render::renderer_context *v107; // esi
  vostok::render::res_pass *v108; // edi
  vostok::render::renderer_context *v109; // ecx
  vostok::render::renderer_context *v110; // eax
  vostok::render::renderer_context *v111; // ecx
  char *v112; // edi
  vostok::math::float4x4 *texture_space_transform; // eax
  vostok::render::renderer_context *v114; // edi
  vostok::math::float4x4 *v115; // eax
  vostok::math::float4x4 *p_m_v2shadow0; // edi
  vostok::render::system_renderer *v117; // [esp-18h] [ebp-1BCh]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v118; // [esp-14h] [ebp-1B8h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v119; // [esp-10h] [ebp-1B4h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v120; // [esp-Ch] [ebp-1B0h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v121; // [esp-8h] [ebp-1ACh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v122; // [esp-4h] [ebp-1A8h] BYREF
  D3D11_VIEWPORT *epsilon; // [esp+0h] [ebp-1A4h]
  const char *v124; // [esp+4h] [ebp-1A0h]
  const char *v125; // [esp+8h] [ebp-19Ch]
  float v126; // [esp+Ch] [ebp-198h]
  unsigned int v127; // [esp+10h] [ebp-194h] BYREF
  unsigned int v128; // [esp+14h] [ebp-190h]
  unsigned int cascade_index; // [esp+18h] [ebp-18Ch] BYREF
  unsigned int v130; // [esp+1Ch] [ebp-188h]
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v131; // [esp+20h] [ebp-184h] BYREF
  unsigned int v132; // [esp+24h] [ebp-180h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> setup_index; // [esp+28h] [ebp-17Ch] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+2Fh] [ebp-175h] BYREF
  unsigned int shadow_map_size; // [esp+34h] [ebp-170h]
  float v136; // [esp+38h] [ebp-16Ch]
  float v137; // [esp+3Ch] [ebp-168h]
  vostok::math::float3_pod v138; // [esp+40h] [ebp-164h] BYREF
  vostok::math::float3_pod other; // [esp+4Ch] [ebp-158h] BYREF
  vostok::math::float3 viewer_pos; // [esp+58h] [ebp-14Ch] BYREF
  vostok::math::float4x4 v141; // [esp+64h] [ebp-140h] BYREF
  vostok::math::float3 v142[3]; // [esp+A8h] [ebp-FCh] BYREF
  vostok::tasks::task v143; // [esp+CCh] [ebp-D8h] BYREF
  vostok::math::frustum v144; // [esp+12Ch] [ebp-78h] BYREF

  if ( !this->is_effects_ready(this) )
    return;
  wszName[1] = (pix_event_wrapper_dx11)s_use_csm_scrolling;
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_sun_shadows_stage
    || !this->is_enabled(this)
    || (m_context = this->m_context,
        m_object = m_context->m_scene_view.m_object,
        LOBYTE(m_object[1].m_children_resources.m_last))
    && !BYTE1(m_object[1].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type) )
  {
    this->execute_disabled(this);
    return;
  }
  qmemcpy(&v141, &this->m_renderer->m_orig_projection_matrix, sizeof(v141));
  vostok::render::renderer_context::push_set_p((vostok::render::renderer_context *)&v141, (int)m_context, &v141);
  v6 = this->m_context;
  viewer_pos = *(vostok::math::float3 *)&v6->m_view_pos.x;
  if ( (_S6_9 & 1) == 0 )
  {
    v7 = v6->m_scene_view.m_object;
    _S6_9 |= 1u;
    vostok::render::environment_properties::get_sun_direction(v5, (int)&v7[1], &s_prev_sun_direction.x);
  }
  v8 = 4 - vostok::quasi_singleton<vostok::render::options>::pinst->current.m_num_shadow_cascades;
  v9 = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality == 0;
  v130 = v8;
  m_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)v9;
  v11 = 4 - v9;
  setup_index.m_object = (vostok::render::res_texture *)v9;
  v132 = v11;
  if ( v8 < v11 )
  {
    m_caster_models = this->m_caster_models;
    v12 = v11 - v8;
    do
    {
      m_caster_models->m_end = m_caster_models->m_begin;
      ++m_caster_models;
      --v12;
    }
    while ( v12 );
  }
  shadow_map_size = 0;
  if ( v8 < v11 )
  {
    cascade_index = v130;
    v128 = 20660;
    v127 = (unsigned int)this + (_DWORD)&loc_40BF9 + 3;
    do
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v131,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)v127 + 28));
      v13 = (vostok::render::res_texture *)v131.m_object;
      v14 = this->m_context;
      *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v14->m_targets + v128) = v131;
      if ( v13 )
      {
        if ( !--v13->m_reference_count )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)v14,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v13);
      }
      vostok::render::stage_shadow_direct::calculate_matrices(
        (vostok::render::stage_shadow_direct *)v14,
        a2,
        *(float *)&this,
        cascade_index,
        shadow_map_size++,
        *(unsigned int *)((char *)&this->__vftable + (_DWORD)&loc_40BF4 + 4),
        *(float *)&setup_index.m_object);
      v127 += 4;
      v128 += 4;
      ++cascade_index;
    }
    while ( cascade_index < v132 );
  }
  if ( wszName[1] )
  {
    v9 = !this->m_first_call;
    m_scene = this->m_context->m_scene;
    cascade_index = (unsigned int)m_scene;
    if ( !v9 || (v16 = this->m_renderer, v16->m_scene_changed) || v16->m_atmosphere_changed )
    {
      m_renderer = this->m_renderer;
      if ( m_renderer->m_scene_changed || m_renderer->m_atmosphere_changed )
      {
        this->m_first_call = 1;
        this->m_num_first_calls = 0;
      }
      v128 = 0;
      if ( v130 < v132 )
      {
        v22 = v132 - v130;
        do
        {
          vostok::render::stage_shadow_direct::flush_cascade_cache(
            (vostok::render::stage_shadow_direct *)m_caster_models,
            (const unsigned int)this,
            v128++);
          --v22;
        }
        while ( v22 );
      }
    }
    else
    {
      v128 = 0;
      if ( v130 < v132 )
      {
        v17 = v132 - v130;
        shadow_map_size = (unsigned int)this + (_DWORD)&loc_406F3 + 5;
        do
        {
          v18 = *(vostok::render::res_pass **)(cascade_index + 590156);
          v127 = *(_DWORD *)((char *)&loc_90148 + cascade_index);
          v131.m_object = v18;
          if ( (vostok::render::res_pass *)v127 != v18 )
          {
            while ( 1 )
            {
              vostok::math::mul4x3(
                (const vostok::math::float4x4 *)(shadow_map_size + 256),
                (const vostok::math::float4x4 *)shadow_map_size,
                &v141);
              vostok::math::frustum::frustum(&v144, &v141);
              if ( vostok::math::cuboid::test_inexact(v19, (int)&v144, (vostok::math::aabb_plane *)v127) != 2 )
                break;
              v127 += 24;
              if ( (vostok::render::res_pass *)v127 == v131.m_object )
                goto LABEL_28;
            }
            vostok::render::stage_shadow_direct::flush_cascade_cache(v20, (const unsigned int)this, v128);
          }
LABEL_28:
          ++v128;
          shadow_map_size += 64;
          --v17;
        }
        while ( v17 );
        m_scene = (vostok::render::scene *)cascade_index;
      }
    }
    m_num_first_calls = this->m_num_first_calls;
    if ( m_num_first_calls > 0x64u )
      this->m_first_call = 0;
    this->m_num_first_calls = m_num_first_calls + 1;
    m_scene->m_modified_model_aabb.m_end = *(vostok::math::aabb **)((char *)&loc_90148 + (_DWORD)m_scene);
  }
  v128 = 0;
  if ( s_async_shadow_culling )
  {
    if ( v130 < v132 )
    {
      shadow_map_size = (unsigned int)this->m_caster_models;
      cascade_index = v132 - v130;
      do
      {
        v24 = *(unsigned int *)((char *)&this->__vftable + (_DWORD)&loc_40BF4 + 4);
        *(_QWORD *)&v142[0].x = __PAIR64__(shadow_map_size, (unsigned int)this);
        LODWORD(v142[0].z) = &vostok::memory::g_mt_allocator;
        v142[1] = viewer_pos;
        LODWORD(v142[2].elements[2]) = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)setup_index.m_object;
        *(_QWORD *)&v142[2].x = __PAIR64__(v24, v128);
        v143.m_child_counter = (volatile int)vostok::render::stage_shadow_direct::prepare_visibile_objects;
        v143.m_next_task_in_child_queue = 0;
        v143.m_event_wait_for_children = 0;
        qmemcpy(&v143.m_function, v142, 0x24u);
        epsilon = (D3D11_VIEWPORT *)&v144;
        qmemcpy(&v144, (const void *)&v143.m_child_counter, 0x30u);
        if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
        {
          v143.m_next_task_in_child_queue = 0;
        }
        else
        {
          qmemcpy(&v141, &v144, 0x30u);
          v25 = (vostok::tasks::task *)operator new(0x30u);
          if ( v25 )
          {
            qmemcpy(v25, &v141, 0x30u);
            v143.m_next_task_in_type_queue = v25;
          }
          else
          {
            v143.m_next_task_in_type_queue = 0;
          }
          v143.m_next_task_in_child_queue = (vostok::tasks::task *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf6<void,vostok::render::stage_shadow_direct,vostok::fixed_vector<vostok::render::caster_model,2048> *,vostok::memory::base_allocator *,vostok::math::float3 const &,unsigned int,unsigned int,unsigned int>,boost::_bi::list7<boost::_bi::value<vostok::render::stage_shadow_direct *>,boost::_bi::value<vostok::fixed_vector<vostok::render::caster_model,2048> *>,boost::_bi::value<vostok::memory::pthreads3_allocator *>,boost::_bi::value<vostok::math::float3>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable;
        }
        vostok::tasks::task_manager::spawn_task(
          (vostok::tasks::task_manager *)&this->m_cascaded_shadow_parent_task,
          &v143,
          (boost::function<void __cdecl(void)> *)this->m_cascaded_shadow_task_type,
          &this->m_cascaded_shadow_parent_task);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v26,
          (int *)&v143);
        ++v128;
        shadow_map_size += 16396;
        --cascade_index;
      }
      while ( cascade_index );
    }
    vostok::tasks::thread_pool::wait_for_task_list(&this->m_cascaded_shadow_parent_task, s_thread_pool.m_variable);
  }
  else if ( v130 < v132 )
  {
    v27 = v132 - v130;
    v28 = this->m_caster_models;
    do
    {
      vostok::render::stage_shadow_direct::prepare_visibile_objects(
        this,
        v28++,
        vostok::render::g_allocator,
        (vostok::math::float4x4 *)&viewer_pos,
        v128++,
        *(unsigned int *)((char *)&this->__vftable + (_DWORD)&loc_40BF4 + 4),
        (unsigned int)setup_index.m_object);
      --v27;
    }
    while ( v27 );
  }
  if ( wszName[1] )
  {
    v127 = 0;
    if ( v130 < v132 )
    {
      cascade_index = v132 - v130;
      while ( 1 )
      {
        v29 = (vostok::render::res_texture *)((char *)this + 16396 * v127);
        v29->m_desc_3d.BindFlags = v29->m_desc_3d.Usage;
        i = *(_DWORD *)&v29[142].m_name.m_string.m_buffer[236];
        *(_DWORD *)&v29[142].m_name.m_string.m_buffer[240] = i;
        v31 = *(float **)&v29[285].m_name.m_string.m_buffer[40];
        v32 = *(_DWORD *)&v29[285].m_name.m_string.m_buffer[44];
        setup_index.m_object = v29;
        v128 = v32;
        if ( v31 != (float *)v32 )
          break;
LABEL_86:
        ++v127;
        if ( !--cascade_index )
          goto LABEL_87;
      }
      while ( 1 )
      {
        material_effects = vostok::render::render_surface::get_material_effects(
                             (vostok::render::render_surface *)i,
                             *(_DWORD *)(*(_DWORD *)v31 + 16));
        if ( material_effects->is_wind_swings && !v127
          || (m_vertex_input_type = material_effects->m_vertex_input_type,
              m_vertex_input_type == skeletal_4_bones_mesh_vertex_input_type)
          || m_vertex_input_type == skeletal_3_bones_mesh_vertex_input_type
          || m_vertex_input_type == skeletal_2_bones_mesh_vertex_input_type
          || m_vertex_input_type == skeletal_1_bones_mesh_vertex_input_type
          || *(_BYTE *)(*(_DWORD *)(*(_DWORD *)v31 + 20) + 277) )
        {
          p_Usage = (D3D11_USAGE *)&setup_index.m_object[142].m_name.m_string.m_buffer[236];
          goto LABEL_84;
        }
        max_tiling = *(float *)&v29[428].streaming_priority;
        v37 = *(_DWORD *)v31;
        v136 = v31[1];
        v38 = LODWORD(v29[428].max_tiling) - LODWORD(max_tiling);
        v131.m_object = (vostok::render::res_pass *)LODWORD(max_tiling);
        for ( i = v38 >> 5; i > 0; --i )
        {
          if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
            goto LABEL_81;
          LODWORD(max_tiling) += 8;
          if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
            goto LABEL_81;
          LODWORD(max_tiling) += 8;
          if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
            goto LABEL_81;
          LODWORD(max_tiling) += 8;
          if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
            goto LABEL_81;
          LODWORD(max_tiling) += 8;
        }
        i = ((LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3) - 1;
        if ( (LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3 == 1 )
          goto LABEL_79;
        i = ((LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3) - 2;
        if ( (LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3 == 2 )
          goto LABEL_77;
        i = ((LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3) - 3;
        if ( (LODWORD(v29[428].max_tiling) - LODWORD(max_tiling)) >> 3 == 3 )
          break;
LABEL_80:
        max_tiling = v29[428].max_tiling;
LABEL_81:
        if ( LODWORD(max_tiling) != LODWORD(v29[428].max_tiling) && !*(_BYTE *)(LODWORD(max_tiling) + 4) )
          goto LABEL_85;
        p_Usage = &setup_index.m_object->m_desc_3d.Usage;
LABEL_84:
        vostok::buffer_vector<vostok::render::caster_model>::push_back(
          (vostok::buffer_vector<vostok::render::caster_model> *)p_Usage,
          (const vostok::render::caster_model *)v31);
        v29 = setup_index.m_object;
LABEL_85:
        v31 += 2;
        if ( v31 == (float *)v128 )
          goto LABEL_86;
      }
      if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
        goto LABEL_81;
      LODWORD(max_tiling) += 8;
LABEL_77:
      if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
        goto LABEL_81;
      LODWORD(max_tiling) += 8;
LABEL_79:
      if ( v37 == *(_DWORD *)LODWORD(max_tiling) )
        goto LABEL_81;
      goto LABEL_80;
    }
LABEL_87:
    if ( v130 < v132 )
    {
      v128 = (unsigned int)this + (_DWORD)&loc_40C1A + 2;
      v39 = (const vostok::math::float4x4 *)((char *)this + (_DWORD)&loc_406F3 + 5);
      cascade_index = v132 - v130;
      do
      {
        vostok::math::mul4x3(v39 + 4, v39, &v141);
        v40 = (float *)v128;
        v41 = (float *)v128;
        v42 = s_bm_current_air_resistance;
        v43 = s_bm_current_air_resistance
            / (float)((float)((float)((float)(v141.j.w + v141.i.w) * 0.0) + (float)(v141.k.w * 10.0)) + v141.c.w);
        v136 = (float)((float)((float)((float)(v141.j.y + v141.i.y) * 0.0) + (float)(v141.k.y * 10.0)) + v141.c.y) * v43;
        *(float *)&shadow_map_size = (float)((float)((float)((float)(v141.i.x + v141.j.x) * 0.0)
                                                   + (float)(v141.k.x * 10.0))
                                           + v141.c.x)
                                   * v43;
        v137 = (float)((float)((float)((float)(v141.j.z + v141.i.z) * 0.0) + (float)(v141.k.z * 10.0)) + v141.c.z) * v43;
        *(_DWORD *)v128 = shadow_map_size;
        *++v40 = v136;
        v40[1] = v137;
        *v41 = (float)(*v41 + v42) * 0.5;
        v41[1] = 0.5 - (float)(v41[1] * 0.5);
        v39 = v44 + 1;
        v9 = cascade_index-- == 1;
        v128 = (unsigned int)(v41 + 3);
      }
      while ( !v9 );
    }
  }
  v45 = (int)this + (_DWORD)&loc_40BF9 + 3;
  cascade_index = 4;
  do
  {
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_depth_stencil_target(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::render_target **)v45);
    vostok::render::backend::clear_depth_stencil(v47, z_low, 1u, *(float *)&v124, (unsigned __int8)v125);
    v45 += 4;
    --cascade_index;
  }
  while ( cascade_index );
  if ( wszName[1] )
  {
    if ( v130 < v132 )
    {
      m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)v130;
      p_m_end = &this->m_caster_models[0].m_end;
      do
      {
        v45 = (char *)*p_m_end - (char *)*(p_m_end - 1);
        if ( ((v45 ^ ((char *)p_m_end[16396] - (char *)p_m_end[16395])) & 0xFFFFFFF8) != 0 )
          break;
        p_m_end += 4099;
        m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)((char *)m_previous_caster_models
                                                                                             + 1);
      }
      while ( (unsigned int)m_previous_caster_models < v132 );
      if ( v130 < v132 )
      {
        setup_index.m_object = (vostok::render::res_texture *)((char *)this + (_DWORD)&loc_40BF9 + 3);
        v128 = (unsigned int)this + (_DWORD)&loc_40C1F + 1;
        shadow_map_size = v132 - v130;
        do
        {
          pix_event_wrapper_dx11::pix_event_wrapper_dx11(
            (pix_event_wrapper_dx11 *)m_previous_caster_models,
            wszName,
            (int)L"copy_shadow_map");
          v51 = *(_DWORD *)((char *)&loc_40174 + (_DWORD)this);
          v52 = 0;
          *(_DWORD *)(v51 + 22048) = 0;
          v53 = **(_DWORD ***)(v51 + 22052);
          v54 = 0;
          cascade_index = 0;
          if ( v53 )
          {
            v54 = v53;
            ++*v53;
            cascade_index = (unsigned int)v53;
          }
          v131.m_object = (vostok::render::res_pass *)(v54 + 2);
          v55 = *(_DWORD **)v54[2];
          if ( v55 )
          {
            v52 = *(vostok::render::res_pass **)v54[2];
            ++*v55;
          }
          vostok::render::res_pass::apply(v50, (int)v52);
          if ( v52 )
          {
            if ( !--v52->m_reference_count )
              vostok::render::effect_manager::delete_pass(
                v56,
                (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
                v52);
          }
          if ( !--*v54 && *((_BYTE *)v54 + 148) )
          {
            M_left = vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques._M_t._M_header._M_data._M_left;
            p_m_techniques = &vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques;
            while ( M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_techniques )
            {
              if ( *(_DWORD **)&M_left[1]._M_color == v54 )
              {
                v59 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                        M_left,
                        &p_m_techniques->_M_t._M_header._M_data._M_parent,
                        &p_m_techniques->_M_t._M_header._M_data._M_left,
                        &p_m_techniques->_M_t._M_header._M_data._M_right);
                vostok::memory::doug_lea_allocator::free_impl(
                  v60,
                  (int)vostok::render::g_allocator,
                  (char *)&v59->_M_color,
                  v124,
                  v125,
                  LODWORD(v126));
                --p_m_techniques->_M_t._M_node_count;
                v61 = vostok::render::g_allocator;
                vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
                  v62,
                  (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)v131.m_object);
                vostok::memory::doug_lea_allocator::free_impl(
                  v63,
                  (int)v61,
                  (char *)cascade_index,
                  v124,
                  v125,
                  LODWORD(v126));
                break;
              }
              M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
            }
          }
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v127,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(setup_index.m_object->loaded_num_mips + 28));
          v64 = (vostok::render::res_texture *)v127;
          vostok::render::backend::set_ps_texture(
            v65,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            "t_shadow_map",
            (vostok::render::res_texture *)v127);
          if ( v64 )
          {
            if ( !--v64->m_reference_count )
              vostok::render::resource_manager::release(
                v66,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v64);
          }
          *(float *)&v67 = *(float *)(v128 + 44) - *(float *)(v128 - 4);
          *(float *)&v68 = *(float *)(v128 + 48) - *(float *)v128;
          v69 = *(float *)(v128 + 52) - *(float *)(v128 + 4);
          epsilon = (D3D11_VIEWPORT *)&other;
          v122.m_object = *(vostok::render::render_target **)((char *)&loc_4016C + (_DWORD)this);
          *(_QWORD *)&other.x = __PAIR64__(v68, v67);
          other.z = v69;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            (vostok::render::backend *)v66,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)v122.m_object,
            (const vostok::math::float3 *)&other);
          v45 = (int)setup_index.m_object;
          epsilon = 0;
          v122.m_object = v70;
          vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &v122,
            (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)setup_index.m_object);
          vostok::render::system_renderer::fill_surface(
            0,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
            0,
            0,
            0,
            0,
            v122.m_object,
            epsilon,
            *(float *)&v124,
            *(float *)&v125,
            v126,
            *(float *)&v127);
          D3DPERF_EndEvent();
          setup_index.m_object = (vostok::render::res_texture *)((char *)setup_index.m_object + 4);
          v128 += 12;
          --shadow_map_size;
        }
        while ( shadow_map_size );
      }
    }
    goto LABEL_122;
  }
  if ( v130 < v132 )
  {
    v71 = v132 - v130;
    m_previous_caster_models = this->m_previous_caster_models;
    do
    {
      m_previous_caster_models->m_end = m_previous_caster_models->m_begin;
      ++m_previous_caster_models;
      --v71;
    }
    while ( v71 );
LABEL_122:
    if ( wszName[1] )
    {
      v45 = (int)&loc_40C0C + (_DWORD)this;
      cascade_index = 4;
      do
      {
        v72 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        vostok::render::backend::set_depth_stencil_target(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(const vostok::render::render_target **)v45);
        vostok::render::backend::clear_depth_stencil(v73, v72, 1u, *(float *)&v124, (unsigned __int8)v125);
        v45 += 4;
        --cascade_index;
      }
      while ( cascade_index );
    }
  }
  if ( s_render_sun_shadows )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)m_previous_caster_models,
      wszName,
      (int)L"stage_shadow_direct_static");
    vostok::render::stage_shadow_direct::start_depth_accumulation(v74, (int)this, (const D3D11_VIEWPORT *)v45);
    v75 = (vostok::render::stage_shadow_direct *)v130;
    v127 = 0;
    if ( v130 < v132 )
    {
      v128 = (unsigned int)this + (_DWORD)&loc_40BF9 + 3;
      setup_index.m_object = (vostok::render::res_texture *)this->m_caster_models;
      v76 = (float *)((char *)this + (_DWORD)&loc_40C1F + 1);
      shadow_map_size = (unsigned int)this + (_DWORD)&loc_40C1F + 1;
      v131.m_object = (vostok::render::res_pass *)(v132 - v130);
      while ( 1 )
      {
        v9 = *(_BYTE *)&wszName[1] == 0;
        this->m_current_num_dips = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                             + 7428);
        v77 = setup_index.m_object;
        if ( !v9 )
          v77 = (vostok::render::res_texture *)((char *)setup_index.m_object - 131168);
        cascade_index = (unsigned int)v77;
        if ( !*(_BYTE *)&wszName[1] )
          goto LABEL_136;
        v78 = v77->m_reference_count - (unsigned int)v77->__vftable;
        if ( (v78 & 0xFFFFFFF8) != 0 )
          break;
        vostok::render::stage_shadow_direct::end_gather_stats(v78, v127, this);
LABEL_139:
        ++v127;
        v128 += 4;
        setup_index.m_object = (vostok::render::res_texture *)((char *)setup_index.m_object + 16396);
        v76 += 3;
        v9 = v131.m_object-- == (vostok::render::res_pass *)1;
        shadow_map_size = (unsigned int)v76;
        if ( v9 )
          goto LABEL_140;
      }
      v9 = *((_BYTE *)&loc_40C7C + (_DWORD)this + v127) == 0;
      v138.x = v76[11] - *(v76 - 1);
      v138.y = v76[12] - *v76;
      v138.z = v76[13] - v76[1];
      if ( !v9
        || (v45 = (int)&v138,
            memset(&other, 0, sizeof(other)),
            !vostok::math::float3_pod::is_similar(&v138, &other, 0.001))
        || !s_csm_scrolling_debug0 )
      {
LABEL_136:
        vostok::render::backend::set_depth_stencil_target(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(const vostok::render::render_target **)v128);
        vostok::render::stage_shadow_direct::render_models(
          v127,
          v80,
          this,
          (vostok::render::res_pass *)cascade_index,
          *(const vostok::math::float3 **)&wszName[1],
          (bool)v124);
        if ( !*(_BYTE *)&wszName[1] )
        {
          v45 = (int)this;
          vostok::render::stage_shadow_direct::render_grass(this, v127, v79, &viewer_pos);
        }
      }
      vostok::render::stage_shadow_direct::end_gather_stats((int)v79, v127, this);
      v76 = (float *)shadow_map_size;
      goto LABEL_139;
    }
LABEL_140:
    vostok::render::stage_shadow_direct::end_depth_accumulation(v75, (int)this);
    D3DPERF_EndEvent();
  }
  if ( wszName[1] )
  {
    if ( vostok::quasi_singleton<vostok::render::device>::pinst->m_feature_level >= D3D_FEATURE_LEVEL_10_1
      && s_csm_scrolling_debug3 )
    {
      if ( v130 < v132 )
      {
        shadow_map_size = (unsigned int)&loc_40C0C + (_DWORD)this;
        cascade_index = v132 - v130;
        do
        {
          v128 = (unsigned int)vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v131,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(shadow_map_size - 16) + 28));
          setup_index.m_object = (vostok::render::res_texture *)v131.m_object[15].m_input_layout.m_object;
          v45 = *(_DWORD *)shadow_map_size + 28;
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v127,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v45);
          epsilon = (D3D11_VIEWPORT *)setup_index.m_object;
          v81 = (vostok::render::res_texture *)v127;
          (*(void (__stdcall **)(unsigned int, _DWORD, vostok::render::res_texture *))(*(_DWORD *)v128 + 188))(
            v128,
            *(_DWORD *)(v127 + 440),
            setup_index.m_object);
          v9 = v81->m_reference_count-- == 1;
          if ( v9 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)m_previous_caster_models,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v81);
          v82 = (vostok::render::res_texture *)v131.m_object;
          v9 = v131.m_object->m_state.m_object-- == (vostok::render::res_state *)1;
          if ( v9 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)m_previous_caster_models,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v82);
          shadow_map_size += 4;
          --cascade_index;
        }
        while ( cascade_index );
      }
    }
    else if ( v130 < v132 )
    {
      v128 = (unsigned int)&loc_40C0C + (_DWORD)this;
      memset(&v138, 0, sizeof(v138));
      shadow_map_size = v132 - v130;
      do
      {
        pix_event_wrapper_dx11::pix_event_wrapper_dx11(
          (pix_event_wrapper_dx11 *)m_previous_caster_models,
          wszName,
          (int)L"copy_shadow_map");
        v83 = *(_DWORD *)((char *)&loc_40174 + (_DWORD)this);
        v84 = 0;
        *(_DWORD *)(v83 + 22048) = 0;
        v85 = **(_DWORD ***)(v83 + 22052);
        cascade_index = 0;
        if ( v85 )
        {
          v84 = v85;
          ++*v85;
          cascade_index = (unsigned int)v85;
        }
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v131,
          (const vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v84[2]);
        vostok::render::res_pass::apply(v86, (int)v131.m_object);
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v131);
        vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&cascade_index);
        v87 = (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v128;
        texture = vostok::render::render_target::get_texture(
                    *(vostok::render::render_target **)(v128 - 16),
                    &setup_index);
        vostok::render::backend::set_ps_texture(
          v89,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "t_shadow_map",
          texture->m_object);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&setup_index);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v90,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(const vostok::render::shader_constant_host **)((char *)&loc_4016C + (_DWORD)this),
          (const vostok::math::float3 *)&v138);
        epsilon = 0;
        v122.m_object = v91;
        v121.m_object = v91;
        cascade_index = (unsigned int)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v122,
          v87);
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v121,
          0);
        v120.m_object = v92;
        v119.m_object = v92;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v120,
          0);
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v119,
          0);
        v118.m_object = v93;
        v45 = (int)&v118;
        v117 = (vostok::render::system_renderer *)v93;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v118,
          0);
        vostok::render::system_renderer::fill_surface(
          v117,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)cascade_index,
          v118.m_object,
          v119.m_object,
          v120.m_object,
          v121,
          v122.m_object,
          epsilon,
          *(float *)&v124,
          *(float *)&v125,
          v126,
          *(float *)&v127);
        D3DPERF_EndEvent();
        v128 += 4;
        --shadow_map_size;
      }
      while ( shadow_map_size );
    }
    if ( s_render_sun_shadows )
    {
      pix_event_wrapper_dx11::pix_event_wrapper_dx11(
        (pix_event_wrapper_dx11 *)m_previous_caster_models,
        wszName,
        (int)L"stage_shadow_direct_dynamic");
      vostok::render::stage_shadow_direct::start_depth_accumulation(v94, (int)this, (const D3D11_VIEWPORT *)v45);
      v127 = 0;
      if ( v130 < v132 )
      {
        v131.m_object = (vostok::render::res_pass *)(v132 - v130);
        do
        {
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          v97 = v127;
          this->m_current_num_dips = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                               + 7428);
          vostok::render::backend::set_depth_stencil_target(
            (vostok::render::backend *)LODWORD(z),
            *(const vostok::render::render_target **)((char *)&this->__vftable + 4 * v97 + (_DWORD)&loc_40BF9 + 3));
          v98 = v97;
          v99 = (char *)this->m_ready_dynamic_casters[v98].m_end - (char *)this->m_ready_dynamic_casters[v98].m_begin;
          if ( (v99 & 0xFFFFFFF8) != 0 )
            vostok::render::stage_shadow_direct::render_models(
              v127,
              (vostok::render::renderer_context *)v99,
              this,
              (vostok::render::res_pass *)&this->m_ready_dynamic_casters[v98],
              0,
              (bool)v124);
          if ( !v127 )
            vostok::render::stage_shadow_direct::render_grass(
              this,
              0,
              (vostok::render::renderer_context *)v99,
              &viewer_pos);
          vostok::render::stage_shadow_direct::end_gather_stats(v99, v127++, this);
          --v131.m_object;
        }
        while ( v131.m_object );
      }
      vostok::render::stage_shadow_direct::end_depth_accumulation(v95, (int)this);
      D3DPERF_EndEvent();
    }
    vostok::memory::zero((unsigned __int8 *)&loc_40C7C + (_DWORD)this, 4u);
    m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)epsilon;
  }
  v127 = 0;
  if ( v130 < v132 )
  {
    cascade_index = v132 - v130;
    while ( 1 )
    {
      if ( wszName[1] )
      {
        v100 = (char *)this + 12 * v127;
        v101 = &v100[(_DWORD)&loc_40C1A + 2];
        v102 = (_DWORD *)((char *)&loc_40C4C + (_DWORD)v100);
        v103 = v127;
        *v102 = *(_DWORD *)v101;
        v101 += 4;
        *++v102 = *(_DWORD *)v101;
        v102[1] = *((_DWORD *)v101 + 1);
        v104 = (char *)this + 16396 * v103;
        v105 = (vostok::fixed_vector<vostok::render::caster_model,2048> *)*((_DWORD *)v104 + 32830);
        m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)*((_DWORD *)v104 + 32829);
        v104 += 196900;
        v106 = *(vostok::render::caster_model ***)v104;
        *((_DWORD *)v104 + 1) = *(_DWORD *)v104 + 8 * (((char *)v105 - (char *)m_previous_caster_models) >> 3);
        while ( m_previous_caster_models != v105 )
        {
          if ( v106 )
          {
            *v106 = m_previous_caster_models->m_begin;
            v106[1] = m_previous_caster_models->m_end;
          }
          m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)((char *)m_previous_caster_models
                                                                                               + 8);
          v106 += 2;
        }
      }
      v107 = this->m_context;
      v108 = (vostok::render::res_pass *)((char *)this + 64 * v127);
      v131.m_object = v108;
      vostok::render::renderer_context::push_set_v(
        (vostok::render::renderer_context *)m_previous_caster_models,
        (int)v107,
        (const vostok::math::float4x4 *)((char *)v108 + (_DWORD)&loc_406F3 + 5));
      vostok::render::renderer_context::push_set_p(
        v109,
        (int)this->m_context,
        (const vostok::math::float4x4 *)((char *)v108 + (_DWORD)&loc_407F4 + 4));
      v110 = this->m_context;
      qmemcpy(&v141, &v110->m_vp, sizeof(v141));
      vostok::render::renderer_context::pop_v(0, (int)v110);
      vostok::render::renderer_context::pop_p(v111, this->m_context);
      v112 = (char *)&loc_40AF5 + (unsigned int)v131.m_object + 3;
      v131.m_object = (vostok::render::res_pass *)((char *)v131.m_object + (unsigned int)&loc_409F7 + 1);
      qmemcpy(v112, v131.m_object, 0x40u);
      texture_space_transform = vostok::render::stage_shadow_direct::get_texture_space_transform(
                                  0,
                                  (vostok::math::float4x4 *)&v143.m_child_counter);
      vostok::math::mul4x3(texture_space_transform, &v141, (vostok::math::float4x4 *)&v144);
      qmemcpy(v131.m_object, &v144, 0x40u);
      v114 = this->m_context;
      v115 = vostok::math::operator*(
               (const vostok::math::float4x4 *)v131.m_object,
               &v114->m_v_inverted,
               (vostok::math::float4x4 *)&v144);
      if ( !v127 )
      {
        p_m_v2shadow0 = &v114->m_v2shadow0;
        goto LABEL_183;
      }
      if ( v127 == 1 )
      {
        p_m_v2shadow0 = &v114->m_v2shadow1;
        goto LABEL_183;
      }
      if ( v127 == 2 )
        break;
      m_previous_caster_models = (vostok::fixed_vector<vostok::render::caster_model,2048> *)(v127 - 3);
      if ( v127 == 3 )
      {
        p_m_v2shadow0 = &v114->m_v2shadow3;
LABEL_183:
        qmemcpy(p_m_v2shadow0, v115, sizeof(vostok::math::float4x4));
        m_previous_caster_models = 0;
      }
      ++v127;
      if ( !--cascade_index )
        goto LABEL_185;
    }
    p_m_v2shadow0 = &v114->m_v2shadow2;
    goto LABEL_183;
  }
LABEL_185:
  vostok::render::renderer_context::pop_p((vostok::render::renderer_context *)m_previous_caster_models, this->m_context);
}
