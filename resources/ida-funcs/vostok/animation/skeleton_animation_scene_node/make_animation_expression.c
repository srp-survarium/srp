vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **__thiscall vostok::animation::skeleton_animation_scene_node::make_animation_expression(
        vostok::animation::skeleton_animation_scene_node *this,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **result,
        vostok::mutable_buffer *buffer)
{
  void *v4; // esp
  int v5; // ecx
  int v6; // eax
  float v7; // edi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // eax
  vostok::buffer_vector<vostok::animation::mixing::animation_interval> *v9; // ecx
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v10; // edi
  vostok::resources::managed_resource *v11; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v12; // ecx
  int v13; // eax
  int v14; // edi
  vostok::resources::pinned_ptr_const<unsigned char> *v15; // ecx
  void **M_finish; // eax
  int v17; // eax
  float m_offset; // xmm0_4
  int v19; // eax
  unsigned int v20; // edi
  unsigned int v21; // edx
  vostok::resources::resource_reconstruction_info *v22; // ecx
  float m_time_scale; // xmm0_4
  vostok::animation::base_interpolator *m_time_interpolator; // ecx
  unsigned int m_weight_synchronizing_group; // ecx
  vostok::animation::mixing::playback_enum m_playback_type; // eax
  vostok::animation::mixing::expression *v27; // ecx
  vostok::animation::mixing::animation_lexeme *v28; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v29; // ecx
  vostok::buffer_vector<vostok::animation::mixing::animation_interval> *v30; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v32; // [esp-4h] [ebp-ACh] BYREF
  const vostok::animation::mixing::animation_interval *v33[3]; // [esp+0h] [ebp-A8h] BYREF
  vostok::animation::mixing::animation_lexeme v34; // [esp+Ch] [ebp-9Ch] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v35; // [esp+90h] [ebp-18h] BYREF
  _BYTE v36[12]; // [esp+E4h] [ebp+3Ch] BYREF
  vostok::animation::mixing::animation_interval v37; // [esp+F0h] [ebp+48h] BYREF
  vostok::animation::mixing::animation_interval v38; // [esp+104h] [ebp+5Ch] BYREF

  v4 = alloca(20 * (this->m_intervals._M_impl._M_finish - this->m_intervals._M_impl._M_start));
  v5 = (char *)this->m_intervals._M_impl._M_finish - (char *)this->m_intervals._M_impl._M_start;
  v38.m_start_time = 0.0;
  v38.m_first_view_animation.m_object = (vostok::resources::managed_resource *)v33;
  v38.m_third_view_animation.m_object = (vostok::resources::managed_resource *)v33;
  v6 = (char *)this->m_intervals._M_impl._M_finish - (char *)this->m_intervals._M_impl._M_start;
  v38.m_animation_id = (unsigned int)&v33[5 * (v5 >> 2)];
  HIBYTE(v38.m_length) = 0;
  if ( v6 >> 2 )
  {
    do
    {
      LODWORD(v7) = 4 * LODWORD(v38.m_start_time);
      v8 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this->m_intervals._M_impl._M_start[LODWORD(v38.m_start_time)];
      vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
        v8 + 1,
        (vostok::resources::managed_resource *)&v37,
        &v37,
        (int)v8->m_object,
        0xFFFF);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(v9, &v38, (int)&v37);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v37.m_third_view_animation);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v37.m_first_view_animation);
      v10 = *(const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)((char *)this->m_intervals._M_impl._M_start + LODWORD(v7));
      v32.m_object = v11;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        &v32,
        v10 + 1);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v12,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v36,
        v32);
      v14 = *(_DWORD *)(*(_DWORD *)(v13 + 4) + 24);
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        v15,
        (int)v36);
      M_finish = this->m_intervals._M_impl._M_finish;
      HIBYTE(v38.m_length) = v14 == 1;
      v17 = (char *)M_finish - (char *)this->m_intervals._M_impl._M_start;
      ++LODWORD(v38.m_start_time);
    }
    while ( LODWORD(v38.m_start_time) < v17 >> 2 );
  }
  m_offset = this->m_offset;
  v19 = this->m_intervals._M_impl._M_finish - this->m_intervals._M_impl._M_start;
  v20 = -1;
  v21 = 0;
  v38.m_start_time = m_offset;
  if ( v19 )
  {
    v22 = &v38.m_first_view_animation.m_object->vostok::resources::resource_reconstruction_info;
    do
    {
      if ( v20 == -1 )
      {
        if ( m_offset <= *(float *)&v22->m_reconstruction_info_actuality_tick )
          v20 = v21;
        else
          m_offset = m_offset - *(float *)&v22->m_reconstruction_info_actuality_tick;
      }
      ++v21;
      v22 = (vostok::resources::resource_reconstruction_info *)((char *)v22 + 20);
    }
    while ( v21 < this->m_intervals._M_impl._M_finish - this->m_intervals._M_impl._M_start );
    v38.m_start_time = m_offset;
  }
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v35,
    buffer,
    (const vostok::animation::mixing::animation_interval *)v38.m_first_view_animation.m_object,
    (const vostok::animation::mixing::animation_interval *)v38.m_third_view_animation.m_object,
    v33[0],
    (vostok::animation::mixing::animation_lexeme *const)v33[1],
    (vostok::animation::mixing::animation_lexeme *const)v33[2]);
  m_time_scale = this->m_time_scale;
  m_time_interpolator = this->m_time_interpolator;
  v35.m_start_cycle_animation_interval_id = this->m_cycle_from_interval_id != -1 ? this->m_cycle_from_interval_id : 0;
  v35.m_time_scale_interpolator = m_time_interpolator;
  v35.m_weight_interpolator = this->m_weight_interpolator;
  v35.m_time_synchronization_group_id = this->m_time_synchronizing_group;
  m_weight_synchronizing_group = this->m_weight_synchronizing_group;
  v35.m_time_scale = m_time_scale;
  v35.m_additivity_priority = HIBYTE(v38.m_length) != 0;
  v35.m_bones_mask = this->m_bone_mask;
  m_playback_type = this->m_playback_type;
  v35.m_weight_synchronization_group_id = m_weight_synchronizing_group;
  v35.m_playback_type = m_playback_type;
  v35.m_start_animation_interval_id = v20;
  v35.m_start_animation_interval_time = v38.m_start_time;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&v34, &v35);
  vostok::animation::mixing::expression::expression(v27, result, &v34);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v28, (int)&v34);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v29, (int)&v35);
  vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(
    v30,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)&v38);
  return result;
}
