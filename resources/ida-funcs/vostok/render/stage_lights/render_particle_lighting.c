void __thiscall vostok::render::stage_lights::render_particle_lighting(
        vostok::render::stage_lights *this,
        vostok::render::stage_lights *instance,
        vostok::render::render_particle_emitter_instance *l,
        vostok::render::light *num_particles,
        vostok::render::render_particle_emitter_instance *num_particlesa)
{
  vostok::render::light *v5; // esi
  float z; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float v9; // xmm0_4
  vostok::render::renderer_context *m_context; // eax
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  vostok::render::light::light_flags flags; // ecx
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  vostok::render::material_effects *material_effects; // eax
  vostok::particle::enum_particle_screen_alignment m_c_light_position; // eax
  const char *m_conflicted_key_name; // edi
  int v26; // ecx
  unsigned int m_c_light_range; // eax
  const char *p_m_current; // ebx
  int v29; // ecx
  __int16 v30; // dx
  float v31; // edi
  vostok::render::material_effects *v32; // eax
  vostok::particle::enum_particle_screen_alignment v33; // eax
  vostok::render::constants_handler<1> *v34; // edi
  int v35; // ecx
  unsigned int m_c_light_direction; // eax
  int v37; // ecx
  __int16 v38; // dx
  unsigned int v39; // eax
  int v40; // ecx
  __int16 v41; // dx
  float v42; // eax
  int v43; // ecx
  __int16 v44; // dx
  long double v45; // st7
  long double v46; // st7
  float v47; // xmm0_4
  float v48; // eax
  int v49; // ecx
  int v50; // ecx
  float v51; // eax
  vostok::render::material_effects *v52; // eax
  vostok::particle::enum_particle_screen_alignment v53; // eax
  vostok::render::constants_handler<1> *v54; // edi
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // ecx
  __int16 v58; // dx
  const vostok::render::shader_constant_host *m_c_light_attenuation_power; // eax
  vostok::render::shader_constant_host *m_c_light_local_to_world; // eax
  const char *v61; // edi
  int m_buffer_index; // ecx
  vostok::particle::enum_particle_vertex_type m_c_light_color; // eax
  int v64; // ecx
  float v65; // esi
  vostok::render::material_effects *v66; // eax
  vostok::particle::enum_particle_screen_alignment v67; // eax
  const char *v68; // edi
  int v69; // ecx
  unsigned int v70; // eax
  int v71; // ecx
  __int16 v72; // dx
  unsigned int v73; // eax
  int v74; // ecx
  __int16 v75; // dx
  float v76; // edx
  vostok::particle::enum_particle_vertex_type v77; // eax
  int v78; // ecx
  __int16 v79; // dx
  float v80; // edx
  float v81; // ecx
  vostok::render::render_particle_emitter_instance *v82; // ecx
  vostok::render::material_effects *v83; // eax
  unsigned int v84; // edi
  float v85; // eax
  const vostok::math::float4x4 *v86; // eax
  const vostok::math::float3 *v87; // eax
  unsigned int v88; // eax
  int v89; // edx
  vostok::render::material_effects *v90; // eax
  const char *v91; // ebx
  vostok::render::material_effects *v92; // eax
  const char *v93; // ebx
  long double v94; // st7
  const vostok::render::shader_constant_host *v95; // eax
  float v96; // xmm0_4
  float v97; // xmm0_4
  float v98; // eax
  const vostok::math::float3 *v99; // eax
  vostok::render::light::light_flags v100; // edx
  const vostok::math::float4 *m_c_light_type; // eax
  float v102; // esi
  vostok::math::float3 *v103; // ebx
  vostok::math::float3 *v104; // eax
  float v105; // ecx
  __int64 v106; // xmm0_8
  vostok::particle::enum_particle_locked_axis v107; // edx
  __int64 v108; // xmm0_8
  float v109; // edx
  __int64 v110; // xmm0_8
  float v111; // eax
  vostok::math::float3 v112; // [esp-2Ch] [ebp-174h] BYREF
  vostok::math::float3 v113; // [esp-20h] [ebp-168h]
  vostok::math::float3 v114; // [esp-14h] [ebp-15Ch]
  vostok::particle::enum_particle_locked_axis v115; // [esp-8h] [ebp-150h]
  float v116; // [esp-4h] [ebp-14Ch]
  float _X; // [esp+0h] [ebp-148h]
  vostok::math::float3 arg; // [esp+14h] [ebp-134h] BYREF
  vostok::math::float3 light_direction; // [esp+20h] [ebp-128h] BYREF
  vostok::math::float3 light_color; // [esp+2Ch] [ebp-11Ch] BYREF
  vostok::math::float3 light_position; // [esp+38h] [ebp-110h] BYREF
  vostok::math::float4x4 obb_world; // [esp+44h] [ebp-104h] BYREF
  vostok::math::float4x4 result; // [esp+84h] [ebp-C4h] BYREF
  vostok::math::float4x4 v124; // [esp+C4h] [ebp-84h] BYREF
  vostok::math::float4x4 v125; // [esp+104h] [ebp-44h] BYREF

  v5 = num_particles;
  z = num_particles->color.z;
  y = num_particles->position.y;
  x = num_particles->position.x;
  arg.z = num_particles->range;
  *(_QWORD *)&light_color.x = *(_QWORD *)&num_particles->color.x;
  v9 = num_particles->position.z;
  light_color.z = z;
  m_context = instance->m_context;
  v11 = m_context->m_v.k.y;
  light_position.x = (float)((float)((float)(m_context->m_v.j.x * y) + (float)(m_context->m_v.k.x * v9))
                           + (float)(x * m_context->m_v.i.x))
                   + m_context->m_v.c.x;
  v12 = (float)((float)((float)(m_context->m_v.j.y * y) + (float)(v11 * v9)) + (float)(m_context->m_v.i.y * x))
      + m_context->m_v.c.y;
  v13 = m_context->m_v.k.x;
  light_position.y = v12;
  flags = num_particles->flags;
  v15 = (float)(m_context->m_v.j.z * y) + (float)(m_context->m_v.k.z * v9);
  v16 = num_particles->direction.y;
  v17 = m_context->m_v.i.z * x;
  v18 = num_particles->direction.x;
  v19 = (float)(v15 + v17) + m_context->m_v.c.z;
  v20 = num_particles->direction.z;
  light_position.z = v19;
  v21 = (float)((float)(m_context->m_v.j.x * v16) + (float)(v13 * v20)) + (float)(v18 * m_context->m_v.i.x);
  v22 = m_context->m_v.j.y;
  light_direction.x = v21;
  light_direction.y = (float)((float)(m_context->m_v.i.y * v18) + (float)(v22 * v16))
                    + (float)(m_context->m_v.k.y * v20);
  light_direction.z = (float)((float)(m_context->m_v.i.z * v18) + (float)(m_context->m_v.j.z * v16))
                    + (float)(m_context->m_v.k.z * v20);
  switch ( *(_BYTE *)&flags & 0xF )
  {
    case 0:
      material_effects = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &material_effects->m_effects[22].m_object->__vftable);
      m_c_light_position = (vostok::particle::enum_particle_screen_alignment)instance->m_c_light_position;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(m_c_light_position + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 573) )
      {
        v26 = *(unsigned __int16 *)(m_c_light_position + 20);
        if ( v26 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_position + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_position + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v26),
            (const char *)&light_position);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      m_c_light_range = (unsigned int)instance->m_c_light_range;
      p_m_current = m_conflicted_key_name + 92;
      if ( *(_DWORD *)(m_c_light_range + 40) == *((_DWORD *)m_conflicted_key_name + 573) )
      {
        v29 = *(unsigned __int16 *)(m_c_light_range + 20);
        if ( v29 != 0xFFFF )
        {
          v30 = *(_WORD *)(m_c_light_range + 16);
          arg.x = *(float *)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 371) + 16) + 4 * v29);
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_range + 22),
            (unsigned __int8)v30,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&arg.elements[2]);
        }
      }
      ++*(_DWORD *)p_m_current;
      LODWORD(v31) = m_conflicted_key_name + 1476;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      break;
    case 1:
      v32 = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v32->m_effects[22].m_object->__vftable);
      v33 = (vostok::particle::enum_particle_screen_alignment)instance->m_c_light_position;
      v34 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v33 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v35 = *(unsigned __int16 *)(v33 + 20);
        if ( v35 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v33 + 22),
            (unsigned __int8)*(_WORD *)(v33 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v35),
            (const char *)&light_position);
      }
      ++v34[7].m_current.m_object;
      m_c_light_direction = (unsigned int)instance->m_c_light_direction;
      p_m_current = (const char *)&v34[7].m_current;
      if ( *(_DWORD *)(m_c_light_direction + 40) == v34[191].m_diff_range_start )
      {
        v37 = *(unsigned __int16 *)(m_c_light_direction + 20);
        if ( v37 != 0xFFFF )
        {
          v38 = *(_WORD *)(m_c_light_direction + 16);
          LODWORD(arg.x) = v34[123].m_current.m_object->m_const_buffers._M_impl._M_start[v37].m_object;
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_direction + 22),
            (unsigned __int8)v38,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&light_direction);
        }
      }
      ++*(_DWORD *)p_m_current;
      v39 = (unsigned int)instance->m_c_light_range;
      if ( *(_DWORD *)(v39 + 40) == v34[191].m_diff_range_start )
      {
        v40 = *(unsigned __int16 *)(v39 + 20);
        if ( v40 != 0xFFFF )
        {
          v41 = *(_WORD *)(v39 + 16);
          LODWORD(arg.x) = v34[123].m_current.m_object->m_const_buffers._M_impl._M_start[v40].m_object;
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v39 + 22),
            (unsigned __int8)v41,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&arg.elements[2]);
        }
      }
      ++*(_DWORD *)p_m_current;
      LODWORD(arg.y) = &v34[123];
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        v34 + 123,
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      ++*(_DWORD *)p_m_current;
      arg.z = cosf(num_particles->spot_penumbra_angle * 0.5);
      v42 = *(float *)&instance->m_c_light_spot_penumbra_half_angle_cosine;
      if ( *(_DWORD *)(LODWORD(v42) + 40) == v34[191].m_diff_range_start )
      {
        v43 = *(unsigned __int16 *)(LODWORD(v42) + 20);
        if ( v43 != 0xFFFF )
        {
          v44 = *(_WORD *)(LODWORD(v42) + 16);
          LODWORD(arg.x) = v34[123].m_current.m_object->m_const_buffers._M_impl._M_start[v43].m_object;
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v42) + 22),
            (unsigned __int8)v44,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&arg.elements[2]);
        }
      }
      ++*(_DWORD *)p_m_current;
      v45 = cosf(num_particles->spot_umbra_angle * 0.5);
      v46 = v45 - arg.z;
      arg.x = v46;
      if ( v46 <= 0.000099999997 )
        v47 = FLOAT_0_000099999997;
      else
        v47 = arg.x;
      v48 = *(float *)&instance->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      v49 = *(_DWORD *)(LODWORD(v48) + 40);
      arg.x = *(float *)&clear_value / v47;
      if ( v49 == v34[191].m_diff_range_start )
      {
        v50 = *(unsigned __int16 *)(LODWORD(v48) + 20);
        if ( v50 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(LODWORD(v48) + 22),
            (unsigned __int8)*(_WORD *)(LODWORD(v48) + 16),
            v34[123].m_current.m_object->m_const_buffers._M_impl._M_start[v50].m_object,
            (const char *)&arg);
      }
      v51 = arg.y;
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_spot_falloff,
        (vostok::render::constants_handler<1> *)LODWORD(v51),
        (const vostok::math::float3 *)&num_particles->spot_falloff);
      v31 = arg.y;
      break;
    case 2:
      v52 = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v52->m_effects[22].m_object->__vftable);
      v53 = (vostok::particle::enum_particle_screen_alignment)instance->m_c_light_position;
      v54 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v53 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v55 = *(unsigned __int16 *)(v53 + 20);
        if ( v55 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v53 + 22),
            (unsigned __int8)*(_WORD *)(v53 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v55),
            (const char *)&light_position);
      }
      ++v54[7].m_current.m_object;
      v56 = (unsigned int)instance->m_c_light_range;
      p_m_current = (const char *)&v54[7].m_current;
      if ( *(_DWORD *)(v56 + 40) == v54[191].m_diff_range_start )
      {
        v57 = *(unsigned __int16 *)(v56 + 20);
        if ( v57 != 0xFFFF )
        {
          v58 = *(_WORD *)(v56 + 16);
          LODWORD(arg.x) = v54[123].m_current.m_object->m_const_buffers._M_impl._M_start[v57].m_object;
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v56 + 22),
            (unsigned __int8)v58,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&arg.elements[2]);
        }
      }
      ++*(_DWORD *)p_m_current;
      m_c_light_attenuation_power = instance->m_c_light_attenuation_power;
      LODWORD(arg.y) = &v54[123];
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        m_c_light_attenuation_power,
        v54 + 123,
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      ++*(_DWORD *)p_m_current;
      qmemcpy((void *)&obb_world, &num_particles->m_xform, sizeof(obb_world));
      vostok::math::float4x4::set_scale(&obb_world, &num_particles->scale);
      vostok::math::mul4x3(&result, &obb_world, &instance->m_context->m_v);
      m_c_light_local_to_world = instance->m_c_light_local_to_world;
      v61 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( m_c_light_local_to_world->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                            + 573) )
      {
        m_buffer_index = m_c_light_local_to_world->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_c_light_local_to_world->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_c_light_local_to_world->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * m_buffer_index),
            (const char *)&result);
      }
      ++*(_DWORD *)p_m_current;
      m_c_light_color = (vostok::particle::enum_particle_vertex_type)instance->m_c_light_color;
      if ( *(_DWORD *)(m_c_light_color + 40) == *((_DWORD *)v61 + 573) )
      {
        v64 = *(unsigned __int16 *)(m_c_light_color + 20);
        if ( v64 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(m_c_light_color + 22),
            (unsigned __int8)*(_WORD *)(m_c_light_color + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v61 + 371) + 16) + 4 * v64),
            (const char *)&light_color);
      }
      ++*(_DWORD *)p_m_current;
      v65 = arg.y;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)LODWORD(arg.y),
        (const vostok::math::float3 *)&num_particles->intensity);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)LODWORD(v65),
        (const vostok::math::float3 *)&num_particles->lighting_model);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        (vostok::render::constants_handler<1> *)LODWORD(v65),
        instance->m_context->m_eye_rays);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        instance->m_c_near_far,
        (vostok::render::constants_handler<0> *)(v61 + 196),
        (const vostok::math::float3 *)&instance->m_context->m_near_far_invn_invf);
      v31 = v65;
      v5 = num_particles;
      break;
    case 3:
      v66 = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v66->m_effects[22].m_object->__vftable);
      v67 = (vostok::particle::enum_particle_screen_alignment)instance->m_c_light_position;
      v68 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *(_DWORD *)(v67 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v69 = *(unsigned __int16 *)(v67 + 20);
        if ( v69 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v67 + 22),
            (unsigned __int8)*(_WORD *)(v67 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v69),
            (const char *)&light_position);
      }
      ++*((_DWORD *)v68 + 23);
      v70 = (unsigned int)instance->m_c_light_direction;
      p_m_current = v68 + 92;
      if ( *(_DWORD *)(v70 + 40) == *((_DWORD *)v68 + 573) )
      {
        v71 = *(unsigned __int16 *)(v70 + 20);
        if ( v71 != 0xFFFF )
        {
          v72 = *(_WORD *)(v70 + 16);
          arg.x = *(float *)(*(_DWORD *)(*((_DWORD *)v68 + 371) + 16) + 4 * v71);
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v70 + 22),
            (unsigned __int8)v72,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&light_direction);
        }
      }
      ++*(_DWORD *)p_m_current;
      v73 = (unsigned int)instance->m_c_light_range;
      if ( *(_DWORD *)(v73 + 40) == *((_DWORD *)v68 + 573) )
      {
        v74 = *(unsigned __int16 *)(v73 + 20);
        if ( v74 != 0xFFFF )
        {
          v75 = *(_WORD *)(v73 + 16);
          arg.x = *(float *)(*(_DWORD *)(*((_DWORD *)v68 + 371) + 16) + 4 * v74);
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v73 + 22),
            (unsigned __int8)v75,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&arg.elements[2]);
        }
      }
      ++*(_DWORD *)p_m_current;
      LODWORD(arg.y) = v68 + 1476;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)v68 + 123,
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_capsule_half_width,
        (vostok::render::constants_handler<1> *)v68 + 123,
        (const vostok::math::float3 *)&num_particles->scale.elements[2]);
      v76 = arg.y;
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_capsule_radius,
        (vostok::render::constants_handler<1> *)LODWORD(v76),
        &num_particles->scale);
      ++*(_DWORD *)p_m_current;
      v77 = (vostok::particle::enum_particle_vertex_type)instance->m_c_light_color;
      if ( *(_DWORD *)(v77 + 40) == *((_DWORD *)v68 + 573) )
      {
        v78 = *(unsigned __int16 *)(v77 + 20);
        if ( v78 != 0xFFFF )
        {
          v79 = *(_WORD *)(v77 + 16);
          arg.x = *(float *)(*(_DWORD *)(*((_DWORD *)v68 + 371) + 16) + 4 * v78);
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v77 + 22),
            (unsigned __int8)v79,
            (vostok::render::shader_constant_buffer *)LODWORD(arg.x),
            (const char *)&light_color);
        }
      }
      v80 = arg.y;
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)LODWORD(v80),
        (const vostok::math::float3 *)&num_particles->intensity);
      v81 = arg.y;
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)LODWORD(v81),
        (const vostok::math::float3 *)&num_particles->lighting_model);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        (vostok::render::constants_handler<1> *)LODWORD(arg.y),
        instance->m_context->m_eye_rays);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        instance->m_c_near_far,
        (vostok::render::constants_handler<0> *)(v68 + 196),
        (const vostok::math::float3 *)&instance->m_context->m_near_far_invn_invf);
      v31 = arg.y;
      break;
    case 4:
      if ( !vostok::render::render_particle_emitter_instance::get_material_effects(l)->m_effects[22].m_object
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        return;
      }
      v83 = vostok::render::render_particle_emitter_instance::get_material_effects(v82);
      vostok::render::res_effect::apply(0, &v83->m_effects[22].m_object->__vftable);
      v84 = 0;
      LODWORD(arg.y) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1476;
      p_m_current = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 92;
      do
      {
        v85 = *(float *)&instance->m_context;
        switch ( v84 )
        {
          case 1u:
            v86 = (const vostok::math::float4x4 *)(LODWORD(v85) + 16580);
            break;
          case 2u:
            v86 = (const vostok::math::float4x4 *)(LODWORD(v85) + 16644);
            break;
          case 3u:
            v86 = (const vostok::math::float4x4 *)(LODWORD(v85) + 16708);
            break;
          default:
            v86 = (const vostok::math::float4x4 *)(LODWORD(v85) + 16516);
            break;
        }
        v87 = (const vostok::math::float3 *)vostok::math::transpose(&v124, v86);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          instance->m_shadow[v84],
          (vostok::render::constants_handler<1> *)LODWORD(arg.y),
          v87);
        ++*(_DWORD *)p_m_current;
        ++v84;
      }
      while ( v84 < 4 );
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_shadow_transparency,
        (vostok::render::constants_handler<1> *)LODWORD(arg.y),
        (const vostok::math::float3 *)&num_particles->shadow_transparency);
      ++*(_DWORD *)p_m_current;
      v88 = (unsigned int)instance->m_c_light_direction;
      if ( *(_DWORD *)(v88 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                    + 573) )
      {
        v89 = *(unsigned __int16 *)(v88 + 20);
        if ( v89 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            *(unsigned __int16 *)(v88 + 22),
            (unsigned __int8)*(_WORD *)(v88 + 16),
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v89),
            (const char *)&light_direction);
      }
      v31 = arg.y;
      break;
    case 5:
      v90 = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v90->m_effects[22].m_object->__vftable);
      v91 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      LODWORD(v31) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1476;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_position,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        &light_position);
      ++*((_DWORD *)v91 + 23);
      p_m_current = v91 + 92;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_range,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (vostok::math::float3 *)&arg.elements[2]);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_sphere_radius,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &num_particles->scale);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_color,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &light_color);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->intensity);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->lighting_model);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        instance->m_context->m_eye_rays);
      ++*(_DWORD *)p_m_current;
      LODWORD(_X) = &instance->m_context->m_near_far_invn_invf;
      LODWORD(v116) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 196;
      goto LABEL_71;
    case 6:
      v92 = vostok::render::render_particle_emitter_instance::get_material_effects(l);
      vostok::render::res_effect::apply(0, &v92->m_effects[22].m_object->__vftable);
      v93 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      LODWORD(v31) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1476;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_position,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        &light_position);
      ++*((_DWORD *)v93 + 23);
      p_m_current = v93 + 92;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_direction,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &light_direction);
      ++*(_DWORD *)p_m_current;
      v94 = sinf(num_particles->spot_penumbra_angle * 0.5);
      v95 = instance->m_c_light_range;
      arg.x = arg.z / v94;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        v95,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &arg);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_attenuation_power,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->attenuation_power);
      ++*(_DWORD *)p_m_current;
      arg.x = cosf(num_particles->spot_penumbra_angle * 0.5);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_spot_penumbra_half_angle_cosine,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &arg);
      ++*(_DWORD *)p_m_current;
      arg.z = cosf(num_particles->spot_umbra_angle * 0.5);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_spot_umbra_half_angle_cosine,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (vostok::math::float3 *)&arg.elements[2]);
      v96 = arg.z;
      ++*(_DWORD *)p_m_current;
      v97 = v96 - arg.x;
      if ( v97 <= 0.000099999997 )
        v97 = FLOAT_0_000099999997;
      _X = COERCE_FLOAT(&arg);
      v98 = *(float *)&instance->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine;
      arg.x = *(float *)&clear_value / v97;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        (const vostok::render::shader_constant_host *)LODWORD(v98),
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &arg);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_spot_falloff,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->spot_falloff);
      ++*(_DWORD *)p_m_current;
      v99 = (const vostok::math::float3 *)vostok::math::operator*(
                                            &v125,
                                            &num_particles->m_plane_spot_xform,
                                            &instance->m_context->m_v);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_local_to_world,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        v99);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_color,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        &light_color);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_light_intensity,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->intensity);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_lighting_model,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        (const vostok::math::float3 *)&num_particles->lighting_model);
      ++*(_DWORD *)p_m_current;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        instance->m_c_eye_ray_corner,
        (vostok::render::constants_handler<1> *)LODWORD(v31),
        instance->m_context->m_eye_rays);
      ++*(_DWORD *)p_m_current;
      LODWORD(_X) = &instance->m_context->m_near_far_invn_invf;
      LODWORD(v116) = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 196;
LABEL_71:
      vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
        instance->m_c_near_far,
        (vostok::render::constants_handler<0> *)LODWORD(v116),
        (const vostok::math::float3 *)LODWORD(_X));
      break;
  }
  ++*(_DWORD *)p_m_current;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_light_color,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    &light_color);
  ++*(_DWORD *)p_m_current;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_light_intensity,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    (const vostok::math::float3 *)&v5->intensity);
  ++*(_DWORD *)p_m_current;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_lighting_model,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    (const vostok::math::float3 *)&v5->lighting_model);
  ++*(_DWORD *)p_m_current;
  v100 = v5->flags;
  _X = COERCE_FLOAT(&arg);
  m_c_light_type = (const vostok::math::float4 *)instance->m_c_light_type;
  LODWORD(arg.x) = *(_BYTE *)&v100 & 0xF;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)m_c_light_type,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    &arg);
  ++*(_DWORD *)p_m_current;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_diffuse_influence_factor,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    (const vostok::math::float3 *)&v5->diffuse_influence_factor);
  ++*(_DWORD *)p_m_current;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    instance->m_c_specular_influence_factor,
    (vostok::render::constants_handler<1> *)LODWORD(v31),
    (const vostok::math::float3 *)&v5->specular_influence_factor);
  ++*(_DWORD *)p_m_current;
  v102 = *(float *)&instance->m_context;
  light_color.x = (float)((float)(*(float *)(LODWORD(v102) + 15780) + *(float *)(LODWORD(v102) + 15764)) * 0.0)
                + (float)(*(float *)(LODWORD(v102) + 15748) * 1000.0);
  light_color.y = (float)((float)(*(float *)(LODWORD(v102) + 15784) + *(float *)(LODWORD(v102) + 15768)) * 0.0)
                + (float)(*(float *)(LODWORD(v102) + 15752) * 1000.0);
  light_color.z = (float)((float)(*(float *)(LODWORD(v102) + 15788) + *(float *)(LODWORD(v102) + 15772)) * 0.0)
                + (float)(*(float *)(LODWORD(v102) + 15756) * 1000.0);
  light_direction.x = (float)((float)(*(float *)(LODWORD(v102) + 15780) + *(float *)(LODWORD(v102) + 15748)) * 0.0)
                    + (float)(*(float *)(LODWORD(v102) + 15764) * 1000.0);
  light_direction.y = (float)((float)(*(float *)(LODWORD(v102) + 15784) + *(float *)(LODWORD(v102) + 15752)) * 0.0)
                    + (float)(*(float *)(LODWORD(v102) + 15768) * 1000.0);
  light_direction.z = (float)((float)(*(float *)(LODWORD(v102) + 15788) + *(float *)(LODWORD(v102) + 15756)) * 0.0)
                    + (float)(*(float *)(LODWORD(v102) + 15772) * 1000.0);
  v103 = vostok::math::float3_pod::normalize(&light_color);
  v104 = vostok::math::float3_pod::normalize(&light_direction);
  v105 = *(float *)&l->m_locked_axis;
  v106 = *(_QWORD *)(LODWORD(v102) + 15796);
  _X = *(float *)&l->m_screen_alignment;
  v107 = *(_DWORD *)(LODWORD(v102) + 15804);
  v116 = v105;
  *(_QWORD *)&v114.elements[1] = v106;
  v108 = *(_QWORD *)&v103->x;
  v115 = v107;
  v109 = v103->z;
  *(_QWORD *)&v113.elements[1] = v108;
  v110 = *(_QWORD *)&v104->x;
  v111 = v104->z;
  v114.x = v109;
  *(_QWORD *)&v112.elements[1] = v110;
  v112.x = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
  v113.x = v111;
  vostok::render::particle_shader_constants::set(
    (vostok::render::particle_shader_constants *)&v112.elements[1],
    v112,
    v113,
    v114,
    v115,
    SLODWORD(v105));
  vostok::render::particle_shader_constants::set_time(
    (vostok::render::particle_shader_constants *)instance->m_context,
    instance->m_context->m_current_time);
  vostok::render::renderer_context::set_w(instance->m_context, &l->m_transform);
  vostok::render::render_particle_emitter_instance::render(
    num_particlesa,
    (const vostok::math::float3 *)&instance->m_context->m_v_inverted.lines[3],
    l);
}
