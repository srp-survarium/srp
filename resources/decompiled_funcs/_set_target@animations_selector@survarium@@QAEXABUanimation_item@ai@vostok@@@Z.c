void __usercall survarium::animations_selector::set_target(
        survarium::animations_selector *this@<ecx>,
        const vostok::ai::animation_item *animation_emitter@<eax>)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v3; // edi
  vostok::animation::animation_expression_emitter *v5; // eax
  vostok::animation::animation_expression_emitter *v6; // ecx
  vostok::animation::animation_expression_emitter *v7; // eax
  bool v8; // zf

  m_object = animation_emitter->animation.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v5 = 0;
  if ( v3 )
  {
    v5 = (vostok::animation::animation_expression_emitter *)v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  v6 = v5;
  v7 = this->m_simple_animation_parameters.emitter.m_object;
  this->m_simple_animation_parameters.emitter.m_object = v6;
  if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  v8 = this->m_current_controller == 0;
  this->m_target_controller = &this->m_simple_animation_controller;
  this->m_target_controller_parameters = &this->m_simple_animation_parameters;
  if ( v8 )
    survarium::animations_selector::reset_animation_controller(
      this,
      (vostok::animation::subscribed_channel **)this->m_game_world->m_game->m_current_time_in_ms);
}
