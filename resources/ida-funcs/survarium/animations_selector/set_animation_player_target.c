void __userpurge survarium::animations_selector::set_animation_player_target(
        const vostok::animation::mixing::expression *target_expression@<eax>,
        survarium::animations_selector *this,
        vostok::animation::subscribed_channel **time_in_ms)
{
  void *v3; // esp
  vostok::animation::mixing::animation_lexeme_parameters *v4; // ecx
  const vostok::animation::mixing::animation_interval *v5; // edi
  const vostok::animation::mixing::animation_interval *i; // esi
  vostok::math::float4x4 *p_m_transform; // esi
  const vostok::animation::mixing::expression *v8; // eax
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  unsigned __int8 v11; // [esp-4000h] [ebp-4100h] BYREF
  vostok::animation::mixing::animation_lexeme lexeme; // [esp+10h] [ebp-F0h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters animation; // [esp+9Ch] [ebp-64h] BYREF
  vostok::mutable_buffer buffer; // [esp+F0h] [ebp-10h] BYREF
  vostok::animation::mixing::expression v15; // [esp+F8h] [ebp-8h] BYREF

  if ( target_expression->m_node.m_object && target_expression->m_lexeme )
  {
    vostok::animation::animation_player::set_target_and_tick(
      this->m_animation_player,
      &this->m_owner->m_transform,
      target_expression,
      time_in_ms);
  }
  else
  {
    v3 = alloca(0x4000);
    boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
      &buffer,
      &v11,
      0x4000u);
    animation.m_buffer = &buffer;
    v15.m_node.m_object = (vostok::animation::mixing::binary_tree_base_node *)&vostok::animation::linear_interpolator::`vftable';
    v15.m_lexeme = (vostok::animation::mixing::base_lexeme *)1048576000;
    memset((void *)&animation.m_time_calculator, 0, 16);
    animation.m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)buffer.m_data;
    memset(&animation.m_weight_interpolator, 0, 12);
    animation.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(&this->m_default_animation);
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
      v4,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animation);
    animation.m_weight_interpolator = (const vostok::animation::base_interpolator *)&v15;
    vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&lexeme, &animation);
    lexeme.vostok::animation::mixing::base_lexeme::m_buffer = animation.m_buffer;
    lexeme.m_cloned = 0;
    lexeme.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
    lexeme.m_cloned_instance.m_object = 0;
    vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
      (vostok::animation::mixing::animation_lexeme *)animation.m_buffer,
      (vostok::animation::mixing::base_lexeme *)&lexeme);
    v5 = &animation.m_animation_intervals[animation.m_animation_intervals_count];
    for ( i = animation.m_animation_intervals; i != v5; ++i )
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&i->m_animation);
    p_m_transform = &this->m_owner->m_transform;
    vostok::animation::mixing::expression::expression(
      &v15,
      (vostok::animation::mixing::base_lexeme *)&lexeme,
      (vostok::animation::mixing::animation_lexeme *)time_in_ms);
    vostok::animation::animation_player::set_target_and_tick(this->m_animation_player, p_m_transform, v8, time_in_ms);
    if ( v15.m_node.m_object )
    {
      if ( v15.m_node.m_object->m_reference_count-- == 1 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v15.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v15.m_node.m_object,
          0);
    }
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&lexeme);
  }
}
