void __thiscall vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
        vostok::animation::mixing::animation_lexeme_parameters *this,
        vostok::mutable_buffer *buffer,
        const char *identifier,
        const vostok::animation::mixing::animation_interval *animation_intervals_begin,
        const vostok::animation::mixing::animation_interval *animation_intervals_end,
        vostok::animation::mixing::base_lexeme *time_driving_animation,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  _BYTE *v12; // eax
  survarium::game_camera *v13; // ecx
  unsigned int v14; // [esp+8h] [ebp-50h]
  unsigned int v15; // [esp+Ch] [ebp-4Ch]
  vostok::mutable_buffer *v16; // [esp+10h] [ebp-48h]
  vostok::mutable_buffer *v17; // [esp+14h] [ebp-44h]
  float m_start_time; // [esp+20h] [ebp-38h]
  float m_length; // [esp+24h] [ebp-34h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v21; // [esp+44h] [ebp-14h]
  const vostok::animation::mixing::animation_interval *i; // [esp+4Ch] [ebp-Ch]
  vostok::animation::mixing::animation_interval *j; // [esp+50h] [ebp-8h]
  const vostok::variant<32> **animation_intervals; // [esp+54h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_buffer = buffer;
  fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
    (vostok::animation::mixing::expression *)buffer,
    &this->m_time_calculator.m_Closure.m_pthis);
  if ( time_driving_animation )
    v17 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v7, time_driving_animation);
  else
    v17 = 0;
  this->m_time_driving_animation = (vostok::animation::mixing::animation_lexeme *const)v17;
  if ( weight_driving_animation )
    v16 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v7, weight_driving_animation);
  else
    v16 = 0;
  this->m_weight_driving_animation = (vostok::animation::mixing::animation_lexeme *const)v16;
  this->m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                                              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                                                                                              (int)buffer);
  this->m_weight_interpolator = 0;
  this->m_time_scale_interpolator = 0;
  this->m_animated_object = 0;
  this->m_animation_intervals_count = animation_intervals_end - animation_intervals_begin;
  this->m_start_cycle_animation_interval_id = 0;
  this->m_start_animation_interval_id = 0;
  this->m_start_animation_interval_time = *(float *)&FLOAT_0_0;
  LODWORD(this->m_time_scale) = clear_value;
  v8 = (vostok::animation::mixing::binary_tree_animation_node *)this;
  this->m_playback_type = play_cyclically;
  if ( time_driving_animation )
    v15 = vostok::animation::mixing::binary_tree_animation_node::time_synchronization_group_id(
            (vostok::animation::mixing::binary_tree_animation_node *)this,
            (int)time_driving_animation);
  else
    v15 = -1;
  this->m_time_synchronization_group_id = v15;
  if ( weight_driving_animation )
    v14 = vostok::animation::mixing::binary_tree_animation_node::weight_synchronization_group_id(
            v8,
            (int)weight_driving_animation);
  else
    v14 = -1;
  this->m_weight_synchronization_group_id = v14;
  this->m_additivity_priority = 0;
  this->m_bones_mask = -1;
  this->m_unique_animation_id = -1;
  this->m_override_existing_animation = 0;
  this->m_is_positive_event_direction = 1;
  this->m_can_generate_events = 1;
  animation_intervals = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                          (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                          (int)this->m_buffer);
  survarium::weapon_user_dead_state::finalize(v9);
  vostok::mutable_buffer::operator+=(
    (vostok::mutable_buffer *)(12 * this->m_animation_intervals_count),
    &this->m_buffer->m_data);
  v10 = (survarium::game_camera *)animation_intervals;
  j = (vostok::animation::mixing::animation_interval *)animation_intervals;
  for ( i = animation_intervals_begin; i != animation_intervals_end; ++i )
  {
    v21 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)operator new(0xCu, (void *)j);
    if ( v21 )
    {
      m_length = i->m_length;
      m_start_time = i->m_start_time;
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
        v21,
        &i->m_animation);
      *(float *)&v21[1].m_object = m_start_time;
      *(float *)&v21[2].m_object = m_length;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v21);
    }
    v10 = (survarium::game_camera *)&j[1];
    ++j;
  }
  survarium::weapon_user_dead_state::finalize(v10);
  if ( *v12 )
    survarium::weapon_user_dead_state::finalize(v11);
  survarium::weapon_user_dead_state::finalize(v11);
  survarium::weapon_user_dead_state::finalize(v13);
}
