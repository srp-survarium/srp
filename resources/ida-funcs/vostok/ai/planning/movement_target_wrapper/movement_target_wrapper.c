void __thiscall vostok::ai::planning::movement_target_wrapper::movement_target_wrapper(
        vostok::ai::planning::movement_target_wrapper *this,
        const vostok::math::float3 *target_position,
        const vostok::math::float3 *eyes_direction,
        const vostok::math::float3 *preferable_velocity,
        const char *animation)
{
  this->position = *target_position;
  this->direction = *eyes_direction;
  this->velocity = *preferable_velocity;
  vostok::fs_new::path_string_impl::path_string_impl(&this->animation_name, 47, &animation);
}
