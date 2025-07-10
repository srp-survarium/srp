void __thiscall vostok::render::stage_lights::render_speedtree_lighting(
        vostok::render::stage_lights *this,
        vostok::render::stage_lights *lod,
        const vostok::render::lod_entry *instance,
        vostok::render::speedtree_forest *instance_lod,
        const SpeedTree::SInstanceLod *tree_component,
        vostok::render::speedtree_tree_component *l,
        vostok::render::light *la)
{
  vostok::render::light *v7; // edi
  float z; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  __int64 v11; // xmm0_8
  float *m_context; // eax
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  vostok::render::light::light_flags flags; // ecx
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // eax
  vostok::render::material_effects *v28; // eax
  unsigned int m_c_light_position; // eax
  const char *m_conflicted_key_name; // ebx
  int v31; // ecx
  unsigned int m_c_light_range; // eax
  int v33; // ecx
  float v34; // eax
  vostok::render::material_effects *v35; // eax
  unsigned int v36; // eax
  int v37; // ecx
  unsigned int m_c_light_direction; // eax
  int v39; // ecx
  unsigned int v40; // eax
  int v41; // ecx
  unsigned int m_c_light_spot_penumbra_half_angle_cosine; // eax
  int v43; // ecx
  long double v44; // st7
  long double v45; // st7
  float v46; // xmm0_4
  unsigned int m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine; // eax
  int v48; // edx
  int v49; // ecx
  float v50; // eax
  vostok::render::material_effects *v51; // eax
  unsigned int v52; // eax
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // ecx
  unsigned int m_c_light_local_to_world; // eax
  int v57; // ecx
  unsigned int m_c_light_color; // eax
  int v59; // ecx
  float v60; // eax
  vostok::render::material_effects *v61; // eax
  unsigned int v62; // eax
  int v63; // ecx
  unsigned int v64; // eax
  int v65; // ecx
  unsigned int v66; // eax
  int v67; // ecx
  vostok::render::constants_handler<1> *v68; // esi
  unsigned int v69; // eax
  int v70; // ecx
  __int16 v71; // dx
  float v72; // eax
  vostok::render::material_effects *v73; // eax
  vostok::render::material_effects *material_effects; // eax
  vostok::render::material_effects *v75; // eax
  vostok::render::material_effects *v76; // eax
  vostok::render::constants_handler<1> *v77; // esi
  long double v78; // st7
  const vostok::render::shader_constant_host *v79; // eax
  float v80; // xmm0_4
  float v81; // xmm0_4
  const vostok::render::shader_constant_host *v82; // eax
  const vostok::math::float3 *v83; // eax
  vostok::render::base_scene_view *m_object; // eax
  int v85; // xmm0_4
  const vostok::render::shader_constant_host *m_far_fog_color_and_distance; // eax
  vostok::render::speedtree_wind_parameters *p_m_speedtree_wind_parameters; // esi
  const SpeedTree::CWind *Wind; // eax
  vostok::render::light::light_flags v89; // eax
  const char *v90; // edi
  vostok::render::renderer_context *v91; // edi
  vostok::math::float4x4 *instance_transform; // eax
  const vostok::math::float4x4 *v93; // eax
  unsigned int v94; // ebp
  vostok::render::speedtree_billboard_parameters *v95; // [esp-8h] [ebp-110h]
  const SpeedTree::CInstance *v96; // [esp+4h] [ebp-104h]
  char src_ptr[4]; // [esp+14h] [ebp-F4h] BYREF
  float umbra_half_angle_cosine; // [esp+18h] [ebp-F0h] BYREF
  vostok::math::float3 light_direction; // [esp+1Ch] [ebp-ECh] BYREF
  int v100; // [esp+28h] [ebp-E0h]
  vostok::math::float3 light_position; // [esp+2Ch] [ebp-DCh] BYREF
  vostok::math::float3 light_color; // [esp+38h] [ebp-D0h] BYREF
  vostok::math::float4x4 obb_world; // [esp+44h] [ebp-C4h] BYREF
  vostok::math::float4x4 v104; // [esp+84h] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+C4h] [ebp-44h] BYREF

  v7 = la;
  z = la->color.z;
  y = la->position.y;
  x = la->position.x;
  umbra_half_angle_cosine = la->range;
  v11 = *(_QWORD *)&la->color.x;
  light_color.z = z;
  m_context = (float *)lod->m_context;
  v13 = m_context[3913];
  v14 = m_context[3909] * y;
  *(_QWORD *)&light_color.x = v11;
  *(float *)&v11 = la->position.z;
  v15 = (float)((float)(v14 + (float)(v13 * *(float *)&v11)) + (float)(x * m_context[3905])) + m_context[3917];
  v16 = m_context[3910];
  light_position.x = v15;
  v17 = (float)((float)((float)(m_context[3906] * x) + (float)(v16 * y)) + (float)(m_context[3914] * *(float *)&v11))
      + m_context[3918];
  v18 = m_context[3913];
  light_position.y = v17;
  v19 = (float)(m_context[3907] * x) + (float)(m_context[3911] * y);
  v20 = la->direction.x;
  flags = la->flags;
  v22 = m_context[3915] * *(float *)&v11;
  *(float *)&v11 = la->direction.z;
  v23 = (float)(v19 + v22) + m_context[3919];
  v24 = la->direction.y;
  light_position.z = v23;
  v25 = (float)((float)(m_context[3909] * v24) + (float)(v18 * *(float *)&v11)) + (float)(m_context[3905] * v20);
  v26 = m_context[3910];
  light_direction.x = v25;
  light_direction.y = (float)((float)(m_context[3906] * v20) + (float)(v26 * v24))
                    + (float)(m_context[3914] * *(float *)&v11);
  light_direction.z = (float)((float)(m_context[3907] * v20) + (float)(m_context[3911] * v24))
                    + (float)(m_context[3915] * *(float *)&v11);
  switch ( *(_BYTE *)&flags & 0xF )
  {
    case 0:
      v27 = *(float *)&l->m_materail_effects_instance.m_object;
      if ( v27 == 0.0 )
        v28 = s_nomaterial_material_effects[l->get_vertex_input_type(l)];
      else
        v28 = (vostok::render::material_effects *)(LODWORD(v27) + 264);
      vostok::render::res_effect::apply(0, &v28->m_effects[22].m_object->__vftable);
      m_c_light_position = (unsigned int)lod->m_c_light_position;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(m_c_light_position + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 573) )
      {
        v31 = *(unsigned __int16 *)(m_c_light_position + 20);
        if ( v31 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_position + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_position + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v31),
            (const char *)&light_position);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      m_c_light_range = (unsigned int)lod->m_c_light_range;
      if ( *(_DWORD *)(m_c_light_range + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v33 = *(unsigned __int16 *)(m_c_light_range + 20);
        if ( v33 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_range + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_range + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v33),
            (const char *)&umbra_half_angle_cosine);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->attenuation_power);
      goto LABEL_76;
    case 1:
      v34 = *(float *)&l->m_materail_effects_instance.m_object;
      if ( v34 == 0.0 )
        v35 = s_nomaterial_material_effects[l->get_vertex_input_type(l)];
      else
        v35 = (vostok::render::material_effects *)(LODWORD(v34) + 264);
      vostok::render::res_effect::apply(0, &v35->m_effects[22].m_object->__vftable);
      v36 = (unsigned int)lod->m_c_light_position;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v36 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v37 = *(unsigned __int16 *)(v36 + 20);
        if ( v37 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v36 + 22),
            (unsigned __int8)*(_WORD *)(v36 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v37),
            (const char *)&light_position);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      m_c_light_direction = (unsigned int)lod->m_c_light_direction;
      if ( *(_DWORD *)(m_c_light_direction + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v39 = *(unsigned __int16 *)(m_c_light_direction + 20);
        if ( v39 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_direction + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_direction + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v39),
            (const char *)&light_direction);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v40 = (unsigned int)lod->m_c_light_range;
      if ( *(_DWORD *)(v40 + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v41 = *(unsigned __int16 *)(v40 + 20);
        if ( v41 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v40 + 22),
            (unsigned __int8)*(_WORD *)(v40 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v41),
            (const char *)&umbra_half_angle_cosine);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      umbra_half_angle_cosine = cosf(la->spot_penumbra_angle * 0.5);
      m_c_light_spot_penumbra_half_angle_cosine = (unsigned int)lod->m_c_light_spot_penumbra_half_angle_cosine;
      if ( *(_DWORD *)(m_c_light_spot_penumbra_half_angle_cosine + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v43 = *(unsigned __int16 *)(m_c_light_spot_penumbra_half_angle_cosine + 20);
        if ( v43 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_spot_penumbra_half_angle_cosine + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_spot_penumbra_half_angle_cosine + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v43),
            (const char *)&umbra_half_angle_cosine);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v44 = cosf(la->spot_umbra_angle * 0.5);
      v45 = v44 - umbra_half_angle_cosine;
      *(float *)src_ptr = v45;
      if ( v45 <= 0.000099999997 )
        v46 = FLOAT_0_000099999997;
      else
        v46 = *(float *)src_ptr;
      m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = (unsigned int)lod->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      v48 = *(_DWORD *)(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine + 40);
      *(float *)src_ptr = *(float *)&clear_value / v46;
      if ( v48 == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v49 = *(unsigned __int16 *)(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine + 20);
        if ( v49 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine
                                      + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v49),
            src_ptr);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_spot_falloff,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->spot_falloff);
      goto LABEL_76;
    case 2:
      v50 = *(float *)&l->m_materail_effects_instance.m_object;
      if ( v50 == 0.0 )
        v51 = s_nomaterial_material_effects[l->get_vertex_input_type(l)];
      else
        v51 = (vostok::render::material_effects *)(LODWORD(v50) + 264);
      vostok::render::res_effect::apply(0, &v51->m_effects[22].m_object->__vftable);
      v52 = (unsigned int)lod->m_c_light_position;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v52 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v53 = *(unsigned __int16 *)(v52 + 20);
        if ( v53 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v52 + 22),
            (unsigned __int8)*(_WORD *)(v52 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v53),
            (const char *)&light_position);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v54 = (unsigned int)lod->m_c_light_range;
      if ( *(_DWORD *)(v54 + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v55 = *(unsigned __int16 *)(v54 + 20);
        if ( v55 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v54 + 22),
            (unsigned __int8)*(_WORD *)(v54 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v55),
            (const char *)&umbra_half_angle_cosine);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      qmemcpy((void *)&obb_world, &la->m_xform, sizeof(obb_world));
      vostok::math::float4x4::set_scale(&obb_world, &la->scale);
      vostok::math::mul4x3(&result, &obb_world, &lod->m_context->m_v);
      m_c_light_local_to_world = (unsigned int)lod->m_c_light_local_to_world;
      if ( *(_DWORD *)(m_c_light_local_to_world + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v57 = *(unsigned __int16 *)(m_c_light_local_to_world + 20);
        if ( v57 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_local_to_world + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_local_to_world + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v57),
            (const char *)&result);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      m_c_light_color = (unsigned int)lod->m_c_light_color;
      if ( *(_DWORD *)(m_c_light_color + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v59 = *(unsigned __int16 *)(m_c_light_color + 20);
        if ( v59 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_color + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_color + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v59),
            (const char *)&light_color);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->intensity);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->lighting_model);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_eye_ray_corner,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        lod->m_context->m_eye_rays);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        lod->m_c_near_far,
        (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
        (const vostok::math::float3 *)&lod->m_context->m_near_far_invn_invf);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v7 = la;
      goto LABEL_77;
    case 3:
      v60 = *(float *)&l->m_materail_effects_instance.m_object;
      if ( v60 == 0.0 )
        v61 = s_nomaterial_material_effects[l->get_vertex_input_type(l)];
      else
        v61 = (vostok::render::material_effects *)(LODWORD(v60) + 264);
      vostok::render::res_effect::apply(0, &v61->m_effects[22].m_object->__vftable);
      v62 = (unsigned int)lod->m_c_light_position;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v62 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v63 = *(unsigned __int16 *)(v62 + 20);
        if ( v63 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v62 + 22),
            (unsigned __int8)*(_WORD *)(v62 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v63),
            (const char *)&light_position);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v64 = (unsigned int)lod->m_c_light_direction;
      if ( *(_DWORD *)(v64 + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v65 = *(unsigned __int16 *)(v64 + 20);
        if ( v65 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v64 + 22),
            (unsigned __int8)*(_WORD *)(v64 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v65),
            (const char *)&light_direction);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v66 = (unsigned int)lod->m_c_light_range;
      if ( *(_DWORD *)(v66 + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v67 = *(unsigned __int16 *)(v66 + 20);
        if ( v67 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v66 + 22),
            (unsigned __int8)*(_WORD *)(v66 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16)
                                                       + 4 * v67),
            (const char *)&umbra_half_angle_cosine);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v68 = (vostok::render::constants_handler<1> *)(m_conflicted_key_name + 1476);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_capsule_half_width,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&la->scale.elements[2]);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_capsule_radius,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        &la->scale);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v69 = (unsigned int)lod->m_c_light_color;
      if ( *(_DWORD *)(v69 + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v70 = *(unsigned __int16 *)(v69 + 20);
        if ( v70 != 0xFFFF )
        {
          v71 = *(_WORD *)(v69 + 16);
          *(float *)src_ptr = *(float *)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v70);
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v69 + 22),
            (unsigned __int8)v71,
            *(vostok::render::shader_constant_buffer **)src_ptr,
            (const char *)&light_color);
        }
      }
      goto LABEL_65;
    case 4:
      v72 = *(float *)&l->m_materail_effects_instance.m_object;
      if ( v72 == 0.0 )
        v73 = s_nomaterial_material_effects[l->get_vertex_input_type(l)];
      else
        v73 = (vostok::render::material_effects *)(LODWORD(v72) + 264);
      if ( !v73->m_effects[22].m_object
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        return;
      }
      material_effects = vostok::render::speedtree_tree_component::get_material_effects(l);
      vostok::render::res_effect::apply(0, &material_effects->m_effects[22].m_object->__vftable);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        &light_direction,
        lod->m_c_light_direction);
      goto LABEL_77;
    case 5:
      v75 = vostok::render::speedtree_tree_component::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v75->m_effects[22].m_object->__vftable);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v68 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 1476);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_position,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        &light_position);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_range,
        v68,
        (const vostok::math::float3 *)&umbra_half_angle_cosine);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        v68,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_sphere_radius,
        v68,
        &la->scale);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_color,
        v68,
        &light_color);
LABEL_65:
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_intensity,
        v68,
        (const vostok::math::float3 *)&la->intensity);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_lighting_model,
        v68,
        (const vostok::math::float3 *)&la->lighting_model);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_eye_ray_corner,
        v68,
        lod->m_context->m_eye_rays);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        lod->m_c_near_far,
        (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
        (const vostok::math::float3 *)&lod->m_context->m_near_far_invn_invf);
      goto LABEL_76;
    case 6:
      v76 = vostok::render::speedtree_tree_component::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v76->m_effects[22].m_object->__vftable);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v77 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 1476);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_position,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        &light_position);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_direction,
        v77,
        &light_direction);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v78 = sinf(la->spot_penumbra_angle * 0.5);
      v79 = lod->m_c_light_range;
      *(float *)src_ptr = umbra_half_angle_cosine / v78;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        v79,
        v77,
        (const vostok::math::float3 *)src_ptr);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_attenuation_power,
        v77,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      *(float *)src_ptr = cosf(la->spot_penumbra_angle * 0.5);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_spot_penumbra_half_angle_cosine,
        v77,
        (const vostok::math::float3 *)src_ptr);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      umbra_half_angle_cosine = cosf(la->spot_umbra_angle * 0.5);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_spot_umbra_half_angle_cosine,
        v77,
        (const vostok::math::float3 *)&umbra_half_angle_cosine);
      v80 = umbra_half_angle_cosine;
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v81 = v80 - *(float *)src_ptr;
      if ( v81 <= 0.000099999997 )
        v81 = FLOAT_0_000099999997;
      v82 = lod->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      *(float *)src_ptr = *(float *)&clear_value / v81;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        v82,
        v77,
        (const vostok::math::float3 *)src_ptr);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_spot_falloff,
        v77,
        (const vostok::math::float3 *)&la->spot_falloff);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      v83 = (const vostok::math::float3 *)vostok::math::operator*(&v104, &la->m_plane_spot_xform, &lod->m_context->m_v);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_local_to_world,
        v77,
        v83);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_color,
        v77,
        &light_color);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_intensity,
        v77,
        (const vostok::math::float3 *)&la->intensity);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_lighting_model,
        v77,
        (const vostok::math::float3 *)&la->lighting_model);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_eye_ray_corner,
        v77,
        lod->m_context->m_eye_rays);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        lod->m_c_near_far,
        (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
        (const vostok::math::float3 *)&lod->m_context->m_near_far_invn_invf);
LABEL_76:
      ++*((_DWORD *)m_conflicted_key_name + 23);
LABEL_77:
      m_object = lod->m_context->m_scene_view.m_object;
      light_direction = *(vostok::math::float3 *)&m_object[1].m_fat_it.m_link_target;
      v85 = *((_DWORD *)&m_object[1].m_memory_type_data + 1);
      m_far_fog_color_and_distance = lod->m_far_fog_color_and_distance;
      v100 = v85;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        m_far_fog_color_and_distance,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        &light_direction);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_near_fog_distance,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&lod->m_context->m_scene_view.m_object[1].vostok::resources::unmanaged_intrusive_base);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_color,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        &light_color);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&v7->intensity);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&v7->lighting_model);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_diffuse_influence_factor,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&v7->diffuse_influence_factor);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_specular_influence_factor,
        (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
        (const vostok::math::float3 *)&v7->specular_influence_factor);
      ++*((_DWORD *)m_conflicted_key_name + 23);
      p_m_speedtree_wind_parameters = &lod->m_context->m_scene->m_speedtree_forest->m_speedtree_wind_parameters;
      Wind = SpeedTree::CCore::GetWind(&l->m_parent->SpeedTree::CCore);
      vostok::render::speedtree_wind_parameters::set(p_m_speedtree_wind_parameters, Wind);
      vostok::render::speedtree_common_parameters::set(
        &lod->m_context->m_scene->m_speedtree_forest->m_speedtree_common_parameters,
        lod->m_context,
        l,
        (const vostok::math::float3 *)&lod->m_context->m_v_inverted.lines[3]);
      v89 = v7->flags;
      v90 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *(_DWORD *)src_ptr = *(_BYTE *)&v89 & 0xF;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        lod->m_c_light_type,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        (const vostok::math::float3 *)src_ptr);
      ++*((_DWORD *)v90 + 23);
      if ( instance_lod )
      {
        v91 = lod->m_context;
        instance_transform = vostok::render::speedtree_forest::get_instance_transform(
                               instance_lod,
                               (int)v91->m_scene->m_speedtree_forest,
                               &v104,
                               v96);
        vostok::render::renderer_context::set_w(v91, instance_transform);
      }
      else
      {
        v93 = vostok::math::float4x4::identity(&v104);
        vostok::render::renderer_context::set_w(lod->m_context, v93);
      }
      if ( l->get_geometry_type(l) == GEOMETRY_TYPE_NUM_3D_TYPES )
      {
        v94 = (unsigned int)lod->m_context;
        v95 = (vostok::render::speedtree_billboard_parameters *)(*(_DWORD *)(*(_DWORD *)(v94 + 12388) + 952) + 44);
        vostok::render::speedtree_billboard_parameters::set(
          v95,
          (vostok::render::renderer_context *)v95,
          (vostok::render::speedtree_tree_component *)v94);
        vostok::render::res_geometry::apply(l->m_render_geometry.geom.m_object);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          l->m_render_geometry.index_count,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      else
      {
        vostok::render::speedtree_tree_parameters::set(
          &lod->m_context->m_scene->m_speedtree_forest->m_speedtree_tree_parameters,
          l,
          (const SpeedTree::CInstance *)instance_lod,
          tree_component);
        vostok::render::res_geometry::apply(l->m_render_geometry.geom.m_object);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          instance->num_indices,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          instance->start_index,
          0);
      }
      return;
  }
}
