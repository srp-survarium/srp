void __usercall survarium::animations_selector::set_target(
        survarium::animations_selector *this@<ecx>,
        const vostok::ai::movement_target *target_position@<eax>)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v4; // edi
  vostok::animation::animation_expression_emitter *v5; // eax
  vostok::animation::animation_expression_emitter *v6; // ecx
  vostok::animation::animation_expression_emitter *v7; // eax
  bool v8; // zf

  this->m_movement_animation_parameters.position = target_position->target_position;
  this->m_movement_animation_parameters.eyes_direction = target_position->direction;
  this->m_movement_animation_parameters.velocity = target_position->velocity;
  m_object = target_position->preferable_animation->animation.m_object;
  v4 = 0;
  if ( m_object )
  {
    v4 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v5 = 0;
  if ( v4 )
  {
    v5 = (vostok::animation::animation_expression_emitter *)v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v6 = v5;
  v7 = this->m_movement_animation_parameters.animation.m_object;
  this->m_movement_animation_parameters.animation.m_object = v6;
  if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  v8 = this->m_current_controller == 0;
  this->m_target_controller = (survarium::base_animation_controller *)this;
  this->m_target_controller_parameters = &this->m_movement_animation_parameters;
  if ( v8 )
    survarium::animations_selector::reset_animation_controller(
      this,
      (vostok::animation::subscribed_channel **)this->m_game_world->m_game->m_current_time_in_ms);
}
