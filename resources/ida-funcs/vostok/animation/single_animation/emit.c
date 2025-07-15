vostok::animation::mixing::expression *__thiscall vostok::animation::single_animation::emit(
        vostok::animation::single_animation *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        vostok::animation::mixing::base_lexeme *time_driving_animation,
        bool *is_last_animation)
{
  vostok::animation::mixing::animation_lexeme *v5; // ecx
  vostok::animation::mixing::animation_lexeme *v6; // ecx
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // esi
  const vostok::animation::mixing::animation_interval *v9; // ebx
  vostok::animation::mixing::animation_lexeme *v11; // [esp+0h] [ebp-F8h]
  _DWORD v12[2]; // [esp+10h] [ebp-E8h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+18h] [ebp-E0h] BYREF
  vostok::animation::mixing::animation_lexeme lexeme; // [esp+70h] [ebp-88h] BYREF

  *is_last_animation = 1;
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)&this->m_animation,
    (int)&parameters,
    buffer,
    &this->m_animation,
    time_driving_animation,
    0,
    v11);
  v12[0] = &vostok::animation::linear_interpolator::`vftable';
  v12[1] = 1048576000;
  parameters.m_weight_interpolator = (const vostok::animation::base_interpolator *)v12;
  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&lexeme, &parameters);
  lexeme.vostok::animation::mixing::base_lexeme::m_buffer = parameters.m_buffer;
  lexeme.m_cloned = 0;
  lexeme.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  lexeme.m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v5, (vostok::animation::mixing::base_lexeme *)&lexeme);
  vostok::animation::mixing::expression::expression(result, (vostok::animation::mixing::base_lexeme *)&lexeme, v6);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v7, (int)&lexeme);
  m_animation_intervals = parameters.m_animation_intervals;
  v9 = &parameters.m_animation_intervals[parameters.m_animation_intervals_count];
  if ( parameters.m_animation_intervals != v9 )
  {
    do
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&m_animation_intervals->m_animation);
      ++m_animation_intervals;
    }
    while ( m_animation_intervals != v9 );
  }
  return result;
}


vostok::animation::mixing::expression *__thiscall vostok::animation::single_animation::emit(
        vostok::animation::single_animation *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool *is_last_animation)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_animation; // esi
  char *m_data; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v6; // ecx
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  vostok::animation::mixing::animation_lexeme *v8; // ecx
  const vostok::animation::mixing::animation_interval *v9; // ebx
  const vostok::animation::mixing::animation_interval *i; // esi
  _DWORD v12[2]; // [esp+10h] [ebp-E8h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+18h] [ebp-E0h] BYREF
  vostok::animation::mixing::animation_lexeme lexeme; // [esp+70h] [ebp-88h] BYREF

  *is_last_animation = 1;
  p_m_animation = &this->m_animation;
  m_data = buffer->m_data;
  parameters.m_buffer = buffer;
  memset((void *)&parameters.m_time_calculator, 0, 16);
  parameters.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)m_data;
  memset(&parameters.m_weight_interpolator, 0, 12);
  parameters.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(p_m_animation);
  memset(&parameters.m_start_cycle_animation_interval_id, 0, 12);
  LODWORD(parameters.m_time_scale) = clear_value;
  parameters.m_playback_type = play_cyclically;
  parameters.m_time_synchronization_group_id = -1;
  parameters.m_weight_synchronization_group_id = -1;
  parameters.m_additivity_priority = 0;
  parameters.m_bones_mask = -1;
  parameters.m_unique_animation_id = -1;
  parameters.m_override_existing_animation = 0;
  parameters.m_is_positive_event_direction = 1;
  parameters.m_can_generate_events = 1;
  vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
    v6,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&parameters);
  v12[0] = &vostok::animation::linear_interpolator::`vftable';
  v12[1] = 1048576000;
  parameters.m_weight_interpolator = (const vostok::animation::base_interpolator *)v12;
  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&lexeme, &parameters);
  lexeme.vostok::animation::mixing::base_lexeme::m_buffer = parameters.m_buffer;
  lexeme.m_cloned = 0;
  lexeme.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  lexeme.m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
    (vostok::animation::mixing::animation_lexeme *)parameters.m_buffer,
    (vostok::animation::mixing::base_lexeme *)&lexeme);
  vostok::animation::mixing::expression::expression(result, (vostok::animation::mixing::base_lexeme *)&lexeme, v7);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v8, (int)&lexeme);
  v9 = &parameters.m_animation_intervals[parameters.m_animation_intervals_count];
  for ( i = parameters.m_animation_intervals; i != v9; ++i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&i->m_animation);
  return result;
}
