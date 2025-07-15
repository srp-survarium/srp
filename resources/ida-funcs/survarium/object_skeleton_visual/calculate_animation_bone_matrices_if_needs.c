// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::object_skeleton_visual::calculate_animation_bone_matrices_if_needs(
        survarium::object_skeleton_visual *this@<ecx>,
        __m128i a2@<xmm0>,
        unsigned int current_time_ms)
{
  vostok::timing::timer *v4; // ecx
  vostok::animation::animation_player *m_current_target_start_time; // ecx
  unsigned int m_playing_time; // eax
  unsigned int v7; // eax
  vostok::animation::skeleton_animation_scene_target *m_next_target; // edi
  vostok::animation::subscribed_channel **v9; // edi
  void *v10; // esp
  vostok::animation::skeleton_animation_scene_target *m_current_target; // ecx
  vostok::animation::animation_player *v12; // ecx
  bool v13; // zf
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  void *v15; // esp
  vostok::animation::animation_player *v16; // ecx
  vostok::render::skeleton_model_instance *v17; // esi
  vostok::animation::mixing::base_lexeme *v18; // eax
  int bone_index; // edi
  int v20; // eax
  int v21; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  vostok::math::float4x4 *rotation; // eax
  vostok::animation::hand_to_weapon_ik_solver *v24; // ecx
  vostok::animation::fingers_to_weapon_corrector *v25; // ecx
  vostok::animation::animation_player *v26; // ecx
  vostok::animation::skeleton *v27; // ecx
  vostok::render::skeleton_model_instance *v28; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v29; // ecx
  vostok::animation::skeleton *v30; // eax
  vostok::animation::skeleton *v31; // esi
  int v32; // edi
  int v33; // eax
  int v34; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  vostok::math::float4x4 *p_result; // esi
  _BYTE v37[32752]; // [esp+10h] [ebp-8078h] BYREF
  vostok::math::float4x4 *m_animation_bone_matrices; // [esp+8000h] [ebp-88h]
  int v39; // [esp+8004h] [ebp-84h]
  vostok::math::float4_pod *p_k; // [esp+8008h] [ebp-80h]
  int v41; // [esp+800Ch] [ebp-7Ch]
  const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *v42; // [esp+8010h] [ebp-78h]
  bool v43; // [esp+8014h] [ebp-74h]
  vostok::math::float4x4 result; // [esp+801Ch] [ebp-6Ch] BYREF
  _DWORD v45[2]; // [esp+805Ch] [ebp-2Ch] BYREF
  _DWORD v46[2]; // [esp+8064h] [ebp-24h] BYREF
  vostok::animation::mixing::expression v47; // [esp+806Ch] [ebp-1Ch] BYREF
  vostok::animation::mixing::expression current_time_in_ms; // [esp+8074h] [ebp-14h] BYREF
  vostok::math::float4x4 *p_m_transform; // [esp+807Ch] [ebp-Ch]
  vostok::math::float4x4 *transform_in_case_of_a_single_object_usage; // [esp+8080h] [ebp-8h]
  vostok::animation::mixing::expression *expression; // [esp+8084h] [ebp-4h]

  if ( this->m_last_matrices_calculated_time == current_time_ms )
    return;
  this->m_last_matrices_calculated_time = current_time_ms;
  if ( !this->m_current_target )
    return;
  p_m_transform = &this->m_transform;
  expression = (vostok::animation::mixing::expression *)&this->m_animation_player;
  vostok::animation::animation_player::set_object_transform(
    (vostok::animation::animation_player *)&this->m_transform,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_animation_player,
    &this->m_transform,
    0);
  transform_in_case_of_a_single_object_usage = (vostok::math::float4x4 *)vostok::timing::timer::get_elapsed_msec(
                                                                           v4,
                                                                           (int)&this->m_animation_timer);
  if ( !this->m_current_target )
    goto LABEL_18;
  do
  {
    m_playing_time = this->m_current_target->m_playing_time;
    if ( m_playing_time == -1 )
      break;
    m_current_target_start_time = (vostok::animation::animation_player *)this->m_current_target_start_time;
    v7 = (unsigned int)m_current_target_start_time + m_playing_time;
    if ( v7 >= (unsigned int)transform_in_case_of_a_single_object_usage )
      break;
    this->m_current_target_start_time = v7;
    m_next_target = this->m_current_target->m_next_target;
    this->m_current_target = m_next_target;
    if ( m_next_target )
    {
      v15 = alloca(0x8000);
      v45[0] = v37;
      v45[1] = 0x8000;
      m_next_target->make_animation_expression(m_next_target, &v47, (vostok::mutable_buffer *)v45);
      vostok::animation::animation_player::set_target_and_tick(
        v16,
        (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
        &v47,
        (vostok::animation::subscribed_channel **)transform_in_case_of_a_single_object_usage,
        (int)p_m_transform);
      if ( !v47.m_node.m_object )
        continue;
      v13 = v47.m_node.m_object->m_reference_count-- == 1;
      if ( !v13 )
        continue;
      m_object = v47.m_node.m_object;
    }
    else
    {
      if ( !this->m_animation_cyclic )
        continue;
      v9 = (vostok::animation::subscribed_channel **)transform_in_case_of_a_single_object_usage;
      this->m_current_target = this->m_start_target;
      this->m_current_target_start_time = (unsigned int)v9;
      v10 = alloca(0x8000);
      m_current_target = this->m_current_target;
      v46[0] = v37;
      v46[1] = 0x8000;
      m_current_target->make_animation_expression(m_current_target, &current_time_in_ms, (vostok::mutable_buffer *)v46);
      vostok::animation::animation_player::set_target_and_tick(
        v12,
        (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
        &current_time_in_ms,
        v9,
        (int)p_m_transform);
      if ( !current_time_in_ms.m_node.m_object )
        continue;
      v13 = current_time_in_ms.m_node.m_object->m_reference_count-- == 1;
      if ( !v13 )
        continue;
      m_object = current_time_in_ms.m_node.m_object;
    }
    ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
      m_object,
      0);
  }
  while ( this->m_current_target );
  if ( this->m_current_target )
    vostok::animation::animation_player::tick_impl(
      m_current_target_start_time,
      (int)expression,
      (vostok::animation::subscribed_channel **)transform_in_case_of_a_single_object_usage,
      (const unsigned int)v42,
      v43);
LABEL_18:
  if ( this->m_bind_weapon )
  {
    v17 = this->m_model.m_object;
    v18 = (vostok::animation::mixing::base_lexeme *)v17->m_skeleton.m_object;
    current_time_in_ms.m_lexeme = v18 + 34;
    bone_index = vostok::animation::skeleton::get_bone_index(
                   (vostok::animation::skeleton *)&v18[34],
                   (int)v18,
                   "Weapon");
    v20 = ((char *)current_time_in_ms.m_lexeme[1].m_buffer - (char *)current_time_in_ms.m_lexeme) / 28;
    result.k.x = 0.0;
    v21 = bone_index - v20;
    vostok::animation::animation_player::compute_bones_local_matrices(
      (vostok::animation::animation_player *)0x1C,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
      v17->m_skeleton.m_object,
      this->m_animation_bone_matrices,
      0,
      (vostok::math::float4x4 *)&result.lines[2],
      (unsigned int *)0xFF,
      v42,
      v43);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v22,
      (int *)&result.k.0);
    current_time_in_ms.m_lexeme = (vostok::animation::mixing::base_lexeme *)&this->m_animation_bone_matrices[v21];
    rotation = vostok::math::create_rotation(
                 (const vostok::math::float3 *)&current_time_in_ms.m_lexeme[2],
                 (int)&result,
                 a2,
                 3.1415927);
    vostok::math::change_matrix_orientation(rotation, (vostok::math::float4x4 *)current_time_in_ms.m_lexeme);
    vostok::animation::hand_to_weapon_ik_solver::process(
      v24,
      (int)&this->m_hand_solver,
      transform_in_case_of_a_single_object_usage,
      this->m_bind_weapon_resolved->m_animation_bone_matrices,
      0,
      this->m_animation_bone_matrices);
    vostok::animation::fingers_to_weapon_corrector::process(
      v25,
      (const unsigned int)&this->m_fingers_corrector,
      transform_in_case_of_a_single_object_usage,
      *(float *)&this->m_animation_bone_matrices);
    vostok::animation::animation_player::convert_to_object_matrices(
      v26,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
      this->m_model.m_object->m_skeleton.m_object,
      this->m_animation_bone_matrices,
      0,
      (vostok::math::float4x4 *)0xFF,
      (const unsigned __int8)v42);
  }
  else
  {
    v41 = 255;
    p_k = &result.k;
    v28 = this->m_model.m_object;
    v39 = 0;
    m_animation_bone_matrices = this->m_animation_bone_matrices;
    result.k.x = 0.0;
    vostok::animation::animation_player::compute_bones_matrices(
      m_current_target_start_time,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
      v28->m_skeleton.m_object,
      m_animation_bone_matrices,
      0,
      (vostok::math::float4x4 *)&result.lines[2],
      (unsigned int *)0xFF,
      v42,
      v43);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v29,
      (int *)&result.k.0);
  }
  if ( this->m_bind_as_weapon_to )
  {
    v30 = this->m_bind_as_weapon_to_resolved->m_model.m_object->m_skeleton.m_object;
    v31 = v30 + 1;
    v32 = vostok::animation::skeleton::get_bone_index(v27, (int)v30, "Weapon");
    v33 = (v31->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
         - (int)v31)
        / 28;
    result.k.x = 0.0;
    v34 = v32 - v33;
    vostok::animation::animation_player::compute_bones_matrices(
      (vostok::animation::animation_player *)0x1C,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
      this->m_model.m_object->m_skeleton.m_object,
      this->m_animation_bone_matrices,
      0,
      (vostok::math::float4x4 *)&result.lines[2],
      (unsigned int *)0xFF,
      v42,
      v43);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v35,
      (int *)&result.k.0);
    survarium::object_skeleton_visual::calculate_animation_bone_matrices_if_needs(
      this->m_bind_as_weapon_to_resolved,
      current_time_ms);
    vostok::math::mul4x3(
      &this->m_bind_as_weapon_to_resolved->m_transform,
      &this->m_bind_as_weapon_to_resolved->m_animation_bone_matrices[v34],
      &result);
    p_result = &result;
  }
  else
  {
    p_result = vostok::animation::animation_player::get_object_transform(
                 (vostok::animation::animation_player *)v27,
                 (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)expression,
                 &result,
                 0);
  }
  qmemcpy(p_m_transform, p_result, sizeof(vostok::math::float4x4));
}
