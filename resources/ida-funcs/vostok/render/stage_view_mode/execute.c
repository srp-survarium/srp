// bad sp value at call has been detected, the output may be wrong!
void __thiscall vostok::render::stage_view_mode::execute(vostok::render::stage_view_mode *this, unsigned int view_mode)
{
  float v3; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::render::render_target *v5; // eax
  vostok::render::render_target *v6; // eax
  vostok::render::render_target *v7; // ecx
  vostok::render::render_target *m_object; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  vostok::render::render_target *v10; // eax
  vostok::render::render_target *v11; // eax
  unsigned __int8 v12; // al
  vostok::render::backend *v13; // ecx
  int z_low; // eax
  int v15; // edi
  _DWORD *v16; // esi
  bool v17; // zf
  vostok::render::backend *v18; // ecx
  vostok::render::renderer_context *m_context; // eax
  vostok::render::scene *m_scene; // ecx
  int p_m_flags; // eax
  vostok::render::render_surface *v22; // ecx
  float v23; // eax
  vostok::render::render_target *v24; // esi
  vostok::render::material_effects *material_effects; // edi
  int v26; // ecx
  unsigned int v27; // eax
  vostok::render::res_effect *v28; // eax
  vostok::render::material_effects *v29; // ecx
  float z; // esi
  vostok::render::backend *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::render::res_effect *v33; // eax
  vostok::math::sphere *v34; // esi
  double v35; // st7
  int v36; // edi
  vostok::render::backend *v37; // ecx
  vostok::render::backend *v38; // ecx
  vostok::render::render_surface_instance *v39; // ecx
  vostok::math::sphere *bound_sphere; // eax
  unsigned int v41; // eax
  vostok::render::backend *v42; // ecx
  float v43; // esi
  vostok::render::res_effect *v44; // eax
  vostok::render::res_effect *v45; // eax
  vostok::render::res_effect *v46; // eax
  vostok::render::render_target *v47; // esi
  vostok::render::res_geometry *v48; // ecx
  void *m_surface; // edi
  vostok::render::backend *v50; // ecx
  float *v51; // eax
  vostok::render::render_target *v52; // ecx
  float v53; // eax
  unsigned int m_reference_count; // esi
  int v55; // ecx
  int *v56; // esi
  vostok::render::res_geometry *v57; // ecx
  float x; // ecx
  vostok::render::res_pass *v59; // edi
  vostok::render::res_effect *v60; // eax
  vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // eax
  vostok::render::res_effect *v62; // eax
  vostok::render::res_shader_technique *v63; // eax
  vostok::render::res_shader_technique *v64; // esi
  vostok::render::res_pass *v65; // eax
  bool v66; // al
  vostok::memory::doug_lea_allocator *v67; // ecx
  vostok::render::render_target *v68; // ecx
  vostok::render::renderer_context *v69; // eax
  vostok::memory::doug_lea_allocator *v70; // eax
  int y_low; // esi
  int v72; // ecx
  vostok::render::material_effects *v73; // eax
  vostok::render::material_effects *v74; // ecx
  int v75; // esi
  vostok::render::res_effect *v76; // eax
  int v77; // eax
  vostok::render::res_effect *v78; // eax
  vostok::render::backend *v79; // ecx
  vostok::render::material_effects *v80; // eax
  vostok::render::res_effect *v81; // ecx
  int v82; // eax
  vostok::render::res_effect *v83; // eax
  float *p_wszName_1; // eax
  int v85; // esi
  vostok::render::res_effect *v86; // eax
  float v87; // esi
  vostok::render::backend *v88; // ecx
  vostok::render::backend *v89; // ecx
  vostok::render::backend *v90; // ecx
  vostok::render::material_effects *v91; // eax
  vostok::render::res_effect *v92; // ecx
  int v93; // eax
  vostok::render::res_effect *v94; // eax
  int v95; // esi
  int v96; // esi
  vostok::render::renderer_context *v97; // eax
  float v98; // esi
  vostok::render::renderer_context *v99; // eax
  vostok::render::particle_shader_constants *v100; // ecx
  int v101; // esi
  vostok::render::render_particle_emitter_instance *v102; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v103; // eax
  vostok::render::backend *v104; // ecx
  vostok::render::render_target *v105; // ecx
  float v106; // ecx
  float v107; // ecx
  vostok::render::res_effect *v108; // eax
  vostok::render::res_shader_technique *v109; // eax
  vostok::render::res_shader_technique *v110; // ecx
  vostok::render::res_pass *v111; // ecx
  vostok::render::render_target *v112; // ecx
  float v113; // ecx
  float v114; // ecx
  vostok::math::float4x4 *v115; // eax
  int v116; // esi
  vostok::render::backend *v117; // ecx
  vostok::render::backend *v118; // ecx
  float v119; // ecx
  vostok::render::render_target *v120; // ecx
  vostok::math::float3 v121; // [esp-8h] [ebp-310h]
  vostok::math::float3 v122; // [esp+4h] [ebp-304h] BYREF
  vostok::math::float3 screen_size_y; // [esp+10h] [ebp-2F8h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v124; // [esp+1Ch] [ebp-2ECh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v125; // [esp+20h] [ebp-2E8h] BYREF
  vostok::math::float3 v126; // [esp+24h] [ebp-2E4h] BYREF
  float v127; // [esp+30h] [ebp-2D8h]
  vostok::render::render_target *i; // [esp+34h] [ebp-2D4h] BYREF
  vostok::math::float3 viewer_position; // [esp+38h] [ebp-2D0h] BYREF
  vostok::render::render_target *rt; // [esp+44h] [ebp-2C4h] BYREF
  vostok::render::backend *v131; // [esp+48h] [ebp-2C0h] BYREF
  unsigned int out_distance; // [esp+4Ch] [ebp-2BCh] BYREF
  vostok::memory::doug_lea_allocator *tiling; // [esp+50h] [ebp-2B8h] BYREF
  unsigned int v134; // [esp+54h] [ebp-2B4h] BYREF
  vostok::math::float3 v135; // [esp+58h] [ebp-2B0h] BYREF
  int *out_wanted_mip_level_decimals; // [esp+64h] [ebp-2A4h] BYREF
  pix_event_wrapper_dx11 wszName; // [esp+6Bh] [ebp-29Dh] BYREF
  float wszName_1; // [esp+6Ch] [ebp-29Ch] BYREF
  float v139; // [esp+70h] [ebp-298h]
  int v140; // [esp+74h] [ebp-294h]
  int v141; // [esp+78h] [ebp-290h]
  float m_zrt; // [esp+7Ch] [ebp-28Ch] BYREF
  int v143; // [esp+80h] [ebp-288h]
  int v144; // [esp+84h] [ebp-284h]
  int v145; // [esp+88h] [ebp-280h]
  float v146; // [esp+8Ch] [ebp-27Ch] BYREF
  float v147; // [esp+90h] [ebp-278h]
  float v148; // [esp+94h] [ebp-274h]
  unsigned int v149; // [esp+98h] [ebp-270h]
  vostok::render::grass_world max_texture_size_calculated_for; // [esp+9Ch] [ebp-26Ch] BYREF
  char v151; // [esp+2C4h] [ebp-44h] BYREF
  vostok::math::float4x4 v152; // [esp+2C8h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, &wszName, (int)L"stage_view_mode");
  if ( !this->is_effects_ready(this) )
    goto LABEL_153;
  if ( !this->is_enabled(this) )
  {
    this->execute_disabled(this);
    goto LABEL_153;
  }
  *(_QWORD *)&v135.x = __PAIR64__(LODWORD(s_spot_max_distance), LODWORD(FLOAT_25_0));
  if ( view_mode < 2 )
  {
    v126.x = v3;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_position,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v126);
    v125.m_object = v7;
    v124.m_object = v7;
    vostok::render::renderer_context::get_rt(this->m_context, rt_ssao_accumulator_z, &v125);
    vostok::render::renderer::copy(
      (vostok::render::renderer *)v124.m_object,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this->m_renderer,
      v125,
      (vostok::render::res_texture *)LODWORD(v126.x));
    m_object = vostok::render::renderer_context::get_rt(
                 this->m_context,
                 rt_position,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&i)->m_object;
    v9 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_generic_0,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v9->m_object,
      m_object,
      0,
      0);
    v10 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v10->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v11 = i;
    if ( i )
    {
      --i->m_reference_count;
      if ( !v11->m_reference_count )
      {
        v6 = i;
        goto LABEL_14;
      }
    }
  }
  else
  {
    v4 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_present,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v4->m_object,
      0,
      0,
      0);
    v5 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v5->m_reference_count )
      {
        v6 = rt;
LABEL_14:
        vostok::render::resource_manager::release(v6, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
    }
  }
  v12 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
  vostok::render::backend::clear_render_targets(
    v13,
    LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
    v12);
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  v15 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
  v16 = (_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384);
  v17 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v15;
  LODWORD(v126.x) = 3;
  LOBYTE(v18) = !v17;
  *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= !v17;
  *v16 = v15;
  vostok::render::backend::clear_depth_stencil(v18, z_low, LODWORD(v126.x), v126.y, LOBYTE(v126.elements[2]));
  m_context = this->m_context;
  m_scene = m_context->m_scene;
  p_m_flags = (int)&m_context->m_scene_view.m_object[62].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
  LODWORD(viewer_position.z) = *(int *)((char *)&dword_8B9664 + (_DWORD)m_scene);
  v22 = *(vostok::render::render_surface **)p_m_flags;
  v23 = *(float *)(p_m_flags + 4);
  LODWORD(viewer_position.y) = v22;
  for ( v135.z = v23; LODWORD(viewer_position.y) != LODWORD(v135.z); LODWORD(viewer_position.y) += 4 )
  {
    i = *(vostok::render::render_target **)LODWORD(viewer_position.y);
    if ( !vostok::render::render_surface_instance::is_occluded((vostok::render::render_surface_instance *)v22, (int)i) )
    {
      rt = (vostok::render::render_target *)i->m_surface_3d;
      v24 = rt;
      material_effects = vostok::render::render_surface::get_material_effects(v22, (int)rt);
      if ( v24->m_name.m_pointer.m_object )
      {
        v26 = (int)v24[2].m_name.m_pointer.m_object;
        viewer_position.x = 0.0;
        v27 = vostok::render::vertex_input_type_to_index(v26);
        if ( (int)view_mode <= 15 )
        {
          switch ( view_mode )
          {
            case 0xFu:
              v45 = this->m_editor_texture_density_effect[v27].m_object;
              v45->m_cur_technique = 0;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)0xF, (int)v45);
              vostok::render::material_effects::get_max_used_texture_dimension(
                &v134,
                (unsigned int *)&v131,
                material_effects);
              wszName_1 = (float)v134;
              v139 = (float)(unsigned int)v131;
              LODWORD(v126.x) = &wszName_1;
              v125.m_object = (vostok::render::render_target *)this->m_current_max_texture_dimension_parameter;
              v140 = 0;
              v141 = 0;
              goto LABEL_45;
            case 0u:
              v44 = this->m_editor_wireframe_accumulation_effect[v27].m_object;
              goto LABEL_41;
            case 1u:
              v44 = this->m_editor_wireframe_accumulation_effect[v27].m_object;
              v44->m_cur_technique = 1;
              goto LABEL_42;
          }
          if ( view_mode != 9 )
          {
            if ( view_mode == 14 )
            {
              v28 = this->m_editor_shader_complexity_effect[v27].m_object;
              v28->m_cur_technique = 0;
              vostok::render::res_effect::apply_pass(0, (int)v28);
              if ( material_effects->m_effects[1].m_object
                && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
              {
                LODWORD(viewer_position.x) = vostok::render::material_effects::get_render_complexity(
                                               v29,
                                               (int)material_effects);
              }
              z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              viewer_position.x = (float)LODWORD(viewer_position.x);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                (vostok::render::backend *)v29,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                this->m_shader_complexity_parameter,
                &viewer_position);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v31,
                (vostok::render::constants_handler<1> *)LODWORD(z),
                this->m_shader_complexity_min_parameter,
                &v135);
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                v32,
                (vostok::render::constants_handler<1> *)LODWORD(z),
                this->m_shader_complexity_max_parameter,
                (vostok::math::float3 *)&v135.elements[1]);
            }
            goto LABEL_47;
          }
          v33 = this->m_editor_show_miplevel_effect[v27].m_object;
          v33->m_cur_technique = 0;
          vostok::render::res_effect::apply_pass(0, (int)v33);
          vostok::render::material_effects::get_max_used_texture_dimension(
            &v134,
            (unsigned int *)&v131,
            material_effects);
          v34 = (vostok::math::sphere *)i;
          v35 = *(float *)&i->m_surface_3d[38].lpVtbl;
          v36 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
          LODWORD(viewer_position.x) = &this->m_context->m_view_pos;
          LODWORD(v126.x) = &out_wanted_mip_level_decimals;
          v125.m_object = (vostok::render::render_target *)&out_distance;
          tiling = 0;
          out_distance = 0;
          out_wanted_mip_level_decimals = 0;
          screen_size_y.y = v35;
          *(float *)&max_texture_size_calculated_for.__vftable = FLOAT_2048_0;
          *(float *)&max_texture_size_calculated_for.type = FLOAT_2048_0;
          LODWORD(screen_size_y.x) = vostok::render::backend::target_height(
                                       v37,
                                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
          LODWORD(v122.z) = vostok::render::backend::target_width(v38, v36);
          LODWORD(v122.y) = v39;
          bound_sphere = vostok::render::render_surface_instance::get_bound_sphere(
                           v39,
                           v34,
                           (vostok::math::sphere *)(&max_texture_size_calculated_for.vostok::resources::resource_flags
                                                  + 1));
          v41 = vostok::render::calculate_wanted_texture_mip_levels(
                  (const vostok::math::float3 *)LODWORD(viewer_position.x),
                  (const vostok::math::float2 *)&max_texture_size_calculated_for,
                  bound_sphere,
                  (const vostok::math::float4x4 *)LODWORD(v122.z),
                  LODWORD(screen_size_y.x),
                  screen_size_y.y,
                  1.0,
                  (float *)&tiling,
                  (float *)&v125.m_object->m_reference_count,
                  (float *)LODWORD(v126.x));
          v42 = v131;
          v146 = (float)v134;
          v147 = (float)(unsigned int)v131;
          LODWORD(viewer_position.x) = v41;
          v148 = (float)v41;
          LODWORD(v126.x) = &v146;
          v125.m_object = (vostok::render::render_target *)this->m_current_max_texture_dimension_parameter;
          v149 = out_distance;
          v43 = *(float *)&v36;
LABEL_46:
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v42,
            (vostok::render::constants_handler<1> *)LODWORD(v43),
            (const vostok::render::shader_constant_host *)v125.m_object,
            (const vostok::math::float3 *)LODWORD(v126.x));
          goto LABEL_47;
        }
        if ( view_mode == 16 )
        {
          v46 = this->m_editor_geometry_complexity_effect[v27].m_object;
          v46->m_cur_technique = 0;
          vostok::render::res_effect::apply_pass(0, (int)v46);
          m_zrt = (float)(unsigned int)v24->m_zrt;
          LODWORD(v126.x) = &m_zrt;
          v125.m_object = (vostok::render::render_target *)this->m_geometry_complexity_parameters;
          v143 = 0;
          v144 = 0;
          v145 = 0;
LABEL_45:
          v43 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          goto LABEL_46;
        }
        if ( view_mode == 21 )
        {
          v44 = this->m_editor_accumulate_overdraw_effect[v27].m_object;
LABEL_41:
          v44->m_cur_technique = 0;
LABEL_42:
          vostok::render::res_effect::apply_pass(0, (int)v44);
LABEL_47:
          v47 = i;
          vostok::render::renderer_context::set_w((const vostok::math::float4x4 *)i->m_height, this->m_context);
          ((void (__thiscall *)(ID3D11RenderTargetView *, _DWORD))v47->m_rt->lpVtbl[1].GetDesc)(v47->m_rt, 0);
          if ( view_mode == 24 )
            m_surface = rt->m_surface;
          else
            m_surface = rt->m_name.m_pointer.m_object;
          vostok::render::res_geometry::apply(v48, (int)m_surface);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            3 * (int)rt->m_zrt,
            v50,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
          continue;
        }
        v22 = (vostok::render::render_surface *)(view_mode - 23);
        if ( view_mode == 23 )
        {
          if ( v27 == 2 )
          {
            v44 = this->m_editor_vertex_alpha_effect.m_object;
            goto LABEL_41;
          }
        }
        else
        {
          v22 = (vostok::render::render_surface *)(view_mode - 24);
          if ( view_mode != 24 )
            goto LABEL_47;
          if ( v27 == 1 && v24->m_surface )
          {
            v44 = this->m_editor_show_geometry_effect.m_object;
            goto LABEL_41;
          }
        }
      }
    }
  }
  v51 = (float *)((char *)&vostok::memory::s_resources.m_buffer[7260] + (unsigned int)this->m_context->m_scene);
  v52 = *(vostok::render::render_target **)v51;
  v53 = v51[1];
  i = v52;
  viewer_position.x = v53;
  if ( v52 != (vostok::render::render_target *)LODWORD(v53) )
  {
    while ( 1 )
    {
      m_reference_count = i->m_reference_count;
      v55 = *(_DWORD *)(i->m_reference_count + 328);
      *(&max_texture_size_calculated_for.m_reconstruction_size + 1) = (unsigned int)&max_texture_size_calculated_for.m_children_resources.vostok::threading::simple_lock;
      max_texture_size_calculated_for.m_uid = (unsigned int)&max_texture_size_calculated_for.m_children_resources.vostok::threading::simple_lock;
      max_texture_size_calculated_for.m_children_resources.m_size = (unsigned int)&v151;
      (*(void (__thiscall **)(int, _DWORD, _DWORD, unsigned int *, int, _DWORD, int))(*(_DWORD *)v55 + 76))(
        v55,
        0,
        0,
        &max_texture_size_calculated_for.m_reconstruction_size + 1,
        1,
        0,
        3);
      viewer_position.y = *((float *)&max_texture_size_calculated_for.m_reconstruction_size + 1);
      out_distance = max_texture_size_calculated_for.m_uid;
      if ( *(&max_texture_size_calculated_for.m_reconstruction_size + 1) != max_texture_size_calculated_for.m_uid )
        break;
LABEL_71:
      i = (vostok::render::render_target *)((char *)i + 4);
      if ( i == (vostok::render::render_target *)LODWORD(viewer_position.x) )
        goto LABEL_72;
    }
    LODWORD(v135.z) = m_reference_count + 264;
    while ( 1 )
    {
      v56 = *(int **)(*(_DWORD *)LODWORD(viewer_position.y) + 16);
      LODWORD(v126.x) = this->m_context;
      out_wanted_mip_level_decimals = ++v56;
      vostok::render::renderer_context::set_w(
        (const vostok::math::float4x4 *)LODWORD(v135.z),
        (vostok::render::renderer_context *)LODWORD(v126.x));
      vostok::render::res_geometry::apply(v57, *v56);
      v59 = 0;
      if ( !view_mode )
        break;
      if ( view_mode == 1 )
      {
        v60 = this->m_editor_wireframe_accumulation_effect[1].m_object;
        v60->m_cur_technique = 1;
        m_begin = v60->m_techniques.m_begin + 1;
LABEL_59:
        v63 = m_begin->m_object;
        v64 = 0;
        if ( v63 )
        {
          v64 = v63;
          ++v63->m_reference_count;
        }
        v65 = v64->m_passes.m_begin->m_object;
        if ( v65 )
        {
          v59 = v64->m_passes.m_begin->m_object;
          ++v65->m_reference_count;
        }
        vostok::render::res_pass::apply((vostok::render::res_pass *)LODWORD(x), (int)v59);
        if ( v59 )
        {
          v17 = v59->m_reference_count-- == 1;
          if ( v17 )
            vostok::render::effect_manager::delete_pass(
              (vostok::render::effect_manager *)LODWORD(x),
              (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
              v59);
        }
        v17 = v64->m_reference_count-- == 1;
        if ( v17 && v64->m_registered )
        {
          v66 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
                  (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)&vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_techniques,
                  (const vostok::render::res_pass *)v64);
          x = v126.x;
          if ( v66 )
          {
            tiling = vostok::render::g_allocator;
            vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
              (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)LODWORD(v126.x),
              &v64->m_passes.m_begin);
            vostok::memory::doug_lea_allocator::free_impl(
              v67,
              (int)tiling,
              (char *)v64,
              (const char *const)LODWORD(v126.y),
              (const char *const)LODWORD(v126.z),
              LODWORD(v127));
          }
        }
      }
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        3 * out_wanted_mip_level_decimals[5],
        (vostok::render::backend *)LODWORD(x),
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
      LODWORD(viewer_position.y) += 4;
      if ( LODWORD(viewer_position.y) == out_distance )
        goto LABEL_71;
    }
    v62 = this->m_editor_wireframe_accumulation_effect[1].m_object;
    v62->m_cur_technique = 0;
    m_begin = v62->m_techniques.m_begin;
    goto LABEL_59;
  }
LABEL_72:
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&viewer_position,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_8B9668 + (unsigned int)this->m_context->m_scene));
  if ( !LODWORD(viewer_position.x)
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    goto LABEL_82;
  }
  v69 = this->m_context;
  max_texture_size_calculated_for.vostok::vfs::vfs_association = *(vostok::vfs::vfs_association *)&v69->m_v_inverted.lines[3].x;
  max_texture_size_calculated_for.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = LODWORD(v69->m_v_inverted.c.z);
  if ( !view_mode )
  {
    v126.x = 0.0;
    v125.m_object = (vostok::render::render_target *)this->m_editor_wireframe_accumulation_effect[11].m_object;
    goto LABEL_80;
  }
  if ( view_mode == 1 )
  {
    v126.x = 0.0;
    v125.m_object = (vostok::render::render_target *)this->m_editor_wireframe_accumulation_effect[11].m_object;
    *(float *)&v124.m_object = 1000000.0;
    LODWORD(screen_size_y.z) = 1;
LABEL_81:
    vostok::render::grass_world::render(
      &max_texture_size_calculated_for,
      (vostok::render::scene *)LODWORD(viewer_position.x),
      (vostok::math::float3 *)v69,
      (vostok::render::enum_render_stage_type)&max_texture_size_calculated_for,
      0x1Du,
      (vostok::render::res_effect *)LODWORD(screen_size_y.z),
      (vostok::render::res_effect *)v124.m_object,
      (vostok::render::res_effect *)v125.m_object,
      (vostok::render::grass_patch *const)LODWORD(v126.x),
      LODWORD(v126.y));
    goto LABEL_82;
  }
  v68 = (vostok::render::render_target *)(view_mode - 21);
  if ( view_mode == 21 )
  {
    v126.x = 0.0;
    v125.m_object = (vostok::render::render_target *)this->m_editor_accumulate_overdraw_effect[11].m_object;
LABEL_80:
    *(float *)&v124.m_object = 1000000.0;
    screen_size_y.z = 0.0;
    goto LABEL_81;
  }
LABEL_82:
  if ( LODWORD(viewer_position.z) )
  {
    v70 = (vostok::memory::doug_lea_allocator *)&this->m_context->m_scene_view.m_object[202].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    v68 = (vostok::render::render_target *)v70->__vftable;
    tiling = v70;
    for ( i = v68; ; v68 = i )
    {
      if ( v68 == v70->m_arena_start )
        goto LABEL_142;
      LODWORD(viewer_position.y) = i->m_reference_count;
      v135.z = **(float **)(LODWORD(viewer_position.y) + 340);
      if ( LODWORD(v135.z) )
        break;
LABEL_140:
      i = (vostok::render::render_target *)((char *)i + 4);
      v70 = tiling;
    }
    y_low = LODWORD(viewer_position.y);
    out_distance = 0;
    if ( vostok::render::render_particle_emitter_instance::get_material_effects(
           (vostok::render::render_particle_emitter_instance *)v68,
           SLODWORD(viewer_position.y))->m_effects[16].m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v73 = vostok::render::render_particle_emitter_instance::get_material_effects(
              (vostok::render::render_particle_emitter_instance *)v72,
              y_low);
      out_distance = vostok::render::material_effects::get_render_complexity(v74, (int)v73);
    }
    switch ( view_mode )
    {
      case 0u:
        v96 = *(_DWORD *)(y_low + 364);
        if ( v96 )
        {
          if ( v96 == 1 )
            v76 = this->m_editor_wireframe_accumulation_effect[8].m_object;
          else
            v76 = this->m_editor_wireframe_accumulation_effect[9].m_object;
        }
        else
        {
          v76 = this->m_editor_wireframe_accumulation_effect[7].m_object;
        }
LABEL_137:
        v76->m_cur_technique = 0;
LABEL_138:
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v72, (int)v76);
        goto LABEL_139;
      case 1u:
        v95 = *(_DWORD *)(y_low + 364);
        if ( v95 )
        {
          v72 = 1;
          if ( v95 == 1 )
            v76 = this->m_editor_wireframe_accumulation_effect[8].m_object;
          else
            v76 = this->m_editor_wireframe_accumulation_effect[9].m_object;
          v76->m_cur_technique = 1;
        }
        else
        {
          v76 = this->m_editor_wireframe_accumulation_effect[7].m_object;
          v76->m_cur_technique = 1;
        }
        goto LABEL_138;
      case 9u:
        v91 = vostok::render::render_particle_emitter_instance::get_material_effects(
                (vostok::render::render_particle_emitter_instance *)v72,
                SLODWORD(viewer_position.y));
        vostok::render::material_effects::get_max_used_texture_dimension(&v134, (unsigned int *)&v131, v91);
        v93 = *(_DWORD *)(LODWORD(viewer_position.y) + 364);
        if ( v93 )
        {
          if ( v93 == 1 )
            v94 = this->m_editor_show_miplevel_effect[8].m_object;
          else
            v94 = this->m_editor_show_miplevel_effect[9].m_object;
        }
        else
        {
          v94 = this->m_editor_show_miplevel_effect[7].m_object;
        }
        v94->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v92, (int)v94);
        v146 = (float)v134;
        v147 = (float)(unsigned int)v131;
        v148 = 0.0;
        v149 = 0;
        p_wszName_1 = &v146;
        break;
      case 0xEu:
        v85 = *(_DWORD *)(y_low + 364);
        if ( v85 )
        {
          if ( v85 == 1 )
            v86 = this->m_editor_shader_complexity_effect[8].m_object;
          else
            v86 = this->m_editor_shader_complexity_effect[9].m_object;
        }
        else
        {
          v86 = this->m_editor_shader_complexity_effect[7].m_object;
        }
        v86->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v72, (int)v86);
        v87 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        viewer_position.z = (float)out_distance;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v88,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          this->m_shader_complexity_parameter,
          (vostok::math::float3 *)&viewer_position.elements[2]);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v89,
          (vostok::render::constants_handler<1> *)LODWORD(v87),
          this->m_shader_complexity_min_parameter,
          &v135);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v90,
          (vostok::render::constants_handler<1> *)LODWORD(v87),
          this->m_shader_complexity_max_parameter,
          (vostok::math::float3 *)&v135.elements[1]);
        goto LABEL_139;
      case 0xFu:
        v80 = vostok::render::render_particle_emitter_instance::get_material_effects(
                (vostok::render::render_particle_emitter_instance *)v72,
                SLODWORD(viewer_position.y));
        vostok::render::material_effects::get_max_used_texture_dimension(&v134, (unsigned int *)&v131, v80);
        v82 = *(_DWORD *)(LODWORD(viewer_position.y) + 364);
        if ( v82 )
        {
          if ( v82 == 1 )
            v83 = this->m_editor_texture_density_effect[8].m_object;
          else
            v83 = this->m_editor_texture_density_effect[9].m_object;
        }
        else
        {
          v83 = this->m_editor_texture_density_effect[7].m_object;
        }
        v83->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v81, (int)v83);
        wszName_1 = (float)v134;
        v139 = (float)(unsigned int)v131;
        v140 = 0;
        v141 = 0;
        p_wszName_1 = &wszName_1;
        break;
      case 0x10u:
        v77 = *(_DWORD *)(y_low + 364);
        if ( v77 )
        {
          if ( v77 == 1 )
            v78 = this->m_editor_geometry_complexity_effect[8].m_object;
          else
            v78 = this->m_editor_geometry_complexity_effect[9].m_object;
        }
        else
        {
          v78 = this->m_editor_geometry_complexity_effect[7].m_object;
        }
        v78->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v72, (int)v78);
        LODWORD(viewer_position.z) = 2 * **(_DWORD **)(y_low + 340);
        m_zrt = (float)LODWORD(viewer_position.z);
        LODWORD(v126.x) = &m_zrt;
        v125.m_object = (vostok::render::render_target *)this->m_geometry_complexity_parameters;
        v143 = 0;
        v144 = 0;
        v145 = 0;
LABEL_106:
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v79,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v125.m_object,
          (const vostok::math::float3 *)LODWORD(v126.x));
LABEL_139:
        v126.x = *(float *)(LODWORD(viewer_position.y) + 372);
        v97 = this->m_context;
        v125.m_object = *(vostok::render::render_target **)(LODWORD(viewer_position.y) + 368);
        *(_QWORD *)&screen_size_y.elements[1] = *(_QWORD *)&v97->m_view_pos.x;
        v124.m_object = (vostok::render::render_target *)LODWORD(v97->m_view_pos.elements[2]);
        *(_QWORD *)&v122.elements[1] = *(_QWORD *)&v97->m_camera_right_vector.x;
        screen_size_y.x = v97->m_camera_right_vector.z;
        *(_QWORD *)&v121.elements[1] = *(_QWORD *)&v97->m_camera_up_vector.x;
        v122.x = v97->m_camera_up_vector.z;
        v98 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
        v121.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
        vostok::render::particle_shader_constants::set(
          (vostok::render::particle_shader_constants *)v97,
          v121,
          v122,
          screen_size_y,
          (vostok::particle::enum_particle_locked_axis)v124.m_object,
          (vostok::particle::enum_particle_screen_alignment)v125.m_object,
          SLODWORD(v126.x));
        v99 = this->m_context;
        LODWORD(v126.x) = v100;
        v126.x = v99->m_current_time;
        vostok::render::particle_shader_constants::set_time(v100, v98, v126);
        v101 = LODWORD(viewer_position.y);
        vostok::render::renderer_context::set_w(
          (const vostok::math::float4x4 *)(LODWORD(viewer_position.y) + 184),
          this->m_context);
        vostok::render::render_particle_emitter_instance::render(
          v102,
          (int)this,
          (int)&v122.y,
          v101,
          (vostok::math::float3 *)v101,
          (const unsigned int)this->m_context,
          LODWORD(v135.z));
        goto LABEL_140;
      case 0x15u:
        v75 = *(_DWORD *)(y_low + 364);
        if ( v75 )
        {
          if ( v75 == 1 )
            v76 = this->m_editor_accumulate_overdraw_effect[8].m_object;
          else
            v76 = this->m_editor_accumulate_overdraw_effect[9].m_object;
        }
        else
        {
          v76 = this->m_editor_accumulate_overdraw_effect[7].m_object;
        }
        goto LABEL_137;
      default:
        goto LABEL_140;
    }
    LODWORD(v126.x) = p_wszName_1;
    v125.m_object = (vostok::render::render_target *)this->m_current_max_texture_dimension_parameter;
    goto LABEL_106;
  }
LABEL_142:
  if ( view_mode < 2 )
  {
    v108 = this->m_editor_apply_wireframe_shader.m_object;
    v108->m_cur_technique = 0;
    v109 = v108->m_techniques.m_begin->m_object;
    v110 = 0;
    v135.x = 0.0;
    if ( v109 )
    {
      v110 = v109;
      ++v109->m_reference_count;
      LODWORD(v135.x) = v109;
    }
    vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v135.elements[1],
      v110->m_passes.m_begin);
    vostok::render::res_pass::apply(v111, SLODWORD(v135.y));
    vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v135.elements[1]);
    vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v135);
    v126.x = 0.0;
    v125.m_object = v112;
    v124.m_object = v112;
    LODWORD(viewer_position.z) = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &v125,
      0);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &v124,
      0);
    screen_size_y.z = v113;
    screen_size_y.y = v113;
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y.elements[2],
      0);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y.elements[1],
      0);
    screen_size_y.x = v114;
    v122.z = v114;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_present,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y);
    vostok::render::system_renderer::fill_surface(
      (vostok::render::system_renderer *)LODWORD(v122.z),
      LODWORD(viewer_position.elements[2]),
      (vostok::render::render_target *)LODWORD(screen_size_y.x),
      (vostok::render::render_target *)LODWORD(screen_size_y.y),
      (vostok::render::render_target *)LODWORD(screen_size_y.z),
      v124,
      v125.m_object,
      (D3D11_VIEWPORT *)LODWORD(v126.x),
      v126.y,
      v126.z,
      v127,
      *(float *)&i);
  }
  else if ( view_mode == 21 )
  {
    v103 = vostok::render::renderer_context::get_rt(
             this->m_context,
             rt_present,
             (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&viewer_position.elements[2]);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v103->m_object,
      0,
      0,
      0);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&viewer_position.elements[2]);
    vostok::render::backend::clear_render_targets(
      v104,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      0,
      0.25,
      0.0,
      0.0);
    for ( i = (vostok::render::render_target *)1;
          (unsigned int)i < 0x20;
          i = (vostok::render::render_target *)((char *)i + 1) )
    {
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)i,
        (int)this->m_editor_show_overdraw_shader.m_object);
      LODWORD(v126.x) = 1;
      v125.m_object = v105;
      v124.m_object = v105;
      LODWORD(viewer_position.z) = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &v125,
        0);
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &v124,
        0);
      screen_size_y.z = v106;
      screen_size_y.y = v106;
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y.elements[2],
        0);
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y.elements[1],
        0);
      screen_size_y.x = v107;
      v122.z = v107;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&screen_size_y);
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)LODWORD(v122.z),
        LODWORD(viewer_position.elements[2]),
        (vostok::render::render_target *)LODWORD(screen_size_y.x),
        (vostok::render::render_target *)LODWORD(screen_size_y.y),
        (vostok::render::render_target *)LODWORD(screen_size_y.z),
        v124,
        v125.m_object,
        (D3D11_VIEWPORT *)LODWORD(v126.x),
        v126.y,
        v126.z,
        v127,
        *(float *)&i);
    }
  }
  v115 = vostok::math::float4x4::identity((vostok::math::float4x4 *)v68, &v152);
  vostok::render::renderer_context::set_w(v115, this->m_context);
  v116 = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::reset_depth_stencil_target(
    v117,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  vostok::render::backend::reset_render_targets(v118, v116);
  if ( view_mode <= 1 )
  {
    v126.x = v119;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_ssao_accumulator_z,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v126);
    v125.m_object = v120;
    v124.m_object = v120;
    vostok::render::renderer_context::get_rt(this->m_context, rt_position, &v125);
    vostok::render::renderer::copy(
      (vostok::render::renderer *)v124.m_object,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this->m_renderer,
      v125,
      (vostok::render::res_texture *)LODWORD(v126.x));
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&viewer_position);
LABEL_153:
  D3DPERF_EndEvent();
}
