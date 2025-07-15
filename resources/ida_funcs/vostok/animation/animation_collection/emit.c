vostok::animation::mixing::expression *__thiscall vostok::animation::animation_collection::emit(
        vostok::animation::animation_collection *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        vostok::animation::mixing::animation_lexeme *driving_animation,
        bool *is_last_animation)
{
  vostok::animation::animation_collection::emit_impl(
    (vostok::animation::animation_collection *)buffer,
    (int)this,
    result,
    buffer,
    driving_animation,
    is_last_animation);
  return result;
}


vostok::animation::mixing::expression *__thiscall vostok::animation::animation_collection::emit(
        vostok::animation::animation_collection *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool *is_last_animation)
{
  vostok::animation::animation_collection::emit_impl(
    (vostok::animation::animation_collection *)is_last_animation,
    (int)this,
    result,
    buffer,
    0,
    is_last_animation);
  return result;
}
