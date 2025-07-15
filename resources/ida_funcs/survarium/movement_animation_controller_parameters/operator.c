survarium::movement_animation_controller_parameters *__usercall survarium::movement_animation_controller_parameters::operator=@<eax>(
        survarium::movement_animation_controller_parameters *this@<esi>,
        const survarium::movement_animation_controller_parameters *__that@<eax>)
{
  vostok::animation::animation_expression_emitter *m_object; // eax
  vostok::animation::animation_expression_emitter *v3; // ecx
  vostok::animation::animation_expression_emitter *v4; // eax

  this->position = __that->position;
  this->eyes_direction = __that->eyes_direction;
  this->velocity = __that->velocity;
  m_object = __that->animation.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = this->animation.m_object;
  this->animation.m_object = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return this;
}
