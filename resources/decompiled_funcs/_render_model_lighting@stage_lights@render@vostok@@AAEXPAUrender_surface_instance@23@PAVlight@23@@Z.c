void __thiscall vostok::render::stage_lights::render_model_lighting(
        vostok::render::stage_lights *this,
        vostok::render::stage_lights *instance,
        vostok::render::render_surface_instance *l,
        vostok::render::light *la)
{
  vostok::render::light *v4; // edi
  float z; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  __int64 v8; // xmm0_8
  vostok::math::float4x4 *m_context; // eax
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  vostok::render::light *v16; // edx
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float w; // xmm1_4
  unsigned int m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // eax
  int v30; // ecx
  unsigned int m_c_light_position; // eax
  vostok::render::backend *m_conflicted_key_name; // ebx
  int v33; // ecx
  vostok::render::shader_constant_host *m_c_light_range; // eax
  int m_buffer_index; // ecx
  unsigned int v36; // eax
  int v37; // ecx
  float v38; // eax
  int v39; // ecx
  vostok::render::shader_constant_host *v40; // eax
  int v41; // ecx
  vostok::render::render_surface *m_c_light_spot_penumbra_half_angle_cosine; // eax
  int x_low; // ecx
  long double v44; // st7
  long double v45; // st7
  float v46; // xmm0_4
  vostok::render::render_model_instance_impl *m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine; // eax
  unsigned int m_lock; // edx
  int v49; // ecx
  unsigned int v50; // eax
  int v51; // ecx
  vostok::render::shader_constant_host *v52; // eax
  int v53; // ecx
  vostok::render::render_surface *m_c_light_local_to_world; // eax
  int v55; // ecx
  vostok::math::float4x4 *m_c_light_color; // eax
  int v57; // ecx
  unsigned int v58; // eax
  int v59; // ecx
  float v60; // eax
  int v61; // ecx
  vostok::render::shader_constant_host *v62; // eax
  int v63; // ecx
  vostok::math::float4x4 *v64; // eax
  int v65; // ecx
  __int16 v66; // dx
  _DWORD *v67; // eax
  vostok::render::renderer_context *v68; // esi
  const vostok::math::float4x4 *view2shadow; // eax
  const vostok::math::float3 *v70; // eax
  float v71; // eax
  int v72; // ecx
  vostok::render::backend *v73; // esi
  long double v74; // st7
  float v75; // xmm0_4
  const vostok::math::float3 *v76; // eax
  float v77; // eax
  int v78; // xmm0_4
  vostok::render::render_surface *m_far_fog_color_and_distance; // eax
  vostok::render::render_surface *m_c_light_type; // eax
  const vostok::render::shader_constant_host *_X; // [esp+0h] [ebp-144h]
  vostok::render::render_model_instance_impl *_Xa; // [esp+0h] [ebp-144h]
  unsigned int v83; // [esp+4h] [ebp-140h]
  float umbra_half_angle_cosine; // [esp+14h] [ebp-130h] BYREF
  char src_ptr[4]; // [esp+18h] [ebp-12Ch] BYREF
  vostok::math::float3 light_position; // [esp+1Ch] [ebp-128h] BYREF
  vostok::math::float3 light_direction; // [esp+28h] [ebp-11Ch] BYREF
  int v88; // [esp+34h] [ebp-110h]
  vostok::math::float3 light_color; // [esp+38h] [ebp-10Ch] BYREF
  vostok::math::float4x4 obb_world; // [esp+44h] [ebp-100h] BYREF
  vostok::math::float4x4 result; // [esp+84h] [ebp-C0h] BYREF
  vostok::math::float4x4 v92; // [esp+C4h] [ebp-80h] BYREF
  vostok::math::float4x4 v93; // [esp+104h] [ebp-40h] BYREF

  v4 = la;
  z = la->color.z;
  y = la->position.y;
  x = la->position.x;
  umbra_half_angle_cosine = la->range;
  v8 = *(_QWORD *)&la->color.x;
  light_color.z = z;
  m_context = (vostok::math::float4x4 *)instance->m_context;
  v10 = m_context[244].k.y;
  v11 = m_context[244].j.y * y;
  *(_QWORD *)&light_color.x = v8;
  *(float *)&v8 = la->position.z;
  v12 = (float)((float)(v11 + (float)(v10 * *(float *)&v8)) + (float)(x * m_context[244].i.y)) + m_context[244].c.y;
  v13 = m_context[244].j.z;
  light_position.x = v12;
  v14 = (float)((float)((float)(m_context[244].i.z * x) + (float)(v13 * y)) + (float)(m_context[244].k.z * *(float *)&v8))
      + m_context[244].c.z;
  v15 = m_context[244].k.y;
  light_position.y = v14;
  v16 = (vostok::render::light *)l;
  v17 = (float)(m_context[244].i.w * x) + (float)(m_context[244].j.w * y);
  v18 = la->direction.x;
  v19 = m_context[244].k.w * *(float *)&v8;
  *(float *)&v8 = la->direction.z;
  v20 = (float)(v17 + v19) + m_context[244].c.w;
  v21 = la->direction.y;
  light_position.z = v20;
  v22 = (float)((float)(m_context[244].j.y * v21) + (float)(v15 * *(float *)&v8)) + (float)(m_context[244].i.y * v18);
  v23 = m_context[244].j.z;
  light_direction.x = v22;
  light_direction.y = (float)((float)(m_context[244].i.z * v18) + (float)(v23 * v21))
                    + (float)(m_context[244].k.z * *(float *)&v8);
  v24 = m_context[244].i.w * v18;
  v25 = m_context[244].j.w * v21;
  w = m_context[244].k.w;
  m_render_surface = (unsigned int)l->m_render_surface;
  m_object = l->m_render_surface->m_materail_effects_instance.m_object;
  light_direction.z = (float)(v24 + v25) + (float)(w * *(float *)&v8);
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[*(_DWORD *)(m_render_surface + 4)];
  else
    p_m_material_effects = &m_object->m_material_effects;
  if ( p_m_material_effects->is_organic )
  {
    v30 = *(_DWORD *)&la->flags & 0xF;
    if ( v30 == 1 )
    {
      if ( vostok::render::light::is_cast_shadows((vostok::render::light *)1, (int)la) )
      {
        if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
             + 267) )
        {
          vostok::render::stage_lights::make_spot_light_shadowmap(la, COERCE_FLOAT(1), instance, v83);
          v16 = (vostok::render::light *)l;
        }
      }
      goto LABEL_10;
    }
    if ( !v30 || v30 == 4 )
    {
LABEL_10:
      vostok::render::stage_lights::make_skin_scattering_texture((int)la, instance, *(float *)&v16);
      return;
    }
  }
  switch ( *(_DWORD *)&la->flags & 0xF )
  {
    case 0:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      m_c_light_position = (unsigned int)instance->m_c_light_position;
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(m_c_light_position + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 573) )
      {
        v33 = *(unsigned __int16 *)(m_c_light_position + 20);
        if ( v33 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_position + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_position + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v33),
            (const char *)&light_position);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      m_c_light_range = instance->m_c_light_range;
      if ( m_c_light_range->m_update_markers[1] == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        m_buffer_index = m_c_light_range->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_c_light_range->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_c_light_range->m_shader_slots[1].m_class_id,
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
            (const char *)&umbra_half_angle_cosine);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++m_conflicted_key_name->num_setted_shader_constants;
      break;
    case 1:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      v36 = (unsigned int)instance->m_c_light_position;
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
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
      ++m_conflicted_key_name->num_setted_shader_constants;
      v38 = *(float *)&instance->m_c_light_direction;
      if ( *(_DWORD *)(LODWORD(v38) + 40) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v39 = *(unsigned __int16 *)(LODWORD(v38) + 20);
        if ( v39 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v38) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v38) + 16),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v39].m_object,
            (const char *)&light_direction);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      v40 = instance->m_c_light_range;
      if ( v40->m_update_markers[1] == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v41 = v40->m_shader_slots[1].m_buffer_index;
        if ( v41 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v40->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v40->m_shader_slots[1].m_class_id,
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v41].m_object,
            (const char *)&umbra_half_angle_cosine);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++m_conflicted_key_name->num_setted_shader_constants;
      umbra_half_angle_cosine = cosf(la->spot_penumbra_angle * 0.5);
      m_c_light_spot_penumbra_half_angle_cosine = (vostok::render::render_surface *)instance->m_c_light_spot_penumbra_half_angle_cosine;
      if ( LODWORD(m_c_light_spot_penumbra_half_angle_cosine->m_bounding_sphere.vector.z) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        x_low = LOWORD(m_c_light_spot_penumbra_half_angle_cosine->m_aabbox.max.x);
        if ( x_low != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            HIWORD(m_c_light_spot_penumbra_half_angle_cosine->m_aabbox.max.elements[0]),
            (unsigned __int8)LOWORD(m_c_light_spot_penumbra_half_angle_cosine->m_aabbox.min.elements[2]),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[x_low].m_object,
            (const char *)&umbra_half_angle_cosine);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      v44 = cosf(la->spot_umbra_angle * 0.5);
      v45 = v44 - umbra_half_angle_cosine;
      *(float *)src_ptr = v45;
      if ( v45 <= 0.000099999997 )
        v46 = FLOAT_0_000099999997;
      else
        v46 = *(float *)src_ptr;
      m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = (vostok::render::render_model_instance_impl *)instance->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      m_lock = m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_children_resources.m_lock;
      *(float *)src_ptr = *(float *)&clear_value / v46;
      if ( m_lock == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v49 = WORD2(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_reconstruction_info_actuality_tick);
        if ( v49 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            HIWORD(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_reconstruction_info_actuality_tick),
            (unsigned __int8)LOWORD(m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine->m_reconstruction_info_actuality_tick),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v49].m_object,
            src_ptr);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_spot_falloff,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->spot_falloff);
      ++m_conflicted_key_name->num_setted_shader_constants;
      break;
    case 2:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      v50 = (unsigned int)instance->m_c_light_position;
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v50 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v51 = *(unsigned __int16 *)(v50 + 20);
        if ( v51 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v50 + 22),
            (unsigned __int8)*(_WORD *)(v50 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v51),
            (const char *)&light_position);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      v52 = instance->m_c_light_range;
      if ( v52->m_update_markers[1] == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v53 = v52->m_shader_slots[1].m_buffer_index;
        if ( v53 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v52->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v52->m_shader_slots[1].m_class_id,
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v53].m_object,
            (const char *)&umbra_half_angle_cosine);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++m_conflicted_key_name->num_setted_shader_constants;
      qmemcpy((void *)&obb_world, &la->m_xform, sizeof(obb_world));
      vostok::math::float4x4::set_scale(&obb_world, &la->scale);
      vostok::math::mul4x3(&result, &obb_world, &instance->m_context->m_v);
      m_c_light_local_to_world = (vostok::render::render_surface *)instance->m_c_light_local_to_world;
      if ( LODWORD(m_c_light_local_to_world->m_bounding_sphere.vector.z) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v55 = LOWORD(m_c_light_local_to_world->m_aabbox.max.x);
        if ( v55 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            HIWORD(m_c_light_local_to_world->m_aabbox.max.elements[0]),
            (unsigned __int8)LOWORD(m_c_light_local_to_world->m_aabbox.min.elements[2]),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v55].m_object,
            (const char *)&result);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      m_c_light_color = (vostok::math::float4x4 *)instance->m_c_light_color;
      if ( LODWORD(m_c_light_color->k.z) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v57 = LOWORD(m_c_light_color->lines[1].elements[1]);
        if ( v57 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            HIWORD(m_c_light_color->lines[1].elements[1]),
            (unsigned __int8)LOWORD(m_c_light_color->lines[1].x),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v57].m_object,
            (const char *)&light_color);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->intensity);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->lighting_model);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        &m_conflicted_key_name->m_ps_constants_handler,
        instance->m_context->m_eye_rays);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        instance->m_c_near_far,
        &m_conflicted_key_name->m_vs_constants_handler,
        (const vostok::math::float3 *)&instance->m_context->m_near_far_invn_invf);
      ++m_conflicted_key_name->num_setted_shader_constants;
      v4 = la;
      break;
    case 3:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      v58 = (unsigned int)instance->m_c_light_position;
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v58 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v59 = *(unsigned __int16 *)(v58 + 20);
        if ( v59 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v58 + 22),
            (unsigned __int8)*(_WORD *)(v58 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v59),
            (const char *)&light_position);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      v60 = *(float *)&instance->m_c_light_direction;
      if ( *(_DWORD *)(LODWORD(v60) + 40) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v61 = *(unsigned __int16 *)(LODWORD(v60) + 20);
        if ( v61 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v60) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v60) + 16),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v61].m_object,
            (const char *)&light_direction);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      v62 = instance->m_c_light_range;
      if ( v62->m_update_markers[1] == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v63 = v62->m_shader_slots[1].m_buffer_index;
        if ( v63 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v62->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v62->m_shader_slots[1].m_class_id,
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v63].m_object,
            (const char *)&umbra_half_angle_cosine);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->attenuation_power);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_capsule_half_width,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->scale.elements[2]);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_capsule_radius,
        &m_conflicted_key_name->m_ps_constants_handler,
        &la->scale);
      ++m_conflicted_key_name->num_setted_shader_constants;
      v64 = (vostok::math::float4x4 *)instance->m_c_light_color;
      if ( LODWORD(v64->k.z) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v65 = LOWORD(v64->lines[1].elements[1]);
        if ( v65 != 0xFFFF )
        {
          v66 = LOWORD(v64->lines[1].x);
          *(float *)src_ptr = *(float *)&m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v65].m_object;
          vostok::render::shader_constant_buffer::set_memory(
            HIWORD(v64->lines[1].elements[1]),
            (unsigned __int8)v66,
            *(vostok::render::shader_constant_buffer **)src_ptr,
            (const char *)&light_color);
        }
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->intensity);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->lighting_model);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        &m_conflicted_key_name->m_ps_constants_handler,
        instance->m_context->m_eye_rays);
      ++m_conflicted_key_name->num_setted_shader_constants;
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        instance->m_c_near_far,
        &m_conflicted_key_name->m_vs_constants_handler,
        (const vostok::math::float3 *)&instance->m_context->m_near_far_invn_invf);
      ++m_conflicted_key_name->num_setted_shader_constants;
      break;
    case 4:
      v67 = &p_m_material_effects->m_effects[22].m_object->__vftable;
      if ( !v67
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        return;
      }
      vostok::render::res_effect::apply(0, v67);
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v68 = 0;
      LODWORD(umbra_half_angle_cosine) = instance->m_shadow;
      do
      {
        view2shadow = vostok::render::renderer_context::get_view2shadow(v68, v83);
        v70 = (const vostok::math::float3 *)vostok::math::transpose(&v92, view2shadow);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)LODWORD(umbra_half_angle_cosine),
          &m_conflicted_key_name->m_ps_constants_handler,
          v70);
        ++m_conflicted_key_name->num_setted_shader_constants;
        LODWORD(umbra_half_angle_cosine) += 4;
        v68 = (vostok::render::renderer_context *)((char *)v68 + 1);
      }
      while ( (unsigned int)v68 < 4 );
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_shadow_transparency,
        &m_conflicted_key_name->m_ps_constants_handler,
        (const vostok::math::float3 *)&la->shadow_transparency);
      ++m_conflicted_key_name->num_setted_shader_constants;
      v71 = *(float *)&instance->m_c_light_direction;
      if ( *(_DWORD *)(LODWORD(v71) + 40) == m_conflicted_key_name->m_constant_update_markers[1] )
      {
        v72 = *(unsigned __int16 *)(LODWORD(v71) + 20);
        if ( v72 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v71) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v71) + 16),
            m_conflicted_key_name->m_ps_constants_handler.m_current.m_object->m_const_buffers._M_impl._M_start[v72].m_object,
            (const char *)&light_direction);
      }
      ++m_conflicted_key_name->num_setted_shader_constants;
      break;
    case 5:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v73 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        &light_position,
        instance->m_c_light_position);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&umbra_half_angle_cosine,
        instance->m_c_light_range);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&la->attenuation_power,
        instance->m_c_light_attenuation_power);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        &la->scale,
        instance->m_c_light_sphere_radius);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v73, &light_color, instance->m_c_light_color);
      goto LABEL_78;
    case 6:
      vostok::render::res_effect::apply(0, &p_m_material_effects->m_effects[22].m_object->__vftable);
      m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v73 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        &light_position,
        instance->m_c_light_position);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        &light_direction,
        instance->m_c_light_direction);
      v74 = sinf(la->spot_penumbra_angle * 0.5);
      _X = instance->m_c_light_range;
      *(float *)src_ptr = umbra_half_angle_cosine / v74;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v73, (const vostok::math::float3 *)src_ptr, _X);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&la->attenuation_power,
        instance->m_c_light_attenuation_power);
      *(float *)src_ptr = cosf(la->spot_penumbra_angle * 0.5);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)src_ptr,
        instance->m_c_light_spot_penumbra_half_angle_cosine);
      umbra_half_angle_cosine = cosf(la->spot_umbra_angle * 0.5);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&umbra_half_angle_cosine,
        instance->m_c_light_spot_umbra_half_angle_cosine);
      v75 = umbra_half_angle_cosine - *(float *)src_ptr;
      if ( (float)(umbra_half_angle_cosine - *(float *)src_ptr) <= 0.000099999997 )
        v75 = FLOAT_0_000099999997;
      _Xa = (vostok::render::render_model_instance_impl *)instance->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      *(float *)src_ptr = *(float *)&clear_value / v75;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)src_ptr,
        (const vostok::render::shader_constant_host *)_Xa);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&la->spot_falloff,
        instance->m_c_light_spot_falloff);
      v76 = (const vostok::math::float3 *)vostok::math::operator*(
                                            &v93,
                                            &la->m_plane_spot_xform,
                                            &instance->m_context->m_v);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v73, v76, instance->m_c_light_local_to_world);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(v73, &light_color, instance->m_c_light_color);
LABEL_78:
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&la->intensity,
        instance->m_c_light_intensity);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        (const vostok::math::float3 *)&la->lighting_model,
        instance->m_c_lighting_model);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v73,
        instance->m_context->m_eye_rays,
        instance->m_c_eye_ray_corner);
      vostok::render::backend::set_vs_constant<vostok::math::float4>(
        v73,
        (const vostok::math::float3 *)&instance->m_context->m_near_far_invn_invf,
        instance->m_c_near_far);
      break;
  }
  v77 = *(float *)&instance->m_context->m_scene_view.m_object;
  light_direction = *(vostok::math::float3 *)(LODWORD(v77) + 448);
  v78 = *(_DWORD *)(LODWORD(v77) + 484);
  m_far_fog_color_and_distance = (vostok::render::render_surface *)instance->m_far_fog_color_and_distance;
  v88 = v78;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)m_far_fog_color_and_distance,
    &m_conflicted_key_name->m_ps_constants_handler,
    &light_direction);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_near_fog_distance,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)&instance->m_context->m_scene_view.m_object[1].vostok::resources::unmanaged_intrusive_base);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_light_color,
    &m_conflicted_key_name->m_ps_constants_handler,
    &light_color);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_light_intensity,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)&v4->intensity);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_lighting_model,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)&v4->lighting_model);
  ++m_conflicted_key_name->num_setted_shader_constants;
  m_c_light_type = (vostok::render::render_surface *)instance->m_c_light_type;
  *(_DWORD *)src_ptr = *(_DWORD *)&v4->flags & 0xF;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)m_c_light_type,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)src_ptr);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_diffuse_influence_factor,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)&v4->diffuse_influence_factor);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_specular_influence_factor,
    &m_conflicted_key_name->m_ps_constants_handler,
    (const vostok::math::float3 *)&v4->specular_influence_factor);
  ++m_conflicted_key_name->num_setted_shader_constants;
  vostok::render::backend::render_indexed(
    m_conflicted_key_name,
    3 * l->m_render_surface->m_render_geometry.primitive_count,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
