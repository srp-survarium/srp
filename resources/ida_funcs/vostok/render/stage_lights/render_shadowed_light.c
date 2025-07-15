void __userpurge vostok::render::stage_lights::render_shadowed_light(
        vostok::render::stage_lights *this@<ecx>,
        float a2@<ebp>,
        float a3@<edi>,
        float a4@<esi>,
        vostok::render::stage_lights *l,
        vostok::render::light *la)
{
  float range; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  vostok::render::renderer_context *m_context; // eax
  float v10; // xmm3_4
  float v11; // xmm4_4
  float z; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // eax
  bool v17; // cl
  unsigned int v18; // xmm4_4
  float v19; // xmm1_4
  unsigned int v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  unsigned int v23; // esi
  vostok::render::backend *v24; // ecx
  unsigned int shadow_map_size_index; // eax
  unsigned int v26; // edi
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v28; // esi
  vostok::render::render_target *v29; // eax
  char *v30; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  const char *m_conflicted_key_name; // edi
  ID3D11RenderTargetView *v33; // eax
  int v34; // eax
  bool v35; // zf
  float v36; // eax
  unsigned int v37; // esi
  bool v38; // al
  unsigned int v39; // ecx
  int v40; // eax
  float v41; // eax
  const char *v42; // esi
  vostok::render::constants_handler<1> *v43; // edi
  const vostok::math::float3 *v44; // eax
  float v45; // eax
  vostok::render::backend *v46; // esi
  vostok::render::constants_handler<1> *v47; // edi
  float v48; // eax
  const char *v49; // esi
  vostok::render::constants_handler<1> *v50; // edi
  const vostok::math::float3 *v51; // eax
  float v52; // eax
  vostok::render::backend *v53; // ebx
  vostok::render::constants_handler<1> *v54; // esi
  float v55; // eax
  float v56; // eax
  const char *v57; // esi
  int v58; // ecx
  const char *v59; // eax
  float v60; // ecx
  int v61; // edx
  float v62; // eax
  int v63; // ecx
  float v64; // eax
  int v65; // ecx
  float v66; // eax
  float v67; // eax
  vostok::render::backend *v68; // esi
  int v69; // ecx
  float v70; // eax
  int v71; // ecx
  const char *v72; // edi
  float v73; // eax
  int v74; // ecx
  float v75; // eax
  int v76; // ecx
  float v77; // eax
  int v78; // ecx
  unsigned int m_c_is_shadower; // eax
  int v80; // ecx
  float v81; // eax
  int v82; // ecx
  float v83; // eax
  int v84; // ecx
  float v85; // eax
  int v86; // ecx
  float v87; // [esp+10h] [ebp-234h]
  const vostok::math::float4x4 *v88; // [esp+10h] [ebp-234h]
  float v89; // [esp+14h] [ebp-230h]
  unsigned int v90; // [esp+14h] [ebp-230h]
  float v91; // [esp+18h] [ebp-22Ch]
  bool distribute_shadow; // [esp+27h] [ebp-21Dh]
  float tech_indexa; // [esp+28h] [ebp-21Ch]
  unsigned int tech_index; // [esp+28h] [ebp-21Ch]
  vostok::render::res_geometry *geometry; // [esp+30h] [ebp-214h]
  float light_range; // [esp+34h] [ebp-210h] BYREF
  unsigned int face_index; // [esp+38h] [ebp-20Ch]
  int src_ptr; // [esp+3Ch] [ebp-208h] BYREF
  float v99; // [esp+40h] [ebp-204h]
  float v100; // [esp+44h] [ebp-200h]
  float range_X_tan_penumbra_angle_div_2; // [esp+48h] [ebp-1FCh]
  vostok::math::float3 light_position; // [esp+4Ch] [ebp-1F8h] BYREF
  float v103; // [esp+58h] [ebp-1ECh]
  vostok::math::float3 light_color; // [esp+5Ch] [ebp-1E8h] BYREF
  vostok::math::float3 view; // [esp+68h] [ebp-1DCh] BYREF
  vostok::math::float3 from; // [esp+74h] [ebp-1D0h] BYREF
  vostok::math::float4x4 scale_matrix; // [esp+80h] [ebp-1C4h] BYREF
  vostok::math::float4x4 local_to_world; // [esp+C0h] [ebp-184h] BYREF
  vostok::math::float4x4 face_projection_matrix; // [esp+100h] [ebp-144h] BYREF
  vostok::math::float4x4 face_view_matrix; // [esp+140h] [ebp-104h] BYREF
  vostok::math::float4x4 obb_world; // [esp+180h] [ebp-C4h] BYREF
  vostok::math::float4x4 result; // [esp+1C0h] [ebp-84h] BYREF
  vostok::math::float4x4 v113; // [esp+200h] [ebp-44h] BYREF

  range = la->range;
  y = la->position.y;
  x = la->position.x;
  v91 = a2;
  light_color.z = la->color.z;
  m_context = l->m_context;
  v10 = m_context->m_v.j.x;
  v11 = m_context->m_v.k.x;
  m_context = (vostok::render::renderer_context *)((char *)m_context + 15620);
  light_range = range;
  *(_QWORD *)&light_color.x = *(_QWORD *)&la->color.x;
  z = la->position.z;
  v13 = (float)((float)((float)(v10 * y) + (float)(v11 * z)) + (float)(x * *(float *)&m_context->m_targets))
      + *(float *)&m_context->m_family[0].orig_name.m_buffer[32];
  v14 = *(float *)&m_context->m_family[0].orig_name.m_buffer[4];
  light_position.x = v13;
  light_position.y = (float)((float)((float)(*(float *)&m_context->m_family[0].orig_name.m_begin * x) + (float)(v14 * y))
                           + (float)(*(float *)&m_context->m_family[0].orig_name.m_buffer[20] * z))
                   + *(float *)&m_context->m_family[0].orig_name.m_buffer[36];
  v15 = (float)((float)((float)(*(float *)&m_context->m_family[0].orig_name.m_end * x)
                      + (float)(*(float *)&m_context->m_family[0].orig_name.m_buffer[8] * y))
              + (float)(*(float *)&m_context->m_family[0].orig_name.m_buffer[24] * z))
      + *(float *)&m_context->m_family[0].orig_name.m_buffer[40];
  v16 = *(float *)&l->m_pyramid_geometry.geometry.m_object;
  v89 = a4;
  v87 = a3;
  light_position.z = v15;
  geometry = 0;
  if ( v16 != 0.0 )
  {
    ++*(_DWORD *)LODWORD(v16);
    geometry = (vostok::render::res_geometry *)LODWORD(v16);
  }
  face_index = 0;
  range_X_tan_penumbra_angle_div_2 = tanf(0.78539819) * light_range;
  do
  {
    v17 = la->shadow_distribution_sides[face_index];
    *(float *)&v18 = *(float *)&dword_A576AC[9 * face_index] + la->position.y;
    v19 = *(float *)&dword_A576B8[9 * face_index] + la->position.y;
    *(float *)&v20 = *(float *)&dword_A576B0[9 * face_index] + la->position.z;
    v21 = *(float *)&dword_A576BC[9 * face_index] + la->position.z;
    v22 = (float)(la->position.x + *(float *)&dword_A576B4[9 * face_index])
        - (float)(la->position.x + view_matrix_parameters[face_index][0].x);
    v23 = 36 * face_index;
    from.x = la->position.x + view_matrix_parameters[face_index][0].x;
    v99 = v22;
    distribute_shadow = v17;
    *(_QWORD *)&from.elements[1] = __PAIR64__(v20, v18);
    v100 = v19 - *(float *)&v18;
    v103 = v21 - *(float *)&v20;
    tech_indexa = sqrtf((float)((float)(v22 * v22) + (float)(v100 * v100)) + (float)(v103 * v103));
    view.x = (float)(*(float *)&clear_value / tech_indexa) * v99;
    view.y = (float)(*(float *)&clear_value / tech_indexa) * v100;
    view.z = (float)(*(float *)&clear_value / tech_indexa) * v103;
    vostok::math::create_camera_direction(&from, &view, (const vostok::math::float3 *)((char *)&unk_A576C0 + v23));
    memset((int)&scale_matrix, 0, sizeof(scale_matrix));
    scale_matrix.i.x = range_X_tan_penumbra_angle_div_2;
    scale_matrix.j.y = range_X_tan_penumbra_angle_div_2;
    qmemcpy((void *)&local_to_world, &face_view_matrix, sizeof(local_to_world));
    scale_matrix.k.z = light_range;
    LODWORD(scale_matrix.c.w) = clear_value;
    vostok::math::float4x4::try_invert(&local_to_world, &local_to_world);
    vostok::math::mul4x3(&face_projection_matrix, &scale_matrix, &local_to_world);
    qmemcpy((void *)&local_to_world, &face_projection_matrix, sizeof(local_to_world));
    if ( distribute_shadow )
    {
      vostok::math::create_perspective_projection(
        COERCE_VOSTOK_MATH_(1.0),
        (struct vostok::math::float4x4 *)LODWORD(s_shadow_z_near_value),
        light_range,
        v87,
        v89,
        v91);
      shadow_map_size_index = la->shadow_map_size_index;
      if ( shadow_map_size_index )
      {
        if ( shadow_map_size_index == 1 )
          v26 = 512;
        else
          v26 = 256;
      }
      else
      {
        v26 = 1024;
      }
      vostok::render::backend::flush_rt_shader_resources(
        v24,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::stage_lights::render_to_hw_shadowmap(
        v26,
        (vostok::render::backend *)&face_view_matrix,
        l,
        la,
        la->shadow_z_bias,
        *(float *)&la->shadow_map_size_index,
        &face_view_matrix,
        (vostok::render::renderer_context *)&face_projection_matrix,
        v88,
        v90);
    }
    vostok::render::renderer_context::set_w(l->m_context, &local_to_world);
    m_object = l->m_context->m_targets->m_family[28].target.m_object;
    v28 = 0;
    if ( m_object )
    {
      v28 = l->m_context->m_targets->m_family[28].target.m_object;
      ++m_object->m_reference_count;
    }
    v29 = l->m_context->m_targets->m_family[26].target.m_object;
    v30 = 0;
    if ( v29 )
    {
      v30 = (char *)l->m_context->m_targets->m_family[26].target.m_object;
      ++v29->m_reference_count;
      m_rt = v29->m_rt;
    }
    else
    {
      m_rt = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( v28 )
      v33 = v28->m_rt;
    else
      v33 = 0;
    if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 536) != v33 )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = v33;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    if ( v30 )
    {
      if ( !--*(_DWORD *)v30 )
      {
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v30);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    if ( v28 )
    {
      if ( !--v28->m_reference_count )
      {
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v30,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v28);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v34 = *((_DWORD *)m_conflicted_key_name + 547);
    v35 = *((_DWORD *)m_conflicted_key_name + 539) == v34;
    *((_DWORD *)m_conflicted_key_name + 539) = v34;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v35;
    v36 = *(float *)&l->m_effect_accum_mask.m_object;
    if ( (*(_DWORD *)(LODWORD(v36) + 284) - *(_DWORD *)(LODWORD(v36) + 280)) >> 2 )
    {
      *(_DWORD *)(LODWORD(v36) + 276) = 0;
      LOBYTE(v30) = !v35;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v30, LODWORD(v87));
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    vostok::render::res_geometry::apply(geometry);
    v37 = 18;
    v38 = *((_DWORD *)m_conflicted_key_name + 529) != 4;
    *((_BYTE *)m_conflicted_key_name + 162) = v38;
    if ( v38 )
      *((_DWORD *)m_conflicted_key_name + 529) = 4;
    vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
    if ( m_conflicted_key_name[104] )
    {
      ++*((_DWORD *)m_conflicted_key_name + 25);
      v37 = 3 * s_max_triagles_per_dip_value < 0x12 ? 3 * s_max_triagles_per_dip_value - 18 + 18 : 18;
    }
    if ( !m_conflicted_key_name[37] )
      (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                               + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v37,
        0,
        0);
    *((_DWORD *)m_conflicted_key_name + 21) += v37 / 3;
    v39 = 0;
    v40 = *(_DWORD *)&la->flags & 0xF;
    tech_index = 0;
    if ( v40 )
    {
      if ( v40 == 2 )
      {
        while ( 1 )
        {
          if ( distribute_shadow )
          {
            v48 = *(float *)&l->m_shadowed_obb_light_accumulator.m_object;
            if ( v39 < (*(_DWORD *)(LODWORD(v48) + 284) - *(_DWORD *)(LODWORD(v48) + 280)) >> 2 )
            {
              *(_DWORD *)(LODWORD(v48) + 276) = v39;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
            }
            v49 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            v50 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                         + 1476);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_transparency,
              (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
            + 123,
              (const vostok::math::float3 *)&la->shadow_transparency);
            ++*((_DWORD *)v49 + 23);
            v51 = (const vostok::math::float3 *)vostok::math::transpose(&result, &l->m_view_to_light_matrix);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_view_to_light_matrix,
              v50,
              v51);
            ++*((_DWORD *)v49 + 23);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_z_bias,
              v50,
              (const vostok::math::float3 *)&l->m_shadow_z_bias);
            ++*((_DWORD *)v49 + 23);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_map_size,
              v50,
              (const vostok::math::float3 *)&l->m_shadow_map_size);
            ++*((_DWORD *)v49 + 23);
            *((_BYTE *)v49 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                      (vostok::render::textures_handler<0> *)(v49 + 1488),
                                      (char *)v49 + 1488,
                                      (vostok::render::res_texture *)&stru_9649F4,
                                      l->m_shadow_depth_stencil_texture[la->shadow_map_size_index].m_object);
          }
          else
          {
            v52 = *(float *)&l->m_obb_light_accumulator.m_object;
            if ( v39 < (*(_DWORD *)(LODWORD(v52) + 284) - *(_DWORD *)(LODWORD(v52) + 280)) >> 2 )
            {
              *(_DWORD *)(LODWORD(v52) + 276) = v39;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
            }
          }
          v53 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          v54 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                       + 1476);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_position,
            (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 123,
            &light_position);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_range,
            v54,
            (const vostok::math::float3 *)&light_range);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_attenuation_power,
            v54,
            (const vostok::math::float3 *)&la->attenuation_power);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_diffuse_influence_factor,
            v54,
            (const vostok::math::float3 *)&la->diffuse_influence_factor);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_specular_influence_factor,
            v54,
            (const vostok::math::float3 *)&la->specular_influence_factor);
          ++v53->num_setted_shader_constants;
          qmemcpy((void *)&obb_world, &la->m_xform, sizeof(obb_world));
          vostok::math::float4x4::set_scale(&obb_world, &la->scale);
          vostok::math::mul4x3(&face_projection_matrix, &obb_world, &l->m_context->m_v);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_local_to_world,
            &v53->m_ps_constants_handler,
            (const vostok::math::float3 *)&face_projection_matrix);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_color,
            &v53->m_ps_constants_handler,
            &light_color);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_intensity,
            &v53->m_ps_constants_handler,
            (const vostok::math::float3 *)&la->intensity);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_lighting_model,
            &v53->m_ps_constants_handler,
            (const vostok::math::float3 *)&la->lighting_model);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_eye_ray_corner,
            &v53->m_ps_constants_handler,
            l->m_context->m_eye_rays);
          ++v53->num_setted_shader_constants;
          vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
            l->m_c_near_far,
            &v53->m_vs_constants_handler,
            (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
          ++v53->num_setted_shader_constants;
          vostok::render::res_geometry::apply(geometry);
          vostok::render::backend::render_indexed(v53, 0x12u, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, 0);
          if ( ++tech_index >= 2 )
            break;
          v39 = tech_index;
        }
      }
      else
      {
        while ( 1 )
        {
          if ( distribute_shadow )
          {
            v41 = *(float *)&l->m_shadowed_sphere_light_accumulator.m_object;
            if ( v39 < (*(_DWORD *)(LODWORD(v41) + 284) - *(_DWORD *)(LODWORD(v41) + 280)) >> 2 )
            {
              *(_DWORD *)(LODWORD(v41) + 276) = v39;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
            }
            v42 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            v43 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                         + 1476);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_transparency,
              (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
            + 123,
              (const vostok::math::float3 *)&la->shadow_transparency);
            ++*((_DWORD *)v42 + 23);
            v44 = (const vostok::math::float3 *)vostok::math::transpose(&face_view_matrix, &l->m_view_to_light_matrix);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_view_to_light_matrix,
              v43,
              v44);
            ++*((_DWORD *)v42 + 23);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_z_bias,
              v43,
              (const vostok::math::float3 *)&l->m_shadow_z_bias);
            ++*((_DWORD *)v42 + 23);
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              l->m_c_shadow_map_size,
              v43,
              (const vostok::math::float3 *)&l->m_shadow_map_size);
            ++*((_DWORD *)v42 + 23);
            *((_BYTE *)v42 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                      (vostok::render::textures_handler<0> *)(v42 + 1488),
                                      (char *)v42 + 1488,
                                      (vostok::render::res_texture *)&stru_9649F4,
                                      l->m_shadow_depth_stencil_texture[la->shadow_map_size_index].m_object);
          }
          else
          {
            v45 = *(float *)&l->m_sphere_light_accumulator.m_object;
            if ( v39 < (*(_DWORD *)(LODWORD(v45) + 284) - *(_DWORD *)(LODWORD(v45) + 280)) >> 2 )
            {
              *(_DWORD *)(LODWORD(v45) + 276) = v39;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
            }
          }
          v46 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          v47 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                       + 1476);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_position,
            (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 123,
            &light_position);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_range,
            v47,
            (const vostok::math::float3 *)&light_range);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_attenuation_power,
            v47,
            (const vostok::math::float3 *)&la->attenuation_power);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_diffuse_influence_factor,
            v47,
            (const vostok::math::float3 *)&la->diffuse_influence_factor);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_specular_influence_factor,
            v47,
            (const vostok::math::float3 *)&la->specular_influence_factor);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_sphere_radius,
            v47,
            &la->scale);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_color,
            v47,
            &light_color);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_light_intensity,
            v47,
            (const vostok::math::float3 *)&la->intensity);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_lighting_model,
            v47,
            (const vostok::math::float3 *)&la->lighting_model);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            l->m_c_eye_ray_corner,
            v47,
            l->m_context->m_eye_rays);
          ++v46->num_setted_shader_constants;
          vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
            l->m_c_near_far,
            &v46->m_vs_constants_handler,
            (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
          ++v46->num_setted_shader_constants;
          vostok::render::res_geometry::apply(geometry);
          vostok::render::backend::render_indexed(v46, 0x12u, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, 0);
          if ( ++tech_index >= 2 )
            break;
          v39 = tech_index;
        }
      }
    }
    else
    {
      src_ptr = 0;
      do
      {
        if ( distribute_shadow )
        {
          v55 = *(float *)&l->m_shadowed_point_light_accumulator.m_object;
          if ( v39 < (*(_DWORD *)(LODWORD(v55) + 284) - *(_DWORD *)(LODWORD(v55) + 280)) >> 2 )
          {
            *(_DWORD *)(LODWORD(v55) + 276) = v39;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
          }
          v56 = *(float *)&l->m_c_shadow_transparency;
          v57 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          if ( *(_DWORD *)(LODWORD(v56) + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                 + 573) )
          {
            v58 = *(unsigned __int16 *)(LODWORD(v56) + 20);
            if ( v58 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                *(unsigned __int16 *)(LODWORD(v56) + 22),
                (unsigned __int8)*(_WORD *)(LODWORD(v56) + 16),
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                         + 371)
                                                                       + 16)
                                                           + 4 * v58),
                (const char *)&la->shadow_transparency);
          }
          ++*((_DWORD *)v57 + 23);
          v59 = (const char *)vostok::math::transpose(&v113, &l->m_view_to_light_matrix);
          v60 = *(float *)&l->m_c_view_to_light_matrix;
          if ( *(_DWORD *)(LODWORD(v60) + 40) == *((_DWORD *)v57 + 573) )
          {
            v61 = *(unsigned __int16 *)(LODWORD(v60) + 20);
            if ( v61 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                *(unsigned __int16 *)(LODWORD(v60) + 22),
                (unsigned __int8)*(_WORD *)(LODWORD(v60) + 16),
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v57 + 371) + 16) + 4 * v61),
                v59);
          }
          ++*((_DWORD *)v57 + 23);
          v62 = *(float *)&l->m_c_shadow_z_bias;
          if ( *(_DWORD *)(LODWORD(v62) + 40) == *((_DWORD *)v57 + 573) )
          {
            v63 = *(unsigned __int16 *)(LODWORD(v62) + 20);
            if ( v63 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                *(unsigned __int16 *)(LODWORD(v62) + 22),
                (unsigned __int8)*(_WORD *)(LODWORD(v62) + 16),
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v57 + 371) + 16) + 4 * v63),
                (const char *)&l->m_shadow_z_bias);
          }
          ++*((_DWORD *)v57 + 23);
          v64 = *(float *)&l->m_c_shadow_map_size;
          if ( *(_DWORD *)(LODWORD(v64) + 40) == *((_DWORD *)v57 + 573) )
          {
            v65 = *(unsigned __int16 *)(LODWORD(v64) + 20);
            if ( v65 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                *(unsigned __int16 *)(LODWORD(v64) + 22),
                (unsigned __int8)*(_WORD *)(LODWORD(v64) + 16),
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v57 + 371) + 16) + 4 * v65),
                (const char *)&l->m_shadow_map_size);
          }
          ++*((_DWORD *)v57 + 23);
          *((_BYTE *)v57 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                    (vostok::render::textures_handler<0> *)(v57 + 1488),
                                    (char *)v57 + 1488,
                                    (vostok::render::res_texture *)&stru_9649F4,
                                    l->m_shadow_depth_stencil_texture[la->shadow_map_size_index].m_object);
        }
        else
        {
          v66 = *(float *)&l->m_point_light_accumulator.m_object;
          if ( v39 < (*(_DWORD *)(LODWORD(v66) + 284) - *(_DWORD *)(LODWORD(v66) + 280)) >> 2 )
          {
            *(_DWORD *)(LODWORD(v66) + 276) = v39;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v39, LODWORD(v87));
          }
        }
        v67 = *(float *)&l->m_c_light_position;
        v68 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        if ( *(_DWORD *)(LODWORD(v67) + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                               + 573) )
        {
          v69 = *(unsigned __int16 *)(LODWORD(v67) + 20);
          if ( v69 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v67) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v67) + 16),
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                       + 371)
                                                                     + 16)
                                                         + 4 * v69),
              (const char *)&light_position);
        }
        ++v68->num_setted_shader_constants;
        v70 = *(float *)&l->m_c_light_range;
        if ( *(_DWORD *)(LODWORD(v70) + 40) != v68->m_constant_update_markers[1]
          || (v71 = *(unsigned __int16 *)(LODWORD(v70) + 20), v71 == 0xFFFF) )
        {
          v72 = (const char *)la;
        }
        else
        {
          v72 = (const char *)la;
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v70) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v70) + 16),
            v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v71].m_object,
            (const char *)&la->range);
        }
        ++v68->num_setted_shader_constants;
        v73 = *(float *)&l->m_c_light_attenuation_power;
        if ( *(_DWORD *)(LODWORD(v73) + 40) == v68->m_constant_update_markers[1] )
        {
          v74 = *(unsigned __int16 *)(LODWORD(v73) + 20);
          if ( v74 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v73) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v73) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v74].m_object,
              v72 + 220);
        }
        ++v68->num_setted_shader_constants;
        v75 = *(float *)&l->m_c_diffuse_influence_factor;
        if ( *(_DWORD *)(LODWORD(v75) + 40) == v68->m_constant_update_markers[1] )
        {
          v76 = *(unsigned __int16 *)(LODWORD(v75) + 20);
          if ( v76 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v75) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v75) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v76].m_object,
              v72 + 340);
        }
        ++v68->num_setted_shader_constants;
        v77 = *(float *)&l->m_c_specular_influence_factor;
        if ( *(_DWORD *)(LODWORD(v77) + 40) == v68->m_constant_update_markers[1] )
        {
          v78 = *(unsigned __int16 *)(LODWORD(v77) + 20);
          if ( v78 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v77) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v77) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v78].m_object,
              v72 + 344);
        }
        ++v68->num_setted_shader_constants;
        m_c_is_shadower = (unsigned int)l->m_c_is_shadower;
        if ( *(_DWORD *)(m_c_is_shadower + 40) == v68->m_constant_update_markers[1] )
        {
          v80 = *(unsigned __int16 *)(m_c_is_shadower + 20);
          if ( v80 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(m_c_is_shadower + 22),
              (unsigned __int8)*(_WORD *)(m_c_is_shadower + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v80].m_object,
              (const char *)&src_ptr);
        }
        ++v68->num_setted_shader_constants;
        v81 = *(float *)&l->m_c_light_color;
        if ( *(_DWORD *)(LODWORD(v81) + 40) == v68->m_constant_update_markers[1] )
        {
          v82 = *(unsigned __int16 *)(LODWORD(v81) + 20);
          if ( v82 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v81) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v81) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v82].m_object,
              (const char *)&light_color);
        }
        ++v68->num_setted_shader_constants;
        v83 = *(float *)&l->m_c_light_intensity;
        if ( *(_DWORD *)(LODWORD(v83) + 40) == v68->m_constant_update_markers[1] )
        {
          v84 = *(unsigned __int16 *)(LODWORD(v83) + 20);
          if ( v84 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v83) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v83) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v84].m_object,
              (const char *)&la->intensity);
        }
        ++v68->num_setted_shader_constants;
        v85 = *(float *)&l->m_c_lighting_model;
        if ( *(_DWORD *)(LODWORD(v85) + 40) == v68->m_constant_update_markers[1] )
        {
          v86 = *(unsigned __int16 *)(LODWORD(v85) + 20);
          if ( v86 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(LODWORD(v85) + 22),
              (unsigned __int8)*(_WORD *)(LODWORD(v85) + 16),
              v68->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v86].m_object,
              (const char *)&la->lighting_model);
        }
        ++v68->num_setted_shader_constants;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          l->m_c_eye_ray_corner,
          &v68->m_ps_constants_handler,
          l->m_context->m_eye_rays);
        ++v68->num_setted_shader_constants;
        vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
          l->m_c_near_far,
          &v68->m_vs_constants_handler,
          (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
        ++v68->num_setted_shader_constants;
        vostok::render::res_geometry::apply(geometry);
        vostok::render::backend::render_indexed(v68, 0x12u, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, 0);
        v39 = tech_index + 1;
        tech_index = v39;
      }
      while ( v39 < 2 );
    }
    ++face_index;
  }
  while ( face_index < 6 );
  if ( geometry )
  {
    v35 = geometry->m_reference_count-- == 1;
    if ( v35 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        geometry);
  }
}
