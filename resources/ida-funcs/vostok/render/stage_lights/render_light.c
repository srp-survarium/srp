void __userpurge vostok::render::stage_lights::render_light(
        vostok::render::stage_lights *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<esi>,
        vostok::render::stage_lights *l,
        vostok::render::light *shadowers_pass)
{
  int v4; // eax
  vostok::render::stage_lights *v5; // ecx
  vostok::render::renderer_context *m_context; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float z; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  vostok::render::light *z_low; // ecx
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  vostok::render::light::light_flags flags; // ecx
  vostok::render::light *v27; // ecx
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_geometry; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v30; // esi
  vostok::render::render_target *v31; // eax
  vostok::render::resource_manager *v32; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  ID3D11RenderTargetView *v35; // edx
  int v36; // esi
  bool v37; // zf
  float v38; // eax
  vostok::render::light *v39; // ecx
  vostok::render::res_effect *v40; // ecx
  float v41; // eax
  float v42; // ecx
  const char *v43; // esi
  int v44; // eax
  __int16 v45; // dx
  unsigned int v46; // ecx
  float v47; // ecx
  int v48; // eax
  __int16 v49; // dx
  unsigned int v50; // ecx
  const vostok::math::float4x4 *v51; // xmm0_4
  unsigned int m_c_is_shadower; // ecx
  int v53; // edx
  int v54; // eax
  __int16 v55; // dx
  unsigned int v56; // ecx
  float v57; // ecx
  int v58; // eax
  __int16 v59; // dx
  unsigned int v60; // ecx
  vostok::render::res_geometry *v61; // ecx
  char *v62; // esi
  const vostok::math::float3 *v63; // eax
  vostok::render::textures_handler<0> *v64; // ecx
  float v65; // ecx
  const char *v66; // esi
  int v67; // eax
  __int16 v68; // dx
  unsigned int v69; // ecx
  float v70; // ecx
  int v71; // eax
  __int16 v72; // dx
  unsigned int v73; // ecx
  long double v74; // st7
  float v75; // eax
  int v76; // ecx
  int v77; // ecx
  __int16 v78; // dx
  unsigned int v79; // eax
  int v80; // ecx
  __int16 v81; // dx
  vostok::collision::space_partitioning_tree *m_c_light_spot_penumbra_half_angle_cosine; // eax
  int v83; // ecx
  __int16 v84; // dx
  vostok::collision::geometry_instance *m_c_light_spot_umbra_half_angle_cosine; // eax
  int v86; // ecx
  __int16 v87; // dx
  float v88; // xmm0_4
  float v89; // xmm0_4
  vostok::collision::object *m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine; // ecx
  unsigned int m_type; // edx
  int v92; // eax
  __int16 x_low; // dx
  unsigned int v94; // ecx
  float v95; // eax
  int v96; // ecx
  __int16 v97; // dx
  vostok::render::res_geometry *v98; // ecx
  float v99; // eax
  const char *v100; // ebx
  int v101; // ecx
  vostok::render::res_geometry *v102; // ecx
  const char *v103; // esi
  vostok::render::constants_handler<1> *v104; // edi
  vostok::render::res_geometry *v105; // ecx
  vostok::render::res_geometry *v106; // eax
  vostok::render::stage_lights *v107; // [esp+4h] [ebp-1DCh]
  vostok::render::stage_lights *v108; // [esp+4h] [ebp-1DCh]
  unsigned int tech_index; // [esp+18h] [ebp-1C8h]
  vostok::render::res_effect *tech_indexa; // [esp+18h] [ebp-1C8h]
  vostok::render::res_effect *tech_indexb; // [esp+18h] [ebp-1C8h]
  vostok::render::res_effect *tech_indexc; // [esp+18h] [ebp-1C8h]
  float penumbra_half_angle_cosine; // [esp+1Ch] [ebp-1C4h] BYREF
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> geometry; // [esp+20h] [ebp-1C0h] BYREF
  float umbra_half_angle_cosine; // [esp+24h] [ebp-1BCh] BYREF
  vostok::math::float3 arg; // [esp+28h] [ebp-1B8h] BYREF
  char src_ptr[4]; // [esp+34h] [ebp-1ACh] BYREF
  vostok::math::float3 light_position; // [esp+38h] [ebp-1A8h] BYREF
  vostok::math::float3 light_color; // [esp+44h] [ebp-19Ch] BYREF
  vostok::math::float3 light_direction; // [esp+50h] [ebp-190h] BYREF
  vostok::math::float4x4 obb_world; // [esp+5Ch] [ebp-184h] BYREF
  vostok::math::float4x4 v122; // [esp+9Ch] [ebp-144h] BYREF
  vostok::math::float4x4 result; // [esp+15Ch] [ebp-84h] BYREF

  if ( !shadowers_pass->is_shadower )
  {
    v4 = *(_DWORD *)&shadowers_pass->flags & 0xF;
    if ( v4 != 4 )
    {
      if ( (!v4 || v4 == 5 || v4 == 2)
        && vostok::render::light::is_cast_shadows((vostok::render::light *)this, (int)shadowers_pass)
        && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
           + 267) )
      {
        vostok::render::stage_lights::render_shadowed_light(
          v5,
          *(float *)&l,
          *(float *)&shadowers_pass,
          *(float *)&a2,
          l,
          shadowers_pass);
      }
      else
      {
        m_context = l->m_context;
        y = shadowers_pass->position.y;
        x = shadowers_pass->position.x;
        v9 = m_context->m_v.k.x;
        v10 = m_context->m_v.j.x * y;
        arg.z = shadowers_pass->range;
        *(_QWORD *)&light_color.x = *(_QWORD *)&shadowers_pass->color.x;
        z = shadowers_pass->position.z;
        v12 = (float)((float)(v10 + (float)(v9 * z)) + (float)(m_context->m_v.i.x * x)) + m_context->m_v.c.x;
        v13 = m_context->m_v.j.y;
        light_position.x = v12;
        v14 = (float)((float)((float)(m_context->m_v.i.y * x) + (float)(v13 * y)) + (float)(m_context->m_v.k.y * z))
            + m_context->m_v.c.y;
        v15 = m_context->m_v.k.x;
        light_position.y = v14;
        v16 = (float)(m_context->m_v.i.z * x) + (float)(m_context->m_v.j.z * y);
        v17 = shadowers_pass->direction.x;
        z_low = (vostok::render::light *)LODWORD(shadowers_pass->color.z);
        v19 = m_context->m_v.k.z * z;
        v20 = shadowers_pass->direction.z;
        v21 = (float)(v16 + v19) + m_context->m_v.c.z;
        v22 = shadowers_pass->direction.y;
        light_position.z = v21;
        v23 = (float)((float)(m_context->m_v.j.x * v22) + (float)(v15 * v20)) + (float)(m_context->m_v.i.x * v17);
        v24 = m_context->m_v.j.y;
        light_direction.x = v23;
        light_direction.y = (float)((float)(m_context->m_v.i.y * v17) + (float)(v24 * v22))
                          + (float)(m_context->m_v.k.y * v20);
        v25 = (float)((float)(m_context->m_v.i.z * v17) + (float)(m_context->m_v.j.z * v22))
            + (float)(m_context->m_v.k.z * v20);
        LODWORD(light_color.z) = z_low;
        light_direction.z = v25;
        vostok::render::light::xform_calc(z_low, shadowers_pass);
        vostok::render::renderer_context::set_w(l->m_context, &shadowers_pass->m_xform);
        flags = shadowers_pass->flags;
        geometry.m_object = 0;
        v27 = (vostok::render::light *)(*(_BYTE *)&flags & 0xF);
        switch ( (unsigned int)v27 )
        {
          case 0u:
          case 5u:
            p_geometry = &l->m_sphere_geometry.geometry;
            goto LABEL_13;
          case 1u:
            p_geometry = &l->m_pyramid_geometry.geometry;
            goto LABEL_13;
          case 2u:
          case 3u:
          case 6u:
            p_geometry = &l->m_obb_geometry.geometry;
LABEL_13:
            a2 = &geometry;
            vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
              p_geometry,
              (const vostok::render::res_geometry **)&geometry.m_object);
            break;
          case 4u:
            break;
        }
        if ( (*(_DWORD *)&shadowers_pass->flags & 0xF) == 1 )
        {
          if ( vostok::render::light::is_cast_shadows(v27, (int)shadowers_pass)
            && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
               + 267) )
          {
            vostok::render::stage_lights::make_spot_light_shadowmap(
              shadowers_pass,
              *(float *)&a2,
              l,
              (unsigned int)v107);
          }
        }
        else if ( (*(_DWORD *)&shadowers_pass->flags & 0xF) == 6
               && vostok::render::light::is_cast_shadows(v27, (int)shadowers_pass)
               && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 267) )
        {
          vostok::render::stage_lights::make_plane_spot_light_shadowmap(
            shadowers_pass,
            *(float *)&a2,
            l,
            (unsigned int)v107);
        }
        vostok::render::renderer_context::set_w(l->m_context, &shadowers_pass->m_xform);
        m_object = l->m_context->m_targets->m_family[28].target.m_object;
        v30 = 0;
        if ( m_object )
        {
          v30 = l->m_context->m_targets->m_family[28].target.m_object;
          ++m_object->m_reference_count;
        }
        v31 = l->m_context->m_targets->m_family[26].target.m_object;
        v32 = 0;
        if ( v31 )
        {
          v32 = (vostok::render::resource_manager *)l->m_context->m_targets->m_family[26].target.m_object;
          ++v31->m_reference_count;
          m_rt = v31->m_rt;
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
        if ( v30 )
          v35 = v30->m_rt;
        else
          v35 = 0;
        if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 536) != v35 )
        {
          *((_DWORD *)m_conflicted_key_name + 536) = v35;
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
        if ( v32 )
        {
          if ( !--v32->sh_created )
          {
            vostok::render::resource_manager::release(
              v32,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v32);
            m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
        }
        if ( v30 )
        {
          if ( !--v30->m_reference_count )
          {
            vostok::render::resource_manager::release(
              v32,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v30);
            m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
        }
        v36 = *((_DWORD *)m_conflicted_key_name + 547);
        v37 = *((_DWORD *)m_conflicted_key_name + 539) == v36;
        *((_DWORD *)m_conflicted_key_name + 539) = v36;
        *((_BYTE *)m_conflicted_key_name + 167) |= !v37;
        v38 = *(float *)&l->m_effect_accum_mask.m_object;
        if ( (*(_DWORD *)(LODWORD(v38) + 284) - *(_DWORD *)(LODWORD(v38) + 280)) >> 2 )
        {
          *(_DWORD *)(LODWORD(v38) + 276) = 0;
          LOBYTE(v32) = !v37;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v32, (unsigned int)v107);
        }
        vostok::render::res_geometry::apply(geometry.m_object);
        vostok::render::stage_lights::draw_geometry(shadowers_pass, v107);
        switch ( *(_DWORD *)&shadowers_pass->flags & 0xF )
        {
          case 0:
            v40 = 0;
            for ( tech_index = 0; ; v40 = (vostok::render::res_effect *)tech_index )
            {
              if ( shadowers_pass->is_shadower )
                v41 = *(float *)&l->m_point_light_shadower.m_object;
              else
                v41 = *(float *)&l->m_point_light_accumulator.m_object;
              vostok::render::res_effect::apply(v40, (_DWORD *)LODWORD(v41));
              v42 = *(float *)&l->m_c_light_position;
              v43 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              if ( *(_DWORD *)(LODWORD(v42) + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                     + 573) )
              {
                v44 = *(unsigned __int16 *)(LODWORD(v42) + 20);
                if ( v44 != 0xFFFF )
                {
                  v45 = *(_WORD *)(LODWORD(v42) + 16);
                  v46 = *(unsigned __int16 *)(LODWORD(v42) + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                      + 371)
                                                                    + 16)
                                                        + 4 * v44);
                  vostok::render::shader_constant_buffer::set_memory(
                    v46,
                    (unsigned __int8)v45,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&light_position);
                }
              }
              ++*((_DWORD *)v43 + 23);
              v47 = *(float *)&l->m_c_light_range;
              if ( *(_DWORD *)(LODWORD(v47) + 40) == *((_DWORD *)v43 + 573) )
              {
                v48 = *(unsigned __int16 *)(LODWORD(v47) + 20);
                if ( v48 != 0xFFFF )
                {
                  v49 = *(_WORD *)(LODWORD(v47) + 16);
                  v50 = *(unsigned __int16 *)(LODWORD(v47) + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v43 + 371) + 16) + 4 * v48);
                  vostok::render::shader_constant_buffer::set_memory(
                    v50,
                    (unsigned __int8)v49,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&arg.elements[2]);
                }
              }
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_attenuation_power,
                (vostok::render::constants_handler<1> *)v43 + 123,
                (const vostok::math::float3 *)&shadowers_pass->attenuation_power);
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_diffuse_influence_factor,
                (vostok::render::constants_handler<1> *)v43 + 123,
                (const vostok::math::float3 *)&shadowers_pass->diffuse_influence_factor);
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_specular_influence_factor,
                (vostok::render::constants_handler<1> *)v43 + 123,
                (const vostok::math::float3 *)&shadowers_pass->specular_influence_factor);
              ++*((_DWORD *)v43 + 23);
              if ( shadowers_pass->is_shadower )
                v51 = clear_value;
              else
                *(float *)&v51 = 0.0;
              m_c_is_shadower = (unsigned int)l->m_c_is_shadower;
              v53 = *(_DWORD *)(m_c_is_shadower + 40);
              umbra_half_angle_cosine = *(float *)&v51;
              if ( v53 == *((_DWORD *)v43 + 573) )
              {
                v54 = *(unsigned __int16 *)(m_c_is_shadower + 20);
                if ( v54 != 0xFFFF )
                {
                  v55 = *(_WORD *)(m_c_is_shadower + 16);
                  v56 = *(unsigned __int16 *)(m_c_is_shadower + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v43 + 371) + 16) + 4 * v54);
                  vostok::render::shader_constant_buffer::set_memory(
                    v56,
                    (unsigned __int8)v55,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&umbra_half_angle_cosine);
                }
              }
              ++*((_DWORD *)v43 + 23);
              v57 = *(float *)&l->m_c_light_color;
              if ( *(_DWORD *)(LODWORD(v57) + 40) == *((_DWORD *)v43 + 573) )
              {
                v58 = *(unsigned __int16 *)(LODWORD(v57) + 20);
                if ( v58 != 0xFFFF )
                {
                  v59 = *(_WORD *)(LODWORD(v57) + 16);
                  v60 = *(unsigned __int16 *)(LODWORD(v57) + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v43 + 371) + 16) + 4 * v58);
                  vostok::render::shader_constant_buffer::set_memory(
                    v60,
                    (unsigned __int8)v59,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&light_color);
                }
              }
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_intensity,
                (vostok::render::constants_handler<1> *)v43 + 123,
                (const vostok::math::float3 *)&shadowers_pass->intensity);
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_lighting_model,
                (vostok::render::constants_handler<1> *)v43 + 123,
                (const vostok::math::float3 *)&shadowers_pass->lighting_model);
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_eye_ray_corner,
                (vostok::render::constants_handler<1> *)v43 + 123,
                l->m_context->m_eye_rays);
              ++*((_DWORD *)v43 + 23);
              vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
                l->m_c_near_far,
                (vostok::render::constants_handler<0> *)(v43 + 196),
                (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
              v61 = geometry.m_object;
              ++*((_DWORD *)v43 + 23);
              vostok::render::res_geometry::apply(v61);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, v108);
              if ( ++tech_index >= 2 )
                break;
            }
            break;
          case 1:
            tech_indexa = 0;
            *(_DWORD *)src_ptr = 0;
            do
            {
              if ( vostok::render::light::is_cast_shadows(v39, (int)shadowers_pass)
                && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 267) )
              {
                vostok::render::res_effect::apply(
                  tech_indexa,
                  &l->m_shadowed_spot_light_accumulator.m_object->__vftable);
                v62 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                  (const vostok::math::float3 *)&shadowers_pass->shadow_transparency,
                  l->m_c_shadow_transparency);
                v63 = (const vostok::math::float3 *)vostok::math::transpose(&result, &l->m_view_to_light_matrix);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  (vostok::render::backend *)v62,
                  v63,
                  l->m_c_view_to_light_matrix);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  (vostok::render::backend *)v62,
                  (const vostok::math::float3 *)&l->m_shadow_z_bias,
                  l->m_c_shadow_z_bias);
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  (vostok::render::backend *)v62,
                  (const vostok::math::float3 *)&l->m_shadow_map_size,
                  l->m_c_shadow_map_size);
                if ( shadowers_pass->static_shadows )
                  v62[159] = vostok::render::textures_handler<0>::set_overwrite(
                               v64,
                               v62 + 1488,
                               (vostok::render::res_texture *)&stru_9649F4,
                               shadowers_pass->m_shadow_depth_stencil_texture.m_object);
                else
                  v62[159] = vostok::render::textures_handler<0>::set_overwrite(
                               (vostok::render::textures_handler<0> *)shadowers_pass->shadow_map_size_index,
                               v62 + 1488,
                               (vostok::render::res_texture *)&stru_9649F4,
                               l->m_shadow_depth_stencil_texture[shadowers_pass->shadow_map_size_index].m_object);
              }
              else
              {
                vostok::render::res_effect::apply(tech_indexa, &l->m_spot_light_accumulator.m_object->__vftable);
              }
              v65 = *(float *)&l->m_c_light_position;
              v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              if ( *(_DWORD *)(LODWORD(v65) + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                     + 573) )
              {
                v67 = *(unsigned __int16 *)(LODWORD(v65) + 20);
                if ( v67 != 0xFFFF )
                {
                  v68 = *(_WORD *)(LODWORD(v65) + 16);
                  v69 = *(unsigned __int16 *)(LODWORD(v65) + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                      + 371)
                                                                    + 16)
                                                        + 4 * v67);
                  vostok::render::shader_constant_buffer::set_memory(
                    v69,
                    (unsigned __int8)v68,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&light_position);
                }
              }
              ++*((_DWORD *)v66 + 23);
              v70 = *(float *)&l->m_c_light_direction;
              if ( *(_DWORD *)(LODWORD(v70) + 40) == *((_DWORD *)v66 + 573) )
              {
                v71 = *(unsigned __int16 *)(LODWORD(v70) + 20);
                if ( v71 != 0xFFFF )
                {
                  v72 = *(_WORD *)(LODWORD(v70) + 16);
                  v73 = *(unsigned __int16 *)(LODWORD(v70) + 22);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v71);
                  vostok::render::shader_constant_buffer::set_memory(
                    v73,
                    (unsigned __int8)v72,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    (const char *)&light_direction);
                }
              }
              ++*((_DWORD *)v66 + 23);
              v74 = sinf(shadowers_pass->spot_penumbra_angle * 0.5);
              v75 = *(float *)&l->m_c_light_range;
              v76 = *(_DWORD *)(LODWORD(v75) + 40);
              penumbra_half_angle_cosine = arg.z / v74;
              if ( v76 == *((_DWORD *)v66 + 573) )
              {
                v77 = *(unsigned __int16 *)(LODWORD(v75) + 20);
                if ( v77 != 0xFFFF )
                {
                  v78 = *(_WORD *)(LODWORD(v75) + 16);
                  umbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v77);
                  vostok::render::shader_constant_buffer::set_memory(
                    *(unsigned __int16 *)(LODWORD(v75) + 22),
                    (unsigned __int8)v78,
                    (vostok::render::shader_constant_buffer *)LODWORD(umbra_half_angle_cosine),
                    (const char *)&penumbra_half_angle_cosine);
                }
              }
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_attenuation_power,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->attenuation_power);
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_diffuse_influence_factor,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->diffuse_influence_factor);
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_specular_influence_factor,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->specular_influence_factor);
              ++*((_DWORD *)v66 + 23);
              v79 = (unsigned int)l->m_c_is_shadower;
              if ( *(_DWORD *)(v79 + 40) == *((_DWORD *)v66 + 573) )
              {
                v80 = *(unsigned __int16 *)(v79 + 20);
                if ( v80 != 0xFFFF )
                {
                  v81 = *(_WORD *)(v79 + 16);
                  penumbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v80);
                  vostok::render::shader_constant_buffer::set_memory(
                    *(unsigned __int16 *)(v79 + 22),
                    (unsigned __int8)v81,
                    (vostok::render::shader_constant_buffer *)LODWORD(penumbra_half_angle_cosine),
                    src_ptr);
                }
              }
              ++*((_DWORD *)v66 + 23);
              penumbra_half_angle_cosine = cosf(shadowers_pass->spot_penumbra_angle * 0.5);
              m_c_light_spot_penumbra_half_angle_cosine = (vostok::collision::space_partitioning_tree *)l->m_c_light_spot_penumbra_half_angle_cosine;
              if ( m_c_light_spot_penumbra_half_angle_cosine[10].__vftable == (vostok::collision::space_partitioning_tree_vtbl *)*((_DWORD *)v66 + 573) )
              {
                v83 = LOWORD(m_c_light_spot_penumbra_half_angle_cosine[5].__vftable);
                if ( v83 != 0xFFFF )
                {
                  v84 = (__int16)m_c_light_spot_penumbra_half_angle_cosine[4].__vftable;
                  umbra_half_angle_cosine = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v83);
                  vostok::render::shader_constant_buffer::set_memory(
                    HIWORD(m_c_light_spot_penumbra_half_angle_cosine[5].__vftable),
                    (unsigned __int8)v84,
                    (vostok::render::shader_constant_buffer *)LODWORD(umbra_half_angle_cosine),
                    (const char *)&penumbra_half_angle_cosine);
                }
              }
              ++*((_DWORD *)v66 + 23);
              umbra_half_angle_cosine = cosf(shadowers_pass->spot_umbra_angle * 0.5);
              m_c_light_spot_umbra_half_angle_cosine = (vostok::collision::geometry_instance *)l->m_c_light_spot_umbra_half_angle_cosine;
              if ( m_c_light_spot_umbra_half_angle_cosine[5].__vftable == (vostok::collision::geometry_instance_vtbl *)*((_DWORD *)v66 + 573) )
              {
                v86 = *(unsigned __int16 *)&m_c_light_spot_umbra_half_angle_cosine[2].m_delete_by_collision_object;
                if ( v86 != 0xFFFF )
                {
                  v87 = (__int16)m_c_light_spot_umbra_half_angle_cosine[2].__vftable;
                  arg.y = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v86);
                  vostok::render::shader_constant_buffer::set_memory(
                    *((unsigned __int16 *)&m_c_light_spot_umbra_half_angle_cosine[2].m_delete_by_collision_object + 1),
                    (unsigned __int8)v87,
                    (vostok::render::shader_constant_buffer *)LODWORD(arg.y),
                    (const char *)&umbra_half_angle_cosine);
                }
              }
              v88 = umbra_half_angle_cosine;
              ++*((_DWORD *)v66 + 23);
              v89 = v88 - penumbra_half_angle_cosine;
              if ( v89 <= 0.000099999997 )
                v89 = FLOAT_0_000099999997;
              m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = (vostok::collision::object *)l->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
              m_type = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_type;
              arg.x = *(float *)&clear_value / v89;
              if ( m_type == *((_DWORD *)v66 + 573) )
              {
                v92 = LOWORD(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_aabb.max.elements[1]);
                if ( v92 != 0xFFFF )
                {
                  x_low = LOWORD(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_aabb.max.x);
                  v94 = HIWORD(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_aabb.max.elements[1]);
                  arg.y = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v92);
                  vostok::render::shader_constant_buffer::set_memory(
                    v94,
                    (unsigned __int8)x_low,
                    (vostok::render::shader_constant_buffer *)LODWORD(arg.y),
                    (const char *)&arg);
                }
              }
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_spot_falloff,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->spot_falloff);
              ++*((_DWORD *)v66 + 23);
              v95 = *(float *)&l->m_c_light_color;
              if ( *(_DWORD *)(LODWORD(v95) + 40) == *((_DWORD *)v66 + 573) )
              {
                v96 = *(unsigned __int16 *)(LODWORD(v95) + 20);
                if ( v96 != 0xFFFF )
                {
                  v97 = *(_WORD *)(LODWORD(v95) + 16);
                  arg.y = *(float *)(*(_DWORD *)(*((_DWORD *)v66 + 371) + 16) + 4 * v96);
                  vostok::render::shader_constant_buffer::set_memory(
                    *(unsigned __int16 *)(LODWORD(v95) + 22),
                    (unsigned __int8)v97,
                    (vostok::render::shader_constant_buffer *)LODWORD(arg.y),
                    (const char *)&light_color);
                }
              }
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_intensity,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->intensity);
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_lighting_model,
                (vostok::render::constants_handler<1> *)v66 + 123,
                (const vostok::math::float3 *)&shadowers_pass->lighting_model);
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_eye_ray_corner,
                (vostok::render::constants_handler<1> *)v66 + 123,
                l->m_context->m_eye_rays);
              ++*((_DWORD *)v66 + 23);
              vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
                l->m_c_near_far,
                (vostok::render::constants_handler<0> *)(v66 + 196),
                (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
              v98 = geometry.m_object;
              ++*((_DWORD *)v66 + 23);
              vostok::render::res_geometry::apply(v98);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, v108);
              tech_indexa = (vostok::render::res_effect *)((char *)tech_indexa + 1);
            }
            while ( (unsigned int)tech_indexa < 2 );
            break;
          case 2:
            tech_indexb = 0;
            arg.x = 0.0;
            do
            {
              vostok::render::res_effect::apply(tech_indexb, &l->m_obb_light_accumulator.m_object->__vftable);
              v99 = *(float *)&l->m_c_light_position;
              v100 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              if ( *(_DWORD *)(LODWORD(v99) + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                     + 573) )
              {
                v101 = *(unsigned __int16 *)(LODWORD(v99) + 20);
                if ( v101 != 0xFFFF )
                  vostok::render::shader_constant_buffer::set_memory(
                    *(unsigned __int16 *)(LODWORD(v99) + 22),
                    (unsigned __int8)*(_WORD *)(LODWORD(v99) + 16),
                    *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                             + 371)
                                                                           + 16)
                                                               + 4 * v101),
                    (const char *)&light_position);
              }
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_range,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (vostok::math::float3 *)&arg.elements[2]);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_attenuation_power,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&shadowers_pass->attenuation_power);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_diffuse_influence_factor,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&shadowers_pass->diffuse_influence_factor);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_specular_influence_factor,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&shadowers_pass->specular_influence_factor);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_is_shadower,
                (vostok::render::constants_handler<1> *)v100 + 123,
                &arg);
              ++*((_DWORD *)v100 + 23);
              qmemcpy((void *)&obb_world, &shadowers_pass->m_xform, sizeof(obb_world));
              vostok::math::float4x4::set_scale(&obb_world, &shadowers_pass->scale);
              vostok::math::mul4x3(&v122, &obb_world, &l->m_context->m_v);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_local_to_world,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&v122);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_color,
                (vostok::render::constants_handler<1> *)v100 + 123,
                &light_color);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_intensity,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&shadowers_pass->intensity);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_lighting_model,
                (vostok::render::constants_handler<1> *)v100 + 123,
                (const vostok::math::float3 *)&shadowers_pass->lighting_model);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_eye_ray_corner,
                (vostok::render::constants_handler<1> *)v100 + 123,
                l->m_context->m_eye_rays);
              ++*((_DWORD *)v100 + 23);
              vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
                l->m_c_near_far,
                (vostok::render::constants_handler<0> *)(v100 + 196),
                (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
              v102 = geometry.m_object;
              ++*((_DWORD *)v100 + 23);
              vostok::render::res_geometry::apply(v102);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, v108);
              tech_indexb = (vostok::render::res_effect *)((char *)tech_indexb + 1);
            }
            while ( (unsigned int)tech_indexb < 2 );
            break;
          case 3:
            tech_indexc = 0;
            arg.x = 0.0;
            do
            {
              vostok::render::res_effect::apply(tech_indexc, &l->m_capsule_light_accumulator.m_object->__vftable);
              v103 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              v104 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                            + 1476);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_position,
                (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
              + 123,
                &light_position);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_direction,
                v104,
                &light_direction);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_range,
                v104,
                (vostok::math::float3 *)&arg.elements[2]);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_attenuation_power,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->attenuation_power);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_diffuse_influence_factor,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->diffuse_influence_factor);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_specular_influence_factor,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->specular_influence_factor);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(l->m_c_is_shadower, v104, &arg);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_capsule_half_width,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->scale.elements[2]);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_capsule_radius,
                v104,
                &shadowers_pass->scale);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_color,
                v104,
                &light_color);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_light_intensity,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->intensity);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_lighting_model,
                v104,
                (const vostok::math::float3 *)&shadowers_pass->lighting_model);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                l->m_c_eye_ray_corner,
                v104,
                l->m_context->m_eye_rays);
              ++*((_DWORD *)v103 + 23);
              vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
                l->m_c_near_far,
                (vostok::render::constants_handler<0> *)(v103 + 196),
                (const vostok::math::float3 *)&l->m_context->m_near_far_invn_invf);
              v105 = geometry.m_object;
              ++*((_DWORD *)v103 + 23);
              vostok::render::res_geometry::apply(v105);
              vostok::render::stage_lights::draw_geometry(shadowers_pass, v108);
              tech_indexc = (vostok::render::res_effect *)((char *)tech_indexc + 1);
            }
            while ( (unsigned int)tech_indexc < 2 );
            break;
        }
        if ( !s_one_light_dip_value )
          vostok::render::backend::flush_rt_shader_resources(
            (vostok::render::backend *)v39,
            (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        v106 = geometry.m_object;
        if ( geometry.m_object )
        {
          v37 = geometry.m_object->m_reference_count-- == 1;
          if ( v37 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              v106);
        }
      }
    }
  }
}
