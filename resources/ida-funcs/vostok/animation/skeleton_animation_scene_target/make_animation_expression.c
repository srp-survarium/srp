vostok::animation::mixing::expression *__thiscall vostok::animation::skeleton_animation_scene_target::make_animation_expression(
        vostok::animation::skeleton_animation_scene_target *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  this->m_child->make_animation_expression(this->m_child, result, buffer);
  return result;
}
