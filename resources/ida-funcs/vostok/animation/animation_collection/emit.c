vostok::animation::mixing::expression *__thiscall vostok::animation::animation_collection::emit(
        vostok::animation::animation_collection *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::animation::mixing::animation_lexeme *driving_animation,
        bool *is_last_animation)
{
  vostok::animation::animation_collection::emit_impl(
    this,
    (vostok::animation::mixing::expression *)this,
    result,
    buffer,
    (bool *)driving_animation,
    is_last_animation);
  return result;
}


vostok::animation::mixing::expression *__thiscall vostok::animation::animation_collection::emit(
        vostok::animation::animation_collection *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        bool *is_last_animation)
{
  vostok::animation::animation_collection::emit_impl(
    this,
    (vostok::animation::mixing::expression *)this,
    result,
    buffer,
    0,
    is_last_animation);
  return result;
}
