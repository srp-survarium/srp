// local variable allocation has failed, the output may be wrong!
vostok::animation::mixing::expression *__thiscall survarium::single_position_animation_controller::selected_animations(
        survarium::single_position_animation_controller *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  survarium::movement_animation_controller_parameters *v4; // edx
  const survarium::movement_animation_controller_parameters *v5; // ecx
  vostok::math::quaternion *quaternion_from_direction_vector; // eax
  survarium::single_position_animation_controller *v7; // esi
  survarium::human_npc *m_owner; // ecx
  vostok::math::float3_pod *p_translation; // edi
  int v10; // edi
  unsigned int v11; // eax
  __int64 v12; // xmm0_8
  unsigned int v13; // edi
  vostok::math::float3 *M_start; // eax
  float x; // xmm0_4
  float v16; // xmm1_4
  float y; // xmm2_4
  float v18; // xmm3_4
  vostok::math::float3 *v19; // eax
  unsigned int v20; // eax
  int v21; // ecx
  unsigned int m_next_key_point; // ecx
  void (__cdecl *v23)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v24)(float *, float *, int); // eax
  float v25; // eax
  vostok::math::float3 *v26; // eax
  int v27; // ecx
  vostok::math::float4x4 *v28; // ecx
  int v29; // eax
  float *p_x; // esi
  vostok::math::quaternion *v31; // ecx
  __int64 *v32; // eax
  __int64 v33; // xmm0_8
  __int64 v34; // xmm1_8
  survarium::single_position_animation_controller *v35; // esi
  survarium::animation_space_vertex_id *m_target_vertex; // eax
  const vostok::resources::resource_ptr<survarium::animation_space_graph,vostok::resources::unmanaged_intrusive_base> *p_m_animation_space_graph; // edi
  survarium::animation_space_vertex_id *v38; // eax
  float v39; // edx
  const vostok::math::float3 *v40; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v41; // esi
  vostok::animation::mixing::animation_lexeme *v42; // ecx
  vostok::animation::mixing::animation_lexeme *v43; // ecx
  const vostok::animation::mixing::animation_interval *v44; // esi
  const vostok::animation::mixing::animation_interval *j; // edi
  vostok::animation::mixing::expression *v46; // edi
  vostok::animation::mixing::animation_lexeme *v47; // ecx
  vostok::animation::mixing::animation_lexeme *p_left_animation; // eax
  vostok::resources::resource_ptr<survarium::animation_space_graph,vostok::resources::unmanaged_intrusive_base> v49; // eax
  float v50; // xmm0_4
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v51; // esi
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::animation_lexeme *m_data; // esi
  vostok::animation::mixing::animation_lexeme *m_object; // ecx
  bool v55; // zf
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // esi
  const vostok::animation::mixing::animation_interval *v57; // edi
  float v58; // edi
  int v59; // ecx
  vostok::animation::linear_interpolator *v60; // eax
  int v61; // eax
  vostok::animation::mixing::animation_lexeme *v62; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v63; // edi
  char *v64; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v65; // ecx
  vostok::mutable_buffer *v66; // eax
  vostok::animation::mixing::animation_lexeme *v67; // esi
  vostok::animation::mixing::animation_lexeme *v68; // ecx
  const vostok::animation::mixing::animation_interval *v69; // esi
  const vostok::animation::mixing::animation_interval *v70; // edi
  vostok::mutable_buffer *v71; // eax
  char *v72; // esi
  float v73; // xmm0_4
  vostok::mutable_buffer *v74; // edi
  vostok::animation::base_interpolator *v75; // eax
  int v76; // xmm0_4
  vostok::animation::mixing::multiplication_lexeme *v77; // eax
  vostok::animation::mixing::expression *v78; // eax
  vostok::animation::mixing::animation_lexeme *v79; // ecx
  unsigned int *v80; // eax
  int f; // ecx
  survarium::animations_search_service *m_search_service; // [esp-24h] [ebp-2DCh]
  survarium::animation_space_vertex_id v84; // [esp-20h] [ebp-2D8h]
  survarium::animation_space_vertex_id v85; // [esp-4h] [ebp-2BCh]
  vostok::math::float3 v86; // [esp+Ch] [ebp-2ACh]
  vostok::animation::mixing::multiplication_lexeme *epsilon; // [esp+14h] [ebp-2A4h]
  __int64 time_scale; // [esp+24h] [ebp-294h] OVERLAPPED BYREF
  float z; // [esp+2Ch] [ebp-28Ch]
  const vostok::math::float3 *movement_position; // [esp+30h] [ebp-288h]
  unsigned int i; // [esp+34h] [ebp-284h]
  vostok::math::float3 v92; // [esp+38h] [ebp-280h] BYREF
  survarium::vector<unsigned int> path; // [esp+44h] [ebp-274h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters animation; // [esp+50h] [ebp-268h] BYREF
  float v95; // [esp+A4h] [ebp-214h]
  survarium::animation_space_vertex_id start_vertex_id; // [esp+A8h] [ebp-210h] BYREF
  int v97; // [esp+CCh] [ebp-1ECh]
  survarium::single_position_animation_controller *v98; // [esp+D0h] [ebp-1E8h]
  float v99[2]; // [esp+D4h] [ebp-1E4h] BYREF
  vostok::animation::linear_interpolator v100; // [esp+DCh] [ebp-1DCh] BYREF
  float v101; // [esp+ECh] [ebp-1CCh]
  float v102; // [esp+F0h] [ebp-1C8h]
  float previous_to_current_length; // [esp+F4h] [ebp-1C4h]
  vostok::animation::mixing::weight_lexeme left_weight; // [esp+F8h] [ebp-1C0h] BYREF
  vostok::animation::mixing::animation_lexeme left_animation; // [esp+120h] [ebp-198h] BYREF
  vostok::animation::mixing::animation_lexeme right_animation; // [esp+1A8h] [ebp-110h] BYREF
  vostok::animation::mixing::animation_lexeme lexeme; // [esp+230h] [ebp-88h] BYREF

  v98 = this;
  v97 = 0;
  if ( !survarium::operator==(&this->m_target_parameters, &this->m_current_parameters) )
    survarium::movement_animation_controller_parameters::operator=(v4, v5);
  quaternion_from_direction_vector = vostok::math::create_quaternion_from_direction_vector(
                                       &this->m_current_parameters.eyes_direction,
                                       &start_vertex_id.rotation);
  v7 = v98;
  v98->m_target_vertex->rotation = *quaternion_from_direction_vector;
  movement_position = &v7->m_current_parameters.position;
  m_owner = v7->m_owner;
  memset(&start_vertex_id, 0, 12);
  m_owner->get_position(m_owner, &v92, (const vostok::math::float3 *)&start_vertex_id);
  p_translation = &v7->m_target_vertex->translation;
  if ( !vostok::math::float3_pod::is_similar(p_translation, &v7->m_current_parameters.position, 0.0000099999997) )
  {
    *p_translation = movement_position->vostok::math::float3_pod;
    v10 = v7->m_ai_navigation_world->get_node_id_at((vostok::ai::navigation::world *)v7->m_ai_navigation_world, &v92);
    v11 = v7->m_ai_navigation_world->get_node_id_at(
            (vostok::ai::navigation::world *)v7->m_ai_navigation_world,
            &v7->m_target_vertex->translation);
    i = v11;
    if ( v10 == -1 || v11 == -1 )
    {
      v7->m_next_key_point = -1;
    }
    else if ( !((unsigned int (__stdcall *)(int, vostok::math::float3 *, unsigned int, int, _DWORD, int))v7->m_ai_navigation_world->find_path)(
                 v10,
                 &v92,
                 i,
                 &v7->m_target_vertex->translation,
                 v7->m_animation_space_graph.m_object->m_agent_radius,
                 &v7->m_navigation_path)
           || v7->m_navigation_path._M_impl._M_start == v7->m_navigation_path._M_impl._M_finish )
    {
      v7->m_next_key_point = -1;
    }
    else
    {
      v7->m_next_key_point = 1;
    }
  }
  if ( v7->m_next_key_point == -1 )
  {
    v12 = *(_QWORD *)&v92.x;
    z = v92.z;
  }
  else
  {
    v13 = v7->m_navigation_path._M_impl._M_finish - v7->m_navigation_path._M_impl._M_start;
    i = v7->m_next_key_point;
    if ( i < v13 )
    {
      do
      {
        M_start = v7->m_navigation_path._M_impl._M_start;
        x = M_start[v7->m_next_key_point].x;
        v16 = M_start[v7->m_next_key_point - 1].x;
        y = M_start[v7->m_next_key_point - 1].y;
        v18 = M_start[v7->m_next_key_point - 1].z;
        v19 = &M_start[v7->m_next_key_point];
        v101 = v16;
        *(float *)&v100.__vftable = x;
        v95 = v19->y;
        v102 = y;
        *(float *)&time_scale = v19->z;
        v99[0] = v18;
        start_vertex_id.rotation.z = *(float *)&time_scale - v18;
        start_vertex_id.rotation.y = v95 - y;
        start_vertex_id.rotation.x = x - v16;
        previous_to_current_length = sqrtf(
                                       (float)((float)(start_vertex_id.rotation.z * start_vertex_id.rotation.z)
                                             + (float)(start_vertex_id.rotation.y * start_vertex_id.rotation.y))
                                     + (float)(start_vertex_id.rotation.x * start_vertex_id.rotation.x));
        if ( previous_to_current_length > (float)((float)((float)((float)(v92.x - v101)
                                                                * (float)(start_vertex_id.rotation.x
                                                                        * (float)(*(float *)&clear_value
                                                                                / previous_to_current_length)))
                                                        + (float)((float)(start_vertex_id.rotation.z
                                                                        * (float)(*(float *)&clear_value
                                                                                / previous_to_current_length))
                                                                * (float)(v92.z - v99[0])))
                                                + (float)((float)(v92.y - v102)
                                                        * (float)(start_vertex_id.rotation.y
                                                                * (float)(*(float *)&clear_value
                                                                        / previous_to_current_length))))
          && sqrtf(
               (float)((float)((float)(v92.x - *(float *)&v100.__vftable) * (float)(v92.x - *(float *)&v100.__vftable))
                     + (float)((float)(v92.z - *(float *)&time_scale) * (float)(v92.z - *(float *)&time_scale)))
             + (float)((float)(v92.y - v95) * (float)(v92.y - v95))) > 0.30000001 )
        {
          break;
        }
        v21 = v7->m_next_key_point + 1;
        v20 = ++i;
        v7->m_next_key_point = v21;
      }
      while ( v20 < v13 );
    }
    m_next_key_point = v7->m_next_key_point;
    if ( m_next_key_point < v7->m_navigation_path._M_impl._M_finish - v7->m_navigation_path._M_impl._M_start )
    {
      v26 = v7->m_navigation_path._M_impl._M_start;
      v27 = m_next_key_point;
      v12 = *(_QWORD *)&v26[v27].x;
      z = v26[v27].z;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v23 = vostok::core::g_log_callback;
        start_vertex_id.rotation.x = 0.0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            (const boost::detail::function::function_buffer *)&start_vertex_id.rotation.vector.elements[2],
            (boost::detail::function::function_buffer *)&start_vertex_id.rotation.vector.elements[2],
            destroy_functor_tag);
        if ( v23 )
        {
          LODWORD(start_vertex_id.rotation.z) = v23;
          LODWORD(start_vertex_id.rotation.x) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                              + 1;
        }
        else
        {
          start_vertex_id.rotation.x = 0.0;
        }
        v97 = 1;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&start_vertex_id,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          &::result.m_buffer[244],
          0x80u,
          &::result.m_buffer[88],
          "game:",
          info,
          &::result.m_buffer[72]);
      }
      if ( (v97 & 1) != 0 )
      {
        if ( LODWORD(start_vertex_id.rotation.x) )
        {
          if ( (LOBYTE(start_vertex_id.rotation.x) & 1) == 0 )
          {
            v24 = *(void (__cdecl **)(float *, float *, int))(LODWORD(start_vertex_id.rotation.x) & 0xFFFFFFFE);
            if ( v24 )
              v24(&start_vertex_id.rotation.z, &start_vertex_id.rotation.z, 2);
          }
        }
      }
      v25 = v92.z;
      v12 = *(_QWORD *)&v92.x;
      v7->m_next_key_point = -1;
      z = v25;
    }
  }
  v28 = (vostok::math::float4x4 *)LODWORD(z);
  v29 = (int)&v7->m_target_vertex->translation;
  *(_QWORD *)v29 = v12;
  *(_DWORD *)(v29 + 8) = v28;
  p_x = &v7->m_owner->m_transform.i.x;
  time_scale = v12;
  vostok::math::float4x4::get_angles_xyz(v28, &start_vertex_id.rotation.x, p_x);
  *(_QWORD *)&v86.x = *(_QWORD *)&start_vertex_id.rotation.x;
  v86.z = start_vertex_id.rotation.z;
  vostok::math::quaternion::quaternion(v31, (float *)&v100, v86);
  v33 = *v32;
  v34 = v32[1];
  v35 = v98;
  m_target_vertex = v98->m_target_vertex;
  memset(&path, 0, sizeof(path));
  v85 = *m_target_vertex;
  *(_QWORD *)&v84.rotation.x = v33;
  *(_QWORD *)&v84.rotation.vector.elements[2] = v34;
  v84.translation = v92;
  p_m_animation_space_graph = &v98->m_animation_space_graph;
  m_search_service = v98->m_search_service;
  *(_QWORD *)&start_vertex_id.rotation.x = v33;
  *(_QWORD *)&start_vertex_id.rotation.vector.elements[2] = v34;
  start_vertex_id.translation = v92;
  LODWORD(v95) = &v98->m_animation_space_graph;
  if ( survarium::animations_search_service::search(m_search_service, &v98->m_animation_space_graph, &path, v84, v85)
    && path._M_impl._M_start != path._M_impl._M_finish )
  {
    goto LABEL_43;
  }
  if ( v35->m_next_key_point < v35->m_navigation_path._M_impl._M_finish - v35->m_navigation_path._M_impl._M_start - 1 )
  {
    do
    {
      ++v35->m_next_key_point;
      v38 = v35->m_target_vertex;
      v39 = z;
      *(_QWORD *)&v38->translation.x = time_scale;
      v38->translation.z = v39;
    }
    while ( (!survarium::animations_search_service::search(
                v35->m_search_service,
                p_m_animation_space_graph,
                &path,
                start_vertex_id,
                *(const survarium::animation_space_vertex_id *)v35->m_target_vertex)
          || path._M_impl._M_start == path._M_impl._M_finish)
         && v35->m_next_key_point < v35->m_navigation_path._M_impl._M_finish
                                  - v35->m_navigation_path._M_impl._M_start
                                  - 1 );
  }
  if ( v35->m_next_key_point < v35->m_navigation_path._M_impl._M_finish - v35->m_navigation_path._M_impl._M_start - 1 )
  {
LABEL_43:
    v35->m_target_vertex->translation = *movement_position;
    v49.m_object = p_m_animation_space_graph->m_object;
    v50 = *(float *)(**((_DWORD **)&p_m_animation_space_graph->m_object[1].m_reconstruction_size
                      + 73 * p_m_animation_space_graph->m_object->m_animations_count
                      + 10 * *path._M_impl._M_start
                      + 2 * p_m_animation_space_graph->m_object->m_mixes_count
                      + 1)
                   + 280)
        / *((float *)&v49.m_object[1].m_children_resources.m_size
          + 73 * v49.m_object->m_animations_count
          + 10 * *path._M_impl._M_start
          + 2 * p_m_animation_space_graph->m_object->m_mixes_count);
    LODWORD(v99[0]) = &vostok::animation::linear_interpolator::`vftable';
    v100.__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
    *(float *)&time_scale = v50;
    v99[1] = 0.25;
    v100.m_total_transition_time = 0.25;
    v51 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)**((_DWORD **)&v49.m_object[1].m_reconstruction_size + 73 * v49.m_object->m_animations_count + 10 * *path._M_impl._M_start + 2 * v49.m_object->m_mixes_count + 1);
    animation.m_buffer = buffer;
    animation.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)buffer->m_data;
    memset((void *)&animation.m_time_calculator, 0, 16);
    memset(&animation.m_weight_interpolator, 0, 12);
    animation.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(v51);
    memset(&animation.m_start_cycle_animation_interval_id, 0, 12);
    LODWORD(animation.m_time_scale) = clear_value;
    animation.m_playback_type = play_cyclically;
    animation.m_time_synchronization_group_id = -1;
    animation.m_weight_synchronization_group_id = -1;
    *(_QWORD *)&animation.m_additivity_priority = 0xFFFFFFFF00000000uLL;
    *(_DWORD *)&animation.m_unique_animation_id = 16843007;
    vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
      &animation,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animation);
    animation.m_time_scale = v50;
    animation.m_time_scale_interpolator = &v100;
    animation.m_weight_interpolator = (const vostok::animation::base_interpolator *)v99;
    animation.m_weight_synchronization_group_id = 0;
    animation.m_time_synchronization_group_id = 0;
    vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&left_animation, &animation);
    m_buffer = animation.m_buffer;
    left_animation.vostok::animation::mixing::base_lexeme::m_buffer = animation.m_buffer;
    left_animation.m_cloned = 0;
    left_animation.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
    left_animation.m_cloned_instance.m_object = 0;
    m_data = (vostok::animation::mixing::animation_lexeme *)animation.m_buffer->m_data;
    animation.m_buffer->m_size -= 132;
    m_buffer->m_data = (char *)&m_data[1];
    if ( m_data )
      vostok::animation::mixing::animation_lexeme::animation_lexeme(m_data, &left_animation);
    m_data->m_cloned = 1;
    ++m_data->m_reference_count;
    m_object = left_animation.m_cloned_instance.m_object;
    left_animation.m_cloned_instance.m_object = m_data;
    if ( m_object )
    {
      v55 = m_object->m_reference_count-- == 1;
      if ( v55 )
        ((void (__thiscall *)(vostok::animation::mixing::animation_lexeme *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
    }
    m_animation_intervals = animation.m_animation_intervals;
    v57 = &animation.m_animation_intervals[animation.m_animation_intervals_count];
    if ( animation.m_animation_intervals != v57 )
    {
      do
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&m_animation_intervals->m_animation);
        ++m_animation_intervals;
      }
      while ( m_animation_intervals != v57 );
    }
    v58 = v95;
    v59 = *(_DWORD *)LODWORD(v95);
    v100.__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
    v100.m_total_transition_time = 0.25;
    LODWORD(time_scale) = *(_DWORD *)(v59
                                    + 292 * *(_DWORD *)(v59 + 276)
                                    + 8 * (*(_DWORD *)(v59 + 280) + 5 * (*path._M_impl._M_start + 8)));
    v60 = vostok::animation::linear_interpolator::clone(&v100, buffer);
    LODWORD(left_weight.m_weight) = time_scale;
    LODWORD(left_weight.m_simplified_weight) = time_scale;
    left_weight.m_interpolator = v60;
    v61 = *(_DWORD *)LODWORD(v58);
    left_weight.m_buffer = buffer;
    memset(&left_weight.m_next_weight, 0, 16);
    left_weight.m_cloned = 0;
    left_weight.__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::weight_lexeme::`vftable';
    LODWORD(time_scale) = &vostok::animation::linear_interpolator::`vftable';
    HIDWORD(time_scale) = 1048576000;
    v62 = (vostok::animation::mixing::animation_lexeme *)(v61 + 292 * *(_DWORD *)(v61 + 276));
    v63 = *(const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> **)(*((_DWORD *)&v62[2].m_weight_driving_animation + 10 * *path._M_impl._M_start + 2 * *(_DWORD *)(v61 + 280)) + 4);
    animation.m_buffer = buffer;
    animation.m_time_calculator.m_Closure.m_pthis = 0;
    animation.m_time_calculator.m_Closure.m_pFunction = 0;
    animation.m_time_driving_animation = (vostok::animation::mixing::animation_lexeme *const)vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
                                                                                               v62,
                                                                                               (vostok::animation::mixing::base_lexeme *)&left_animation);
    v64 = buffer->m_data;
    animation.m_weight_driving_animation = 0;
    animation.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)v64;
    memset(&animation.m_weight_interpolator, 0, 12);
    animation.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(v63);
    animation.m_weight_synchronization_group_id = -1;
    memset(&animation.m_start_cycle_animation_interval_id, 0, 12);
    LODWORD(animation.m_time_scale) = clear_value;
    animation.m_playback_type = play_cyclically;
    animation.m_time_synchronization_group_id = left_animation.m_time_synchronization_group_id;
    *(_QWORD *)&animation.m_additivity_priority = 0xFFFFFFFF00000000uLL;
    *(_DWORD *)&animation.m_unique_animation_id = 16843007;
    vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
      v65,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animation);
    animation.m_weight_synchronization_group_id = 0;
    animation.m_time_synchronization_group_id = 0;
    animation.m_weight_interpolator = (const vostok::animation::base_interpolator *)&time_scale;
    vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&right_animation, &animation);
    v66 = animation.m_buffer;
    right_animation.vostok::animation::mixing::base_lexeme::m_buffer = animation.m_buffer;
    right_animation.m_cloned = 0;
    right_animation.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
    right_animation.m_cloned_instance.m_object = 0;
    v67 = (vostok::animation::mixing::animation_lexeme *)animation.m_buffer->m_data;
    animation.m_buffer->m_size -= 132;
    v66->m_data = (char *)&v67[1];
    if ( v67 )
      vostok::animation::mixing::animation_lexeme::animation_lexeme(v67, &right_animation);
    v67->m_cloned = 1;
    ++v67->m_reference_count;
    v68 = right_animation.m_cloned_instance.m_object;
    right_animation.m_cloned_instance.m_object = v67;
    if ( v68 )
    {
      v55 = v68->m_reference_count-- == 1;
      if ( v55 )
        ((void (__thiscall *)(vostok::animation::mixing::animation_lexeme *, _DWORD))v68->~vostok::animation::mixing::binary_tree_base_node)(
          v68,
          0);
    }
    v69 = animation.m_animation_intervals;
    v70 = &animation.m_animation_intervals[animation.m_animation_intervals_count];
    if ( animation.m_animation_intervals != v70 )
    {
      do
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v69->m_animation);
        ++v69;
      }
      while ( v69 != v70 );
    }
    v71 = left_weight.m_buffer;
    v72 = left_weight.m_buffer->m_data;
    v73 = *(float *)&clear_value - left_weight.m_weight;
    left_weight.m_buffer->m_data += 40;
    v71->m_size -= 40;
    *(float *)&time_scale = v73;
    if ( v72 )
    {
      v74 = left_weight.m_buffer;
      v75 = left_weight.m_interpolator->clone(left_weight.m_interpolator, left_weight.m_buffer);
      v76 = time_scale;
      *((_DWORD *)v72 + 1) = 0;
      *((_DWORD *)v72 + 2) = 0;
      *((_DWORD *)v72 + 3) = 0;
      *((_DWORD *)v72 + 4) = 0;
      *((_DWORD *)v72 + 5) = v75;
      *((_DWORD *)v72 + 6) = v76;
      *((_DWORD *)v72 + 7) = v76;
      *((_DWORD *)v72 + 8) = v74;
      v72[36] = 0;
      *(_DWORD *)v72 = &vostok::animation::mixing::weight_lexeme::`vftable';
    }
    v72[36] = 1;
    epsilon = vostok::animation::mixing::operator*<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::weight_lexeme>(
                &right_animation,
                (vostok::animation::mixing::weight_lexeme *)v72);
    v77 = vostok::animation::mixing::operator*<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::weight_lexeme>(
            &left_animation,
            &left_weight);
    v78 = (vostok::animation::mixing::expression *)vostok::animation::mixing::operator+<vostok::animation::mixing::multiplication_lexeme,vostok::animation::mixing::multiplication_lexeme>(
                                                     v77,
                                                     epsilon);
    v46 = result;
    vostok::animation::mixing::expression::expression(v78, result);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v79, (int)&right_animation);
    p_left_animation = &left_animation;
  }
  else
  {
    v40 = movement_position;
    v35->m_next_key_point = -1;
    v35->m_target_vertex->translation = *v40;
    v41 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_animation_space_graph->m_object;
    animation.m_buffer = buffer;
    animation.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)buffer->m_data;
    LODWORD(time_scale) = &vostok::animation::linear_interpolator::`vftable';
    HIDWORD(time_scale) = 1048576000;
    memset((void *)&animation.m_time_calculator, 0, 16);
    memset(&animation.m_weight_interpolator, 0, 12);
    animation.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(v41 + 72);
    memset(&animation.m_start_cycle_animation_interval_id, 0, 12);
    LODWORD(animation.m_time_scale) = clear_value;
    animation.m_playback_type = play_cyclically;
    animation.m_time_synchronization_group_id = -1;
    animation.m_weight_synchronization_group_id = -1;
    *(_QWORD *)&animation.m_additivity_priority = 0xFFFFFFFF00000000uLL;
    *(_DWORD *)&animation.m_unique_animation_id = 16843007;
    vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
      &animation,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animation);
    animation.m_weight_interpolator = (const vostok::animation::base_interpolator *)&time_scale;
    vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&lexeme, &animation);
    lexeme.vostok::animation::mixing::base_lexeme::m_buffer = animation.m_buffer;
    lexeme.m_cloned = 0;
    lexeme.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
    lexeme.m_cloned_instance.m_object = 0;
    vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
      v42,
      (vostok::animation::mixing::base_lexeme *)&lexeme);
    v43 = (vostok::animation::mixing::animation_lexeme *)(3 * animation.m_animation_intervals_count);
    v44 = &animation.m_animation_intervals[animation.m_animation_intervals_count];
    for ( j = animation.m_animation_intervals; j != v44; ++j )
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&j->m_animation);
    v46 = result;
    vostok::animation::mixing::expression::expression(result, (vostok::animation::mixing::base_lexeme *)&lexeme, v43);
    p_left_animation = &lexeme;
  }
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v47, (int)p_left_animation);
  v80 = path._M_impl._M_start;
  if ( path._M_impl._M_start )
  {
    f = (int)survarium::g_allocator.f_.f_;
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(*(malloc_state **)(f + 20), (char *)v80);
  }
  return v46;
}
