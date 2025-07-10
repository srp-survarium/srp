vostok::animation::mixing::expression *__thiscall survarium::empty_hands::selected_animations(
        survarium::empty_hands *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view)
{
  unsigned int m_seed; // eax
  unsigned int m_animations_count; // ecx
  unsigned int v7; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // edi
  char *m_data; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v10; // ecx
  survarium::base_player *m_user; // edx
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  vostok::animation::mixing::animation_lexeme *v13; // ecx
  const vostok::animation::mixing::animation_interval *v14; // edi
  const vostok::animation::mixing::animation_interval *i; // esi
  vostok::animation::mixing::animation_lexeme *v16; // ecx
  vostok::animation::linear_interpolator l_interpolator; // [esp+8h] [ebp-E4h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters animation; // [esp+10h] [ebp-DCh] BYREF
  vostok::animation::mixing::animation_lexeme lexeme; // [esp+64h] [ebp-88h] BYREF

  m_seed = this->m_random.m_seed;
  m_animations_count = this->m_animations_count;
  v7 = 134775813 * m_seed + 1;
  this->m_random.m_seed = v7;
  v8 = &this->m_animations[(m_animations_count * (unsigned __int64)v7) >> 32];
  m_data = buffer->m_data;
  animation.m_buffer = buffer;
  l_interpolator.__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
  l_interpolator.m_total_transition_time = s_aim_transition_time;
  memset((void *)&animation.m_time_calculator, 0, 16);
  animation.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)m_data;
  memset(&animation.m_weight_interpolator, 0, 12);
  animation.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(v8);
  animation.m_time_synchronization_group_id = -1;
  animation.m_weight_synchronization_group_id = -1;
  animation.m_bones_mask = -1;
  memset(&animation.m_start_cycle_animation_interval_id, 0, 12);
  LODWORD(animation.m_time_scale) = clear_value;
  animation.m_playback_type = play_cyclically;
  animation.m_additivity_priority = 0;
  animation.m_unique_animation_id = -1;
  animation.m_override_existing_animation = 0;
  animation.m_is_positive_event_direction = 1;
  animation.m_can_generate_events = 1;
  vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
    v10,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animation);
  m_user = this->m_user;
  animation.m_weight_synchronization_group_id = 0;
  animation.m_time_synchronization_group_id = 0;
  animation.m_weight_interpolator = &l_interpolator;
  animation.m_time_scale_interpolator = &l_interpolator;
  animation.m_animated_object = m_user;
  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&lexeme, &animation);
  lexeme.vostok::animation::mixing::base_lexeme::m_buffer = animation.m_buffer;
  lexeme.m_cloned = 0;
  lexeme.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  lexeme.m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v12, (vostok::animation::mixing::base_lexeme *)&lexeme);
  v13 = (vostok::animation::mixing::animation_lexeme *)(3 * animation.m_animation_intervals_count);
  v14 = &animation.m_animation_intervals[animation.m_animation_intervals_count];
  for ( i = animation.m_animation_intervals; i != v14; ++i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&i->m_animation);
  vostok::animation::mixing::expression::expression(result, (vostok::animation::mixing::base_lexeme *)&lexeme, v13);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v16, (int)&lexeme);
  return result;
}
