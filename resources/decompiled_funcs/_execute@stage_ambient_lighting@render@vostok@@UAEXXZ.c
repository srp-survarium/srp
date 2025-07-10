void __thiscall vostok::render::stage_ambient_lighting::execute(vostok::render::stage_ambient_lighting *this)
{
  vostok::render::stage_ambient_lighting *v2; // ecx
  vostok::render::base_scene_view *m_object; // eax
  vostok::render::environment_probe **m_flags; // esi
  vostok::render::environment_probe **v5; // eax
  vostok::render::renderer_context *m_context; // eax
  vostok::render::base_scene_view *v7; // ebx
  const vostok::math::float3 *m_eye_rays; // edx
  const char *m_conflicted_key_name; // eax
  int v10; // esi
  bool v11; // zf
  vostok::math::float3 *v12; // eax
  float v13; // xmm0_4
  float z; // xmm1_4
  vostok::render::res_effect *v15; // eax
  const char *v16; // esi
  vostok::render::shader_constant_host *m_c_skylight_parameters0; // eax
  int v18; // ecx
  float v19; // xmm1_4
  float m_ambient_multiplier; // xmm2_4
  unsigned __int16 m_buffer_index; // cx
  float v22; // xmm1_4
  vostok::render::shader_constant_host *m_c_skylight_parameters1; // eax
  vostok::render::lights_db *v24; // ecx
  vostok::render::light *v25; // edi
  float m_current_satisfaction; // eax
  float v27; // ecx
  float v28; // edx
  vostok::render::constants_handler<1> *v29; // esi
  float v30; // eax
  float v31; // ecx
  vostok::render::shader_constant_host *m_c_skylight_parameters2; // eax
  int v33; // ecx
  float v34; // edx
  unsigned __int16 v35; // cx
  float v36; // xmm0_4
  vostok::render::shader_constant_host *m_c_skylight_parameters3; // eax
  unsigned int m_diff_range_start; // ecx
  unsigned __int16 v39; // cx
  float v40; // xmm0_4
  vostok::render::shader_constant_host *m_c_skylight_parameters4; // eax
  unsigned int v42; // ecx
  unsigned __int16 v43; // cx
  float v44; // xmm0_4
  vostok::render::shader_constant_host *m_c_skylight_parameters5; // eax
  unsigned int v46; // ecx
  unsigned __int16 v47; // cx
  float v48; // xmm0_4
  vostok::math::float3 *p_direction; // eax
  unsigned int v50; // ecx
  float v51; // xmm1_4
  vostok::render::shader_constant_host *m_c_skylight_parameters6; // eax
  unsigned __int16 v53; // cx
  vostok::math::float3 *p_plus_z; // eax
  const vostok::render::shader_constant_table *v55; // ecx
  float v56; // xmm1_4
  vostok::render::shader_constant_host *v57; // eax
  unsigned __int16 v58; // cx
  float intensity; // xmm3_4
  float v60; // xmm2_4
  unsigned int v61; // ecx
  vostok::render::shader_constant_host *m_c_skylight_parameters7; // eax
  unsigned __int16 v63; // cx
  const vostok::math::float3 *v64; // edx
  vostok::render::system_renderer *v65; // ecx
  const char *v66; // esi
  vostok::render::render_target *v67; // eax
  vostok::render::resource_manager *v68; // ecx
  int v69; // ecx
  int v70; // eax
  vostok::render::environment_probe *v71; // edx
  _DWORD *v72; // eax
  ID3D11RenderTargetView *v73; // ebx
  vostok::render::resource_manager *v74; // ecx
  int v75; // eax
  unsigned int v76; // eax
  unsigned int m_reference_count; // esi
  unsigned int v78; // edi
  const vostok::math::float3 *v79; // ebx
  vostok::render::res_effect *v80; // eax
  unsigned int v81; // ecx
  vostok::render::backend *v82; // esi
  vostok::render::render_target *v83; // eax
  ID3D11RenderTargetView *v84; // ebx
  vostok::render::render_target *v85; // eax
  vostok::render::resource_manager *v86; // ecx
  int v87; // eax
  vostok::render::environment_probe **v88; // eax
  vostok::render::environment_probe *v89; // eax
  const vostok::math::float4x4 *v90; // eax
  vostok::math::float4x4 *p_transform; // esi
  unsigned int v92; // eax
  BOOL clip_by_normal; // ecx
  BOOL with_shadows; // edx
  unsigned int geometry; // ebx
  int v96; // eax
  vostok::render::res_effect *v97; // ecx
  const char *v98; // esi
  const char *v99; // esi
  vostok::render::backend *v100; // ebx
  vostok::render::constants_handler<1> *v101; // esi
  vostok::render::shader_constant_host *m_c_color_parameters; // eax
  unsigned int v103; // eax
  const vostok::math::float3 *v104; // eax
  const char *v105; // esi
  int v106; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v107; // [esp-1Ch] [ebp-204h]
  vostok::render::renderer_context *power; // [esp+Ch] [ebp-1DCh]
  unsigned int v109; // [esp+10h] [ebp-1D8h]
  float probec; // [esp+20h] [ebp-1C8h]
  vostok::render::environment_probe *probe; // [esp+20h] [ebp-1C8h]
  vostok::render::environment_probe *probea; // [esp+20h] [ebp-1C8h]
  vostok::render::environment_probe *probeb; // [esp+20h] [ebp-1C8h]
  vostok::math::float3 src_ptr; // [esp+24h] [ebp-1C4h] BYREF
  float x; // [esp+30h] [ebp-1B8h]
  unsigned int tech_index; // [esp+34h] [ebp-1B4h]
  vostok::math::float3 plus_z; // [esp+38h] [ebp-1B0h] BYREF
  int v118; // [esp+44h] [ebp-1A4h]
  float radius; // [esp+48h] [ebp-1A0h] BYREF
  vostok::render::environment_probe **it; // [esp+4Ch] [ebp-19Ch]
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v121; // [esp+50h] [ebp-198h]
  float skylight_power; // [esp+54h] [ebp-194h] BYREF
  const vostok::math::float3 *eye_rays; // [esp+58h] [ebp-190h]
  vostok::render::environment_probe **v124; // [esp+5Ch] [ebp-18Ch]
  vostok::math::float3 minus_y; // [esp+60h] [ebp-188h]
  float skylight_upper_limit; // [esp+6Ch] [ebp-17Ch]
  vostok::render::base_scene_view *v127; // [esp+70h] [ebp-178h]
  float skylight_lower_limit; // [esp+74h] [ebp-174h]
  vostok::math::float3 minus_x; // [esp+78h] [ebp-170h]
  vostok::math::float3 plus_y; // [esp+84h] [ebp-164h]
  vostok::math::float3 minus_z; // [esp+90h] [ebp-158h]
  vostok::math::float3 plus_x; // [esp+9Ch] [ebp-14Ch]
  vostok::math::float4x4 dst; // [esp+A8h] [ebp-140h] BYREF
  vostok::math::float4x4 world_to_probe; // [esp+E8h] [ebp-100h] BYREF
  vostok::math::float4x4 v135; // [esp+128h] [ebp-C0h] BYREF
  vostok::math::float4x4 world_transform; // [esp+168h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+1A8h] [ebp-40h] BYREF

  if ( this->is_enabled(this) && vostok::render::stage_ambient_lighting::is_effects_ready(v2, this) )
  {
    m_object = this->m_context->m_scene_view.m_object;
    m_flags = (vostok::render::environment_probe **)m_object[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags;
    v121 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)m_object;
    v5 = *(vostok::render::environment_probe ***)&m_object[4].m_inlined_in_fat;
    LOBYTE(radius) = 0;
    it = m_flags;
    v124 = v5;
    ___sort_PAPAUenvironment_probe_render_vostok__Usort_by_size_predicate__4__execute_stage_ambient_lighting_23_UAEXXZ__stlp_std__YAXPAPAUenvironment_probe_render_vostok__0Usort_by_size_predicate__4__execute_stage_ambient_lighting_23_UAEXXZ__Z(
      m_flags,
      v5,
      0);
    m_context = this->m_context;
    v7 = m_context->m_scene_view.m_object;
    m_eye_rays = m_context->m_eye_rays;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
    v11 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v10;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v10;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v11;
    eye_rays = m_eye_rays;
    v127 = v7;
    v12 = vostok::math::pow((const vostok::math::float3_pod *)&v7[3].m_children_resources.gapC, &plus_z.x, 2.2);
    v13 = *(float *)&v7[3].m_parent_resources.gapC;
    radius = v13 * v12->x;
    *(float *)&tech_index = v12->y * v13;
    z = v12->z;
    v15 = this->m_skylight_effect.m_object;
    skylight_upper_limit = *(float *)&v7[3].m_parent_resources.m_lock;
    skylight_lower_limit = *(float *)&v7[3].m_parent_resources.m_size;
    probec = z * v13;
    skylight_power = *(float *)&v7[3].m_parent_resources.m_thread_id;
    vostok::render::res_effect::apply((vostok::render::res_effect *)1, v15);
    v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    m_c_skylight_parameters0 = this->m_c_skylight_parameters0;
    v18 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
    v19 = this->m_ambient_multiplier * radius;
    m_ambient_multiplier = this->m_ambient_multiplier;
    plus_z.z = m_ambient_multiplier * probec;
    plus_z.x = v19;
    plus_z.y = m_ambient_multiplier * *(float *)&tech_index;
    v118 = 0;
    if ( m_c_skylight_parameters0->m_update_markers[1] == v18 )
    {
      m_buffer_index = m_c_skylight_parameters0->m_shader_slots[1].m_buffer_index;
      if ( m_buffer_index != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters0->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters0->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * m_buffer_index),
          (const char *)&plus_z);
    }
    v22 = skylight_lower_limit;
    ++*((_DWORD *)v16 + 23);
    m_c_skylight_parameters1 = this->m_c_skylight_parameters1;
    v24 = (vostok::render::lights_db *)*((_DWORD *)v16 + 573);
    plus_z.y = skylight_upper_limit - v22;
    plus_z.z = skylight_power;
    plus_z.x = v22;
    v118 = 0;
    if ( (vostok::render::lights_db *)m_c_skylight_parameters1->m_update_markers[1] == v24 )
    {
      v24 = (vostok::render::lights_db *)m_c_skylight_parameters1->m_shader_slots[1].m_buffer_index;
      if ( (unsigned __int16)v24 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters1->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters1->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v16 + 371) + 16)
                                                     + 4 * (unsigned __int16)v24),
          (const char *)&plus_z);
    }
    ++*((_DWORD *)v16 + 23);
    v25 = vostok::render::lights_db::get_sun(
            v24,
            (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this->m_context->m_scene->m_lights.m_object,
            (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&skylight_power)->m_object;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&skylight_power);
    m_current_satisfaction = v7[2].m_current_satisfaction;
    v27 = *(float *)&v7[2].m_target_quality_level;
    v28 = *(float *)&v7[2].grm_satisfaction_tree_hook.right_;
    v29 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *(_QWORD *)&minus_x.x = *(_QWORD *)&v7[2].m_next_in_increase_quality_queue;
    *(_QWORD *)&plus_x.x = *(_QWORD *)&v7[2].m_last_fail_of_increasing_quality;
    *(_QWORD *)&minus_y.x = *(_QWORD *)&v7[2].grm_satisfaction_tree_hook.parent_;
    *(_QWORD *)&plus_y.x = *(_QWORD *)&v7[2].m_next_in_memory_type;
    *(_QWORD *)&minus_z.x = *(_QWORD *)&v7[2].m_fat_it.m_link_target;
    *(_QWORD *)&plus_z.x = *(_QWORD *)&v7[2].m_next_for_grm_observer_list;
    minus_x.z = m_current_satisfaction;
    v30 = *(float *)&v7[2].m_fat_it.m_hashset;
    plus_x.z = v27;
    v31 = *(float *)&v7[2].m_name_registry_entry;
    *(_QWORD *)&src_ptr.x = *(_QWORD *)&minus_x.x;
    plus_y.z = v30;
    m_c_skylight_parameters2 = this->m_c_skylight_parameters2;
    minus_z.z = v31;
    v33 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
    minus_y.z = v28;
    v34 = *(float *)&v7[2].m_creation_source;
    src_ptr.z = minus_x.z;
    plus_z.z = v34;
    x = minus_z.x;
    if ( m_c_skylight_parameters2->m_update_markers[1] == v33 )
    {
      v35 = m_c_skylight_parameters2->m_shader_slots[1].m_buffer_index;
      if ( v35 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters2->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters2->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * v35),
          (const char *)&src_ptr);
    }
    v36 = plus_x.x;
    ++v29[7].m_current.m_object;
    m_c_skylight_parameters3 = this->m_c_skylight_parameters3;
    m_diff_range_start = v29[191].m_diff_range_start;
    *(_QWORD *)&src_ptr.x = __PAIR64__(LODWORD(plus_x.y), LODWORD(v36));
    src_ptr.z = plus_x.z;
    x = minus_z.y;
    if ( m_c_skylight_parameters3->m_update_markers[1] == m_diff_range_start )
    {
      v39 = m_c_skylight_parameters3->m_shader_slots[1].m_buffer_index;
      if ( v39 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters3->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters3->m_shader_slots[1].m_class_id,
          v29[123].m_current.m_object->m_const_buffers._M_impl._M_start[v39].m_object,
          (const char *)&src_ptr);
    }
    v40 = plus_y.x;
    ++v29[7].m_current.m_object;
    m_c_skylight_parameters4 = this->m_c_skylight_parameters4;
    v42 = v29[191].m_diff_range_start;
    *(_QWORD *)&src_ptr.x = __PAIR64__(LODWORD(plus_y.y), LODWORD(v40));
    src_ptr.z = plus_y.z;
    x = minus_z.z;
    if ( m_c_skylight_parameters4->m_update_markers[1] == v42 )
    {
      v43 = m_c_skylight_parameters4->m_shader_slots[1].m_buffer_index;
      if ( v43 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters4->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters4->m_shader_slots[1].m_class_id,
          v29[123].m_current.m_object->m_const_buffers._M_impl._M_start[v43].m_object,
          (const char *)&src_ptr);
    }
    v44 = plus_z.x;
    ++v29[7].m_current.m_object;
    m_c_skylight_parameters5 = this->m_c_skylight_parameters5;
    v46 = v29[191].m_diff_range_start;
    *(_QWORD *)&src_ptr.x = __PAIR64__(LODWORD(plus_z.y), LODWORD(v44));
    src_ptr.z = plus_z.z;
    x = minus_y.x;
    if ( m_c_skylight_parameters5->m_update_markers[1] == v46 )
    {
      v47 = m_c_skylight_parameters5->m_shader_slots[1].m_buffer_index;
      if ( v47 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters5->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters5->m_shader_slots[1].m_class_id,
          v29[123].m_current.m_object->m_const_buffers._M_impl._M_start[v47].m_object,
          (const char *)&src_ptr);
    }
    ++v29[7].m_current.m_object;
    v48 = 0.0;
    if ( v25 )
    {
      p_direction = &v25->direction;
    }
    else
    {
      memset(&plus_z, 0, sizeof(plus_z));
      p_direction = &plus_z;
    }
    v50 = v29[191].m_diff_range_start;
    *(_QWORD *)&src_ptr.x = *(_QWORD *)&p_direction->x;
    v51 = p_direction->z;
    m_c_skylight_parameters6 = this->m_c_skylight_parameters6;
    src_ptr.z = v51;
    x = minus_y.y;
    if ( m_c_skylight_parameters6->m_update_markers[1] == v50 )
    {
      v53 = m_c_skylight_parameters6->m_shader_slots[1].m_buffer_index;
      if ( v53 != 0xFFFF )
      {
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters6->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters6->m_shader_slots[1].m_class_id,
          v29[123].m_current.m_object->m_const_buffers._M_impl._M_start[v53].m_object,
          (const char *)&src_ptr);
        v48 = 0.0;
      }
    }
    ++v29[7].m_current.m_object;
    if ( v25 )
    {
      p_plus_z = &v25->direction;
    }
    else
    {
      memset(&plus_z, 0, sizeof(plus_z));
      p_plus_z = &plus_z;
    }
    v55 = v29[190].m_current.m_object;
    *(_QWORD *)&src_ptr.x = *(_QWORD *)&p_plus_z->x;
    v56 = p_plus_z->z;
    v57 = this->m_c_skylight_parameters6;
    src_ptr.z = v56;
    x = minus_y.y;
    if ( (const vostok::render::shader_constant_table *)v57->m_update_markers[0] == v55 )
    {
      v58 = v57->m_shader_slots[0].m_buffer_index;
      if ( v58 != 0xFFFF )
      {
        vostok::render::shader_constant_buffer::set_memory(
          v57->m_shader_slots[0].m_slot_index,
          (unsigned __int8)v57->m_shader_slots[0].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(v29[17].m_diff_range_start + 16) + 4 * v58),
          (const char *)&src_ptr);
        v48 = 0.0;
      }
    }
    ++v29[7].m_current.m_object;
    if ( v25 )
    {
      intensity = v25->intensity;
      v60 = (float)(v25->color.z * *(float *)&v7[2].m_reference_count) * intensity;
      v48 = (float)(*(float *)&v7[2].m_memory_type_data * v25->color.x) * intensity;
      plus_z.y = (float)(v25->color.y * *((float *)&v7[2].m_memory_type_data + 1)) * intensity;
      plus_z.z = v60;
    }
    else
    {
      *(_QWORD *)&plus_z.elements[1] = 0;
    }
    v61 = v29[191].m_diff_range_start;
    plus_z.x = v48;
    *(_QWORD *)&src_ptr.x = *(_QWORD *)&plus_z.x;
    m_c_skylight_parameters7 = this->m_c_skylight_parameters7;
    src_ptr.z = plus_z.z;
    x = minus_y.z;
    if ( m_c_skylight_parameters7->m_update_markers[1] == v61 )
    {
      v63 = m_c_skylight_parameters7->m_shader_slots[1].m_buffer_index;
      if ( v63 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_skylight_parameters7->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_skylight_parameters7->m_shader_slots[1].m_class_id,
          v29[123].m_current.m_object->m_const_buffers._M_impl._M_start[v63].m_object,
          (const char *)&src_ptr);
    }
    v64 = eye_rays;
    ++v29[7].m_current.m_object;
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(this->m_c_eye_ray_corner, v29 + 123, v64);
    ++v29[7].m_current.m_object;
    v66 = 0;
    v67 = this->m_context->m_targets->m_family[26].target.m_object;
    if ( v67 )
    {
      v66 = (const char *)this->m_context->m_targets->m_family[26].target.m_object;
      ++v67->m_reference_count;
    }
    v107.m_object = 0;
    if ( v66 )
    {
      v107.m_object = (vostok::render::render_target *)v66;
      ++*(_DWORD *)v66;
    }
    vostok::render::system_renderer::fill_surface(
      v65,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
      v107,
      0,
      0,
      0,
      0,
      (D3D11_VIEWPORT *)1,
      0.0,
      0.0,
      0.0,
      1.0);
    if ( v66 )
    {
      v11 = (*(_DWORD *)v66)-- == 1;
      if ( v11 )
        vostok::render::resource_manager::release(
          v68,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v66);
    }
    v69 = (int)this->m_context;
    v70 = *(_DWORD *)(v69 + 12392);
    v71 = *(vostok::render::environment_probe **)(v70 + 1416);
    tech_index = *(unsigned int *)(v70 + 1420);
    probe = v71;
    if ( ((tech_index - (_DWORD)v71) & 0xFFFFFFFC) != 0 )
    {
      v72 = *(_DWORD **)(*(_DWORD *)v69 + 4312);
      v73 = 0;
      if ( v72 )
      {
        v73 = *(ID3D11RenderTargetView **)(*(_DWORD *)v69 + 4312);
        ++*v72;
      }
      vostok::render::backend::set_render_targets(
        v73,
        0,
        0,
        0,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      if ( v73 )
      {
        v11 = v73->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
        if ( v11 )
          vostok::render::resource_manager::release(
            v74,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v73);
      }
      v69 = (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v75 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
      v11 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v75;
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v75;
      v76 = tech_index;
      *(_BYTE *)(v69 + 167) |= !v11;
      if ( probe != (vostok::render::environment_probe *)v76 )
      {
        do
        {
          v69 = (int)probe;
          m_reference_count = probe->m_reference_count;
          if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                 + 288)
             || !*(_BYTE *)(m_reference_count + 108))
            && *(_BYTE *)(m_reference_count + 72) )
          {
            vostok::render::renderer_context::set_w(
              this->m_context,
              (const vostok::math::float4x4 *)(m_reference_count + 4));
            vostok::render::res_effect::apply(0, &this->m_effect_accum_mask.m_object->__vftable);
            vostok::render::res_geometry::apply(this->m_box_geometry.m_object);
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
              0x24u,
              D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
              0,
              0);
            v78 = 0;
            v79 = (const vostok::math::float3 *)(m_reference_count + 68);
            do
            {
              v80 = this->m_ambient_volume_effect.m_object;
              v81 = v80->m_techniques._M_impl._M_finish - v80->m_techniques._M_impl._M_start;
              if ( v78 < v81 )
              {
                v80->m_cur_technique = v78;
                vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v81, v109);
              }
              vostok::render::res_geometry::apply(this->m_box_geometry.m_object);
              v82 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                this->m_c_ambient_volume_multiplier,
                (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
              + 123,
                v79);
              ++v82->num_setted_shader_constants;
              vostok::render::backend::render_indexed(v82, 0x24u, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, 0);
              ++v78;
            }
            while ( v78 < 2 );
          }
          probe = (vostok::render::environment_probe *)((char *)probe + 4);
        }
        while ( probe != (vostok::render::environment_probe *)tech_index );
      }
    }
    if ( this->m_use_probes )
    {
      v69 = (char *)v121[345].m_object - (char *)v121[344].m_object;
      if ( (v69 & 0xFFFFFFFC) != 0 )
      {
        v83 = this->m_context->m_targets->m_family[28].target.m_object;
        v84 = 0;
        probea = 0;
        if ( v83 )
        {
          ++v83->m_reference_count;
          probea = (vostok::render::environment_probe *)v83;
        }
        v85 = this->m_context->m_targets->m_family[26].target.m_object;
        if ( v85 )
        {
          v84 = (ID3D11RenderTargetView *)this->m_context->m_targets->m_family[26].target.m_object;
          ++v85->m_reference_count;
        }
        vostok::render::backend::set_render_targets(
          v84,
          (const vostok::render::render_target *)probea,
          0,
          0,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        if ( v84 )
        {
          v11 = v84->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
          if ( v11 )
            vostok::render::resource_manager::release(
              v86,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v84);
        }
        v69 = (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        if ( probea )
        {
          v11 = probea->m_reference_count-- == 1;
          if ( v11 )
          {
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)v69,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)probea);
            v69 = (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
        }
        v87 = *(_DWORD *)(v69 + 2188);
        v11 = *(_DWORD *)(v69 + 2156) == v87;
        *(_DWORD *)(v69 + 2156) = v87;
        v88 = v124;
        *(_BYTE *)(v69 + 167) |= !v11;
        if ( it != v88 )
        {
          do
          {
            v69 = (int)it;
            v89 = *it;
            probeb = *it;
            if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 288)
               || !v89->m_occluded)
              && v89->m_texture.m_object
              && probeb->m_properties.enabled )
            {
              v11 = probeb->m_properties.geometry == 0;
              radius = probeb->m_properties.radius;
              if ( v11 )
              {
                memset((int)&dst, 0, sizeof(dst));
                dst.i.x = radius;
                dst.j.y = radius;
                dst.k.z = radius;
                LODWORD(dst.c.w) = clear_value;
                v90 = vostok::math::create_translation(&result, &probeb->m_properties.location);
                vostok::math::mul4x3(&v135, &dst, v90);
                p_transform = &v135;
              }
              else
              {
                p_transform = &probeb->m_properties.transform;
              }
              power = this->m_context;
              qmemcpy((void *)&world_transform, p_transform, sizeof(world_transform));
              vostok::render::renderer_context::set_w(power, &world_transform);
              vostok::render::res_effect::apply(0, &this->m_effect_accum_mask.m_object->__vftable);
              if ( probeb->m_properties.geometry )
              {
                vostok::render::res_geometry::apply(this->m_box_geometry.m_object);
                v92 = 36;
              }
              else
              {
                vostok::render::res_geometry::apply(this->m_sphere_geometry.m_object);
                v92 = 540;
              }
              vostok::render::backend::render_indexed(
                (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                v92,
                D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
                0,
                0);
              clip_by_normal = probeb->m_properties.clip_by_normal;
              with_shadows = probeb->m_properties.with_shadows;
              geometry = probeb->m_properties.geometry;
              if ( geometry )
              {
                v96 = probeb->m_properties.geometry;
                if ( geometry > 1 )
                  v96 = 1;
              }
              else
              {
                v96 = 0;
              }
              *(float *)&tech_index = 0.0;
              v121 = &this->m_environment_probe_lighting_effect[clip_by_normal][with_shadows][v96];
              src_ptr.z = 0.0;
              x = 0.0;
              do
              {
                v97 = (vostok::render::res_effect *)tech_index;
                if ( tech_index < v121->m_object->m_techniques._M_impl._M_finish
                                - v121->m_object->m_techniques._M_impl._M_start )
                {
                  v121->m_object->m_cur_technique = tech_index;
                  vostok::render::res_effect::apply_pass(v97, v109);
                }
                v98 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                *((_BYTE *)v98 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                          (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                                + 1488),
                                          (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                        + 1488,
                                          (vostok::render::res_texture *)&stru_9642F8,
                                          probeb->m_texture.m_object);
                if ( probeb->m_properties.with_shadows && probeb->m_texture_depth.m_object )
                {
                  v99 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                  *((_BYTE *)v99 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                            (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                                  + 1488),
                                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                          + 1488,
                                            (vostok::render::res_texture *)&stru_9642F8.m_rescale_min,
                                            probeb->m_texture_depth.m_object);
                }
                v100 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                v101 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                              + 1476);
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  this->m_c_eye_ray_corner,
                  (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 123,
                  eye_rays);
                ++v100->num_setted_shader_constants;
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  this->m_c_light_range,
                  v101,
                  (const vostok::math::float3 *)&radius);
                ++v100->num_setted_shader_constants;
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  this->m_c_num_mips,
                  v101,
                  (const vostok::math::float3 *)&probeb->m_num_mips);
                ++v100->num_setted_shader_constants;
                src_ptr.x = *(float *)&v127[3].m_parent_resources.m_last * probeb->m_properties.diffuse_multiplier;
                m_c_color_parameters = this->m_c_color_parameters;
                src_ptr.y = *((float *)&v127[3].m_parent_resources + 6) * probeb->m_properties.specular_multiplier;
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  m_c_color_parameters,
                  v101,
                  &src_ptr);
                ++v100->num_setted_shader_constants;
                if ( probeb->m_properties.geometry )
                {
                  qmemcpy((void *)&world_to_probe, &probeb->m_properties.transform, sizeof(world_to_probe));
                  vostok::math::float4x4::try_invert(&world_to_probe, &world_to_probe);
                  v104 = (const vostok::math::float3 *)vostok::math::transpose(&result, &world_to_probe);
                  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                    this->m_c_world_to_probe,
                    &v100->m_ps_constants_handler,
                    v104);
                  ++v100->num_setted_shader_constants;
                  vostok::render::res_geometry::apply(this->m_box_geometry.m_object);
                  v103 = 36;
                }
                else
                {
                  vostok::render::res_geometry::apply(this->m_sphere_geometry.m_object);
                  v103 = 540;
                }
                vostok::render::backend::render_indexed(v100, v103, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, 0);
                ++tech_index;
              }
              while ( tech_index < 2 );
            }
            ++it;
          }
          while ( it != v124 );
        }
      }
    }
    v105 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)v69,
      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    v106 = *((_DWORD *)v105 + 547);
    v11 = *((_DWORD *)v105 + 539) == v106;
    *((_DWORD *)v105 + 539) = v106;
    *((_BYTE *)v105 + 167) |= !v11;
  }
  else
  {
    this->execute_disabled(this);
  }
}
