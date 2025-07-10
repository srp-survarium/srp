vostok::animation::mixing::expression *__thiscall survarium::simple_animation_controller::selected_animations(
        survarium::simple_animation_controller *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::mixing::expression *v4; // eax

  if ( this->m_current_parameters.emitter.m_object != this->m_target_parameters.emitter.m_object )
  {
    this->m_last_animation_emitted = 0;
    survarium::simple_animation_controller_parameters::operator=(
      &this->m_target_parameters,
      (int)&this->m_current_parameters);
  }
  if ( this->m_last_animation_emitted )
  {
    v4 = result;
    result->m_node.m_object = 0;
    result->m_lexeme = 0;
  }
  else
  {
    this->m_current_parameters.emitter.m_object->emit(
      this->m_current_parameters.emitter.m_object,
      result,
      buffer,
      &this->m_last_animation_emitted);
    return result;
  }
  return v4;
}
