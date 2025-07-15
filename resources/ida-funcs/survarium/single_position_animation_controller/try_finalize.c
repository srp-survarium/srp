vostok::animation::mixing::expression *__thiscall survarium::single_position_animation_controller::try_finalize(
        survarium::single_position_animation_controller *this,
        vostok::animation::mixing::expression *result,
        survarium::base_animation_controller *next_controller,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::mixing::expression *v4; // eax

  v4 = result;
  result->m_node.m_object = 0;
  result->m_lexeme = 0;
  return v4;
}
